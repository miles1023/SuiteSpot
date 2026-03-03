# SuiteSpot CVar Console Menu — Design Document
**Status:** In Progress — descriptions complete, UI layout approved, ready for implementation plan
**Last updated:** 2026-03-03
**Owner:** bmile (non-technical) — all technical decisions made by developer/AI

---

## Project Summary

Add a new tab inside the **SuiteSpot BakkesMod plugin** that gives users a searchable, clickable list of every executable console variable (CVar) available in BakkesMod's F6 console. Each CVar will have a plain-English description, an inline input box for setting values, and a one-click button that sends the command to BakkesMod exactly as if the user typed it manually.

---

## Context & Motivation

BakkesMod has ~271 CVars spread across its core system and many plugins. Most users don't know they exist. The F6 console requires knowing the exact CVar name by memory. This feature makes every CVar discoverable and executable without ever opening the console.

---

## Verified Architecture Facts
*(Do not re-research these — confirmed by reading actual files)*

### Source of Truth: `config.cfg`
- **Location:** `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\cfg\config.cfg`
- **Format:** `cvar_name "current_value" //plain comment`
- **271 CVars** currently in this file
- BakkesMod **automatically writes** every registered CVar here when plugins load
- If a CVar is in config.cfg → its plugin is loaded → the command is executable
- If a plugin is unloaded → its CVars are automatically removed from config.cfg
- This file is the **only reliable source** for knowing what CVars are currently executable

### Plugin Lifecycle & Refresh Pattern
- **`onLoad()`** fires on: initial BakkesMod boot AND every hotreload
- **`onUnload()`** fires when plugin is unloaded
- Hotreload mechanism (from `bakkes_patchplugin.py`): connects to RCON WebSocket → sends `plugin unload <name>` → replaces DLL → sends `plugin load <name>`
- Therefore: **parse config.cfg inside `onLoad()`** and the CVar list will always be current for both boot and hotreload — no timers, file watchers, or manual refresh needed

### Command Execution
- Internal API: `cvarManager->executeCommand("cvar_name value")`
- This is identical to the user typing in the F6 console
- RCON WebSocket also available (port 9002) but unnecessary for an in-process plugin

### RCON System
- **Port:** 9002 (configurable via `rcon_port` CVar)
- **Auth:** `rcon_password` (currently `atUYTTbY0PxvWQEs` — do not expose in UI)
- **Whitelist:** `rcon_commands.cfg` lists allowed RCON commands: `ws_inventory`, `sendback`, `rcon_password`, `plugin`, `cl_settings_refreshplugins`, `rcon_refresh_allowed`
- Not needed for this feature but explains the hotreload mechanism

