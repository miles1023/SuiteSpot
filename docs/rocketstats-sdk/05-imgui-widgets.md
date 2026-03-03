# Custom ImGui Widgets

_Source: RocketStats BakkesMod plugin — extracted via repomix_

## File: Libraries/imgui/imconfig.h
```c
//-----------------------------------------------------------------------------
// COMPILE-TIME OPTIONS FOR DEAR IMGUI
// Runtime options (clipboard callbacks, enabling various features, etc.) can generally be set via the ImGuiIO structure.
// You can use ImGui::SetAllocatorFunctions() before calling ImGui::CreateContext() to rewire memory allocation functions.
//-----------------------------------------------------------------------------
// A) You may edit imconfig.h (and not overwrite it when updating Dear ImGui, or maintain a patch/branch with your modifications to imconfig.h)
// B) or add configuration directives in your own file and compile with #define IMGUI_USER_CONFIG "myfilename.h"
// If you do so you need to make sure that configuration settings are defined consistently _everywhere_ Dear ImGui is used, which include
// the imgui*.cpp files but also _any_ of your code that uses Dear ImGui. This is because some compile-time options have an affect on data structures.
// Defining those options in imconfig.h will ensure every compilation unit gets to see the same data structure layouts.
// Call IMGUI_CHECKVERSION() from your .cpp files to verify that the data structures your files are using are matching the ones imgui.cpp is using.
//-----------------------------------------------------------------------------

#pragma once

//---- Define assertion handler. Defaults to calling assert().
// If your macro uses multiple statements, make sure is enclosed in a 'do { .. } while (0)' block so it can be used as a single statement.
//#define IM_ASSERT(_EXPR)  MyAssert(_EXPR)
//#define IM_ASSERT(_EXPR)  ((void)(_EXPR))     // Disable asserts

//---- Define attributes of all API symbols declarations, e.g. for DLL under Windows
// Using dear imgui via a shared library is not recommended, because of function call overhead and because we don't guarantee backward nor forward ABI compatibility.
//#define IMGUI_API __declspec( dllexport )
//#define IMGUI_API __declspec( dllimport )

//---- Don't define obsolete functions/enums/behaviors. Consider enabling from time to time after updating to avoid using soon-to-be obsolete function/names.
//#define IMGUI_DISABLE_OBSOLETE_FUNCTIONS

//---- Disable all of Dear ImGui or don't implement standard windows. 
// It is very strongly recommended to NOT disable the demo windows during development. Please read comments in imgui_demo.cpp.
//#define IMGUI_DISABLE                                     // Disable everything: all headers and source files will be empty. 
//#define IMGUI_DISABLE_DEMO_WINDOWS                        // Disable demo windows: ShowDemoWindow()/ShowStyleEditor() will be empty. Not recommended. 
//#define IMGUI_DISABLE_METRICS_WINDOW                      // Disable debug/metrics window: ShowMetricsWindow() will be empty.

//---- Don't implement some functions to reduce linkage requirements.
//#define IMGUI_DISABLE_WIN32_DEFAULT_CLIPBOARD_FUNCTIONS   // [Win32] Don't implement default clipboard handler. Won't use and link with OpenClipboard/GetClipboardData/CloseClipboard etc.
//#define IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCTIONS         // [Win32] Don't implement default IME handler. Won't use and link with ImmGetContext/ImmSetCompositionWindow.
//#define IMGUI_DISABLE_WIN32_FUNCTIONS                     // [Win32] Won't use and link with any Win32 function (clipboard, ime).
//#define IMGUI_ENABLE_OSX_DEFAULT_CLIPBOARD_FUNCTIONS      // [OSX] Implement default OSX clipboard handler (need to link with '-framework ApplicationServices', this is why this is not the default).
//#define IMGUI_DISABLE_DEFAULT_FORMAT_FUNCTIONS            // Don't implement ImFormatString/ImFormatStringV so you can implement them yourself (e.g. if you don't want to link with vsnprintf)
//#define IMGUI_DISABLE_DEFAULT_MATH_FUNCTIONS              // Don't implement ImFabs/ImSqrt/ImPow/ImFmod/ImCos/ImSin/ImAcos/ImAtan2 so you can implement them yourself.
//#define IMGUI_DISABLE_DEFAULT_FILE_FUNCTIONS              // Don't implement ImFileOpen/ImFileClose/ImFileRead/ImFileWrite so you can implement them yourself if you don't want to link with fopen/fclose/fread/fwrite. This will also disable the LogToTTY() function.
//#define IMGUI_DISABLE_DEFAULT_ALLOCATORS                  // Don't implement default allocators calling malloc()/free() to avoid linking with them. You will need to call ImGui::SetAllocatorFunctions().

//---- Include imgui_user.h at the end of imgui.h as a convenience
//#define IMGUI_INCLUDE_IMGUI_USER_H

//---- Pack colors to BGRA8 instead of RGBA8 (to avoid converting from one to another)
//#define IMGUI_USE_BGRA_PACKED_COLOR

//---- Avoid multiple STB libraries implementations, or redefine path/filenames to prioritize another version
// By default the embedded implementations are declared static and not available outside of imgui cpp files.
//#define IMGUI_STB_TRUETYPE_FILENAME   "my_folder/stb_truetype.h"
//#define IMGUI_STB_RECT_PACK_FILENAME  "my_folder/stb_rect_pack.h"
//#define IMGUI_DISABLE_STB_TRUETYPE_IMPLEMENTATION
//#define IMGUI_DISABLE_STB_RECT_PACK_IMPLEMENTATION

//---- Unless IMGUI_DISABLE_DEFAULT_FORMAT_FUNCTIONS is defined, use the much faster STB sprintf library implementation of vsnprintf instead of the one from the default C library.
// Note that stb_sprintf.h is meant to be provided by the user and available in the include path at compile time. Also, the compatibility checks of the arguments and formats done by clang and GCC will be disabled in order to support the extra formats provided by STB sprintf.
// #define IMGUI_USE_STB_SPRINTF

//---- Define constructor and implicit cast operators to convert back<>forth between your math types and ImVec2/ImVec4.
// This will be inlined as part of ImVec2 and ImVec4 class declarations.
/*
#define IM_VEC2_CLASS_EXTRA                                                 \
        ImVec2(const MyVec2& f) { x = f.x; y = f.y; }                       \
        operator MyVec2() const { return MyVec2(x,y); }

#define IM_VEC4_CLASS_EXTRA                                                 \
        ImVec4(const MyVec4& f) { x = f.x; y = f.y; z = f.z; w = f.w; }     \
        operator MyVec4() const { return MyVec4(x,y,z,w); }
*/

//---- Use 32-bit vertex indices (default is 16-bit) is one way to allow large meshes with more than 64K vertices.
// Your renderer back-end will need to support it (most example renderer back-ends support both 16/32-bit indices).
// Another way to allow large meshes while keeping 16-bit indices is to handle ImDrawCmd::VtxOffset in your renderer.
// Read about ImGuiBackendFlags_RendererHasVtxOffset for details.
//#define ImDrawIdx unsigned int

//---- Override ImDrawCallback signature (will need to modify renderer back-ends accordingly)
//struct ImDrawList;
//struct ImDrawCmd;
//typedef void (*MyImDrawCallback)(const ImDrawList* draw_list, const ImDrawCmd* cmd, void* my_renderer_user_data);
//#define ImDrawCallback MyImDrawCallback

//---- Debug Tools: Macro to break in Debugger
// (use 'Metrics->Tools->Item Picker' to pick widgets with the mouse and break into them for easy debugging.)
//#define IM_DEBUG_BREAK  IM_ASSERT(0)
//#define IM_DEBUG_BREAK  __debugbreak()

//---- Debug Tools: Have the Item Picker break in the ItemAdd() function instead of ItemHoverable(),
// (which comes earlier in the code, will catch a few extra items, allow picking items other than Hovered one.)
// This adds a small runtime cost which is why it is not enabled by default.
//#define IMGUI_DEBUG_TOOL_ITEM_PICKER_EX

//---- Debug Tools: Enable slower asserts
//#define IMGUI_DEBUG_PARANOID

//---- Tip: You can add extra functions within the ImGui:: namespace, here or in your own headers files.
/*
namespace ImGui
{
    void MyFunction(const char* name, const MyMatrix44& v);
}
*/

#define IMGUI_DEFINE_MATH_OPERATORS
```

## File: Libraries/imgui/imgui_additions.h
```c
#pragma once
#include <string>
#include <vector>
#include "imgui.h"
#include "imgui_internal.h"

namespace ImGui
{
	static auto vector_getter = [](void* vec, int idx, const char** out_text)
	{
		auto& vector = *static_cast<std::vector<std::string>*>(vec);
		if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
		*out_text = vector.at(idx).c_str();
		return true;
	};
	bool Combo(const char* label, int* currIndex, std::vector<std::string>& values);
	bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values);
}
```

## File: Libraries/imgui/imgui_additions.cpp
```cpp
#include "imgui_additions.h"

namespace ImGui {
	bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
	{
		if (values.empty()) { return false; }
		return Combo(label, currIndex, vector_getter,
			static_cast<void*>(&values), int(values.size()));
	}

	bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values)
	{
		if (values.empty()) { return false; }
		return ListBox(label, currIndex, vector_getter,
			static_cast<void*>(&values), int(values.size()));
	}
}
```

## File: Libraries/imgui/imgui_rotate.h
```c
#pragma once
#include "imgui.h"

extern int rotation_start_index;
extern ImDrawList* rotation_drawlist;

int ImRotateStart(ImDrawList* drawlist = nullptr);
ImVec2 ImRotationCenter(int start = rotation_start_index, ImDrawList* drawlist = rotation_drawlist);
void ImRotateEnd(float rad, int start = rotation_start_index, ImDrawList* drawlist = rotation_drawlist, ImVec2 center = ImRotationCenter());
```

## File: Libraries/imgui/imgui_rotate.cpp
```cpp
#include "imgui_rotate.h"
#include "imgui_internal.h"

int rotation_start_index;
ImDrawList* rotation_drawlist;

int ImRotateStart(ImDrawList* drawlist)
{ 
	rotation_start_index = drawlist->VtxBuffer.Size;
	if (drawlist != nullptr)
		rotation_drawlist = drawlist;

	return rotation_start_index;
}

ImVec2 ImRotationCenter(int start, ImDrawList* drawlist)
{
	ImVec2 l(FLT_MAX, FLT_MAX), u(-FLT_MAX, -FLT_MAX); // bounds

	const auto& buf = drawlist->VtxBuffer;
	for (int i = start; i < buf.Size; ++i)
		l = ImMin(l, buf[i].pos), u = ImMax(u, buf[i].pos);

	return ImVec2{ ((l.x + u.x) / 2), ((l.y + u.y) / 2) }; // or use _ClipRectStack?
}

//ImVec2 operator-(const ImVec2& l, const ImVec2& r) { return { l.x - r.x, l.y - r.y }; }

void ImRotateEnd(float rad, int start, ImDrawList* drawlist, ImVec2 center)
{
	float s = float(sin(rad)), c = float(cos(rad));
	center = (ImRotate(center, s, c) - center);

	auto& buf = drawlist->VtxBuffer;
	for (int i = start; i < buf.Size; ++i)
		buf[i].pos = (ImRotate(buf[i].pos, s, c) - center);
}
```

## File: Libraries/imgui/imgui_rangeslider.h
```c
#pragma once
#include "imgui.h"
namespace ImGui
{
    IMGUI_API bool RangeSliderScalar(const char* label, ImGuiDataType data_type, void* p_data1, void* p_data2, const void* p_min, const void* p_max, const char* format = NULL, float power = 1.0f);
    IMGUI_API bool RangeSliderScalarN(const char* label, ImGuiDataType data_type, void* p_data1, void* p_data2, int components, const void* p_min, const void* p_max, const char* format = NULL, float power = 1.0f);
    IMGUI_API bool RangeSliderFloat(const char* label, float* v1, float* v2, float v_min, float v_max, const char* format = "(%.3f, %.3f)", float power = 1.0f);     // adjust format to decorate the value with a prefix or a suffix for in-slider labels or unit display. Use power!=1.0 for power curve sliders
    IMGUI_API bool RangeSliderFloat2(const char* label, float v1[2], float v2[2], float v_min, float v_max, const char* format = "(%.3f, %.3f)", float power = 1.0f);
    IMGUI_API bool RangeSliderFloat3(const char* label, float v1[3], float v2[3], float v_min, float v_max, const char* format = "(%.3f, %.3f)", float power = 1.0f);
    IMGUI_API bool RangeSliderFloat4(const char* label, float v1[4], float v2[4], float v_min, float v_max, const char* format = "(%.3f, %.3f)", float power = 1.0f);
    IMGUI_API bool RangeSliderAngle(const char* label, float* v_rad1, float* v_rad2, float v_degrees_min = -360.0f, float v_degrees_max = +360.0f, const char* format = "(%d, %d) deg");
    IMGUI_API bool RangeSliderInt(const char* label, int* v1, int* v2, int v_min, int v_max, const char* format = "(%d, %d)");
    IMGUI_API bool RangeSliderInt2(const char* label, int v1[2], int v2[2], int v_min, int v_max, const char* format = "(%d, %d)");
    IMGUI_API bool RangeSliderInt3(const char* label, int v1[3], int v2[3], int v_min, int v_max, const char* format = "(%d, %d)");
    IMGUI_API bool RangeSliderInt4(const char* label, int v1[4], int v2[4], int v_min, int v_max, const char* format = "(%d, %d)");
    IMGUI_API bool RangeVSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data1, void* p_data2, const void* p_min, const void* p_max, const char* format = NULL, float power = 1.0f);
    IMGUI_API bool RangeVSliderFloat(const char* label, const ImVec2& size, float* v1, float* v2, float v_min, float v_max, const char* format = "(%.3f, %.3f)", float power = 1.0f);
    IMGUI_API bool RangeVSliderInt(const char* label, const ImVec2& size, int* v1, int* v2, int v_min, int v_max, const char* format = "(%d, %d)");

} // namespace ImGui
```

