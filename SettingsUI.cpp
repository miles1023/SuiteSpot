#include "pch.h"

#include "SettingsUI.h"
#include "LoadoutUI.h"
#include "TrainingPackUI.h"
#include "SuiteSpot.h"
#include "MapManager.h"
#include "TrainingPackManager.h"
#include "WorkshopDownloader.h"
#include "SettingsSync.h"
#include "ConstantsUI.h"
#include "HelpersUI.h"
#include "DefaultPacks.h"
#include "F6ForDummies/ConfigParser.h"
#include "F6ForDummies/DescriptionsLoader.h"
#include "bakkesmod/wrappers/GuiManagerWrapper.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstring>
#include <ctime>

SettingsUI::SettingsUI(SuiteSpot* plugin) : plugin_(plugin) {}

void SettingsUI::RenderMainSettingsWindow()
{
    if (!plugin_) {
        return;
    }

    ImGui::SetWindowFontScale(UI::FONT_SCALE);

    // Header with metadata and Load Now button
    ImGui::BeginGroup();
    ImGui::TextColored(UI::SettingsUI::HEADER_TEXT_COLOR, "By: Flicks Creations");
    std::string ver = "Version: " + std::string(plugin_version);
    ImGui::TextColored(UI::SettingsUI::HEADER_TEXT_COLOR, "%s", ver.c_str());
    {
        // Format __DATE__ ("Mmm dd yyyy") and __TIME__ ("hh:mm:ss") into "Mmm. dd, yyyy h:mm:ss AM/PM"
        char buildDate[] = __DATE__; // e.g. "Feb 12 2026"
        char buildTime[] = __TIME__; // e.g. "23:50:30"
        int hour = (buildTime[0] - '0') * 10 + (buildTime[1] - '0');
        const char* ampm = hour >= 12 ? "PM" : "AM";
        int hour12 = hour % 12;
        if (hour12 == 0) hour12 = 12;
        // Month is first 3 chars, day starts at index 4, year starts at index 7
        char day[3] = {buildDate[4] == ' ' ? '0' : buildDate[4], buildDate[5], '\0'};
        ImGui::TextColored(UI::SettingsUI::HEADER_TEXT_COLOR, "Built: %.3s. %s, %.4s %d:%.2s:%.2s %s", buildDate, day,
                           buildDate + 7, hour12, buildTime + 3, buildTime + 6, ampm);
    }
    ImGui::EndGroup();

    // Live system clock - drawn directly on the draw list so it doesn't affect layout
    {
        // Retrieve the clock font (queued in onLoad, built asynchronously by BakkesMod)
        if (!plugin_->clockFont) {
            auto gui = plugin_->gameWrapper->GetGUIManager();
            plugin_->clockFont = gui.GetFont("suitespot_clock_48");
        }

        ImFont* font = plugin_->clockFont;
        if (font) {
            std::time_t now = std::time(nullptr);
            std::tm local{};
            localtime_s(&local, &now);
            int h = local.tm_hour % 12;
            if (h == 0) h = 12;
            const char* ap = local.tm_hour >= 12 ? "pm" : "am";
            char clockBuf[32];
            snprintf(clockBuf, sizeof(clockBuf), "%d:%02d:%02d%s", h, local.tm_min, local.tm_sec, ap);

            float fontSize = font->FontSize; // Native size — crisp rendering
            ImVec2 clockSize = font->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, clockBuf);
            ImVec2 windowPos = ImGui::GetWindowPos();
            float windowWidth = ImGui::GetWindowWidth();
            ImVec2 groupSize = ImGui::GetItemRectSize(); // size of the preceding group
            ImVec2 groupMin = ImGui::GetItemRectMin();   // top-left of the group
            float clockX = windowPos.x + (windowWidth - clockSize.x) * 0.5f;
            float clockY = groupMin.y + (groupSize.y - clockSize.y) * 0.5f;
            ImGui::GetWindowDrawList()->AddText(font, fontSize, ImVec2(clockX, clockY), IM_COL32(255, 255, 255, 255),
                                                clockBuf);
        }
    }

    ImGui::SameLine(ImGui::GetWindowWidth() - 150.0f);
    if (ImGui::Button("LOAD NOW", ImVec2(130, 26))) {
        int mapType = plugin_->GetMapType();
        SuiteSpot* p = plugin_;
        bool issuedLoad = false;

        if (mapType == 0) { // Freeplay
            std::string code = p->GetCurrentFreeplayCode();
            if (!code.empty()) {
                LOG("SuiteSpot UI: User clicked Load Now (Freeplay: {})", code);
                p->gameWrapper
                    ->SetTimeout([p, code](GameWrapper* gw) { p->cvarManager->executeCommand("load_freeplay " + code); },
                                 0.0f);
                statusMessage.ShowSuccess("Loading Freeplay", 2.0f, UI::StatusMessage::DisplayMode::TimerWithFade);
                issuedLoad = true;
            }
        } else if (mapType == 1) { // Training
            std::string code = p->settingsSync->GetQuickPicksSelectedCode();
            if (code.empty()) code = p->GetCurrentTrainingCode();

            if (!code.empty()) {
                LOG("SuiteSpot UI: User clicked Load Now (Training: {})", code);
                if (p->usageTracker) p->usageTracker->IncrementLoadCount(code);
                p->gameWrapper
                    ->SetTimeout([p, code](GameWrapper* gw) { p->cvarManager->executeCommand("load_training " + code); },
                                 0.0f);
                statusMessage.ShowSuccess("Loading Training Pack", 2.0f, UI::StatusMessage::DisplayMode::TimerWithFade);
                issuedLoad = true;
            }
        } else if (mapType == 2) { // Workshop
            std::string path = p->GetCurrentWorkshopPath();
            if (!path.empty()) {
                LOG("SuiteSpot UI: User clicked Load Now (Workshop: {})", path);
                p->gameWrapper->SetTimeout(
                    [p, path](GameWrapper* gw) { p->cvarManager->executeCommand("load_workshop \"" + path + "\""); },
                    0.0f);
                statusMessage.ShowSuccess("Loading Workshop Map", 2.0f, UI::StatusMessage::DisplayMode::TimerWithFade);
                issuedLoad = true;
            }
        }

        if (issuedLoad && p->cvarManager) {
            p->cvarManager->executeCommand("togglemenu settings");
        }
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Immediately load the currently selected map/pack");
    }

    ImGui::Spacing();
    statusMessage.Render(ImGui::GetIO().DeltaTime);
    if (statusMessage.IsVisible()) ImGui::Spacing();

    bool enabledValue = plugin_->IsEnabled();
    int mapTypeValue = plugin_->GetMapType();
    bool autoQueueValue = plugin_->IsAutoQueueEnabled();
    int delayQueueSecValue = plugin_->GetDelayQueueSec();
    int delayFreeplaySecValue = plugin_->GetDelayFreeplaySec();
    int delayTrainingSecValue = plugin_->GetDelayTrainingSec();
    int delayWorkshopSecValue = plugin_->GetDelayWorkshopSec();
    std::string currentFreeplayCode = plugin_->GetCurrentFreeplayCode();
    std::string currentTrainingCode = plugin_->GetCurrentTrainingCode();
    std::string quickPicksSelectedCode = plugin_->settingsSync->GetQuickPicksSelectedCode();
    std::string currentWorkshopPath = plugin_->GetCurrentWorkshopPath();

    // Only show status if enabled
    if (enabledValue) {
        ImGui::Separator();

        const char* modeNames[] = {"Freeplay", "Training", "Workshop"};
        std::string currentMap = "<none>";
        std::string queueDelayStr = std::to_string(delayQueueSecValue) + "s";
        std::string mapDelayStr = "0s";
        const ImVec4 white = UI::SettingsUI::STATUS_SEPARATOR_COLOR;

        // Get current selection and appropriate delay
        if (mapTypeValue == 0) {
            // Find freeplay map by code
            auto it = std::find_if(RLMaps.begin(), RLMaps.end(),
                                   [&](const MapEntry& e) { return e.code == currentFreeplayCode; });
            if (it != RLMaps.end()) {
                currentMap = it->name;
            }
            mapDelayStr = std::to_string(delayFreeplaySecValue) + "s";
        } else if (mapTypeValue == 1) {
            mapDelayStr = std::to_string(delayTrainingSecValue) + "s";

            // Get packs from manager for consistent lookup
            const auto& trainingPacks = plugin_->trainingPackMgr ? plugin_->trainingPackMgr->GetPacks() : RLTraining;

            std::string targetCode = quickPicksSelectedCode;
            if (targetCode.empty()) targetCode = currentTrainingCode;

            auto targetPack = plugin_->trainingPackMgr->GetPackByCode(targetCode);
            if (targetPack) {
                currentMap = targetPack->name;
            } else if (!targetCode.empty()) {
                currentMap = targetCode + " (custom)";
            } else {
                currentMap = "<none selected>";
            }

            mapDelayStr = "with " + std::to_string(delayTrainingSecValue) + "s delay";
        } else if (mapTypeValue == 2) {
            // Find workshop map by path
            auto it = std::find_if(RLWorkshop.begin(), RLWorkshop.end(),
                                   [&](const WorkshopEntry& e) { return e.filePath == currentWorkshopPath; });
            if (it != RLWorkshop.end()) {
                currentMap = it->name;
            }
            mapDelayStr = std::to_string(delayWorkshopSecValue) + "s";
        }

        // Map mode status
        const ImVec4 green = UI::SettingsUI::STATUS_ENABLED_TEXT_COLOR;
        const ImVec4 red = UI::SettingsUI::STATUS_DISABLED_TEXT_COLOR;
        std::string modeText = "Mode: " + std::string(modeNames[mapTypeValue]);

        int currentDelay = (mapTypeValue == 0) ? delayFreeplaySecValue
                                               : (mapTypeValue == 1 ? delayTrainingSecValue : delayWorkshopSecValue);
        if (currentDelay > 0) {
            modeText += " Delayed: " + mapDelayStr;
        }

        ImGui::TextColored(green, "%s", modeText.c_str());
        ImGui::SameLine();
        ImGui::TextColored(white, "|");
        ImGui::SameLine();
        ImGui::TextColored(green, "Map: %s", currentMap.c_str());
        ImGui::SameLine();
        ImGui::TextColored(white, "|");
        ImGui::SameLine();
        const ImVec4 queueColor = autoQueueValue ? green : red;
        if (delayQueueSecValue > 0) {
            ImGui::TextColored(queueColor, "Next Match Queue Delayed: %s", queueDelayStr.c_str());
        } else {
            ImGui::TextColored(queueColor, "Next Match Queue");
        }
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    // 1) Global Controls
    // ...
    ImGui::Spacing();

    // 1) Global Controls (Enable/Disable + Map Mode) - above the tabs
    RenderGeneralTab(enabledValue, mapTypeValue);
    ImGui::Spacing();
    ImGui::Separator();

    // Main tab bar - disabled when plugin is off
    if (!enabledValue) {
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
    }

    if (ImGui::BeginTabBar("SuiteSpotTabs", ImGuiTabBarFlags_None)) {

        // ===== MAP SELECT TAB =====
        if (ImGui::BeginTabItem("Map Select")) {
            if (enabledValue) {
                ImGui::Spacing();

                // 1) Unified Header: Auto-Queue Toggle | Queue Delay | Map Delay
                ImGui::Columns(2, "MapSelectHeaderCols", false);
                ImGui::SetColumnWidth(0, 150.0f);

                // Auto-Queue
                UI::Helpers::CheckboxWithCVar("Auto-Queue", autoQueueValue, "suitespot_auto_queue",
                                              plugin_->cvarManager, plugin_->gameWrapper,
                                              "Automatically queue into the next match after the current match ends.");
                ImGui::NextColumn();
                ImGui::NextColumn(); // Skip right column

                // Queue Delay
                ImGui::Text("Queue Delay");
                ImGui::NextColumn();
                ImGui::SetNextItemWidth(-1);
                UI::Helpers::InputIntWithRange("##QueueDelay", delayQueueSecValue,
                                               UI::SettingsUI::DELAY_QUEUE_MIN_SECONDS,
                                               UI::SettingsUI::DELAY_QUEUE_MAX_SECONDS, 0.0f,
                                               "suitespot_delay_queue_sec", plugin_->cvarManager, plugin_->gameWrapper,
                                               "Wait before auto-queuing.", nullptr);
                ImGui::NextColumn();

                // Map Delay (Context-sensitive)
                int* currentMapDelayValue = &delayFreeplaySecValue;
                const char* currentMapDelayCVar = "suitespot_delay_freeplay_sec";
                const char* mapDelayTooltip = "Wait before loading Freeplay.";

                if (mapTypeValue == 1) { // Training
                    currentMapDelayValue = &delayTrainingSecValue;
                    currentMapDelayCVar = "suitespot_delay_training_sec";
                    mapDelayTooltip = "Wait before loading Training.";
                } else if (mapTypeValue == 2) { // Workshop
                    currentMapDelayValue = &delayWorkshopSecValue;
                    currentMapDelayCVar = "suitespot_delay_workshop_sec";
                    mapDelayTooltip = "Wait before loading Workshop.";
                }

                ImGui::Text("Map Delay");
                ImGui::NextColumn();
                ImGui::SetNextItemWidth(-1);
                UI::Helpers::InputIntWithRange("##MapDelay", *currentMapDelayValue, 0, 300, 0.0f, currentMapDelayCVar,
                                               plugin_->cvarManager, plugin_->gameWrapper, mapDelayTooltip, nullptr);
                ImGui::NextColumn();

                ImGui::Columns(1); // Reset

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();

                // 2) Map Selection Logic
                RenderMapSelectionTab(mapTypeValue, currentFreeplayCode, currentTrainingCode, currentWorkshopPath,
                                      delayFreeplaySecValue, delayTrainingSecValue, delayWorkshopSecValue,
                                      delayQueueSecValue);
            } else {
                ImGui::Spacing();
                ImGui::TextDisabled("Enable SuiteSpot to configure map settings.");
            }

            ImGui::EndTabItem();
        }

        // ===== LOADOUT MANAGEMENT TAB =====
        if (ImGui::BeginTabItem("Loadout Management")) {
            if (enabledValue) {
                if (plugin_->loadoutUI) {
                    plugin_->loadoutUI->RenderLoadoutControls();
                }
            } else {
                ImGui::Spacing();
                ImGui::TextDisabled("Enable SuiteSpot to manage loadouts.");
            }
            ImGui::EndTabItem();
        }

        // ===== HOTKEYS TAB =====
        // TODO: hotkeys tab — disabled pending crash investigation; re-enable with hotkeys feature
        /*
        if (ImGui::BeginTabItem("Hotkeys")) {
            ImGui::Spacing();
            ImGui::TextDisabled("Click Bind to capture a key press, or type the UE3 name manually.");
            ImGui::TextDisabled("Key 1 = trigger.  Key 2 = held combo partner (optional).");
            ImGui::Spacing();

            // Color per action group
            static const ImVec4 kGroupColors[] = {
                {0.40f, 0.65f, 1.00f, 1.0f},   // Cycle Mode Fwd  — blue
                {0.40f, 0.65f, 1.00f, 1.0f},   // Cycle Mode Back — blue
                {0.35f, 0.85f, 0.55f, 1.0f},   // Cycle Map Fwd   — green
                {0.35f, 0.85f, 0.55f, 1.0f},   // Cycle Map Back  — green
                {1.00f, 0.65f, 0.10f, 1.0f},   // Load Now        — orange
            };

            ImDrawList* wdl = ImGui::GetWindowDrawList();

            for (int i = 0; i < 5; i++) {
                const auto& row = UI::SettingsUI::HOTKEY_ROWS[i];
                ImGui::PushID(i);

                // Separator before "Load Now" group
                if (i == 4) {
                    ImGui::Spacing(); ImGui::Separator(); ImGui::Spacing();
                }

                // Card background using splitter
                ImDrawListSplitter splitter;
                splitter.Split(wdl, 2);
                splitter.SetCurrentChannel(wdl, 1);  // controls on front

                ImVec2 rowMin = ImGui::GetCursorScreenPos();
                rowMin.x -= 4.0f;
                rowMin.y -= 2.0f;

                // Action label — full width, colored by group
                ImGui::PushStyleColor(ImGuiCol_Text, kGroupColors[i]);
                ImGui::TextUnformatted(row.label);
                ImGui::PopStyleColor();

                // Render two key slots vertically
                for (int slot = 0; slot < 2; slot++) {
                    const char* cvarName = (slot == 0) ? row.key1CVar : row.key2CVar;
                    char buf[64] = {};
                    if (auto cvar = plugin_->cvarManager->getCvar(cvarName); !cvar.IsNull())
                        strncpy_s(buf, cvar.getStringValue().c_str(), sizeof(buf) - 1);

                    bool cap = (plugin_->captureRow == i && plugin_->captureSlot == slot);

                    ImGui::Indent(12.0f);
                    ImGui::AlignTextToFramePadding();
                    ImGui::TextDisabled("Key %d", slot + 1);
                    ImGui::SameLine();

                    float inputW = ImGui::GetContentRegionAvail().x * 0.55f;

                    // Styled key input (badge look)
                    ImGui::PushStyleColor(ImGuiCol_FrameBg,        IM_COL32(18, 24, 42, 220));
                    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, IM_COL32(28, 36, 60, 255));
                    ImGui::PushStyleColor(ImGuiCol_Border,         IM_COL32(70, 110, 180, 200));
                    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 5.0f);
                    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(8.0f, 4.0f));

                    char inputId[16];
                    snprintf(inputId, sizeof(inputId), "##k%d", slot);

                    if (cap) {
                        ImGui::SetNextItemWidth(inputW);
                        char capBuf[] = "Press any key...";
                        ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(80, 20, 20, 220));
                        ImGui::InputText(inputId, capBuf, sizeof(capBuf), ImGuiInputTextFlags_ReadOnly);
                        ImGui::PopStyleColor();
                    } else {
                        ImGui::SetNextItemWidth(inputW);
                        if (ImGui::InputText(inputId, buf, sizeof(buf), ImGuiInputTextFlags_EnterReturnsTrue))
                            UI::Helpers::SetCVarSafely(cvarName, std::string(buf), plugin_->cvarManager,
                                                       plugin_->gameWrapper);
                        if (ImGui::IsItemDeactivatedAfterEdit())
                            UI::Helpers::SetCVarSafely(cvarName, std::string(buf), plugin_->cvarManager,
                                                       plugin_->gameWrapper);
                        const char* tip = (slot == 0)
                            ? "Trigger key — press Bind to capture, or type UE3 name"
                            : "Held key — must also be down when Key 1 fires (empty = single-key bind)";
                        if (ImGui::IsItemHovered()) ImGui::SetTooltip("%s", tip);
                    }

                    ImGui::PopStyleVar(2);
                    ImGui::PopStyleColor(3);

                    // Bind / Stop button
                    ImGui::SameLine(0, 4);
                    ImGui::PushID(slot);
                    if (cap) {
                        ImGui::PushStyleColor(ImGuiCol_Button,        IM_COL32(160, 40,  40,  255));
                        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(200, 60,  60,  255));
                        if (ImGui::Button("Stop", ImVec2(48, 0))) {
                            plugin_->captureRow = -1;
                        }
                        ImGui::PopStyleColor(2);
                        if (ImGui::IsItemHovered()) ImGui::SetTooltip("Cancel (or press Esc)");
                    } else {
                        ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(30, 50, 90, 200));
                        if (ImGui::Button("Bind", ImVec2(48, 0))) {
                            plugin_->captureRow = i;
                            plugin_->captureSlot = slot;
                        }
                        ImGui::PopStyleColor();
                        if (ImGui::IsItemHovered()) ImGui::SetTooltip("Click then press any key to capture");
                    }

                    // Clear X button
                    if (!cap && buf[0] != '\0') {
                        ImGui::SameLine(0, 2);
                        char clrId[16];
                        snprintf(clrId, sizeof(clrId), "X##k%dx", slot);
                        if (ImGui::SmallButton(clrId))
                            UI::Helpers::SetCVarSafely(cvarName, std::string(""), plugin_->cvarManager,
                                                       plugin_->gameWrapper);
                    }
                    ImGui::PopID();
                    ImGui::Unindent(12.0f);
                }

                // Draw card background behind the row content
                ImVec2 rowMax = {rowMin.x + ImGui::GetContentRegionAvail().x + 8.0f,
                                 ImGui::GetCursorScreenPos().y + 2.0f};
                splitter.SetCurrentChannel(wdl, 0);  // bg behind
                wdl->AddRectFilled(rowMin, rowMax, IM_COL32(22, 28, 48, 160), 6.0f);
                splitter.Merge(wdl);

                ImGui::PopID();
                ImGui::Spacing();
            }

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            // Styled Save Hotkeys button
            ImGui::PushStyleColor(ImGuiCol_Button,        IM_COL32(0,  100, 200, 220));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(30, 130, 240, 255));
            ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(16.0f, 6.0f));
            if (ImGui::Button("Save Hotkeys")) plugin_->cvarManager->executeCommand("writeconfig", false);
            ImGui::PopStyleVar();
            ImGui::PopStyleColor(2);
            if (ImGui::IsItemHovered()) ImGui::SetTooltip("Persist hotkey settings to config file");
            ImGui::EndTabItem();
        }
        */

        // ===== F6 FOR DUMMIES TAB =====
        if (ImGui::BeginTabItem("F6 For Dummies")) {
            RenderF6ForDummiesTab();
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    if (!enabledValue) {
        ImGui::PopStyleVar();
    }
}

void SettingsUI::RenderGeneralTab(bool& enabledValue, int& mapTypeValue)
{
    ImGui::Columns(2, "GeneralTabCols", false); // Invisible columns

    // Col 1: Enable
    UI::Helpers::CheckboxWithCVar("Enable SuiteSpot", enabledValue, "suitespot_enabled", plugin_->cvarManager,
                                  plugin_->gameWrapper, "Enable/disable all SuiteSpot auto-loading and queuing features");

    ImGui::NextColumn();

    // Col 2: Map Mode
    ImGui::TextUnformatted("Map Mode:");
    ImGui::SameLine();

    const char* mapLabels[] = {"Freeplay", "Training", "Workshop"};
    for (int i = 0; i < 3; i++) {
        if (i > 0) ImGui::SameLine(0, UI::SettingsUI::MAP_TYPE_RADIO_BUTTON_SPACING);
        if (ImGui::RadioButton(mapLabels[i], mapTypeValue == i)) {
            mapTypeValue = i;
            LOG("SuiteSpot UI: User switched Map Mode to {}", mapLabels[i]);
            UI::Helpers::SetCVarSafely("suitespot_map_type", mapTypeValue, plugin_->cvarManager, plugin_->gameWrapper);
        }
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Choose which map type loads after matches:\nFreeplay = Official | Training = Custom Packs | "
                          "Workshop = Modded Maps");
    }

    ImGui::Columns(1); // Reset
    ImGui::Spacing();

    bool gameSpeedFixEnabled = plugin_->settingsSync ? plugin_->settingsSync->IsTrainingGameSpeedFixEnabled() : true;
    if (UI::Helpers::CheckboxWithCVar("Fix Training Game Speed", gameSpeedFixEnabled,
                                      "suitespot_fix_training_gamespeed", plugin_->cvarManager, plugin_->gameWrapper,
                                      "Sync in-game training speed with sv_soccar_gamespeed in training playlists.")) {
        LOG("Fix Training Game Speed toggled to {}", gameSpeedFixEnabled ? "ON" : "OFF");
    }
}

void SettingsUI::RenderMapSelectionTab(int mapTypeValue, std::string& currentFreeplayCode,
                                       std::string& currentTrainingCode, std::string& currentWorkshopPath,
                                       int& delayFreeplaySecValue, int& delayTrainingSecValue,
                                       int& delayWorkshopSecValue, int& delayQueueSecValue)
{
    ImGui::TextUnformatted("Map Selection:");
    ImGui::Spacing();

    if (mapTypeValue == 0) {
        RenderFreeplayMode(currentFreeplayCode);
    } else if (mapTypeValue == 1) {
        RenderTrainingMode(0, currentTrainingCode);
    } else if (mapTypeValue == 2) {
        RenderWorkshopMode(currentWorkshopPath);
    }
}

void SettingsUI::RenderFreeplayMode(std::string& currentFreeplayCode)
{
    // Initialize to first map if empty and maps are available
    if (currentFreeplayCode.empty() && !RLMaps.empty()) {
        currentFreeplayCode = RLMaps[0].code;
        plugin_->settingsSync->SetCurrentFreeplayCode(currentFreeplayCode);
        plugin_->cvarManager->getCvar("suitespot_current_freeplay_code").setValue(currentFreeplayCode);
    }

    // Find current selection index for display
    int currentIndex = 0;
    if (!currentFreeplayCode.empty()) {
        for (int i = 0; i < (int)RLMaps.size(); i++) {
            if (RLMaps[i].code == currentFreeplayCode) {
                currentIndex = i;
                break;
            }
        }
    }

    const char* freeplayLabel = RLMaps.empty() ? "<none>" : RLMaps[currentIndex].name.c_str();

    ImGui::Columns(2, "FreeplayCols", false);
    ImGui::SetColumnWidth(0, 150.0f);

    ImGui::Text("Freeplay Map");
    ImGui::NextColumn();

    ImGui::SetNextItemWidth(-1);
    if (UI::Helpers::ComboWithTooltip("##FreeplayMap", freeplayLabel, "Select which stadium to load after matches",
                                      -1.0f)) {
        ImGuiListClipper clipper;
        clipper.Begin((int)RLMaps.size());
        while (clipper.Step()) {
            for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++) {
                bool selected = (RLMaps[row].code == currentFreeplayCode);
                if (ImGui::Selectable(RLMaps[row].name.c_str(), selected)) {
                    currentFreeplayCode = RLMaps[row].code;
                    LOG("SuiteSpot UI: User selected Freeplay map: {} ({})", RLMaps[row].name, currentFreeplayCode);
                    plugin_->settingsSync->SetCurrentFreeplayCode(currentFreeplayCode);
                    plugin_->cvarManager->getCvar("suitespot_current_freeplay_code").setValue(currentFreeplayCode);
                }
            }
        }
        ImGui::EndCombo();
    }
    ImGui::Columns(1);
}

