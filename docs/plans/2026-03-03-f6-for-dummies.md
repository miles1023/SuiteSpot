# F6 For Dummies — Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Add a searchable, clickable CVar browser tab called "F6 For Dummies" to the SuiteSpot BakkesMod plugin, making all 271 executable console variables discoverable without opening the F6 console.

**Architecture:** Parse `config.cfg` once in `onLoad()` to build an in-memory list of active CVars. Render them in a scrollable, searchable ImGui table inside a new SuiteSpot tab. When user clicks execute, call `cvarManager->executeCommand()` with the CVar name and current input value.

**Tech Stack:** C++17, Dear ImGui, BakkesMod SDK, nlohmann/json v3.11.3 (`IMGUI/json.hpp`), `config.cfg` as runtime data source.

---

## Pre-Work: Create Branch

Before anything else, create a feature branch:

```bash
cd C:\Users\bmile\Source\Repos\SuiteSpot
git checkout -b feature/f6-for-dummies
```

All work goes on this branch. Do not commit to main/master.

---

## Pre-Work: Read First

**SuiteSpot source code:** `C:\Users\bmile\Source\Repos\SuiteSpot`

Before touching any code, read these files to understand existing patterns:

- Design doc: `C:\Users\bmile\.claude\plans\temporal-pondering-taco.md` — all architecture decisions
- `SuiteSpot.h` / `SuiteSpot.cpp` — main plugin class, `onLoad()` at line ~554
- `SettingsUI.h` / `SettingsUI.cpp` — **this is where tabs live**, tab bar at line ~242
- `MapManager.h` / `MapManager.cpp` — path helpers: `GetDataRoot()`, `GetSuiteSpotRoot()`
- `TrainingPackManager.cpp` — canonical JSON loading pattern to follow
- `IMGUI/json.hpp` — nlohmann/json v3.11.3, already in project
- SDK: `bakkesmodsdk\include\bakkesmod\wrappers\cvarmanagerwrapper.h`
- Data reference: `cfg\config.cfg` — runtime source of truth (271 CVars)

**Important constraints:**
- Do NOT use RCON — use `cvarManager->executeCommand()` only
- Do NOT add file watchers or timers — `onLoad()` is the only refresh trigger
- Do NOT hide any CVars — show all 271
- `config.cfg` is read-only at runtime — never write to it

---

## Task 1: Generate `cvars_descriptions.json`

> ⚠️ **THIS TASK HAS ITS OWN DEDICATED PLAN.**
> See: `C:\Users\bmile\.claude\plans\2026-03-03-f6-for-dummies-descriptions.md`
> Run that plan in a **separate full-context session** before continuing here.
> The descriptions file must exist at the path below before Task 2 will work end-to-end.

**Expected output:** `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\data\SuiteSpot\cvars_descriptions.json`

This task can be worked in parallel with Tasks 2–3 (parser and loader can be written without the JSON file present — the loader handles a missing file gracefully). Do not block on it unless you need to test the full feature end-to-end.

---

## Task 1a (can proceed in parallel): Build `cvars_descriptions.json`

**This is the most important task. Do it before writing any C++ code.**

The descriptions file is a JSON object mapping every CVar name to metadata. It ships with the plugin inside `data/SuiteSpot/`.

**Files:**
- Create: `data/SuiteSpot/cvars_descriptions.json`
- Reference: `cfg/config.cfg` (all 271 CVars with their raw comments)
- Reference: `bakkesmod/BAKKESMOD_COMMANDS.md` (partial existing documentation)

### Step 1: Extract all CVar names from config.cfg

Run this from the bakkesmod directory to get a clean list:
```bash
grep -oP '^[a-zA-Z_][a-zA-Z0-9_]*(?= ")' cfg/config.cfg
```
This outputs one CVar name per line. Pipe to a file if needed for reference.

### Step 2: Write the JSON file

**Schema per entry:**
```json
{
  "cvar_name": {
    "description": "Plain English. Written for a player, not a developer. No jargon.",
    "default": "the_default_value_from_config",
    "type": "boolean|number|decimal|range|color|string",
    "raw_comment": "original comment from config.cfg, copied verbatim"
  }
}
```

**Type detection rules (derive from current value in config.cfg):**
| Value pattern | Type to assign |
|---|---|
| `"0"` or `"1"` only | `"boolean"` |
| Integer like `"2"`, `"30"` | `"number"` |
| Decimal like `"0.611000"` | `"decimal"` |
| Starts with `(` and has 2 comma-separated numbers | `"range"` |
| Starts with `(` and has 4 comma-separated numbers | `"color"` |
| Everything else | `"string"` |