## File: Libraries/imgui/imgui_rangeslider.cpp
```cpp
#include "imgui_rangeslider.h"
#include "imgui_internal.h"
#include <string>
// https://github.com/ocornut/imgui/issues/76
// Inspired by: https://github.com/wasikuss/imgui/commit/a50515ace6d9a62ebcd69817f1da927d31c39bb1
// Rewritten for ImGUi 1.75

namespace ImGui
{
    //-------------------------------------------------------------------------
    // Data
    //-------------------------------------------------------------------------

    // Those MIN/MAX values are not define because we need to point to them
    static const signed char    IM_S8_MIN  = -128;
    static const signed char    IM_S8_MAX  = 127;
    static const unsigned char  IM_U8_MIN  = 0;
    static const unsigned char  IM_U8_MAX  = 0xFF;
    static const signed short   IM_S16_MIN = -32768;
    static const signed short   IM_S16_MAX = 32767;
    static const unsigned short IM_U16_MIN = 0;
    static const unsigned short IM_U16_MAX = 0xFFFF;
    static const ImS32          IM_S32_MIN = INT_MIN;    // (-2147483647 - 1), (0x80000000);
    static const ImS32          IM_S32_MAX = INT_MAX;    // (2147483647), (0x7FFFFFFF)
    static const ImU32          IM_U32_MIN = 0;
    static const ImU32          IM_U32_MAX = UINT_MAX;   // (0xFFFFFFFF)
#ifdef LLONG_MIN
    static const ImS64          IM_S64_MIN = LLONG_MIN;  // (-9223372036854775807ll - 1ll);
    static const ImS64          IM_S64_MAX = LLONG_MAX;  // (9223372036854775807ll);
#else
    static const ImS64          IM_S64_MIN = -9223372036854775807LL - 1;
    static const ImS64          IM_S64_MAX = 9223372036854775807LL;
#endif
    static const ImU64          IM_U64_MIN = 0;
#ifdef ULLONG_MAX
    static const ImU64          IM_U64_MAX = ULLONG_MAX; // (0xFFFFFFFFFFFFFFFFull);
#else
    static const ImU64          IM_U64_MAX = (2ULL * 9223372036854775807LL + 1);
#endif

    //-------------------------------------------------------------------------
    // [SECTION] Data Type and Data Formatting Helpers [Internal]
    //-------------------------------------------------------------------------
    // - PatchFormatStringFloatToInt()
    // - DataTypeFormatString()
    //-------------------------------------------------------------------------

    static const ImGuiDataTypeInfo GDataTypeInfo[] =
    {
        { sizeof(char),             "%d",   "%d"    },  // ImGuiDataType_S8
        { sizeof(unsigned char),    "%u",   "%u"    },
        { sizeof(short),            "%d",   "%d"    },  // ImGuiDataType_S16
        { sizeof(unsigned short),   "%u",   "%u"    },
        { sizeof(int),              "%d",   "%d"    },  // ImGuiDataType_S32
        { sizeof(unsigned int),     "%u",   "%u"    },
    #ifdef _MSC_VER
        { sizeof(ImS64),            "%I64d","%I64d" },  // ImGuiDataType_S64
        { sizeof(ImU64),            "%I64u","%I64u" },
    #else
        { sizeof(ImS64),            "%lld", "%lld"  },  // ImGuiDataType_S64
        { sizeof(ImU64),            "%llu", "%llu"  },
    #endif
        { sizeof(float),            "%f",   "%f"    },  // ImGuiDataType_Float (float are promoted to double in va_arg)
        { sizeof(double),           "%f",   "%lf"   },  // ImGuiDataType_Double
    };
    IM_STATIC_ASSERT(IM_ARRAYSIZE(GDataTypeInfo) == ImGuiDataType_COUNT);

    // ~65% common code with PatchFormatStringFloatToInt.
    // FIXME-LEGACY: Prior to 1.61 our DragInt() function internally used floats and because of this the compile-time default value for format was "%.0f".
    // Even though we changed the compile-time default, we expect users to have carried %f around, which would break the display of DragInt() calls.
    // To honor backward compatibility we are rewriting the format string, unless IMGUI_DISABLE_OBSOLETE_FUNCTIONS is enabled. What could possibly go wrong?!
    static const char* PatchFormatStringFloatToInt(const char* fmt)
    {
        if (strcmp(fmt, "(%.0f, %.0f)") == 0) // Fast legacy path for "(%.0f, %.0f)" which is expected to be the most common case.
            return "(%d, %d)";

        // Find % (if any, and ignore %%)
        ImGuiContext& g = *GImGui;
        g.TempBuffer[0] = '\0';
        for (const char* fmt_b = fmt; char c = fmt_b[0]; fmt_b++)
        {
            if (c == '%' && fmt_b[1] != '%')
            {
                const char* fmt_start = fmt_b;
                const char* fmt_end = ImParseFormatFindEnd(fmt_start);  // Find end of format specifier, which itself is an exercise of confidence/recklessness (because snprintf is dependent on libc or user).
                if (fmt_end > fmt_start&& fmt_end[-1] == 'f')
                {
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
                    ImFormatString(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), "%.*s%%d%s", (int)(fmt_start - fmt_b), fmt_b, fmt_end); // Honor leading and trailing decorations, but lose alignment/precision.
#else
                    IM_ASSERT(0 && "DragInt(): Invalid format string!"); // Old versions used a default parameter of "(%.0f, %.0f)", please replace with e.g. "(%d, %d)"
#endif
                }
            }
            else if (c == '%')
                fmt_b++;
        }

        if (g.TempBuffer[0] == '\0')
            return fmt;
        return g.TempBuffer;
    }

    int DataTypeFormatString(char* buf, int buf_size, ImGuiDataType data_type, const void* p_data1, const void* p_data2, const char* format)
    {
        // Signedness doesn't matter when pushing integer arguments
        if (data_type == ImGuiDataType_S32 || data_type == ImGuiDataType_U32)
            return ImFormatString(buf, buf_size, format, *(const ImU32*)p_data1, *(const ImU32*)p_data2);
        if (data_type == ImGuiDataType_S64 || data_type == ImGuiDataType_U64)
            return ImFormatString(buf, buf_size, format, *(const ImU64*)p_data1, *(const ImU64*)p_data2);
        if (data_type == ImGuiDataType_Float)
            return ImFormatString(buf, buf_size, format, *(const float*)p_data1, *(const float*)p_data2);
        if (data_type == ImGuiDataType_Double)
            return ImFormatString(buf, buf_size, format, *(const double*)p_data1, *(const double*)p_data2);
        if (data_type == ImGuiDataType_S8)
            return ImFormatString(buf, buf_size, format, *(const ImS8*)p_data1, *(const ImS8*)p_data2);
        if (data_type == ImGuiDataType_U8)
            return ImFormatString(buf, buf_size, format, *(const ImU8*)p_data1, *(const ImU8*)p_data2);
        if (data_type == ImGuiDataType_S16)
            return ImFormatString(buf, buf_size, format, *(const ImS16*)p_data1, *(const ImS16*)p_data2);
        if (data_type == ImGuiDataType_U16)
            return ImFormatString(buf, buf_size, format, *(const ImU16*)p_data1, *(const ImU16*)p_data2);
        IM_ASSERT(0);
        return 0;
    }

    //-------------------------------------------------------------------------
    // [SECTION] Widgets: SliderScalar, SliderFloat, SliderInt, etc.
    //-------------------------------------------------------------------------
    // - RangeSliderBehaviorT<>() [Internal]
    // - RangeSliderBehavior() [Internal]
    // - RangeSliderScalar()
    // - RangeSliderFloat()
    // - RangeSliderAngle()
    // - RangeSliderInt()
    //-------------------------------------------------------------------------

    // ~80% common code with ImGui::SliderBehaviorT.
    // FIXME: Move some of the code into SliderBehavior(). Current responsability is larger than what the equivalent DragBehaviorT<> does, we also do some rendering, etc.
    template<typename TYPE, typename SIGNEDTYPE, typename FLOATTYPE>
    bool RangeSliderBehaviorT(const ImRect& bb, ImGuiID id, ImGuiDataType data_type, TYPE* v1, TYPE* v2, const TYPE v_min, const TYPE v_max, const char* format, float power, ImGuiSliderFlags flags, ImRect* out_grab1_bb, ImRect* out_grab2_bb)
    {
        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;

        const ImGuiAxis axis = (flags & ImGuiSliderFlags_Vertical) ? ImGuiAxis_Y : ImGuiAxis_X;
        const bool is_decimal = (data_type == ImGuiDataType_Float) || (data_type == ImGuiDataType_Double);
        const bool is_power = (power != 1.0f) && is_decimal;

        const float grab_padding = 2.0f;
        const float slider_sz = (bb.Max[axis] - bb.Min[axis]) - grab_padding * 2.0f;
        float grab_sz = style.GrabMinSize;
        SIGNEDTYPE v_range = (v_min < v_max ? v_max - v_min : v_min - v_max);
        if (!is_decimal && v_range >= 0)                                             // v_range < 0 may happen on integer overflows
            grab_sz = ImMax((float)(slider_sz / (v_range + 1)), style.GrabMinSize);  // For integer sliders: if possible have the grab size represent 1 unit
        grab_sz = ImMin(grab_sz, slider_sz);
        const float slider_usable_sz = slider_sz - grab_sz;
        const float slider_usable_pos_min = bb.Min[axis] + grab_padding + grab_sz * 0.5f;
        const float slider_usable_pos_max = bb.Max[axis] - grab_padding - grab_sz * 0.5f;

        // For power curve sliders that cross over sign boundary we want the curve to be symmetric around 0.0f
        float linear_zero_pos;   // 0.0->1.0f
        if (is_power && v_min * v_max < 0.0f)
        {
            // Different sign
            const FLOATTYPE linear_dist_min_to_0 = ImPow(v_min >= 0 ? (FLOATTYPE)v_min : -(FLOATTYPE)v_min, (FLOATTYPE)1.0f / power);
            const FLOATTYPE linear_dist_max_to_0 = ImPow(v_max >= 0 ? (FLOATTYPE)v_max : -(FLOATTYPE)v_max, (FLOATTYPE)1.0f / power);
            linear_zero_pos = (float)(linear_dist_min_to_0 / (linear_dist_min_to_0 + linear_dist_max_to_0));
        }
        else
        {
            // Same sign
            linear_zero_pos = v_min < 0.0f ? 1.0f : 0.0f;
        }

        // Process interacting with the slider
        bool value_changed = false;
        if (g.ActiveId == id)
        {
            bool set_v_new = false;
            static int lastDrag = -1;
            float clicked_t = 0.0f;
            if (g.ActiveIdSource == ImGuiInputSource_Mouse)
            {
                if (!g.IO.MouseDown[0])
                {
                    ClearActiveID();
                }
                else
                {
                    const float mouse_abs_pos = g.IO.MousePos[axis];
                    clicked_t = (slider_usable_sz > 0.0f) ? ImClamp((mouse_abs_pos - slider_usable_pos_min) / slider_usable_sz, 0.0f, 1.0f) : 0.0f;
                    if (axis == ImGuiAxis_Y)
                        clicked_t = 1.0f - clicked_t;
                    set_v_new = true;
                }
            }
            else if (g.ActiveIdSource == ImGuiInputSource_Nav)
            {
                const ImVec2 delta2 = GetNavInputAmount2d(ImGuiNavDirSourceFlags_Keyboard | ImGuiNavDirSourceFlags_PadDPad, ImGuiInputReadMode_RepeatFast, 0.0f, 0.0f);
                float delta = (axis == ImGuiAxis_X) ? delta2.x : -delta2.y;
                if (g.NavActivatePressedId == id && !g.ActiveIdIsJustActivated)
                {
                    ClearActiveID();
                }
                else if (delta != 0.0f)
                {
                    clicked_t = SliderCalcRatioFromValueT<TYPE, FLOATTYPE>(data_type, *v1, v_min, v_max, power, linear_zero_pos);
                    const int decimal_precision = is_decimal ? ImParseFormatPrecision(format, 3) : 0;
                    if ((decimal_precision > 0) || is_power)
                    {
                        delta /= 100.0f;    // Gamepad/keyboard tweak speeds in % of slider bounds
                        if (IsNavInputDown(ImGuiNavInput_TweakSlow))
                            delta /= 10.0f;
                    }
                    else
                    {
                        if ((v_range >= -100.0f && v_range <= 100.0f) || IsNavInputDown(ImGuiNavInput_TweakSlow))
                            delta = ((delta < 0.0f) ? -1.0f : +1.0f) / (float)v_range; // Gamepad/keyboard tweak speeds in integer steps
                        else
                            delta /= 100.0f;
                    }
                    if (IsNavInputDown(ImGuiNavInput_TweakFast))
                        delta *= 10.0f;
                    set_v_new = true;
                    if ((clicked_t >= 1.0f && delta > 0.0f) || (clicked_t <= 0.0f && delta < 0.0f)) // This is to avoid applying the saturation when already past the limits
                        set_v_new = false;
                    else
                        clicked_t = ImSaturate(clicked_t + delta);
                }
            }

            if (set_v_new)
            {
                TYPE v_new;
                if (is_power)
                {
                    // Account for power curve scale on both sides of the zero
                    if (clicked_t < linear_zero_pos)
                    {
                        // Negative: rescale to the negative range before powering
                        float a = 1.0f - (clicked_t / linear_zero_pos);
                        a = ImPow(a, power);
                        v_new = ImLerp(ImMin(v_max, (TYPE)0), v_min, a);
                    }
                    else
                    {
                        // Positive: rescale to the positive range before powering
                        float a;
                        if (ImFabs(linear_zero_pos - 1.0f) > 1.e-6f)
                            a = (clicked_t - linear_zero_pos) / (1.0f - linear_zero_pos);
                        else
                            a = clicked_t;
                        a = ImPow(a, power);
                        v_new = ImLerp(ImMax(v_min, (TYPE)0), v_max, a);
                    }
                }
                else
                {
                    // Linear slider
                    if (is_decimal)
                    {
                        v_new = ImLerp(v_min, v_max, clicked_t);
                    }
                    else
                    {
                        // For integer values we want the clicking position to match the grab box so we round above
                        // This code is carefully tuned to work with large values (e.g. high ranges of U64) while preserving this property..
                        FLOATTYPE v_new_off_f = (v_max - v_min) * clicked_t;
                        TYPE v_new_off_floor = (TYPE)(v_new_off_f);
                        TYPE v_new_off_round = (TYPE)(v_new_off_f + (FLOATTYPE)0.5);
                        if (v_new_off_floor < v_new_off_round)
                            v_new = v_min + v_new_off_round;
                        else
                            v_new = v_min + v_new_off_floor;
                    }
                }

                // Round to user desired precision based on format string
                v_new = RoundScalarWithFormatT<TYPE, SIGNEDTYPE>(format, data_type, v_new);

                // Apply result
                if (*v1 != v_new || *v2 != v_new)
                {
                    if (lastDrag == 1 || lastDrag == 2)
                    {
                        if (*v2 == v_new)
                        {
                            *v1 = v_new;
                            lastDrag = 2; //left to right, just hit same spot
                        }
                    }
                    else if (lastDrag == 0 || lastDrag == 3)
                    {
                        if (*v1 == v_new)
                        {
                            *v2 = v_new;
                            lastDrag = 3; //right to left, just hit left spot
                        }
                    }
                    if (ImFabs(*v1 - v_new) == ImFabs(*v2 - v_new))
                    {
                        if (*v1 == *v2)
                        {
                            if (*v1 != v_new)
                            {
                                if (v_new > * v1)
                                {
                                    *v2 = v_new;
                                }
                                else
                                {
                                    *v1 = v_new;
                                }
                            }
                        }
                        //else
                        if (lastDrag == 1)
                        {
                            *v1 = v_new;
                        }
                        else if (lastDrag == 0)
                        {
                            *v2 = v_new;
                        }

                    }
                    else if (ImFabs(*v1 - v_new) < ImFabs(*v2 - v_new))
                    {
                        *v1 = v_new;
                        lastDrag = 1;
                    }
                    else
                    {
                        *v2 = v_new;
                        lastDrag = 0;
                    }
                    value_changed = true;
                }
            }
        }

        if (slider_sz < 1.0f)
        {
            *out_grab1_bb = ImRect(bb.Min, bb.Min);
            *out_grab2_bb = ImRect(bb.Min, bb.Min);
        }
        else
        {
            // Output grab1 position so it can be displayed by the caller
            float grab1_t = SliderCalcRatioFromValueT<TYPE, FLOATTYPE>(data_type, *v1, v_min, v_max, power, linear_zero_pos);
            if (axis == ImGuiAxis_Y)
                grab1_t = 1.0f - grab1_t;
            const float grab1_pos = ImLerp(slider_usable_pos_min, slider_usable_pos_max, grab1_t);
            if (axis == ImGuiAxis_X)
                *out_grab1_bb = ImRect(grab1_pos - grab_sz * 0.5f, bb.Min.y + grab_padding, grab1_pos + grab_sz * 0.5f, bb.Max.y - grab_padding);
            else
                *out_grab1_bb = ImRect(bb.Min.x + grab_padding, grab1_pos - grab_sz * 0.5f, bb.Max.x - grab_padding, grab1_pos + grab_sz * 0.5f);

            // Output grab2 position so it can be displayed by the caller
            float grab2_t = SliderCalcRatioFromValueT<TYPE, FLOATTYPE>(data_type, *v2, v_min, v_max, power, linear_zero_pos);
            if (axis == ImGuiAxis_Y)
                grab2_t = 1.0f - grab2_t;
            const float grab2_pos = ImLerp(slider_usable_pos_min, slider_usable_pos_max, grab2_t);
            if (axis == ImGuiAxis_X)
                *out_grab2_bb = ImRect(grab2_pos - grab_sz * 0.5f, bb.Min.y + grab_padding, grab2_pos + grab_sz * 0.5f, bb.Max.y - grab_padding);
            else
                *out_grab2_bb = ImRect(bb.Min.x + grab_padding, grab2_pos - grab_sz * 0.5f, bb.Max.x - grab_padding, grab2_pos + grab_sz * 0.5f);
        }

        return value_changed;
    }

    // ~95% common code with ImGui::SliderBehavior.
    // For 32-bit and larger types, slider bounds are limited to half the natural type range.
    // So e.g. an integer Slider between INT_MAX-10 and INT_MAX will fail, but an integer Slider between INT_MAX/2-10 and INT_MAX/2 will be ok.
    // It would be possible to lift that limitation with some work but it doesn't seem to be worth it for sliders.
    bool RangeSliderBehavior(const ImRect& bb, ImGuiID id, ImGuiDataType data_type, void* p_v1, void* p_v2, const void* p_min, const void* p_max, const char* format, float power, ImGuiSliderFlags flags, ImRect* out_grab1_bb, ImRect* out_grab2_bb)
    {
        switch (data_type)
        {
        case ImGuiDataType_S8:
        {
            ImS32 v32_1 = (ImS32) * (ImS8*)p_v1;
            ImS32 v32_2 = (ImS32) * (ImS8*)p_v2;
            bool r = RangeSliderBehaviorT<ImS32, ImS32, float>(bb, id, ImGuiDataType_S32, &v32_1, &v32_2, *(const ImS8*)p_min, *(const ImS8*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
            if (r)
            {
                *(ImS8*)p_v1 = (ImS8)v32_1;
                *(ImS8*)p_v2 = (ImS8)v32_2;
            }
            return r;
        }
        case ImGuiDataType_U8:
        {
            ImU32 v32_1 = (ImU32) * (ImU8*)p_v1;
            ImU32 v32_2 = (ImU32) * (ImU8*)p_v2;
            bool r = RangeSliderBehaviorT<ImU32, ImS32, float>(bb, id, ImGuiDataType_U32, &v32_1, &v32_2, *(const ImU8*)p_min, *(const ImU8*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
            if (r)
            {
                *(ImU8*)p_v1 = (ImU8)v32_1;
                *(ImU8*)p_v2 = (ImU8)v32_2;
            }
            return r;
        }
        case ImGuiDataType_S16:
        {
            ImS32 v32_1 = (ImS32) * (ImS16*)p_v1;
            ImS32 v32_2 = (ImS32) * (ImS16*)p_v2;
            bool r = RangeSliderBehaviorT<ImS32, ImS32, float>(bb, id, ImGuiDataType_S32, &v32_1, &v32_2, *(const ImS16*)p_min, *(const ImS16*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
            if (r)
            {
                *(ImS16*)p_v1 = (ImS16)v32_1;
                *(ImS16*)p_v2 = (ImS16)v32_2;
            }
            return r;
        }
        case ImGuiDataType_U16:
        {
            ImU32 v32_1 = (ImU32) * (ImU16*)p_v1;
            ImU32 v32_2 = (ImU32) * (ImU16*)p_v2;
            bool r = RangeSliderBehaviorT<ImU32, ImS32, float>(bb, id, ImGuiDataType_U32, &v32_1, &v32_2, *(const ImU16*)p_min, *(const ImU16*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
            if (r)
            {
                *(ImU16*)p_v1 = (ImU16)v32_1;
                *(ImU16*)p_v2 = (ImU16)v32_2;
            }
            return r;
        }
        case ImGuiDataType_S32:
            IM_ASSERT(*(const ImS32*)p_min >= IM_S32_MIN / 2 && *(const ImS32*)p_max <= IM_S32_MAX / 2);
            return RangeSliderBehaviorT<ImS32, ImS32, float >(bb, id, data_type, (ImS32*)p_v1, (ImS32*)p_v2, *(const ImS32*)p_min, *(const ImS32*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
        case ImGuiDataType_U32:
            IM_ASSERT(*(const ImU32*)p_max <= IM_U32_MAX / 2);
            return RangeSliderBehaviorT<ImU32, ImS32, float >(bb, id, data_type, (ImU32*)p_v1, (ImU32*)p_v2, *(const ImU32*)p_min, *(const ImU32*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
        case ImGuiDataType_S64:
            IM_ASSERT(*(const ImS64*)p_min >= IM_S64_MIN / 2 && *(const ImS64*)p_max <= IM_S64_MAX / 2);
            return RangeSliderBehaviorT<ImS64, ImS64, double>(bb, id, data_type, (ImS64*)p_v1, (ImS64*)p_v2, *(const ImS64*)p_min, *(const ImS64*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
        case ImGuiDataType_U64:
            IM_ASSERT(*(const ImU64*)p_max <= IM_U64_MAX / 2);
            return RangeSliderBehaviorT<ImU64, ImS64, double>(bb, id, data_type, (ImU64*)p_v1, (ImU64*)p_v2, *(const ImU64*)p_min, *(const ImU64*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
        case ImGuiDataType_Float:
            IM_ASSERT(*(const float*)p_min >= -FLT_MAX / 2.0f && *(const float*)p_max <= FLT_MAX / 2.0f);
            return RangeSliderBehaviorT<float, float, float >(bb, id, data_type, (float*)p_v1, (float*)p_v2, *(const float*)p_min, *(const float*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
        case ImGuiDataType_Double:
            IM_ASSERT(*(const double*)p_min >= -DBL_MAX / 2.0f && *(const double*)p_max <= DBL_MAX / 2.0f);
            return RangeSliderBehaviorT<double, double, double>(bb, id, data_type, (double*)p_v1, (double*)p_v2, *(const double*)p_min, *(const double*)p_max, format, power, flags, out_grab1_bb, out_grab2_bb);
        case ImGuiDataType_COUNT: break;
        }
        IM_ASSERT(0);
        return false;
    }

    // ~95% common code with ImGui::SliderScalar
    // Note: p_data, p_min and p_max are _pointers_ to a memory address holding the data. For a slider, they are all required.
    // Read code of e.g. SliderFloat(), SliderInt() etc. or examples in 'Demo->Widgets->Data Types' to understand how to use this function directly.
    bool ImGui::RangeSliderScalar(const char* label, ImGuiDataType data_type, void* p_data1, void* p_data2, const void* p_min, const void* p_max, const char* format, float power)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const float w = CalcItemWidth();

        const ImVec2 label_size = CalcTextSize(label, NULL, true);
        const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(w, label_size.y + style.FramePadding.y * 2.0f));
        const ImRect total_bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0.0f));

        ItemSize(total_bb, style.FramePadding.y);
        if (!ItemAdd(total_bb, id, &frame_bb))
            return false;

        // Default format string when passing NULL
        if (format == NULL)
            format = (std::string("(") + DataTypeGetInfo(data_type)->PrintFmt + ", " + DataTypeGetInfo(data_type)->PrintFmt + ")").c_str();
        else if (data_type == ImGuiDataType_S32 && strcmp(format, "(%d, %d)") != 0) // (FIXME-LEGACY: Patch old "%.0f" format string to use "%d", read function more details.)
            format = PatchFormatStringFloatToInt(format);

        // Tabbing or CTRL-clicking on Slider turns it into an input box
        const bool hovered = ItemHoverable(frame_bb, id);
        bool temp_input_is_active = TempInputTextIsActive(id);
        bool temp_input_start = false;
        if (!temp_input_is_active)
        {
            //const bool focus_requested = FocusableItemRegister(window, id);
            const bool focus_requested = FocusableItemRegister(window, g.ActiveId == id);
            const bool clicked = (hovered && g.IO.MouseClicked[0]);
            if (focus_requested || clicked || g.NavActivateId == id || g.NavInputId == id)
            {
                SetActiveID(id, window);
                SetFocusID(id, window);
                FocusWindow(window);
                g.ActiveIdUsingNavDirMask |= (1 << ImGuiDir_Left) | (1 << ImGuiDir_Right);
                if (focus_requested || (clicked && g.IO.KeyCtrl) || g.NavInputId == id)
                {
                    temp_input_start = true;
                    FocusableItemUnregister(window);
                }
            }
        }
        if (temp_input_is_active || temp_input_start)
            return TempInputTextScalar(frame_bb, id, label, data_type, p_data1, format);

        // Draw frame
        const ImU32 frame_col = GetColorU32(g.ActiveId == id ? ImGuiCol_FrameBgActive : g.HoveredId == id ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg);
        RenderNavHighlight(frame_bb, id);
        RenderFrame(frame_bb.Min, frame_bb.Max, frame_col, true, g.Style.FrameRounding);

        // Slider behavior
        ImRect grab_bb1, grab_bb2;
        const bool value_changed = RangeSliderBehavior(frame_bb, id, data_type, p_data1, p_data2, p_min, p_max, format, power, ImGuiSliderFlags_None, &grab_bb1, &grab_bb2);
        if (value_changed)
            MarkItemEdited(id);

        // Render grabs
        if (grab_bb1.Max.x > grab_bb1.Min.x)
            window->DrawList->AddRectFilled(grab_bb1.Min, grab_bb1.Max, GetColorU32(g.ActiveId == id ? ImGuiCol_SliderGrabActive : ImGuiCol_SliderGrab), style.GrabRounding);
        if (grab_bb2.Max.x > grab_bb2.Min.x)
            window->DrawList->AddRectFilled(grab_bb2.Min, grab_bb2.Max, GetColorU32(g.ActiveId == id ? ImGuiCol_SliderGrabActive : ImGuiCol_SliderGrab), style.GrabRounding);
        // Render connector
        ImRect connector(grab_bb1.Min, grab_bb2.Max);
        float grab_sz = grab_bb1.Max.x - grab_bb1.Min.x;
        connector.Min.x += grab_sz;
        connector.Min.y += grab_sz * 0.3f;
        connector.Max.x -= grab_sz;
        connector.Max.y -= grab_sz * 0.3f;
        window->DrawList->AddRectFilled(connector.Min, connector.Max, GetColorU32(ImGuiCol_RangeSliderBar), style.GrabRounding);

        // Display value using user-provided display format so user can add prefix/suffix/decorations to the value.
        char value_buf[64];
        const char* value_buf_end = value_buf + DataTypeFormatString(value_buf, IM_ARRAYSIZE(value_buf), data_type, p_data1, p_data2, format);
        RenderTextClipped(frame_bb.Min, frame_bb.Max, value_buf, value_buf_end, NULL, ImVec2(0.5f, 0.5f));

        if (label_size.x > 0.0f)
            RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y + style.FramePadding.y), label);

        IMGUI_TEST_ENGINE_ITEM_INFO(id, label, window->DC.ItemFlags);
        return value_changed;
    }

    // ~95% common code with ImGui::SliderScalarN
    // Add multiple sliders on 1 line for compact edition of multiple components
    bool ImGui::RangeSliderScalarN(const char* label, ImGuiDataType data_type, void* v1, void* v2, int components, const void* v_min, const void* v_max, const char* format, float power)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        bool value_changed = false;
        BeginGroup();
        PushID(label);
        PushMultiItemsWidths(components, CalcItemWidth());
        size_t type_size = GDataTypeInfo[data_type].Size;
        for (int i = 0; i < components; i++)
        {
            PushID(i);
            if (i > 0)
                SameLine(0, g.Style.ItemInnerSpacing.x);
            value_changed |= RangeSliderScalar("", data_type, v1, v2, v_min, v_max, format, power);
            PopID();
            PopItemWidth();
            v1 = (void*)((char*)v1 + type_size);
            v2 = (void*)((char*)v2 + type_size);
        }
        PopID();

        const char* label_end = FindRenderedTextEnd(label);
        if (label != label_end)
        {
            SameLine(0, g.Style.ItemInnerSpacing.x);
            TextEx(label, label_end);
        }

        EndGroup();
        return value_changed;
    }

    // ~95% common code with ImGui::SliderFloat
    bool ImGui::RangeSliderFloat(const char* label, float* v1, float* v2, float v_min, float v_max, const char* format, float power)
    {
        return RangeSliderScalar(label, ImGuiDataType_Float, v1, v2, &v_min, &v_max, format, power);
    }

    // ~95% common code with ImGui::SliderFloat2
    bool ImGui::RangeSliderFloat2(const char* label, float v1[2], float v2[2], float v_min, float v_max, const char* format, float power)
    {
        return RangeSliderScalarN(label, ImGuiDataType_Float, v1, v2, 2, &v_min, &v_max, format, power);
    }

    // ~95% common code with ImGui::SliderFloat3
    bool ImGui::RangeSliderFloat3(const char* label, float v1[3], float v2[3], float v_min, float v_max, const char* format, float power)
    {
        return RangeSliderScalarN(label, ImGuiDataType_Float, v1, v2, 3, &v_min, &v_max, format, power);
    }

    // ~95% common code with ImGui::SliderFloat4
    bool ImGui::RangeSliderFloat4(const char* label, float v1[4], float v2[4], float v_min, float v_max, const char* format, float power)
    {
        return RangeSliderScalarN(label, ImGuiDataType_Float, v1, v2, 4, &v_min, &v_max, format, power);
    }

    // ~95% common code with ImGui::SliderAngle
    bool ImGui::RangeSliderAngle(const char* label, float* v_rad1, float* v_rad2, float v_degrees_min, float v_degrees_max, const char* format)
    {
        if (format == NULL)
            format = "%d deg";
        float v_deg1 = (*v_rad1) * 360.0f / (2 * IM_PI);
        float v_deg2 = (*v_rad2) * 360.0f / (2 * IM_PI);
        bool value_changed = RangeSliderFloat(label, &v_deg2, &v_deg1, v_degrees_min, v_degrees_max, format, 1.0f);
        *v_rad1 = v_deg1 * (2 * IM_PI) / 360.0f;
        *v_rad2 = v_deg2 * (2 * IM_PI) / 360.0f;
        return value_changed;
    }

    // ~95% common code with ImGui::SliderInt
    bool ImGui::RangeSliderInt(const char* label, int* v1, int* v2, int v_min, int v_max, const char* format)
    {
        return RangeSliderScalar(label, ImGuiDataType_S32, v1, v2, &v_min, &v_max, format);
    }

    // ~95% common code with ImGui::SliderInt2
    bool ImGui::RangeSliderInt2(const char* label, int v1[2], int v2[2], int v_min, int v_max, const char* format)
    {
        return RangeSliderScalarN(label, ImGuiDataType_S32, v1, v2, 2, &v_min, &v_max, format);
    }

    // ~95% common code with ImGui::SliderInt3
    bool ImGui::RangeSliderInt3(const char* label, int v1[3], int v2[3], int v_min, int v_max, const char* format)
    {
        return RangeSliderScalarN(label, ImGuiDataType_S32, v1, v2, 3, &v_min, &v_max, format);
    }

    // ~95% common code with ImGui::SliderInt4
    bool ImGui::RangeSliderInt4(const char* label, int v1[4], int v2[4], int v_min, int v_max, const char* format)
    {
        return RangeSliderScalarN(label, ImGuiDataType_S32, v1, v2, 4, &v_min, &v_max, format);
    }

    bool ImGui::RangeVSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data1, void* p_data2, const void* p_min, const void* p_max, const char* format, float power)
    {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);

        const ImVec2 label_size = CalcTextSize(label, NULL, true);
        const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + size);
        const ImRect bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0.0f));

        ItemSize(bb, style.FramePadding.y);
        if (!ItemAdd(frame_bb, id))
            return false;

        // Default format string when passing NULL
        if (format == NULL)
            format = DataTypeGetInfo(data_type)->PrintFmt;
        else if (data_type == ImGuiDataType_S32 && strcmp(format, "%d") != 0) // (FIXME-LEGACY: Patch old "%.0f" format string to use "%d", read function more details.)
            format = PatchFormatStringFloatToInt(format);

        const bool hovered = ItemHoverable(frame_bb, id);
        if ((hovered && g.IO.MouseClicked[0]) || g.NavActivateId == id || g.NavInputId == id)
        {
            SetActiveID(id, window);
            SetFocusID(id, window);
            FocusWindow(window);
            g.ActiveIdUsingNavDirMask |= (1 << ImGuiDir_Up) | (1 << ImGuiDir_Down);
        }

        // Draw frame
        const ImU32 frame_col = GetColorU32(g.ActiveId == id ? ImGuiCol_FrameBgActive : g.HoveredId == id ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg);
        RenderNavHighlight(frame_bb, id);
        RenderFrame(frame_bb.Min, frame_bb.Max, frame_col, true, g.Style.FrameRounding);

        // Slider behavior
        ImRect grab_bb1, grab_bb2;
        const bool value_changed = RangeSliderBehavior(frame_bb, id, data_type, p_data1, p_data2, p_min, p_max, format, power, ImGuiSliderFlags_Vertical, &grab_bb1, &grab_bb2);
        if (value_changed)
            MarkItemEdited(id);

        // Render grabs
        if (grab_bb1.Max.y > grab_bb1.Min.y)
            window->DrawList->AddRectFilled(grab_bb1.Min, grab_bb1.Max, GetColorU32(g.ActiveId == id ? ImGuiCol_SliderGrabActive : ImGuiCol_SliderGrab), style.GrabRounding);
        if (grab_bb2.Max.y > grab_bb2.Min.y)
            window->DrawList->AddRectFilled(grab_bb2.Min, grab_bb2.Max, GetColorU32(g.ActiveId == id ? ImGuiCol_SliderGrabActive : ImGuiCol_SliderGrab), style.GrabRounding);
        // Render connector
        ImRect connector(grab_bb1.Min, grab_bb2.Max);
        float grab_sz = grab_bb1.Max.x - grab_bb1.Min.x;
        connector.Min.x += grab_sz;
        connector.Min.y += grab_sz * 0.3f;
        connector.Max.x -= grab_sz;
        connector.Max.y -= grab_sz * 0.3f;
        window->DrawList->AddRectFilled(connector.Min, connector.Max, GetColorU32(ImGuiCol_RangeSliderBar), style.GrabRounding);

        // Display value using user-provided display format so user can add prefix/suffix/decorations to the value.
        // For the vertical slider we allow centered text to overlap the frame padding
        char value_buf[64];
        const char* value_buf_end = value_buf + DataTypeFormatString(value_buf, IM_ARRAYSIZE(value_buf), data_type, p_data1, p_data2, format);
        RenderTextClipped(ImVec2(frame_bb.Min.x, frame_bb.Min.y + style.FramePadding.y), frame_bb.Max, value_buf, value_buf_end, NULL, ImVec2(0.5f, 0.0f));
        if (label_size.x > 0.0f)
            RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y + style.FramePadding.y), label);

        return value_changed;
    }

    bool ImGui::RangeVSliderFloat(const char* label, const ImVec2& size, float* v1, float* v2, float v_min, float v_max, const char* format, float power)
    {
        return RangeVSliderScalar(label, size, ImGuiDataType_Float, v1, v2, &v_min, &v_max, format, power);
    }

    bool ImGui::RangeVSliderInt(const char* label, const ImVec2& size, int* v1, int* v2, int v_min, int v_max, const char* format)
    {
        return RangeVSliderScalar(label, size, ImGuiDataType_S32, v1, v2, &v_min, &v_max, format);
    }
} // namespace ImGui
```

