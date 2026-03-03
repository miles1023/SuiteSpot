# Core Plugin — RocketStats.h / .cpp / Languages

_Source: RocketStats BakkesMod plugin — extracted via repomix_

## File: RocketStats.cpp
```cpp
/* ===========================================================
 *   Developped by @Lyliya, @NuSa_yt, @Arubinu42 & @Larsluph
 * =========================================================== */

#define _WINSOCKAPI_ // stops windows.h including winsock.h
#define _WEBSOCKETPP_CPP11_TYPE_TRAITS_

#include "RocketStats.h"

BAKKESMOD_PLUGIN(RocketStats, "RocketStats", "4.2.1", PERMISSION_ALL)

#pragma region Utils
Stats RocketStats::GetStats()
{
    Stats result;

    switch (rs_mode)
    {
        case 1: result = stats[current.playlist]; break;
        case 2: result = always; break;
        case 3: result = always_gm[current.playlist]; break;
        default: result = session;
    }

    return result;
}

std::string RocketStats::GetRank(int tierID)
{
    cvarManager->log("Tier: " + std::to_string(tierID));
    if (tierID < rank_nb)
        return rank[tierID].name;
    else
        return "Unranked";
}

std::string RocketStats::GetRankName(int tierID, int& number)
{
    std::string tmp = GetRank(tierID);
    std::vector<std::string> num = {};

    Utils::ReplaceAll(tmp, "_", " ");
    num = Utils::Split(tmp, ' ');

    if (num.back().size())
    {
        auto it = std::find(roman_numbers.begin(), roman_numbers.end(), num.back());
        if (it != roman_numbers.end())
        {
            num.pop_back();
            number = int(it - roman_numbers.begin());

            tmp = "";
            for (int i = 0; i < num.size(); ++i)
                tmp += (i ? " " : "") + num.at(i);
        }
    }

    return tmp;
}

std::string RocketStats::GetPlaylistName(int playlistID)
{
    if (playlist_name.find(playlistID) != playlist_name.end())
        return playlist_name.at(playlistID);
    else
        return "Unknown Game Mode (" + std::to_string(playlistID) + ")";
}

std::string RocketStats::GetRoman(int number)
{
    return ((number >= 0 && number < roman_numbers.size()) ? roman_numbers.at(number) : "");
}

std::string RocketStats::AddRoman(std::string str, int number)
{
    std::string tmp;
    if (rs_roman_numbers && number >= 0 && number < roman_numbers.size())
        tmp = roman_numbers.at(number);
    else
        tmp = std::to_string(number);

    Utils::ReplaceAll(str, "{{Number}}", tmp);
    return str;
}

void RocketStats::LogImageLoadStatus(bool status, std::string imageName)
{
    if (status)
        cvarManager->log(imageName + ": image load");
    else
        cvarManager->log(imageName + ": failed to load");
}

std::shared_ptr<ImageWrapper> RocketStats::LoadImg(const std::string& _filename)
{
    fs::path _path = GetPath(_filename);
    return LoadImg(_path);
}

std::shared_ptr<ImageWrapper> RocketStats::LoadImg(fs::path& _path)
{
    return std::make_shared<ImageWrapper>(_path, false, true);
}

void RocketStats::LoadImgs()
{
    int load_check = 0;

    casual = LoadImg("RocketStats_images/Casual.tga");
    load_check += (int)casual->IsLoadedForImGui();
    if (!load_check)
        cvarManager->log("Casual: failed to load");

    for (int i = 0; i < rank_nb; ++i)
    {
        rank[i].image = LoadImg("RocketStats_images/" + rank[i].name + ".tga");
        load_check += (int)rank[i].image->IsLoadedForImGui();
        LogImageLoadStatus(rank[i].image->IsLoadedForImGui(), rank[i].name);
    }
    cvarManager->log(std::to_string(load_check) + "/" + std::to_string(rank_nb + 1) + " images were loaded successfully");
}

bool RocketStats::GetCVar(const char* name, int& value)
{
    std::string key = (name + 3);
    if (themes_values[theme_render.name].is_object() && (themes_values[theme_render.name][key].is_number_integer() || themes_values[theme_render.name][key].is_number_unsigned()))
    {
        value = int(themes_values[theme_render.name][key]);
        cvarManager->log("GetCVar: " + std::string(name) + " " + std::to_string(value));

        return true;
    }

    return false;
}

bool RocketStats::GetCVar(const char* name, bool& value)
{
    std::string key = (name + 3);
    if (themes_values[theme_render.name].is_object() && themes_values[theme_render.name][key].is_boolean())
    {
        value = bool(themes_values[theme_render.name][key]);
        cvarManager->log("GetCVar: " + std::string(name) + " " + std::to_string(value));

        return true;
    }

    return false;
}

bool RocketStats::GetCVar(const char* name, float& value)
{
    std::string key = (name + 3);
    if (themes_values[theme_render.name].is_object() && themes_values[theme_render.name][key].is_number())
    {
        value = float(themes_values[theme_render.name][key]);
        cvarManager->log("GetCVar: " + std::string(name) + " " + std::to_string(value));

        return true;
    }

    return false;
}

bool RocketStats::SetCVar(const char* name, int& value, bool save)
{
    std::string key = (name + 3);
    CVarWrapper cvar = cvarManager->getCvar(name);

    if (!cvar.IsNull() && value != cvar.getIntValue())
    {
        cvarManager->log("SetCVar: " + std::string(name) + " " + std::to_string(value));
        cvarManager->getCvar(name).setValue(value);

        if (save)
        {
            if (!themes_values[theme_render.name].is_object())
                themes_values[theme_render.name] = json::object();

            themes_values[theme_render.name][key] = value;
        }

        return true;
    }

    return false;
}

bool RocketStats::SetCVar(const char* name, bool& value, bool save)
{
    std::string key = (name + 3);
    CVarWrapper cvar = cvarManager->getCvar(name);

    if (!cvar.IsNull() && value != cvar.getBoolValue())
    {
        cvarManager->log("SetCVar: " + std::string(name) + " " + std::to_string(value));
        cvar.setValue(value);

        if (save)
        {
            if (!themes_values[theme_render.name].is_object())
                themes_values[theme_render.name] = json::object();

            themes_values[theme_render.name][key] = value;
        }

        return true;
    }

    return false;
}

bool RocketStats::SetCVar(const char* name, float& value, bool save)
{
    std::string key = (name + 3);
    value = (std::round(value * 1000.f) / 1000.f);
    CVarWrapper cvar = cvarManager->getCvar(name);

    if (!cvar.IsNull() && value != cvar.getFloatValue())
    {
        cvarManager->log("SetCVar: " + std::string(name) + " " + std::to_string(value));
        cvar.setValue(value);

        if (save)
        {
            if (!themes_values[theme_render.name].is_object())
                themes_values[theme_render.name] = json::object();

            themes_values[theme_render.name][key] = value;
        }

        return true;
    }

    return false;
}

void RocketStats::CloseWelcome()
{
    if (rs_recovery == RecoveryFlags_Welcome)
    {
        cvarManager->log("CloseWelcome");

        rs_recovery = RecoveryFlags_Process;
        RemoveFile("RocketStats_images/welcome.tga");

        gameWrapper->SetTimeout([&](GameWrapper* gameWrapper) {
            cvarManager->executeCommand("exec config");

            gameWrapper->SetTimeout([&](GameWrapper* gameWrapper) {
                rs_launch = 0.f;
                rs_recovery = (RecoveryOldVars() ? RecoveryFlags_Finish : RecoveryFlags_Off);
                SetRefresh(RefreshFlags_RefreshAndImages);
            }, 1.0f);
        }, 0.2f);
    }
}

bool RocketStats::RecoveryOldVars()
{
    cvarManager->log("Recovery old vars !");

    CVarWrapper ors_session = cvarManager->getCvar("RS_session");
    if (!ors_session.IsNull())
        rs_mode = ors_session.getBoolValue();

    CVarWrapper ors_Use_v1 = cvarManager->getCvar("RS_Use_v1");
    CVarWrapper ors_Use_v2 = cvarManager->getCvar("RS_Use_v2");
    if (!ors_Use_v1.IsNull() && !ors_Use_v2.IsNull())
        SetTheme(ors_Use_v1.getBoolValue() ? "Default" : (ors_Use_v2.getBoolValue() ? "Redesigned" : "Arubinu42"));

    CVarWrapper ors_x_position = cvarManager->getCvar("RS_x_position");
    if (!ors_x_position.IsNull())
        rs_x = ors_x_position.getFloatValue();

    CVarWrapper ors_y_position = cvarManager->getCvar("RS_y_position");
    if (!ors_y_position.IsNull())
        rs_y = ors_y_position.getFloatValue();

    CVarWrapper ors_scale = cvarManager->getCvar("RS_scale");
    if (!ors_scale.IsNull())
        rs_scale = ors_scale.getFloatValue();

    CVarWrapper ors_disp_ig = cvarManager->getCvar("RS_disp_ig");
    if (!ors_disp_ig.IsNull())
        rs_disp_overlay = ors_disp_ig.getBoolValue();

    CVarWrapper ors_enable_float = cvarManager->getCvar("RS_enable_float");
    if (!ors_enable_float.IsNull())
        rs_enable_float = ors_enable_float.getBoolValue();

    CVarWrapper ors_hide_overlay_ig = cvarManager->getCvar("RS_hide_overlay_ig");
    if (!ors_hide_overlay_ig.IsNull())
        rs_enable_ingame = !ors_hide_overlay_ig.getBoolValue();

    CVarWrapper ors_disp_gamemode = cvarManager->getCvar("RS_disp_gamemode");
    if (!ors_disp_gamemode.IsNull())
        rs_hide_gm = !ors_disp_gamemode.getBoolValue();

    CVarWrapper ors_disp_rank = cvarManager->getCvar("RS_disp_rank");
    if (!ors_disp_rank.IsNull())
        rs_hide_rank = !ors_disp_rank.getBoolValue();

    CVarWrapper ors_disp_mmr = cvarManager->getCvar("RS_disp_mmr");
    if (!ors_disp_mmr.IsNull())
        rs_hide_mmr = !ors_disp_mmr.getBoolValue();

    CVarWrapper ors_disp_wins = cvarManager->getCvar("RS_disp_wins");
    if (!ors_disp_wins.IsNull())
        rs_hide_win = !ors_disp_wins.getBoolValue();

    CVarWrapper ors_disp_losses = cvarManager->getCvar("RS_disp_losses");
    if (!ors_disp_losses.IsNull())
        rs_hide_loss = !ors_disp_losses.getBoolValue();

    CVarWrapper ors_disp_streak = cvarManager->getCvar("RS_disp_streak");
    if (!ors_disp_streak.IsNull())
        rs_hide_streak = !ors_disp_streak.getBoolValue();

    CVarWrapper ors_stop_boost = cvarManager->getCvar("RocketStats_stop_boost");
    if (!ors_stop_boost.IsNull())
        rs_file_boost = ors_stop_boost.getBoolValue();

    ChangeTheme(rs_theme);
    WriteConfig();

    return !ors_session.IsNull();
}
#pragma endregion

void RocketStats::onLoad()
{
    // notifierToken = gameWrapper->GetMMRWrapper().RegisterMMRNotifier(std::bind(&RocketStats::UpdateMMR, this, std::placeholders::_1));

    // Retrieves the plugin version to display it in the menu
    if (exports.pluginVersion != nullptr)
        menu_version = ("v" + std::string(exports.pluginVersion));

    // Loads the language into the array and initializes the list of modes
    cvarManager->log(("Language: " + gameWrapper->GetUILanguage().ToString()).c_str());
    ChangeLang((gameWrapper->GetUILanguage().ToString() == "FRA") ? IDB_LANG_FRA : IDB_LANG_INT);
    modes = {
        GetLang(LANG_MODE_SESSION),
        GetLang(LANG_MODE_GAMEMODE),
        GetLang(LANG_MODE_ALWAYS),
        GetLang(LANG_MODE_ALWAYS_GAMEMODE)
    };

    // Must be placed here, otherwise it is not generated in the menu
    cvarManager->registerCvar("rs_toggle_logo", "1", GetLang(LANG_TOGGLE_LOGO_HELP), true, true, 0, true, 1);

    // Define the "One Click" protocol
    SetCustomProtocol();

    // Force InMenu variable
    is_in_menu = (!gameWrapper->IsInGame() && !gameWrapper->IsInOnlineGame() && !gameWrapper->IsInFreeplay());

    gameWrapper->Execute([&](GameWrapper* gameWrapper) {
        // Here, thread WebSocket.run()
        // InitWebSocket();
        server_thread = std::thread(std::bind(&RocketStats::InitWebSocket, this));
        server_thread.detach();

        // Checks if the configuration file exists
        if (!ExistsPath("data/rocketstats.json", true))
        {
            if (ExistsPath("RocketStats", true))
            {
                rs_recovery = RecoveryFlags_Files;

                gameWrapper->SetTimeout([&](GameWrapper* gameWrapper) {
                    UpdateUIScale("onLoad");
                    ShowPlugin("onLoad");
                }, 1.f);
                return;
            }
        }

        onInit();

        UpdateUIScale("onLoad");
        ShowPlugin("onLoad");
    });
}

void RocketStats::onInit()
{
    // Load menu font
    GuiManagerWrapper gui = gameWrapper->GetGUIManager();
    gui.LoadFont("Ubuntu-Regular28", "Ubuntu-Regular.ttf", 28);

    // Loads important and rank images
    std::string logo_path = "RocketStats_images/logo.tga";
    std::string title_path = "RocketStats_images/title.tga";
    WriteResInFile(logo_path, IDB_LOGO, "TGA");
    WriteResInFile(title_path, IDB_TITLE, "TGA");
    rs_logo = LoadImg(logo_path);
    rs_title = LoadImg(title_path);
    LoadImgs();
    LoadThemes();

    // Initializes the different functionalities
    InitRank();
    InitStats();
    rs_recovery = (ReadConfig() ? RecoveryFlags_Off : RecoveryFlags_Welcome);
    ChangeTheme(rs_theme);

    // Reset all files (and create them if they don't exist)
    ResetFiles();

    // Can be used from the console or in bindings
    cvarManager->registerNotifier("rs_toggle_menu", [this](std::vector<std::string> params) {
        ToggleSettings("rs_toggle_menu");
    }, GetLang(LANG_TOGGLE_MENU), PERMISSION_ALL);

    cvarManager->registerNotifier("rs_reset_stats", [this](std::vector<std::string> params) {
        ResetStats();
    }, GetLang(LANG_RESET_STATS), PERMISSION_ALL);
    
    cvarManager->registerNotifier("rs_menu_pos", [this](std::vector<std::string> params) {
        ToggleSettings("rs_toggle_menu", ToggleFlags_Hide);

        gameWrapper->SetTimeout([&](GameWrapper* gameWrapper) {
            rs_menu_pos = true;
            ToggleSettings("rs_toggle_menu", ToggleFlags_Show);
        }, 0.2f);
    }, GetLang(LANG_RESET_MENU_POSITION), PERMISSION_ALL);

    // Hook on Event
    gameWrapper->HookEvent("Function TAGame.GFxData_StartMenu_TA.EventTitleScreenClicked", std::bind(&RocketStats::ShowPlugin, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function TAGame.GameViewportClient_TA.SetUIScaleModifier", std::bind(&RocketStats::UpdateUIScale, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function Engine.GameViewportClient.IsFullScreenViewport", std::bind(&RocketStats::UpdateUIScale, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function GameEvent_TA.Countdown.BeginState", std::bind([this](std::string event) {GameStart(event);InGameTheme();is_in_MainMenu = false;}, std::placeholders::_1));
    gameWrapper->HookEvent("Function TAGame.GameEvent_Soccar_TA.OnMatchWinnerSet", std::bind(&RocketStats::GameEnd, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function TAGame.GameEvent_TA.Destroyed", std::bind([this](std::string event) {GameDestroyed(event);}, std::placeholders::_1));
    gameWrapper->HookEvent("Function CarComponent_Boost_TA.Active.BeginState", std::bind(&RocketStats::OnBoostStart, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function TAGame.CarComponent_Boost_TA.EventBoostAmountChanged", std::bind(&RocketStats::OnBoostChanged, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function CarComponent_Boost_TA.Active.EndState", std::bind(&RocketStats::OnBoostEnd, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function TAGame.GameEvent_Soccar_TA.TriggerGoalScoreEvent", std::bind(&RocketStats::onGoalScore, this, std::placeholders::_1));
    gameWrapper->HookEvent("Function TAGame.GFxData_MainMenu_TA.OnEnteredMainMenu", std::bind([this]() { menu_stack = 0; is_in_menu = true; is_in_MainMenu = true; BacktoMenu();}));
    gameWrapper->HookEvent("Function TAGame.GFxData_MenuStack_TA.PushMenu", std::bind([this]() { ++menu_stack;  is_in_menu = true; }));
    gameWrapper->HookEvent("Function TAGame.GFxData_MenuStack_TA.PopMenu", std::bind([this]() { if (menu_stack) --menu_stack; is_in_menu = (menu_stack > 0); }));
    gameWrapper->HookEvent("Function TAGame.MenuSequence_TA.EnterSequence", std::bind([this]() { is_in_menu = true; }));
    gameWrapper->HookEvent("Function TAGame.MenuSequence_TA.LeaveSequence", std::bind([this]() { is_in_menu = false; }));
    gameWrapper->HookEvent("Function TAGame.GFxData_GameEvent_TA.OnOpenScoreboard", std::bind([this]() { is_in_scoreboard = true; }));
    gameWrapper->HookEvent("Function TAGame.GFxData_GameEvent_TA.OnCloseScoreboard", std::bind([this]() { is_in_scoreboard = false; }));

    gameWrapper->HookEventWithCallerPost<ServerWrapper>("Function TAGame.GFxHUD_TA.HandleStatEvent", std::bind(&RocketStats::onStatEvent, this, std::placeholders::_1, std::placeholders::_2));
    gameWrapper->HookEventWithCallerPost<ServerWrapper>("Function TAGame.GFxHUD_TA.HandleStatTickerMessage", std::bind(&RocketStats::onStatTickerMessage, this, std::placeholders::_1, std::placeholders::_2));

    // Register Cvars
    if (rs_recovery == RecoveryFlags_Welcome)
    {
        cvarManager->registerCvar("RS_Use_v1", "0", "Use the v1 overlay", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_Use_v2", "0", "Use the v2 overlay", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_ig", "1", "Display information panel", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_hide_overlay_ig", "0", "Hide overlay while in-game", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_mmr", "1", "Display the current MMR", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_wins", "1", "Display the wins on the current game mode", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_losses", "1", "Display the losses on the current game mode", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_streak", "1", "Display the streak on the current game mode", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_rank", "1", "Display the rank on the current game mode", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_disp_gamemode", "1", "Display the current game mode", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_enable_float", "0", "Enable floating point for MMR (OBS only)", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_x_position", "0.700", "Overlay X position", true, true, 0, true, 1.0f);
        cvarManager->registerCvar("RS_y_position", "0.575", "Overlay Y position", true, true, 0, true, 1.0f);
        cvarManager->registerCvar("RS_scale", "1", "Overlay scale", true, true, 0, true, 10);
        cvarManager->registerCvar("RocketStats_stop_boost", "1", "Stop Boost animation", true, true, 0, true, 1);
        cvarManager->registerCvar("RS_session", "0", "Display session information instead of game mode", true, true, 0, true, 1, true);
    }

    cvarManager->registerCvar("cl_rocketstats_settings", (settings_open ? "1" : "0"), GetLang(LANG_TOGGLE_MENU_HELP), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) {
        settings_open = now.getBoolValue();

        cvarManager->log("cl_rocketstats_settings: " + std::string(settings_open ? "true" : "false"));
        if (!settings_open)
            WriteConfig();
    });

    cvarManager->registerCvar("rs_mode", std::to_string(rs_mode), GetLang(LANG_MODE), true, true, 0, true, float(modes.size() - 1), false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_theme", std::to_string(rs_theme), GetLang(LANG_THEME), true, true, 0, false, 99, false).addOnValueChanged([this](std::string old, CVarWrapper now) {
        if (((!dualtheme && !is_in_MainMenu) || is_in_MainMenu) && !ChangeTheme(now.getIntValue())) {
            now.setValue(old);
        }
    });
    cvarManager->registerCvar("rs_gameTheme", std::to_string(rs_gameTheme), GetLang(LANG_MENU) + GetLang(LANG_THEME), true, true, 0, false, 99, false).addOnValueChanged([this](std::string old, CVarWrapper now) {
        if (dualtheme && !is_in_MainMenu && !ChangeTheme(now.getIntValue())) {
            now.setValue(old);
        }
    });
    cvarManager->registerCvar("rs_x", std::to_string(rs_x), GetLang(LANG_X), true, true, 0.f, true, 1.f, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_y", std::to_string(rs_y), GetLang(LANG_Y), true, true, 0.f, true, 1.f, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_scale", std::to_string(rs_scale), GetLang(LANG_SCALE), true, true, 0.001f, true, 10.f, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_rotate", std::to_string(rs_rotate), GetLang(LANG_ROTATE), true, true, -180.f, true, 180.f, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_opacity", std::to_string(rs_opacity), GetLang(LANG_OPACITY), true, true, 0.f, true, 1.f, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));

    cvarManager->registerCvar("rs_disp_overlay", (rs_disp_overlay ? "1" : "0"), GetLang(LANG_OVERLAY), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));

    cvarManager->registerCvar("rs_enable_inmenu", (rs_enable_inmenu ? "1" : "0"), GetLang(LANG_SHOW_IN_MENU), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_enable_ingame", (rs_enable_ingame ? "1" : "0"), GetLang(LANG_SHOW_IN_GAME), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_enable_inscoreboard", (rs_enable_inscoreboard ? "1" : "0"), GetLang(LANG_SHOW_IN_SCOREBOARD), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshTheme, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_enable_float", (rs_enable_float ? "1" : "0"), GetLang(LANG_FLOATING_POINT), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_preview_rank", (rs_preview_rank ? "1" : "0"), GetLang(LANG_PREVIEW_RANK), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_roman_numbers", (rs_roman_numbers ? "1" : "0"), GetLang(LANG_ROMAN_NUMBERS), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));

    cvarManager->registerCvar("rs_replace_mmr", (rs_replace_mmr ? "1" : "0"), GetLang(LANG_MMR_TO_MMRCHANGE), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_replace_mmr_cc", (rs_replace_mmr_cc ? "1" : "0"), GetLang(LANG_MMR_TO_MMRCHANGE), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_replace_mmrc", (rs_replace_mmrc ? "1" : "0"), GetLang(LANG_MMRCHANGE_TO_MMR), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_replace_mmrc_cc", (rs_replace_mmrc_cc ? "1" : "0"), GetLang(LANG_MMRCHANGE_TO_MMRCUMULCHANGE), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_replace_mmrcc", (rs_replace_mmrcc ? "1" : "0"), GetLang(LANG_MMRCUMULCHANGE_TO_MMR), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));
    cvarManager->registerCvar("rs_replace_mmrcc_c", (rs_replace_mmrcc_c ? "1" : "0"), GetLang(LANG_MMRCUMULCHANGE_TO_MMRCHANGE), true, true, 0, true, 1, false).addOnValueChanged(std::bind(&RocketStats::RefreshFiles, this, std::placeholders::_1, std::placeholders::_2));

    cvarManager->registerCvar("rs_in_file", (rs_in_file ? "1" : "0"), GetLang(LANG_IN_FILE), true, true, 0, true, 1, true).addOnValueChanged([this](std::string old, CVarWrapper now) {
        if (now.getBoolValue())
            UpdateFiles(true);
        RefreshTheme(old, now);
    });
    cvarManager->registerCvar("rs_file_games", (rs_file_games ? "1" : "0"), GetLang(LANG_FILE_GAMES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarGames(true); });
    cvarManager->registerCvar("rs_file_gm", (rs_file_gm ? "1" : "0"), GetLang(LANG_FILE_GAMEMODE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarGameMode(true); });
    cvarManager->registerCvar("rs_file_rank", (rs_file_rank ? "1" : "0"), GetLang(LANG_FILE_RANK), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarRank(true); });
    cvarManager->registerCvar("rs_file_div", (rs_file_div ? "1" : "0"), GetLang(LANG_FILE_DIVISION), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarDiv(true); });
    cvarManager->registerCvar("rs_file_mmr", (rs_file_mmr ? "1" : "0"), GetLang(LANG_FILE_MMR), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarMMR(true); });
    cvarManager->registerCvar("rs_file_mmrc", (rs_file_mmrc ? "1" : "0"), GetLang(LANG_FILE_MMRCHANGE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarMMRChange(true); });
    cvarManager->registerCvar("rs_file_mmrcc", (rs_file_mmrcc ? "1" : "0"), GetLang(LANG_FILE_MMRCUMULCHANGE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarMMRCumulChange(true); });
    cvarManager->registerCvar("rs_file_win", (rs_file_win ? "1" : "0"), GetLang(LANG_FILE_WINS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarWin(true); });
    cvarManager->registerCvar("rs_file_loss", (rs_file_loss ? "1" : "0"), GetLang(LANG_FILE_LOSSES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarLoss(true); });
    cvarManager->registerCvar("rs_file_streak", (rs_file_streak ? "1" : "0"), GetLang(LANG_FILE_STREAKS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarStreak(true); });
    cvarManager->registerCvar("rs_file_winratio", (rs_file_winratio ? "1" : "0"), GetLang(LANG_FILE_WINRATIO), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarWinRatio(true); });
    cvarManager->registerCvar("rs_file_winpercentage", (rs_file_winpercentage ? "1" : "0"), GetLang(LANG_FILE_WINPERCENTAGE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarWinPercentage(true); });
    cvarManager->registerCvar("rs_file_score", (rs_file_score ? "1" : "0"), GetLang(LANG_FILE_SCORE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarScorePlayer(true); VarScoreOpposite(true); });
    cvarManager->registerCvar("rs_file_shots", (rs_file_shots ? "1" : "0"), GetLang(LANG_FILE_SHOTS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllShots(); });
    cvarManager->registerCvar("rs_file_saves", (rs_file_saves ? "1" : "0"), GetLang(LANG_FILE_SAVES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllSaves(); });
    cvarManager->registerCvar("rs_file_goals", (rs_file_goals ? "1" : "0"), GetLang(LANG_FILE_GOALS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllGoals(); });
    cvarManager->registerCvar("rs_file_dropshot", (rs_file_dropshot ? "1" : "0"), GetLang(LANG_FILE_DROPSHOT), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllDropshot(); });
    cvarManager->registerCvar("rs_file_knockout", (rs_file_knockout ? "1" : "0"), GetLang(LANG_FILE_KNOCKOUT), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllKnockout(); });
    cvarManager->registerCvar("rs_file_miscs", (rs_file_miscs ? "1" : "0"), GetLang(LANG_FILE_MISCS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllMiscs(); });
    cvarManager->registerCvar("rs_file_accolades", (rs_file_accolades ? "1" : "0"), GetLang(LANG_FILE_ACCOLADES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllAccolades(); });
    cvarManager->registerCvar("rs_file_boost", (rs_file_boost ? "1" : "0"), GetLang(LANG_FILE_BOOST), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarBoost(true); });

    cvarManager->registerCvar("rs_hide_games", (rs_hide_games ? "1" : "0"), GetLang(LANG_HIDE_GAMES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarGames(true); });
    cvarManager->registerCvar("rs_hide_gm", (rs_hide_gm ? "1" : "0"), GetLang(LANG_HIDE_GAMEMODE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarGameMode(true); });
    cvarManager->registerCvar("rs_hide_rank", (rs_hide_rank ? "1" : "0"), GetLang(LANG_HIDE_RANK), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarRank(true); });
    cvarManager->registerCvar("rs_hide_div", (rs_hide_div ? "1" : "0"), GetLang(LANG_HIDE_DIVISION), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarDiv(true); });
    cvarManager->registerCvar("rs_hide_mmr", (rs_hide_mmr ? "1" : "0"), GetLang(LANG_HIDE_MMR), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarMMR(true); });
    cvarManager->registerCvar("rs_hide_mmrc", (rs_hide_mmrc ? "1" : "0"), GetLang(LANG_HIDE_MMRCHANGE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarMMRChange(true); });
    cvarManager->registerCvar("rs_hide_mmrcc", (rs_hide_mmrcc ? "1" : "0"), GetLang(LANG_HIDE_MMRCUMULCHANGE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarMMRCumulChange(true); });
    cvarManager->registerCvar("rs_hide_win", (rs_hide_win ? "1" : "0"), GetLang(LANG_HIDE_WINS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarWin(true); });
    cvarManager->registerCvar("rs_hide_loss", (rs_hide_loss ? "1" : "0"), GetLang(LANG_HIDE_LOSSES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarLoss(true); });
    cvarManager->registerCvar("rs_hide_streak", (rs_hide_streak ? "1" : "0"), GetLang(LANG_HIDE_STREAKS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarStreak(true); });
    cvarManager->registerCvar("rs_hide_winratio", (rs_hide_winratio ? "1" : "0"), GetLang(LANG_HIDE_WINRATIO), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarWinRatio(true); });
    cvarManager->registerCvar("rs_hide_winpercentage", (rs_hide_winpercentage ? "1" : "0"), GetLang(LANG_HIDE_WINPERCENTAGE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarWinPercentage(true); });
    cvarManager->registerCvar("rs_hide_score", (rs_hide_score ? "1" : "0"), GetLang(LANG_HIDE_SCORE), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { VarScorePlayer(true); VarScoreOpposite(true); });
    cvarManager->registerCvar("rs_hide_shots", (rs_hide_shots ? "1" : "0"), GetLang(LANG_HIDE_SHOTS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllShots(); });
    cvarManager->registerCvar("rs_hide_saves", (rs_hide_saves ? "1" : "0"), GetLang(LANG_HIDE_SAVES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllSaves(); });
    cvarManager->registerCvar("rs_hide_goals", (rs_hide_goals ? "1" : "0"), GetLang(LANG_HIDE_GOALS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllGoals(); });
    cvarManager->registerCvar("rs_hide_dropshot", (rs_hide_dropshot ? "1" : "0"), GetLang(LANG_HIDE_DROPSHOT), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllDropshot(); });
    cvarManager->registerCvar("rs_hide_knockout", (rs_hide_knockout ? "1" : "0"), GetLang(LANG_HIDE_KNOCKOUT), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllKnockout(); });
    cvarManager->registerCvar("rs_hide_miscs", (rs_hide_miscs ? "1" : "0"), GetLang(LANG_HIDE_MISCS), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllMiscs(); });
    cvarManager->registerCvar("rs_hide_accolades", (rs_hide_accolades ? "1" : "0"), GetLang(LANG_HIDE_ACCOLADES), true, true, 0, true, 1, false).addOnValueChanged([this](std::string old, CVarWrapper now) { AllAccolades(); });


    gameWrapper->Execute([&](GameWrapper* gameWrapper) {
        // Displays the plugin shortly after initialization
        if (rs_recovery == RecoveryFlags_Welcome)
        {
            std::string path = "RocketStats_images/welcome.tga";
            if (WriteResInFile(path, ((gameWrapper->GetUILanguage().ToString() == "FRA") ? IDB_WEL_FRA : IDB_WEL_INT), "TGA"))
                rs_welcome = LoadImg(path);
        }

        SetRefresh(RefreshFlags_Refresh);
    });
}

void RocketStats::onUnload()
{
    ShutdownWebSocket();
    WriteConfig(); // Save settings (if not already done)
    TogglePlugin("onUnload", ToggleFlags_Hide); // Hide the plugin before unloading it
}

void RocketStats::SetCustomProtocol()
{
    std::string dir = GetPath();
    Utils::ReplaceAll(dir, "/", "\\");

    HKEY key;
    LPCTSTR value;
    DWORD dwDisposition;
    if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Classes\\RocketStats"), 0, NULL, 0, KEY_WRITE, NULL, &key, &dwDisposition) == ERROR_SUCCESS)
    {
        value = TEXT("URL:RocketStats protocol");
        if (RegSetValueEx(key, TEXT(""), 0, REG_SZ, (const BYTE*)value, sizeof(TCHAR) * (lstrlen(value) + 1)) != ERROR_SUCCESS)
            cvarManager->log("Set protocol failed!");

        value = TEXT("RocketStats");
        if (RegSetValueEx(key, TEXT("URL Protocol"), 0, REG_SZ, (const BYTE*)value, sizeof(TCHAR) * (lstrlen(value) + 1)) != ERROR_SUCCESS)
            cvarManager->log("Set url failed!");

        RegCloseKey(key);

        /*if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Classes\\RocketStats\\DefaultIcon"), 0, NULL, 0, KEY_WRITE, NULL, &key, &dwDisposition) == ERROR_SUCCESS)
        {
            value = Utils::ConvertToLPSTR(installer + ", 1");
            if (RegSetValueEx(key, TEXT(""), 0, REG_SZ, (const BYTE*)value, sizeof(TCHAR) * (lstrlen(value) + 1)) != ERROR_SUCCESS)
                cvarManager->log("Set icon failed!");

            RegCloseKey(key);
        }*/

        if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Classes\\RocketStats\\shell\\open\\command"), 0, NULL, 0, KEY_WRITE, NULL, &key, &dwDisposition) == ERROR_SUCCESS)
        {
            value = Utils::ConvertToLPSTR("rundll32 shell32.dll,ShellExec_RunDLL \"powershell\" \"try { $theme = \\\"%1\\\".split( '/' )[ 3 ]; $version = \\\"%1\\\".split( '/' )[ 4 ]; $dir = \\\"" + dir + "\"; $url = \\\"http://rocketstats.net/$theme/dl/$version\\\"; $zip = \\\"$dir\\toinstall.zip\\\"; $dest = \\\"$dir\\RocketStats_themes\\\"; if ( \\\"%1\\\".split( '/' )[ 2 ] -eq 'install' -and $theme -match '^\\d+$' -and $version -match '^\\d+$' ) { echo 'Theme being downloaded ...'; Invoke-WebRequest -Uri $url -OutFile $zip >$null 2>$null; try { echo 'Theme being installed ...'; Expand-Archive $zip -DestinationPath $dest -Force >$null 2>$null; echo 'Theme successfully installed.'; echo 'Click ''R'' to the right of the ''Reload Theme'' button in RocketStats to add the theme to the list.'; Remove-Item $zip >$null 2>$null; } catch { echo 'Install error!'; } } else { echo 'The requested theme could not be found!'; } } catch { echo 'Download error!'; } echo ''; echo 'Press Enter to continue ...'; Read-Host;\"");
            if (RegSetValueEx(key, TEXT(""), 0, REG_SZ, (const BYTE*)value, sizeof(TCHAR) * (lstrlen(value) + 1)) != ERROR_SUCCESS)
                cvarManager->log("Set command failed!");

            RegCloseKey(key);
        }
    }
}

void RocketStats::ShowPlugin(std::string eventName)
{
    TogglePlugin(eventName, ToggleFlags_Show);
}

void RocketStats::UpdateUIScale(std::string eventName)
{
    rs_screen_scale[0] = gameWrapper->GetInterfaceScale();
    rs_screen_scale[1] = gameWrapper->GetDisplayScale();
    cvarManager->log("Scale: " + std::to_string(rs_screen_scale[0]) + " " + std::to_string(rs_screen_scale[1]));
    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::TogglePlugin(std::string eventName, ToggleFlags mode)
{
    if (mode == ToggleFlags_Toggle || (mode == ToggleFlags_Show && !plugin_open) || (mode == ToggleFlags_Hide && plugin_open))
    {
        plugin_open = !plugin_open;
        cvarManager->executeCommand("togglemenu " + GetMenuName());
    }
}

void RocketStats::ToggleSettings(std::string eventName, ToggleFlags mode)
{
    if (mode == ToggleFlags_Toggle || (mode == ToggleFlags_Show && !settings_open) || (mode == ToggleFlags_Hide && settings_open))
    {
        settings_open = !settings_open;

        CVarWrapper cvar = cvarManager->getCvar("cl_rocketstats_settings");
        if (cvar)
            cvar.setValue(settings_open);

        if (!settings_open)
            WriteConfig(); // Saves settings when closing the menu
    }
}
```