**Writing good descriptions — rules:**
- Max 2 sentences. First sentence: what it does. Second (optional): when you'd change it.
- Never use the words: "cvar", "variable", "flag", "boolean", "plugin", "toggle", "parameter"
- Write as if explaining to a friend who plays Rocket League but has never modded a game
- For on/off settings: say "Turns on/off..." not "Enables/disables..."
- For ranges: say "Controls how [fast/high/far]... Left number = minimum, right = maximum"
- For colors: say "Sets the color of [thing]. Values are Red, Green, Blue, Transparency (0–255 each)"

**Example good descriptions:**
```json
"ranked_autogg": {
  "description": "Automatically types 'GG' in chat when a ranked match ends. Turn this off if you prefer to type it yourself or not at all.",
  "default": "1",
  "type": "boolean",
  "raw_comment": "Automatically says GG at the end of the match"
},
"wallhit_speed": {
  "description": "How fast the ball moves toward the wall in Wallhit training shots. Left number is the slowest possible speed, right is the fastest.",
  "default": "(800, 1000)",
  "type": "range",
  "raw_comment": ""
},
"GSA_Color": {
  "description": "The color of the goal speed text shown on screen. Values are Red, Green, Blue, and Transparency — each from 0 (none) to 255 (full).",
  "default": "(0, 255, 0, 255)",
  "type": "color",
  "raw_comment": "Goal speed anywhere text color"
},
"bakkesmod_style_alpha": {
  "description": "How see-through the BakkesMod menus are. 0 = completely invisible, 1 = fully solid.",
  "default": "0.611000",
  "type": "decimal",
  "raw_comment": "Alpha for gui"
}
```

**Research sources for unclear CVars** (in order of reliability):
1. `BAKKESMOD_COMMANDS.md` — partial descriptions already written in plain English
2. BakkesMod wiki: https://bakkesmod.fandom.com/wiki/BakkesMod_Wiki
3. BakkesMod subreddit: search `site:reddit.com/r/RocketLeague bakkesmod [cvar_name]`
4. Plugin GitHub repos — see README.md in BakkesMod2-Plugins for each built-in plugin
5. The raw `//comment` in config.cfg — rephrase into plain English as last resort

**All 271 CVars to document** (from config.cfg — grouped here by prefix for writing convenience, displayed alphabetically in UI):

