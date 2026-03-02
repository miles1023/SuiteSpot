#include "pch.h"
#include "SuiteSpot.h"
#include "MapList.h"
#include "MapManager.h"
#include "SettingsSync.h"
#include "AutoLoadFeature.h"
#include "TrainingPackManager.h"
#include "WorkshopDownloader.h"
#include "SettingsUI.h"
#include "TrainingPackUI.h"
#include "LoadoutUI.h"
#include "ConstantsUI.h"
#include "HelpersUI.h"
#include "bakkesmod/wrappers/GameEvent/TrainingEditorWrapper.h"
#include "bakkesmod/wrappers/GuiManagerWrapper.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_set>
#include <random>
#include <iomanip>
#include <sstream>
#include <cmath>

/*
 * ======================================================================================
 * SUITESPOT: IMPLEMENTATION DETAILS
 * ======================================================================================
 * 
 * This file contains the actual code for the plugin's lifecycle.
 * 
 * KEY SECTIONS:
 * 1. PERSISTENCE HELPERS: Tiny functions that ask the Managers for data paths (like where 
 *    to find Workshop maps).
 * 2. EVENT HOOKS: The `GameEndedEvent` function is the heartbeat of the automation. 
 *    It waits for the match to finish, then triggers the `AutoLoadFeature`.
 * 3. LOADING (onLoad):
 *    - Creates all the "Managers" (tools for Maps, Settings, Packs).
 *    - Registers the "Browser Window" logic (via togglemenu).
 *    - Hooks into the game events.
 * 4. RENDERING:
 *    - Handled natively by BakkesMod's PluginWindow interface.
 *    - Uses a custom OnClose override to ensure standalone windows stay persistent
 *      when the main settings menu is closed.
 */

// ===== SuiteSpot persistence helpers =====
std::filesystem::path SuiteSpot::GetDataRoot() const
{
    return mapManager ? mapManager->GetDataRoot() : std::filesystem::path();
}

std::filesystem::path SuiteSpot::GetSuiteTrainingDir() const
{
    return mapManager ? mapManager->GetSuiteTrainingDir() : std::filesystem::path();
}

void SuiteSpot::EnsureDataDirectories() const
{
    if (mapManager) {
        mapManager->EnsureDataDirectories();
    }
}

std::filesystem::path SuiteSpot::GetWorkshopLoaderConfigPath() const
{
    return mapManager ? mapManager->GetWorkshopLoaderConfigPath() : std::filesystem::path();
}

std::filesystem::path SuiteSpot::ResolveConfiguredWorkshopRoot() const
{
    return mapManager ? mapManager->ResolveConfiguredWorkshopRoot() : std::filesystem::path();
}

void SuiteSpot::DiscoverWorkshopInDir(const std::filesystem::path& dir)
{
    if (mapManager) {
        mapManager->DiscoverWorkshopInDir(dir, RLWorkshop);
    }
}

void SuiteSpot::LoadWorkshopMaps()
{
    if (mapManager) {
        // Load workshop maps without passing an index - the path-based selection persists automatically
        int unused = 0;
        mapManager->LoadWorkshopMaps(RLWorkshop, unused);
    }
}

// ===== TRAINING PACK UPDATE INTEGRATION =====
bool SuiteSpot::IsEnabled() const
{
    return settingsSync ? settingsSync->IsEnabled() : false;
}

bool SuiteSpot::IsAutoQueueEnabled() const
{
    return settingsSync ? settingsSync->IsAutoQueue() : false;
}

bool SuiteSpot::IsTrainingGameSpeedFixEnabled() const
{
    return settingsSync ? settingsSync->IsTrainingGameSpeedFixEnabled() : true;
}

int SuiteSpot::GetMapType() const
{
    return settingsSync ? settingsSync->GetMapType() : 0;
}

int SuiteSpot::GetDelayQueueSec() const
{
    return settingsSync ? settingsSync->GetDelayQueueSec() : 0;
}

int SuiteSpot::GetDelayFreeplaySec() const
{
    return settingsSync ? settingsSync->GetDelayFreeplaySec() : 0;
}

int SuiteSpot::GetDelayTrainingSec() const
{
    return settingsSync ? settingsSync->GetDelayTrainingSec() : 0;
}

int SuiteSpot::GetDelayWorkshopSec() const
{
    return settingsSync ? settingsSync->GetDelayWorkshopSec() : 0;
}

