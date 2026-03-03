#pragma once
// TODO: HotkeyToastOverlay — disabled pending crash investigation; re-enable with hotkeys feature
#if 0
#include "imgui/imgui.h"
#include <string>
#include <chrono>

class HotkeyToastOverlay
{
public:
    void ShowToast(const std::string& message, bool isError = false);
    void Render(ImDrawList* dl, ImFont* titleFont, ImFont* bodyFont);

private:
    std::string title;
    std::string body;
    std::chrono::steady_clock::time_point startTime{};
    float duration = 0.0f;
    bool  visible  = false;
    bool  isError  = false;
};
#endif
