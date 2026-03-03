# F6 For Dummies — CVar Descriptions Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.
> **IMPORTANT:** This plan requires a **dedicated full context session**. Do not combine with the implementation plan. The descriptions are the most important deliverable of the entire F6 For Dummies feature.

**Goal:** Research and write plain-English descriptions for all 271 BakkesMod CVars and produce `cvars_descriptions.json` — the content layer that makes the F6 For Dummies tab useful to non-technical players.

**Architecture:** One JSON file mapping each CVar name to a description, default value, type, and raw comment. Researched from multiple community sources. Written for players, not developers.

**Output file:** `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\data\SuiteSpot\cvars_descriptions.json`

---

## Context: Why This Matters

The F6 For Dummies tab is a searchable CVar browser inside the SuiteSpot BakkesMod plugin. It shows every executable console variable with a description a normal player can understand. Without good descriptions, this feature is no better than the raw F6 console.

The owner (bmile) has specifically emphasized:
- **Non-technical language** — written for Rocket League players, not developers
- **Comprehensive** — every single CVar needs a description, no blanks
- **Accurate** — descriptions should reflect what the CVar actually does, researched from community sources
- **This is the most important aspect of the entire feature**

---

## Source of Truth: config.cfg

Read this file first to get all 271 CVar names and their current values/raw comments:
```
C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\cfg\config.cfg
```

Format of each line: `cvar_name "current_value" //raw_comment`

The raw comment is a starting point — it's what BakkesMod developers wrote. It is often too technical or too brief. Your job is to **rewrite it in plain English**.

Also read this partial reference (already ~35% coverage):
```
C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\BAKKESMOD_COMMANDS.md
```

---

## Research Sources (Use in This Order)

For each CVar, try these sources to understand what it does before writing:

1. **BAKKESMOD_COMMANDS.md** — already in this repo, check here first
2. **config.cfg raw comment** — fallback starting point, rephrase in plain English
3. **BakkesMod Wiki:** https://bakkesmod.fandom.com/wiki/BakkesMod_Wiki
4. **GitHub — BakkesMod2-Plugins:** https://github.com/Bakkes/BakkesMod2-Plugins (source for built-in plugins — comments in code)
5. **GitHub — DollyCam Plugin:** https://github.com/Bakkes/DollyCamPlugin2
6. **Reddit:** Search `site:reddit.com bakkesmod [cvar_name]` or `site:reddit.com/r/RocketLeague bakkesmod [feature]`
7. **BakkesMod Discord FAQ/docs** — search for plugin names
8. **Inference from CVar name + value pattern** — use as last resort, be conservative

---

## Output JSON Schema

```json
{
  "cvar_name": {
    "description": "Plain-English description. 1-3 sentences. Player-facing.",
    "default": "the_value_from_config.cfg",
    "type": "boolean|number|decimal|range|color|string",
    "raw_comment": "copied verbatim from config.cfg //comment, empty string if none"
  }
}
```

### Type Detection Rules

| Value pattern in config.cfg | Assign type |
|---|---|
| `"0"` or `"1"` only | `"boolean"` |
| Integer like `"2"`, `"30"`, `"9002"` | `"number"` |
| Decimal like `"0.611000"`, `"1.503000"` | `"decimal"` |
| Starts with `(` and has exactly 1 comma: `"(800, 1000)"` | `"range"` |
| Starts with `(` and has exactly 3 commas: `"(0, 255, 0, 255)"` | `"color"` |
| Everything else (text, paths, keys, templates) | `"string"` |

---

## Description Writing Rules

**DO:**
- Write 1–3 sentences max. First sentence: what it does. Second (optional): when you'd change it or what values mean.
- Use "Turns on/off" for boolean CVars, not "Enables/disables"
- For range types: say "Left number = minimum, right = maximum"
- For color types: say "Values are Red, Green, Blue, Transparency — each from 0 (none) to 255 (full)"
- For number types: explain what the number represents (seconds, pixels, units, etc.) if known
- Write in present tense: "Shows the..." not "This shows the..."
- Mention where the effect is visible if helpful ("...visible on the in-game HUD", "...appears in the main menu")