std::string SuiteSpot::GetCurrentFreeplayCode() const
{
    return settingsSync ? settingsSync->GetCurrentFreeplayCode() : "";
}

std::string SuiteSpot::GetCurrentTrainingCode() const
{
    return settingsSync ? settingsSync->GetCurrentTrainingCode() : "";
}

std::string SuiteSpot::GetCurrentWorkshopPath() const
{
    return settingsSync ? settingsSync->GetCurrentWorkshopPath() : "";
}

// #detailed comments: UpdateTrainingPackList
// Purpose: Launches an external PowerShell script to download the latest
// training pack data and write a JSON cache to disk. This is intentionally
// performed in a background task to avoid any blocking on the UI/game thread.
//
// Safety and behavior notes:
//  - scrapingInProgress is a guard flag ensuring only one update
//    runs at a time. It is set before launching and cleared when the
//    background process finishes.
//  - The implementation uses system() and relies on the platform's
//    default process creation semantics; this must remain as-is for
//    portability with existing deployments. If this is changed to a
//    more advanced process API, ensure identical detach/exit semantics.
//  - The script path is hard-coded to the repo dev path; callers should
//    ensure that the script is present when invoking this routine.
//
// DO NOT CHANGE: Modifying the background thread logic or the way the
// result is checked could resurface race conditions that previously
// required this exact coordination.
void SuiteSpot::UpdateTrainingPackList()
{
    if (trainingPackMgr) {
        trainingPackMgr->UpdateTrainingPackList(GetTrainingPacksPath(), gameWrapper);
    }
}