## File: RocketStats.h
```c
#pragma once
#pragma comment(lib, "pluginsdk.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"

#include <pch.h>
#include <json.hpp>
#include <fpstimer.hpp>
#include <resource.hpp>
#include <imgui/imgui_rotate.h>
#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include "bakkesmod/wrappers/GuiManagerWrapper.h"

#include <map>
#include <set>
#include <thread>
#include <vector>
#include <fstream>
#include <windows.h>
#include <functional>
#include <utils/parser.h>

#include "Utils.h"
#include "Languages.h"
#include "Resources/Resource.h"

#define  M_PI		3.14159265358979323846
#define  ARC_SPAN	(float(M_PI) * 2)

using json = nlohmann::json;

namespace fs = std::filesystem;

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::connection_hdl;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

enum ToggleFlags {
	ToggleFlags_Toggle,
	ToggleFlags_Show,
	ToggleFlags_Hide
};

enum RefreshFlags {
	RefreshFlags_Off,
	RefreshFlags_Refresh,
	RefreshFlags_RefreshAndImages
};

enum RecoveryFlags {
	RecoveryFlags_Off,
	RecoveryFlags_Files,
	RecoveryFlags_Welcome,
	RecoveryFlags_Process,
	RecoveryFlags_Finish
};

struct Color {
	bool enable = false;
	ImColor color = ImGui::GetColorU32({ 255.f, 255.f, 255.f, 1.f });
};

struct Element {
	std::string name = "Unknown";
	std::string type;
	std::string font;
	std::string value;
	std::vector<ImVec2> positions;
	ImVec2 size;
	Color color;
	Color fill;
	Color stroke;
	float scale = 1.f;
	bool rotate_enable = false;
	float rotate = 0.f;
};

struct Options {
	int x;
	int y;
	int width;
	int height;
	float scale;
	float opacity;
};

struct Stats {
	int games = 0;
	float myMMR = 100.f;
	float MMRChange = 0.f;
	float MMRCumulChange = 0.f;
	int win = 0;
	int loss = 0;
	int streak = 0;

	/// Shots
	int Clear = 0;
	int Assist = 0;
	int Center = 0;
	int AerialHit = 0;
	int BicycleHit = 0;
	int ShotOnGoal = 0;
	int TeamAssist = 0;
	int TeamShotOnGoal = 0;
	int TeamBicycleHit = 0;
	int TotalAssist = 0;
	int TotalShotOnGoal = 0;
	int TotalBicycleHit = 0;

	int ClearCumul = 0;
	int AssistCumul = 0;
	int CenterCumul = 0;
	int AerialHitCumul = 0;
	int BicycleHitCumul = 0;
	int ShotOnGoalCumul = 0;
	int TeamAssistCumul = 0;
	int TeamShotOnGoalCumul = 0;
	int TeamBicycleHitCumul = 0;
	int TotalAssistCumul = 0;
	int TotalShotOnGoalCumul = 0;
	int TotalBicycleHitCumul = 0;

	/// Derived stat for Shooting Percentage
	int ShootingPercentage = 0;
	int TeamShootingPercentage = 0;
	int TotalShootingPercentage = 0;
	int ShootingPercentageCumul = 0;
	int TeamShootingPercentageCumul = 0;
	int TotalShootingPercentageCumul = 0;

	/// Saves
	int Save = 0;
	int EpicSave = 0;
	int TeamSave = 0;
	int TeamEpicSave = 0;
	int TotalSave = 0;
	int TotalEpicSave = 0;

	int SaveCumul = 0;
	int EpicSaveCumul = 0;
	int TeamSaveCumul = 0;
	int TeamEpicSaveCumul = 0;
	int TotalSaveCumul = 0;
	int TotalEpicSaveCumul = 0;

	/// Goals
	int Goal = 0;
	int OwnGoal = 0;
	int LongGoal = 0;
	int PoolShot = 0;
	int AerialGoal = 0;
	int TurtleGoal = 0;
	int BicycleGoal = 0;
	int OvertimeGoal = 0;
	int BackwardsGoal = 0;
	int HoopsSwishGoal = 0;
	int TeamGoal = 0;
	int TeamLongGoal = 0;
	int TeamPoolShot = 0;
	int TeamAerialGoal = 0;
	int TeamTurtleGoal = 0;
	int TeamBicycleGoal = 0;
	int TeamOvertimeGoal = 0;
	int TeamBackwardsGoal = 0;
	int TeamHoopsSwishGoal = 0;
	int TotalGoal = 0;
	int TotalLongGoal = 0;
	int TotalPoolShot = 0;
	int TotalAerialGoal = 0;
	int TotalBackwardsGoal = 0;
	int TotalBicycleGoal = 0;
	int TotalTurtleGoal = 0;
	int TotalOvertimeGoal = 0;
	int TotalHoopsSwishGoal = 0;

	int GoalCumul = 0;
	int OwnGoalCumul = 0;
	int LongGoalCumul = 0;
	int PoolShotCumul = 0;
	int AerialGoalCumul = 0;
	int TurtleGoalCumul = 0;
	int BicycleGoalCumul = 0;
	int OvertimeGoalCumul = 0;
	int BackwardsGoalCumul = 0;
	int HoopsSwishGoalCumul = 0;
	int TeamGoalCumul = 0;
	int TeamLongGoalCumul = 0;
	int TeamPoolShotCumul = 0;
	int TeamAerialGoalCumul = 0;
	int TeamTurtleGoalCumul = 0;
	int TeamBicycleGoalCumul = 0;
	int TeamOvertimeGoalCumul = 0;
	int TeamBackwardsGoalCumul = 0;
	int TeamHoopsSwishGoalCumul = 0;
	int TotalGoalCumul = 0;
	int TotalLongGoalCumul = 0;
	int TotalPoolShotCumul = 0;
	int TotalAerialGoalCumul = 0;
	int TotalTurtleGoalCumul = 0;
	int TotalBicycleGoalCumul = 0;
	int TotalOvertimeGoalCumul = 0;
	int TotalBackwardsGoalCumul = 0;
	int TotalHoopsSwishGoalCumul = 0;

	/// Dropshot
	int BreakoutDamage = 0;
	int BreakoutDamageLarge = 0;
	int TeamBreakoutDamage = 0;
	int TeamBreakoutDamageLarge = 0;
	int TotalBreakoutDamage = 0;
	int TotalBreakoutDamageLarge = 0;

	int BreakoutDamageCumul = 0;
	int BreakoutDamageLargeCumul = 0;
	int TeamBreakoutDamageCumul = 0;
	int TeamBreakoutDamageLargeCumul = 0;
	int TotalBreakoutDamageCumul = 0;
	int TotalBreakoutDamageLargeCumul = 0;

	/// Knockout
	int KnockoutKO = 0;
	int KnockoutDeath = 0;
	int KnockoutAssist = 0;
	int KnockoutThrown = 0;
	int KnockoutWinner = 0;
	int KnockoutGrabbed = 0;
	int KnockoutDoubleKO = 0;
	int KnockoutHeavyHit = 0;
	int KnockoutHitTaken = 0;
	int KnockoutLightHit = 0;
	int KnockoutTripleKO = 0;
	int KnockoutBlockTaken = 0;
	int KnockoutHeavyBlock = 0;
	int KnockoutLightBlock = 0;
	int KnockoutPlayerThrown = 0;
	int KnockoutPlayerGrabbed = 0;
	int KnockoutAerialHeavyHit = 0;
	int KnockoutAerialLightHit = 0;

	int KnockoutKOCumul = 0;
	int KnockoutDeathCumul = 0;
	int KnockoutAssistCumul = 0;
	int KnockoutThrownCumul = 0;
	int KnockoutWinnerCumul = 0;
	int KnockoutGrabbedCumul = 0;
	int KnockoutDoubleKOCumul = 0;
	int KnockoutHeavyHitCumul = 0;
	int KnockoutHitTakenCumul = 0;
	int KnockoutLightHitCumul = 0;
	int KnockoutTripleKOCumul = 0;
	int KnockoutBlockTakenCumul = 0;
	int KnockoutHeavyBlockCumul = 0;
	int KnockoutLightBlockCumul = 0;
	int KnockoutPlayerThrownCumul = 0;
	int KnockoutPlayerGrabbedCumul = 0;
	int KnockoutAerialHeavyHitCumul = 0;
	int KnockoutAerialLightHitCumul = 0;

	/// Miscs
	int Death = 0;
	int Savior = 0; // 3 saves in a game
	int LowFive = 0;
	int HatTrick = 0;
	int HighFive = 0;
	int Playmaker = 0; // 3 assists in a game
	int FirstTouch = 0;
	int Demolitions = 0;
	int TeamDeath = 0;
	int TeamSavior = 0;
	int TeamLowFive = 0;
	int TeamHatTrick = 0;
	int TeamHighFive = 0;
	int TeamPlaymaker = 0;
	int TeamDemolitions = 0;
	int TotalDeath = 0;
	int TotalSavior = 0;
	int TotalLowFive = 0;
	int TotalHatTrick = 0;
	int TotalHighFive = 0;
	int TotalPlaymaker = 0;
	int TotalDemolitions = 0;

	int DeathCumul = 0;
	int SaviorCumul = 0;
	int LowFiveCumul = 0;
	int HatTrickCumul = 0;
	int HighFiveCumul = 0;
	int PlaymakerCumul = 0;
	int FirstTouchCumul = 0;
	int DemolitionsCumul = 0;
	int TeamDeathCumul = 0;
	int TeamSaviorCumul = 0;
	int TeamLowFiveCumul = 0;
	int TeamHatTrickCumul = 0;
	int TeamHighFiveCumul = 0;
	int TeamPlaymakerCumul = 0;
	int TeamDemolitionsCumul = 0;
	int TotalDeathCumul = 0;
	int TotalSaviorCumul = 0;
	int TotalLowFiveCumul = 0;
	int TotalHatTrickCumul = 0;
	int TotalHighFiveCumul = 0;
	int TotalPlaymakerCumul = 0;
	int TotalDemolitionsCumul = 0;

	/// Accolades (what data to display on "Match" variables: 0/1, Y/N, Yes/No, ...)
	int MVP = 0;
	int CarTouches = 0;
	int FastestGoal = 0;
	int SlowestGoal = 0;
	int BoostPickups = 0;
	int FurthestGoal = 0;
	int MostBallTouches = 0;
	int MostBoostPickups = 0;
	int FewestBallTouches = 0;
	int TeamMVP = 0;
	int TotalMVP = 0;

	int MVPCumul = 0;
	int CarTouchesCumul = 0;
	int FastestGoalCumul = 0;
	int SlowestGoalCumul = 0;
	int BoostPickupsCumul = 0;
	int FurthestGoalCumul = 0;
	int MostBallTouchesCumul = 0;
	int MostBoostPickupsCumul = 0;
	int FewestBallTouchesCumul = 0;
	int TeamMVPCumul = 0;
	int TotalMVPCumul = 0;

	bool isInit = false;
};

struct ThemeFont {
	int size = 0;
	std::string name = "";
	bool isDefault = false;
};

struct Theme {
	std::string name = "Unknown";
	std::string author = "Unknown";
	std::string version = "v1.0.0";
	std::string date = "";
	std::vector<ThemeFont> fonts = {};
	std::vector<Element> elements;
};

struct StatTickerParams {
	uintptr_t Receiver; // person who got a stat
	uintptr_t Victim; // person who is victim of a stat (only exists for demos afaik)
	uintptr_t StatEvent;
};

struct StatEventParams {
	uintptr_t PRI; // always primary player
	uintptr_t StatEvent; // wrapper for the stat event
};

struct Vector2D {
	float x = 0;
	float y = 0;
	float width = 0;
	float height = 0;
};


class RocketStats : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginWindow
{
private:
	int rs_recovery = RecoveryFlags_Off;
	float rs_launch = 0.f;
	float rs_llaunch = 0.f;
	float rs_buttons_x = 0.f;
	bool rs_menu_pos = false;
	bool rs_logo_mouv = false;
	float rs_logo_flash = -1.f;
	float rs_logo_rotate = 0.f;
	float rs_screen_scale[2] = { 1.f, 1.f };
	std::vector<std::string> rs_lang;
	std::shared_ptr<ImageWrapper> rs_logo;
	std::shared_ptr<ImageWrapper> rs_title;
	std::shared_ptr<ImageWrapper> rs_welcome;
	ImDrawList* rs_drawlist = IM_NEW(ImDrawList(NULL));

	// WebServer
	typedef std::set<connection_hdl, std::owner_less<connection_hdl>> con_list;
	void InitWebSocket();
	void ShutdownWebSocket();
	void SocketOpen(connection_hdl hdl);
	void SocketClose(connection_hdl hdl);
	void SocketReceive(connection_hdl hdl, server::message_ptr msg);
	json SocketData(std::string name, json data, std::string type);
	void SocketSend(std::string name, json data = nullptr, std::string type = "");
	void SocketBroadcast(json data);

	std::thread server_thread;
	server ws_server;

	server m_server;
	con_list m_connections;

	// Time
	tm local_time;
	time_t current_time;
	FPSTimer timer_30fps = FPSTimer(30, true);

	// Themes
	ImVec2 theme_size = { 0.f, 0.f };
	ImVec2 display_size = { 0.f, 0.f };
	unsigned char theme_style = 0;
	unsigned char theme_refresh = 2;

	json theme_config = json::object();
	json themes_values = json::object();
	Theme theme_render;
	std::string theme_prev = "";
	std::string theme_hide_value = "##";
	std::vector<Theme> themes;
	std::vector<std::string> modes;
	std::map<std::string, std::string> theme_vars;
	std::map<std::string, std::shared_ptr<ImageWrapper>> theme_images;

	// Overlay
	bool overlay_move = false;
	ImVec2 overlay_cursor;
	ImVec2 overlay_origin;

	//std::unique_ptr<MMRNotifierToken> notifierToken;

	// Game states
	int menu_stack = 0;
	bool is_in_game = false;
	bool is_in_menu = false;
	bool is_in_freeplay = false;
	bool is_in_scoreboard = false;
	bool is_online_game = false;
	bool is_offline_game = false;
	bool is_boosting = false;
	bool is_game_ended = false;
	bool is_game_started = false;

	// All stats
	Stats always;
	Stats session;
	std::map<int, Stats> stats;
	std::map<int, Stats> always_gm;

	// Current stats
	int my_team_num = -1;

	typedef struct s_current {
		int tier = 0;
		int playlist = 0;
		bool ranked = false;
		std::string rank = "norank";
		std::string division = "nodiv";
		std::string preview_rank = "norank";
		std::string preview_division = "nodiv";
		int rank_number = 0;
		int division_number = 0;
		int preview_rank_number = 0;
		int preview_division_number = 0;
		int score_player = 0;
		int score_opposite = 0;
		int boost_amount = -1;

		Stats stats = {};
	} t_current;

	t_current current;
	std::string last_rank = "norank";
	std::string last_division = "nodiv";

	// Rank & Division
	int rank_nb = 23;
	std::shared_ptr<ImageWrapper> casual;
	std::vector<std::string> roman_numbers = { "", "I", "II", "III", "IV", "V" };

	typedef struct s_ranks {
		std::string name;
		std::shared_ptr<ImageWrapper> image;
	} t_ranks;

	t_ranks rank[23] = {
		{"Unranked", nullptr},
		{"Bronze_I", nullptr},
		{"Bronze_II", nullptr},
		{"Bronze_III", nullptr},
		{"Silver_I", nullptr},
		{"Silver_II", nullptr},
		{"Silver_III", nullptr},
		{"Gold_I", nullptr},
		{"Gold_II", nullptr},
		{"Gold_III", nullptr},
		{"Platinum_I", nullptr},
		{"Platinum_II", nullptr},
		{"Platinum_III", nullptr},
		{"Diamond_I", nullptr},
		{"Diamond_II", nullptr},
		{"Diamond_III", nullptr},
		{"Champion_I", nullptr},
		{"Champion_II", nullptr},
		{"Champion_III", nullptr},
		{"Grand_Champion_I", nullptr},
		{"Grand_Champion_II", nullptr},
		{"Grand_Champion_III", nullptr},
		{"Supersonic_Legend", nullptr},
	};

	/*
	// Find link in "Documents\My Games\Rocket League\TAGame\Logs\Launch.log" and searching for psynet.gg
	// This only contains gamemode slugs, need manual mapping for "official" names
	curl -s "https://config.psynet.gg/v2/Config/BattleCars/-1514904541/Prod/Steam/INT/" | jq -r '
	  "{" ,
	  (to_entries
		| map(select(.value.PlaylistID != null))
		| sort_by(.value.PlaylistID)
		| .[]
		| "    {\(.value.PlaylistID), \"\(.key)\"},"
	  ),
	  "}"
	'
	*/

	const std::map<int, std::string> playlist_name = {
		// Soccar
		{1, "Casual Duel"},
		{2, "Casual Doubles"},
		{3, "Casual Standard"},
		{4, "Casual Quads"},

		{10, "Ranked Duel"},
		{11, "Ranked Doubles"},
		{13, "Ranked Standard"},
		{61, "Ranked Quads"},

		// Extras
		{15, "Casual Snowday"},
		{17, "Casual Hoops"},
		{18, "Casual Rumble"},
		{23, "Casual Dropshot"},

		{27, "Ranked Hoops"},
		{28, "Ranked Rumble"},
		{29, "Ranked Dropshot"},
		{30, "Ranked SnowDay"},

		// Custom Games
		{6, "Private Match"},
		{7, "Season"},
		{8, "Offline Splitscreen"},
		{9, "Training"},
		{19, "Workshop"},
		{20, "UGCTrainingEditor"}, // ???
		{21, "UGCTraining"}, // ???
		{22, "Custom Tournament"},
		{34, "Season Tournament"},

		// Misc
		{16, "Rocket Labs"},
		{26, "FaceIt"},
		{35, "Rocket Labs"},

		// LTMs
		{31, "Ghost Hunt"},
		{32, "Beachball"},
		{33, "Spike Rush"},
		{37, "Dropshot Rumble"},
		{38, "Heatseeker"},
		{41, "Boomer Ball"},
		{43, "Heatseeker Doubles"},
		{44, "Winter Breakaway"},
		{46, "Gridiron"},
		{47, "Super Cube"},
		{48, "Tactical Rumble"},
		{49, "Spring Loaded"},
		{50, "Speed Demon"},
		{52, "Gotham City Rumble"},
		{54, "Knockout"},
		{55, "confidential_thirdwheel_test"}, // ???
		{62, "Nike FC Showdown"},
		{64, "Spooky Heatseeker"},
		{65, "Haunted Heatseeker"},
		{66, "Heatseeker Ricochet"},
		{67, "Spooky Cube"},
		{68, "G-Force Frenzy"},
		{70, "Dropshot Rumble Doubles"},
		{72, "Split Shot"},
		{73, "Online Free Play"},
		{74, "Split Shot Doubles"},
		{75, "Split Shot Heatseeker"},
		{76, "Split Shot Heatseeker Doubles"},
		{77, "NonStandardSoccar"},
		{79, "Split Shot Snowday"},
		{80, "RunItBack"}, // ???
		{81, "CarWars"}, // ???
		{82, "PizzaParty"}, // ???
		{83, "PushThePuck"}, // ???
		{84, "Possession"}, // ???
		{86, "FCShowdown"}, // ???
		{87, "Sacrifice"}, // ???
		{88, "JumpJam"}, // ???
		{90, "Up to No Good"},
	};

	// PluginWindow
	int windows_count = -1;
	bool mouse_state = false;
	bool escape_state = false;
	bool plugin_open = false;
	bool settings_open = false;
	std::string menu_name = "rocketstats";
	std::string menu_title = "RocketStats";
	std::string menu_version = "";

	void RenderIcon();
	void RenderOverlay();
	void RenderSettings();

	virtual void Render() override;
	virtual std::string GetMenuName() override;
	virtual std::string GetMenuTitle() override;
	virtual void SetImGuiContext(uintptr_t ctx) override;
	virtual bool ShouldBlockInput() override;
	virtual bool IsActiveOverlay() override;
	virtual void OnOpen() override;
	virtual void OnClose() override;

public:
	bool dualtheme = false;
	int rs_mode = 0;
	int rs_theme = 0;
	int rs_gameTheme = 0;
	bool is_in_MainMenu = true;
	std::string MenuTheme;
	std::string GameTheme;

	bool rs_disp_obs = false;
	bool rs_disp_overlay = true;
	bool rs_enable_inmenu = true;
	bool rs_enable_ingame = true;
	bool rs_enable_inscoreboard = true;
	bool rs_enable_float = false;
	bool rs_preview_rank = false;
	bool rs_roman_numbers = true;

	bool rs_replace_mmr = false;
	bool rs_replace_mmr_cc = false;
	bool rs_replace_mmrc = false;
	bool rs_replace_mmrc_cc = false;
	bool rs_replace_mmrcc = false;
	bool rs_replace_mmrcc_c = false;

	bool rs_in_file = true;
	bool rs_select_all_file = true;
	bool rs_file_games = true;
	bool rs_file_gm = true;
	bool rs_file_rank = true;
	bool rs_file_div = true;
	bool rs_file_mmr = true;
	bool rs_file_mmrc = true;
	bool rs_file_mmrcc = true;
	bool rs_file_win = true;
	bool rs_file_loss = true;
	bool rs_file_streak = true;
	bool rs_file_winratio = true;
	bool rs_file_winpercentage = true;
	bool rs_file_score = true;
	bool rs_file_death = true;
	bool rs_file_deathm = true;
	bool rs_file_deathc = true;
	bool rs_file_demolitions = true;
	bool rs_file_demolitionsm = true;
	bool rs_file_demolitionsc = true;
	bool rs_file_shots = true;
	bool rs_file_goals = true;
	bool rs_file_saves = true;
	bool rs_file_dropshot = true;
	bool rs_file_knockout = true;
	bool rs_file_miscs = true;
	bool rs_file_accolades = true;
	bool rs_file_boost = true;

	bool rs_select_all_hide = true;
	bool rs_hide_games = false;
	bool rs_hide_gm = false;
	bool rs_hide_rank = false;
	bool rs_hide_div = false;
	bool rs_hide_mmr = false;
	bool rs_hide_mmrc = false;
	bool rs_hide_mmrcc = false;
	bool rs_hide_win = false;
	bool rs_hide_loss = false;
	bool rs_hide_streak = false;
	bool rs_hide_winratio = false;
	bool rs_hide_winpercentage = false;
	bool rs_hide_score = false;
	bool rs_hide_death = false;
	bool rs_hide_deathm = false;
	bool rs_hide_deathc = false;
	bool rs_hide_demolitions = false;
	bool rs_hide_demolitionsm = false;
	bool rs_hide_demolitionsc = false;
	bool rs_hide_shots = false;
	bool rs_hide_goals = false;
	bool rs_hide_saves = false;
	bool rs_hide_dropshot = false;
	bool rs_hide_knockout = false;
	bool rs_hide_miscs = false;
	bool rs_hide_accolades = false;

	float rs_x = 0.7f;
	float rs_y = 0.575f;
	float rs_scale = 1.f;
	bool rs_rotate_enabled = false;
	float rs_rotate = 0.f;
	float rs_crotate = 0.f;
	float rs_opacity = 1.f;

	bool rs_x_edit = false;
	bool rs_y_edit = false;
	bool rs_scale_edit = false;
	bool rs_rotate_edit = false;
	bool rs_opacity_edit = false;

	// Utils
	Stats GetStats();
	std::string GetRank(int tierID);
	std::string GetRankName(int tierID, int& number);
	std::string GetPlaylistName(int playlistID);
	std::string GetRoman(int number);
	std::string AddRoman(std::string str, int number);
	void LogImageLoadStatus(bool status, std::string imageName);
	std::shared_ptr<ImageWrapper> LoadImg(const std::string& _filename);
	std::shared_ptr<ImageWrapper> LoadImg(fs::path& _path);
	void LoadImgs();
	bool GetCVar(const char* name, int& value);
	bool GetCVar(const char* name, bool& value);
	bool GetCVar(const char* name, float& value);
	bool SetCVar(const char* name, int& value, bool save = false);
	bool SetCVar(const char* name, bool& value, bool save = false);
	bool SetCVar(const char* name, float& value, bool save = false);
	void CloseWelcome();
	bool RecoveryOldVars();

	// PluginLoadRoutines
	virtual void onLoad();
	virtual void onUnload();
	void onInit();
	void SetCustomProtocol();
	void ShowPlugin(std::string eventName);
	void UpdateUIScale(std::string eventName);
	void TogglePlugin(std::string eventName, ToggleFlags mode = ToggleFlags_Toggle);
	void ToggleSettings(std::string eventName, ToggleFlags mode = ToggleFlags_Toggle);

	// GameManagement
	void GameStart(std::string eventName);
	void GameEnd(std::string eventName);
	void GameDestroyed(std::string eventName);
	void ComputeStreak(bool win);
	json GetGameState();
	void SendGameState(std::string name);
	int GetGameTime();
	TeamWrapper GetTeam(bool opposing);
	LinearColor GetTeamColor(TeamWrapper team);

	// StatsManagement
	bool isPrimaryPlayer(PriWrapper pri);
	void onStatEvent(ServerWrapper caller, void* args);
	void onStatTickerMessage(ServerWrapper caller, void* args);
	void onGoalScore(std::string eventName);
	void InitRank();
	void MajRank(bool isRanked, float _currentMMR, SkillRank playerRank);
	void UpdateMMR(UniqueIDWrapper id);
	void InitStats();
	void SessionStats();
	void ResetStats();
	void ResetBasicStats();

	// BoostManagement
	void OnBoostStart(std::string eventName);
	void OnBoostChanged(std::string eventName);
	void OnBoostEnd(std::string eventName);
	int GetBoostAmount();
	//void StopBoost();

	// OverlayManagement
	void BacktoMenu();
	void InGameTheme();
	void LoadThemes();
	bool ChangeTheme(int idx);
	void SetTheme(std::string name);
	void SetGameTheme(std::string name);
	void SetRefresh(unsigned char value);
	void RefreshFiles(std::string old, CVarWrapper now);
	void RefreshTheme(std::string old, CVarWrapper now);
	void RefreshVars();
	Element CalculateElement(json& element, Options& options, bool& check);
	void RenderElement(ImDrawList* drawlist, Element& element);

	// LangManagement
	void ChangeLang(int id = IDB_LANG_INT);
	std::string GetLang(LangStringId id);

	// FileManagement
	std::string GetPath(std::string _path = "", bool root = false);
	bool ExistsPath(std::string _filename, bool root = false);
	bool RemoveFile(std::string _filename, bool root = false);
	std::string ReadFile(std::string _filename, bool root = false);
	json ReadJSON(std::string _filename, bool root = false);
	void WriteInFile(std::string _fileName, std::string _value, bool root = false);
	bool WriteResInFile(std::string _filename, int id, const char* type, bool root = false);
	void MigrateFolder();
	void MigrateRemove();
	void UpdateFiles(bool force = false);
	void ResetFiles();
	bool ReadConfig();
	void WriteConfig();

	// VarManagement
	void VarsRead(Stats& stat, json& config);
	void VarsWrite(Stats& stat, json& config, bool more = false);
	void VarsReplace(std::map<std::string, std::string>& vars);
	void VarsSession(Stats& stat, int index = 0, bool playlists = false);

#pragma region Other
	void ReadOther(Stats& stat, json& config);
	void WriteOther(Stats& stat, json& config, bool more = false);
	void ReplaceOther(std::map<std::string, std::string>& vars);
	void SessionOther(Stats& stat, int index = 0, bool playlists = false);
	void AllOther(bool force = false, bool default_value = false);

	std::string VarGames(bool write = false, bool force = false, bool default_value = false);
	std::string VarGameMode(bool write = false, bool force = false, bool default_value = false);
	std::string VarRank(bool write = false, bool force = false, bool default_value = false, int* number = nullptr);
	std::string SubVarRankName(std::string value, int number, bool default_value = false);
	std::string SubVarRankNumber(std::string value, int number, bool default_value = false);
	std::string VarDiv(bool write = false, bool force = false, bool default_value = false, int* number = nullptr);
	std::string SubVarDivName(std::string value, int number, bool default_value = false);
	std::string SubVarDivNumber(std::string value, int number, bool default_value = false);
	std::string VarMMR(bool write = false, bool force = false, bool default_value = false);
	std::string VarMMRChange(bool write = false, bool force = false, bool default_value = false);
	std::string VarMMRCumulChange(bool write = false, bool force = false, bool default_value = false);
	std::string VarWin(bool write = false, bool force = false, bool default_value = false);
	std::string VarLoss(bool write = false, bool force = false, bool default_value = false);
	std::string VarStreak(bool write = false, bool force = false, bool default_value = false);
	std::string VarWinRatio(bool write = false, bool force = false, bool default_value = false);
	std::string VarWinPercentage(bool write = false, bool force = false, bool default_value = false);
	std::string VarScorePlayer(bool write = false, bool force = false, bool default_value = false);
	std::string VarScoreOpposite(bool write = false, bool force = false, bool default_value = false);
	std::string VarBoost(bool write = false, bool force = false, bool default_value = false, bool enabled = false);
#pragma endregion

#pragma region Shots
	void ReadShots(Stats& stat, json& config);
	void WriteShots(Stats& stat, json& config, bool more = false);
	void ReplaceShots(std::map<std::string, std::string>& vars);
	void SessionShots(Stats& stat, int index = 0, bool playlists = false);
	void AllShots(bool force = false, bool default_value = false);
	void AllShotsClear(bool force = false, bool default_value = false);
	void AllShotsAssist(bool force = false, bool default_value = false);
	void AllShotsCenter(bool force = false, bool default_value = false);
	void AllShotsAerialHit(bool force = false, bool default_value = false);
	void AllShotsBicycleHit(bool force = false, bool default_value = false);
	void AllShotsShotOnGoal(bool force = false, bool default_value = false);

	std::string VarShotsClear(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsAssist(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsCenter(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsAerialHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsBicycleHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsShotOnGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsShootingPercentage(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamAssist(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamBicycleHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamShotOnGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamShootingPercentage(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalAssist(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalBicycleHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalShotOnGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalShootingPercentage(bool write = false, bool force = false, bool default_value = false);

	std::string VarShotsClearMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsAssistMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsCenterMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsAerialHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsBicycleHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsShotOnGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsShootingPercentageMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamAssistMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamBicycleHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamShotOnGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamShootingPercentageMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalAssistMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalBicycleHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalShotOnGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalShootingPercentageMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarShotsClearCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsAssistCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsCenterCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsAerialHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsBicycleHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsShotOnGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsShootingPercentageCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamAssistCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamBicycleHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamShotOnGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTeamShootingPercentageCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalAssistCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalBicycleHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalShotOnGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarShotsTotalShootingPercentageCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion

#pragma region Saves
	void ReadSaves(Stats& stat, json& config);
	void WriteSaves(Stats& stat, json& config, bool more = false);
	void ReplaceSaves(std::map<std::string, std::string>& vars);
	void SessionSaves(Stats& stat, int index = 0, bool playlists = false);
	void AllSaves(bool force = false, bool default_value = false);
	void AllSavesSave(bool force = false, bool default_value = false);
	void AllSavesEpicSave(bool force = false, bool default_value = false);

	std::string VarSavesSave(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesEpicSave(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTeamSave(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTeamEpicSave(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTotalSave(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTotalEpicSave(bool write = false, bool force = false, bool default_value = false);

	std::string VarSavesSaveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesEpicSaveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTeamSaveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTeamEpicSaveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTotalSaveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTotalEpicSaveMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarSavesSaveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesEpicSaveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTeamSaveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTeamEpicSaveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTotalSaveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarSavesTotalEpicSaveCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion

#pragma region Goals
	void ReadGoals(Stats& stat, json& config);
	void WriteGoals(Stats& stat, json& config, bool more = false);
	void ReplaceGoals(std::map<std::string, std::string>& vars);
	void SessionGoals(Stats& stat, int index = 0, bool playlists = false);
	void AllGoals(bool force = false, bool default_value = false);
	void AllGoalsGoal(bool force = false, bool default_value = false);
	void AllGoalsOwnGoal(bool force = false, bool default_value = false);
	void AllGoalsLongGoal(bool force = false, bool default_value = false);
	void AllGoalsPoolShot(bool force = false, bool default_value = false);
	void AllGoalsAerialGoal(bool force = false, bool default_value = false);
	void AllGoalsTurtleGoal(bool force = false, bool default_value = false);
	void AllGoalsBicycleGoal(bool force = false, bool default_value = false);
	void AllGoalsOvertimeGoal(bool force = false, bool default_value = false);
	void AllGoalsBackwardsGoal(bool force = false, bool default_value = false);
	void AllGoalsHoopsSwishGoal(bool force = false, bool default_value = false);

	std::string VarGoalsGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsOwnGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsLongGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsPoolShot(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsAerialGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTurtleGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsBicycleGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsOvertimeGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsBackwardsGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsHoopsSwishGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamLongGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamPoolShot(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamAerialGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamTurtleGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamBicycleGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamOvertimeGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamBackwardsGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamHoopsSwishGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalLongGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalPoolShot(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalAerialGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalTurtleGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalBicycleGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalOvertimeGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalBackwardsGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalHoopsSwishGoal(bool write = false, bool force = false, bool default_value = false);

	std::string VarGoalsGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsOwnGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsLongGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsPoolShotMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsAerialGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTurtleGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsBicycleGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsOvertimeGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsBackwardsGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsHoopsSwishGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamLongGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamPoolShotMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamAerialGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamTurtleGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamBicycleGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamOvertimeGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamBackwardsGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamHoopsSwishGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalLongGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalPoolShotMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalAerialGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalTurtleGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalBicycleGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalOvertimeGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalBackwardsGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalHoopsSwishGoalMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarGoalsGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsOwnGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsLongGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsPoolShotCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsAerialGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTurtleGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsBicycleGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsOvertimeGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsBackwardsGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsHoopsSwishGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamLongGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamPoolShotCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamAerialGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamTurtleGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamBicycleGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamOvertimeGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamBackwardsGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTeamHoopsSwishGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalLongGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalPoolShotCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalAerialGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalTurtleGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalBicycleGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalOvertimeGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalBackwardsGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarGoalsTotalHoopsSwishGoalCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion

#pragma region Dropshot
	void ReadDropshot(Stats& stat, json& config);
	void WriteDropshot(Stats& stat, json& config, bool more = false);
	void ReplaceDropshot(std::map<std::string, std::string>& vars);
	void SessionDropshot(Stats& stat, int index = 0, bool playlists = false);
	void AllDropshot(bool force = false, bool default_value = false);
	void AllDropshotBreakoutDamage(bool force = false, bool default_value = false);
	void AllDropshotBreakoutDamageLarge(bool force = false, bool default_value = false);

	std::string VarDropshotBreakoutDamage(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotBreakoutDamageLarge(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTeamBreakoutDamage(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTeamBreakoutDamageLarge(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTotalBreakoutDamage(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTotalBreakoutDamageLarge(bool write = false, bool force = false, bool default_value = false);

	std::string VarDropshotBreakoutDamageMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotBreakoutDamageLargeMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTeamBreakoutDamageMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTeamBreakoutDamageLargeMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTotalBreakoutDamageMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTotalBreakoutDamageLargeMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarDropshotBreakoutDamageCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotBreakoutDamageLargeCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTeamBreakoutDamageCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTeamBreakoutDamageLargeCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTotalBreakoutDamageCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarDropshotTotalBreakoutDamageLargeCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion

#pragma region Knockout
	void ReadKnockout(Stats& stat, json& config);
	void WriteKnockout(Stats& stat, json& config, bool more = false);
	void ReplaceKnockout(std::map<std::string, std::string>& vars);
	void SessionKnockout(Stats& stat, int index = 0, bool playlists = false);
	void AllKnockout(bool force = false, bool default_value = false);
	void AllKnockoutKO(bool force = false, bool default_value = false);
	void AllKnockoutDeath(bool force = false, bool default_value = false);
	void AllKnockoutAssist(bool force = false, bool default_value = false);
	void AllKnockoutThrown(bool force = false, bool default_value = false);
	void AllKnockoutWinner(bool force = false, bool default_value = false);
	void AllKnockoutGrabbed(bool force = false, bool default_value = false);
	void AllKnockoutDoubleKO(bool force = false, bool default_value = false);
	void AllKnockoutHeavyHit(bool force = false, bool default_value = false);
	void AllKnockoutHitTaken(bool force = false, bool default_value = false);
	void AllKnockoutLightHit(bool force = false, bool default_value = false);
	void AllKnockoutTripleKO(bool force = false, bool default_value = false);
	void AllKnockoutBlockTaken(bool force = false, bool default_value = false);
	void AllKnockoutHeavyBlock(bool force = false, bool default_value = false);
	void AllKnockoutLightBlock(bool force = false, bool default_value = false);
	void AllKnockoutPlayerThrown(bool force = false, bool default_value = false);
	void AllKnockoutPlayerGrabbed(bool force = false, bool default_value = false);
	void AllKnockoutAerialHeavyHit(bool force = false, bool default_value = false);
	void AllKnockoutAerialLightHit(bool force = false, bool default_value = false);

	std::string VarKnockoutKO(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutDeath(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAssist(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutThrown(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutWinner(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutGrabbed(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutDoubleKO(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHeavyHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHitTaken(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutLightHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutTripleKO(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutBlockTaken(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHeavyBlock(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutLightBlock(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutPlayerThrown(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutPlayerGrabbed(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAerialHeavyHit(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAerialLightHit(bool write = false, bool force = false, bool default_value = false);

	std::string VarKnockoutKOMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutDeathMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAssistMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutThrownMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutWinnerMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutGrabbedMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutDoubleKOMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHeavyHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHitTakenMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutLightHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutTripleKOMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutBlockTakenMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHeavyBlockMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutLightBlockMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutPlayerThrownMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutPlayerGrabbedMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAerialHeavyHitMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAerialLightHitMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarKnockoutKOCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutDeathCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAssistCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutThrownCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutWinnerCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutGrabbedCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutDoubleKOCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHeavyHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHitTakenCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutLightHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutTripleKOCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutBlockTakenCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutHeavyBlockCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutLightBlockCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutPlayerThrownCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutPlayerGrabbedCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAerialHeavyHitCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarKnockoutAerialLightHitCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion

#pragma region Miscs
	void ReadMiscs(Stats& stat, json& config);
	void WriteMiscs(Stats& stat, json& config, bool more = false);
	void ReplaceMiscs(std::map<std::string, std::string>& vars);
	void SessionMiscs(Stats& stat, int index = 0, bool playlists = false);
	void AllMiscs(bool force = false, bool default_value = false);
	void AllMiscsDeath(bool force = false, bool default_value = false);
	void AllMiscsSavior(bool force = false, bool default_value = false);
	void AllMiscsLowFive(bool force = false, bool default_value = false);
	void AllMiscsHatTrick(bool force = false, bool default_value = false);
	void AllMiscsHighFive(bool force = false, bool default_value = false);
	void AllMiscsPlaymaker(bool force = false, bool default_value = false);
	void AllMiscsFirstTouch(bool force = false, bool default_value = false);
	void AllMiscsDemolitions(bool force = false, bool default_value = false);

	std::string VarMiscsDeath(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsSavior(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsLowFive(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsHatTrick(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsHighFive(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsPlaymaker(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsFirstTouch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsDemolitions(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamDeath(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamSavior(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamLowFive(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamHatTrick(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamHighFive(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamPlaymaker(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamDemolitions(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalDeath(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalSavior(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalLowFive(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalHatTrick(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalHighFive(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalPlaymaker(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalDemolitions(bool write = false, bool force = false, bool default_value = false);

	std::string VarMiscsDeathMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsSaviorMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsLowFiveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsHatTrickMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsHighFiveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsPlaymakerMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsFirstTouchMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsDemolitionsMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamDeathMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamSaviorMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamLowFiveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamHatTrickMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamHighFiveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamPlaymakerMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamDemolitionsMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalDeathMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalSaviorMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalLowFiveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalHatTrickMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalHighFiveMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalPlaymakerMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalDemolitionsMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarMiscsDeathCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsSaviorCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsLowFiveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsHatTrickCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsHighFiveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsPlaymakerCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsFirstTouchCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsDemolitionsCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamDeathCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamSaviorCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamLowFiveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamHatTrickCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamHighFiveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamPlaymakerCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTeamDemolitionsCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalDeathCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalSaviorCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalLowFiveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalHatTrickCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalHighFiveCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalPlaymakerCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarMiscsTotalDemolitionsCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion

#pragma region Accolades
	void ReadAccolades(Stats& stat, json& config);
	void WriteAccolades(Stats& stat, json& config, bool more = false);
	void ReplaceAccolades(std::map<std::string, std::string>& vars);
	void SessionAccolades(Stats& stat, int index = 0, bool playlists = false);
	void AllAccolades(bool force = false, bool default_value = false);
	void AllAccoladesMVP(bool force = false, bool default_value = false);
	void AllAccoladesCarTouches(bool force = false, bool default_value = false);
	void AllAccoladesFastestGoal(bool force = false, bool default_value = false);
	void AllAccoladesSlowestGoal(bool force = false, bool default_value = false);
	void AllAccoladesBoostPickups(bool force = false, bool default_value = false);
	void AllAccoladesFurthestGoal(bool force = false, bool default_value = false);
	void AllAccoladesMostBallTouches(bool force = false, bool default_value = false);
	void AllAccoladesMostBoostPickups(bool force = false, bool default_value = false);
	void AllAccoladesFewestBallTouches(bool force = false, bool default_value = false);

	std::string VarAccoladesMVP(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesCarTouches(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFastestGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesSlowestGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesBoostPickups(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFurthestGoal(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesMostBallTouches(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesMostBoostPickups(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFewestBallTouches(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesTeamMVP(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesTotalMVP(bool write = false, bool force = false, bool default_value = false);

	std::string VarAccoladesMVPMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesCarTouchesMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFastestGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesSlowestGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesBoostPickupsMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFurthestGoalMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesMostBallTouchesMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesMostBoostPickupsMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFewestBallTouchesMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesTeamMVPMatch(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesTotalMVPMatch(bool write = false, bool force = false, bool default_value = false);

	std::string VarAccoladesMVPCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesCarTouchesCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFastestGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesSlowestGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesBoostPickupsCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFurthestGoalCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesMostBallTouchesCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesMostBoostPickupsCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesFewestBallTouchesCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesTeamMVPCumul(bool write = false, bool force = false, bool default_value = false);
	std::string VarAccoladesTotalMVPCumul(bool write = false, bool force = false, bool default_value = false);
#pragma endregion
};
```