## File: Libraries/imgui/imgui_searchablecombo.h
```c
#pragma once
#include "imgui.h"

#include <ctype.h>      // isprint
#include <vector>       // vector<>
#include <string>       // string
#include <algorithm>    // transform

namespace ImGui
{
    IMGUI_API bool          BeginSearchableCombo(const char* label, const char* preview_value, char* input, int input_size, const char* input_preview_value, ImGuiComboFlags flags = 0);
    IMGUI_API void          EndSearchableCombo();
    IMGUI_API bool          SearchableCombo(const char* label, int* current_item, std::vector<std::string> items, const char* default_preview_text, const char* input_preview_value, int popup_max_height_in_items = -1);
} // namespace ImGui
```

## File: Libraries/imgui/imgui_searchablecombo.cpp
```cpp
#include "imgui_searchablecombo.h"
#include "imgui_internal.h"

static float CalcMaxPopupHeightFromItemCount(int items_count)
{
    ImGuiContext& g = *GImGui;
    if (items_count <= 0)
        return FLT_MAX;
    return (g.FontSize + g.Style.ItemSpacing.y) * items_count - g.Style.ItemSpacing.y + (g.Style.WindowPadding.y * 2);
}

/* Modified version of BeginCombo from imgui.cpp at line 9172,
 * to include a input field to be able to filter the combo values. */
bool ImGui::BeginSearchableCombo(const char* label, const char* preview_value, char* input, int input_size, const char* input_preview_value, ImGuiComboFlags flags)
{
    // Always consume the SetNextWindowSizeConstraint() call in our early return paths
    ImGuiContext& g = *GImGui;
    bool has_window_size_constraint = (g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSizeConstraint) != 0;
    g.NextWindowData.Flags &= ~ImGuiNextWindowDataFlags_HasSizeConstraint;

    ImGuiWindow* window = GetCurrentWindow();
    if (window->SkipItems)
        return false;

    IM_ASSERT((flags & (ImGuiComboFlags_NoArrowButton | ImGuiComboFlags_NoPreview)) != (ImGuiComboFlags_NoArrowButton | ImGuiComboFlags_NoPreview)); // Can't use both flags together

    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);

    const float arrow_size = (flags & ImGuiComboFlags_NoArrowButton) ? 0.0f : GetFrameHeight();
    const ImVec2 label_size = CalcTextSize(label, NULL, true);
    const float expected_w = CalcItemWidth();
    const float w = (flags & ImGuiComboFlags_NoPreview) ? arrow_size : expected_w;
    const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(w, label_size.y + style.FramePadding.y * 2.0f));
    const ImRect total_bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0.0f));

    bool hovered, held;
    bool pressed = ButtonBehavior(frame_bb, id, &hovered, &held);
    bool popup_open = IsPopupOpen(id);

    const ImU32 frame_col = GetColorU32(hovered ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg);
    const float value_x2 = ImMax(frame_bb.Min.x, frame_bb.Max.x - arrow_size);

    if (popup_open || (pressed || g.NavActivateId == id))
    {
        ImGuiID activeId = g.ActiveId;
        if (popup_open)
            g.ActiveId = id;
        else
            g.NavInputId = id;
        InputTextEx(label, input_preview_value, input, input_size, frame_bb.Max - frame_bb.Min, ImGuiInputTextFlags_NoUndoRedo);
        g.ActiveId = activeId;
        if (!(flags & ImGuiComboFlags_NoArrowButton))
        {
            ImU32 bg_col = GetColorU32((popup_open || hovered) ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
            ImU32 text_col = GetColorU32(ImGuiCol_Text);
            window->DrawList->AddRectFilled(ImVec2(value_x2, frame_bb.Min.y), frame_bb.Max, bg_col, style.FrameRounding, (w <= arrow_size) ? ImDrawCornerFlags_All : ImDrawCornerFlags_Right);
            if (value_x2 + arrow_size - style.FramePadding.x <= frame_bb.Max.x)
                RenderArrow(window->DrawList, ImVec2(value_x2 + style.FramePadding.y, frame_bb.Min.y + style.FramePadding.y), text_col, ImGuiDir_Down, 1.0f);
        }
    }
    else
    {
        ItemSize(total_bb, style.FramePadding.y);
        if (!ItemAdd(total_bb, id, &frame_bb))
            return false;
    }

    if ((pressed || g.NavActivateId == id) && !popup_open)
    {
        if (window->DC.NavLayerCurrent == 0)
            window->NavLastIds[0] = id;
        OpenPopupEx(id);
        popup_open = true;
    }

    if (!popup_open)
    {
        RenderNavHighlight(frame_bb, id);
        if (!(flags & ImGuiComboFlags_NoPreview))
            window->DrawList->AddRectFilled(frame_bb.Min, ImVec2(value_x2, frame_bb.Max.y), frame_col, style.FrameRounding, (flags & ImGuiComboFlags_NoArrowButton) ? ImDrawCornerFlags_All : ImDrawCornerFlags_Left);
        if (!(flags & ImGuiComboFlags_NoArrowButton))
        {
            ImU32 bg_col = GetColorU32((popup_open || hovered) ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
            ImU32 text_col = GetColorU32(ImGuiCol_Text);
            window->DrawList->AddRectFilled(ImVec2(value_x2, frame_bb.Min.y), frame_bb.Max, bg_col, style.FrameRounding, (w <= arrow_size) ? ImDrawCornerFlags_All : ImDrawCornerFlags_Right);
            if (value_x2 + arrow_size - style.FramePadding.x <= frame_bb.Max.x)
                RenderArrow(window->DrawList, ImVec2(value_x2 + style.FramePadding.y, frame_bb.Min.y + style.FramePadding.y), text_col, ImGuiDir_Down, 1.0f);
        }
        RenderFrameBorder(frame_bb.Min, frame_bb.Max, style.FrameRounding);

        if (preview_value != NULL && !(flags & ImGuiComboFlags_NoPreview))
            RenderTextClipped(frame_bb.Min + style.FramePadding, ImVec2(value_x2, frame_bb.Max.y), preview_value, NULL, NULL, ImVec2(0.0f, 0.0f));
        if (label_size.x > 0)
            RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y + style.FramePadding.y), label);

        return false;
    }

    if (has_window_size_constraint)
    {
        g.NextWindowData.Flags |= ImGuiNextWindowDataFlags_HasSizeConstraint;
        g.NextWindowData.SizeConstraintRect.Min.x = ImMax(g.NextWindowData.SizeConstraintRect.Min.x, w);
    }
    else
    {
        if ((flags & ImGuiComboFlags_HeightMask_) == 0)
            flags |= ImGuiComboFlags_HeightRegular;
        IM_ASSERT(ImIsPowerOfTwo(flags & ImGuiComboFlags_HeightMask_));    // Only one
        int popup_max_height_in_items = -1;
        if (flags & ImGuiComboFlags_HeightRegular)     popup_max_height_in_items = 8;
        else if (flags & ImGuiComboFlags_HeightSmall)  popup_max_height_in_items = 4;
        else if (flags & ImGuiComboFlags_HeightLarge)  popup_max_height_in_items = 20;
        SetNextWindowSizeConstraints(ImVec2(w, 0.0f), ImVec2(FLT_MAX, CalcMaxPopupHeightFromItemCount(popup_max_height_in_items)));
    }

    char name[16];
    ImFormatString(name, IM_ARRAYSIZE(name), "##Combo_%02d", g.BeginPopupStack.Size); // Recycle windows based on depth

    // Peak into expected window size so we can position it
    if (ImGuiWindow* popup_window = FindWindowByName(name))
        if (popup_window->WasActive)
        {
            ImVec2 size_expected = CalcWindowExpectedSize(popup_window);
            if (flags & ImGuiComboFlags_PopupAlignLeft)
                popup_window->AutoPosLastDirection = ImGuiDir_Left;
            ImRect r_outer = GetWindowAllowedExtentRect(popup_window);
            ImVec2 pos = FindBestWindowPosForPopupEx(frame_bb.GetBL(), size_expected, &popup_window->AutoPosLastDirection, r_outer, frame_bb, ImGuiPopupPositionPolicy_ComboBox);
            SetNextWindowPos(pos);
        }

    // We don't use BeginPopupEx() solely because we have a custom name string, which we could make an argument to BeginPopupEx()
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_Popup | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove;

    // Horizontally align ourselves with the framed text
    PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(style.FramePadding.x, style.WindowPadding.y));
    bool ret = Begin(name, NULL, window_flags);
    PopStyleVar();
    if (!ret)
    {
        EndPopup();
        IM_ASSERT(0);   // This should never happen as we tested for IsPopupOpen() above
        return false;
    }

    return true;
}


// Just so you can end your BeginSearchableCombo with EndSearchableCombo.
void ImGui::EndSearchableCombo()
{
    EndCombo();
}


/* Modified version of Combo from imgui.cpp at line 9343,
 * to include a input field to be able to filter the combo values. */
bool ImGui::SearchableCombo(const char* label, int* current_item, std::vector<std::string> items, const char* default_preview_text, const char* input_preview_value, int popup_max_height_in_items)
{
    ImGuiContext& g = *GImGui;

    const char* preview_text = NULL;
    if (*current_item >= (int)items.size())
        *current_item = 0;
    if (*current_item >= 0 && *current_item < (int)items.size())
        preview_text = items[*current_item].c_str();
    else
        preview_text = default_preview_text;

    // The old Combo() API exposed "popup_max_height_in_items". The new more general BeginCombo() API doesn't have/need it, but we emulate it here.
    if (popup_max_height_in_items != -1 && !(g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSizeConstraint))
        SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2(FLT_MAX, CalcMaxPopupHeightFromItemCount(popup_max_height_in_items)));

    const int input_size = 64;
    char input_buffer[input_size] = "";
    if (!BeginSearchableCombo(label, preview_text, input_buffer, input_size, input_preview_value, ImGuiComboFlags_None))
        return false;

    // Display items
    // FIXME-OPT: Use clipper (but we need to disable it on the appearing frame to make sure our call to SetItemDefaultFocus() is processed)
    int matched_items = 0;
    bool value_changed = false;
    for (int i = 0; i < (int)items.size(); i++)
    {
        char buffer[input_size] = "";
        ImStrncpy(buffer, input_buffer, input_size);
        std::string input(buffer);
        std::string item = items[i];

        std::transform(item.begin(), item.end(), item.begin(),
            [](unsigned char c) { return (unsigned char)std::tolower(c); });
        std::transform(input.begin(), input.end(), input.begin(),
            [](unsigned char c) { return (unsigned char)std::tolower(c); });

        if (item.find(input, 0) == std::string::npos)
            continue;

        matched_items++;
        PushID((void*)(intptr_t)i);
        const bool item_selected = (i == *current_item);
        const char* item_text = items[i].c_str();
        if (Selectable(item_text, item_selected))
        {
            value_changed = true;
            *current_item = i;
        }
        if (item_selected)
            SetItemDefaultFocus();
        PopID();
    }
    if (matched_items == 0)
        ImGui::Selectable("No maps found", false, ImGuiSelectableFlags_Disabled);

    EndSearchableCombo();

    return value_changed;
}
```