void SettingsUI::RenderTrainingMode(int trainingModeValue, std::string& currentTrainingCode)
{
    RenderSinglePackMode(currentTrainingCode);

    ImGui::Spacing();

    if (ImGui::Button("Open Training Pack Browser", ImVec2(250, 30))) {
        if (plugin_->trainingPackUI) {
            plugin_->trainingPackUI->SetOpen(true);
            plugin_->isBrowserOpen = true;
        }
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Open the full training pack browser to manage bags and packs");
    }
}

void SettingsUI::RenderWorkshopMode(std::string& currentWorkshopPath)
{
    if (ImGui::BeginTabBar("##WorkshopSubTabs")) {
        if (ImGui::BeginTabItem("Installed Maps")) {
            RenderInstalledMaps(currentWorkshopPath);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Map Browser")) {
            RenderWorkshopBrowserTab();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
}

void SettingsUI::RenderInstalledMaps(std::string& currentWorkshopPath)
{
    // Header with Refresh button
    ImGui::Spacing();
    ImGui::SameLine(ImGui::GetContentRegionAvail().x - 70.0f);
    if (ImGui::Button("Refresh", ImVec2(70, 0))) {
        plugin_->LoadWorkshopMaps();
        selectedWorkshopIndex = -1; // Reset selection
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Rescan workshop folders for maps");
    }
    ImGui::Spacing();

    // Check if we have any maps
    if (RLWorkshop.empty()) {
        ImGui::TextColored(UI::WorkshopBrowserUI::NO_MAPS_COLOR, "No workshop maps found.");
        ImGui::TextDisabled("Maps are discovered from:");
        ImGui::BulletText("WorkshopMapLoader configured path");
        ImGui::BulletText("Epic Games install mods folder");
        ImGui::BulletText("Steam install mods folder");
        ImGui::Spacing();
        ImGui::TextDisabled("Download maps from the Map Browser tab.");
        return;
    }

    // Initialize selection from current CVar if needed
    if (selectedWorkshopIndex < 0 && !currentWorkshopPath.empty()) {
        for (int i = 0; i < (int)RLWorkshop.size(); i++) {
            if (RLWorkshop[i].filePath == currentWorkshopPath) {
                selectedWorkshopIndex = i;
                break;
            }
        }
    }

    // Clamp selection to valid range
    if (selectedWorkshopIndex >= (int)RLWorkshop.size()) {
        selectedWorkshopIndex = (int)RLWorkshop.size() - 1;
    }

    // Calculate panel widths
    float availWidth = ImGui::GetContentRegionAvail().x;
    float leftWidth = std::max(UI::WorkshopBrowserUI::LEFT_PANEL_MIN_WIDTH,
                               availWidth * UI::WorkshopBrowserUI::LEFT_PANEL_WIDTH_PERCENT);
    float rightWidth = availWidth - leftWidth - ImGui::GetStyle().ItemSpacing.x;

    // Two-panel layout
    ImGui::BeginGroup();

    // === LEFT PANEL: Map List ===
    if (ImGui::BeginChild("WorkshopMapList", ImVec2(leftWidth, UI::WorkshopBrowserUI::BROWSER_HEIGHT), true)) {
        ImGui::TextDisabled("%d maps", (int)RLWorkshop.size());
        ImGui::Separator();

        for (int i = 0; i < (int)RLWorkshop.size(); i++) {
            const auto& entry = RLWorkshop[i];
            bool isSelected = (i == selectedWorkshopIndex);
            bool isCurrentAutoLoad = (entry.filePath == currentWorkshopPath);

            ImGui::PushID(i);

            // Show marker if this is the current auto-load selection
            if (isCurrentAutoLoad) {
                ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::SELECTED_BADGE_COLOR);
                ImGui::Text(">");
                ImGui::PopStyleColor();
                ImGui::SameLine();
            }

            if (ImGui::Selectable(entry.name.c_str(), isSelected, ImGuiSelectableFlags_None)) {
                selectedWorkshopIndex = i;
                // FIX: Update CVar immediately when selection changes (not just on explicit button click)
                // This synchronizes selectedWorkshopIndex with currentWorkshopPath so "Load Now" works
                currentWorkshopPath = entry.filePath;
                LOG("SuiteSpot UI: User selected Workshop map: {} ({})", entry.name, entry.filePath);
                plugin_->settingsSync->SetCurrentWorkshopPath(entry.filePath);
                if (auto cvar = plugin_->cvarManager->getCvar("suitespot_current_workshop_path")) {
                    cvar.setValue(entry.filePath);
                }
            }

            // Double-click to load immediately
            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                SuiteSpot* p = plugin_;
                std::string path = entry.filePath;
                p->gameWrapper->SetTimeout(
                    [p, path](GameWrapper* gw) { p->cvarManager->executeCommand("load_workshop \"" + path + "\""); },
                    0.0f);
                statusMessage.ShowSuccess("Loading Workshop Map", 2.0f, UI::StatusMessage::DisplayMode::TimerWithFade);
                if (p->cvarManager) {
                    p->cvarManager->executeCommand("togglemenu settings");
                }
            }

            ImGui::PopID();
        }
    }
    ImGui::EndChild();

    ImGui::SameLine();

    // === RIGHT PANEL: Details Pane ===
    if (ImGui::BeginChild("WorkshopMapDetails", ImVec2(rightWidth, UI::WorkshopBrowserUI::BROWSER_HEIGHT), true)) {
        if (selectedWorkshopIndex >= 0 && selectedWorkshopIndex < (int)RLWorkshop.size()) {
            auto& selectedMap = RLWorkshop[selectedWorkshopIndex];

            // Load preview image if needed (lazy loading)
            if (!selectedMap.previewPath.empty() && !selectedMap.isImageLoaded && !selectedMap.previewImage) {
                selectedMap.previewImage = std::make_shared<ImageWrapper>(selectedMap.previewPath.string(), false, true);
                selectedMap.isImageLoaded = true;
            }

            // Preview image — fills available panel width at 16:9
            {
                float previewW = ImGui::GetContentRegionAvail().x;
                float previewH = previewW * (9.0f / 16.0f);
                if (selectedMap.previewImage && selectedMap.previewImage->GetImGuiTex()) {
                    ImVec2 p = ImGui::GetCursorScreenPos();
                    ImGui::GetWindowDrawList()->AddImageRounded(
                        selectedMap.previewImage->GetImGuiTex(),
                        p, ImVec2(p.x + previewW, p.y + previewH),
                        ImVec2(0, 0), ImVec2(1, 1), IM_COL32_WHITE, 6.0f);
                    ImGui::Dummy(ImVec2(previewW, previewH));
                } else {
                    // Placeholder box
                    ImVec2 p = ImGui::GetCursorScreenPos();
                    ImDrawList* drawList = ImGui::GetWindowDrawList();
                    drawList->AddRectFilled(p,
                                            ImVec2(p.x + previewW, p.y + previewH),
                                            ImColor(40, 40, 45, 255), 6.0f);
                    drawList->AddText(ImVec2(p.x + previewW / 2 - 40,
                                             p.y + previewH / 2 - 8),
                                      ImColor(100, 100, 100, 255), "No Preview");
                    ImGui::Dummy(ImVec2(previewW, previewH));
                }
            }

            ImGui::Spacing();

            // Map name (large)
            ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::MAP_NAME_COLOR);
            ImGui::TextWrapped("%s", selectedMap.name.c_str());
            ImGui::PopStyleColor();

            // Author
            if (!selectedMap.author.empty()) {
                ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::AUTHOR_COLOR);
                ImGui::Text("By: %s", selectedMap.author.c_str());
                ImGui::PopStyleColor();
            }

            ImGui::Spacing();

            // Description
            if (!selectedMap.description.empty()) {
                ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::DESCRIPTION_COLOR);
                ImGui::PushTextWrapPos(ImGui::GetContentRegionAvail().x);
                ImGui::TextWrapped("%s", selectedMap.description.c_str());
                ImGui::PopTextWrapPos();
                ImGui::PopStyleColor();
            }

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            // Current selection indicator
            bool isCurrentAutoLoad = (selectedMap.filePath == currentWorkshopPath);
            if (isCurrentAutoLoad) {
                ImGui::TextColored(UI::WorkshopBrowserUI::SELECTED_BADGE_COLOR, "Selected for Post-Match Auto-Load");
                ImGui::Spacing();
            }

            // Action buttons
            if (!isCurrentAutoLoad) {
                if (ImGui::Button("Select for Post-Match", ImVec2(180, 26))) {
                    plugin_->settingsSync->SetCurrentWorkshopPath(selectedMap.filePath);
                    plugin_->cvarManager->getCvar("suitespot_current_workshop_path").setValue(selectedMap.filePath);
                    currentWorkshopPath = selectedMap.filePath;
                    statusMessage.ShowSuccess("Workshop map selected", 2.0f,
                                              UI::StatusMessage::DisplayMode::TimerWithFade);
                }
                if (ImGui::IsItemHovered()) {
                    ImGui::SetTooltip("Set this map to load after matches end");
                }
            }

            ImGui::SameLine();

            if (ImGui::Button("Load Now", ImVec2(100, 26))) {
                SuiteSpot* p = plugin_;
                std::string path = selectedMap.filePath;
                p->gameWrapper->SetTimeout(
                    [p, path](GameWrapper* gw) { p->cvarManager->executeCommand("load_workshop \"" + path + "\""); },
                    0.0f);
                statusMessage.ShowSuccess("Loading Workshop Map", 2.0f, UI::StatusMessage::DisplayMode::TimerWithFade);
                if (p->cvarManager) {
                    p->cvarManager->executeCommand("togglemenu settings");
                }
            }
            if (ImGui::IsItemHovered()) {
                ImGui::SetTooltip("Load this workshop map immediately");
            }

        } else {
            // No selection
            ImGui::TextDisabled("Select a map from the list");
        }
    }
    ImGui::EndChild();

    ImGui::EndGroup();
}