BAKKESMOD_PLUGIN(SuiteSpot, "SuiteSpot", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

float SuiteSpot::ConvertMenuPercentToDecimal(float menuValue)
{
    if (!std::isfinite(menuValue)) {
        return 1.0f;
    }

    return std::clamp(menuValue, 0.01f, 10.0f);
}

void SuiteSpot::ApplyTrainingGameSpeedFromMenuValue(float menuValue)
{
    officialTrainingGameSpeed = ConvertMenuPercentToDecimal(menuValue);

    if (!IsTrainingGameSpeedFixEnabled()) {
        return;
    }

    CVarWrapper speedCvar = cvarManager->getCvar("sv_soccar_gamespeed");
    if (!speedCvar) {
        return;
    }

    speedCvar.setValue(officialTrainingGameSpeed);
    LOG("Training game speed set to {}", officialTrainingGameSpeed);
}

void SuiteSpot::LoadTrainingGameSpeedHooks()
{
    gameWrapper->HookEventWithCaller<ActorWrapper>("Function TAGame.GFxData_Settings_TA.SetTrainingGameSpeed",
                                                   [this](ActorWrapper caller, void* params, std::string eventName) {
                                                       if (params == nullptr) {
                                                           return;
                                                       }

                                                       // SetTrainingGameSpeed params have 8 bytes of padding before the float
                                                       struct SetTrainingGameSpeedParams
                                                       {
                                                           unsigned char _pad[0x8];
                                                           float value;
                                                       };
                                                       float rawValue =
                                                           reinterpret_cast<SetTrainingGameSpeedParams*>(params)->value;

                                                       ApplyTrainingGameSpeedFromMenuValue(rawValue);
                                                   });
}

void SuiteSpot::UnloadTrainingGameSpeedHooks()
{
    gameWrapper->UnhookEvent("Function TAGame.GFxData_Settings_TA.SetTrainingGameSpeed");
}

void SuiteSpot::LoadHooks()
{
    // ===== MATCH EVENT HOOKS =====
    // Re-queue/transition at match end. We use HookEventPost to ensure the game has finished
    // its internal match-end logic before we attempt to load a new map.
    gameWrapper->HookEventPost("Function TAGame.GameEvent_Soccar_TA.EventMatchEnded",
                               [this](std::string eventName) { GameEndedEvent(eventName); });

    // ===== PACK HEALER - Training Events =====
    // Based on BakkesMod SDK reference documentation

    // Hook: Training pack loaded or restarted
    // Note: IsInCustomTraining() will not yet return true at this point
    gameWrapper->HookEventPost("Function TAGame.GameEvent_TrainingEditor_TA.OnInit", [this](std::string eventName) {
        if (!IsEnabled()) return;
        LOG("Hook triggered: GameEvent_TrainingEditor_TA.OnInit");
        gameWrapper->SetTimeout([this](GameWrapper* gw) { TryHealCurrentPack(gw); }, 1.5f);
    });

    // Hook: Shot attempt started (player moves)
    // This fires when switching shots and player starts moving
    gameWrapper->HookEventPost("Function TAGame.TrainingEditorMetrics_TA.TrainingShotAttempt",
                               [this](std::string eventName) {
                                   LOG("Hook triggered: TrainingEditorMetrics_TA.TrainingShotAttempt");
                                   // Note: This hook exists but is not currently used for auto-heal
                               });

    // Manual heal command
    cvarManager->registerNotifier(
        "ss_heal_current_pack", [this](std::vector<std::string> args) { TryHealCurrentPack(gameWrapper.get()); },
        "Manually heal the currently loaded training pack", PERMISSION_ALL);

    // Hotkey action notifiers — triggered by HandleKeyPress combo detection (not via setBind).
    // Can also be invoked directly from the BakkasMod console for testing.
    cvarManager->registerNotifier(
        "ss_cycle_map_mode_fwd",
        [this](std::vector<std::string> args) {
            if (!settingsSync || !mapManager) return;
            mapManager->CycleMapMode(true);
            cvarManager->getCvar("suitespot_map_type").setValue(mapManager->GetCurrentMapModeIndex());
            {
                static const char* modeNames[] = {"Freeplay", "Training Pack", "Workshop"};
                int newMode = mapManager->GetCurrentMapModeIndex();
                std::string modeName = (newMode >= 0 && newMode < 3) ? modeNames[newMode] : "Unknown";
                ShowToastForAction("Mode Changed: " + modeName, false);
            }
        },
        "SuiteSpot: Cycle map mode forward", PERMISSION_ALL);

    cvarManager->registerNotifier(
        "ss_cycle_map_mode_bk",
        [this](std::vector<std::string> args) {
            if (!settingsSync || !mapManager) return;
            mapManager->CycleMapMode(false);
            cvarManager->getCvar("suitespot_map_type").setValue(mapManager->GetCurrentMapModeIndex());
            {
                static const char* modeNames[] = {"Freeplay", "Training Pack", "Workshop"};
                int newMode = mapManager->GetCurrentMapModeIndex();
                std::string modeName = (newMode >= 0 && newMode < 3) ? modeNames[newMode] : "Unknown";
                ShowToastForAction("Mode Changed: " + modeName, false);
            }
        },
        "SuiteSpot: Cycle map mode backward", PERMISSION_ALL);

    cvarManager->registerNotifier(
        "ss_cycle_map_fwd",
        [this](std::vector<std::string> args) {
            if (!settingsSync || !mapManager) return;
            mapManager->CycleMap(true);
            int mode = mapManager->GetCurrentMapModeIndex();
            if (mode == 0) cvarManager->getCvar("suitespot_current_freeplay_code").setValue(mapManager->GetCurrentFreeplayCode());
            else if (mode == 1) cvarManager->getCvar("suitespot_current_training_code").setValue(mapManager->GetCurrentTrainingCode());
            else if (mode == 2) cvarManager->getCvar("suitespot_current_workshop_path").setValue(mapManager->GetCurrentWorkshopPath());
            {
                std::string displayName;
                if (mode == 0) {
                    auto code = mapManager->GetCurrentFreeplayCode();
                    auto it = std::find_if(RLMaps.begin(), RLMaps.end(), [&](const MapEntry& e) { return e.code == code; });
                    displayName = (it != RLMaps.end()) ? it->name : code;
                } else if (mode == 1) {
                    auto code = mapManager->GetCurrentTrainingCode();
                    if (trainingPackMgr) {
                        auto entry = trainingPackMgr->GetPackByCode(code);
                        displayName = entry ? entry->name : code;
                    }
                } else if (mode == 2) {
                    auto path = mapManager->GetCurrentWorkshopPath();
                    auto it = std::find_if(RLWorkshop.begin(), RLWorkshop.end(), [&](const WorkshopEntry& e) { return e.filePath == path; });
                    displayName = (it != RLWorkshop.end()) ? it->name : std::filesystem::path(path).stem().string();
                }
                ShowToastForAction("Map Changed: " + displayName, false);
            }
        },
        "SuiteSpot: Cycle map forward", PERMISSION_ALL);

    cvarManager->registerNotifier(
        "ss_cycle_map_bk",
        [this](std::vector<std::string> args) {
            if (!settingsSync || !mapManager) return;
            mapManager->CycleMap(false);
            int mode = mapManager->GetCurrentMapModeIndex();
            if (mode == 0) cvarManager->getCvar("suitespot_current_freeplay_code").setValue(mapManager->GetCurrentFreeplayCode());
            else if (mode == 1) cvarManager->getCvar("suitespot_current_training_code").setValue(mapManager->GetCurrentTrainingCode());
            else if (mode == 2) cvarManager->getCvar("suitespot_current_workshop_path").setValue(mapManager->GetCurrentWorkshopPath());
            {
                std::string displayName;
                if (mode == 0) {
                    auto code = mapManager->GetCurrentFreeplayCode();
                    auto it = std::find_if(RLMaps.begin(), RLMaps.end(), [&](const MapEntry& e) { return e.code == code; });
                    displayName = (it != RLMaps.end()) ? it->name : code;
                } else if (mode == 1) {
                    auto code = mapManager->GetCurrentTrainingCode();
                    if (trainingPackMgr) {
                        auto entry = trainingPackMgr->GetPackByCode(code);
                        displayName = entry ? entry->name : code;
                    }
                } else if (mode == 2) {
                    auto path = mapManager->GetCurrentWorkshopPath();
                    auto it = std::find_if(RLWorkshop.begin(), RLWorkshop.end(), [&](const WorkshopEntry& e) { return e.filePath == path; });
                    displayName = (it != RLWorkshop.end()) ? it->name : std::filesystem::path(path).stem().string();
                }
                ShowToastForAction("Map Changed: " + displayName, false);
            }
        },
        "SuiteSpot: Cycle map backward", PERMISSION_ALL);

    cvarManager->registerNotifier(
        "ss_load_now",
        [this](std::vector<std::string> args) {
            if (!settingsSync) return;
            int mapType = settingsSync->GetMapType();
            std::string cmd;
            if (mapType == 0) {
                auto code = settingsSync->GetCurrentFreeplayCode();
                if (!code.empty()) cmd = "load_freeplay " + code;
            } else if (mapType == 1) {
                auto code = settingsSync->GetCurrentTrainingCode();
                if (!code.empty()) cmd = "load_training " + code;
            } else if (mapType == 2) {
                auto path = settingsSync->GetCurrentWorkshopPath();
                if (!path.empty()) cmd = "load_workshop \"" + path + "\"";
            }
            if (cmd.empty()) {
                ShowToastError("no map selected");
                return;
            }
            gameWrapper->Execute([this, cmd](GameWrapper*) { cvarManager->executeCommand(cmd); });
        },
        "SuiteSpot: Load current map immediately", PERMISSION_ALL);

    // Raw input hook — detects key combos, tracks held keys, and handles capture UI.
    // Fires on every key press/release; never polls. This is the sole trigger for hotkey actions
    // (no setBind — BakkesMod's bind system is not used for SuiteSpot hotkeys).
    gameWrapper->HookEventWithCaller<ActorWrapper>("Function TAGame.GameViewportClient_TA.HandleKeyPress",
                                                   [this](ActorWrapper caller, void* params, std::string eventName) {
                                                       auto p = static_cast<HandleKeyPressParams*>(params);

                                                       std::string keyName = gameWrapper->GetFNameByIndex(p->KeyIndex);
                                                       if (keyName.empty() || keyName == "None") return;

                                                       // Maintain heldKeys set for combo detection and capture UI.
                                                       if (p->EventType == 0)      // IE_Pressed
                                                           heldKeys.insert(keyName);
                                                       else if (p->EventType == 1) // IE_Released
                                                           heldKeys.erase(keyName);

                                                       // Combo hotkey detection: fires notifier when key1 is pressed
                                                       // with key2 held, or alone when no key2 is configured.
                                                       if (p->EventType == 0 && captureRow < 0 && settingsSync) {
                                                           auto checkAndFire = [&](const std::string& key1,
                                                                                   const std::string& key2,
                                                                                   const char* notifier) {
                                                               if (key1.empty() || keyName != key1) return;
                                                               if (!key2.empty() && heldKeys.count(key2) == 0) return;
                                                               std::string cmd = notifier;
                                                               gameWrapper->Execute([this, cmd](GameWrapper*) {
                                                                   cvarManager->executeCommand(cmd);
                                                               });
                                                           };
                                                           checkAndFire(settingsSync->GetHotkeyMapModeFwdKey1(), settingsSync->GetHotkeyMapModeFwdKey2(), "ss_cycle_map_mode_fwd");
                                                           checkAndFire(settingsSync->GetHotkeyMapModeBkKey1(), settingsSync->GetHotkeyMapModeBkKey2(), "ss_cycle_map_mode_bk");
                                                           checkAndFire(settingsSync->GetHotkeyCycleMapFwdKey1(), settingsSync->GetHotkeyCycleMapFwdKey2(), "ss_cycle_map_fwd");
                                                           checkAndFire(settingsSync->GetHotkeyCycleMapBkKey1(), settingsSync->GetHotkeyCycleMapBkKey2(), "ss_cycle_map_bk");
                                                           checkAndFire(settingsSync->GetHotkeyLoadNowKey1(), settingsSync->GetHotkeyLoadNowKey2(), "ss_load_now");
                                                       }

                                                       // Hotkey capture UI — only active when captureRow >= 0.
                                                       if (captureRow < 0) return;
                                                       if (p->EventType != 0) return; // capture on press only

                                                       LOG("Hotkey Capture: Detected key {} (Index: {}, Gamepad: {})",
                                                           keyName, p->KeyIndex, p->bGamepad);

                                                       // Escape cancels capture
                                                       if (keyName == "Escape") {
                                                           LOG("Hotkey Capture: Cancelled via Escape");
                                                           captureRow = -1;
                                                           return;
                                                       }

                                                       // Valid key captured - map to target CVar
                                                       if (captureRow < 5) {
                                                           const auto& row = UI::SettingsUI::HOTKEY_ROWS[captureRow];
                                                           const char* cvarName = (captureSlot == 0) ? row.key1CVar
                                                                                                     : row.key2CVar;

                                                           LOG("Hotkey Capture: Assigning {} to {}", keyName, cvarName);

                                                           // We use Execute to ensure we're not modifying CVars directly inside a hooked game call
                                                           gameWrapper->Execute([this, cvarName, keyName](GameWrapper* gw) {
                                                               UI::Helpers::SetCVarSafely(cvarName, keyName,
                                                                                          cvarManager, gameWrapper);
                                                           });

                                                           captureRow = -1;
                                                       }
                                                   });
}

// #detailed comments: GameEndedEvent
// Purpose: Called by hooked game events when a match ends. The function
// runs the auto-load logic if enabled.
//
// Timing and ordering notes:
//  - The postMatch.start timestamp is recorded with steady_clock so
//    overlay lifetime calculations are not affected by system clock
//    adjustments.
//
// DO NOT CHANGE: The safeExecute lambda intentionally accepts a delay
// (in seconds) and either executes immediately or schedules via
// gameWrapper->SetTimeout. Changing its semantics will alter when
// external commands (load_freeplay, queue, etc.) are run relative to
// overlay presentation.
void SuiteSpot::GameEndedEvent(std::string name)
{
    if (!IsEnabled()) return;

    LOG("SuiteSpot: GameEndedEvent triggered by hook: {}", name);

    // 1. Run Auto-Load/Queue Logic first (Independent of overlay)
    if (autoLoadFeature && settingsSync) {
        LOG("SuiteSpot: Triggering AutoLoadFeature::OnMatchEnded");

        autoLoadFeature->OnMatchEnded(gameWrapper, cvarManager, RLMaps, RLTraining, RLWorkshop, *settingsSync,
                                      usageTracker.get());

        // Usage tracking handled by AutoLoadFeature::OnMatchEnded
    }
}

// Helper method to extract and heal pack data from current training session
void SuiteSpot::TryHealCurrentPack(GameWrapper* gw)
{
    if (!trainingPackMgr) {
        LOG("SuiteSpot: TryHealCurrentPack - trainingPackMgr is null");
        return;
    }

    if (!gw) {
        LOG("SuiteSpot: TryHealCurrentPack - GameWrapper is null");
        return;
    }

    if (!gw->IsInCustomTraining()) {
        LOG("SuiteSpot: TryHealCurrentPack - Not in custom training (IsInCustomTraining=false)");
        return;
    }

    LOG("SuiteSpot: TryHealCurrentPack - In custom training, attempting to get data...");

    auto server = gw->GetGameEventAsServer();
    if (!server) {
        LOG("SuiteSpot: TryHealCurrentPack - Failed to get GameEventAsServer");
        return;
    }

    TrainingEditorWrapper editor(server.memory_address);
    if (!editor) {
        LOG("SuiteSpot: TryHealCurrentPack - Failed to create TrainingEditorWrapper");
        return;
    }

    auto trainingData = editor.GetTrainingData();
    if (!trainingData) {
        LOG("SuiteSpot: TryHealCurrentPack - Failed to get TrainingData");
        return;
    }

    auto saveData = trainingData.GetTrainingData();
    if (!saveData) {
        LOG("SuiteSpot: TryHealCurrentPack - Failed to get TrainingEditorSaveData");
        return;
    }

    std::string code = saveData.GetCode().ToString();

    if (code.empty()) {
        LOG("SuiteSpot: TryHealCurrentPack - Pack code is empty");
        return;
    }

    // Try multiple methods to get shot count
    int realShots = 0;

    // Method 1: From TrainingEditorWrapper directly
    realShots = editor.GetTotalRounds();
    LOG("SuiteSpot: Method 1 (editor.GetTotalRounds): {}", realShots);

    // Method 2: From save data (backup)
    if (realShots <= 0) {
        realShots = saveData.GetNumRounds();
        LOG("SuiteSpot: Method 2 (saveData.GetNumRounds): {}", realShots);
    }

    if (realShots <= 0) {
        LOG("SuiteSpot: [ERR] All methods failed to extract shot count (got {})", realShots);
        return;
    }

    LOG("SuiteSpot: [OK] Successfully extracted pack data - Code: {}, Shots: {}", code, realShots);
    LOG("SuiteSpot: Calling HealPack...");
    trainingPackMgr->HealPack(code, realShots);
}

void SuiteSpot::onLoad()
{
    _globalCvarManager = cvarManager;
    LOG("SuiteSpot loaded");
    mapManager = std::make_unique<MapManager>();
    settingsSync = std::make_unique<SettingsSync>();
    autoLoadFeature = std::make_unique<AutoLoadFeature>();
    trainingPackMgr = std::make_unique<TrainingPackManager>();
    settingsUI = std::make_unique<SettingsUI>(this);
    trainingPackUI = std::make_shared<TrainingPackUI>(this);
    loadoutUI = std::make_unique<LoadoutUI>(this);

    EnsureDataDirectories();
    LoadWorkshopMaps();

    // Initialize LoadoutManager
    loadoutManager = std::make_unique<LoadoutManager>(gameWrapper);
    LOG("SuiteSpot: LoadoutManager initialized");

    // Initialize PackUsageTracker
    usageTracker = std::make_unique<PackUsageTracker>(GetSuiteTrainingDir() / "pack_usage_stats.json");
    LOG("SuiteSpot: PackUsageTracker initialized");

    // Initialize WorkshopDownloader
    workshopDownloader = std::make_shared<WorkshopDownloader>(gameWrapper);
    LOG("SuiteSpot: WorkshopDownloader initialized");

    // Initialize TextureDownloader
    textureDownloader = std::make_unique<TextureDownloader>(gameWrapper, cvarManager);
    LOG("SuiteSpot: TextureDownloader initialized");

    // Check Pack cache and load if available

    if (trainingPackMgr) {
        if (!std::filesystem::exists(GetTrainingPacksPath())) {
            LOG("SuiteSpot: No Pack cache found. Schedule scraping on next opportunity.");
            // Will be scraped on first Settings render or user request
        } else {
            // Load existing Pack cache
            trainingPackMgr->LoadPacksFromFile(GetTrainingPacksPath());
            LOG("SuiteSpot: Pack cache loaded");
        }
    }

    LoadHooks();

    if (settingsSync) {
        settingsSync->RegisterAllCVars(cvarManager);

        // Auto-download textures if enabled
        if (settingsSync->IsAutoDownloadTextures() && textureDownloader) {
            std::vector<std::string> missing = textureDownloader->CheckMissingTextures();
            if (!missing.empty()) {
                LOG("SuiteSpot: Missing textures detected. Auto-downloading...");
                // Clean up any previous download thread
                if (textureDownloadThread.joinable()) {
                    textureDownloadThread.join();
                }
                // Start managed texture download thread
                textureDownloadThread = std::thread([this]() { textureDownloader->DownloadAndInstallTextures(); });
            }
        }
    }
    LoadTrainingGameSpeedHooks();

    // Open suitespot_browser silently so Render() fires every frame for the hotkey overlay.
    // isOverlayAutoOpen guards OnOpen() so the training browser does NOT pop open.
    isOverlayAutoOpen = true;
    gameWrapper->Execute([this](GameWrapper*) {
        cvarManager->executeCommand("openmenu suitespot_browser");
    });

    LOG("SuiteSpot: Plugin initialization complete");
}

// #detailed comments: onUnload
// Purpose: Clean up all SDK resources in proper order to enable hot-reload.
//
// Cleanup sequence (CRITICAL - must follow this order):
//  1. Join all background threads (prevents dangling thread callbacks)
//  2. Save pending data (ensures no data loss)
//  3. Unhook events (removes game event callbacks pointing to freed memory)
//  4. Reset UI components (releases ImGui resources)
//  5. Reset managers (releases business logic)
//  6. Clear ImGui context
//
// Note: BakkesMod automatically cleans up CVars and notifiers on plugin unload,
// but event hooks MUST be manually unhooked to prevent hot-reload crashes.
//
// DO NOT CHANGE: This sequence prevents hot-reload crashes by ensuring
// all callbacks are removed before the plugin DLL is unloaded. Skipping
// event unhooking will cause BakkesMod to call freed memory on reload.
void SuiteSpot::onUnload()
{
    isUnloading = true;
    LOG("SuiteSpot unloading...");

    // Wait for texture download to complete if running
    if (textureDownloadThread.joinable()) {
        LOG("SuiteSpot: Waiting for texture download to complete...");
        textureDownloadThread.join();
    }

    // Stop workshop downloader search thread
    if (workshopDownloader) {
        workshopDownloader->StopSearch();
    }

    if (usageTracker) {
        usageTracker->SaveStats();
    }

    UnloadTrainingGameSpeedHooks();

    // STEP 3: Unhook all game events and drawables (CRITICAL - SDK requirement)
    gameWrapper->UnhookEventPost("Function TAGame.GameEvent_Soccar_TA.EventMatchEnded");
    gameWrapper->UnhookEventPost("Function TAGame.GameEvent_TrainingEditor_TA.OnInit");
    gameWrapper->UnhookEventPost("Function TAGame.TrainingEditorMetrics_TA.TrainingShotAttempt");
    gameWrapper->UnhookEvent("Function TAGame.GameViewportClient_TA.HandleKeyPress");
    gameWrapper->UnregisterDrawables();
    LOG("Event hooks and drawables removed");

    // STEP 4: Reset UI components (releases ImGui resources)
    settingsUI.reset();
    trainingPackUI.reset();
    loadoutUI.reset();
    LOG("UI components destroyed");

    // STEP 5: Reset data managers
    trainingPackMgr.reset();
    autoLoadFeature.reset();
    settingsSync.reset();
    mapManager.reset();
    workshopDownloader.reset();
    LOG("Managers destroyed");

    // STEP 6: Clear ImGui context
    imgui_ctx = 0;

    LOG("SuiteSpot unloaded successfully");
}

void SuiteSpot::Render()
{
    if (!imgui_ctx) return;
    ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(imgui_ctx));

    if (!hotkeyOverlay.visible) return;

    auto elapsed = std::chrono::duration<float>(
        std::chrono::steady_clock::now() - hotkeyOverlay.startTime).count();

    if (elapsed >= hotkeyOverlay.duration) {
        hotkeyOverlay.visible = false;
        return;
    }

    // Hold at full opacity for 5s, then linear fade over the final 2s (total 7s)
    float alpha = (elapsed < 5.0f) ? 1.0f : 1.0f - ((elapsed - 5.0f) / 2.0f);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration
        | ImGuiWindowFlags_AlwaysAutoResize
        | ImGuiWindowFlags_NoInputs
        | ImGuiWindowFlags_NoFocusOnAppearing
        | ImGuiWindowFlags_NoMove;

    // RL Blue rounded bubble (#0079CF approx), slightly transparent background
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(16.f, 10.f));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.47f, 0.81f, 0.80f * alpha));

    ImGui::SetNextWindowPos(ImVec2(20.f, 20.f), ImGuiCond_Always);
    ImGui::SetNextWindowBgAlpha(0.80f * alpha);

    ImGui::Begin("##ss_hotkey_overlay", nullptr, flags);

    // Orange for success, Red for errors
    ImVec4 textColor = hotkeyOverlay.isError
        ? ImVec4(0.95f, 0.25f, 0.25f, alpha)
        : ImVec4(1.0f, 0.55f, 0.0f, alpha);

    ImGui::TextColored(textColor, "%s", hotkeyOverlay.text.c_str());

    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
}