## File: Libraries/imgui/imgui_timeline.h
```c
#pragma once
namespace ImGui {

	bool BeginTimeline(const char* str_id, float max_time);
	bool TimelineEvent(const char* str_id, float times[2]);
	void EndTimeline(float current_time = -1);

}
```

## File: Libraries/imgui/imgui_timeline.cpp
```cpp
#include "imgui_timeline.h"
// cpp
#include "imgui.h"
#include "imgui_internal.h"
// https://github.com/ocornut/imgui/issues/76

namespace ImGui {

	static float s_max_timeline_value;


	bool BeginTimeline(const char* str_id, float max_time)
	{
		s_max_timeline_value = max_time;
		return BeginChild(str_id);
	}


	static const float TIMELINE_RADIUS = 6;


	bool TimelineEvent(const char* str_id, float values[2])
	{
		ImGuiWindow* win = GetCurrentWindow();
		const ImU32 inactive_color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_Button]);
		const ImU32 active_color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_ButtonHovered]);
		const ImU32 line_color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_SeparatorActive]);
		bool changed = false;
		ImVec2 cursor_pos = win->DC.CursorPos;

		// @r-lyeh {
		Button(str_id, ImVec2(120, 0)); // @todo: enable/disable track channel here
		SameLine();
		cursor_pos += ImVec2(0, GetTextLineHeightWithSpacing() / 3);
		// }

		for (int i = 0; i < 2; ++i)
		{
			ImVec2 pos = cursor_pos;
			pos.x += win->Size.x * values[i] / s_max_timeline_value + TIMELINE_RADIUS;
			pos.y += TIMELINE_RADIUS;

			SetCursorScreenPos(pos - ImVec2(TIMELINE_RADIUS, TIMELINE_RADIUS));
			PushID(i);
			InvisibleButton(str_id, ImVec2(2 * TIMELINE_RADIUS, 2 * TIMELINE_RADIUS));
			if (IsItemActive() || IsItemHovered())
			{
				ImGui::SetTooltip("%f", values[i]);
				ImVec2 a(pos.x, GetWindowContentRegionMin().y + win->Pos.y + win->Scroll.y);
				ImVec2 b(pos.x, GetWindowContentRegionMax().y + win->Pos.y + win->Scroll.y);
				win->DrawList->AddLine(a, b, line_color);
			}
			if (IsItemActive() && IsMouseDragging(0))
			{
				values[i] += GetIO().MouseDelta.x / win->Size.x * s_max_timeline_value;
				changed = true;
			}
			PopID();
			win->DrawList->AddCircleFilled(
				pos, TIMELINE_RADIUS, IsItemActive() || IsItemHovered() ? active_color : inactive_color);
		}

		ImVec2 start = cursor_pos;
		start.x += win->Size.x * values[0] / s_max_timeline_value + 2 * TIMELINE_RADIUS;
		start.y += TIMELINE_RADIUS * 0.5f;
		ImVec2 end = start + ImVec2(win->Size.x * (values[1] - values[0]) / s_max_timeline_value - 2 * TIMELINE_RADIUS,
			TIMELINE_RADIUS);

		PushID(-1);
		SetCursorScreenPos(start);
		InvisibleButton(str_id, end - start);
		if (IsItemActive() && IsMouseDragging(0))
		{
			values[0] += GetIO().MouseDelta.x / win->Size.x * s_max_timeline_value;
			values[1] += GetIO().MouseDelta.x / win->Size.x * s_max_timeline_value;
			changed = true;
		}
		PopID();

		SetCursorScreenPos(cursor_pos + ImVec2(0, GetTextLineHeightWithSpacing()));

		win->DrawList->AddRectFilled(start, end, IsItemActive() || IsItemHovered() ? active_color : inactive_color);

		if (values[0] > values[1])
		{
			float tmp = values[0];
			values[0] = values[1];
			values[1] = tmp;
		}
		if (values[1] > s_max_timeline_value) values[1] = s_max_timeline_value;
		if (values[0] < 0) values[0] = 0;
		return changed;
	}


	void EndTimeline(float t)
	{
		ImGuiWindow* win = GetCurrentWindow();

		// @r-lyeh {
		if (t >= 0) {
			if (t > s_max_timeline_value) t = s_max_timeline_value; t /= s_max_timeline_value;
			const ImU32 line_color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_SeparatorActive]);
			ImVec2 a(win->Pos.x + GetWindowContentRegionMin().x + t * GetWindowContentRegionWidth(), GetWindowContentRegionMin().y + win->Pos.y + win->Scroll.y);
			ImVec2 b(win->Pos.x + GetWindowContentRegionMin().x + t * GetWindowContentRegionWidth(), GetWindowContentRegionMax().y + win->Pos.y + win->Scroll.y);
			win->DrawList->AddLine(a, b, line_color);
		}
		// }

		ImU32 color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_Button]);
		ImU32 line_color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_Border]);
		ImU32 text_color = ColorConvertFloat4ToU32(GImGui->Style.Colors[ImGuiCol_Text]);
		float rounding = GImGui->Style.ScrollbarRounding;
		ImVec2 start(GetWindowContentRegionMin().x + win->Pos.x,
			GetWindowContentRegionMax().y - GetTextLineHeightWithSpacing() + win->Pos.y + win->Scroll.y);
		ImVec2 end = GetWindowContentRegionMax() + win->Pos + ImVec2(0, win->Scroll.y);

		win->DrawList->AddRectFilled(start, end, color, rounding);

		const int LINE_COUNT = 5;
		const ImVec2 text_offset(0, GetTextLineHeightWithSpacing());
		for (int i = 0; i <= LINE_COUNT; ++i)
		{
			ImVec2 a = GetWindowContentRegionMin() + win->Pos; // @r-lyeh: - ImVec2(TIMELINE_RADIUS, 0);
			a.x += i * (GetWindowContentRegionWidth() - 1) / LINE_COUNT; // @r-lyeh: -1
			ImVec2 b = a;
			b.y = start.y;
			win->DrawList->AddLine(a, b, line_color);
			char tmp[256];
			ImFormatString(tmp, sizeof(tmp), "%.2f", i * s_max_timeline_value / LINE_COUNT);
			win->DrawList->AddText(b, text_color, tmp);
		}

		EndChild();
	}

}
```