## File: Languages.h
```c
#pragma once

enum LangStringId {
	LANG_ERROR,
	LANG_ERROR_RELOAD,
	LANG_DONATE,
	LANG_DOCUMENTATION,
	LANG_DEVELOPERS,

	LANG_MIGRATE_MESSAGE,
	LANG_MIGRATE_BUTTON_MIGRATE,
	LANG_MIGRATE_BUTTON_REMOVE,
	LANG_MIGRATE_BUTTON_NOTHING,

	LANG_RESET_TOOLTIP,
	LANG_SCALE_TOOLTIP,
	LANG_ROTATE_TOOLTIP,
	LANG_OPACITY_TOOLTIP,
	LANG_OVERLAY_TOOLTIP,
	LANG_SELECT_ALL_TOOLTIP,

	LANG_TOGGLE_LOGO_HELP,
	LANG_TOGGLE_MENU,
	LANG_TOGGLE_MENU_HELP,
	LANG_TOGGLE_MENU_TOOLTIP,
	LANG_RESET_MENU_POSITION,

	LANG_MODE,
	LANG_MODE_TOOLTIP,
	LANG_MODE_SESSION,
	LANG_MODE_GAMEMODE,
	LANG_MODE_ALWAYS,
	LANG_MODE_ALWAYS_GAMEMODE,
	LANG_THEME,
	LANG_THEME_TOOLTIP,
	LANG_X,
	LANG_X_TOOLTIP,
	LANG_Y,
	LANG_Y_TOOLTIP,
	LANG_SCALE,
	LANG_ROTATE,
	LANG_OPACITY,

	LANG_OVERLAY,
	LANG_OVERLAY_OBS,
	LANG_OVERLAY_MOVE,

	LANG_OPEN_FOLDER,
	LANG_OPEN_FOLDER_TOOLTIP,
	LANG_RELOAD_THEME,
	LANG_RELOAD_THEME_TOOLTIP,
	LANG_RELOAD_THEME_A,
	LANG_RELOAD_THEME_A_TOOLTIP,
	LANG_RESET_STATS,
	LANG_RESET_STATS_TOOLTIP,

	LANG_THEME_BY,

	LANG_SHOW_IN_MENU,
	LANG_SHOW_IN_GAME,
	LANG_SHOW_IN_SCOREBOARD,
	LANG_FLOATING_POINT,
	LANG_PREVIEW_RANK,
	LANG_ROMAN_NUMBERS,
	LANG_MMR_TO_MMRCHANGE,
	LANG_MMR_TO_MMRCUMULCHANGE,
	LANG_MMRCHANGE_TO_MMR,
	LANG_MMRCHANGE_TO_MMRCUMULCHANGE,
	LANG_MMRCUMULCHANGE_TO_MMR,
	LANG_MMRCUMULCHANGE_TO_MMRCHANGE,

	LANG_IN_FILE,
	LANG_IN_FILE_TOOLTIP,

	LANG_GAMES,
	LANG_GAMEMODE,
	LANG_RANK,
	LANG_DIVISION,
	LANG_MMR,
	LANG_MMRCHANGE,
	LANG_MMRCUMULCHANGE,
	LANG_WINS,
	LANG_LOSSES,
	LANG_STREAKS,
	LANG_WINRATIO,
	LANG_WINPERCENTAGE,
	LANG_SCORE,
	LANG_SHOTS,
	LANG_SAVES,
	LANG_GOALS,
	LANG_DROPSHOT,
	LANG_KNOCKOUT,
	LANG_MISCS,
	LANG_ACCOLADES,
	LANG_BOOST,

	LANG_FILE_TITLE,
	LANG_FILE_GAMES,
	LANG_FILE_GAMEMODE,
	LANG_FILE_RANK,
	LANG_FILE_DIVISION,
	LANG_FILE_MMR,
	LANG_FILE_MMRCHANGE,
	LANG_FILE_MMRCUMULCHANGE,
	LANG_FILE_WINS,
	LANG_FILE_LOSSES,
	LANG_FILE_STREAKS,
	LANG_FILE_WINRATIO,
	LANG_FILE_WINPERCENTAGE,
	LANG_FILE_SCORE,
	LANG_FILE_SHOTS,
	LANG_FILE_SAVES,
	LANG_FILE_GOALS,
	LANG_FILE_DROPSHOT,
	LANG_FILE_KNOCKOUT,
	LANG_FILE_MISCS,
	LANG_FILE_ACCOLADES,
	LANG_FILE_BOOST,

	LANG_HIDE_TITLE,
	LANG_HIDE_GAMES,
	LANG_HIDE_GAMEMODE,
	LANG_HIDE_RANK,
	LANG_HIDE_DIVISION,
	LANG_HIDE_MMR,
	LANG_HIDE_MMRCHANGE,
	LANG_HIDE_MMRCUMULCHANGE,
	LANG_HIDE_WINS,
	LANG_HIDE_LOSSES,
	LANG_HIDE_STREAKS,
	LANG_HIDE_WINRATIO,
	LANG_HIDE_WINPERCENTAGE,
	LANG_HIDE_SCORE,
	LANG_HIDE_SHOTS,
	LANG_HIDE_SAVES,
	LANG_HIDE_GOALS,
	LANG_HIDE_DROPSHOT,
	LANG_HIDE_KNOCKOUT,
	LANG_HIDE_MISCS,
	LANG_HIDE_ACCOLADES,
	LANG_MENU,
	LANG_GAME,
	LANG_MENU_THEME,
	LANG_GAME_THEME,
};
```