void SettingsUI::RenderSinglePackMode(std::string& currentTrainingCode)
{
    // Toggle between Flicks Picks and Your Favorites
    int listType = plugin_->settingsSync->GetQuickPicksListType();

    ImGui::TextUnformatted("List Type:");
    ImGui::SameLine();

    if (ImGui::RadioButton("Flicks Picks", listType == 0)) {
        UI::Helpers::SetCVarSafely("suitespot_quickpicks_list_type", 0, plugin_->cvarManager, plugin_->gameWrapper);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Curated selection of 10 essential training packs");
    }
    ImGui::SameLine();
    if (ImGui::RadioButton("Your Favorites", listType == 1)) {
        UI::Helpers::SetCVarSafely("suitespot_quickpicks_list_type", 1, plugin_->cvarManager, plugin_->gameWrapper);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Your most-used training packs based on load history");
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    // Display header based on list type
    if (listType == 0) {
        ImGui::TextColored(UI::TrainingPackUI::SECTION_HEADER_TEXT_COLOR, "Flicks Picks");
    } else {
        ImGui::TextColored(UI::TrainingPackUI::SECTION_HEADER_TEXT_COLOR, "Your Favorites");
    }
    ImGui::SameLine();
    ImGui::TextDisabled("(Select post-match pack)");

    std::vector<std::string> quickPicks = GetQuickPicksList();
    std::string selectedCode = plugin_->settingsSync->GetQuickPicksSelectedCode();

    // If nothing selected, default to the first one in the list
    if (selectedCode.empty() && !quickPicks.empty()) {
        selectedCode = quickPicks[0];
        plugin_->settingsSync->SetQuickPicksSelected(selectedCode);
        plugin_->cvarManager->getCvar("suitespot_quickpicks_selected").setValue(selectedCode);
    }

    if (ImGui::BeginChild("QuickPicksList", ImVec2(UI::QuickPicksUI::TABLE_WIDTH, UI::QuickPicksUI::TABLE_HEIGHT), true)) {
        for (const auto& code : quickPicks) {
            std::string name = "Unknown Pack";
            int shots = 0;
            std::string description = "";
            bool found = false;

            // 1. Try to find in loaded cache
            const auto& trainingPacks = plugin_->trainingPackMgr ? plugin_->trainingPackMgr->GetPacks() : RLTraining;
            auto it = std::find_if(trainingPacks.begin(), trainingPacks.end(),
                                   [&](const TrainingEntry& e) { return e.code == code; });

            if (it != trainingPacks.end()) {
                name = it->name;
                shots = it->shotCount;
                description = it->staffComments.empty() ? it->notes : it->staffComments;
                found = true;
            } else {
                // 2. Try to find in DefaultPacks (Hardcoded fallback for first run)
                for (const auto& defPack : DefaultPacks::FLICKS_PICKS) {
                    if (defPack.code == code) {
                        name = defPack.name;
                        shots = defPack.shotCount;
                        description = defPack.description;
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                bool isSelected = (code == selectedCode);

                // Add top padding
                ImGui::Dummy(ImVec2(0, 4.0f));

                ImGui::PushID(code.c_str());
                if (ImGui::RadioButton("##select", isSelected)) {
                    selectedCode = code;
                    LOG("SuiteSpot UI: User selected Training pack: {} ({})", name, code);
                    plugin_->settingsSync->SetQuickPicksSelected(code);
                    plugin_->cvarManager->getCvar("suitespot_quickpicks_selected").setValue(code);
                }
                ImGui::SameLine();

                // Name and Shot Count
                float availWidth = ImGui::GetContentRegionAvail().x;
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f)); // White for name
                ImGui::Text("%s", name.c_str());
                ImGui::PopStyleColor();
                ImGui::SameLine(availWidth - 80.0f);
                ImGui::TextDisabled("| %d shots", shots);

                // Description (Indented and Wrapped)
                if (!description.empty()) {
                    ImGui::Indent(28.0f);
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.6f, 0.6f, 0.6f, 1.0f)); // Darker gray for description
                    ImGui::PushTextWrapPos(ImGui::GetWindowContentRegionWidth() - 10.0f);
                    ImGui::TextUnformatted(description.c_str());
                    ImGui::PopTextWrapPos();
                    ImGui::PopStyleColor();
                    ImGui::Unindent(28.0f);
                }

                // Add bottom padding
                ImGui::Dummy(ImVec2(0, 4.0f));

                ImGui::Separator();
                ImGui::PopID();
            }
        }
    }
    ImGui::EndChild();
}