**DON'T:**
- Never use the words: `cvar`, `variable`, `flag`, `boolean`, `toggle`, `plugin`, `parameter`, `notifier`
- Never write "This enables the..." — just say what it does
- Never leave a description empty
- Never copy the raw comment word-for-word without rewriting it
- Don't guess at functionality — if unknown after research, write "Controls [feature name]. Change with caution — effects may vary." rather than making something up

**Examples of good descriptions:**

```json
"ranked_autogg": {
  "description": "Automatically types 'GG' in chat when a ranked match ends. Turn this off if you prefer to type it yourself or stay silent.",
  "default": "1",
  "type": "boolean",
  "raw_comment": "Automatically says GG at the end of the match"
},
"ranked_autogg_delay": {
  "description": "How long to wait before the automatic GG is sent, in milliseconds. Left = shortest wait, right = longest. Useful if you want it to feel more natural.",
  "default": "(250, 2500)",
  "type": "range",
  "raw_comment": "Time to wait before sending gg message"
},
"GSA_Color": {
  "description": "The color of the goal speed text shown on screen after a goal. Values are Red, Green, Blue, and Transparency — each from 0 (none) to 255 (full).",
  "default": "(0, 255, 0, 255)",
  "type": "color",
  "raw_comment": "Goal speed anywhere text color"
},
"bakkesmod_style_alpha": {
  "description": "How transparent the BakkesMod menus are. 0 = completely invisible, 1 = fully solid.",
  "default": "0.611000",
  "type": "decimal",
  "raw_comment": "Alpha for gui"
},
"cl_autoreplayupload_replaynametemplate": {
  "description": "The naming pattern used for replay files when auto-saving or uploading. Placeholders like {YEAR}, {PLAYER}, {MODE}, and {WINLOSS} are replaced with real values from the match.",
  "default": "{YEAR}-{MONTH}-{DAY}.{HOUR}.{MIN} {PLAYER} {MODE} {WINLOSS}",
  "type": "string",
  "raw_comment": "Template for in game name of replay"
},
"sv_soccar_unlimitedflips": {
  "description": "Lets you flip and double-jump as many times as you want without landing. Useful for practicing aerial mechanics in Freeplay.",
  "default": "0",
  "type": "boolean",
  "raw_comment": "Allows you to keep flipping in the air for practice"
}
```

---

## Plugin Context Reference

Use this to understand what each plugin prefix does before writing descriptions:

| Prefix | What it controls |
|--------|-----------------|
| `GSA_*` | Goal Speed Anywhere — shows ball speed when it crosses the goal line, anywhere on the field |
| `airdrib_*` | Airdribble training drill — shoots the ball upward for aerial dribble practice |
| `alliteration_andy` | Gives players joke alliterative names like "Stalling Steven" |
| `bakkesmod_log_*` | How BakkesMod writes its internal log file |
| `bakkesmod_style_*` | Appearance of the BakkesMod overlay menus (transparency, scale, theme) |
| `bounceaway_*` / `bounceto_*` | Ball bounce drills — shoots ball toward or away from car |
| `cl_alphaboost` | Forces the Alpha Boost (Gold Rush boost trail) visual on your car |
| `cl_anonymizer_*` | Hides player names, ranks, or car styles during matches (for streamers) |
| `cl_autoreplayupload_*` | Auto-uploads replays to ballchasing.com or calculated.gg after matches |
| `cl_bakkesmod_enablesupportdialog` | Shows a "Support a Creator" dialog |
| `cl_camera_*` | Camera behavior in replays |
| `cl_console_*` | The F6 BakkesMod console window settings |
| `cl_demo_*` | Demo/replay recording settings |
| `cl_draw_*` | On-screen displays (FPS counter, system clock) |
| `cl_freeplay_*` | Visual settings when in Freeplay mode |
| `cl_goalreplay_*` | Goal replay camera behavior after scoring |
| `cl_itemmod_*` | Override your in-game item appearance with a custom loadout code |
| `cl_loadout_*` | Car color customization for orange and blue team appearances |
| `cl_mainmenu_background` | Changes the animated background in Rocket League's main menu |
| `cl_misophoniamode_enabled` | Disables items with food-related sound effects |
| `cl_notifications_*` | In-game notification popups (MMR change, ranked results) |
| `cl_online_status_detailed` | Shows detailed match info (score, time) in friends' online status |
| `cl_record_fps` | Frame rate for demo recordings |
| `cl_rendering_*` | Master switches for BakkesMod's rendering system |
| `cl_settings_*` | BakkesMod settings window behavior |
| `cl_soccar_*` | In-game gameplay enhancements (boost counter direction, jump helper sounds) |
| `cl_training_printjson` | Debug output for custom training shots (developer tool) |
| `cl_workshop_freecam` | Lets you enter spectator/free camera in custom workshop maps |
| `defender_*` | Defender Plugin — AI shoots at your goal, you practice defending |
| `dolly_*` | DollyCam Plugin — record and play back smooth camera paths for cinematics/clips |
| `gui_quicksettings_rows` | Number of columns in BakkesMod's quick settings grid |
| `ingamerank_*` | Shows opponent/teammate ranks on screen during matches |
| `inputbuffer_reset_automatic` | Resets controller input buffer after alt-tabbing out of the game |
| `max_touch_markers` | How many touch indicators can appear on screen at once |
| `mech_*` | Mechanical Plugin — limits controls for focused mechanical practice (e.g. no boost, no jump) |
| `queuemenu_*` | Automatic behavior of the queue/party menu |
| `ranked_*` | Ranked match automation (auto-GG, auto-queue, rank display, replay saving) |
| `rcon_*` | Remote Control server — lets external tools send commands to BakkesMod |
| `rebound_*` | Rebound Plugin — shoots ball at backboard for rebound practice |
| `record` | Whether BakkesMod is currently recording |
| `recovery_*` | Recovery Plugin — simulates getting bumped to practice recovery |
| `redirect_*` | Redirect Plugin — passes the ball to practice redirects and 50/50s |
| `revela_*` | Revela's Input HUD — shows your boost, jump, and slide inputs on screen |
| `ring_*` | Ring indicator displayed around your car |
| `rollaway_*` / `rollto_*` | Ball roll drills — rolls ball toward or away from car along the ground |
| `rs_*` | RocketStats — tracks and displays your ranked stats |
| `sf_*` | Speedflip Trainer — shows angle, flip cancel, and position meters for speedflip practice |
| `shootatme_*` | ShootAtMe drill — ball shoots toward you for save practice |
| `shot_*` | Custom training shot parameters (position, velocity, spin of ball and car) |
| `sv_freeplay_*` | Freeplay mode settings (goals, rumble powerups, boost limits) |
| `sv_password` | Password for hosting a private LAN/custom game server |
| `sv_soccar_*` | In-game server rules (goal scoring, slow motion, unlimited flips) |
| `sv_training_*` | Custom training variance and randomization settings |
| `touch_marker_*` | Visual indicators that appear where the ball is touched |
| `wallhit_*` | Wallhit Training Plugin — practice hitting balls off the wall |
| `workshop_*` | Workshop Map Loader — loads community-made training maps |

---

## Complete CVar List to Document

All 271 CVars extracted from config.cfg. Work through these in alphabetical order:

```
GSA_Color
GSA_Decimal_Precision
GSA_Duration
GSA_Enable
GSA_Shadow
GSA_X_Position
GSA_Y_Position
airdrib_boost
airdrib_spin
airdrib_variance
alliteration_andy
bakkesmod_log_instantflush
bakkesmod_style_alpha
bakkesmod_style_light
bakkesmod_style_scale
bakkesmod_style_theme
bounceaway_speed
bounceto_speed
cl_alphaboost
cl_anonymizer_alwaysshowcars
cl_anonymizer_bot
cl_anonymizer_hideforfeit
cl_anonymizer_kickoff_quickchat
cl_anonymizer_mode_opponent
cl_anonymizer_mode_party
cl_anonymizer_mode_team
cl_anonymizer_scores
cl_autoreplayupload_ballchasing
cl_autoreplayupload_ballchasing_authkey
cl_autoreplayupload_ballchasing_visibility
cl_autoreplayupload_calculated
cl_autoreplayupload_calculated_visibility
cl_autoreplayupload_filepath
cl_autoreplayupload_notifications
cl_autoreplayupload_replaynametemplate
cl_autoreplayupload_replaysequence
cl_autoreplayupload_save
cl_bakkesmod_enablesupportdialog
cl_camera_cliptofield
cl_console_buffersize
cl_console_enabled
cl_console_height
cl_console_key
cl_console_logkeys
cl_console_suggestions
cl_console_toggleable
cl_console_width
cl_console_x
cl_console_y
cl_demo_autosave
cl_demo_nameplates
cl_draw_fpsonboot
cl_draw_systemtime
cl_draw_systemtime_format
cl_freeplay_carcolor
cl_freeplay_stadiumcolors
cl_goalreplay_pov
cl_goalreplay_timeout
cl_itemmod_code
cl_itemmod_enabled
cl_loadout_blue_primary
cl_loadout_blue_secondary
cl_loadout_color_enabled
cl_loadout_color_same
cl_loadout_orange_primary
cl_loadout_orange_secondary
cl_mainmenu_background
cl_misophoniamode_enabled
cl_notifications_enabled_beta
cl_notifications_ranked
cl_online_status_detailed
cl_record_fps
cl_rendering_disabled
cl_rendering_scaleform_disabled
cl_settings_ignoreminwindowsize
cl_settings_logrefreshinfo
cl_settings_plugin_favorites
cl_soccar_ballfadein
cl_soccar_boostcounter
cl_soccar_jumphelp
cl_soccar_jumphelp_carcolor
cl_training_printjson
cl_workshop_freecam
defender_active
defender_cooldown
defender_difficulty
defender_shotspeed
dolly_chaikin_degree
dolly_interpmode
dolly_interpmode_location
dolly_interpmode_rotation
dolly_path_directory
dolly_render
dolly_render_frame
dolly_spline_acc
gui_quicksettings_rows
ingamerank_calculate_unranked
ingamerank_enabled
ingamerank_include_extramodes
ingamerank_include_tournaments
ingamerank_playlist
ingamerank_show_division
ingamerank_show_playlist
inputbuffer_reset_automatic
max_touch_markers
mech_disable_boost
mech_disable_handbrake
mech_disable_jump
mech_enabled
mech_hold_boost
mech_hold_roll
mech_pitch_limit
mech_roll_limit
mech_steer_limit
mech_throttle_limit
mech_yaw_limit
queuemenu_close_joining
queuemenu_open_mainmenu
queuemenu_open_match_ended
ranked_aprilfools
ranked_autogg
ranked_autogg_delay
ranked_autogg_id
ranked_autoqueue
ranked_autosavereplay
ranked_autosavereplay_all
ranked_disableranks
ranked_disregardplacements
ranked_showranks
ranked_showranks_casual
ranked_showranks_casual_menu
ranked_showranks_gameover
ranked_showranks_menu
rcon_enabled
rcon_log
rcon_password
rcon_port
rcon_timeout
rebound_addedheight
rebound_addedspin
rebound_resetspin
rebound_shotspeed
rebound_side_offset
record
recovery_bumpspeed_angular
recovery_bumpspeed_linear
recovery_bumpspeed_linear_z
recovery_cooldown
redirect_on_ground
redirect_pass_offset
redirect_pass_offset_z
redirect_pass_predict
redirect_predict_multiplier_x
redirect_predict_multiplier_y
redirect_shot_speed
revela_hud_bst_x
revela_hud_bst_y
revela_hud_enabled
revela_hud_jmp_x
revela_hud_jmp_y
revela_hud_last_preset
revela_hud_replay_enabled
revela_hud_scale
revela_hud_sld_x
revela_hud_sld_y
revela_hud_smooth_speed
revela_hud_x
revela_hud_y
ring_color
ring_enabled
ring_size
rollaway_speed
rollto_speed
rs_in_file
rs_toggle_logo
sf_cancel_threshold
sf_change_speed
sf_enabled
sf_left_angle
sf_num_hits
sf_remember_speed
sf_right_angle
sf_save_attempts
sf_show_angle
sf_show_flip
sf_show_jump
sf_show_position
sf_speed
sf_speed_increment
shootatme_bounds_x
shootatme_bounds_y
shootatme_bounds_z
shootatme_speed
shot_countdowntime
shot_initial_ball_location_x
shot_initial_ball_location_y
shot_initial_ball_location_z
shot_initial_ball_pitch
shot_initial_ball_roll
shot_initial_ball_torque_pitch
shot_initial_ball_torque_roll
shot_initial_ball_torque_yaw
shot_initial_ball_velocity_x
shot_initial_ball_velocity_y
shot_initial_ball_velocity_z
shot_initial_ball_yaw
shot_mirror
shot_randomization
shot_waitbeforeshot
sv_freeplay_bindings
sv_freeplay_enablegoal
sv_freeplay_enablegoal_bakkesmod
sv_freeplay_goalspeed
sv_freeplay_limitboost_default
sv_freeplay_rumble_enable_boot
sv_freeplay_rumble_enable_disruptor
sv_freeplay_rumble_enable_freezer
sv_freeplay_rumble_enable_grapplinghook
sv_freeplay_rumble_enable_haymaker
sv_freeplay_rumble_enable_magnetizer
sv_freeplay_rumble_enable_plunger
sv_freeplay_rumble_enable_powerhitter
sv_freeplay_rumble_enable_spike
sv_freeplay_rumble_enable_swapper
sv_freeplay_rumble_enable_tornado
sv_password
sv_soccar_enablegoal
sv_soccar_enablegoal_onlyfirstball
sv_soccar_goalslomo
sv_soccar_goalspeed
sv_soccar_unlimitedflips
sv_training_allowmirror
sv_training_autoshuffle
sv_training_clock
sv_training_enabled
sv_training_goalblocker_enabled
sv_training_limitboost
sv_training_player_velocity
sv_training_timeup_reset
sv_training_usefreeplaymap
sv_training_userandommap
sv_training_var_car_loc
sv_training_var_car_rot
sv_training_var_loc
sv_training_var_loc_z
sv_training_var_rot
sv_training_var_speed
sv_training_var_spin
touch_marker_correct_color
touch_marker_duration
touch_marker_enabled
touch_marker_incorrect_color
touch_marker_reset_color
touch_marker_size
wallhit_default_mode
wallhit_expert_mode
wallhit_floor
wallhit_freeze_dist
wallhit_freeze_mode
wallhit_height
wallhit_mode
wallhit_onwall_target_ahead
wallhit_pop_mode
wallhit_pop_speed
wallhit_speed
workshop_shot_random
```