```
GSA_Color, GSA_Decimal_Precision, GSA_Duration, GSA_Enable, GSA_Shadow,
GSA_X_Position, GSA_Y_Position,
airdrib_boost, airdrib_spin, airdrib_variance,
alliteration_andy,
bakkesmod_log_instantflush, bakkesmod_style_alpha, bakkesmod_style_light,
bakkesmod_style_scale, bakkesmod_style_theme,
bounceaway_speed, bounceto_speed,
cl_alphaboost,
cl_anonymizer_alwaysshowcars, cl_anonymizer_bot, cl_anonymizer_hideforfeit,
cl_anonymizer_kickoff_quickchat, cl_anonymizer_mode_opponent,
cl_anonymizer_mode_party, cl_anonymizer_mode_team, cl_anonymizer_scores,
cl_autoreplayupload_ballchasing, cl_autoreplayupload_ballchasing_authkey,
cl_autoreplayupload_ballchasing_visibility, cl_autoreplayupload_calculated,
cl_autoreplayupload_calculated_visibility, cl_autoreplayupload_filepath,
cl_autoreplayupload_notifications, cl_autoreplayupload_replaynametemplate,
cl_autoreplayupload_replaysequence, cl_autoreplayupload_save,
cl_bakkesmod_enablesupportdialog,
cl_camera_cliptofield,
cl_console_buffersize, cl_console_enabled, cl_console_height, cl_console_key,
cl_console_logkeys, cl_console_suggestions, cl_console_toggleable,
cl_console_width, cl_console_x, cl_console_y,
cl_demo_autosave, cl_demo_nameplates,
cl_draw_fpsonboot, cl_draw_systemtime, cl_draw_systemtime_format,
cl_freeplay_carcolor, cl_freeplay_stadiumcolors,
cl_goalreplay_pov, cl_goalreplay_timeout,
cl_itemmod_code, cl_itemmod_enabled,
cl_loadout_blue_primary, cl_loadout_blue_secondary, cl_loadout_color_enabled,
cl_loadout_color_same, cl_loadout_orange_primary, cl_loadout_orange_secondary,
cl_mainmenu_background,
cl_misophoniamode_enabled,
cl_notifications_enabled_beta, cl_notifications_ranked,
cl_online_status_detailed,
cl_record_fps, cl_rendering_disabled, cl_rendering_scaleform_disabled,
cl_settings_ignoreminwindowsize, cl_settings_logrefreshinfo,
cl_settings_plugin_favorites, cl_settings_refreshplugins (notifier, skip),
cl_soccar_ballfadein, cl_soccar_boostcounter, cl_soccar_jumphelp,
cl_soccar_jumphelp_carcolor, cl_training_printjson, cl_workshop_freecam,
defender_active, defender_cooldown, defender_difficulty, defender_shotspeed,
dolly_chaikin_degree, dolly_interpmode, dolly_interpmode_location,
dolly_interpmode_rotation, dolly_path_directory, dolly_render,
dolly_render_frame, dolly_spline_acc,
gui_quicksettings_rows,
ingamerank_calculate_unranked, ingamerank_enabled, ingamerank_include_extramodes,
ingamerank_include_tournaments, ingamerank_playlist, ingamerank_show_division,
ingamerank_show_playlist,
inputbuffer_reset_automatic,
max_touch_markers,
mech_disable_boost, mech_disable_handbrake, mech_disable_jump, mech_enabled,
mech_hold_boost, mech_hold_roll, mech_pitch_limit, mech_roll_limit,
mech_steer_limit, mech_throttle_limit, mech_yaw_limit,
queuemenu_close_joining, queuemenu_open_mainmenu, queuemenu_open_match_ended,
ranked_aprilfools, ranked_autogg, ranked_autogg_delay, ranked_autogg_id,
ranked_autoqueue, ranked_autosavereplay, ranked_autosavereplay_all,
ranked_disableranks, ranked_disregardplacements, ranked_showranks,
ranked_showranks_casual, ranked_showranks_casual_menu,
ranked_showranks_gameover, ranked_showranks_menu,
rcon_enabled, rcon_log, rcon_password, rcon_port, rcon_timeout,
rebound_addedheight, rebound_addedspin, rebound_resetspin, rebound_shotspeed,
rebound_side_offset,
record,
recovery_bumpspeed_angular, recovery_bumpspeed_linear,
recovery_bumpspeed_linear_z, recovery_cooldown,
redirect_on_ground, redirect_pass_offset, redirect_pass_offset_z,
redirect_pass_predict, redirect_predict_multiplier_x,
redirect_predict_multiplier_y, redirect_shot_speed,
revela_hud_bst_x, revela_hud_bst_y, revela_hud_enabled, revela_hud_jmp_x,
revela_hud_jmp_y, revela_hud_last_preset, revela_hud_replay_enabled,
revela_hud_scale, revela_hud_sld_x, revela_hud_sld_y, revela_hud_smooth_speed,
revela_hud_x, revela_hud_y,
ring_color, ring_enabled, ring_size,
rollaway_speed, rollto_speed,
rs_in_file, rs_toggle_logo,
sf_cancel_threshold, sf_change_speed, sf_enabled, sf_left_angle, sf_num_hits,
sf_remember_speed, sf_right_angle, sf_save_attempts, sf_show_angle,
sf_show_flip, sf_show_jump, sf_show_position, sf_speed, sf_speed_increment,
shootatme_bounds_x, shootatme_bounds_y, shootatme_bounds_z, shootatme_speed,
shot_countdowntime, shot_initial_ball_location_x, shot_initial_ball_location_y,
shot_initial_ball_location_z, shot_initial_ball_pitch, shot_initial_ball_roll,
shot_initial_ball_torque_pitch, shot_initial_ball_torque_roll,
shot_initial_ball_torque_yaw, shot_initial_ball_velocity_x,
shot_initial_ball_velocity_y, shot_initial_ball_velocity_z,
shot_initial_ball_yaw, shot_mirror, shot_randomization, shot_waitbeforeshot,
sv_freeplay_bindings, sv_freeplay_enablegoal, sv_freeplay_enablegoal_bakkesmod,
sv_freeplay_goalspeed, sv_freeplay_limitboost_default,
sv_freeplay_rumble_enable_boot, sv_freeplay_rumble_enable_disruptor,
sv_freeplay_rumble_enable_freezer, sv_freeplay_rumble_enable_grapplinghook,
sv_freeplay_rumble_enable_haymaker, sv_freeplay_rumble_enable_magnetizer,
sv_freeplay_rumble_enable_plunger, sv_freeplay_rumble_enable_powerhitter,
sv_freeplay_rumble_enable_spike, sv_freeplay_rumble_enable_swapper,
sv_freeplay_rumble_enable_tornado,
sv_password,
sv_soccar_enablegoal, sv_soccar_enablegoal_onlyfirstball, sv_soccar_goalslomo,
sv_soccar_goalspeed, sv_soccar_unlimitedflips,
sv_training_allowmirror, sv_training_autoshuffle, sv_training_clock,
sv_training_enabled, sv_training_goalblocker_enabled, sv_training_limitboost,
sv_training_player_velocity, sv_training_timeup_reset, sv_training_usefreeplaymap,
sv_training_userandommap, sv_training_var_car_loc, sv_training_var_car_rot,
sv_training_var_loc, sv_training_var_loc_z, sv_training_var_rot,
sv_training_var_speed, sv_training_var_spin,
touch_marker_correct_color, touch_marker_duration, touch_marker_enabled,
touch_marker_incorrect_color, touch_marker_reset_color, touch_marker_size,
wallhit_default_mode, wallhit_expert_mode, wallhit_floor, wallhit_freeze_dist,
wallhit_freeze_mode, wallhit_height, wallhit_mode, wallhit_onwall_target_ahead,
wallhit_pop_mode, wallhit_pop_speed, wallhit_speed,
workshop_shot_random
```

