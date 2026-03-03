# Plan: On-Demand Overlay Window (Remove Always-On Pattern)

## Context

The hotkey toast overlay currently keeps `suitespot_browser` permanently open so that
`PluginWindow::Render()` fires every frame. This was necessary because BakkesMod only
calls `Render()` while the window is in its active-windows list. The result is a
re-open loop in `OnClose()` and an `isOverlayAutoOpen` guard that suppresses the
training browser UI on silent re-opens.

Since `Render()` is only needed when a toast is actually visible (at most 7s after a
hotkey press), we can open the window on-demand and close it when the toast expires.
This eliminates the always-on overhead and the guard complexity entirely.

## Approach: Open on hotkey, close on expiry

| State | Before | After |
|-------|--------|-------|
| Plugin loaded, idle | Window always open | Window closed |
| Hotkey pressed | Already open, sets `visible=true` | Opens window + sets `visible=true` |
| Toast visible (7s) | Renders every frame | Renders every frame |
| Toast expires | Sets `visible=false`, keeps rendering (no-op) | Sets `visible=false`, closes window |
| User presses Esc | `OnClose` silently re-opens | `OnClose` does nothing special |

## Files to Modify

- `SuiteSpot.cpp` — 3 targeted changes
- `SuiteSpot.h` — remove `isOverlayAutoOpen` field

---

## Changes

### 1. `SuiteSpot.h` — Remove `isOverlayAutoOpen`

Remove:
```cpp
bool isOverlayAutoOpen = false;
```

### 2. `SuiteSpot.cpp` — `onLoad()`: Remove auto-open block

Remove the block added at the end of `onLoad()`:
```cpp
// Open suitespot_browser silently so Render() fires every frame for the hotkey overlay.
// isOverlayAutoOpen guards OnOpen() so the training browser does NOT pop open.
isOverlayAutoOpen = true;
gameWrapper->Execute([this](GameWrapper*) {
    cvarManager->executeCommand("openmenu suitespot_browser");
});
```

### 3. `SuiteSpot.cpp` — `OnOpen()`: Remove `isOverlayAutoOpen` guard

Before:
```cpp
void SuiteSpot::OnOpen() {
    LOG("SuiteSpot: OnOpen called (autoOpen={})", isOverlayAutoOpen);
    isBrowserOpen = true;
    if (!isOverlayAutoOpen && trainingPackUI) {
        trainingPackUI->SetOpen(true);
    }
    isOverlayAutoOpen = false;
}
```

After:
```cpp
void SuiteSpot::OnOpen() {
    LOG("SuiteSpot: OnOpen called");
    isBrowserOpen = true;
    if (trainingPackUI) {
        trainingPackUI->SetOpen(true);
    }
}
```

### 4. `SuiteSpot.cpp` — `OnClose()`: Remove re-open loop

Before:
```cpp
void SuiteSpot::OnClose() {
    if (isUnloading) return;
    LOG("SuiteSpot: OnClose — re-opening silently to keep hotkey overlay alive");
    isOverlayAutoOpen = true;
    gameWrapper->Execute([this](GameWrapper*) {
        cvarManager->executeCommand("openmenu suitespot_browser");
    });
}
```

After:
```cpp
void SuiteSpot::OnClose() {
    LOG("SuiteSpot: OnClose");
    isBrowserOpen = false;
    if (trainingPackUI) {
        trainingPackUI->SetOpen(false);
    }
}
```

### 5. `SuiteSpot.cpp` — `ShowToastForAction()`: Open window when toast starts

After:
```cpp
void SuiteSpot::ShowToastForAction(const std::string& message, bool isError)
{
    hotkeyOverlay.text = message;
    hotkeyOverlay.startTime = std::chrono::steady_clock::now();
    hotkeyOverlay.duration = 7.0f;
    hotkeyOverlay.isError = isError;
    hotkeyOverlay.visible = true;

    // Open the overlay window so Render() starts firing.
    // isUnloading guard prevents scheduling Execute() against freed `this`.
    if (!isUnloading) {
        gameWrapper->Execute([this](GameWrapper*) {
            cvarManager->executeCommand("openmenu suitespot_browser");
        });
    }
}
```

### 6. `SuiteSpot.cpp` — `Render()`: Close window when toast expires

Before (expiry path):
```cpp
if (elapsed >= hotkeyOverlay.duration) {
    hotkeyOverlay.visible = false;
    return;
}
```

After:
```cpp
if (elapsed >= hotkeyOverlay.duration) {
    hotkeyOverlay.visible = false;
    // Close window — no more Render() calls needed until next hotkey press.
    // Execute() defers closemenu to next frame, safe to call from Render().
    if (!isUnloading) {
        gameWrapper->Execute([this](GameWrapper*) {
            cvarManager->executeCommand("closemenu suitespot_browser");
        });
    }
    return;
}
```

---

## Edge Cases

- **Hotkey pressed while toast already visible:** `ShowToastForAction()` resets `startTime`
  and calls `openmenu` again — harmless if window is already open (BakkasMod no-ops it).
- **User manually opens the browser (F2/hotkey) while overlay is showing:** `OnOpen()` now
  unconditionally calls `trainingPackUI->SetOpen(true)`. This is correct — if a user opens
  the menu, they should see the browser. When the toast expires, `closemenu` will close the
  overlay window AND the training browser. This is a minor behavior change worth noting.
- **Plugin unload during active toast:** `isUnloading` guards both `Execute()` calls.

## Note on Edge Case (manual open during toast)

If the user opens the training browser manually while a toast is visible, the 7s expiry will
call `closemenu suitespot_browser` and close both. This is acceptable since the toast would
rarely outlast user interaction. If it becomes an issue, we can track whether the user opened
it manually via `isBrowserOpen` and skip the `closemenu` in that case.

## Verification

1. Build: `powershell -Command "& 'C:\Program Files\Microsoft Visual Studio\18\Community\MSBuild\Current\Bin\amd64\MSBuild.exe' 'C:\Users\bmile\Source\Repos\SuiteSpot\SuiteSpot.sln' /p:Configuration=Release /p:Platform=x64 /v:minimal"`
2. Hot-reload plugin in BakkasMod
3. Press a mapped hotkey — toast should appear within one frame
4. Wait 7s — toast should fade and disappear; check `bakkesmod.log` for `OnClose` log
5. Press Esc in BakkasMod menus — should no longer silently re-open the overlay window
6. Press hotkey again after close — toast should reappear normally
