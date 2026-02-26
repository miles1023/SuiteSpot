# Custom Toasts and Overlays in BakkesMod

A comprehensive reference for everything learned while implementing the SuiteSpot
hotkey notification bubble. Covers all approaches explored, their limitations, and
the final working solution.

---

## The Three Rendering Pipelines

BakkasMod exposes three distinct ways to draw things on screen. They are
**completely separate** — do not mix them.

| Pipeline | API | Always-on? | ImGui? | Rounded shapes? |
|----------|-----|------------|--------|-----------------|
| CanvasWrapper | `RegisterDrawable` | ✅ Yes | ❌ No | ❌ No |
| ImageWrapper | `RegisterDrawable` + `canvas.DrawRect(w,h,img)` | ✅ Yes | ❌ No | ⚠️ Static only |
| ImGui PluginWindow | `PluginWindow::Render()` | ⚠️ Only when open | ✅ Yes | ✅ Yes |

---

## Approach 1: CanvasWrapper via RegisterDrawable

### How it works

```cpp
gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
    canvas.SetPosition(Vector2F{20.f, 20.f});
    canvas.SetColor(LinearColor{0.f, 0.f, 0.f, 200.f});
    canvas.FillBox(Vector2F{boxW, boxH});
    canvas.SetPosition(Vector2F{20.f + padX, 20.f + padY});
    canvas.SetColor(LinearColor{255.f, 165.f, 0.f, 255.f});
    canvas.DrawString(text, 1.5f, 1.5f);
});
```

The lambda fires **every frame**, unconditionally, regardless of any window state.
No ImGui context required. This is the most reliable always-on drawing method.

### Confirmed CanvasWrapper API

```cpp
canvas.SetPosition(Vector2F{x, y});           // move draw cursor
canvas.SetColor(LinearColor{R, G, B, A});      // 0–255 floats
canvas.FillBox(Vector2F{width, height});       // filled axis-aligned rect
canvas.DrawBox(Vector2F{width, height});       // outline rect
canvas.DrawString(text, xScale, yScale);       // draw text at cursor
canvas.DrawString(text, xScale, yScale, false);// false = no drop shadow
canvas.GetStringSize(text, xScale, yScale);    // returns Vector2F {w, h}
```

### What CanvasWrapper CANNOT do

There is **no** rounded rect, arc, circle, or ellipse primitive in CanvasWrapper.
Every shape is axis-aligned rectangles or lines. This was confirmed by reading
the full `canvaswrapper.h` header.

### Limitations

- No rounded corners (plain rectangles only)
- Limited Unicode support — the game's default CanvasWrapper font is bitmap-based
  and does not render characters like `•` (U+2022), em dash `—`, etc.
  Use plain ASCII separators: ` - `, `:`, spaces.
- No alpha blending between layers (layering background + text = two separate draws)
- Text scale is float multiplier on the bitmap atlas — produces blurry text at
  sizes other than 1.0. For large text load a font via `LoadFont`.
- `DrawString` scale of `1.5f` produces slightly blurry text; `1.0f` is crispest.

---

## Approach 2: ImageWrapper

### How it works

Load a PNG at startup, then stretch it behind your text:

```cpp
// Declaration
std::shared_ptr<ImageWrapper> bubbleImg;

// In onLoad():
bubbleImg = std::make_shared<ImageWrapper>(
    gameWrapper->GetDataFolder() / "plugins" / "images" / "bubble.png", false);

// In RegisterDrawable:
canvas.SetPosition(Vector2F{x, y});
canvas.DrawRect(Vector2F{boxW, boxH}, &(*bubbleImg));
```

### Why this fails for dynamic-width overlays

`DrawRect` stretches the entire image to the given rect size. A bubble PNG with
rounded corners will have its corners **distorted** when the width changes with
text length. The corners stretch proportionally instead of remaining fixed-radius.

The proper solution is **9-slice** (fixed corners, stretched center). BakkasMod
has `DrawTile` but it is undocumented (`// don't ask. try..`), making it
unreliable to depend on.

**Verdict:** ImageWrapper is fine for fixed-size images (icons, logos). Do not
use it for variable-width text bubbles unless you pre-render a fixed-size image.

---

## Approach 3: ImGui PluginWindow (Final Solution)

### Why ImGui for overlays?

ImGui windows support `ImGuiStyleVar_WindowRounding` which rounds the window
background corners natively. The background IS the bubble shape. No separate
shape-drawing required.

### Confirmed APIs (imgui.h)

```cpp
// imgui.h:1120 — window corner radius
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.0f);

// imgui.h:299 — per-window background alpha override
ImGui::SetNextWindowBgAlpha(0.80f * alpha);

// imgui.h:293 — pin window to screen position every frame
ImGui::SetNextWindowPos(ImVec2(20.f, 20.f), ImGuiCond_Always);

// imgui.h:753–769 — overlay flags
ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration
    | ImGuiWindowFlags_AlwaysAutoResize
    | ImGuiWindowFlags_NoInputs
    | ImGuiWindowFlags_NoFocusOnAppearing
    | ImGuiWindowFlags_NoMove;

// imgui.h:677 — measure text before drawing
ImVec2 size = ImGui::CalcTextSize(text);
```