### Step 3: Verify

Open the JSON in a validator (e.g. https://jsonlint.com). Confirm:
- Every CVar from the list above has an entry
- No entry has an empty `"description"` field
- All `"type"` values are one of: `boolean`, `number`, `decimal`, `range`, `color`, `string`

### Step 4: Place file

Copy to: `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\data\SuiteSpot\cvars_descriptions.json`

---

## Task 2: config.cfg Parser

Write the utility that reads `config.cfg` and returns a structured list of CVars with their current values.

**Files:**
- Create: `C:\Users\bmile\Source\Repos\SuiteSpot\F6ForDummies\ConfigParser.h`
- Create: `C:\Users\bmile\Source\Repos\SuiteSpot\F6ForDummies\ConfigParser.cpp`
- Add to Visual Studio project (right-click project → Add → Existing Item)

### Step 1: Write the struct and header

```cpp
// ConfigParser.h
#pragma once
#include <string>
#include <vector>

enum class CvarType {
    Boolean,
    Number,
    Decimal,
    Range,    // "(min, max)"
    Color,    // "(r, g, b, a)"
    String
};

struct ParsedCvar {
    std::string name;
    std::string currentValue;
    std::string rawComment;
    CvarType type;

    // For Range type
    float rangeMin = 0.f;
    float rangeMax = 0.f;

    // For Color type
    float colorR = 0.f, colorG = 0.f, colorB = 0.f, colorA = 255.f;
};

class ConfigParser {
public:
    // Parse config.cfg and return all CVars sorted A-Z case-insensitive
    static std::vector<ParsedCvar> Parse(const std::string& configPath);

private:
    static CvarType DetectType(const std::string& value);
    static void ParseRange(const std::string& value, float& min, float& max);
    static void ParseColor(const std::string& value, float& r, float& g, float& b, float& a);
};
```

### Step 2: Write the parser

```cpp
// ConfigParser.cpp
#include "ConfigParser.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

std::vector<ParsedCvar> ConfigParser::Parse(const std::string& configPath) {
    std::vector<ParsedCvar> results;
    std::ifstream file(configPath);
    if (!file.is_open()) return results;

    std::string line;
    // Regex: name "value" //comment
    // Matches lines like: ranked_autogg "1" //Automatically says GG
    std::regex lineRe(R"(^([a-zA-Z_][a-zA-Z0-9_]*)\s+"([^"]*)"\s*(?://(.*))?$)");

    while (std::getline(file, line)) {
        // Skip blank lines and alias lines
        if (line.empty() || line.rfind("alias", 0) == 0 || line.rfind("//", 0) == 0)
            continue;

        std::smatch m;
        if (!std::regex_match(line, m, lineRe)) continue;

        ParsedCvar cvar;
        cvar.name = m[1].str();
        cvar.currentValue = m[2].str();
        cvar.rawComment = m.size() > 3 ? m[3].str() : "";
        cvar.type = DetectType(cvar.currentValue);

        if (cvar.type == CvarType::Range)
            ParseRange(cvar.currentValue, cvar.rangeMin, cvar.rangeMax);
        if (cvar.type == CvarType::Color)
            ParseColor(cvar.currentValue, cvar.colorR, cvar.colorG, cvar.colorB, cvar.colorA);

        results.push_back(cvar);
    }

    // Sort A-Z case-insensitive
    std::sort(results.begin(), results.end(), [](const ParsedCvar& a, const ParsedCvar& b) {
        std::string la = a.name, lb = b.name;
        std::transform(la.begin(), la.end(), la.begin(), ::tolower);
        std::transform(lb.begin(), lb.end(), lb.begin(), ::tolower);
        return la < lb;
    });

    return results;
}

CvarType ConfigParser::DetectType(const std::string& v) {
    if (v == "0" || v == "1") return CvarType::Boolean;
    if (!v.empty() && v[0] == '(') {
        // Count commas to distinguish range (1 comma) from color (3 commas)
        int commas = (int)std::count(v.begin(), v.end(), ',');
        return commas == 3 ? CvarType::Color : CvarType::Range;
    }
    // Check for decimal
    if (v.find('.') != std::string::npos) {
        try { std::stof(v); return CvarType::Decimal; } catch (...) {}
    }
    // Check for plain integer
    try { std::stoi(v); return CvarType::Number; } catch (...) {}
    return CvarType::String;
}

void ConfigParser::ParseRange(const std::string& v, float& mn, float& mx) {
    // Format: "(min, max)"
    std::sscanf(v.c_str(), "(%f, %f)", &mn, &mx);
}

void ConfigParser::ParseColor(const std::string& v, float& r, float& g, float& b, float& a) {
    // Format: "(r, g, b, a)"
    std::sscanf(v.c_str(), "(%f, %f, %f, %f)", &r, &g, &b, &a);
}
```

### Step 3: Hotswap and verify manually

Compile, hotswap, add a temporary `cvarManager->log("Parsed: " + std::to_string(cvars.size()) + " cvars")` in `onLoad()`. Open BakkesMod console — you should see `Parsed: 271 cvars` (or close to it).

Remove the log line. Commit.

```bash
git add F6ForDummies/ConfigParser.h F6ForDummies/ConfigParser.cpp
git commit -m "feat: config.cfg parser for CVar browser"
```

---

## Task 3: Descriptions Loader

Load `cvars_descriptions.json` and merge its data with the parsed CVars.

**Files:**
- Create: `C:\Users\bmile\Source\Repos\SuiteSpot\F6ForDummies\DescriptionsLoader.h`
- Create: `C:\Users\bmile\Source\Repos\SuiteSpot\F6ForDummies\DescriptionsLoader.cpp`
- JSON library: `#include "IMGUI/json.hpp"` — already in project (nlohmann v3.11.3)

### Step 1: Write the loader

```cpp
// DescriptionsLoader.h
#pragma once
#include "ConfigParser.h"
#include <string>
#include <vector>

class DescriptionsLoader {
public:
    // Enriches ParsedCvar list with descriptions from JSON.
    // CVars not found in JSON keep rawComment as fallback.
    static void Enrich(std::vector<ParsedCvar>& cvars, const std::string& jsonPath);
};
```

```cpp
// DescriptionsLoader.cpp
#include "DescriptionsLoader.h"
#include <fstream>
#include "IMGUI/json.hpp"  // nlohmann/json — already in SuiteSpot project

void DescriptionsLoader::Enrich(std::vector<ParsedCvar>& cvars, const std::string& jsonPath) {
    std::ifstream f(jsonPath);
    if (!f.is_open()) return;  // silently continue — rawComment is the fallback

    nlohmann::json j;
    try { f >> j; } catch (...) { return; }

    for (auto& cvar : cvars) {
        if (j.contains(cvar.name)) {
            auto& entry = j[cvar.name];
            if (entry.contains("description"))
                cvar.friendlyDescription = entry["description"].get<std::string>();
        }
        // Fallback: use rawComment if no description was loaded
        if (cvar.friendlyDescription.empty())
            cvar.friendlyDescription = cvar.rawComment;
    }
}
```

Also add `friendlyDescription` field to `ParsedCvar` in `ConfigParser.h`:
```cpp
std::string friendlyDescription;  // populated by DescriptionsLoader
```

### Step 2: Hotswap, verify in debugger or log

Add a temp log: output the description of `ranked_autogg` — should be your plain-English version, not the raw comment.

Commit:
```bash
git add F6ForDummies/DescriptionsLoader.h F6ForDummies/DescriptionsLoader.cpp F6ForDummies/ConfigParser.h
git commit -m "feat: descriptions loader merges JSON descriptions with parsed CVars"
```

---

## Task 4: F6ForDummies Tab — State & Initialization

Add the tab state to SuiteSpot and hook up `onLoad()`.

**Files:**
- Modify: `C:\Users\bmile\Source\Repos\SuiteSpot\SuiteSpot.h` — add tab state members
- Modify: `C:\Users\bmile\Source\Repos\SuiteSpot\SuiteSpot.cpp` — populate state in `onLoad()` (currently at line ~554)

### Step 1: Add state to SuiteSpot.h

```cpp
// Inside SuiteSpot class, add:
#include "F6ForDummies/ConfigParser.h"

private:
    // F6 For Dummies tab state
    std::vector<ParsedCvar> f6Cvars;         // full sorted list, loaded in onLoad()
    char f6SearchBuf[256] = {};              // search bar text buffer
    std::string f6StatusMsg;                 // "" when idle, "✓ cvar_name value" on success
    float f6StatusTimer = 0.f;              // countdown to clear status message
    bool f6StatusIsError = false;           // true = red, false = green
```

### Step 2: Populate in onLoad()

Add these lines at the **end** of `SuiteSpot::onLoad()` (after line ~624, before the closing brace):

```cpp
void SuiteSpot::onLoad() {
    // ... all existing onLoad code stays unchanged ...

    // F6 For Dummies: parse config.cfg and enrich with descriptions
    // mapManager->GetDataRoot() returns %APPDATA%\bakkesmod\bakkesmod\data
    // config.cfg is one level up at ...\cfg\config.cfg
    auto configPath = mapManager->GetDataRoot().parent_path() / "cfg" / "config.cfg";
    auto descPath   = mapManager->GetSuiteSpotRoot() / "cvars_descriptions.json";

    f6Cvars = ConfigParser::Parse(configPath.string());
    DescriptionsLoader::Enrich(f6Cvars, descPath.string());

    LOG("SuiteSpot: F6 For Dummies loaded {} CVars", f6Cvars.size());
}
```

> `mapManager->GetDataRoot()` is the canonical path helper — already used throughout SuiteSpot. Do not use `gameWrapper->GetDataFolder()` for this — it points to a different location.

### Step 3: Hotswap and log count

Verify `f6Cvars.size()` is ~271 in the log. Commit.

```bash
git add SuiteSpot.h SuiteSpot.cpp
git commit -m "feat: load and enrich CVar list in onLoad() for F6 For Dummies tab"
```

---

## Task 5: F6ForDummies Tab — ImGui Rendering

Add the tab and render the CVar list.

**Files:**
- Modify: `C:\Users\bmile\Source\Repos\SuiteSpot\SettingsUI.cpp` — add tab to `BeginTabBar("SuiteSpotTabs")` at line ~242
- Modify: `C:\Users\bmile\Source\Repos\SuiteSpot\SettingsUI.h` — declare render method
- The tab bar currently has: Map Select, Loadout Management, Hotkeys — add "F6 For Dummies" after these

### Step 1: Add tab to tab bar

In `SettingsUI.cpp`, inside `if (ImGui::BeginTabBar("SuiteSpotTabs", ImGuiTabBarFlags_None))`, after the existing tabs:

```cpp
if (ImGui::BeginTabItem("F6 For Dummies")) {
    RenderF6ForDummiesTab();
    ImGui::EndTabItem();
}
```

### Step 2: Write RenderF6ForDummiesTab()

```cpp
void SuiteSpot::RenderF6ForDummiesTab() {
    // Search bar
    ImGui::SetNextItemWidth(-1.f);
    ImGui::InputText("##f6search", f6SearchBuf, sizeof(f6SearchBuf));
    ImGui::SameLine(0, 4);
    if (ImGui::Button("X")) { f6SearchBuf[0] = '\0'; }
    ImGui::Separator();

    // Status message (success/error) — fades out after 3 seconds
    if (!f6StatusMsg.empty()) {
        ImVec4 color = f6StatusIsError
            ? ImVec4(1.f, 0.2f, 0.2f, 1.f)   // red
            : ImVec4(0.2f, 1.f, 0.2f, 1.f);  // green
        ImGui::TextColored(color, "%s", f6StatusMsg.c_str());
        ImGui::Separator();
    }

    // Scrollable CVar list
    ImGui::BeginChild("##f6list", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

    std::string query(f6SearchBuf);
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    for (auto& cvar : f6Cvars) {
        // Filter by search (name OR description, case-insensitive)
        if (!query.empty()) {
            std::string lname = cvar.name, ldesc = cvar.friendlyDescription;
            std::transform(lname.begin(), lname.end(), lname.begin(), ::tolower);
            std::transform(ldesc.begin(), ldesc.end(), ldesc.begin(), ::tolower);
            if (lname.find(query) == std::string::npos &&
                ldesc.find(query) == std::string::npos)
                continue;
        }

        ImGui::PushID(cvar.name.c_str());
        RenderCvarRow(cvar);
        ImGui::PopID();
        ImGui::Separator();
    }

    ImGui::EndChild();
}
```

### Step 3: Write RenderCvarRow()

```cpp
void SuiteSpot::RenderCvarRow(ParsedCvar& cvar) {
    // CVar name — bold, with tooltip showing raw comment
    ImGui::TextUnformatted(cvar.name.c_str());
    if (!cvar.rawComment.empty() && ImGui::IsItemHovered()) {
        ImGui::SetTooltip("%s", cvar.rawComment.c_str());
    }

    // Friendly description — smaller, gray
    ImGui::TextDisabled("%s", cvar.friendlyDescription.c_str());

    // Input control(s) based on type
    ImGui::SameLine();
    float inputWidth = 120.f;

    if (cvar.type == CvarType::Color) {
        // Color picker: convert 0-255 to 0-1 for ImGui
        float col[4] = {
            cvar.colorR / 255.f, cvar.colorG / 255.f,
            cvar.colorB / 255.f, cvar.colorA / 255.f
        };
        ImGui::SetNextItemWidth(inputWidth);
        if (ImGui::ColorEdit4("##color", col, ImGuiColorEditFlags_AlphaBar)) {
            cvar.colorR = col[0] * 255.f; cvar.colorG = col[1] * 255.f;
            cvar.colorB = col[2] * 255.f; cvar.colorA = col[3] * 255.f;
            // Rebuild currentValue string
            cvar.currentValue = "(" + std::to_string((int)cvar.colorR) + ", " +
                std::to_string((int)cvar.colorG) + ", " +
                std::to_string((int)cvar.colorB) + ", " +
                std::to_string((int)cvar.colorA) + ")";
        }
    } else if (cvar.type == CvarType::Range) {
        ImGui::SetNextItemWidth(inputWidth / 2.f - 4.f);
        ImGui::InputFloat("##min", &cvar.rangeMin, 0, 0, "%.1f");
        ImGui::SameLine(0, 4);
        ImGui::SetNextItemWidth(inputWidth / 2.f - 4.f);
        ImGui::InputFloat("##max", &cvar.rangeMax, 0, 0, "%.1f");
        // Rebuild currentValue string for execute
        cvar.currentValue = "(" + std::to_string(cvar.rangeMin) + ", " +
                            std::to_string(cvar.rangeMax) + ")";
    } else {
        // Plain text input for all other types
        char buf[256];
        strncpy_s(buf, cvar.currentValue.c_str(), sizeof(buf));
        ImGui::SetNextItemWidth(inputWidth);
        if (ImGui::InputText("##val", buf, sizeof(buf)))
            cvar.currentValue = std::string(buf);
    }

    // Execute button
    ImGui::SameLine(0, 8);
    if (ImGui::Button("▶")) {
        ExecuteCvar(cvar);
    }
}
```

### Step 4: Hotswap, verify tab appears

Compile and hotswap. Open SuiteSpot — you should see the "F6 For Dummies" tab. The list should show CVars alphabetically. Search should filter in real-time.

Commit:
```bash
git add SuiteSpot.cpp SuiteSpot.h
git commit -m "feat: F6 For Dummies tab renders searchable CVar list"
```

---

## Task 6: Execute + Feedback

Wire up the ▶ button to actually send the command and show feedback.

**Files:**
- Modify: `C:\Users\bmile\Source\Repos\SuiteSpot\SettingsUI.cpp`

### Step 1: Write ExecuteCvar()

```cpp
void SuiteSpot::ExecuteCvar(const ParsedCvar& cvar) {
    std::string command = cvar.name + " " + cvar.currentValue;
    cvarManager->executeCommand(command);

    // Re-read config.cfg to get the confirmed value BakkesMod stored
    // (gives feedback that the command actually took effect)
    std::string configPath = gameWrapper->GetDataFolder().string() + "/../cfg/config.cfg";
    std::string descPath   = gameWrapper->GetDataFolder().string() + "/SuiteSpot/cvars_descriptions.json";
    f6Cvars = ConfigParser::Parse(configPath);
    DescriptionsLoader::Enrich(f6Cvars, descPath);

    // Show green success message in-window
    f6StatusMsg = "✓  " + command;
    f6StatusIsError = false;
    f6StatusTimer = 3.f;
}
```

### Step 2: Clear status message over time

In SuiteSpot's render/tick function, decrement the timer and clear the message:

```cpp
// In your render loop or wherever you call RenderF6ForDummiesTab from:
if (f6StatusTimer > 0.f) {
    f6StatusTimer -= ImGui::GetIO().DeltaTime;
    if (f6StatusTimer <= 0.f) {
        f6StatusTimer = 0.f;
        f6StatusMsg.clear();
    }
}
```

### Step 3: Hotswap, test execute

1. Open F6 For Dummies tab
2. Find `ranked_autogg` in the list
3. Change value to `0`, click ▶
4. Green text should appear: `✓ ranked_autogg 0`
5. Open F6 console directly — type `ranked_autogg` and confirm it shows `0`
6. Change it back to `1`, confirm it updates

Commit:
```bash
git add SuiteSpot.cpp
git commit -m "feat: CVar execute button with green success feedback and live value sync"
```

---

## Task 7: Final Polish

### Step 1: Handle empty search gracefully

If the filtered list is empty after searching, show a helpful message:
```cpp
if (/* no rows rendered */) {
    ImGui::TextDisabled("No CVars match \"%s\"", f6SearchBuf);
}
```
Track this with a `bool anyVisible = false;` flag inside the render loop, set to `true` when a row passes the filter.

### Step 2: Hotswap and full walkthrough

1. Open tab — all 271 CVars visible, sorted A-Z
2. Search "boost" — shows only boost-related CVars
3. Search "sv_training" — shows all training CVars
4. Clear search — all CVars return
5. Hover a CVar name — tooltip shows raw technical comment
6. Execute a CVar — green text appears, value syncs
7. Type an intentionally wrong value — red text shows `✗ INVALID COMMAND`, no popup appears
8. Close and reopen BakkesMod — CVar list re-populates correctly from config.cfg

### Step 3: Final commit

```bash
git add -A
git commit -m "feat: F6 For Dummies - complete searchable CVar browser in SuiteSpot"
```

---

## Verification Checklist

- [ ] All 271 CVars appear in the list
- [ ] List is sorted A-Z, case-insensitive
- [ ] Search filters by both CVar name and description
- [ ] Clearing search restores full list
- [ ] Range CVars show two float input boxes (Min / Max)
- [ ] Color CVars show a color picker
- [ ] All other CVars show a plain text input
- [ ] Current value is pre-filled from config.cfg
- [ ] Clicking ▶ sends the command to BakkesMod
- [ ] After execute, input box updates to confirmed value from config.cfg
- [ ] Green text appears inline at top of tab on success, clears after 3 seconds — no toast, no popup
- [ ] Red text appears inline on invalid command — no toast, no popup
- [ ] Hovering CVar name shows raw technical comment as tooltip
- [ ] Hotreloading SuiteSpot refreshes the list (tests onLoad() path)
- [ ] Tab still works after adding/removing a plugin and hotreloading

---

## Key File Paths Reference

| File | Path |
|------|------|
| config.cfg (runtime source) | `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\cfg\config.cfg` |
| cvars_descriptions.json (to create) | `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\data\SuiteSpot\cvars_descriptions.json` |
| SuiteSpot source root | `C:\Users\bmile\Source\Repos\SuiteSpot\` |
| Main plugin class | `SuiteSpot.h` / `SuiteSpot.cpp` (onLoad at line ~554) |
| Tab bar (add new tab here) | `SettingsUI.cpp` (BeginTabBar at line ~242) |
| JSON library | `IMGUI/json.hpp` (nlohmann v3.11.3) |
| Path helper | `MapManager::GetDataRoot()`, `GetSuiteSpotRoot()` |
| SuiteSpot.dll (compiled output) | `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\plugins\SuiteSpot.dll` |
| BakkesMod SDK headers | `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\bakkesmodsdk\include\bakkesmod\` |
| Hotswap script | `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\bakkesmodsdk\bakkes_patchplugin.py` |
| Design doc | `C:\Users\bmile\.claude\plans\temporal-pondering-taco.md` |