### SuiteSpot Plugin
- **DLL:** `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\plugins\SuiteSpot.dll`
- **Data dir:** `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\data\SuiteSpot\`
- **UI Framework:** Dear ImGui (same as all BakkesMod plugins)
- **Existing tabs:** TrainingSuite, Workshop
- **Data pattern:** JSON files for persistent data (training_packs.json, etc.)
- **No source code** in this working directory — SuiteSpot source lives elsewhere

### SDK
- **Location:** `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\bakkesmodsdk\`
- Key headers: `cvarmanagerwrapper.h`, `bakkesmodplugin.h`, `bakkesmodsdk.h`
- `CVarManagerWrapper::executeCommand(std::string command, bool log = true)`
- `CVarManagerWrapper::getCvar(std::string cvar)` — returns CVarWrapper (safe if CVar doesn't exist)
- `CVarManagerWrapper::registerCvar(...)` — how plugins add their CVars

---

## Known CVar Prefixes & Plugin Mapping
*(Derived from config.cfg — these are all active plugins)*

| Prefix | Plugin | Example CVars |
|--------|--------|---------------|
| `cl_anonymizer_*` | BakkesMod core | `cl_anonymizer_mode_team`, `cl_anonymizer_scores` |
| `cl_autoreplayupload_*` | Auto Replay Uploader | `cl_autoreplayupload_ballchasing`, `cl_autoreplayupload_save` |
| `cl_console_*` | BakkesMod core | `cl_console_enabled`, `cl_console_key` |
| `cl_demo_*` | BakkesMod core | `cl_demo_autosave` |
| `cl_draw_*` | BakkesMod core | `cl_draw_fpsonboot`, `cl_draw_systemtime` |
| `cl_freeplay_*` | BakkesMod core | `cl_freeplay_carcolor` |
| `cl_goalreplay_*` | BakkesMod core | `cl_goalreplay_pov` |
| `cl_itemmod_*` | BakkesMod core | `cl_itemmod_enabled`, `cl_itemmod_code` |
| `cl_loadout_*` | BakkesMod core | `cl_loadout_color_enabled` |
| `cl_notifications_*` | BakkesMod core | `cl_notifications_ranked` |
| `cl_soccar_*` | BakkesMod core | `cl_soccar_boostcounter`, `cl_soccar_jumphelp` |
| `sv_freeplay_*` | BakkesMod core | `sv_freeplay_enablegoal`, `sv_freeplay_rumble_enable_*` |
| `sv_training_*` | BakkesMod core | `sv_training_enabled`, `sv_training_var_loc` |
| `sv_soccar_*` | BakkesMod core | `sv_soccar_unlimitedflips`, `sv_soccar_goalslomo` |
| `ranked_*` | BakkesMod core | `ranked_autogg`, `ranked_showranks` |
| `rcon_*` | RCON Plugin | `rcon_enabled`, `rcon_port` |
| `defender_*` | Defender Plugin | `defender_active`, `defender_difficulty` |
| `dolly_*` | DollyCam Plugin | `dolly_render`, `dolly_interpmode` |
| `ingamerank_*` | In-Game Rank | `ingamerank_enabled`, `ingamerank_playlist` |
| `mech_*` | Mechanical Plugin | `mech_enabled`, `mech_disable_jump` |
| `revela_*` | Revela Input HUD | `revela_hud_enabled`, `revela_hud_scale` |
| `sf_*` | Speedflip Trainer | `sf_enabled`, `sf_left_angle`, `sf_right_angle` |
| `wallhit_*` | Wallhit Training | `wallhit_mode`, `wallhit_speed` |
| `GSA_*` | Goal Speed Anywhere | `GSA_Enable`, `GSA_Color`, `GSA_Duration` |
| `bakkesmod_style_*` | BakkesMod core | `bakkesmod_style_alpha`, `bakkesmod_style_scale` |
| `touch_marker_*` | BakkesMod core | `touch_marker_enabled`, `touch_marker_size` |
| `queuemenu_*` | BakkesMod core | `queuemenu_close_joining` |
| `shot_*` | Training Plugin | `shot_initial_ball_location_x`, `shot_mirror` |
| `redirect_*` | Redirect Plugin | `redirect_shot_speed`, `redirect_pass_predict` |
| `rebound_*` | Rebound Plugin | `rebound_shotspeed`, `rebound_addedheight` |
| `recovery_*` | Recovery Plugin | `recovery_bumpspeed_linear`, `recovery_cooldown` |
| `airdrib_*` | Airdribble Plugin | `airdrib_boost`, `airdrib_variance` |
| `ring_*` | BakkesMod core | `ring_enabled`, `ring_color`, `ring_size` |
| `rs_*` | RocketStats | `rs_in_file`, `rs_toggle_logo` |
| `workshop_*` | Workshop Plugin | `workshop_shot_random` |
| `gui_*` | BakkesMod core | `gui_quicksettings_rows` |

---

## Design Decisions — SETTLED

| Decision | Choice | Reason |
|----------|--------|--------|
| Source of truth | `config.cfg` | Only file with all currently-executable CVars |
| Refresh trigger | `onLoad()` only | Covers both boot + hotreload automatically |
| Command execution | `executeCommand()` | In-process, identical to F6 console |
| UI location | New tab in SuiteSpot | Consistent with existing plugin structure |
| UI framework | Dear ImGui | Already used by SuiteSpot |
| Plugin detection | Presence in config.cfg | If it's there, it's active. Simple. |
| Tab name | **"F6 For Dummies"** | User-chosen — approachable, memorable |
| Hidden CVars | Show everything | No filtering — user sees all 271 |
| Execute feedback | **Green text inline in tab on success. Red text inline on invalid/error. No toast, no popup.** | Simple colored text only |
| Live value sync | **Yes** | Re-read config.cfg after execute to reflect new value |
| Input control type | **Single `InputText` for all types, with watermark hint text showing accepted format** | Simple, consistent, no special controls |
| Sorting/categorization | **Alphabetical, case-insensitive** | Flat A-Z list, no grouping — predictable and simple |
| Search scope | **Both CVar name AND description** | Typing a prefix or plain-English term both work |
| Source code location | Developer has it elsewhere | Not in this repo; developer integrates from plan |
| Reset to default | **Not in v1** | Keep scope small |
| Validation | **Warn in red toast if value looks invalid, still executes** | BakkesMod ignores bad values anyway |

### Input Type Rules (Detected from current value in config.cfg)

| Value Pattern | Example | Input Control |
|--------------|---------|---------------|
| `"0"` or `"1"` | `ranked_autogg "1"` | Plain text box (v2: checkbox) |
| Plain number | `GSA_Duration "2"` | Plain text box |
| Plain decimal | `bakkesmod_style_alpha "0.611"` | Plain text box |
| Range `"(N, N)"` | `wallhit_speed "(800, 1000)"` | **Two boxes: Min \| Max** |
| Color `"(N, N, N, N)"` | `GSA_Color "(0, 255, 0, 255)"` | **Color picker button** |
| Plain string | `cl_console_key "Tilde"` | Plain text box |
| Empty string | `cl_itemmod_code ""` | Plain text box |

Detection logic: if value starts with `(` and has exactly 2 comma-separated numbers → range. If 4 numbers → color.

---

## Design Decisions — OPEN / UNRESOLVED

### 🔴 CRITICAL: CVar Descriptions — APPROACH DECIDED, WORK NOT STARTED
**Decision:** Generate comprehensive plain-English descriptions for all 271 CVars. This is the **most important aspect of the entire feature.**

**Requirements:**
- Non-technical language — written for players, not developers
- Pull from multiple sources: config.cfg comments, BAKKESMOD_COMMANDS.md (existing partial doc), community threads/forums online
- Stored in `data/SuiteSpot/cvars_descriptions.json`
- config.cfg raw comment used as fallback for any CVar not in the JSON (future new plugins)
- Must be comprehensive — every single CVar needs a description

**Work to do:**
- [ ] Research community sources (BakkesMod wiki, reddit, discord docs) for each plugin's CVars
- [ ] Write plain-English descriptions for all 271 CVars
- [ ] Assign each CVar a feature tag/hint for future categorization
- [ ] Write `cvars_descriptions.json` with structure: `{ "cvar_name": { "description": "...", "default": "...", "type": "..." } }`

**⚠️ This work has NOT been done yet. This is the primary blocker before implementation.**

### 🟡 MINOR: `cvars_descriptions.json` Schema
**Still needs to be finalized.** Proposed structure:
```json
{
  "ranked_autogg": {
    "description": "Automatically types 'GG' in chat when the match ends.",
    "default": "1",
    "type": "boolean",
    "raw_comment": "Automatically says GG at the end of the match"
  },
  "wallhit_speed": {
    "description": "How fast the ball travels toward the wall in Wallhit training. Left number is slowest, right is fastest.",
    "default": "(800, 1000)",
    "type": "range",
    "raw_comment": ""
  }
}
```
Types: `"boolean"`, `"number"`, `"decimal"`, `"range"`, `"color"`, `"string"`

---

## Proposed UI Layout (APPROVED)

```
┌─────────────────────────────────────────────────────────────────┐
│ [TrainingSuite] [Workshop] [F6 For Dummies]                      │
├─────────────────────────────────────────────────────────────────┤
│  Search CVars...                                                 │
├─────────────────────────────────────────────────────────────────┤
│ ← pad →│← CVar Name (col 1) →│← Description (col 2) ──────────→│← Input (col 3) →│← Btn →│
│        │                      │                                  │                 │       │
│        │ airdrib_boost        │ Controls how fast the ball is    │ [-1.0] | [-1.0] │  ▶    │
│        │                      │ shot during air dribble          │                 │       │
│        │                      │                                  │                 │       │
│        │ ranked_autogg        │ Automatically types 'GG' in      │      [1]        │  ▶    │
│        │                      │ chat when the match ends         │                 │       │
│        │                      │                                  │                 │       │
│        │ wallhit_speed        │ Ball speed range for standard    │ [800] | [1000]  │  ▶    │
│        │                      │ Wallhit shots toward the wall    │                 │       │
│        │                      │                                  │                 │       │
│        │ GSA_Color            │ Color and opacity of the goal    │   [color btn]   │  ▶    │
│        │                      │ speed text shown on screen       │                 │       │
└─────────────────────────────────────────────────────────────────┘
│  ✓ ranked_autogg 1   ← green inline feedback, auto-fades        │
└─────────────────────────────────────────────────────────────────┘
```

### Layout Structure — ImGui 1.75 Implementation (manual cursor positioning, no Tables API)

**⚠️ ImGui 1.75 confirmed — Tables API not available. Using manual SetCursorPos layout.**

---

#### Global constants — defined once, used everywhere

```cpp
const float PAD_OUTER  = 10.0f;  // left AND right margin from window edge to content
const float PAD_TOP    = 8.0f;   // space above the search bar and above the first row
const float PAD_BOTTOM = 8.0f;   // space below the last row / feedback bar
const float PAD_ROW    = 6.0f;   // vertical padding inside EACH row (applied top AND bottom)
const float PAD_COL    = 8.0f;   // horizontal gap between every column
const float NAME_W     = 180.0f; // fixed width of the CVar name column
const float INPUT_W    = 160.0f; // fixed width of the input column
const float BTN_W      = 36.0f;  // fixed width of the execute button column

// Derived at render time (recalculated each frame):
// float contentWidth = ImGui::GetContentRegionAvail().x;
// float descWidth    = contentWidth - PAD_OUTER - NAME_W - PAD_COL - INPUT_W - PAD_COL - BTN_W - PAD_OUTER;
// float nameX        = PAD_OUTER;
// float descX        = PAD_OUTER + NAME_W + PAD_COL;
// float inputX       = descX + descWidth + PAD_COL;
// float btnX         = inputX + INPUT_W + PAD_COL;
```

---

#### Render order per frame

```
[PAD_TOP vertical space]
[Search bar — full width minus PAD_OUTER on both sides]
[PAD_ROW vertical space]
[BeginChild scrollable list]
  for each filtered CVar (sorted A-Z):
    rowStartY = GetCursorPosY()

    // Name — top-left of row, padded in from left and from top of row
    SetCursorPos(nameX, rowStartY + PAD_ROW)
    PushFont(bold) → Text(cvar_name) → PopFont()
    if IsItemHovered() → SetTooltip(raw_comment)

    // Description — same top Y as name, padded in, word-wraps downward
    SetCursorPos(descX, rowStartY + PAD_ROW)
    PushTextWrapPos(descX + descWidth)
    TextWrapped(description)
    PopTextWrapPos()
    afterDescY = GetCursorPosY()   ← true bottom of this row's content

    // Input box(es) — anchored to rowStartY + PAD_ROW, fixed right side
    SetCursorPos(inputX, rowStartY + PAD_ROW)
    SetNextItemWidth(INPUT_W)
    InputText / two InputTexts / ColorButton depending on type

    // Execute button — anchored to rowStartY + PAD_ROW
    SetCursorPos(btnX, rowStartY + PAD_ROW)
    SmallButton(">")

    // Advance cursor — always driven by the description height, never by widgets
    SetCursorPosY(afterDescY + PAD_ROW)   ← bottom padding after row

    Separator()  // subtle divider between rows
[EndChild]
[PAD_BOTTOM vertical space]
[Feedback line — PAD_OUTER from left, PAD_BOTTOM from bottom]
```

---

#### Search bar

```cpp
ImGui::SetCursorPosX(PAD_OUTER);
ImGui::SetNextItemWidth(contentWidth - PAD_OUTER * 2);
ImGui::InputText("##search", searchBuf, sizeof(searchBuf));
```

Filters in real-time on both CVar name and description text, case-insensitive.

---

#### Input type rendering (inside input column)

Single `InputText` for every CVar type, full width `INPUT_W`. No special controls.

Watermark/hint text (shown when box is empty) communicates the expected format:

| Type | Watermark text |
|------|---------------|
| `boolean` | `0 or 1` |
| `number` | `whole number` |
| `decimal` | `e.g. 0.5` |
| `range` | `(min, max)` |
| `color` | `(R, G, B, A)` |
| `string` | `text` |

Current value is always pre-filled from config.cfg, so the watermark only appears if the box is cleared.

---

#### Low-Effort High-Reward Features (included in v1)

| Feature | Implementation | Effort |
|---------|---------------|--------|
| **Uncertain CVar marker** | If `uncertain == true` in JSON, render a small `(?)` in muted color after the CVar name. Tooltip on hover: "Description may be approximate." | 2 lines |
| **Result count label** | Below search bar: `"Showing 43 of 266"` — updates live as user types. Tells user the filter is working. | 3 lines |
| **Clear search [×] button** | `SameLine` after the search `InputText`, small `[×]` button that calls `memset(searchBuf, 0, sizeof(searchBuf))`. | 4 lines |
| **Copy command to clipboard** | Second small button per row (after ▶). Copies the full command string `"cvar_name value"` to clipboard via `ImGui::SetClipboardText()`. Useful for sharing settings. | 4 lines |
| **Default value tooltip on input** | When hovering the input box, `SetTooltip("Default: %s", cvar.default_val.c_str())`. Zero extra state. | 2 lines |
| **Alternating row background** | `PushStyleColor(ImGuiCol_ChildBg, ...)` alternating per row index. Improves readability of long list. | 3 lines |
| **"Only show uncertain" toggle** | Small checkbox above the list: `[ ] Show only uncertain (*)`. Filters to the 26 flagged CVars for easy future verification iteration. | 5 lines |

---

#### Feedback bar (below scrollable list)

```cpp
// Rendered after EndChild, before end of tab
ImGui::SetCursorPosX(PAD_OUTER);
// Green on success:
ImGui::TextColored(ImVec4(0,1,0,alpha), "✓ %s %s", lastName, lastValue);
// Red on error:
ImGui::TextColored(ImVec4(1,0.3f,0.3f,alpha), "✗ %s", lastError);
// alpha fades to 0 over 3 seconds using (float)(currentTime - feedbackTime) / 3.0f
```

---

## Files To Create / Modify

| File | Action | Purpose |
|------|--------|---------|
| `SuiteSpot.cpp` (source, not in this repo) | Modify | Add new tab, `onLoad()` parsing logic, ImGui rendering |
| `data/SuiteSpot/cvars_descriptions.json` | Create | Plain-English descriptions, categories, type hints per CVar |
| `cfg/config.cfg` | Read-only | Runtime source for active CVars and current values |

---

## Next Steps (In Order)

1. ~~**Research + write `cvars_descriptions.json`**~~ ✅ DONE — 266 CVars, proofed by GPT-5.3-Codex
2. ~~**Get user approval on UI layout**~~ ✅ DONE — layout approved with column/padding/wordwrap spec
3. **ACTIVE: Invoke writing-plans skill** — Create the full implementation plan for the developer

---

## All ImGui Additions — Full Audit

| File | What it provides | Used? | How |
|------|-----------------|-------|-----|
| `imgui_additions.h/.cpp` | `Combo` / `ListBox` accepting `std::vector<std::string>` | No | No dropdowns needed |
| `imgui_searchablecombo.h/.cpp` | Filterable combo **dropdown** popup | No | Wrong UX — we need a flat visible list, not a picker |
| `imgui_rangeslider.h` | `RangeSliderFloat` / `RangeSliderInt` — dual-handle range slider | No | All inputs are plain `InputText` with watermarks |
| `imguivariouscontrols.h` | `SmallCheckButton` — toggleable button for booleans | No | All inputs are plain `InputText` with watermarks |
| `imguivariouscontrols.h` | `ColorCombo` — color swatch + inline dropdown color picker | No | All inputs are plain `InputText` with watermarks |
| `imguivariouscontrols.h` | `ColorChooser` — full-screen color chooser popup | No | `ColorCombo` is sufficient and inline |
| `imguivariouscontrols.h` | `PopupMenuSimpleCopyCutPasteOnLastItem` | No | Not needed |
| `imguivariouscontrols.h` | `InputTextWithAutoCompletion` | No | Search is a plain filter, not autocomplete |
| `imguivariouscontrols.h` | `TreeView`, `PlotHistogram`, `AnimatedImage`, `Timeline` | No | Not relevant |
| `imgui_timeline.h` | Timeline editor | No | Not relevant |

---

## Custom ImGui Additions (Reviewed — Neither Used)

| File | What it does | Used? |
|------|-------------|-------|
| `imgui_additions.h/.cpp` | Overloads `Combo` and `ListBox` to accept `std::vector<std::string>` instead of raw callbacks | No — we don't use dropdowns |
| `imgui_searchablecombo.h/.cpp` | Combo box with a built-in text filter that shows a filtered **dropdown popup** | No — wrong UX pattern. Our search filters a flat scrollable list of visible rows, not a popup picker. Use plain `InputText` instead. |

---

## What NOT To Do
- Do not re-research the config.cfg structure — it's verified
- Do not re-research the refresh pattern — `onLoad()` is the answer
- Do not add RCON complexity — not needed for in-process plugin
- Do not overthink plugin detection — config.cfg presence = plugin active
- Do not build type-aware input controls in v1 — plain text input is sufficient