std::string SuiteSpot::GetMenuName()
{

    return "suitespot_browser";
}

std::string SuiteSpot::GetMenuTitle()
{

    return "SuiteSpot Training Browser";
}

void SuiteSpot::SetImGuiContext(uintptr_t ctx)
{

    if (ctx) {

        imgui_ctx = ctx;

        ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));

        // Load clock font — GetFont first (hot-reload: font already in atlas, no rebuild)
        // Falls back to Execute + LoadFont (cold start: defers atlas rebuild to game thread)
        if (!clockFont) {
            auto gui = gameWrapper->GetGUIManager();
            clockFont = gui.GetFont("suitespot_clock_48");
            if (!clockFont) {
                gameWrapper->Execute([this](GameWrapper* gw) {
                    auto gui = gw->GetGUIManager();
                    auto [res, font] = gui.LoadFont("suitespot_clock_48", "Ubuntu-Regular.ttf", 48);
                    if (res == 2 && font) {
                        clockFont = font;
                    }
                });
            }
        }
    }
}

bool SuiteSpot::ShouldBlockInput()
{
    if (!isBrowserOpen) {
        return false; // Browser closed → no blocking
    }

    // Selective input blocking - consistent with TrainingPackUI
    ImGuiIO& io = ImGui::GetIO();

    // Block when actively typing in text fields (settings UI)
    if (io.WantTextInput && ImGui::IsAnyItemActive()) {
        return true;
    }

    // Allow normal mouse interaction without blocking game input
    return false;
}