std::vector<std::string> SettingsUI::GetQuickPicksList()
{
    int listType = plugin_->settingsSync->GetQuickPicksListType();

    // Build Flicks Picks list
    std::vector<std::string> flicksPicks;
    for (const auto& p : DefaultPacks::FLICKS_PICKS) {
        flicksPicks.push_back(p.code);
    }

    // If Flicks Picks mode is selected, always return Flicks Picks
    if (listType == 0) {
        return flicksPicks;
    }

    // Your Favorites mode - use usage tracker
    if (!plugin_->usageTracker) return flicksPicks;

    // If first run or no data, fallback to Flicks Picks
    if (plugin_->usageTracker->IsFirstRun()) {
        return flicksPicks;
    }

    int count = plugin_->settingsSync->GetQuickPicksCount();
    auto topCodes = plugin_->usageTracker->GetTopUsedCodes(count);

    // If no favorites yet, fallback to Flicks Picks
    if (topCodes.empty()) return flicksPicks;

    return topCodes;
}

// ── Workshop Search Scoring ────────────────────────────────────────────────
// Returns relevance score >= 1 if query found in result, -1 if no match.
// Higher = better match. Uses search-engine best practices:
//   1000 = exact name match
//    900 = name starts with query (prefix)
//    800 = any word in name starts with query (word boundary)
//    700-N = query found at position N in name (earlier = better)
//    +50 per extra occurrence (frequency bonus)
//    +100 if author also matches
static int ScoreResult(const std::string& queryLower, const RLMAPS_MapResult& result)
{
    if (queryLower.empty()) return 1; // No filter: everything passes

    std::string nameLower = result.Name;
    std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);

    size_t firstPos = nameLower.find(queryLower);
    if (firstPos == std::string::npos) return -1; // No match → exclude

    int score = 0;

    // Tier 1: exact match
    if (nameLower == queryLower) {
        score = 1000;
    }
    // Tier 2: prefix match (name starts with query)
    else if (nameLower.compare(0, queryLower.size(), queryLower) == 0) {
        score = 900;
    }
    // Tier 3: word boundary match
    else {
        bool wordBoundary = false;
        // A word boundary = position 0 or preceded by space
        size_t searchPos = 0;
        while ((searchPos = nameLower.find(queryLower, searchPos)) != std::string::npos) {
            if (searchPos == 0 || nameLower[searchPos - 1] == ' ') {
                wordBoundary = true;
                break;
            }
            searchPos++;
        }
        if (wordBoundary) {
            score = 800;
        } else {
            // Tier 4: position-based (max 700, minus 10 per character of distance)
            score = std::max(1, 700 - (int)firstPos * 10);
        }
    }

    // Frequency bonus: extra +50 per additional occurrence after the first
    size_t countPos = 0;
    int occurrences = 0;
    while ((countPos = nameLower.find(queryLower, countPos)) != std::string::npos) {
        occurrences++;
        countPos += queryLower.size();
    }
    if (occurrences > 1) score += (occurrences - 1) * 50;

    // Author bonus: +100 if query appears in author name too
    std::string authorLower = result.Author;
    std::transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
    if (!authorLower.empty() && authorLower.find(queryLower) != std::string::npos) score += 100;

    return std::max(score, 1);
}