**Important:** `PushStyleVar` / `PushStyleColor` must be called BEFORE `Begin()`.
`PopStyleVar` / `PopStyleColor` must be called AFTER `End()`.

```cpp
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.0f);
ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(16.f, 10.f));
ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.47f, 0.81f, 0.80f * alpha));
ImGui::SetNextWindowPos(ImVec2(20.f, 20.f), ImGuiCond_Always);
ImGui::SetNextWindowBgAlpha(0.80f * alpha);

ImGui::Begin("##ss_hotkey_overlay", nullptr, flags);
ImGui::TextColored(textColor, "%s", text.c_str());
ImGui::End();

ImGui::PopStyleColor();    // must come after End()
ImGui::PopStyleVar(2);     // pops WindowPadding then WindowRounding
```

### The `##` prefix in window names

`"##ss_hotkey_overlay"` — the `##` prefix makes the entire string an ID with no
visible title. Without it, BakkasMod would show the name in the title bar.

### Colors used in SuiteSpot

```cpp
// RL Blue background (~#0079CF)
ImVec4(0.0f, 0.47f, 0.81f, 0.80f)

// Success text orange (~#FF8C00)
ImVec4(1.0f, 0.55f, 0.0f, alpha)

// Error text red (~#F24040)
ImVec4(0.95f, 0.25f, 0.25f, alpha)
```

---

## Timing: Hold-then-Fade

Use `std::chrono::steady_clock` for frame-independent timing. Neither
`RegisterDrawable` nor `PluginWindow::Render()` provide a delta time.

```cpp
// Arm:
hotkeyOverlay.startTime = std::chrono::steady_clock::now();
hotkeyOverlay.duration = 7.0f;
hotkeyOverlay.visible = true;

// Each frame in Render():
auto elapsed = std::chrono::duration<float>(
    std::chrono::steady_clock::now() - hotkeyOverlay.startTime).count();

if (elapsed >= hotkeyOverlay.duration) {
    hotkeyOverlay.visible = false;
    return;
}

// Hold 5s at full opacity, fade linearly over final 2s
float alpha = (elapsed < 5.0f) ? 1.0f : 1.0f - ((elapsed - 5.0f) / 2.0f);
```

---

## Critical: IsActiveOverlay() Is Not "Always-On"

This is the most important lesson from implementing this feature.

**`IsActiveOverlay() = true` does NOT cause `Render()` to fire every frame.**

What it actually controls:
- `return true` → the window will close when the user presses Esc
- `return false` → the window will NOT close when the user presses Esc

`Render()` only fires while BakkasMod has the window in its active-windows list,
which requires a prior `openmenu <menuname>` call. See
`persistent-pluginwindow-overlay.md` for the full pattern to keep the window
permanently open.

---

## Do Not Use: gameWrapper->Toast()

BakkasMod provides `gameWrapper->Toast(title, text, duration)`. This is a
**native BakkasMod notification** — plain toast with no custom styling, colors,
or shapes. It is NOT related to the CanvasWrapper or ImGui overlay approaches.

Avoid naming custom overlay variables `toast` to prevent confusion with this API.

---

## Font Notes

### CanvasWrapper font
- Bitmap font built into BakkasMod
- Limited Unicode — plain ASCII only
- Scale multiplier on bitmap = blurry at non-1.0 scales
- `DrawString(text, 1.0f, 1.0f)` for crispest result

### ImGui font (Ubuntu-Regular.ttf)
- Loaded via `GUIManager::LoadFont("name", "Ubuntu-Regular.ttf", size)`
- Must call `GetFont` first (returns existing atlas entry, no rebuild)
- Only call `LoadFont` via `gameWrapper->Execute()` — never during rendering
- Ubuntu Regular supports most Latin Unicode including em dash and bullet

```cpp
// Safe pattern:
clockFont = gui.GetFont("suitespot_clock_48");
if (!clockFont) {
    gameWrapper->Execute([this](GameWrapper* gw) {
        auto gui = gw->GetGUIManager();
        auto [res, font] = gui.LoadFont("suitespot_clock_48", "Ubuntu-Regular.ttf", 48);
        if (res == 2 && font) clockFont = font;
    });
}
```

LoadFont return values: `0` = failed, `1` = queued, `2` = loaded.

---

## Diagnostic Checklist

If your overlay is not appearing:

1. **Check if Render() fires at all** — add a one-shot `static bool` log at top
   of `Render()`. If it never appears, the window is not open.

2. **Check if imgui_ctx is set** — `SetImGuiContext()` must be called before
   `Render()` can use ImGui. Log `(bool)imgui_ctx` in the one-shot.

3. **Check if the visible flag is being set** — add a LOG in your toast setter
   function to confirm it runs after the notifier fires.

4. **Check for Unicode issues** — if text renders as `□□□`, replace the
   characters with plain ASCII equivalents.

5. **Check Push/Pop balance** — unmatched `PushStyleVar`/`PopStyleVar` or
   `PushStyleColor`/`PopStyleColor` silently corrupt subsequent ImGui rendering.