bool SuiteSpot::IsActiveOverlay()
{
    return true;
}

void SuiteSpot::OnOpen()
{
    LOG("SuiteSpot: OnOpen called (autoOpen={})", isOverlayAutoOpen);
    isBrowserOpen = !isOverlayAutoOpen;  // true if user opened, false if auto-open
    if (!isOverlayAutoOpen && trainingPackUI) {
        trainingPackUI->SetOpen(true);
    }
    isOverlayAutoOpen = false;
}

void SuiteSpot::OnClose()
{
    if (isUnloading) return; // plugin is shutting down — do not schedule Execute() with a soon-to-be-freed `this`
    LOG("SuiteSpot: OnClose");

    if (isBrowserOpen && trainingPackUI) {
        // User was viewing the browser: close the UI and let window stay closed
        trainingPackUI->SetOpen(false);
        isBrowserOpen = false;
    } else {
        // Window was in silent mode: re-open silently to keep hotkey overlay alive
        LOG("SuiteSpot: Re-opening silently to keep hotkey overlay alive");
        isOverlayAutoOpen = true;
        gameWrapper->Execute([this](GameWrapper*) {
            cvarManager->executeCommand("openmenu suitespot_browser");
        });
    }
}

std::filesystem::path SuiteSpot::GetTrainingPacksPath() const
{
    return mapManager ? mapManager->GetTrainingPacksPath() : std::filesystem::path();
}

void SuiteSpot::LoadTrainingPacksFromFile(const std::filesystem::path& filePath)
{
    if (trainingPackMgr) {
        trainingPackMgr->LoadPacksFromFile(filePath);
    }
}

void SuiteSpot::ShowToastForAction(const std::string& message, bool isError)
{
    hotkeyOverlay.text = message;
    hotkeyOverlay.startTime = std::chrono::steady_clock::now();
    hotkeyOverlay.duration = 7.0f;
    hotkeyOverlay.isError = isError;
    hotkeyOverlay.visible = true;
}

void SuiteSpot::ShowToastError(const std::string& reason)
{
    ShowToastForAction("Load Now: Failed - " + reason, true);
}