void SettingsUI::RebuildDisplayList()
{
    std::string query = localFilterBuf;
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);

    // Score and filter
    std::vector<std::pair<int, size_t>> scored;
    scored.reserve(cachedResultList.size());
    for (size_t i = 0; i < cachedResultList.size(); ++i) {
        int s = ScoreResult(query, cachedResultList[i]);
        if (s > 0) scored.push_back({s, i});
    }

    // Sort descending by score
    std::stable_sort(scored.begin(), scored.end(), [](const auto& a, const auto& b) { return a.first > b.first; });

    // Build display list
    displayResultList.clear();
    displayResultList.reserve(scored.size());
    for (auto& [score, idx] : scored)
        displayResultList.push_back(cachedResultList[idx]);

    // Reset selection — position in list may have shifted
    selectedBrowserIndex = -1;
}

void SettingsUI::RenderWorkshopBrowserTab()
{
    if (!plugin_->workshopDownloader) {
        ImGui::TextDisabled("Workshop downloader not initialized");
        return;
    }

    ImGui::Spacing();

    static bool pathInit = false;
    if (!pathInit) {
        // Use the resolved workshop root (from workshopmaploader.cfg or platform defaults)
        std::string defaultPath;
        if (plugin_->mapManager) {
            auto resolved = plugin_->mapManager->ResolveConfiguredWorkshopRoot();
            if (!resolved.empty() && fs::exists(resolved)) defaultPath = resolved.string();
        }
        if (defaultPath.empty()) defaultPath = plugin_->gameWrapper->GetDataFolder().string() + "\\SuiteSpot\\Workshop";
        strncpy_s(workshopDownloadPathBuf, defaultPath.c_str(), sizeof(workshopDownloadPathBuf) - 1);
        pathInit = true;
    }

    // Download destination path
    ImGui::Text("Download to:");
    ImGui::SetNextItemWidth(400.0f);
    ImGui::InputText("##WorkshopPath", workshopDownloadPathBuf, IM_ARRAYSIZE(workshopDownloadPathBuf));

    ImGui::SameLine();
    RenderTextureCheck();

    ImGui::SameLine();
    bool autoDl = plugin_->settingsSync->IsAutoDownloadTextures();
    if (ImGui::Checkbox("Auto-Check on Launch", &autoDl)) {
        UI::Helpers::SetCVarSafely("suitespot_auto_download_textures", autoDl ? 1 : 0, plugin_->cvarManager,
                                   plugin_->gameWrapper);
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Automatically check for and download missing textures when the game starts.");
    }

    ImGui::Spacing();

    // API Search — fetches from RLMAPS
    ImGui::Text("Search Maps:");
    ImGui::SetNextItemWidth(400.0f);
    bool enterPressed = ImGui::InputText("##WorkshopSearch", workshopSearchBuf, IM_ARRAYSIZE(workshopSearchBuf),
                                         ImGuiInputTextFlags_EnterReturnsTrue);
    ImGui::SameLine();

    if ((ImGui::Button("Search") || enterPressed) && strlen(workshopSearchBuf) > 0) {
        // Reset local filter when doing a new API search
        memset(localFilterBuf, 0, sizeof(localFilterBuf));
        lastLocalFilter.clear();
        plugin_->workshopDownloader->GetResults(workshopSearchBuf, 1);
    }

    ImGui::SameLine();
    if (plugin_->workshopDownloader->RLMAPS_Searching) {
        if (ImGui::Button("Stop")) {
            plugin_->workshopDownloader->StopSearch();
        }
        ImGui::SameLine();
        ImGui::TextDisabled("Searching...");
    } else if (!cachedResultList.empty()) {
        ImGui::Text("%d / %d maps", (int)displayResultList.size(), (int)cachedResultList.size());
    }

    // Local filter — re-ranks already-loaded results in real time, no API call
    if (!cachedResultList.empty()) {
        ImGui::Spacing();
        ImGui::Text("Filter & Rank:");
        ImGui::SetNextItemWidth(400.0f);
        ImGui::InputText("##LocalFilter", localFilterBuf, IM_ARRAYSIZE(localFilterBuf));
        if (ImGui::IsItemHovered())
            ImGui::SetTooltip("Type to filter and rank results by relevance. Closer matches appear first.");
        if (strlen(localFilterBuf) > 0) {
            ImGui::SameLine();
            if (ImGui::Button("Clear")) {
                memset(localFilterBuf, 0, sizeof(localFilterBuf));
                lastLocalFilter.clear();
            }
        }
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    // Download progress bar
    if (plugin_->workshopDownloader->RLMAPS_IsDownloadingWorkshop) {
        float downloaded = static_cast<float>(plugin_->workshopDownloader->RLMAPS_WorkshopDownload_Progress.load());
        float fileSize = static_cast<float>(plugin_->workshopDownloader->RLMAPS_WorkshopDownload_FileSize.load());
        float fraction = (fileSize > 0) ? (downloaded / fileSize) : 0.0f;

        char label[64];
        snprintf(label, sizeof(label), "%.1f / %.1f MB", downloaded / 1048576.0f, fileSize / 1048576.0f);
        ImGui::ProgressBar(fraction, ImVec2(-1, 20), label);

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();
    }

    // Search results
    RLMAPS_RenderSearchWorkshopResults(workshopDownloadPathBuf);

    // Popups - donor pattern: thread sets flag, render loop opens popup
    if (plugin_->workshopDownloader->UserIsChoosingYESorNO) {
        ImGui::OpenPopup("Download?");
    }
    RenderAcceptDownload();
    RenderInfoPopup("Downloading?",
                    "A download is already running!\\nYou cannot download 2 workshops at the same time.");
    RenderInfoPopup("Exists?", "This directory is not valid!");

    if (plugin_->workshopDownloader->FolderErrorBool) {
        RenderInfoPopup("FolderError", plugin_->workshopDownloader->FolderErrorText.c_str());
    }
}

void SettingsUI::RLMAPS_RenderSearchWorkshopResults(const char* mapspath)
{
    if (!plugin_->workshopDownloader) return;

    // Check if API list has changed
    int currentVersion = plugin_->workshopDownloader->listVersion.load();
    if (currentVersion != lastListVersion) {
        std::lock_guard<std::mutex> lock(plugin_->workshopDownloader->resultsMutex);
        auto& fullList = plugin_->workshopDownloader->RLMAPS_MapResultList;
        cachedResultList.clear();
        for (auto& result : fullList) {
            // Filter out maps that already exist in the download directory
            std::string safeName = plugin_->workshopDownloader->SanitizeMapName(result.Name);
            std::string mapDir = std::string(mapspath);
            if (!mapDir.empty() && (mapDir.back() != '/' && mapDir.back() != '\\')) mapDir += "/";
            mapDir += safeName;
            if (!fs::exists(mapDir)) {
                cachedResultList.push_back(result);
            }
        }
        LOG("UI Synced list. New version: {}, items: {} (filtered from {})", currentVersion, cachedResultList.size(),
            fullList.size());
        lastListVersion = currentVersion;
        RebuildDisplayList(); // Score and sort the freshly-built cache
    }

    // Re-rank if user changed the local filter text
    std::string currentFilter = localFilterBuf;
    if (currentFilter != lastLocalFilter) {
        lastLocalFilter = currentFilter;
        RebuildDisplayList();
    }

    if (displayResultList.empty()) return;

    // Clamp selection
    if (selectedBrowserIndex >= (int)displayResultList.size()) selectedBrowserIndex = (int)displayResultList.size() - 1;

    // Two-panel layout matching Installed Maps design
    float availWidth = ImGui::GetContentRegionAvail().x;
    float leftWidth = std::max(UI::WorkshopBrowserUI::LEFT_PANEL_MIN_WIDTH,
                               availWidth * UI::WorkshopBrowserUI::LEFT_PANEL_WIDTH_PERCENT);
    float rightWidth = availWidth - leftWidth - ImGui::GetStyle().ItemSpacing.x;

    ImGui::BeginGroup();

    // === LEFT PANEL: Map List ===
    if (ImGui::BeginChild("##BrowserMapList", ImVec2(leftWidth, UI::WorkshopBrowserUI::BROWSER_HEIGHT), true)) {
        ImGui::TextDisabled("%d maps", (int)displayResultList.size());
        ImGui::Separator();

        for (int i = 0; i < (int)displayResultList.size(); i++) {
            auto& mapResult = displayResultList[i];
            bool isSelected = (i == selectedBrowserIndex);
            bool hasReleases = !mapResult.releases.empty();

            ImGui::PushID(i);

            // Show loading indicator for maps still fetching releases
            if (!hasReleases) {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));
            }

            if (ImGui::Selectable(mapResult.Name.c_str(), isSelected)) {
                selectedBrowserIndex = i;
            }

            if (!hasReleases) {
                ImGui::PopStyleColor();
            }

            ImGui::PopID();
        }
    }
    ImGui::EndChild();

    ImGui::SameLine();

    // === RIGHT PANEL: Details + Download ===
    if (ImGui::BeginChild("##BrowserMapDetails", ImVec2(rightWidth, UI::WorkshopBrowserUI::BROWSER_HEIGHT), true)) {
        if (selectedBrowserIndex >= 0 && selectedBrowserIndex < (int)displayResultList.size()) {
            auto& mapResult = displayResultList[selectedBrowserIndex];

            // Preview image
            std::shared_ptr<ImageWrapper> image = nullptr;
            if (!mapResult.ID.empty()) {
                auto it = workshopImageCache.find(mapResult.ID);
                if (it != workshopImageCache.end()) {
                    image = it->second;
                } else if (!mapResult.ImagePath.empty() && mapResult.isImageLoaded) {
                    try {
                        image = std::make_shared<ImageWrapper>(mapResult.ImagePath.string(), false, true);
                        if (workshopImageCache.size() >= 150) workshopImageCache.erase(workshopImageCache.begin());
                        workshopImageCache[mapResult.ID] = image;
                    } catch (...) {}
                }
            }

            // Preview image — fills available panel width at 16:9
            {
                float previewW = ImGui::GetContentRegionAvail().x;
                float previewH = previewW * (9.0f / 16.0f);
                if (image && image->GetImGuiTex()) {
                    ImVec2 p = ImGui::GetCursorScreenPos();
                    ImGui::GetWindowDrawList()->AddImageRounded(
                        image->GetImGuiTex(),
                        p, ImVec2(p.x + previewW, p.y + previewH),
                        ImVec2(0, 0), ImVec2(1, 1), IM_COL32_WHITE, 6.0f);
                    ImGui::Dummy(ImVec2(previewW, previewH));
                } else {
                    ImVec2 p = ImGui::GetCursorScreenPos();
                    ImDrawList* dl = ImGui::GetWindowDrawList();
                    dl->AddRectFilled(p,
                                      ImVec2(p.x + previewW, p.y + previewH),
                                      ImColor(40, 40, 45, 255), 6.0f);
                    dl->AddText(ImVec2(p.x + previewW / 2 - 40,
                                       p.y + previewH / 2 - 8),
                                ImColor(100, 100, 100, 255), "No Preview");
                    ImGui::Dummy(ImVec2(previewW, previewH));
                }
            }

            ImGui::Spacing();

            // Map name
            ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::MAP_NAME_COLOR);
            ImGui::TextWrapped("%s", mapResult.Name.c_str());
            ImGui::PopStyleColor();

            // Author
            if (!mapResult.Author.empty()) {
                ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::AUTHOR_COLOR);
                ImGui::Text("By: %s", mapResult.Author.c_str());
                ImGui::PopStyleColor();
            }

            ImGui::Spacing();

            // Description
            if (!mapResult.Description.empty()) {
                ImGui::PushStyleColor(ImGuiCol_Text, UI::WorkshopBrowserUI::DESCRIPTION_COLOR);
                ImGui::PushTextWrapPos(ImGui::GetContentRegionAvail().x);
                ImGui::TextWrapped("%s", mapResult.Description.c_str());
                ImGui::PopTextWrapPos();
                ImGui::PopStyleColor();
            }

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            // Download button
            bool hasReleases = !mapResult.releases.empty();
            if (hasReleases) {
                if (ImGui::Button("Download", ImVec2(180, 26))) {
                    if (!plugin_->workshopDownloader->RLMAPS_IsDownloadingWorkshop && fs::exists(mapspath)) {
                        ImGui::OpenPopup("Releases");
                    } else if (!fs::exists(mapspath)) {
                        ImGui::OpenPopup("Exists?");
                    } else {
                        ImGui::OpenPopup("Downloading?");
                    }
                }
                if (ImGui::IsItemHovered()) {
                    ImGui::SetTooltip("Download this map to your workshop folder");
                }
                RenderReleases(mapResult, mapspath);
            } else {
                ImGui::TextDisabled("Loading releases...");
            }
        } else {
            ImGui::TextDisabled("Select a map from the list");
        }
    }
    ImGui::EndChild();

    ImGui::EndGroup();
}