---

## Execution Steps

### Step 1: Read source files

Read both of these before writing a single description:
- `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\cfg\config.cfg`
- `C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\BAKKESMOD_COMMANDS.md`

### Step 2: Research unclear CVars

For any CVar where the raw comment is insufficient, use WebSearch to look up the plugin or feature. Key searches:
- `bakkesmod [plugin_name] documentation`
- `bakkesmod wiki [cvar_prefix]`
- `site:github.com/Bakkes [plugin_name] cvar`

### Step 3: Write all 271 descriptions

Work alphabetically. Write the full JSON object. Do not skip any CVar.

### Step 4: Validate the JSON

Paste into https://jsonlint.com or similar validator. Confirm:
- Valid JSON syntax
- No empty `"description"` fields
- All 271 CVars present
- All `"type"` values are valid

### Step 5: Write the file

Output to:
```
C:\Users\bmile\AppData\Roaming\bakkesmod\bakkesmod\data\SuiteSpot\cvars_descriptions.json
```

### Step 6: Cross-check against config.cfg

Run a final check: every CVar in config.cfg should have an entry in the JSON. Flag any mismatches.

---

## Quality Bar

Before considering this done, verify:
- [ ] All 271 CVars have a description
- [ ] Zero descriptions are copied verbatim from raw comments
- [ ] Zero descriptions use the word "cvar", "variable", "boolean", "toggle", "flag", or "plugin"
- [ ] Range CVars explain what left/right numbers mean
- [ ] Color CVars explain the R, G, B, A format
- [ ] Boolean CVars say "Turns on/off" not "Enables/disables"
- [ ] JSON validates without errors
- [ ] File is written to the correct output path
