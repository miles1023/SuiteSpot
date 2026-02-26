# Persistent PluginWindow Overlay Pattern

## Problem

`PluginWindow::Render()` is only called by BakkasMod while the window is in its
active-windows list — i.e., only after `openmenu <menuname>` has been called.

**`IsActiveOverlay()` does NOT make the window always-on.**

What `IsActiveOverlay()` actually controls:
- `return true` → window closes when the user presses Esc (passive overlay)
- `return false` → window does NOT close when the user presses Esc (persistent)

This is orthogonal to whether `Render()` fires. The window must still be
explicitly opened for `Render()` to be invoked.

This was confirmed by adding a diagnostic log inside `Render()` and observing that
it was never printed even when the plugin was fully loaded and notifiers were firing.

## Why RegisterDrawable Is Different

`gameWrapper->RegisterDrawable()` is a game-thread hook that fires **every frame
regardless of any window state**. It bypasses BakkasMod's window system entirely.
Its limitation is that it only provides `CanvasWrapper` (no rounded rects, no
arbitrary ImGui primitives).

## Solution: Auto-Open + Re-Open on Close

To keep `PluginWindow::Render()` firing at all times (required for game-state
overlays like hotkey notifications), open the window on plugin load and silently
re-open it whenever BakkasMod closes it.

### Key files: `SuiteSpot.h` + `SuiteSpot.cpp`

### 1. Add a guard flag (SuiteSpot.h)

```cpp
bool isOverlayAutoOpen = false; // suppresses training browser on silent re-opens
```

### 2. Auto-open at end of `onLoad()` (SuiteSpot.cpp)

```cpp
// Open suitespot_browser silently so Render() fires every frame for the hotkey overlay.
// isOverlayAutoOpen guards OnOpen() so the training browser does NOT pop open.
isOverlayAutoOpen = true;
gameWrapper->Execute([this](GameWrapper*) {
    cvarManager->executeCommand("openmenu suitespot_browser");
});
```

`Execute()` defers to the game thread (next frame). Never call `executeCommand`
inline inside a lifecycle hook — BakkasMod may be mid-sequence.

### 3. Guard `OnOpen()` (SuiteSpot.cpp)

```cpp
void SuiteSpot::OnOpen() {
    LOG("SuiteSpot: OnOpen called (autoOpen={})", isOverlayAutoOpen);
    isBrowserOpen = true;
    if (!isOverlayAutoOpen && trainingPackUI) {
        trainingPackUI->SetOpen(true);   // only show training browser on real user open
    }
    isOverlayAutoOpen = false;
}
```

### 4. Re-open silently in `OnClose()` (SuiteSpot.cpp)

```cpp
void SuiteSpot::OnClose() {
    LOG("SuiteSpot: OnClose — re-opening silently to keep hotkey overlay alive");
    isOverlayAutoOpen = true;
    gameWrapper->Execute([this](GameWrapper*) {
        cvarManager->executeCommand("openmenu suitespot_browser");
    });
}
```

## Render() Entry Pattern

With the window permanently open, `Render()` fires every frame. Guard at the top
for performance — return immediately when nothing needs drawing:

```cpp
void SuiteSpot::Render() {
    if (!imgui_ctx) return;
    ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(imgui_ctx));

    if (!hotkeyOverlay.visible) return;   // fast path — most frames exit here
    // ... draw overlay
}
```

`imgui_ctx` is set in `SetImGuiContext()`, which BakkasMod calls when the window
first enters its render list. On the very first frame after `openmenu` it may be
0 — the guard handles this safely.

## Behaviour Summary

| Event | `isOverlayAutoOpen` | `trainingPackUI->SetOpen()` called? |
|-------|---------------------|--------------------------------------|
| Plugin load (auto-open) | `true` | No |
| User opens menu (hotkey/F2) | `false` | Yes |
| User presses Esc | `true` (set in OnClose) | No (silent re-open) |

The training browser opens/closes via its own UI controls (`trainingPackUI->SetOpen()`),
independently of the `suitespot_browser` window lifecycle.

## Diagnostic Technique

To confirm whether `Render()` is ever called, add a one-shot log at the top:

```cpp
static bool renderLoggedOnce = false;
if (!renderLoggedOnce) {
    LOG("SuiteSpot::Render() called — imgui_ctx={} visible={}", (bool)imgui_ctx, hotkeyOverlay.visible);
    renderLoggedOnce = true;
}
```

If this line never appears in `bakkesmod.log` after triggering a notifier, the
window is not open and `Render()` is not being called.
