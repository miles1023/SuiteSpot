// TODO: HotkeyToastOverlay — disabled pending crash investigation; re-enable with hotkeys feature
#include "pch.h"
#if 0
#include "HotkeyToastOverlay.h"
#include <cmath>
#include <algorithm>

void HotkeyToastOverlay::ShowToast(const std::string& message, bool isError)
{
    // Split on ": " for two-line card (e.g. "Map Changed: Floating Rings")
    auto sep = message.find(": ");
    if (sep != std::string::npos) {
        title = message.substr(0, sep);
        body  = message.substr(sep + 2);
    } else {
        title.clear();
        body = message;
    }

    startTime     = std::chrono::steady_clock::now();
    duration      = 7.0f;
    this->isError = isError;
    visible       = true;
}

void HotkeyToastOverlay::Render(ImDrawList* dl, ImFont* titleFont, ImFont* bodyFont)
{
    if (!visible || !dl) return;

    // Guard against fonts not yet loaded (async LoadFont still pending)
    if (!titleFont || !bodyFont) return;

    float elapsed = std::chrono::duration<float>(
        std::chrono::steady_clock::now() - startTime).count();
    if (elapsed >= duration) { visible = false; return; }

    // Opacity: hold full 5s, linear fade over final 2s
    float alpha = (elapsed < 5.0f) ? 1.0f : 1.0f - ((elapsed - 5.0f) / 2.0f);
    alpha = std::clamp(alpha, 0.0f, 1.0f);

    // Smooth slide-in from above (0.3s smoothstep)
    float t    = std::min(elapsed / 0.3f, 1.0f);
    float ease = t * t * (3.0f - 2.0f * t);

    int a = static_cast<int>(alpha * 255.0f);

    // Accent color: blue for normal, red for error
    ImU32 accent    = isError ? IM_COL32(220, 60, 60, a) : IM_COL32(0, 150, 255, a);
    ImVec4 accentV  = isError ? ImVec4(0.86f, 0.24f, 0.24f, alpha)
                              : ImVec4(0.0f, 0.59f, 1.0f, alpha);

    // ── Measure text ──
    bool twoLine = !title.empty();
    const char* titleStr = title.c_str();
    const char* bodyStr  = body.c_str();

    ImFont* tFont = titleFont ? titleFont : bodyFont;
    ImFont* bFont = bodyFont;
    float tFsz = tFont ? tFont->FontSize : 0.0f;
    float bFsz = bFont ? bFont->FontSize : 0.0f;

    // Measure with appropriate fonts
    ImVec2 titleSize{0, 0};
    if (twoLine && tFont) {
        titleSize = tFont->CalcTextSizeA(tFsz, FLT_MAX, 0.0f, titleStr);
    } else if (twoLine) {
        titleSize = ImGui::CalcTextSize(titleStr);
    }

    ImVec2 bodySize;
    if (bFont) {
        bodySize = bFont->CalcTextSizeA(bFsz, FLT_MAX, 0.0f, bodyStr);
    } else {
        bodySize = ImGui::CalcTextSize(bodyStr);
    }

    // ── Card geometry ──
    const float accentW = 6.0f;
    const float iconW   = 28.0f;  // 4 gap + 20 diam + 4 gap
    const float padX    = 14.0f;
    const float padY    = 10.0f;

    float textW = std::max(titleSize.x, bodySize.x);
    float bw    = accentW + iconW + textW + padX;
    float bh;
    if (twoLine) {
        bh = padY + titleSize.y + 3.0f + bodySize.y + padY;
    } else {
        bh = padY * 2.0f + bodySize.y;
    }
    bh = std::max(bh, 44.0f);  // ensure icon fits

    const float bx = 20.0f;
    const float by = -bh + (20.0f + bh) * ease;

    // ── Layer 1: Outer glow (3 rings) ──
    dl->AddRectFilled(
        ImVec2(bx - 8, by - 8), ImVec2(bx + bw + 8, by + bh + 8),
        IM_COL32(0, 100, 200, static_cast<int>(20 * alpha)), 20.0f);
    dl->AddRectFilled(
        ImVec2(bx - 4, by - 4), ImVec2(bx + bw + 4, by + bh + 4),
        IM_COL32(0, 100, 200, static_cast<int>(10 * alpha)), 16.0f);
    dl->AddRectFilled(
        ImVec2(bx - 2, by - 2), ImVec2(bx + bw + 2, by + bh + 2),
        IM_COL32(0, 100, 200, static_cast<int>(4 * alpha)), 14.0f);

    // ── Layer 2: BG gradient ──
    dl->AddRectFilledMultiColor(
        ImVec2(bx, by), ImVec2(bx + bw, by + bh),
        IM_COL32(8, 15, 28, static_cast<int>(235 * alpha)),    // top-left
        IM_COL32(14, 22, 42, static_cast<int>(235 * alpha)),   // top-right
        IM_COL32(8, 15, 28, static_cast<int>(235 * alpha)),    // bottom-right
        IM_COL32(4, 8, 18, static_cast<int>(235 * alpha)));    // bottom-left

    // ── Layer 3: Border ──
    dl->AddRect(
        ImVec2(bx, by), ImVec2(bx + bw, by + bh),
        IM_COL32(0, 121, 207, a), 12.0f, 0, 1.5f);

    // ── Layer 4: Top-light (surface reflection) ──
    dl->AddLine(
        ImVec2(bx + 12, by + 1), ImVec2(bx + bw - 12, by + 1),
        IM_COL32(255, 255, 255, static_cast<int>(30 * alpha)), 1.0f);

    // ── Layer 5: Accent bar ──
    float barInset = 4.0f;
    dl->AddRectFilled(
        ImVec2(bx + barInset, by + barInset),
        ImVec2(bx + barInset + accentW, by + bh - barInset),
        accent, 3.0f);

    // ── Layer 6: Icon circle ──
    float iconCx = bx + accentW + 4.0f + 10.0f;  // center of 20px diameter circle
    float iconCy = by + bh * 0.5f;
    float iconR  = 10.0f;

    dl->AddCircleFilled(ImVec2(iconCx, iconCy), iconR,
        IM_COL32(ImU8(accentV.x * 255), ImU8(accentV.y * 255), ImU8(accentV.z * 255),
                 static_cast<int>(75 * alpha)));
    dl->AddCircle(ImVec2(iconCx, iconCy), iconR, accent, 0, 1.5f);

    // ── Layer 7: Icon glyph ──
    if (isError) {
        // X icon
        float s = 4.5f;
        dl->AddLine(ImVec2(iconCx - s, iconCy - s), ImVec2(iconCx + s, iconCy + s),
                    IM_COL32(255, 255, 255, a), 2.0f);
        dl->AddLine(ImVec2(iconCx + s, iconCy - s), ImVec2(iconCx - s, iconCy + s),
                    IM_COL32(255, 255, 255, a), 2.0f);
    } else {
        // Checkmark
        dl->PathLineTo(ImVec2(iconCx - 5.0f, iconCy + 0.5f));
        dl->PathLineTo(ImVec2(iconCx - 1.5f, iconCy + 4.0f));
        dl->PathLineTo(ImVec2(iconCx + 5.5f, iconCy - 4.0f));
        dl->PathStroke(IM_COL32(255, 255, 255, a), false, 2.0f);
    }

    // ── Layer 8: Title + Body text ──
    float textX = bx + accentW + iconW;
    if (twoLine) {
        float titleY = by + padY;
        // Title shadow
        dl->AddText(tFont, tFsz, ImVec2(textX + 1, titleY + 1),
            IM_COL32(0, 0, 0, static_cast<int>(140 * alpha)), titleStr);
        dl->AddText(tFont, tFsz, ImVec2(textX, titleY), accent, titleStr);

        float bodyY = titleY + titleSize.y + 3.0f;
        // Body shadow
        dl->AddText(bFont, bFsz, ImVec2(textX + 1, bodyY + 1),
            IM_COL32(0, 0, 0, static_cast<int>(100 * alpha)), bodyStr);
        dl->AddText(bFont, bFsz, ImVec2(textX, bodyY),
            IM_COL32(230, 230, 230, a), bodyStr);
    } else {
        float bodyY = by + (bh - bodySize.y) * 0.5f;
        dl->AddText(bFont, bFsz, ImVec2(textX + 1, bodyY + 1),
            IM_COL32(0, 0, 0, static_cast<int>(140 * alpha)), bodyStr);
        dl->AddText(bFont, bFsz, ImVec2(textX, bodyY), accent, bodyStr);
    }

    // ── Layer 9: Progress drain bar (empties over 5s) ──
    if (elapsed < 5.0f) {
        float drainFrac = 1.0f - (elapsed / 5.0f);
        float drainW    = (bw - 4.0f) * drainFrac;
        float drainY    = by + bh - 3.5f;
        dl->AddRectFilled(
            ImVec2(bx + 2.0f, drainY),
            ImVec2(bx + 2.0f + drainW, drainY + 2.0f),
            accent, 1.0f);
    }

    // ── Layer 10: Shimmer sweep (one-shot, first 0.35s) ──
    if (elapsed < 0.35f) {
        float shimT    = elapsed / 0.35f;
        float shimX    = bx + (bw + 24.0f) * shimT - 24.0f;
        float shimW    = 24.0f;
        int   shimAlph = static_cast<int>(30 * alpha);

        dl->PushClipRect(ImVec2(bx, by), ImVec2(bx + bw, by + bh), true);
        dl->AddRectFilledMultiColor(
            ImVec2(shimX, by), ImVec2(shimX + shimW, by + bh),
            IM_COL32(255, 255, 255, 0),         // left: transparent
            IM_COL32(255, 255, 255, shimAlph),   // center-ish
            IM_COL32(255, 255, 255, shimAlph),   // center-ish
            IM_COL32(255, 255, 255, 0));         // right: transparent
        dl->PopClipRect();
    }
}
#endif