## File: Libraries/imgui/imguivariouscontrols.h
```c
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.


#ifndef IMGUIVARIOUSCONTROLS_H_
#define IMGUIVARIOUSCONTROLS_H_

#ifndef IMGUI_API
#include <imgui.h>
#endif //IMGUI_API

// USAGE
/*
#include "imguivariouscontrols.h"

// inside a ImGui::Window:
ImGui::TestProgressBar();

ImGui::TestPopupMenuSimple();
*/



namespace ImGui {

#ifndef IMGUIHELPER_H_
IMGUI_API bool IsItemActiveLastFrame();
IMGUI_API bool IsItemJustReleased();
#endif //IMGUIHELPER_H_

IMGUI_API bool CheckButton(const char* label,bool* pvalue);
IMGUI_API bool SmallCheckButton(const char* label,bool* pvalue);

// Please note that you can tweak the "format" argument if you want to add a prefix (or a suffix) piece of text to the text that appears at the right of the bar.
// returns the value "fraction" in 0.f-1.f.
// It does not need any ID.
IMGUI_API float ProgressBar(const char* optionalPrefixText,float value,const float minValue=0.f,const float maxValue=1.f,const char* format="%1.0f%%",const ImVec2& sizeOfBarWithoutTextInPixels=ImVec2(-1,-1),
                 const ImVec4& colorLeft=ImVec4(0,1,0,0.8),const ImVec4& colorRight=ImVec4(0,0.4,0,0.8),const ImVec4& colorBorder=ImVec4(0.25,0.25,1.0,1));

IMGUI_API void TestProgressBar();

// Single column popup menu without icon support. It disappears when the mouse goes away.
// Returns -1 when no entries has been selected.
// Optional scrollUpEntryText returns index of -2,scrollDownEntryText -3 (but they must be manually handled by the user)
IMGUI_API int PopupMenuSimple(bool& open, const char** pEntries, int numEntries, const char* optionalTitle=NULL, int* pOptionalHoveredEntryOut=NULL, int startIndex=0, int endIndex=-1, bool reverseItems=false, const char* scrollUpEntryText=NULL, const char* scrollDownEntryText=NULL);

// returns -1 if nothing has been chosen, 0 if copy has been clicked, 1 if cut has been clicked and 2 if paste has been clicked
IMGUI_API int PopupMenuSimpleCopyCutPasteOnLastItem(bool readOnly=false);

class PopupMenuSimpleParams {
public:
    bool open;
    int getSelectedEntry() const {return selectedEntry;}    // optional (use PopupMenuSimple(...) return value)
protected:
    int selectedEntry;
    int hoveredEntry;
    int endIndex;
    int startIndex;
    float scrollTimer;
    bool resetScrollingWhenRestart;
public:
    PopupMenuSimpleParams(bool _resetScrollingWhenRestart=true)
    : open(false),selectedEntry(-1),hoveredEntry(-1),endIndex(-1),startIndex(-1),scrollTimer(ImGui::GetTime()),resetScrollingWhenRestart(_resetScrollingWhenRestart)
    {}
friend int PopupMenuSimple(PopupMenuSimpleParams& params,const char** pTotalEntries,int numTotalEntries,int numAllowedEntries,bool reverseItems,const char* optionalTitle,const char* scrollUpEntryText,const char* scrollDownEntryText);
};

IMGUI_API int PopupMenuSimple(PopupMenuSimpleParams& params,const char** pTotalEntries,int numTotalEntries,int numAllowedEntries,bool reverseItems=false,const char* optionalTitle=NULL,const char* scrollUpEntryText="   ^   ",const char* scrollDownEntryText="   v   ");

IMGUI_API void TestPopupMenuSimple(const char* scrollUpEntryText="   ^   ",const char* scrollDownEntryText="   v   ");

// Single column popup menu with icon support. It disappears when the mouse goes away. Never tested.
// User is supposed to create a static instance of it, add entries once, and then call "render()".
class PopupMenu {
protected:
// TODO: Merge IconData into PopupMenuEntry
    struct IconData {
        ImTextureID user_texture_id;
        ImVec2 uv0;
        ImVec2 uv1;
        ImVec4 bg_col;
        ImVec4 tint_col;
        IconData(ImTextureID _user_texture_id=NULL,const ImVec2& _uv0 = ImVec2(0,0),const ImVec2& _uv1 = ImVec2(1,1),const ImVec4& _bg_col = ImVec4(0,0,0,1),const ImVec4& _tint_col = ImVec4(1,1,1,1))
            : user_texture_id(_user_texture_id),uv0(_uv0),uv1(_uv1),bg_col(_bg_col),tint_col(_tint_col)
        {}
        IconData(const IconData& o) {*this = o;}
        inline int compareTo(const IconData& o) const {
            if ((size_t) user_texture_id < (size_t) o.user_texture_id) return -1;
            if (user_texture_id==o.user_texture_id) {
                if (uv0.y < o.uv0.y) return -1;
                if (uv0.y == o.uv0.y)   {
                    if (uv0.x < o.uv0.x) return -1;
                    if (uv0.x == o.uv0.x) return 0;
                }
            }
            return 1;
        }
        const IconData& operator=(const IconData& o) {
            user_texture_id = o.user_texture_id;
            uv0 = o.uv0; uv1 = o.uv1; bg_col = o.bg_col; tint_col = o.tint_col;
            return *this;
        }
    };
public:    
    struct PopupMenuEntry : public IconData  {
    public:
        enum {
            MAX_POPUP_MENU_ENTRY_TEXT_SIZE = 512
        };
        char text[MAX_POPUP_MENU_ENTRY_TEXT_SIZE];
        bool selectable;
        PopupMenuEntry(const char* _text=NULL,bool _selectable=false,ImTextureID _user_texture_id=NULL,const ImVec2& _uv0 = ImVec2(0,0),const ImVec2& _uv1 = ImVec2(1,1),const ImVec4& _bg_col = ImVec4(0,0,0,1),const ImVec4& _tint_col = ImVec4(1,1,1,1))
            :  IconData(_user_texture_id,_uv0,_uv1,_bg_col,_tint_col),selectable(_selectable)
        {
            if (_text)   {
                IM_ASSERT(strlen(_text)<MAX_POPUP_MENU_ENTRY_TEXT_SIZE);
                strcpy(text,_text);
            }
            else text[0]='\0';
        }
        PopupMenuEntry(const PopupMenuEntry& o) : IconData(o) {*this = o;}
        inline int compareTo(const PopupMenuEntry& o) const {
            if (text[0]=='\0')  {
                if (o.text[0]!='\0') return 1;
            }
            else if (o.text[0]=='\0') return -1;
            const int c = strcmp(text,o.text);
            if (c!=0) return c;
            if ((size_t) user_texture_id < (size_t) o.user_texture_id) return -1;
            if (user_texture_id==o.user_texture_id) {
                if (uv0.y < o.uv0.y) return -1;
                if (uv0.y == o.uv0.y)   {
                    if (uv0.x < o.uv0.x) return -1;
                    if (uv0.x == o.uv0.x) return 0;
                }
            }
            return 1;
        }
        const PopupMenuEntry& operator=(const PopupMenuEntry& o) {
            IconData::operator=(o);
            selectable = o.selectable;
            if (o.text[0]!='\0') strcpy(text,o.text);
            else text[0]='\0';
            return *this;
        }
    };

mutable int selectedEntry;  // of last frame. otherwise -1
ImVector <PopupMenuEntry> entries;  // should be protected, but maybe the user wants to modify it at runtime: in case inherit from this class

void addEntryTitle(const char* text,bool addSeparator=true) {
    entries.push_back(PopupMenuEntry(text,false));
    if (addSeparator) addEntrySeparator();
}
void addEntrySeparator() {
    entries.push_back(PopupMenuEntry(NULL,false));
}
void addEntry(const char* _text,ImTextureID _user_texture_id=NULL,const ImVec2& _uv0 = ImVec2(0,0),const ImVec2& _uv1 = ImVec2(1,1),const ImVec4& _bg_col = ImVec4(0,0,0,1),const ImVec4& _tint_col = ImVec4(1,1,1,1))  {
    entries.push_back(PopupMenuEntry(_text,true,_user_texture_id,_uv0,_uv1,_bg_col,_tint_col));
}

// of last frame. otherwise -1
int getSelectedEntry() const {return selectedEntry;}

// please set "open" to "true" when starting popup.
// When the menu closes, you have open==false and as a return value "selectedEntry"
// The returned "selectedEntry" (and "getSelectedEntry()") are !=-1 only at the exact frame the menu entry is selected.
int render(bool& open) const    {
    selectedEntry = -1;
    if (!open) return selectedEntry;
    const int numEntries = (int) entries.size();
    if (numEntries==0) {
        open = false;
        return selectedEntry;
    }    

    static const ImVec4 transparentColor(1,1,1,0);   
    ImGui::PushStyleColor(ImGuiCol_Button,transparentColor);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered,ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered]);
    ImVec2 iconSize;iconSize.x = iconSize.y = ImGui::GetTextLineHeight();

    ImGui::PushID(&entries);
    //ImGui::BeginPopup(&open);
    ImGui::OpenPopup("MyOwnMenu");
    if (ImGui::BeginPopup("MyOwnMenu")) {
        bool imageClicked = false;
        for (int i = 0; i < numEntries; i++)    {
            const PopupMenuEntry& entry = entries[i];
            imageClicked = false;
            if (entry.user_texture_id) {
                imageClicked = ImGui::ImageButton((void*)entry.user_texture_id,iconSize,entry.uv0,entry.uv1,0,entry.bg_col,entry.tint_col) && entry.selectable;
                ImGui::SameLine();
            }
            if (strlen(entry.text)==0) ImGui::Separator();
            else if (entry.selectable)  {
                if (ImGui::Selectable(entry.text, false) || imageClicked)  {
                    selectedEntry = i;
                    open = false;    // Hide menu
                }
            }
            else ImGui::Text("%s",entry.text);
        }
        if (open)   // close menu when mouse goes away
        {
            ImVec2 pos = ImGui::GetWindowPos();pos.x-=5;pos.y-=5;
            ImVec2 size = ImGui::GetWindowSize();size.x+=10;size.y+=10;
            const ImVec2& mousePos = ImGui::GetIO().MousePos;
            if (mousePos.x<pos.x || mousePos.y<pos.y || mousePos.x>pos.x+size.x || mousePos.y>pos.y+size.y) open = false;
        }
    }
    ImGui::EndPopup();
    ImGui::PopID();
    ImGui::PopStyleColor(2);

    return selectedEntry;
}

bool isEmpty() const {return entries.size()==0;}

};

// Based on the code from: https://github.com/benoitjacquier/imgui
IMGUI_API bool ColorChooser(bool* open,ImVec4* pColorOut=NULL, bool supportsAlpha=true);
// Based on the code from: https://github.com/benoitjacquier/imgui
IMGUI_API bool ColorCombo(const char* label,ImVec4 *pColorOut=NULL,bool supportsAlpha=false,float width=0.f,bool closeWhenMouseLeavesIt=true);


// Based on the code from: https://github.com/Roflraging (see https://github.com/ocornut/imgui/issues/383)
/*
    *pOptionalCursorPosOut;      // Out
    *pOptionalSelectionStartOut; // Out (== to SelectionEnd when no selection)
    *pOptionalSelectionEndOut;   // Out
*/
IMGUI_API bool InputTextMultilineWithHorizontalScrolling(const char* label, char* buf, size_t buf_size, float height, ImGuiInputTextFlags flags = 0, bool* pOptionalIsHoveredOut=NULL, int* pOptionalCursorPosOut=NULL, int* pOptionalSelectionStartOut=NULL, int* pOptionalSelectionEndOut=NULL, float SCROLL_WIDTH=2000.f);

// Based on the code from: https://github.com/Roflraging (see https://github.com/ocornut/imgui/issues/383)
/*
  staticBoolVar is true if the popup_menu is open
  The three integers represent the cursorPos, the selectionStart and the selectionEnd position.
  Must be static and be in an array.
*/
IMGUI_API bool InputTextMultilineWithHorizontalScrollingAndCopyCutPasteMenu(const char* label, char* buf, int buf_size, float height,bool& staticBoolVar, int* staticArrayOfThreeIntegersHere, ImGuiInputTextFlags flags=0, bool*pOptionalHoveredOut=NULL,float SCROLL_WIDTH=2000.f,const char* copyName=NULL, const char* cutName=NULL, const char *pasteName=NULL);

// label is used as id
// <0 frame_padding uses default frame padding settings. 0 for no padding
IMGUI_API bool ImageButtonWithText(ImTextureID texId,const char* label,const ImVec2& imageSize=ImVec2(0,0), const ImVec2& uv0 = ImVec2(0,0),  const ImVec2& uv1 = ImVec2(1,1), int frame_padding = -1, const ImVec4& bg_col = ImVec4(0,0,0,0), const ImVec4& tint_col = ImVec4(1,1,1,1));

#ifndef NO_IMGUIVARIOUSCONTROLS_ANIMATEDIMAGE
// One instance per image can feed multiple widgets
struct AnimatedImage {
    // TODO: load still images as fallback and load gifs from memory
    public:
    typedef void (*FreeTextureDelegate)(ImTextureID& texid);
    typedef void (*GenerateOrUpdateTextureDelegate)(ImTextureID& imtexid,int width,int height,int channels,const unsigned char* pixels,bool useMipmapsIfPossible,bool wraps,bool wrapt);
    void SetFreeTextureCallback(FreeTextureDelegate freeTextureCb) {FreeTextureCb=freeTextureCb;}
    void SetGenerateOrUpdateTextureCallback(GenerateOrUpdateTextureDelegate generateOrUpdateTextureCb) {GenerateOrUpdateTextureCb=generateOrUpdateTextureCb;}

#	ifndef STBI_NO_GIF
#   ifndef IMGUIVARIOUSCONTROLS_NO_STDIO
    IMGUI_API AnimatedImage(char const *gif_filepath,bool useHoverModeIfSupported=false); // 'hoverMode' is supported only if all frames fit 'MaxPersistentTextureSize'
#   endif //IMGUIVARIOUSCONTROLS_NO_STDIO
    IMGUI_API AnimatedImage(const unsigned char* gif_buffer,int gif_buffer_size,bool useHoverModeIfSupported=false); // 'hoverMode' is supported only if all frames fit 'MaxPersistentTextureSize'
#	endif //STBI_NO_GIF
    IMGUI_API AnimatedImage(ImTextureID myTexId,int animationImageWidth,int animationImageHeight,int numFrames,int numFramesPerRowInTexture,int numFramesPerColumnInTexture,float delayBetweenFramesInCs,bool useHoverMode=false); // 'hoverMode' always available. 'myTexId' is yours.
    IMGUI_API AnimatedImage();    // You'll need to manually call 'load' o 'create'
    IMGUI_API ~AnimatedImage();   // calls 'clear'
    IMGUI_API void clear();   // releases the textures that are created inside the class

    // Main methods
    IMGUI_API void render(ImVec2 size=ImVec2(0,0), const ImVec2& uv0=ImVec2(0,0), const ImVec2& uv1=ImVec2(1,1), const ImVec4& tint_col=ImVec4(1,1,1,1), const ImVec4& border_col=ImVec4(0,0,0,0)) const;
    IMGUI_API bool renderAsButton(const char* label,ImVec2 size=ImVec2(0,0), const ImVec2& uv0 = ImVec2(0,0),  const ImVec2& uv1 = ImVec2(1,1), int frame_padding = -1, const ImVec4& bg_col = ImVec4(0,0,0,0), const ImVec4& tint_col = ImVec4(1,1,1,1));    // <0 frame_padding uses default frame padding settings. 0 for no padding

    // Less useful methods
#	ifndef STBI_NO_GIF
#   ifndef IMGUIVARIOUSCONTROLS_NO_STDIO
    IMGUI_API bool load(char const *gif_filepath,bool useHoverModeIfSupported=false); // 'hoverMode' is supported only if all frames fit 'MaxPersistentTextureSize'
#   endif //IMGUIVARIOUSCONTROLS_NO_STDIO
    IMGUI_API bool load_from_memory(const unsigned char* gif_buffer,int gif_buffer_size,bool useHoverModeIfSupported=false);  // 'hoverMode' is supported only if all frames fit 'MaxPersistentTextureSize'
#	endif //STBI_NO_GIF
    IMGUI_API bool create(ImTextureID myTexId,int animationImageWidth,int animationImageHeight,int numFrames,int numFramesPerRowInTexture,int numFramesPerColumnInTexture,float delayBetweenFramesInCs,bool useHoverMode=false); // 'hoverMode' always available. 'myTexId' is yours.
    IMGUI_API int getWidth() const;
    IMGUI_API int getHeight() const;
    IMGUI_API int getNumFrames() const;
    IMGUI_API bool areAllFramesInASingleTexture() const;  // when true, 'hoverMode' was available in ctr/load/create (but it can't change at runtime)

    static ImVec2 MaxPersistentTextureSize;   // 2048,2048 (Enlarge the buffer if needed for 'hoverMode': but using smaller animated images and less frames is better)

    private:
    AnimatedImage(const AnimatedImage& ) {}     // Actually maybe we could allow some of these for containers...
    void operator=(const AnimatedImage& ) {}
    static FreeTextureDelegate FreeTextureCb;
    static GenerateOrUpdateTextureDelegate GenerateOrUpdateTextureCb;
    friend struct AnimatedImageInternal;
    struct AnimatedImageInternal* ptr;
};
#endif //NO_IMGUIVARIOUSCONTROLS_ANIMATEDIMAGE

// zoomCenter is panning in [(0,0),(1,1)]
// returns true if some user interaction have been processed
IMGUI_API bool ImageZoomAndPan(ImTextureID user_texture_id, const ImVec2& size,float aspectRatio,float& zoom,ImVec2& zoomCenter,int panMouseButtonDrag=1,int resetZoomAndPanMouseButton=2,const ImVec2& zoomMaxAndZoomStep=ImVec2(16.f,1.025f));

// USAGE:
/*
// Nobody will use this, it's too complicated to set up. However:

            static bool closed = false;                 // Notable exception to this rule: "use static booleans only when the button is togglable".
            bool paste = false,copy = false;
            if (!closed)    {
                static bool myTreeNodeIsOpen = false;   // 'static' here, just to reuse its address as id...
                const void* ptr_id = &myTreeNodeIsOpen;
                const float curPosX = ImGui::GetCursorPosX();   // used for clipping
                ImGui::BeginGroup();    // Not sure grouping is strictly necessary here
                myTreeNodeIsOpen = ImGui::TreeNodeEx(ptr_id,(ImGuiTreeNodeFlags_CollapsingHeader & (~ImGuiTreeNodeFlags_NoTreePushOnOpen))|ImGuiTreeNodeFlags_AllowOverlapMode,"Collapsable %d",1);
                //if (ImGui::IsItemHovered()) // optional condition if we want buttons to appear only when the collapsable header is hovered
                {
                    ImGui::AppendTreeNodeHeaderButtons(ptr_id,curPosX,
                        3,                                // Num Buttons
                        &closed,"delete",NULL,0,      // Button 0 (far-right) quartet:        &pressed | tooltip | single glyph as const char* (if NULL it's a close button) | isToggleButton?1:0
                        &paste,"paste","v",0,         // Button 1 (second far-right) quartet: &pressed | tooltip | single glyph as const char* (if NULL it's a close button) | isToggleButton?1:0
                        &copy,"copy","^",0            // Button 2 (third far-right) quartet:  &pressed | tooltip | single glyph as const char* (if NULL it's a close button) | isToggleButton?1:0
                    );  // return value non-negative if one button is hovered or clicked, so that you can prevent the 'tree node header' tooltip to show up if you use it.
                    // return value can be: -1 => No button is hovered or clicked | [0,numButtons-1] => buttons[rv] has been clicked | [numButtons,2*numButtons-1] => buttons[rv-numButtons] is hovered
                }
                if (myTreeNodeIsOpen) {
                    // (optional) Fill the header with data within tree node indent
                }
                if (myTreeNodeIsOpen) ImGui::TreePop();   // Mandatory when we want to close the indent (before or after filling the header with data)
                if (myTreeNodeIsOpen) {
                    // (optional) Fill the header with data without tree node indent
                    static ImVec4 color(1,1,1,1);ImGui::ColorEdit4("MyColor##AppendTreeNodeHeaderButtonsMyColor",&color.x);
                }
                ImGui::EndGroup();    // Not sure grouping is strictly necessary here
            }
            else if (ImGui::Button("Reset collapsable header##AppendTreeNodeHeaderButtonsReset")) closed = false;
*/
// Return value rv can be: -1 => No button is hovered or clicked | [0,numButtons-1] => buttons[rv] has been clicked | [numButtons,2*numButtons-1] => buttons[rv-numButtons] is hovered
IMGUI_API int AppendTreeNodeHeaderButtons(const void* ptr_id, float startWindowCursorXForClipping, int numButtons, ...);

// Returns the hovered value index WITH 'values_offset' ( (hovered_index+values_offset)%values_offset or -1). The index of the hovered histogram can be retrieved through 'pOptionalHoveredHistogramIndexOut'.
IMGUI_API int PlotHistogram(const char* label, const float** values,int num_histograms,int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0,0), int stride = sizeof(float),float histogramGroupSpacingInPixels=0.f,int* pOptionalHoveredHistogramIndexOut=NULL,float fillColorGradientDeltaIn0_05=0.05f,const ImU32* pColorsOverride=NULL,int numColorsOverride=0);
IMGUI_API int PlotHistogram(const char* label, float (*values_getter)(void* data, int idx,int histogramIdx), void* data,int num_histograms, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0,0),float histogramGroupSpacingInPixels=0.f,int* pOptionalHoveredHistogramIndexOut=NULL,float fillColorGradientDeltaIn0_05=0.05f,const ImU32* pColorsOverride=NULL,int numColorsOverride=0);
// Shortcut for a single histogram to ease user code a bit (same signature as one of the 2 default Dear ImGui PlotHistogram(...) methods):
IMGUI_API int PlotHistogram2(const char* label, const float* values,int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0,0), int stride = sizeof(float),float fillColorGradientDeltaIn0_05=0.05f,const ImU32* pColorsOverride=NULL,int numColorsOverride=0);

// This one plots a generic function (or multiple functions together) of a float single variable.
// Returns the index of the hovered curve (or -1).
// Passing rangeX.y = FLT_MAX should ensure that the aspect ratio between axis is correct.
// By doubling 'precisionInPixels', we halve the times 'values_getter' gets called.
// 'numGridLinesHint' is currently something we must still fix. Set it to zero to hide lines.
IMGUI_API int PlotCurve(const char* label, float (*values_getter)(void* data, float x,int numCurve), void* data,int num_curves,const char* overlay_text,const ImVec2 rangeY,const ImVec2 rangeX=ImVec2(-.1f,FLT_MAX), ImVec2 graph_size=ImVec2(0,0),ImVec2* pOptionalHoveredValueOut=NULL,float precisionInPixels=1.f,float numGridLinesHint=4.f,const ImU32* pColorsOverride=NULL,int numColorsOverride=0);

// These 2 have a completely different implementation:
// Posted by @JaapSuter and @maxint (please see: https://github.com/ocornut/imgui/issues/632)
IMGUI_API void PlotMultiLines(
    const char* label,
    int num_datas,
    const char** names,
    const ImColor* colors,
    float(*getter)(const void* data, int idx),
    const void * const * datas,
    int values_count,
    float scale_min,
    float scale_max,
    ImVec2 graph_size);

// Posted by @JaapSuter and @maxint (please see: https://github.com/ocornut/imgui/issues/632)
IMGUI_API void PlotMultiHistograms(
    const char* label,
    int num_hists,
    const char** names,
    const ImColor* colors,
    float(*getter)(const void* data, int idx),
    const void * const * datas,
    int values_count,
    float scale_min,
    float scale_max,
    ImVec2 graph_size);


class InputTextWithAutoCompletionData  {
    protected:
    // auto completion:
    int deltaTTItems;                           // modified by UP/DOWN keys
    bool tabPressed;                            // triggers autocompletion
    ImVector<char> newTextToSet;                // needed because ImGui does not allow changing an InputText(...) buffer directly, while it's active
    int itemPositionOfReturnedText;
    int itemIndexOfReturnedText;
    int additionalFlags,bufTextLen,lastSelectedTTItemIndex;
    bool inited;                                // turns true the first time a method that use this class is called

    public:
    int currentAutocompletionItemIndex;         // completely user-side (if!=-1, that item is displayed in a different way in the autocompletion menu)
    InputTextWithAutoCompletionData(ImGuiInputTextFlags _additionalFlags=0,int _currentAutocompletionItemIndex=-1) : deltaTTItems(0),tabPressed(false),itemPositionOfReturnedText(-1),itemIndexOfReturnedText(-1),
    additionalFlags(_additionalFlags&(ImGuiInputTextFlags_CharsDecimal|ImGuiInputTextFlags_CharsHexadecimal|ImGuiInputTextFlags_CharsNoBlank|ImGuiInputTextFlags_CharsUppercase)),bufTextLen(-1),lastSelectedTTItemIndex(-1),
    inited(false),currentAutocompletionItemIndex(_currentAutocompletionItemIndex) {}

    bool isInited() const {return inited;}      // added just for my laziness (to init elements inside DrawGL() of similiar)
    int getItemPositionOfReturnedText() const {return itemPositionOfReturnedText;}  // usable only after "return" is pressed: it returns the item position at which the newly entered text can be inserted, or -1
    int getItemIndexOfReturnedText() const {return itemIndexOfReturnedText;}        // usable only after "return" is pressed: it returns the item index that exactly matches the newly entered text, or -1

    static float Opacity;   // 0.6f;

    friend bool InputTextWithAutoCompletion(const char* label, char* buf, size_t buf_size,InputTextWithAutoCompletionData* pAutocompletion_data, bool (*autocompletion_items_getter)(void*, int, const char**), int autocompletion_items_size, void* autocompletion_user_data, int num_visible_autocompletion_items);
    friend int DefaultInputTextAutoCompletionCallback(ImGuiTextEditCallbackData *data);

    // Some useful helper methods
    IMGUI_API static int HelperGetItemInsertionPosition(const char* txt,bool (*items_getter)(void*, int, const char**), int items_count, void* user_data=NULL,bool* item_is_already_present_out=NULL);
    IMGUI_API static int HelperInsertItem(const char* txt,bool (*items_getter)(void*, int, const char**),bool (*items_inserter)(void*, int,const char*), int items_count, void* user_data=NULL,bool* item_is_already_present_out=NULL);
};
IMGUI_API bool InputTextWithAutoCompletion(const char* label, char* buf, size_t buf_size, InputTextWithAutoCompletionData* pAutocompletion_data, bool (*autocompletion_items_getter)(void*, int, const char**), int autocompletion_items_size, void* autocompletion_user_data=NULL, int num_visible_autocompletion_items=-1);


class InputComboWithAutoCompletionData : protected InputTextWithAutoCompletionData {
    protected:
    int inputTextShown;
    ImVector<char> buf;
    bool isRenaming;
    bool itemHovered,itemActive;
    public:
    InputComboWithAutoCompletionData(ImGuiInputTextFlags additionalInputTextFlags=0) : InputTextWithAutoCompletionData(additionalInputTextFlags),inputTextShown(0),isRenaming(false),itemHovered(false),itemActive(false) {}

    bool isInited() const {return inited;}              // added just for my laziness (to init elements inside DrawGL() of similiar)
    bool isItemHovered() const {return itemHovered;}    // well, this widget is made of 2 widgets with buttons, so ImGui::IsItemHovered() does not always work
    bool isItemActive() const {return itemActive;}      // well, this widget is made of 2 widgets with buttons, so ImGui::IsItemActive() does not always work
    bool isInputTextVisibleNextCall() const {return inputTextShown!=0;}
    const char* getInputTextBuffer() const {return buf.size()>0 ? &buf[0] : NULL;}

    static char ButtonCharcters[3][5];  // = {"+","r","x"};
    static char ButtonTooltips[3][128]; // = {"add","rename","delete"};

    friend bool InputComboWithAutoCompletion(const char* label, int *current_item, size_t autocompletion_buffer_size, InputComboWithAutoCompletionData* pAutocompletion_data,
                                  bool (*items_getter)(void*, int, const char**),       // gets item at position ... (cannot be NULL)
                                  bool (*items_inserter)(void*, int,const char*),       // inserts item at position ... (cannot be NULL)
                                  bool (*items_deleter)(void*, int),                    // deletes item at position ... (can be NULL)
                                  bool (*items_renamer)(void *, int, int, const char *),// deletes item at position, and inserts renamed item at new position  ... (can be NULL)
                                  int items_count, void* user_data, int num_visible_items);
};
IMGUI_API bool InputComboWithAutoCompletion(const char* label,int* current_item,size_t autocompletion_buffer_size,InputComboWithAutoCompletionData* pAutocompletion_data,
    bool (*items_getter)(void*, int, const char**),  // gets item at position ... (cannot be NULL)
    bool (*items_inserter)(void*, int,const char*),  // inserts item at position ... (cannot be NULL)
    bool (*items_deleter)(void*, int),               // deletes item at position ... (can be NULL)
    bool (*items_renamer)(void*,int,int,const char*),// deletes item at position, and inserts renamed item at new position  ... (can be NULL)
    int items_count, void* user_data=NULL, int num_visible_items=-1);


// Basic tree view implementation
// TODO: See if we can switch context-menu with a single-shot RMB click (when a menu is already open)
class TreeViewNode {
protected:
    friend class TreeView;
    friend struct MyTreeViewHelperStruct;
public:
    enum State {
        STATE_NONE      = 0,
        STATE_OPEN      = 1,
        STATE_SELECTED  = 1<<2,
        STATE_CHECKED   = 1<<3,
        STATE_DEFAULT   = 1<<4,     // user state (but its look is hard-coded)
        STATE_DISABLED  = 1<<5,     // user state (but its look is hard-coded)
        STATE_FORCE_CHECKBOX  = 1<<6, // checkbox always visible (even if disabled in its TreeView)
        STATE_HIDDEN    = 1<<7,       // node (and its child nodes) not visible at all

        // user states (without any specific look)
        STATE_USER5     = 1<<8,

        // user states (but its look can be set in TreeView::getTextColorForStateColor(...))
        STATE_COLOR1    = 1<<9,
        STATE_COLOR2    = 1<<10,    // STATE_COLOR1 wins on it (but only as far as the look is concerned)
        STATE_COLOR3    = 1<<11,    // STATE_COLOR1 and STATE_COLOR2 win on it (but only as far as the look is concerned)

        // user states (without any specific look)
        STATE_USER1     = 1<<12,
        STATE_USER2     = 1<<13,
        STATE_USER3     = 1<<14,
        STATE_USER4     = 1<<15
    };
    mutable int state;

    enum Mode {
        MODE_NONE = 0,

        MODE_ROOT = 1,
        MODE_INTERMEDIATE = 2,
        MODE_LEAF = 4,

        MODE_ROOT_INTERMEDIATE = 3,
        MODE_ROOT_LEAF = 5,
        MODE_INTERMEDIATE_LEAF = 6,
        MODE_ALL = 7,
    };

    enum EventType {
        EVENT_NONE = 0,
        EVENT_STATE_CHANGED,
        EVENT_DOUBLE_CLICKED,
        EVENT_RENAMED
    };
    struct Event {
        TreeViewNode* node;
        EventType type;
        State state;bool wasStateRemoved;
        Event() {set();}
        inline void reset() {set();}
        inline void set(TreeViewNode* _node=NULL,EventType _type=EVENT_NONE,State _state=STATE_NONE,bool _wasStateRemoved=false)    {node=_node;type=_type;state=_state;wasStateRemoved=_wasStateRemoved;}
    };

    struct Data {
        char* displayName;      // can't be NULL (it's set to "" when NULL)
        char* tooltip;          // optional (can be NULL)
        char* userText;         // user stuff, optional (can be NULL)
        int   userId;           // user stuff
        Data(const char* _displayedName=NULL,const char* _tooltip=NULL,const char* _userText=NULL,const int _id=0) : displayName(NULL),tooltip(NULL),userText(NULL),userId(0) {
            set(_displayedName,_tooltip,_userText,_id);
        }
        Data(const Data& o) : displayName(NULL),tooltip(NULL),userText(NULL),userId(0) {*this=o;}
        ~Data() {
            if (displayName){ImGui::MemFree(displayName);displayName=NULL;}
            if (tooltip)    {ImGui::MemFree(tooltip);tooltip=NULL;}
            if (userText)   {ImGui::MemFree(userText);userText=NULL;}
            userId=0;
        }
        void set(const char* _displayName=NULL,const char* _tooltip=NULL,const char* _userText=NULL,const int _id=0) {
            SetString(displayName,_displayName,false);
            SetString(tooltip,_tooltip,true);
            SetString(userText,_userText,true);
            userId = _id;
        }        
        inline static void SetString(char*& destText,const char* text,bool allowNullDestText=true) {
            if (destText) {ImGui::MemFree(destText);destText=NULL;}
            const char e = '\0';
            if (!text && !allowNullDestText) text=&e;
            if (text)  {
                const int sz = strlen(text);
                destText = (char*) ImGui::MemAlloc(sz+1);strcpy(destText,text);
            }
        }       
        const Data& operator=(const Data& o) {
            set(o.displayName,o.tooltip,o.userText,o.userId);
            return *this;
        }
    };


protected:

    IMGUI_API static TreeViewNode* CreateNode(const Data& _data,TreeViewNode* _parentNode=NULL,int nodeIndex=-1,bool addEmptyChildNodeVector=false);

    IMGUI_API void render(void *ptr, int numIndents=1);

public:

    inline TreeViewNode* addChildNode(const Data& _data,int nodeIndex=-1,bool addEmptyChildNodeVector=false)    {
        return CreateNode(_data,this,nodeIndex,addEmptyChildNodeVector);
    }
    inline TreeViewNode* addSiblingNode(const Data& _data,int parentNodeIndex=-1)    {
        IM_ASSERT(parentNode);
        return CreateNode(_data,parentNode,parentNodeIndex);
    }
    IMGUI_API static void DeleteNode(TreeViewNode* n);

    IMGUI_API class TreeView& getTreeView();              // slightly slow
    IMGUI_API const class TreeView& getTreeView() const;  // slightly slow
    IMGUI_API TreeViewNode* getParentNode();
    IMGUI_API const TreeViewNode* getParentNode() const;
    IMGUI_API int getNodeIndex() const;
    IMGUI_API void moveNodeTo(int nodeIndex);
    inline bool isLeafNode() const {return childNodes==NULL;}       // Please note that non-leaf nodes can have childNodes->size()==0
    inline bool isRootNode() const {return !parentNode || !parentNode->parentNode;}
    inline int getNumChildNodes() const {return childNodes ? childNodes->size() : 0;}
    inline TreeViewNode* getChildNode(int index=0) {return (childNodes && childNodes->size()>index) ? (*childNodes)[index] : NULL;}
    inline const TreeViewNode* getChildNode(int index=0) const {return (childNodes && childNodes->size()>index) ? (*childNodes)[index] : NULL;}
    IMGUI_API void deleteAllChildNodes(bool leaveEmptyChildNodeVector=false);
    IMGUI_API void addEmptyChildNodeVector();         // Only works if "childNodes==NULL" (and allocates it)
    IMGUI_API void removeEmptyChildNodeVector();      // Only works if (childNodes->size()==0" (and deallocates it)
    IMGUI_API int getNumSiblings(bool includeMe=true) const;
    IMGUI_API TreeViewNode* getSiblingNode(int nodeIndexInParentHierarchy=-1);
    IMGUI_API const TreeViewNode* getSiblingNode(int nodeIndexInParentHierarchy=-1) const;
    IMGUI_API int getDepth() const;   // root nodes have depth = 0

    IMGUI_API static void Swap(TreeViewNode*& n1,TreeViewNode*& n2); // untested
    IMGUI_API void startRenamingMode();       // starts renaming the node
    IMGUI_API bool isInRenamingMode() const;

    IMGUI_API void sortChildNodes(bool recursive,int (*comp)(const void *, const void *));
    IMGUI_API void sortChildNodesByDisplayName(bool recursive=false,bool reverseOrder=false);
    IMGUI_API void sortChildNodesByTooltip(bool recursive=false,bool reverseOrder=false);
    IMGUI_API void sortChildNodesByUserText(bool recursive=false,bool reverseOrder=false);
    IMGUI_API void sortChildNodesByUserId(bool recursive=false,bool reverseOrder=false);

    inline void addState(int stateFlag) const {state|=stateFlag;}
    inline void removeState(int stateFlag) const {state&=~stateFlag;}
    inline void toggleState(int stateFlag) const {state^=stateFlag;}
    inline bool isStatePresent(int stateFlag) const {return ((state&stateFlag)==stateFlag);}
    inline bool isStateMissing(int stateFlag) const {return ((state&stateFlag)!=stateFlag);}

    IMGUI_API void addStateToAllChildNodes(int stateFlag, bool recursive = false) const;
    IMGUI_API void removeStateFromAllChildNodes(int stateFlag, bool recursive = false) const;
    IMGUI_API bool isStatePresentInAllChildNodes(int stateFlag) const;
    IMGUI_API bool isStateMissingInAllChildNodes(int stateFlag) const;

    void addStateToAllDescendants(int stateFlag) const {addStateToAllChildNodes(stateFlag,true);}
    void removeStateFromAllDescendants(int stateFlag) const {removeStateFromAllChildNodes(stateFlag,true);}
    IMGUI_API bool isStatePresentInAllDescendants(int stateFlag) const;
    IMGUI_API bool isStateMissingInAllDescendants(int stateFlag) const;

    // These return the first matching parentNode (if "recursive==false" they return node->parentNode or NULL).
    IMGUI_API TreeViewNode* getFirstParentNodeWithState(int stateFlag,bool recursive=true);
    IMGUI_API const TreeViewNode* getFirstParentNodeWithState(int stateFlag,bool recursive=true) const;
    IMGUI_API TreeViewNode* getFirstParentNodeWithoutState(int stateFlag,bool recursive=true);
    IMGUI_API const TreeViewNode* getFirstParentNodeWithoutState(int stateFlag,bool recursive=true) const;

    // if "recursive==true" deleting the "result nodes" in order shouldn't work, but probably it works in the reverse order (TO TEST)
    IMGUI_API void getAllChildNodesWithState(ImVector<TreeViewNode*>& result,int stateFlag,bool recursive = false, bool returnOnlyLeafNodes=false, bool clearResultBeforeUsage=true) const;
    IMGUI_API void getAllChildNodesWithoutState(ImVector<TreeViewNode*>& result,int stateFlag,bool recursive = false, bool returnOnlyLeafNodes=false, bool clearResultBeforeUsage=true) const;
    IMGUI_API void getAllChildNodes(ImVector<TreeViewNode*>& result,bool recursive = false,bool returnOnlyLeafNodes=false,bool clearResultBeforeUsage=true) const;

    // Deleting the "result nodes" in order shouldn't work, but probably it works in the reverse order (TO TEST)
    void getAllDescendants(ImVector<TreeViewNode*>& result,bool clearResultBeforeUsage=true) const {return getAllChildNodes(result,true,false,clearResultBeforeUsage);}
    void getAllDescendantsWithState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllChildNodesWithState(result,stateFlag,true,false,clearResultBeforeUsage);}
    void getAllDescendantsWithoutState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllChildNodesWithoutState(result,stateFlag,true,false,clearResultBeforeUsage);}

    // Deleting the "result nodes" in order shouldn't work, but probably it works in the reverse order (TO TEST)
    void getAllLeafNodes(ImVector<TreeViewNode*>& result,bool clearResultBeforeUsage=true) const {return getAllChildNodes(result,true,true,clearResultBeforeUsage);}
    void getAllLeafNodesWithState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllChildNodesWithState(result,stateFlag,true,true,clearResultBeforeUsage);}
    void getAllLeafNodesWithoutState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllChildNodesWithoutState(result,stateFlag,true,true,clearResultBeforeUsage);}

    // To remove
/*
    void dbgDisplay(const int indent = 0) const {
        for (int i=0;i<indent;i++) printf(" ");
        printf("%s (%s) (%d) [parent=%s]\n",data.displayName?data.displayName:"NULL",data.text?data.text:"NULL",data.id,parentNode?(parentNode->data.displayName):"NULL");
        if (childNodes && childNodes->size()>0) {
            for (int i=0;i<childNodes->size();i++) {
                TreeViewNode* n = (*childNodes)[i];
                if (n) {n->dbgDisplay(indent+3);}
            }
        }
    }
*/

    // "data" accessors
    inline const char* getDisplayName() const {return data.displayName;}
    inline void setDisplayName(const char* _displayName) {Data::SetString(data.displayName,_displayName,false);}
    inline const char* getTooltip() const {return data.tooltip;}
    inline void setTooltip(const char* _tooltip) {Data::SetString(data.tooltip,_tooltip,true);}
    inline const char* getUserText() const {return data.userText;}
    inline void setUserText(const char* _userText) {Data::SetString(data.userText,_userText,true);}
    inline int& getUserId() {return data.userId;}
    inline const int& getUserId() const {return data.userId;}
    inline void setUserId(int uid) {data.userId=uid;}




    void *userPtr;  // Not mine

protected:

    IMGUI_API TreeViewNode(const TreeViewNode::Data& _data=TreeViewNode::Data(), TreeViewNode* _parentNode=NULL, int nodeIndex=-1, bool addEmptyChildNodeVector=false);
    IMGUI_API virtual ~TreeViewNode();

    Data data;

    TreeViewNode* parentNode;
    ImVector<TreeViewNode*>* childNodes;

    inline unsigned int getMode() const {
        int m = MODE_NONE;if (childNodes==NULL) m|=MODE_LEAF;
        if (!parentNode || !parentNode->parentNode) m|=MODE_ROOT;
        if (m==MODE_NONE) m = MODE_INTERMEDIATE;return m;
    }
    inline static bool MatchMode(unsigned int m,unsigned int nodeM) {
        // Hp) nodeM can't be MODE_NONE
        return (m==MODE_ALL || (m!=MODE_NONE && (m&nodeM)));
    }

protected:
    TreeViewNode(const TreeViewNode&) {}
    void operator=(const TreeViewNode&) {}
};

class TreeView : protected TreeViewNode {
protected:
friend class TreeViewNode;
friend struct MyTreeViewHelperStruct;
public:

    IMGUI_API TreeView(Mode _selectionMode=MODE_ALL,bool _allowMultipleSelection=false,Mode _checkboxMode=MODE_NONE,bool _allowAutoCheckboxBehaviour=true,bool _inheritDisabledLook=true);
    IMGUI_API virtual ~TreeView();
    bool isInited() {return inited;}
    IMGUI_API bool render();  // Main method (makes inited = true). Returns "lastEvent", containing the node that's changed in some way (e.g. double-clicked, end-edited or basic state changed)
    inline Event& getLastEvent() const {return lastEvent;}

    inline int getNumRootNodes() const {return childNodes->size();}
    inline TreeViewNode* getRootNode(int index=0) {return ((childNodes->size()>index) ? (*childNodes)[index] : NULL);}
    inline const TreeViewNode* getRootNode(int index=0) const {return ((childNodes->size()>index) ? (*childNodes)[index] : NULL);}

    inline TreeViewNode* addRootNode(const TreeViewNode::Data& _data,int nodeIndex=-1,bool addEmptyChildNodeVector=false)    {
        return TreeViewNode::CreateNode(_data,this,nodeIndex,addEmptyChildNodeVector);
    }
    inline static void DeleteNode(TreeViewNode* n) {TreeViewNode::DeleteNode(n);}    

    IMGUI_API void clear();

    // sorting
    void sortRootNodes(bool recursive,int (*comp)(const void *, const void *))  {TreeViewNode::sortChildNodes(recursive,comp);}
    void sortRootNodesByDisplayName(bool recursive=false,bool reverseOrder=false) {TreeViewNode::sortChildNodesByDisplayName(recursive,reverseOrder);}
    void sortRootNodesByTooltip(bool recursive=false,bool reverseOrder=false) {TreeViewNode::sortChildNodesByTooltip(recursive,reverseOrder);}
    void sortRootNodesByUserText(bool recursive=false,bool reverseOrder=false) {TreeViewNode::sortChildNodesByUserText(recursive,reverseOrder);}
    void sortRootNodesByUserId(bool recursive=false,bool reverseOrder=false) {TreeViewNode::sortChildNodesByUserId(recursive,reverseOrder);}

    // state
    void addStateToAllRootNodes(int stateFlag, bool recursive = false) const {TreeViewNode::addStateToAllChildNodes(stateFlag,recursive);}
    void removeStateFromAllRootNodes(int stateFlag, bool recursive = false) const {TreeViewNode::removeStateFromAllChildNodes(stateFlag,recursive);}
    bool isStatePresentInAllRootNodes(int stateFlag) const {return TreeView::isStatePresentInAllChildNodes(stateFlag);}
    bool isStateMissingInAllRootNodes(int stateFlag) const {return TreeView::isStateMissingInAllChildNodes(stateFlag);}

    // These methods are related to the whole node hierarchy
    void addStateToAllDescendants(int stateFlag) const {TreeViewNode::addStateToAllDescendants(stateFlag);}
    void removeStateFromAllDescendants(int stateFlag) const {TreeViewNode::removeStateFromAllDescendants(stateFlag);}
    bool isStatePresentInAllDescendants(int stateFlag) const {return TreeViewNode::isStatePresentInAllDescendants(stateFlag);}
    bool isStateMissingInAllDescendants(int stateFlag) const {return TreeViewNode::isStateMissingInAllDescendants(stateFlag);}

    // if "recursive==true" deleting the "result nodes" in order shouldn't work, but probably it works in the reverse order (TO TEST)
    void getAllRootNodesWithState(ImVector<TreeViewNode*>& result,int stateFlag,bool recursive = false, bool returnOnlyLeafNodes=false,bool clearResultBeforeUsage=true) const {TreeViewNode::getAllChildNodesWithState(result,stateFlag,recursive,returnOnlyLeafNodes,clearResultBeforeUsage);}
    void getAllRootNodesWithoutState(ImVector<TreeViewNode*>& result,int stateFlag,bool recursive = false, bool returnOnlyLeafNodes=false,bool clearResultBeforeUsage=true) const {TreeViewNode::getAllChildNodesWithoutState(result,stateFlag,recursive,returnOnlyLeafNodes,clearResultBeforeUsage);}
    void getAllRootNodes(ImVector<TreeViewNode*>& result,bool recursive = false,bool returnOnlyLeafNodes=false,bool clearResultBeforeUsage=true) const {TreeViewNode::getAllChildNodes(result,recursive,returnOnlyLeafNodes,clearResultBeforeUsage);}

    // deleting the "result nodes" in order shouldn't work, but probably it works in the reverse order (TO TEST)
    void getAllNodes(ImVector<TreeViewNode*>& result,bool clearResultBeforeUsage=true) const {return getAllRootNodes(result,true,false,clearResultBeforeUsage);}
    void getAllNodesWithState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllRootNodesWithState(result,stateFlag,true,false,clearResultBeforeUsage);}
    void getAllLeafNodesWithoutState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllRootNodesWithoutState(result,stateFlag,true,true,clearResultBeforeUsage);}

    // deleting the "result nodes" in order shouldn't work, but probably it works in the reverse order (TO TEST)
    void getAllLeafNodes(ImVector<TreeViewNode*>& result,bool clearResultBeforeUsage=true) const {return getAllRootNodes(result,true,true,clearResultBeforeUsage);}
    void getAllLeafNodesWithState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllRootNodesWithState(result,stateFlag,true,true,clearResultBeforeUsage);}
    void getAllNodesWithoutState(ImVector<TreeViewNode*>& result,int stateFlag,bool clearResultBeforeUsage=true) const {return getAllRootNodesWithoutState(result,stateFlag,true,false,clearResultBeforeUsage);}

    // -1 = disabled. When >= 0 if node->getDepth()==collapseToLeafNodesAtNodeDepth the hierarchy is flattened to leaf nodes
    void setCollapseNodesToLeafNodesAtDepth(int nodeDepth) const {collapseToLeafNodesAtNodeDepth=nodeDepth;}
    int getCollapseNodesToLeafNodesAtDepth() const {return collapseToLeafNodesAtNodeDepth;}

    // Callbacks:
    typedef void (*TreeViewNodeCallback)(TreeViewNode* node,TreeView& parent,void* userPtr);
    void setTreeViewNodePopupMenuDrawerCb(TreeViewNodeCallback cb,void* userPtr=NULL) {treeViewNodePopupMenuDrawerCb = cb;treeViewNodePopupMenuDrawerCbUserPtr = userPtr;}
    inline TreeViewNodeCallback getTreeViewNodePopupMenuDrawerCb() const {return treeViewNodePopupMenuDrawerCb;}
    inline static const char* GetTreeViewNodePopupMenuName() {return "TreeViewNodePopupMenu";}  // you can use this name inside the callback: e.g. ImGui::BeginPopup(ImGui::TreeView::GetTreeViewNodePopupMenuName());
    // must return true if icon is hovered. If set, use ImGui::SameLine() before returning
    typedef bool (*TreeViewNodeDrawIconCallback)(TreeViewNode* node,TreeView& parent,void* userPtr);
    void setTreeViewNodeDrawIconCb(TreeViewNodeDrawIconCallback cb,void* userPtr=NULL) {treeViewNodeDrawIconCb = cb;treeViewNodeDrawIconCbUserPtr = userPtr;}
    inline TreeViewNodeDrawIconCallback getTreeViewNodeDrawIconCb() const {return treeViewNodeDrawIconCb;}
    // just called after all rendering in this node (can be used to append stuff at the right of the line)
    typedef void (*TreeViewNodeAfterDrawCallback)(TreeViewNode* node,TreeView& parent,float windowWidth,void* userPtr);
    void setTreeViewNodeAfterDrawCb(TreeViewNodeAfterDrawCallback cb,void* userPtr=NULL) {treeViewNodeAfterDrawCb = cb;treeViewNodeAfterDrawCbUserPtr = userPtr;}
    inline TreeViewNodeAfterDrawCallback getTreeViewNodeAfterDrawCb() const {return treeViewNodeAfterDrawCb;}
    // called after a node is created and before it's deleted (usable for TreeViewNode::userPtrs)
    typedef void (*TreeViewNodeCreationDelationCallback)(TreeViewNode* node,TreeView& parent,bool delation,void* userPtr);
    void setTreeViewNodeCreationDelationCb(TreeViewNodeCreationDelationCallback cb,void* userPtr=NULL) {treeViewNodeCreationDelationCb = cb;treeViewNodeCreationDelationCbUserPtr = userPtr;}
    inline TreeViewNodeCreationDelationCallback getTreeViewNodeCreationDelationCb() const {return treeViewNodeCreationDelationCb;}


    void *userPtr;                  // user stuff, not mine

    IMGUI_API ImVec4* getTextColorForStateColor(int aStateColorFlag) const;
    IMGUI_API ImVec4* getTextDisabledColorForStateColor(int aStateColorFlag) const;

    IMGUI_API void setTextColorForStateColor(int aStateColorFlag,const ImVec4& textColor,float disabledTextColorAlphaFactor=0.5f) const;

//-------------------------------------------------------------------------------
#       if (defined(IMGUIHELPER_H_) && !defined(NO_IMGUIHELPER_SERIALIZATION))
#       ifndef NO_IMGUIHELPER_SERIALIZATION_SAVE
public:
        IMGUI_API bool save(ImGuiHelper::Serializer& s);
        IMGUI_API bool save(const char* filename);
        IMGUI_API static bool Save(const char* filename, TreeView **pTreeViews, int numTreeviews);
#       endif //NO_IMGUIHELPER_SERIALIZATION_SAVE
#       ifndef NO_IMGUIHELPER_SERIALIZATION_LOAD
public:
        IMGUI_API bool load(ImGuiHelper::Deserializer& d,const char** pOptionalBufferStart=NULL);
        IMGUI_API bool load(const char* filename);
        IMGUI_API static bool Load(const char* filename,TreeView** pTreeViews,int numTreeviews);
#       endif //NO_IMGUIHELPER_SERIALIZATION_LOAD
#       endif //NO_IMGUIHELPER_SERIALIZATION
//--------------------------------------------------------------------------------

    IMGUI_API static void SetFontCheckBoxGlyphs(const char* emptyState,const char* fillState);
    static inline bool HasCustomCheckBoxGlyphs() {return FontCheckBoxGlyphs[0][0]!='\0';}
    IMGUI_API static void SetFontArrowGlyphs(const char* leftArrow,const char* downArrow);
    static inline bool HasCustomArrowGlyphs() {return FontArrowGlyphs[0][0]!='\0';}


    // TODO: Fix stuff in this area ------------------------------------------------
    // we leave these public...     // to make protected
    unsigned int selectionMode;     // it SHOULD be a TreeViewNode::Mode, but we use a uint to fit ImGui::ComboFlag(...) directly (to change)
    bool allowMultipleSelection;

    unsigned int checkboxMode;
    bool allowAutoCheckboxBehaviour;

    bool inheritDisabledLook;   // Not the STATE_DISABLED flag! Just the look. (Can we replace it with a unsigned int for generic state look-inheritance?)
    //------------------------------------------------------------------------------

protected:
    TreeViewNodeCallback treeViewNodePopupMenuDrawerCb;
    void* treeViewNodePopupMenuDrawerCbUserPtr;
    TreeViewNodeDrawIconCallback treeViewNodeDrawIconCb;
    void* treeViewNodeDrawIconCbUserPtr;
    TreeViewNodeAfterDrawCallback treeViewNodeAfterDrawCb;
    void* treeViewNodeAfterDrawCbUserPtr;
    TreeViewNodeCreationDelationCallback treeViewNodeCreationDelationCb;
    void* treeViewNodeCreationDelationCbUserPtr;

    bool inited;
    mutable ImVec4 stateColors[6];  // 3 pairs of textColor-textDisabledColor

    mutable Event lastEvent;

    static char FontCheckBoxGlyphs[2][5];
    static char FontArrowGlyphs[2][5];

    mutable int collapseToLeafNodesAtNodeDepth; // -1 = disabled. When >= 0 if node->getDepth()>=collapseToLeafNodesAtNodeDepth the hierarchy is flattened to leaf nodes


protected:
    TreeView(const TreeView& tv) : TreeViewNode(tv) {}
    void operator=(const TreeView&) {}
    TreeView(const TreeViewNode&) {}
    void operator=(const TreeViewNode&) {}



};
typedef TreeViewNode::Data TreeViewNodeData;
typedef TreeViewNode::State TreeViewNodeState;
typedef TreeViewNode::Mode TreeViewNodeMode;
typedef TreeViewNode::Event TreeViewEvent;

// Timeline (from: https://github.com/nem0/LumixEngine/blob/timeline_gui/external/imgui/imgui_user.h)=
/* Possible enhancements:
 * Add some kind of "snap to grid" epsilon
 * Add different types of TimelineEvent (e.g. multiple ranges in a single line, dot-like markers, etc.)
*/
// opt_exact_num_rows: optional, when !=0, enables item culling
// popt_offset_and_scale: optional reference to a static ImVec2 (CTRL+RMB drag: pan in [0.f,1.f]; CTRL+MW: zoom in [0.25f,4.f]). Thanks @meshula!
IMGUI_API bool BeginTimeline(const char* str_id, float max_value=0.f, int num_visible_rows=0, int opt_exact_num_rows=0,ImVec2* popt_offset_and_scale=NULL);
IMGUI_API bool TimelineEvent(const char* str_id, float* values, bool keep_range_constant=false);
IMGUI_API void EndTimeline(int num_vertical_grid_lines=5.f,float current_time=0.f,ImU32 timeline_running_color=IM_COL32(0,128,0,200));
// End Timeline ======================================================================================


// mobile lock control: a very unsafe way of using password
// passwordSize: must be: gridSize*gridSize+1, where gridSize is in [2,6]
// size: is the width and height of the widget in pixels
// colors: please copy defaultColors in the definition (.cpp file), and modify it as needed.
typedef int ImGuiPasswordDrawerFlags;
IMGUI_API bool PasswordDrawer(char* password, int passwordSize, ImGuiPasswordDrawerFlags flags=0, const float size=0, const ImU32 colors[7]=NULL);



} // namespace ImGui

enum ImGuiPasswordDrawerFlags_  {
    ImGuiPasswordDrawerFlags_ReadOnly         = 1 << 1,   // password is not touched, it's simply shown. Returns true when the (whole) widget pressed. [Note that passwordSize must still be gridSize*gridSize+1, even if the (untouched) password buffer is shorter]
    ImGuiPasswordDrawerFlags_NoFilledCircles  = 1 << 2,   // Filled circles are hidden
    ImGuiPasswordDrawerFlags_NoLines          = 1 << 4,   // Draw lines are hidden
    ImGuiPasswordDrawerFlags_Hidden           =           // Everything is hidden [to prevent someone from spotting your password]
    ImGuiPasswordDrawerFlags_NoFilledCircles|ImGuiPasswordDrawerFlags_NoLines
};


namespace ImGui {

// Experimental: CheckboxFlags(...) overload to handle multiple flags with a single call
// returns the value of the pressed flag (not the index of the check box), or zero
// flagAnnotations, when!=0, just displays a circle in the required checkboxes
// itemHoveredOut, when used, returns the index of the hovered check box (not its flag), or -1.
// pFlagsValues, when used, must be numFlags long, and must contain the flag values (not the flag indices) that the control must use.
// KNOWN BUG: When ImGui::SameLine() is used after it, the alignment is broken
IMGUI_API unsigned int CheckboxFlags(const char* label,unsigned int* flags,int numFlags,int numRows,int numColumns,unsigned int flagAnnotations=0,int* itemHoveredOut=NULL,const unsigned int* pFlagsValues=NULL);

// These just differ from the default ones for their look:
// checkBoxScale.y max is clamped to 2.f
// pOptionalEightColors are: {circle_on, circle_on_hovered, circle_off, circle_off_hovered, bg_on, bg_on_hovered, bg_off, bg_off_hovered} [The 4 circle colors will have A = 255, even if users choose otherwise]
// checkBoxRounding if negative defaults to style.WindowRounding
IMGUI_API bool CheckboxStyled(const char* label, bool* v, const ImU32 *pOptionalEightColors=NULL, const ImVec2 &checkBoxScale=ImVec2(1.f,1.f), float checkBoxRounding=-1.f);
IMGUI_API bool CheckboxStyledFlags(const char* label, unsigned int* flags, unsigned int flags_value,const ImU32 *pOptionalEightColors=NULL,const ImVec2 &checkBoxScale=ImVec2(1.f,1.f), float checkBoxRounding=-1.f);

// Minimal implementation from: https://github.com/ocornut/imgui/issues/942
IMGUI_API bool KnobFloat(const char* label, float* p_value, float v_min, float v_max, float v_step=50.f);

} // namespace ImGui

#endif
```