void SettingsUI::RenderReleases(RLMAPS_MapResult mapResult, const char* mapspath)
{
    if (ImGui::BeginPopupModal("Releases", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        for (int releasesIndex = 0; releasesIndex < mapResult.releases.size(); releasesIndex++) {
            RLMAPS_Release release = mapResult.releases[releasesIndex];

            if (ImGui::Button(release.tag_name.c_str(), ImVec2(182, 20))) {
                if (!plugin_->workshopDownloader->RLMAPS_IsDownloadingWorkshop && fs::exists(mapspath)) {
                    // Donor pattern: spawn thread immediately, it will spin-wait for confirmation
                    auto downloader = plugin_->workshopDownloader;
                    std::string path = std::string(mapspath);
                    std::thread t2([downloader, path, mapResult, release]() {
                        downloader->RLMAPS_DownloadWorkshop(path, mapResult, release);
                    });
                    t2.detach();
                    ImGui::CloseCurrentPopup();
                }
            }
        }

        if (ImGui::Button("Cancel", ImVec2(182, 20))) {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }
}

void SettingsUI::RenderAcceptDownload()
{
    if (!plugin_->workshopDownloader) return;

    RenderYesNoPopup(
        "Download?", "Do you really want to download?\nYou'll not be able to cancel if you start it.",
        [this]() {
            // User confirmed - signal the waiting thread
            plugin_->workshopDownloader->AcceptTheDownload = true;
            plugin_->workshopDownloader->UserIsChoosingYESorNO = false;
            ImGui::CloseCurrentPopup();
        },
        [this]() {
            // User cancelled - signal the waiting thread
            plugin_->workshopDownloader->AcceptTheDownload = false;
            plugin_->workshopDownloader->UserIsChoosingYESorNO = false;
            ImGui::CloseCurrentPopup();
        });
}

void SettingsUI::RenderYesNoPopup(const char* popupName, const char* label, std::function<void()> yesFunc,
                                  std::function<void()> noFunc)
{
    if (ImGui::BeginPopupModal(popupName, NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("%s", label);
        ImGui::NewLine();

        CenterNextItem(208.0f);
        ImGui::BeginGroup();
        {
            if (ImGui::Button("YES", ImVec2(100.0f, 25.0f))) {
                try {
                    yesFunc();
                } catch (const std::exception& ex) {
                    LOG("Popup error: {}", ex.what());
                }
            }
            ImGui::SameLine();
            if (ImGui::Button("NO", ImVec2(100.0f, 25.0f))) {
                noFunc();
            }
            ImGui::EndGroup();
        }

        ImGui::EndPopup();
    }
}

void SettingsUI::RenderInfoPopup(const char* popupName, const char* label)
{
    if (ImGui::BeginPopupModal(popupName, NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("%s", label);
        ImGui::NewLine();
        CenterNextItem(100.0f);
        if (ImGui::Button("OK", ImVec2(100.0f, 25.0f))) {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

void SettingsUI::CenterNextItem(float itemWidth)
{
    auto windowWidth = ImGui::GetWindowSize().x;
    ImGui::SetCursorPosX((windowWidth - itemWidth) * 0.5f);
}

std::string SettingsUI::LimitTextSize(std::string str, float maxTextSize)
{
    while (ImGui::CalcTextSize(str.c_str()).x > maxTextSize) {
        if (str.empty()) break;
        str = str.substr(0, str.size() - 1);
    }
    return str;
}
void SettingsUI::RenderTextureCheck()
{
    if (!plugin_->textureDownloader) return;

    if (ImGui::Button("Check Textures")) {
        showTexturePopup = true;
        ImGui::OpenPopup("DownloadTextures");
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("Check for missing workshop textures and install them");
    }

    if (showTexturePopup) {
        std::vector<std::string> missing = plugin_->textureDownloader->CheckMissingTextures();
        RenderDownloadTexturesPopup(missing);
    }
}

void SettingsUI::RenderDownloadTexturesPopup(const std::vector<std::string>& missingFiles)
{
    if (ImGui::BeginPopupModal("DownloadTextures", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        if (!missingFiles.empty()) {
            ImGui::Text("It seems like the workshop textures aren't installed.");
            ImGui::Text("You can still play without them but some maps will have white/weird textures.");

            if (plugin_->textureDownloader->isDownloading) {
                ImGui::Separator();
                ImGui::Text("Downloading... %d%%", plugin_->textureDownloader->downloadProgress.load());
                ImGui::ProgressBar(plugin_->textureDownloader->downloadProgress.load() / 100.0f, ImVec2(300, 20));
                ImGui::Separator();
            }

            ImGui::NewLine();

            if (ImGui::BeginChild("##MissingFiles", ImVec2(300, 150), true)) {
                ImGui::Text("Missing Files (%d):", (int)missingFiles.size());
                ImGui::Separator();
                for (const auto& file : missingFiles) {
                    ImGui::Text("%s", file.c_str());
                }
                ImGui::EndChild();
            }

            ImGui::NewLine();

            if (ImGui::Button("Download & Install", ImVec2(140, 25)) && !plugin_->textureDownloader->isDownloading) {
                plugin_->textureDownloader->DownloadAndInstallTextures();
            }

            ImGui::SameLine();

            if (ImGui::Button("Close", ImVec2(100, 25))) {
                showTexturePopup = false;
                ImGui::CloseCurrentPopup();
            }
        } else {
            ImGui::Text("Workshop textures are installed!");
            ImGui::NewLine();
            if (ImGui::Button("OK", ImVec2(100, 25))) {
                showTexturePopup = false;
                ImGui::CloseCurrentPopup();
            }
        }
        ImGui::EndPopup();
    }
}

// =============================================================================
// F6 FOR DUMMIES — CVar Browser
// =============================================================================

void SettingsUI::LoadF6Cvars(const std::string& configPath, const std::string& descPath)
{
    f6Cvars = ConfigParser::Parse(configPath);
    DescriptionsLoader::Enrich(f6Cvars, descPath);
}

void SettingsUI::ExecuteCvar(ParsedCvar& cvar)
{
    std::string command = cvar.name + " " + cvar.currentValue;
    plugin_->cvarManager->executeCommand(command, false);

    // Re-read config.cfg to sync live values
    auto configPath = plugin_->mapManager->GetDataRoot().parent_path() / "cfg" / "config.cfg";
    auto descPath   = plugin_->mapManager->GetSuiteSpotRoot() / "cvars_descriptions.json";
    f6Cvars = ConfigParser::Parse(configPath.string());
    DescriptionsLoader::Enrich(f6Cvars, descPath.string());

    f6StatusMsg      = "\xe2\x9c\x93  " + command;   // ✓ UTF-8
    f6StatusIsError  = false;
    f6StatusTimer    = 3.f;
}

void SettingsUI::RenderCvarRow(ParsedCvar& cvar, int rowIndex)
{
    using namespace UI::SettingsUI;
    float contentWidth = ImGui::GetContentRegionAvail().x;
    float descWidth = contentWidth - F6_PAD_OUTER - F6_NAME_W - F6_PAD_COL
                    - F6_INPUT_W - F6_PAD_COL - F6_BTN_W - F6_PAD_OUTER;
    if (descWidth < 60.f) descWidth = 60.f;

    float nameX  = F6_PAD_OUTER;
    float descX  = nameX  + F6_NAME_W + F6_PAD_COL;
    float inputX = descX  + descWidth  + F6_PAD_COL;
    float btnX   = inputX + F6_INPUT_W + F6_PAD_COL;

    float rowStartY = ImGui::GetCursorPosY();

    // ---- alternating row background ----
    // Drawn after afterDescY is known (see lines below near ---- Advance cursor ----)

    // ---- Name column ----
    ImGui::SetCursorPos(ImVec2(nameX, rowStartY + F6_PAD_ROW));
    if (cvar.uncertain) {
        ImGui::TextUnformatted(cvar.name.c_str());
        ImGui::SameLine(0, 2);
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(180, 140, 60, 200));
        ImGui::TextUnformatted(" (?)");
        ImGui::PopStyleColor();
    } else {
        ImGui::TextUnformatted(cvar.name.c_str());
    }
    if (ImGui::IsItemHovered()) {
        std::string tip = cvar.uncertain
            ? "Description may be approximate.\n\n" + cvar.rawComment
            : (cvar.rawComment.empty() ? cvar.name : cvar.rawComment);
        ImGui::SetTooltip("%s", tip.c_str());
    }

    // ---- Description column (drives row height) ----
    ImGui::SetCursorPos(ImVec2(descX, rowStartY + F6_PAD_ROW));
    ImGui::PushTextWrapPos(descX + descWidth);
    std::string desc = cvar.friendlyDescription.empty() ? cvar.rawComment : cvar.friendlyDescription;
    ImGui::TextWrapped("%s", desc.c_str());
    ImGui::PopTextWrapPos();
    float afterDescY = ImGui::GetCursorPosY(); // actual bottom of wrapped text

    // ---- Input column ----
    ImGui::SetCursorPos(ImVec2(inputX, rowStartY + F6_PAD_ROW));

    std::string inputId = "##val_" + cvar.name;
    char buf[512];
    std::strncpy(buf, cvar.currentValue.c_str(), sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    if (cvar.type == CvarType::Range) {
        float halfW = (F6_INPUT_W - 4.f) * 0.5f;
        ImGui::PushItemWidth(halfW);
        ImGui::InputFloat(("##rmin_" + cvar.name).c_str(), &cvar.rangeMin, 0.f, 0.f, "%.2f");
        ImGui::SameLine(0, 4);
        ImGui::InputFloat(("##rmax_" + cvar.name).c_str(), &cvar.rangeMax, 0.f, 0.f, "%.2f");
        ImGui::PopItemWidth();
        // Update currentValue string from floats
        char rangeBuf[64];
        std::snprintf(rangeBuf, sizeof(rangeBuf), "(%.2f, %.2f)", cvar.rangeMin, cvar.rangeMax);
        cvar.currentValue = rangeBuf;
    } else if (cvar.type == CvarType::Color) {
        float col[4] = { cvar.colorR / 255.f, cvar.colorG / 255.f,
                         cvar.colorB / 255.f, cvar.colorA / 255.f };
        ImGui::PushItemWidth(F6_INPUT_W);
        if (ImGui::ColorEdit4(("##col_" + cvar.name).c_str(), col)) {
            cvar.colorR = col[0] * 255.f;
            cvar.colorG = col[1] * 255.f;
            cvar.colorB = col[2] * 255.f;
            cvar.colorA = col[3] * 255.f;
            char colBuf[64];
            std::snprintf(colBuf, sizeof(colBuf), "(%.0f, %.0f, %.0f, %.0f)",
                cvar.colorR, cvar.colorG, cvar.colorB, cvar.colorA);
            cvar.currentValue = colBuf;
        }
        ImGui::PopItemWidth();
    } else {
        const char* hint = "";
        if      (cvar.type == CvarType::Boolean) hint = "0 or 1";
        else if (cvar.type == CvarType::Number)  hint = "whole number";
        else if (cvar.type == CvarType::Decimal) hint = "e.g. 0.5";
        else                                     hint = "text";

        ImGui::PushItemWidth(F6_INPUT_W);
        if (ImGui::InputTextWithHint(inputId.c_str(), hint, buf, sizeof(buf)))
            cvar.currentValue = buf;
        ImGui::PopItemWidth();

        if (ImGui::IsItemHovered() && !cvar.default_val.empty())
            ImGui::SetTooltip("Default: %s", cvar.default_val.c_str());
    }

    // ---- Execute button ----
    ImGui::SetCursorPos(ImVec2(btnX, rowStartY + F6_PAD_ROW));
    if (ImGui::SmallButton(("\xe2\x96\xb6##" + cvar.name).c_str()))  // ▶ UTF-8
        ExecuteCvar(cvar);
    if (ImGui::IsItemHovered()) ImGui::SetTooltip("Execute: %s %s", cvar.name.c_str(), cvar.currentValue.c_str());

    // ---- Copy button ----
    float copyBtnX = btnX + F6_BTN_W + 2.f;
    ImGui::SetCursorPos(ImVec2(copyBtnX, rowStartY + F6_PAD_ROW));
    if (ImGui::SmallButton(("\xe2\x8e\x98##cp_" + cvar.name).c_str()))  // ⎘ UTF-8
        ImGui::SetClipboardText((cvar.name + " " + cvar.currentValue).c_str());
    if (ImGui::IsItemHovered()) ImGui::SetTooltip("Copy command to clipboard");

    // ---- Alternating row background (drawn behind content) ----
    if (rowIndex % 2 != 0) {
        float rowEndY = afterDescY + F6_PAD_ROW;
        ImVec2 winPos = ImGui::GetWindowPos();
        float scrollX = ImGui::GetScrollX();
        float scrollY = ImGui::GetScrollY();
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImVec2(winPos.x - scrollX, winPos.y + rowStartY - scrollY),
            ImVec2(winPos.x - scrollX + contentWidth, winPos.y + rowEndY - scrollY),
            IM_COL32(255, 255, 255, 8)
        );
    }

    // ---- Advance cursor past row ----
    ImGui::SetCursorPosY(afterDescY + F6_PAD_ROW);
    ImGui::Separator();
}

void SettingsUI::RenderF6ForDummiesTab()
{
    using namespace UI::SettingsUI;

    // Tick down status timer
    if (f6StatusTimer > 0.f) {
        f6StatusTimer -= ImGui::GetIO().DeltaTime;
        if (f6StatusTimer <= 0.f) {
            f6StatusTimer = 0.f;
            f6StatusMsg.clear();
        }
    }

    float contentWidth = ImGui::GetContentRegionAvail().x;

    // ---- Top padding ----
    ImGui::Dummy(ImVec2(0, F6_PAD_TOP));

    // ---- Search bar ----
    float searchWidth = contentWidth - F6_PAD_OUTER * 2.f - 30.f - 160.f; // leave room for × and checkbox
    ImGui::SetCursorPosX(F6_PAD_OUTER);
    ImGui::PushItemWidth(searchWidth);
    ImGui::InputTextWithHint("##f6search", "Search CVars...", f6SearchBuf, sizeof(f6SearchBuf));
    ImGui::PopItemWidth();

    ImGui::SameLine(0, 6);
    if (ImGui::SmallButton("[x]")) {
        std::memset(f6SearchBuf, 0, sizeof(f6SearchBuf));
    }
    if (ImGui::IsItemHovered()) ImGui::SetTooltip("Clear search");

    ImGui::SameLine(0, 10);
    ImGui::Checkbox("Uncertain only (?)", &f6ShowUncertainOnly);

    // ---- Result count ----
    std::string searchLower(f6SearchBuf);
    std::transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);

    int visibleCount = 0;
    for (auto& c : f6Cvars) {
        if (f6ShowUncertainOnly && !c.uncertain) continue;
        if (!searchLower.empty()) {
            std::string nameLower = c.name;
            std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            std::string descLower = c.friendlyDescription;
            std::transform(descLower.begin(), descLower.end(), descLower.begin(), ::tolower);
            if (nameLower.find(searchLower) == std::string::npos &&
                descLower.find(searchLower) == std::string::npos) continue;
        }
        visibleCount++;
    }

    ImGui::SetCursorPosX(F6_PAD_OUTER);
    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(150, 150, 150, 200));
    ImGui::Text("Showing %d of %d CVars", visibleCount, (int)f6Cvars.size());
    ImGui::PopStyleColor();

    // ---- Status / feedback bar ----
    if (!f6StatusMsg.empty() && f6StatusTimer > 0.f) {
        float alpha = (f6StatusTimer / 3.f);
        if (alpha > 1.f) alpha = 1.f;
        ImGui::SetCursorPosX(F6_PAD_OUTER);
        if (f6StatusIsError)
            ImGui::TextColored(ImVec4(1.f, 0.3f, 0.3f, alpha), "%s", f6StatusMsg.c_str());
        else
            ImGui::TextColored(ImVec4(0.2f, 1.f, 0.2f, alpha), "%s", f6StatusMsg.c_str());
    } else {
        ImGui::Dummy(ImVec2(0, ImGui::GetTextLineHeight()));
    }

    // ---- Scrollable list ----
    ImGui::BeginChild("##f6list", ImVec2(0, 0), false);

    int rowIndex = 0;
    bool anyVisible = false;
    for (auto& cvar : f6Cvars) {
        if (f6ShowUncertainOnly && !cvar.uncertain) continue;
        if (!searchLower.empty()) {
            std::string nameLower = cvar.name;
            std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            std::string descLower = cvar.friendlyDescription;
            std::transform(descLower.begin(), descLower.end(), descLower.begin(), ::tolower);
            if (nameLower.find(searchLower) == std::string::npos &&
                descLower.find(searchLower) == std::string::npos) continue;
        }
        anyVisible = true;
        RenderCvarRow(cvar, rowIndex++);
    }

    if (!anyVisible) {
        ImGui::SetCursorPosX(F6_PAD_OUTER);
        ImGui::TextDisabled("No CVars match \"%s\"", f6SearchBuf);
    }

    ImGui::EndChild();
    ImGui::Dummy(ImVec2(0, F6_PAD_BOTTOM));
}