This file is a merged representation of a subset of the codebase, containing specifically included files, combined into a single document by Repomix.

# File Summary

## Purpose
This file contains a packed representation of a subset of the repository's contents that is considered the most important context.
It is designed to be easily consumable by AI systems for analysis, code review,
or other automated processes.

## File Format
The content is organized as follows:
1. This summary section
2. Repository information
3. Directory structure
4. Repository files (if enabled)
5. Multiple file entries, each consisting of:
  a. A header with the file path (## File: path/to/file)
  b. The full contents of the file in a code block

## Usage Guidelines
- This file should be treated as read-only. Any changes should be made to the
  original repository files, not this packed version.
- When processing this file, use the file path to distinguish
  between different files in the repository.
- Be aware that this file may contain sensitive information. Handle it with
  the same level of security as you would the original repository.

## Notes
- Some files may have been excluded based on .gitignore rules and Repomix's configuration
- Binary files are not included in this packed representation. Please refer to the Repository Structure section for a complete list of file paths, including binary files
- Only files matching these patterns are included: RocketStats.cpp, RocketStats.h, Utils.cpp, Utils.h, Languages.h, Managements/OverlayManagement.cpp, Managements/WindowManagement.cpp, Managements/StatsManagement.cpp, Managements/VarsManagement.cpp, Managements/FileManagement.cpp, Libraries/imgui/imgui_additions.cpp, Libraries/imgui/imgui_additions.h, Libraries/imgui/imgui_rotate.cpp, Libraries/imgui/imgui_rotate.h, Libraries/imgui/imgui_rangeslider.cpp, Libraries/imgui/imgui_rangeslider.h, Libraries/imgui/imgui_searchablecombo.cpp, Libraries/imgui/imgui_searchablecombo.h, Libraries/imgui/imgui_timeline.cpp, Libraries/imgui/imgui_timeline.h, Libraries/imgui/imguivariouscontrols.h, Libraries/imgui/imconfig.h, Libraries/fpstimer.hpp, Libraries/resource.hpp
- Files matching patterns in .gitignore are excluded
- Files matching default ignore patterns are excluded
- Files are sorted by Git change count (files with more changes are at the bottom)

# Directory Structure
```
Languages.h
Libraries/fpstimer.hpp
Libraries/imgui/imconfig.h
Libraries/imgui/imgui_additions.cpp
Libraries/imgui/imgui_additions.h
Libraries/imgui/imgui_rangeslider.cpp
Libraries/imgui/imgui_rangeslider.h
Libraries/imgui/imgui_rotate.cpp
Libraries/imgui/imgui_rotate.h
Libraries/imgui/imgui_searchablecombo.cpp
Libraries/imgui/imgui_searchablecombo.h
Libraries/imgui/imgui_timeline.cpp
Libraries/imgui/imgui_timeline.h
Libraries/imgui/imguivariouscontrols.h
Libraries/resource.hpp
Managements/FileManagement.cpp
Managements/OverlayManagement.cpp
Managements/StatsManagement.cpp
Managements/VarsManagement.cpp
Managements/WindowManagement.cpp
RocketStats.cpp
RocketStats.h
Utils.cpp
Utils.h
```

# Files

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

## File: Libraries/fpstimer.hpp
```cpp
#ifndef INCLUDE_FPSTIMER_HPP_
#define INCLUDE_FPSTIMER_HPP_

#include <ctime>

class FPSTimer
{
private:
	bool _wait;
	double _fps;
	double _tick;
	unsigned int _frames;
	timespec _beg, _end;

public:
	FPSTimer(unsigned int fps, bool wait_tick = false)
	{
		_fps = fps;
		_tick = (1. / fps);
		_wait = wait_tick;
		_frames = 0;
		reset();
	}

	double elapsed()
	{
		return (_end.tv_sec - _beg.tv_sec + (_end.tv_nsec - _beg.tv_nsec) / 1000000000.);
	}

	unsigned int frames(bool set = false)
	{
		if (set)
			_frames = int(elapsed() / _tick);

		return _frames;
	}

	unsigned int tick()
	{
		if (_frames > 0)
			_beg = _end;

#ifdef CLOCK_REALTIME
		(void)clock_gettime(CLOCK_REALTIME, &_end);
#else
		(void)timespec_get(&_end, TIME_UTC);
#endif

		if (_wait)
		{
			_beg = _end;
			_wait = false;
		}

		return frames(true);
	}

	void reset()
	{
#ifdef CLOCK_REALTIME
		(void)clock_gettime(CLOCK_REALTIME, &_end);
#else
		(void)timespec_get(&_end, TIME_UTC);
#endif

		_beg = _end;
		_frames = 0;
	}
};

#endif
```

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

## File: Libraries/imgui/imgui_timeline.h
```c
#pragma once
namespace ImGui {

	bool BeginTimeline(const char* str_id, float max_time);
	bool TimelineEvent(const char* str_id, float times[2]);
	void EndTimeline(float current_time = -1);

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

## File: Libraries/resource.hpp
```cpp
#include <span>
#include <windows.h>

using namespace std;

class Resource
{
private:
	HRSRC hResource = nullptr;
	HGLOBAL hMemory = nullptr;

	struct ResourceData
	{
		std::size_t size_bytes = 0;
		void* ptr = nullptr;
	};

	ResourceData p;

public:
	Resource(int resource_id, const char* resource_class, HMODULE module_handle = nullptr)
		: hResource(FindResource(module_handle, MAKEINTRESOURCE(resource_id), __TEXT(resource_class)))
	{
		if (!hResource)
			return;

		hMemory = LoadResource(module_handle, hResource);
		if (!hMemory)
			return;

		p.size_bytes = SizeofResource(module_handle, hResource);
		p.ptr = LockResource(hMemory);
	}

	std::span<const char> GetResource()
	{
		return {static_cast<const char*>(p.ptr), p.size_bytes};
	}
};
```

## File: Managements/FileManagement.cpp
```cpp
#include "../RocketStats.h"

std::string RocketStats::GetPath(std::string _path, bool root)
{
    std::string _return = gameWrapper->GetBakkesModPath().string() + "/";

    if (root)
        _return += _path;
    else
        _return += "data/RocketStats/" + _path;

    return _return;
}

bool RocketStats::ExistsPath(std::string _filename, bool root)
{
    return fs::exists(GetPath(_filename, root));
}

bool RocketStats::RemoveFile(std::string _filename, bool root)
{
    if (!ExistsPath(_filename, root))
        return true;

    try
    {
        return fs::remove(GetPath(_filename, root));
    }
    catch (const std::exception&) {}

    return false;
}

std::string RocketStats::ReadFile(std::string _filename, bool root)
{
    std::string _value = "";
    std::string _path = GetPath(_filename, root);
    if (fs::exists(_path) && fs::is_regular_file(_path) && (fs::status(_path).permissions() & fs::perms::owner_read) == fs::perms::owner_read)
    {
        std::ifstream stream(_path, std::ios::in | std::ios::binary);

        if (stream.is_open())
        {
            std::ostringstream os;
            os << stream.rdbuf();
            _value = os.str();
            stream.close();
        }
        else
            cvarManager->log("Can't read this file: " + _filename);
    }
    else
        cvarManager->log("Bad path: " + _filename);

    return _value;
}

json RocketStats::ReadJSON(std::string _filename, bool root)
{
    cvarManager->log("Read JSON: " + _filename);
    return json::parse(ReadFile(_filename, root));
}

void RocketStats::WriteInFile(std::string _filename, std::string _value, bool root)
{
    std::string _path = GetPath(_filename, root);
    if (!fs::exists(_path) || fs::is_regular_file(_path))
    {
        std::ofstream stream(_path, std::ios::out | std::ios::trunc);

        if (stream.is_open())
        {
            stream << _value;
            stream.close();
        }
        else
        {
            cvarManager->log("Can't write to file: " + _filename);
            cvarManager->log("Value to write was: " + _value);
        }
    }
}

bool RocketStats::WriteResInFile(std::string _filename, int id, const char* type, bool root)
{
    std::string _path = GetPath(_filename, root);
    if (!fs::exists(_path) || fs::is_regular_file(_path))
    {
        Resource res = Resource(id, type, GetModuleHandle("RocketStats"));
        std::span<const char> obj = res.GetResource();

        if (obj.data())
        {
            std::ofstream stream(_path, std::ios::out | std::ios::trunc | std::ios::binary);

            if (stream.is_open())
            {
                stream.write(obj.data(), obj.size());
                stream.close();
                return true;
            }
            else
                cvarManager->log("Can't write to file: " + _filename);
        }
    }

    return false;
}

void RocketStats::MigrateFolder()
{
    // If the old folder exist, copy everything to the new path
    if (ExistsPath("RocketStats", true))
    {
        std::string old_path = GetPath("RocketStats", true);
        fs::copy(old_path, GetPath(), (fs::copy_options::recursive | fs::copy_options::update_existing));
        MigrateRemove();
    }
}

void RocketStats::MigrateRemove()
{
    if (ExistsPath("RocketStats", true))
        fs::remove_all(GetPath("RocketStats", true));

    RemoveFile("RocketStats_Loose.txt"); // Delete the old file
    RemoveFile("RocketStats_images/BoostState.txt"); // Delete the old file
}

void RocketStats::UpdateFiles(bool force)
{
    AllOther(force);
    AllShots(force);
    AllSaves(force);
    AllGoals(force);
    AllDropshot(force);
    AllKnockout(force);
    AllMiscs(force);
    AllAccolades(force);
}

void RocketStats::ResetFiles()
{
    last_rank = "";
    last_division = "";

    AllOther(true, true);
    AllShots(true, true);
    AllSaves(true, true);
    AllGoals(true, true);
    AllDropshot(true, true);
    AllKnockout(true, true);
    AllMiscs(true, true);
    AllAccolades(true, true);
}

bool RocketStats::ReadConfig()
{
    cvarManager->log("===== ReadConfig =====");

    std::string file = "data/rocketstats.json";
    bool exists = ExistsPath(file, true);
    if (exists)
    {
        try
        {
            // Read the plugin settings JSON file
            json config = ReadJSON(file, true);

            if (config.is_object())
            {
                if (config["settings"].is_object() && !config["settings"].is_null())
                {
                    if (config["settings"]["mode"].is_number_unsigned())
                        rs_mode = config["settings"]["mode"];

                    if (config["settings"]["theme"].is_string())
                       SetTheme(config["settings"]["theme"]);

                    if (config["settings"]["overlay"].is_boolean())
                        rs_disp_overlay = config["settings"]["overlay"];

                    if (config["settings"]["GameTheme"].is_string()) {
                        SetGameTheme(config["settings"]["GameTheme"]);
                    }

                    if (config["settings"]["themes"].is_object() && !config["settings"]["themes"].is_null() && config["settings"]["themes"].size())
                    {
                        json tmp = json::object();
                        for (auto it = config["settings"]["themes"].begin(); it != config["settings"]["themes"].end(); ++it)
                        {
                            if (!it.value().is_null())
                            {
                                json ctmp = json::object();
                                for (auto cit = it.value().begin(); cit != it.value().end(); ++cit)
                                {
                                    if (!cit.value().is_null())
                                        ctmp[cit.key()] = cit.value();
                                }

                                if (ctmp.size())
                                    tmp[it.key()] = ctmp;
                            }
                        }

                        if (tmp.size())
                            themes_values = tmp;
                    }

                    if (config["settings"]["inmenu"].is_boolean())
                        rs_enable_inmenu = config["settings"]["inmenu"];
                    if (config["settings"]["enableDualTheme"].is_boolean())
                        dualtheme = config["settings"]["enableDualTheme"];
                    if (config["settings"]["ingame"].is_boolean())
                        rs_enable_ingame = config["settings"]["ingame"];
                    if (config["settings"]["inscoreboard"].is_boolean())
                        rs_enable_inscoreboard = config["settings"]["inscoreboard"];
                    if (config["settings"]["float"].is_boolean())
                        rs_enable_float = config["settings"]["float"];
                    if (config["settings"]["preview"].is_boolean())
                        rs_preview_rank = config["settings"]["preview"];
                    if (config["settings"]["roman"].is_boolean())
                        rs_roman_numbers = config["settings"]["roman"];

                    if (config["settings"]["replace_mmr"].is_boolean())
                        rs_replace_mmr = config["settings"]["replace_mmr"];
                    if (config["settings"]["replace_mmr_cc"].is_boolean())
                        rs_replace_mmr_cc = config["settings"]["replace_mmr_cc"];
                    if (config["settings"]["replace_mmrc"].is_boolean())
                        rs_replace_mmrc = config["settings"]["replace_mmrc"];
                    if (config["settings"]["replace_mmrc_cc"].is_boolean())
                        rs_replace_mmrc_cc = config["settings"]["replace_mmrc_cc"];
                    if (config["settings"]["replace_mmrcc"].is_boolean())
                        rs_replace_mmrcc = config["settings"]["replace_mmrcc"];
                    if (config["settings"]["replace_mmrcc_c"].is_boolean())
                        rs_replace_mmrcc_c = config["settings"]["replace_mmrcc_c"];

                    if (config["settings"]["files"].is_object() && !config["settings"]["files"].is_null())
                    {
                        if (config["settings"]["files"]["on"].is_boolean())
                            rs_in_file = config["settings"]["files"]["on"];
                        if (config["settings"]["files"]["games"].is_boolean())
                            rs_file_games = config["settings"]["files"]["games"];
                        if (config["settings"]["files"]["gm"].is_boolean())
                            rs_file_gm = config["settings"]["files"]["gm"];
                        if (config["settings"]["files"]["rank"].is_boolean())
                            rs_file_rank = config["settings"]["files"]["rank"];
                        if (config["settings"]["files"]["div"].is_boolean())
                            rs_file_div = config["settings"]["files"]["div"];
                        if (config["settings"]["files"]["mmr"].is_boolean())
                            rs_file_mmr = config["settings"]["files"]["mmr"];
                        if (config["settings"]["files"]["mmrc"].is_boolean())
                            rs_file_mmrc = config["settings"]["files"]["mmrc"];
                        if (config["settings"]["files"]["mmrcc"].is_boolean())
                            rs_file_mmrcc = config["settings"]["files"]["mmrcc"];
                        if (config["settings"]["files"]["win"].is_boolean())
                            rs_file_win = config["settings"]["files"]["win"];
                        if (config["settings"]["files"]["loss"].is_boolean())
                            rs_file_loss = config["settings"]["files"]["loss"];
                        if (config["settings"]["files"]["streak"].is_boolean())
                            rs_file_streak = config["settings"]["files"]["streak"];
                        if (config["settings"]["files"]["winratio"].is_boolean())
                            rs_file_winratio = config["settings"]["files"]["winratio"];
                        if (config["settings"]["files"]["winpercentage"].is_boolean())
                            rs_file_winpercentage = config["settings"]["files"]["winpercentage"];
                        if (config["settings"]["files"]["score"].is_boolean())
                            rs_file_score = config["settings"]["files"]["score"];
                        if (config["settings"]["files"]["demo"].is_boolean())
                            rs_file_demolitions = config["settings"]["files"]["demo"];
                        if (config["settings"]["files"]["demom"].is_boolean())
                            rs_file_demolitionsm = config["settings"]["files"]["demom"];
                        if (config["settings"]["files"]["democ"].is_boolean())
                            rs_file_demolitionsc = config["settings"]["files"]["democ"];
                        if (config["settings"]["files"]["death"].is_boolean())
                            rs_file_death = config["settings"]["files"]["death"];
                        if (config["settings"]["files"]["deathm"].is_boolean())
                            rs_file_deathm = config["settings"]["files"]["deathm"];
                        if (config["settings"]["files"]["deathc"].is_boolean())
                            rs_file_deathc = config["settings"]["files"]["deathc"];
                        if (config["settings"]["files"]["shots"].is_boolean())
                            rs_file_shots = config["settings"]["files"]["shots"];
                        if (config["settings"]["files"]["saves"].is_boolean())
                            rs_file_saves = config["settings"]["files"]["saves"];
                        if (config["settings"]["files"]["goals"].is_boolean())
                            rs_file_goals = config["settings"]["files"]["goals"];
                        if (config["settings"]["files"]["dropshot"].is_boolean())
                            rs_file_dropshot = config["settings"]["files"]["dropshot"];
                        if (config["settings"]["files"]["knockout"].is_boolean())
                            rs_file_knockout = config["settings"]["files"]["knockout"];
                        if (config["settings"]["files"]["boost"].is_boolean())
                            rs_file_boost = config["settings"]["files"]["boost"];
                        if (config["settings"]["files"]["miscs"].is_boolean())
                            rs_file_miscs = config["settings"]["files"]["miscs"];
                        if (config["settings"]["files"]["accolades"].is_boolean())
                            rs_file_accolades = config["settings"]["files"]["accolades"];
                    }

                    if (config["settings"]["hides"].is_object() && !config["settings"]["hides"].is_null())
                    {
                        if (config["settings"]["hides"]["games"].is_boolean())
                            rs_hide_games = config["settings"]["hides"]["games"];
                        if (config["settings"]["hides"]["gm"].is_boolean())
                            rs_hide_gm = config["settings"]["hides"]["gm"];
                        if (config["settings"]["hides"]["rank"].is_boolean())
                            rs_hide_rank = config["settings"]["hides"]["rank"];
                        if (config["settings"]["hides"]["div"].is_boolean())
                            rs_hide_div = config["settings"]["hides"]["div"];
                        if (config["settings"]["hides"]["mmr"].is_boolean())
                            rs_hide_mmr = config["settings"]["hides"]["mmr"];
                        if (config["settings"]["hides"]["mmrc"].is_boolean())
                            rs_hide_mmrc = config["settings"]["hides"]["mmrc"];
                        if (config["settings"]["hides"]["mmrcc"].is_boolean())
                            rs_hide_mmrcc = config["settings"]["hides"]["mmrcc"];
                        if (config["settings"]["hides"]["win"].is_boolean())
                            rs_hide_win = config["settings"]["hides"]["win"];
                        if (config["settings"]["hides"]["loss"].is_boolean())
                            rs_hide_loss = config["settings"]["hides"]["loss"];
                        if (config["settings"]["hides"]["streak"].is_boolean())
                            rs_hide_streak = config["settings"]["hides"]["streak"];
                        if (config["settings"]["hides"]["winratio"].is_boolean())
                            rs_hide_winratio = config["settings"]["hides"]["winratio"];
                        if (config["settings"]["hides"]["winpercentage"].is_boolean())
                            rs_hide_winpercentage = config["settings"]["hides"]["winpercentage"];
                        if (config["settings"]["hides"]["score"].is_boolean())
                            rs_hide_score = config["settings"]["hides"]["score"];
                        if (config["settings"]["hides"]["demo"].is_boolean())
                            rs_hide_demolitions = config["settings"]["hides"]["demo"];
                        if (config["settings"]["hides"]["demom"].is_boolean())
                            rs_hide_demolitionsm = config["settings"]["hides"]["demom"];
                        if (config["settings"]["hides"]["democ"].is_boolean())
                            rs_hide_demolitionsc = config["settings"]["hides"]["democ"];
                        if (config["settings"]["hides"]["death"].is_boolean())
                            rs_hide_death = config["settings"]["hides"]["death"];
                        if (config["settings"]["hides"]["deathm"].is_boolean())
                            rs_hide_deathm = config["settings"]["hides"]["deathm"];
                        if (config["settings"]["hides"]["deathc"].is_boolean())
                            rs_hide_deathc = config["settings"]["hides"]["deathc"];
                        if (config["settings"]["hides"]["shots"].is_boolean())
                            rs_hide_shots = config["settings"]["hides"]["shots"];
                        if (config["settings"]["hides"]["saves"].is_boolean())
                            rs_hide_saves = config["settings"]["hides"]["saves"];
                        if (config["settings"]["hides"]["goals"].is_boolean())
                            rs_hide_goals = config["settings"]["hides"]["goals"];
                        if (config["settings"]["hides"]["dropshot"].is_boolean())
                            rs_hide_dropshot = config["settings"]["hides"]["dropshot"];
                        if (config["settings"]["hides"]["knockout"].is_boolean())
                            rs_hide_knockout = config["settings"]["hides"]["knockout"];
                        if (config["settings"]["hides"]["miscs"].is_boolean())
                            rs_hide_miscs = config["settings"]["hides"]["miscs"];
                        if (config["settings"]["hides"]["accolades"].is_boolean())
                            rs_hide_accolades = config["settings"]["hides"]["accolades"];

                        cvarManager->log("Config: hides loaded");
                    }

                    cvarManager->log("Config: settings loaded");
                }

                if (config["always"].is_object() && !config["always"].is_null())
                {
                    VarsRead(always, config["always"]);
                    always.isInit = true;

                    cvarManager->log("Config: stats loaded");
                }

                if (config["always_gm_idx"].is_number_unsigned() && int(config["always_gm_idx"]) < playlist_name.size())
                    current.playlist = config["always_gm_idx"];

                if (config["always_gm"].is_array())
                {
                    for (int i = 0; i < config["always_gm"].size() && i < playlist_name.size(); ++i)
                    {
                        if (config["always_gm"][i].is_object() && !config["always_gm"][i].is_null())
                        {
                            VarsRead(always_gm[i], config["always_gm"][i]);
                            always_gm[i].isInit = true;
                        }
                    }

                    cvarManager->log("Config: stats loaded");
                }

                SetRefresh(RefreshFlags_Refresh);
            }
            else
                cvarManager->log("Config: bad JSON");
        }
        catch (json::parse_error& e)
        {
            cvarManager->log("Config: bad JSON -> " + std::string(e.what()));
        }
    }

    cvarManager->log("===== !ReadConfig =====");
    return exists;
}

void RocketStats::WriteConfig()
{
    cvarManager->log("===== WriteConfig =====");

    json tmp = json::object();

    tmp["settings"] = json::object();
    tmp["settings"]["mode"] = rs_mode;
    tmp["settings"]["theme"] = themes.at(rs_theme).name.c_str();
    tmp["settings"]["GameTheme"] = themes.at(rs_gameTheme).name.c_str();
    tmp["settings"]["enableDualTheme"] = dualtheme;
    tmp["settings"]["overlay"] = rs_disp_overlay;
    tmp["settings"]["inmenu"] = rs_enable_inmenu;
    tmp["settings"]["ingame"] = rs_enable_ingame;
    tmp["settings"]["inscoreboard"] = rs_enable_inscoreboard;
    tmp["settings"]["float"] = rs_enable_float;
    tmp["settings"]["preview"] = rs_preview_rank;
    tmp["settings"]["roman"] = rs_roman_numbers;

    tmp["settings"]["replace_mmr"] = rs_replace_mmr;
    tmp["settings"]["replace_mmr_cc"] = rs_replace_mmr_cc;
    tmp["settings"]["replace_mmrc"] = rs_replace_mmrc;
    tmp["settings"]["replace_mmrc_cc"] = rs_replace_mmrc_cc;
    tmp["settings"]["replace_mmrcc"] = rs_replace_mmrcc;
    tmp["settings"]["replace_mmrcc_c"] = rs_replace_mmrcc_c;

    // Save only existing themes
    tmp["settings"]["themes"] = json::object();
    for (int i = 0; i < themes.size(); ++i)
    {
        std::string name = themes.at(i).name;
        if (themes_values[name].is_object() && !themes_values[name].is_null() && themes_values[name].size())
            tmp["settings"]["themes"][name] = themes_values[name];
    }

    tmp["settings"]["files"] = json::object();
    tmp["settings"]["files"]["on"] = rs_in_file;
    tmp["settings"]["files"]["games"] = rs_file_games;
    tmp["settings"]["files"]["gm"] = rs_file_gm;
    tmp["settings"]["files"]["rank"] = rs_file_rank;
    tmp["settings"]["files"]["div"] = rs_file_div;
    tmp["settings"]["files"]["mmr"] = rs_file_mmr;
    tmp["settings"]["files"]["mmr"] = rs_file_mmr;
    tmp["settings"]["files"]["mmrc"] = rs_file_mmrc;
    tmp["settings"]["files"]["mmrcc"] = rs_file_mmrcc;
    tmp["settings"]["files"]["win"] = rs_file_win;
    tmp["settings"]["files"]["loss"] = rs_file_loss;
    tmp["settings"]["files"]["streak"] = rs_file_streak;
    tmp["settings"]["files"]["winratio"] = rs_file_winratio;
    tmp["settings"]["files"]["winpercentage"] = rs_file_winpercentage;
    tmp["settings"]["files"]["score"] = rs_file_score;
    tmp["settings"]["files"]["demo"] = rs_file_demolitions;
    tmp["settings"]["files"]["demom"] = rs_file_demolitionsm;
    tmp["settings"]["files"]["democ"] = rs_file_demolitionsc;
    tmp["settings"]["files"]["death"] = rs_file_death;
    tmp["settings"]["files"]["deathm"] = rs_file_deathm;
    tmp["settings"]["files"]["deathc"] = rs_file_deathc;
    tmp["settings"]["files"]["shots"] = rs_file_shots;
    tmp["settings"]["files"]["saves"] = rs_file_saves;
    tmp["settings"]["files"]["goals"] = rs_file_goals;
    tmp["settings"]["files"]["dropshot"] = rs_file_dropshot;
    tmp["settings"]["files"]["knockout"] = rs_file_knockout;
    tmp["settings"]["files"]["miscs"] = rs_file_miscs;
    tmp["settings"]["files"]["accolades"] = rs_file_accolades;
    tmp["settings"]["files"]["boost"] = rs_file_boost;

    tmp["settings"]["hides"] = json::object();
    tmp["settings"]["hides"]["games"] = rs_hide_games;
    tmp["settings"]["hides"]["gm"] = rs_hide_gm;
    tmp["settings"]["hides"]["rank"] = rs_hide_rank;
    tmp["settings"]["hides"]["div"] = rs_hide_div;
    tmp["settings"]["hides"]["mmr"] = rs_hide_mmr;
    tmp["settings"]["hides"]["mmrc"] = rs_hide_mmrc;
    tmp["settings"]["hides"]["mmrcc"] = rs_hide_mmrcc;
    tmp["settings"]["hides"]["win"] = rs_hide_win;
    tmp["settings"]["hides"]["loss"] = rs_hide_loss;
    tmp["settings"]["hides"]["streak"] = rs_hide_streak;
    tmp["settings"]["hides"]["winratio"] = rs_hide_winratio;
    tmp["settings"]["hides"]["winpercentage"] = rs_hide_winpercentage;
    tmp["settings"]["hides"]["score"] = rs_hide_score;
    tmp["settings"]["hides"]["demo"] = rs_hide_demolitions;
    tmp["settings"]["hides"]["demom"] = rs_hide_demolitionsm;
    tmp["settings"]["hides"]["democ"] = rs_hide_demolitionsc;
    tmp["settings"]["hides"]["death"] = rs_hide_death;
    tmp["settings"]["hides"]["deathm"] = rs_hide_deathm;
    tmp["settings"]["hides"]["deathc"] = rs_hide_deathc;
    tmp["settings"]["hides"]["shots"] = rs_hide_shots;
    tmp["settings"]["hides"]["saves"] = rs_hide_saves;
    tmp["settings"]["hides"]["goals"] = rs_hide_goals;
    tmp["settings"]["hides"]["dropshot"] = rs_hide_dropshot;
    tmp["settings"]["hides"]["knockout"] = rs_hide_knockout;
    tmp["settings"]["hides"]["miscs"] = rs_hide_miscs;
    tmp["settings"]["hides"]["accolades"] = rs_hide_accolades;

    tmp["always"] = json::object();
    VarsWrite(always, tmp["always"]);

    tmp["always_gm_idx"] = current.playlist;
    tmp["always_gm"] = json::array();
    for (int i = 0; i < always_gm.size(); ++i)
    {
        tmp["always_gm"][i] = json::object();
        VarsWrite(always_gm[i], tmp["always_gm"][i]);
    }

    WriteInFile("data/rocketstats.json", tmp.dump(2), true); // Save plugin settings in JSON format

    cvarManager->log("===== !WriteConfig =====");
}
```

## File: Managements/OverlayManagement.cpp
```cpp
#include "../RocketStats.h"

void RocketStats::LoadThemes()
{
    cvarManager->log("===== LoadThemes =====");

    themes = {};
    std::string theme_base = GetPath("RocketStats_themes");
    if (fs::exists(theme_base))
    {
        // List the themes (taking the name of the folder)
        for (const auto& entry : fs::directory_iterator(theme_base))
        {
            std::string theme_path = entry.path().string();
            if (entry.is_directory() && fs::exists(theme_path + "/config.json"))
            {
                Theme theme;
                theme.name = theme_path.substr(theme_path.find_last_of("/\\") + 1);
                cvarManager->log("Theme: " + theme.name);

                // Puts the "Default" theme in the first position and "Redesign" in the second position
                if (theme.name == "Default" || theme.name == "Redesigned")
                {
                    size_t pos = ((theme.name == "Redesigned" && themes.at(0).name == "Default") ? 1 : 0);
                    themes.insert((themes.begin() + pos), theme);
                }
                else
                    themes.push_back(theme);
            }
        }
    }

    cvarManager->log("===== !LoadThemes =====");
}

void RocketStats::BacktoMenu()
{
    if (is_in_MainMenu) {
        SetTheme(themes.at(rs_theme).name.c_str());
        ChangeTheme(rs_theme);
    }
}

void RocketStats::InGameTheme()
{
    if (dualtheme) {
        SetGameTheme(themes.at(rs_gameTheme).name.c_str());
        ChangeTheme(rs_gameTheme);
    }
}

bool RocketStats::ChangeTheme(int idx)
{
    cvarManager->log("===== ChangeTheme =====");

    // Stores current theme variables on error
    Theme old = {
        theme_render.name,
        theme_render.author,
        theme_render.version,
        theme_render.date,
        theme_render.fonts
    };

    try
    {
        // If the index of the theme does not fit in the list of themes, we do nothing
        if (themes.size() <= idx)
            return true;

        Theme& theme = themes.at(idx);

        // Read the JSON file including the settings of the chosen theme
        theme_config = ReadJSON("RocketStats_themes/" + theme.name + "/config.json");

        if (theme_config.is_object())
        {
            theme_render.name = theme.name;

            if (theme_config.contains("author") && theme_config["author"].size())
                theme_render.author = theme_config["author"];

            if (theme_config.contains("version"))
            {
                std::string version = theme_config["version"];
                if (version.size() >= 2 && version[0] == 'v')
                    theme_render.version = version;
            }

            if (theme_config.contains("date"))
            {
                std::string date = theme_config["date"];
                if (date.size() == 10 && date[2] == '/' && date[5] == '/')
                    theme_render.date = date;
            }

            // Add default theme font to system
            bool default_font = false;
            if (theme_config.contains("font") && theme_config["font"].is_array() && theme_config["font"].size() == 2)
            {
                if (!theme_config.contains("fonts") || !theme_config["fonts"].is_array())
                    theme_config["fonts"] = json::array();

                default_font = true;
                theme_config["fonts"].insert(theme_config["fonts"].begin(), theme_config["font"]);
            }

            // Add theme fonts to system
            theme_render.fonts = {};
            if (theme_config.contains("fonts") && theme_config["fonts"].is_array())
            {
                for (int i = 0; i < theme_config["fonts"].size(); ++i)
                {
                    json font = theme_config["fonts"][i];
                    if (font.size() == 2 && font[0].is_string() && font[1].is_number_unsigned())
                    {
                        int font_size = font[1];
                        std::string font_file = font[0];

                        std::string font_prefix = "rs_";
                        std::string font_path = ("RocketStats_themes/" + theme_render.name + "/fonts/" + font_file);
                        std::string font_dest = ("../RocketStats/" + font_path);

                        if (font_file.size() && font_size > 0 && ExistsPath(font_path))
                        {
                            std::string font_name = Utils::tolower(font_prefix + (font_file.substr(0, font_file.find_last_of('.'))) + "_" + std::to_string(font_size));
                            theme_render.fonts.push_back({ font_size, font_name, (!i && default_font) });

                            GuiManagerWrapper gui = gameWrapper->GetGUIManager();
                            gui.LoadFont(font_name, font_dest, font_size);
                            cvarManager->log("Load font: " + font_name);
                        }
                    }
                }
            }

            if (themes_values[theme_render.name].is_object())
            {
                if (themes_values[theme_render.name]["x"].is_number())
                    rs_x = float(themes_values[theme_render.name]["x"]);
                if (themes_values[theme_render.name]["y"].is_number())
                    rs_y = float(themes_values[theme_render.name]["y"]);
                if (themes_values[theme_render.name]["scale"].is_number())
                    rs_scale = std::min(10.f, std::max(0.001f, float(themes_values[theme_render.name]["scale"])));
                if (themes_values[theme_render.name]["rotate"].is_number())
                    rs_rotate = std::min(180.f, std::max(-180.f, float(themes_values[theme_render.name]["rotate"])));
                if (themes_values[theme_render.name]["opacity"].is_number())
                    rs_opacity = std::min(1.f, std::max(0.f, float(themes_values[theme_render.name]["opacity"])));
            }

            cvarManager->log("Theme changed: " + theme.name + " (old: " + theme_render.name + ")");
            SetRefresh(RefreshFlags_RefreshAndImages);
        }
        else {
            cvarManager->log("Theme config: " + theme.name + " bad JSON");
            return false;
        }
    }
    catch (json::parse_error& e)
    {
        cvarManager->log("Theme config: " + std::to_string(idx) + " bad JSON -> " + std::string(e.what()));

        // Returns the variables as they were before the process
        theme_render.name = old.name;
        theme_render.author = old.author;
        theme_render.version = old.version;
        theme_render.date = old.date;
        theme_render.fonts = old.fonts;
        return false;
    }

    cvarManager->log("===== !ChangeTheme =====");
    return true;
}

void RocketStats::SetTheme(std::string name)
{
    // Search the index of a theme with its name (changes current theme if found)
    for (int i = 0; i < themes.size(); ++i)
    {
        if (themes.at(i).name == name)
        {
            cvarManager->log("SetTheme: [" + std::to_string(i) + "] " + name);

            rs_theme = i;
            break;
        }
    }
}

void RocketStats::SetGameTheme(std::string name)
{
    // Search the index of a theme with its name (changes current theme if found)
    for (int i = 0; i < themes.size(); ++i)
    {
        if (themes.at(i).name == name)
        {
            cvarManager->log("SetGameTheme: [" + std::to_string(i) + "] " + name);

            rs_gameTheme = i;
            break;
        }
    }
}

void RocketStats::SetRefresh(unsigned char value)
{
    if (theme_refresh < value)
        theme_refresh = value;
}

void RocketStats::RefreshFiles(std::string old, CVarWrapper now)
{
    if (now.getBoolValue())
        UpdateFiles(true);
    RefreshTheme(old, now);
}

void RocketStats::RefreshTheme(std::string old, CVarWrapper now)
{
    bool refresh = true;
    bool value = now.getBoolValue();
    std::string name = now.getCVarName();
    if (name == "rs_disp_overlay")
        rs_disp_overlay = value;
    else if (name == "rs_enable_inmenu")
        rs_enable_inmenu = value;
    else if (name == "rs_enable_ingame")
        rs_enable_ingame = value;
    else if (name == "rs_enable_inscoreboard")
        rs_enable_inscoreboard = value;
    else
        refresh = false;

    if (refresh)
    {
        cvarManager->log("SetCVar: " + std::string(name) + " " + std::to_string(value));
        RefreshVars();
    }

    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::RefreshVars()
{
    CVarWrapper cvar_x = cvarManager->getCvar("rs_x");
    CVarWrapper cvar_y = cvarManager->getCvar("rs_y");
    CVarWrapper cvar_scale = cvarManager->getCvar("rs_scale");
    CVarWrapper cvar_rotate = cvarManager->getCvar("rs_rotate");
    CVarWrapper cvar_opacity = cvarManager->getCvar("rs_opacity");

    // Delimits certain variables
    if (rs_x < cvar_x.GetMinimum())
        rs_x = cvar_x.GetMinimum();
    else if (rs_x > cvar_x.GetMaximum())
        rs_x = cvar_x.GetMaximum();

    if (rs_y < cvar_y.GetMinimum())
        rs_y = cvar_y.GetMinimum();
    else if (rs_y > cvar_y.GetMaximum())
        rs_y = cvar_y.GetMaximum();

    if (rs_scale < cvar_scale.GetMinimum())
        rs_scale = cvar_scale.GetMinimum();
    else if (rs_scale > cvar_scale.GetMaximum())
        rs_scale = cvar_scale.GetMaximum();

    if (rs_rotate < cvar_rotate.GetMinimum())
        rs_rotate = cvar_rotate.GetMinimum();
    else if (rs_rotate > cvar_rotate.GetMaximum())
        rs_rotate = cvar_rotate.GetMaximum();

    if (rs_opacity < cvar_opacity.GetMinimum())
        rs_opacity = cvar_opacity.GetMinimum();
    else if (rs_opacity > cvar_opacity.GetMaximum())
        rs_opacity = cvar_opacity.GetMaximum();

    // Check for changes before modifying cvars
    bool changed = false;
    if (SetCVar("rs_mode", rs_mode))
    {
        changed = true;
        UpdateFiles();
    }
    SetCVar("rs_theme", rs_theme);
    SetCVar("rs_gameTheme", rs_gameTheme);

    SetCVar("rs_x", rs_x, true);
    SetCVar("rs_y", rs_y, true);

    SetCVar("rs_scale", rs_scale, true);
    SetCVar("rs_rotate", rs_rotate, true);
    SetCVar("rs_opacity", rs_opacity, true);

    SetCVar("rs_disp_overlay", rs_disp_overlay);
    if (SetCVar("rs_enable_inmenu", rs_enable_inmenu) && !rs_enable_inmenu && !rs_enable_ingame && !rs_enable_inscoreboard)
        rs_enable_ingame = true;
    if (SetCVar("rs_enable_ingame", rs_enable_ingame) && !rs_enable_ingame && !rs_enable_inmenu && !rs_enable_inscoreboard)
        rs_enable_inmenu = true;
    if (SetCVar("rs_enable_inscoreboard", rs_enable_inscoreboard) && !rs_enable_ingame && !rs_enable_inmenu && !rs_enable_inscoreboard)
        rs_enable_inmenu = true;
    SetCVar("rs_enable_float", rs_enable_float);
    SetCVar("rs_preview_rank", rs_preview_rank);
    changed = (SetCVar("rs_roman_numbers", rs_roman_numbers) || changed);

    if (SetCVar("rs_replace_mmr", rs_replace_mmr) && rs_replace_mmr && rs_replace_mmr_cc)
        rs_replace_mmr_cc = false;
    if (SetCVar("rs_replace_mmr_cc", rs_replace_mmr_cc) && rs_replace_mmr_cc && rs_replace_mmr)
        rs_replace_mmr = false;
    if (SetCVar("rs_replace_mmrc", rs_replace_mmrc) && rs_replace_mmrc && rs_replace_mmrc_cc)
        rs_replace_mmrc_cc = false;
    if (SetCVar("rs_replace_mmrc_cc", rs_replace_mmrc_cc) && rs_replace_mmrc_cc && rs_replace_mmrc)
        rs_replace_mmrc = false;
    if (SetCVar("rs_replace_mmrcc", rs_replace_mmrcc) && rs_replace_mmrcc && rs_replace_mmrcc_c)
        rs_replace_mmrcc_c = false;
    if (SetCVar("rs_replace_mmrcc_c", rs_replace_mmrcc_c) && rs_replace_mmrcc_c && rs_replace_mmrcc)
        rs_replace_mmrcc = false;

    SetCVar("rs_in_file", rs_in_file);
    SetCVar("rs_file_games", rs_file_games);
    SetCVar("rs_file_gm", rs_file_gm);
    SetCVar("rs_file_rank", rs_file_rank);
    SetCVar("rs_file_div", rs_file_div);
    SetCVar("rs_file_mmr", rs_file_mmr);
    SetCVar("rs_file_mmrc", rs_file_mmrc);
    SetCVar("rs_file_mmrcc", rs_file_mmrcc);
    SetCVar("rs_file_win", rs_file_win);
    SetCVar("rs_file_loss", rs_file_loss);
    SetCVar("rs_file_streak", rs_file_streak);
    SetCVar("rs_file_winratio", rs_file_winratio);
    SetCVar("rs_file_winpercentage", rs_file_winpercentage);
    SetCVar("rs_file_score", rs_file_score);
    SetCVar("rs_file_demo", rs_file_demolitions);
    SetCVar("rs_file_demom", rs_file_demolitionsm);
    SetCVar("rs_file_democ", rs_file_demolitionsc);
    SetCVar("rs_file_death", rs_file_death);
    SetCVar("rs_file_deathm", rs_file_deathm);
    SetCVar("rs_file_deathc", rs_file_deathc);
    SetCVar("rs_file_shots", rs_file_shots);
    SetCVar("rs_file_saves", rs_file_saves);
    SetCVar("rs_file_goals", rs_file_goals);
    SetCVar("rs_file_dropshot", rs_file_dropshot);
    SetCVar("rs_file_knockout", rs_file_knockout);
    SetCVar("rs_file_miscs", rs_file_miscs);
    SetCVar("rs_file_accolades", rs_file_accolades);
    SetCVar("rs_file_boost", rs_file_boost);

    SetCVar("rs_hide_games", rs_hide_games);
    SetCVar("rs_hide_gm", rs_hide_gm);
    SetCVar("rs_hide_rank", rs_hide_rank);
    SetCVar("rs_hide_div", rs_hide_div);
    SetCVar("rs_hide_mmr", rs_hide_mmr);
    SetCVar("rs_hide_mmrc", rs_hide_mmrc);
    SetCVar("rs_hide_mmrcc", rs_hide_mmrcc);
    SetCVar("rs_hide_win", rs_hide_win);
    SetCVar("rs_hide_loss", rs_hide_loss);
    SetCVar("rs_hide_streak", rs_hide_streak);
    SetCVar("rs_hide_winratio", rs_hide_winratio);
    SetCVar("rs_hide_winpercentage", rs_hide_winpercentage);
    SetCVar("rs_hide_score", rs_hide_score);
    SetCVar("rs_hide_demo", rs_hide_demolitions);
    SetCVar("rs_hide_demom", rs_hide_demolitionsm);
    SetCVar("rs_hide_democ", rs_hide_demolitionsc);
    SetCVar("rs_hide_death", rs_hide_death);
    SetCVar("rs_hide_deathm", rs_hide_deathm);
    SetCVar("rs_hide_deathc", rs_hide_deathc);
    SetCVar("rs_hide_shots", rs_hide_shots);
    SetCVar("rs_hide_saves", rs_hide_saves);
    SetCVar("rs_hide_goals", rs_hide_goals);
    SetCVar("rs_hide_dropshot", rs_hide_dropshot);
    SetCVar("rs_hide_knockout", rs_hide_knockout);
    SetCVar("rs_hide_miscs", rs_hide_miscs);
    SetCVar("rs_hide_accolades", rs_hide_accolades);

    if (changed)
    {
        gameWrapper->SetTimeout([&](GameWrapper* gameWrapper) {
            SendGameState("SettingsChanged");
        }, 0.1f);
    }
}

Element RocketStats::CalculateElement(json& element, Options& options, bool& check)
{
    check = false;
    Element calculated;

    if (!element.contains("visible") || element["visible"])
    {
        try
        {
            Vector2D element_2d;
            std::vector<ImVec2> positions;

            if (element.contains("name") && element["name"].size())
                calculated.name = element["name"];

            if (element.contains("x"))
                element_2d.x = (float(element["x"].is_string() ? Utils::EvaluateExpression(element["x"], options.width, display_size) : int(element["x"])) * options.scale);

            if (element.contains("y"))
                element_2d.y = (float(element["y"].is_string() ? Utils::EvaluateExpression(element["y"], options.height, display_size) : int(element["y"])) * options.scale);

            if (element.contains("width"))
                element_2d.width = (float(element["width"].is_string() ? Utils::EvaluateExpression(element["width"], options.width, display_size) : int(element["width"])) * options.scale);

            if (element.contains("height"))
                element_2d.height = (float(element["height"].is_string() ? Utils::EvaluateExpression(element["height"], options.height, display_size) : int(element["height"])) * options.scale);

            ImVec2 element_pos = { float(options.x + element_2d.x), float(options.y + element_2d.y) };
            ImVec2 element_size = { float(element_2d.width), float(element_2d.height) };
            const float element_scale = (element.contains("scale") ? float(element["scale"]) : 1.f);
            const float element_rotate = (element.contains("rotate") ? float(element["rotate"]) : 0.f);
            const float element_opacity = (options.opacity * (element.contains("opacity") ? float(element["opacity"]) : 1.f));

            calculated.scale = (element_scale * options.scale);

            calculated.color.enable = true;
            if (element.contains("color") && element["color"].is_array())
                calculated.color = { true, Utils::GetImColor(element["color"], element_opacity) };

            if (element.contains("fill") && element["fill"].is_array())
                calculated.fill = { true, Utils::GetImColor(element["fill"], element_opacity) };

            if (element.contains("stroke") && element["stroke"].is_array())
                calculated.stroke = { true, Utils::GetImColor(element["stroke"], element_opacity) };

            if (element["type"] == "text" && element["value"].size())
            {
                calculated.scale *= 2.f;
                calculated.value = element["value"];

                Utils::ReplaceVars(calculated.value, theme_vars, [this, &element, &options, &calculated, &element_opacity](const std::string& key, std::string& value) {
                    std::string tkey = key;
                    if (tkey == "MMR" && rs_replace_mmr)
                        tkey = "MMRChange";
                    else if (tkey == "MMR" && rs_replace_mmr_cc)
                        tkey = "MMRCumulChange";
                    else if (tkey == "MMRChange" && rs_replace_mmrc)
                        tkey = "MMR";
                    else if (tkey == "MMRChange" && rs_replace_mmrc_cc)
                        tkey = "MMRCumulChange";
                    else if (tkey == "MMRCumulChange" && rs_replace_mmrcc)
                        tkey = "MMR";
                    else if (tkey == "MMRCumulChange" && rs_replace_mmrcc_c)
                        tkey = "MMRChange";

                    if (element.contains("sign") && element["sign"] == tkey && value != theme_hide_value)
                    {
                        bool positive = (value.at(0) != '-' && value.at(0) != '0');
                        if (positive)
                            value = ("+" + value);
                    }

                    if (element.contains("chameleon") && element["chameleon"] == tkey)
                    {
                        bool positive = (value.at(0) != '-');
                        calculated.color.color = Utils::GetImColor({ float(positive ? 30 : 224), float(positive ? 224 : 24), float(positive ? 24 : 24) }, element_opacity);
                    }
                });

                if (!calculated.value.size())
                    return calculated;

                if (element.contains("transform") && element["transform"].is_string())
                {
                    std::string transform = element["transform"];
                    if (transform == "lower")
                        calculated.value = Utils::tolower(calculated.value);
                    else if (transform == "upper")
                        calculated.value = Utils::toupper(calculated.value);
                    else if (transform == "capitalize")
                        calculated.value = Utils::capitalize(calculated.value);
                }

                int font_pos = -1;
                if (theme_render.fonts.size())
                {
                    if (theme_render.fonts.at(0).isDefault)
                        font_pos = 0;

                    bool specific = (element.contains("font") && element["font"].is_string() && element["font"].size());
                    if (specific)
                    {
                        for (int i = 0; i < theme_render.fonts.size(); ++i)
                        {
                            if (theme_render.fonts.at(i).name.substr(3, (theme_render.fonts.at(i).name.find_last_of('_') - 3)) == Utils::tolower(element["font"]))
                            {
                                font_pos = i;
                                break;
                            }
                        }
                    }
                }

                ImVec2 string_size;
                ImGui::SetWindowFontScale(1.f);
                if (font_pos >= 0)
                {
                    calculated.font = theme_render.fonts.at(font_pos).name;
                    calculated.scale *= theme_render.fonts.at(font_pos).size;

                    GuiManagerWrapper gui = gameWrapper->GetGUIManager();
                    string_size = gui.GetFont(theme_render.fonts.at(font_pos).name)->CalcTextSizeA(calculated.scale, FLT_MAX, 0.f, calculated.value.c_str());
                }
                else
                {
                    ImGui::SetWindowFontScale(calculated.scale);
                    string_size = ImGui::CalcTextSize(calculated.value.c_str());
                }

                if (element.contains("align") && element["align"].is_string())
                {
                    if (element["align"] == "right")
                        element_pos.x -= string_size.x;
                    else if (element["align"] == "center")
                        element_pos.x -= (string_size.x / 2.f);
                }

                if (element.contains("valign") && element["valign"].is_string())
                {
                    if (element["valign"] == "bottom")
                        element_pos.y -= string_size.y;
                    else if (element["valign"] == "middle")
                        element_pos.y -= (string_size.y / 2.f);
                }
            }
            else if (element["type"] == "line")
            {
                element_pos.x = float(options.x) + (float(element["x1"].is_string() ? Utils::EvaluateExpression(element["x1"], options.width, display_size) : int(element["x1"])) * options.scale);
                element_pos.y = float(options.y) + (float(element["y1"].is_string() ? Utils::EvaluateExpression(element["y1"], options.height, display_size) : int(element["y1"])) * options.scale);
                const float element_width = (element.contains("scale") ? float(element["scale"]) : 1);

                element_size.x = element_width;
                calculated.scale = (element_width * options.scale);

                positions.push_back(ImVec2{
                    float(options.x) + (float(element["x2"].is_string() ? Utils::EvaluateExpression(element["x2"], options.width, display_size) : int(element["x2"])) * options.scale),
                    float(options.y) + (float(element["y2"].is_string() ? Utils::EvaluateExpression(element["y2"], options.height, display_size) : int(element["y2"])) * options.scale)
                });
            }
            else if (element["type"] == "rectangle")
            {
                element_size.x = (element.contains("rounding") ? float(element["rounding"]) : 0.f);

                positions.push_back(ImVec2{
                    element_pos.x + element_2d.width,
                    element_pos.y + element_2d.height
                });
            }
            else if (element["type"] == "triangle")
            {
                element_pos.x = float(options.x) + (float(element["x1"].is_string() ? Utils::EvaluateExpression(element["x1"], options.width, display_size) : int(element["x1"])) * options.scale);
                element_pos.y = float(options.y) + (float(element["y1"].is_string() ? Utils::EvaluateExpression(element["y1"], options.height, display_size) : int(element["y1"])) * options.scale);

                positions.push_back(ImVec2{
                    float(options.x) + (float(element["x2"].is_string() ? Utils::EvaluateExpression(element["x2"], options.width, display_size) : int(element["x2"])) * options.scale),
                    float(options.y) + (float(element["y2"].is_string() ? Utils::EvaluateExpression(element["y2"], options.height, display_size) : int(element["y2"])) * options.scale)
                });
                positions.push_back(ImVec2{
                    float(options.x) + (float(element["x3"].is_string() ? Utils::EvaluateExpression(element["x3"], options.width, display_size) : int(element["x3"])) * options.scale),
                    float(options.y) + (float(element["y3"].is_string() ? Utils::EvaluateExpression(element["y3"], options.height, display_size) : int(element["y3"])) * options.scale)
                });
            }
            else if (element["type"] == "circle")
            {
                const float radius = float(element["radius"].is_string() ? Utils::EvaluateExpression(element["radius"], options.width, display_size) : int(element["radius"]));

                element_size.x = (radius * options.scale);
                element_size.y = float(element.contains("segments") ? int(element["segments"]) : 0);
            }
            else if (element["type"] == "pie_chart")
            {
                const float radius = float(element["radius"].is_string() ? Utils::EvaluateExpression(element["radius"], options.width, display_size) : int(element["radius"]));
                const float angle_min = ((element.contains("angle-min") ? float(element["angle-min"]) : 0.f) - 90.f);
                const float angle_max = ((element.contains("angle-max") ? float(element["angle-max"]) : 0.f) - 90.f);
                const float radian_min = ((angle_min / 360.f) * ARC_SPAN);
                const float radian_max = ((angle_max / 360.f) * ARC_SPAN);

                element_size.x = (radius * options.scale);
                element_size.y = float(element.contains("segments") ? int(element["segments"]) : 0);

                positions.push_back(ImVec2{ radian_min, radian_max });

                if (element.contains("stroke"))
                {
                    positions.push_back(ImVec2{
                        (element_pos.x + ((element_size.x * cos(radian_min)))),
                        (element_pos.y + ((element_size.x * sin(radian_min))))
                    });
                }
            }
            else if (element["type"] == "image")
            {
                calculated.scale *= 0.5f;
                calculated.value = element["file"];

                if (!element.contains("color"))
                    calculated.color = { true, Utils::GetImColor({ 255.f, 255.f, 255.f }, element_opacity) };

                if (calculated.value == "{{Rank}}")
                {
                    theme_images[calculated.value] = rank[0].image;

                    // Returns the casual games image, otherwise returns the current ranking image
                    if (current.playlist >= 1 && current.playlist <= 4)
                        theme_images[calculated.value] = casual;
                    else if (current.ranked || rs_preview_rank)
                        theme_images[calculated.value] = rank[(!rs_hide_rank && current.tier < rank_nb) ? current.tier : 0].image;
                }
                else if (!theme_images[calculated.value])
                {
                    // Get the requested image
                    element_size = { 0, 0 };
                    std::string image_path = "RocketStats_themes/" + theme_render.name + "/images/" + calculated.value;

                    cvarManager->log("Load image: " + image_path);
                    theme_images[calculated.value] = LoadImg(image_path);
                }

                // Calculate the image only if it is loaded (request for recalculation later if needed)
                if (theme_images[calculated.value]->GetImGuiTex() != nullptr)
                {
                    Vector2F image_size = theme_images[calculated.value]->GetSizeF();
                    element_size = {
                        (image_size.X * calculated.scale),
                        (image_size.Y * calculated.scale)
                    };

                    if (element.contains("align") && element["align"].is_string())
                    {
                        if (element["align"] == "right")
                            element_pos.x -= element_size.x;
                        else if (element["align"] == "center")
                            element_pos.x -= (element_size.x / 2.f);
                    }

                    if (element.contains("valign") && element["valign"].is_string())
                    {
                        if (element["valign"] == "bottom")
                            element_pos.y -= element_size.y;
                        else if (element["valign"] == "middle")
                            element_pos.y -= (element_size.y / 2.f);
                    }

                    element_size.x += element_pos.x;
                    element_size.y += element_pos.y;
                }
            }

            positions.emplace(positions.begin(), element_pos);

            calculated.type = element["type"];
            calculated.positions = positions;
            calculated.size = element_size;
            if (element_rotate)
            {
                calculated.rotate_enable = true;
                calculated.rotate = ((90.f - element_rotate) * (float(M_PI) / 180.f)); // Convert degrees to radians
            }

            check = true;
        }
        catch (const std::exception& e)
        {
            cvarManager->log("CalculateElement error: " + std::string(e.what()));
        }
    }

    return calculated;
}

void RocketStats::RenderElement(ImDrawList* drawlist, Element& element)
{
    try
    {
        if (element.rotate_enable)
            ImRotateStart(drawlist); // Saves the position of the vertex array for future rotation

        if (element.fill.enable)
        {
            if (element.type == "triangle")
                drawlist->AddTriangleFilled(element.positions.at(0), element.positions.at(1), element.positions.at(2), element.fill.color);
            else if (element.type == "rectangle")
                drawlist->AddRectFilled(element.positions.at(0), element.positions.at(1), element.fill.color, element.size.x, ImDrawCornerFlags_All);
            else if (element.type == "circle")
                drawlist->AddCircleFilled(element.positions.at(0), element.size.x, element.fill.color, int(element.size.y ? element.size.y : 12));
            else if (element.type == "pie_chart")
            {
                drawlist->PathLineTo(element.positions.at(0));
                drawlist->PathArcTo(element.positions.at(0), element.size.x, element.positions.at(1).x, element.positions.at(1).y, int(element.size.y));
                drawlist->PathFillConvex(element.fill.color);
            }
        }

        if (element.stroke.enable)
        {
            if (element.type == "triangle")
                drawlist->AddTriangle(element.positions.at(0), element.positions.at(1), element.positions.at(2), element.stroke.color, element.scale);
            else if (element.type == "rectangle")
                drawlist->AddRect(element.positions.at(0), element.positions.at(1), element.stroke.color, element.size.x, ImDrawCornerFlags_All, element.scale);
            else if (element.type == "circle")
                drawlist->AddCircle(element.positions.at(0), element.size.x, element.stroke.color, int(element.size.y ? element.size.y : 12), element.scale);
            else if (element.type == "pie_chart")
            {
                drawlist->PathLineTo(element.positions.at(2));
                drawlist->PathArcTo(element.positions.at(0), element.size.x, element.positions.at(1).x, element.positions.at(1).y, int(element.size.y));
                drawlist->PathStroke(element.stroke.color, false, element.scale);
            }
        }

        if (element.type == "image")
        {
            std::shared_ptr<ImageWrapper> image = theme_images[element.value];
            if (image != nullptr && image->GetImGuiTex() != nullptr && element.size.x && element.size.y)
                drawlist->AddImage(image->GetImGuiTex(), element.positions.at(0), element.size, ImVec2{ 0, 0 }, ImVec2{ 1, 1 }, element.color.color);
            else
                SetRefresh(RefreshFlags_Refresh);
        }
        else if (element.type == "text")
        {
            ImGui::SetWindowFontScale(1);
            if (theme_render.fonts.size() && (element.font.size() || theme_render.fonts.at(0).isDefault))
            {
                GuiManagerWrapper gui = gameWrapper->GetGUIManager();
                ImFont* font = gui.GetFont(element.font.size() ? element.font : theme_render.fonts.at(0).name);

                // Display text if font is loaded
                if (font && font->IsLoaded())
                    drawlist->AddText(font, element.scale, element.positions.at(0), element.color.color, element.value.c_str());
            }
            else
            {
                // Displays text without font
                ImGui::SetWindowFontScale(element.scale);
                drawlist->AddText(element.positions.at(0), element.color.color, element.value.c_str());
            }
        }
        else if (element.type == "line")
            drawlist->AddLine(element.positions.at(0), element.positions.at(1), element.color.color, element.size.x);

        if (element.rotate_enable)
            ImRotateEnd(element.rotate); // Applies the rotation to the vertices of the current element
    }
    catch (const std::exception&) {}
}
```

## File: Managements/StatsManagement.cpp
```cpp
#include "../RocketStats.h"

bool RocketStats::isPrimaryPlayer(PriWrapper PRI)
{
    if (PRI.IsNull())
        return (false);

    ServerWrapper server = (is_online_game ? gameWrapper->GetOnlineGame() : gameWrapper->GetGameEventAsServer());
    if (server.IsNull())
        return (false);

    PlayerControllerWrapper player = server.GetLocalPrimaryPlayer();
    if (player.IsNull())
        return (false);

    PriWrapper playerPRI = player.GetPRI();
    if (playerPRI.IsNull())
        return (false);

    return (PRI.GetUniqueIdWrapper().GetUID() == playerPRI.GetUniqueIdWrapper().GetUID());
}

void RocketStats::onStatEvent(ServerWrapper caller, void* params)
{
    StatEventParams* pstats = (StatEventParams*)params;
    StatEventWrapper event = StatEventWrapper(pstats->StatEvent);

    std::string name = event.GetEventName();
    if (name == "Shot")
        name = "ShotOnGoal";

    SocketSend(name, {
        { "Points", event.GetPoints() }
    }, "StatEvent");

    if (!is_online_game)
        return;

    bool refresh = true;
    if (name == "Clear")
    {
        cvarManager->log(" --> " + name);

        ++always.Clear;
        ++current.stats.Clear;
        ++session.Clear;
        ++stats[current.playlist].Clear;
        ++always_gm[current.playlist].Clear;

        ++always.ClearCumul;
        ++current.stats.ClearCumul;
        ++session.ClearCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].ClearCumul;
            ++always_gm[it->first].ClearCumul;
        }

        AllShotsClear(true);
    }
    else if (name == "Center")
    {
        cvarManager->log(" --> " + name);

        ++always.Center;
        ++current.stats.Center;
        ++session.Center;
        ++stats[current.playlist].Center;
        ++always_gm[current.playlist].Center;

        ++always.CenterCumul;
        ++current.stats.CenterCumul;
        ++session.CenterCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].CenterCumul;
            ++always_gm[it->first].CenterCumul;
        }

        AllShotsCenter(true);
    }
    else if (name == "AerialHit")
    {
        cvarManager->log(" --> " + name);

        ++always.AerialHit;
        ++current.stats.AerialHit;
        ++session.AerialHit;
        ++stats[current.playlist].AerialHit;
        ++always_gm[current.playlist].AerialHit;

        ++always.AerialHitCumul;
        ++current.stats.AerialHitCumul;
        ++session.AerialHitCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].AerialHitCumul;
            ++always_gm[it->first].AerialHitCumul;
        }

        AllShotsAerialHit(true);
    }
    else if (name == "FirstTouch")
    {
        cvarManager->log(" --> " + name);

        ++always.FirstTouch;
        ++current.stats.FirstTouch;
        ++session.FirstTouch;
        ++stats[current.playlist].FirstTouch;
        ++always_gm[current.playlist].FirstTouch;

        ++always.FirstTouchCumul;
        ++current.stats.FirstTouchCumul;
        ++session.FirstTouchCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FirstTouchCumul;
            ++always_gm[it->first].FirstTouchCumul;
        }

        AllMiscsFirstTouch(true);
    }
    else if (name == "OwnGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.OwnGoal;
        ++current.stats.OwnGoal;
        ++session.OwnGoal;
        ++stats[current.playlist].OwnGoal;
        ++always_gm[current.playlist].OwnGoal;

        ++always.OwnGoalCumul;
        ++current.stats.OwnGoalCumul;
        ++session.OwnGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].OwnGoalCumul;
            ++always_gm[it->first].OwnGoalCumul;
        }

        AllGoalsOwnGoal(true);
    }
    else if (name == "KO_Thrown")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutThrown;
        ++current.stats.KnockoutThrown;
        ++session.KnockoutThrown;
        ++stats[current.playlist].KnockoutThrown;
        ++always_gm[current.playlist].KnockoutThrown;

        ++always.KnockoutThrownCumul;
        ++current.stats.KnockoutThrownCumul;
        ++session.KnockoutThrownCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutThrownCumul;
            ++always_gm[it->first].KnockoutThrownCumul;
        }

        AllKnockoutThrown(true);
    }
    else if (name == "KO_Grabbed")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutGrabbed;
        ++current.stats.KnockoutGrabbed;
        ++session.KnockoutGrabbed;
        ++stats[current.playlist].KnockoutGrabbed;
        ++always_gm[current.playlist].KnockoutGrabbed;

        ++always.KnockoutGrabbedCumul;
        ++current.stats.KnockoutGrabbedCumul;
        ++session.KnockoutGrabbedCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutGrabbedCumul;
            ++always_gm[it->first].KnockoutGrabbedCumul;
        }

        AllKnockoutGrabbed(true);
    }
    else if (name == "KO_HitTaken")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutHitTaken;
        ++current.stats.KnockoutHitTaken;
        ++session.KnockoutHitTaken;
        ++stats[current.playlist].KnockoutHitTaken;
        ++always_gm[current.playlist].KnockoutHitTaken;

        ++always.KnockoutHitTakenCumul;
        ++current.stats.KnockoutHitTakenCumul;
        ++session.KnockoutHitTakenCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutHitTakenCumul;
            ++always_gm[it->first].KnockoutHitTakenCumul;
        }

        AllKnockoutHitTaken(true);
    }
    else if (name == "KO_LightHit")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutLightHit;
        ++current.stats.KnockoutLightHit;
        ++session.KnockoutLightHit;
        ++stats[current.playlist].KnockoutLightHit;
        ++always_gm[current.playlist].KnockoutLightHit;

        ++always.KnockoutLightHitCumul;
        ++current.stats.KnockoutLightHitCumul;
        ++session.KnockoutLightHitCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutLightHitCumul;
            ++always_gm[it->first].KnockoutLightHitCumul;
        }

        AllKnockoutLightHit(true);
    }
    else if (name == "KO_BlockTaken")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutBlockTaken;
        ++current.stats.KnockoutBlockTaken;
        ++session.KnockoutBlockTaken;
        ++stats[current.playlist].KnockoutBlockTaken;
        ++always_gm[current.playlist].KnockoutBlockTaken;

        ++always.KnockoutBlockTakenCumul;
        ++current.stats.KnockoutBlockTakenCumul;
        ++session.KnockoutBlockTakenCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutBlockTakenCumul;
            ++always_gm[it->first].KnockoutBlockTakenCumul;
        }

        AllKnockoutBlockTaken(true);
    }
    else if (name == "KO_LightBlock")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutLightBlock;
        ++current.stats.KnockoutLightBlock;
        ++session.KnockoutLightBlock;
        ++stats[current.playlist].KnockoutLightBlock;
        ++always_gm[current.playlist].KnockoutLightBlock;

        ++always.KnockoutLightBlockCumul;
        ++current.stats.KnockoutLightBlockCumul;
        ++session.KnockoutLightBlockCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutLightBlockCumul;
            ++always_gm[it->first].KnockoutLightBlockCumul;
        }

        AllKnockoutLightBlock(true);
    }
    else if (name == "KO_PlayerThrown")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutPlayerThrown;
        ++current.stats.KnockoutPlayerThrown;
        ++session.KnockoutPlayerThrown;
        ++stats[current.playlist].KnockoutPlayerThrown;
        ++always_gm[current.playlist].KnockoutPlayerThrown;

        ++always.KnockoutPlayerThrownCumul;
        ++current.stats.KnockoutPlayerThrownCumul;
        ++session.KnockoutPlayerThrownCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutPlayerThrownCumul;
            ++always_gm[it->first].KnockoutPlayerThrownCumul;
        }

        AllKnockoutPlayerThrown(true);
    }
    else if (name == "KO_PlayerGrabbed")
    {
        cvarManager->log(" --> " + name);

        ++always.KnockoutPlayerGrabbed;
        ++current.stats.KnockoutPlayerGrabbed;
        ++session.KnockoutPlayerGrabbed;
        ++stats[current.playlist].KnockoutPlayerGrabbed;
        ++always_gm[current.playlist].KnockoutPlayerGrabbed;

        ++always.KnockoutPlayerGrabbedCumul;
        ++current.stats.KnockoutPlayerGrabbedCumul;
        ++session.KnockoutPlayerGrabbedCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].KnockoutPlayerGrabbedCumul;
            ++always_gm[it->first].KnockoutPlayerGrabbedCumul;
        }

        AllKnockoutPlayerGrabbed(true);
    }
    else if (name == "CarTouches")
    {
        cvarManager->log(" --> " + name);

        ++always.CarTouches;
        ++current.stats.CarTouches;
        ++session.CarTouches;
        ++stats[current.playlist].CarTouches;
        ++always_gm[current.playlist].CarTouches;

        ++always.CarTouchesCumul;
        ++current.stats.CarTouchesCumul;
        ++session.CarTouchesCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].CarTouchesCumul;
            ++always_gm[it->first].CarTouchesCumul;
        }

        AllAccoladesCarTouches(true);
    }
    else if (name == "FastestGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.FastestGoal;
        ++current.stats.FastestGoal;
        ++session.FastestGoal;
        ++stats[current.playlist].FastestGoal;
        ++always_gm[current.playlist].FastestGoal;

        ++always.FastestGoalCumul;
        ++current.stats.FastestGoalCumul;
        ++session.FastestGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FastestGoalCumul;
            ++always_gm[it->first].FastestGoalCumul;
        }

        AllAccoladesFastestGoal(true);
    }
    else if (name == "SlowestGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.SlowestGoal;
        ++current.stats.SlowestGoal;
        ++session.SlowestGoal;
        ++stats[current.playlist].SlowestGoal;
        ++always_gm[current.playlist].SlowestGoal;

        ++always.SlowestGoalCumul;
        ++current.stats.SlowestGoalCumul;
        ++session.SlowestGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].SlowestGoalCumul;
            ++always_gm[it->first].SlowestGoalCumul;
        }

        AllAccoladesSlowestGoal(true);
    }
    else if (name == "BoostPickups")
    {
        cvarManager->log(" --> " + name);

        ++always.BoostPickups;
        ++current.stats.BoostPickups;
        ++session.BoostPickups;
        ++stats[current.playlist].BoostPickups;
        ++always_gm[current.playlist].BoostPickups;

        ++always.BoostPickupsCumul;
        ++current.stats.BoostPickupsCumul;
        ++session.BoostPickupsCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].BoostPickupsCumul;
            ++always_gm[it->first].BoostPickupsCumul;
        }

        AllAccoladesBoostPickups(true);
    }
    else if (name == "FurthestGoal")
    {
        cvarManager->log(" --> " + name);

        ++always.FurthestGoal;
        ++current.stats.FurthestGoal;
        ++session.FurthestGoal;
        ++stats[current.playlist].FurthestGoal;
        ++always_gm[current.playlist].FurthestGoal;

        ++always.FurthestGoalCumul;
        ++current.stats.FurthestGoalCumul;
        ++session.FurthestGoalCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FurthestGoalCumul;
            ++always_gm[it->first].FurthestGoalCumul;
        }

        AllAccoladesFurthestGoal(true);
    }
    else if (name == "MostBallTouches")
    {
        cvarManager->log(" --> " + name);

        ++always.MostBallTouches;
        ++current.stats.MostBallTouches;
        ++session.MostBallTouches;
        ++stats[current.playlist].MostBallTouches;
        ++always_gm[current.playlist].MostBallTouches;

        ++always.MostBallTouchesCumul;
        ++current.stats.MostBallTouchesCumul;
        ++session.MostBallTouchesCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].MostBallTouchesCumul;
            ++always_gm[it->first].MostBallTouchesCumul;
        }

        AllAccoladesMostBallTouches(true);
    }
    else if (name == "MostBoostPickups")
    {
        cvarManager->log(" --> " + name);

        ++always.MostBoostPickups;
        ++current.stats.MostBoostPickups;
        ++session.MostBoostPickups;
        ++stats[current.playlist].MostBoostPickups;
        ++always_gm[current.playlist].MostBoostPickups;

        ++always.MostBoostPickupsCumul;
        ++current.stats.MostBoostPickupsCumul;
        ++session.MostBoostPickupsCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].MostBoostPickupsCumul;
            ++always_gm[it->first].MostBoostPickupsCumul;
        }

        AllAccoladesMostBoostPickups(true);
    }
    else if (name == "FewestBallTouches")
    {
        cvarManager->log(" --> " + name);

        ++always.FewestBallTouches;
        ++current.stats.FewestBallTouches;
        ++session.FewestBallTouches;
        ++stats[current.playlist].FewestBallTouches;
        ++always_gm[current.playlist].FewestBallTouches;

        ++always.FewestBallTouchesCumul;
        ++current.stats.FewestBallTouchesCumul;
        ++session.FewestBallTouchesCumul;

        for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        {
            ++stats[it->first].FewestBallTouchesCumul;
            ++always_gm[it->first].FewestBallTouchesCumul;
        }

        AllAccoladesFewestBallTouches(true);
    }
    else
    {
        if (name == "Win" || name == "Loss" || name == "TimePlayed" || name == "BicycleHit" || name == "Shot" || name == "Assist" || name == "Save" || name == "EpicSave" || name == "Goal" || name == "AerialGoal" || name == "BackwardsGoal" || name == "BicycleGoal" || name == "LongGoal" || name == "TurtleGoal" || name == "OvertimeGoal" || name == "HoopsSwishGoal" || name == "PoolShot" || name == "FirstTouch" || name == "Savior" || name == "LowFive" || name == "HatTrick" || name == "HighFive" || name == "Playmaker" || name == "Demolish" || name == "BreakoutDamage" || name == "BreakoutDamageLarge" || name == "KO_Knockout" || name == "KO_KnockoutAssist" || name == "KO_DoubleKO" || name == "KO_HeavyHit" || name == "KO_TripleKO" || name == "KO_HeavyBlock" || name == "KO_AerialHeavyHit" || name == "KO_AerialLightHit" || name == "MVP")
            return;

        refresh = false;
        cvarManager->log("onStatEvent " + name + "[" + std::to_string(event.GetPoints()) + "]");
    }

    if (refresh)
        SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::onStatTickerMessage(ServerWrapper caller, void* params)
{
    StatTickerParams* pstats = (StatTickerParams*)params;

    CarWrapper me = gameWrapper->GetLocalCar();
    PriWrapper receiver = PriWrapper(pstats->Receiver);
    PriWrapper victim = PriWrapper(pstats->Victim);
    StatEventWrapper event = StatEventWrapper(pstats->StatEvent);

    std::string name = event.GetEventName();
    if (name == "Shot")
        name = "ShotOnGoal";

    bool iam_receiver = (!receiver.IsNull() && isPrimaryPlayer(receiver));
    bool iam_victim = (!victim.IsNull() && isPrimaryPlayer(victim));
    bool team_receiver = (!me.IsNull() && !receiver.IsNull() && me.GetTeamNum2() == receiver.GetTeamNum2());
    bool team_victim = (!me.IsNull() && !victim.IsNull() && me.GetTeamNum2() == victim.GetTeamNum2());

    SocketSend(name, {
        { "Points", event.GetPoints() },
        { "Receiver", (iam_receiver ? "me" : (team_receiver ? "team" : "no")) },
        { "Victim", (iam_victim ? "me" : (team_victim ? "team" : "no")) }
    }, "TickerMessage");

    if (!is_online_game)
        return;

    bool refresh = true;
    if (!iam_receiver && !team_receiver && !iam_victim && !team_victim) // Opponent statistics
    {
        refresh = false;
    }
    else // Self and team statistics
    {
        if (name == "BicycleHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBicycleHit;
            ++current.stats.TotalBicycleHit;
            ++session.TotalBicycleHit;
            ++stats[current.playlist].TotalBicycleHit;
            ++always_gm[current.playlist].TotalBicycleHit;

            ++(iam_receiver ? always.BicycleHit : always.TeamBicycleHit);
            ++(iam_receiver ? current.stats.BicycleHit : current.stats.TeamBicycleHit);
            ++(iam_receiver ? session.BicycleHit : session.TeamBicycleHit);
            ++(iam_receiver ? stats[current.playlist].BicycleHit : stats[current.playlist].TeamBicycleHit);
            ++(iam_receiver ? always_gm[current.playlist].BicycleHit : always_gm[current.playlist].TeamBicycleHit);

            ++always.TotalBicycleHitCumul;
            ++current.stats.TotalBicycleHitCumul;
            ++session.TotalBicycleHitCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBicycleHitCumul;
                ++always_gm[it->first].TotalBicycleHitCumul;

                ++(iam_receiver ? stats[it->first].BicycleHitCumul : stats[it->first].TeamBicycleHitCumul);
                ++(iam_receiver ? always_gm[it->first].BicycleHitCumul : always_gm[it->first].TeamBicycleHitCumul);
            }

            AllShotsBicycleHit(true);
        }
        else if (name == "ShotOnGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalShotOnGoal;
            ++current.stats.TotalShotOnGoal;
            ++session.TotalShotOnGoal;
            ++stats[current.playlist].TotalShotOnGoal;
            ++always_gm[current.playlist].TotalShotOnGoal;

            ++(iam_receiver ? always.ShotOnGoal : always.TeamShotOnGoal);
            ++(iam_receiver ? current.stats.ShotOnGoal : current.stats.TeamShotOnGoal);
            ++(iam_receiver ? session.ShotOnGoal : session.TeamShotOnGoal);
            ++(iam_receiver ? stats[current.playlist].ShotOnGoal : stats[current.playlist].TeamShotOnGoal);
            ++(iam_receiver ? always_gm[current.playlist].ShotOnGoal : always_gm[current.playlist].TeamShotOnGoal);

            ++always.TotalShotOnGoalCumul;
            ++current.stats.TotalShotOnGoalCumul;
            ++session.TotalShotOnGoalCumul;

            if (always.ShotOnGoal > 0)
                always.ShootingPercentage = static_cast<int>(static_cast<float>(always.Goal) / always.ShotOnGoal * 100);
            if (current.stats.ShotOnGoal > 0)
                current.stats.ShootingPercentage = static_cast<int>(static_cast<float>(current.stats.Goal) / current.stats.ShotOnGoal * 100);
            if (session.ShotOnGoal > 0)
                session.ShootingPercentage = static_cast<int>(static_cast<float>(session.Goal) / session.ShotOnGoal * 100);
            
            if (always.TeamShotOnGoal > 0)
                always.TeamShootingPercentage = static_cast<int>(static_cast<float>(always.TeamGoal) / always.TeamShotOnGoal * 100);
            if (current.stats.TeamShotOnGoal > 0)
                current.stats.TeamShootingPercentage = static_cast<int>(static_cast<float>(current.stats.TeamGoal) / current.stats.TeamShotOnGoal * 100);
            if (session.TeamShotOnGoal > 0)
                session.TeamShootingPercentage = static_cast<int>(static_cast<float>(session.TeamGoal) / session.TeamShotOnGoal * 100);

            if (stats[current.playlist].ShotOnGoal > 0)
                stats[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].Goal) / stats[current.playlist].ShotOnGoal * 100);
            if (stats[current.playlist].TeamShotOnGoal > 0)
                stats[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].TeamGoal) / stats[current.playlist].TeamShotOnGoal * 100);

            if (always_gm[current.playlist].ShotOnGoal > 0)
                always_gm[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].Goal) / always_gm[current.playlist].ShotOnGoal * 100);
            if (always_gm[current.playlist].TeamShotOnGoal > 0)
                always_gm[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].TeamGoal) / always_gm[current.playlist].TeamShotOnGoal * 100);

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalShotOnGoalCumul;
                ++always_gm[it->first].TotalShotOnGoalCumul;

                if (stats[it->first].TotalShotOnGoalCumul > 0)
                    stats[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TotalGoalCumul) / stats[it->first].TotalShotOnGoalCumul * 100);
                if (always_gm[it->first].TotalShotOnGoalCumul > 0)
                    always_gm[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TotalGoalCumul) / always_gm[it->first].TotalShotOnGoalCumul * 100);

                ++(iam_receiver ? stats[it->first].ShotOnGoalCumul : stats[it->first].TeamShotOnGoalCumul);
                ++(iam_receiver ? always_gm[it->first].ShotOnGoalCumul : always_gm[it->first].TeamShotOnGoalCumul);

                if (stats[it->first].ShotOnGoalCumul > 0)
                    stats[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].GoalCumul) / stats[it->first].ShotOnGoalCumul * 100);
                if (stats[it->first].TeamShotOnGoalCumul > 0)
                    stats[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TeamGoalCumul) / stats[it->first].TeamShotOnGoalCumul * 100);

                if (always_gm[it->first].ShotOnGoalCumul > 0)
                    always_gm[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].GoalCumul) / always_gm[it->first].ShotOnGoalCumul * 100);
                if (always_gm[it->first].TeamShotOnGoalCumul > 0)
                    always_gm[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TeamGoalCumul) / always_gm[it->first].TeamShotOnGoalCumul * 100);
            }

            AllShotsShotOnGoal(true);
        }
        else if (name == "Assist")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalAssist;
            ++current.stats.TotalAssist;
            ++session.TotalAssist;
            ++stats[current.playlist].TotalAssist;
            ++always_gm[current.playlist].TotalAssist;

            ++(iam_receiver ? always.Assist : always.TeamAssist);
            ++(iam_receiver ? current.stats.Assist : current.stats.TeamAssist);
            ++(iam_receiver ? session.Assist : session.TeamAssist);
            ++(iam_receiver ? stats[current.playlist].Assist : stats[current.playlist].TeamAssist);
            ++(iam_receiver ? always_gm[current.playlist].Assist : always_gm[current.playlist].TeamAssist);

            ++always.TotalAssistCumul;
            ++current.stats.TotalAssistCumul;
            ++session.TotalAssistCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalAssistCumul;
                ++always_gm[it->first].TotalAssistCumul;

                ++(iam_receiver ? stats[it->first].AssistCumul : stats[it->first].TeamAssistCumul);
                ++(iam_receiver ? always_gm[it->first].AssistCumul : always_gm[it->first].TeamAssistCumul);
            }

            AllShotsAssist(true);
        }
        else if (name == "Save")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalSave;
            ++current.stats.TotalSave;
            ++session.TotalSave;
            ++stats[current.playlist].TotalSave;
            ++always_gm[current.playlist].TotalSave;

            ++(iam_receiver ? always.Save : always.TeamSave);
            ++(iam_receiver ? current.stats.Save : current.stats.TeamSave);
            ++(iam_receiver ? session.Save : session.TeamSave);
            ++(iam_receiver ? stats[current.playlist].Save : stats[current.playlist].TeamSave);
            ++(iam_receiver ? always_gm[current.playlist].Save : always_gm[current.playlist].TeamSave);

            ++always.TotalSaveCumul;
            ++current.stats.TotalSaveCumul;
            ++session.TotalSaveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalSaveCumul;
                ++always_gm[it->first].TotalSaveCumul;

                ++(iam_receiver ? stats[it->first].SaveCumul : stats[it->first].TeamSaveCumul);
                ++(iam_receiver ? always_gm[it->first].SaveCumul : always_gm[it->first].TeamSaveCumul);
            }

            AllSavesSave(true);
        }
        else if (name == "EpicSave")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalEpicSave;
            ++current.stats.TotalEpicSave;
            ++session.TotalEpicSave;
            ++stats[current.playlist].TotalEpicSave;
            ++always_gm[current.playlist].TotalEpicSave;

            ++(iam_receiver ? always.EpicSave : always.TeamEpicSave);
            ++(iam_receiver ? current.stats.EpicSave : current.stats.TeamEpicSave);
            ++(iam_receiver ? session.EpicSave : session.TeamEpicSave);
            ++(iam_receiver ? stats[current.playlist].EpicSave : stats[current.playlist].TeamEpicSave);
            ++(iam_receiver ? always_gm[current.playlist].EpicSave : always_gm[current.playlist].TeamEpicSave);

            ++always.TotalEpicSaveCumul;
            ++current.stats.TotalEpicSaveCumul;
            ++session.TotalEpicSaveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalEpicSaveCumul;
                ++always_gm[it->first].TotalEpicSaveCumul;

                ++(iam_receiver ? stats[it->first].EpicSaveCumul : stats[it->first].TeamEpicSaveCumul);
                ++(iam_receiver ? always_gm[it->first].EpicSaveCumul : always_gm[it->first].TeamEpicSaveCumul);
            }

            AllSavesEpicSave(true);
        }
        else if (name == "Goal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalGoal;
            ++current.stats.TotalGoal;
            ++session.TotalGoal;
            ++stats[current.playlist].TotalGoal;
            ++always_gm[current.playlist].TotalGoal;

            ++(iam_receiver ? always.Goal : always.TeamGoal);
            ++(iam_receiver ? current.stats.Goal : current.stats.TeamGoal);
            ++(iam_receiver ? session.Goal : session.TeamGoal);
            ++(iam_receiver ? stats[current.playlist].Goal : stats[current.playlist].TeamGoal);
            ++(iam_receiver ? always_gm[current.playlist].Goal : always_gm[current.playlist].TeamGoal);

            ++always.TotalGoalCumul;
            ++current.stats.TotalGoalCumul;
            ++session.TotalGoalCumul;

            if (always.ShotOnGoal > 0)
                always.ShootingPercentage = static_cast<int>(static_cast<float>(always.Goal) / always.ShotOnGoal * 100);
            if (current.stats.ShotOnGoal > 0)
                current.stats.ShootingPercentage = static_cast<int>(static_cast<float>(current.stats.Goal) / current.stats.ShotOnGoal * 100);
            if (session.ShotOnGoal > 0)
                session.ShootingPercentage = static_cast<int>(static_cast<float>(session.Goal) / session.ShotOnGoal * 100);

            if (always.TeamShotOnGoal > 0)
                always.TeamShootingPercentage = static_cast<int>(static_cast<float>(always.TeamGoal) / always.TeamShotOnGoal * 100);
            if (current.stats.TeamShotOnGoal > 0)
                current.stats.TeamShootingPercentage = static_cast<int>(static_cast<float>(current.stats.TeamGoal) / current.stats.TeamShotOnGoal * 100);
            if (session.TeamShotOnGoal > 0)
                session.TeamShootingPercentage = static_cast<int>(static_cast<float>(session.TeamGoal) / session.TeamShotOnGoal * 100);

            if (stats[current.playlist].ShotOnGoal > 0)
                stats[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].Goal) / stats[current.playlist].ShotOnGoal * 100);
            if (stats[current.playlist].TeamShotOnGoal > 0)
                stats[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(stats[current.playlist].TeamGoal) / stats[current.playlist].TeamShotOnGoal * 100);

            if (always_gm[current.playlist].ShotOnGoal > 0)
                always_gm[current.playlist].ShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].Goal) / always_gm[current.playlist].ShotOnGoal * 100);
            if (always_gm[current.playlist].TeamShotOnGoal > 0)
                always_gm[current.playlist].TeamShootingPercentage = static_cast<int>(static_cast<float>(always_gm[current.playlist].TeamGoal) / always_gm[current.playlist].TeamShotOnGoal * 100);

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalGoalCumul;
                ++always_gm[it->first].TotalGoalCumul;

                if (stats[it->first].TotalShotOnGoalCumul > 0)
                    stats[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TotalGoalCumul) / stats[it->first].TotalShotOnGoalCumul * 100);
                if (always_gm[it->first].TotalShotOnGoalCumul > 0)
                    always_gm[it->first].TotalShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TotalGoalCumul) / always_gm[it->first].TotalShotOnGoalCumul * 100);

                ++(iam_receiver ? stats[it->first].GoalCumul : stats[it->first].TeamGoalCumul);
                ++(iam_receiver ? always_gm[it->first].GoalCumul : always_gm[it->first].TeamGoalCumul);

                if (stats[it->first].ShotOnGoalCumul > 0)
                    stats[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].GoalCumul) / stats[it->first].ShotOnGoalCumul * 100);
                if (stats[it->first].TeamShotOnGoalCumul > 0)
                    stats[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(stats[it->first].TeamGoalCumul) / stats[it->first].TeamShotOnGoalCumul * 100);

                if (always_gm[it->first].ShotOnGoalCumul > 0)
                    always_gm[it->first].ShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].GoalCumul) / always_gm[it->first].ShotOnGoalCumul * 100);
                if (always_gm[it->first].TeamShotOnGoalCumul > 0)
                    always_gm[it->first].TeamShootingPercentageCumul = static_cast<int>(static_cast<float>(always_gm[it->first].TeamGoalCumul) / always_gm[it->first].TeamShotOnGoalCumul * 100);
            }

            AllGoalsGoal(true);
        }
        else if (name == "AerialGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalAerialGoal;
            ++current.stats.TotalAerialGoal;
            ++session.TotalAerialGoal;
            ++stats[current.playlist].TotalAerialGoal;
            ++always_gm[current.playlist].TotalAerialGoal;

            ++(iam_receiver ? always.AerialGoal : always.TeamAerialGoal);
            ++(iam_receiver ? current.stats.AerialGoal : current.stats.TeamAerialGoal);
            ++(iam_receiver ? session.AerialGoal : session.TeamAerialGoal);
            ++(iam_receiver ? stats[current.playlist].AerialGoal : stats[current.playlist].TeamAerialGoal);
            ++(iam_receiver ? always_gm[current.playlist].AerialGoal : always_gm[current.playlist].TeamAerialGoal);

            ++always.TotalAerialGoalCumul;
            ++current.stats.TotalAerialGoalCumul;
            ++session.TotalAerialGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalAerialGoalCumul;
                ++always_gm[it->first].TotalAerialGoalCumul;

                ++(iam_receiver ? stats[it->first].AerialGoalCumul : stats[it->first].TeamAerialGoalCumul);
                ++(iam_receiver ? always_gm[it->first].AerialGoalCumul : always_gm[it->first].TeamAerialGoalCumul);
            }

            AllGoalsAerialGoal(true);
        }
        else if (name == "BackwardsGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBackwardsGoal;
            ++current.stats.TotalBackwardsGoal;
            ++session.TotalBackwardsGoal;
            ++stats[current.playlist].TotalBackwardsGoal;
            ++always_gm[current.playlist].TotalBackwardsGoal;

            ++(iam_receiver ? always.BackwardsGoal : always.TeamBackwardsGoal);
            ++(iam_receiver ? current.stats.BackwardsGoal : current.stats.TeamBackwardsGoal);
            ++(iam_receiver ? session.BackwardsGoal : session.TeamBackwardsGoal);
            ++(iam_receiver ? stats[current.playlist].BackwardsGoal : stats[current.playlist].TeamBackwardsGoal);
            ++(iam_receiver ? always_gm[current.playlist].BackwardsGoal : always_gm[current.playlist].TeamBackwardsGoal);

            ++always.TotalBackwardsGoalCumul;
            ++current.stats.TotalBackwardsGoalCumul;
            ++session.TotalBackwardsGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBackwardsGoalCumul;
                ++always_gm[it->first].TotalBackwardsGoalCumul;

                ++(iam_receiver ? stats[it->first].BackwardsGoalCumul : stats[it->first].TeamBackwardsGoalCumul);
                ++(iam_receiver ? always_gm[it->first].BackwardsGoalCumul : always_gm[it->first].TeamBackwardsGoalCumul);
            }

            AllGoalsBackwardsGoal(true);
        }
        else if (name == "BicycleGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBicycleGoal;
            ++current.stats.TotalBicycleGoal;
            ++session.TotalBicycleGoal;
            ++stats[current.playlist].TotalBicycleGoal;
            ++always_gm[current.playlist].TotalBicycleGoal;

            ++(iam_receiver ? always.BicycleGoal : always.TeamBicycleGoal);
            ++(iam_receiver ? current.stats.BicycleGoal : current.stats.TeamBicycleGoal);
            ++(iam_receiver ? session.BicycleGoal : session.TeamBicycleGoal);
            ++(iam_receiver ? stats[current.playlist].BicycleGoal : stats[current.playlist].TeamBicycleGoal);
            ++(iam_receiver ? always_gm[current.playlist].BicycleGoal : always_gm[current.playlist].TeamBicycleGoal);

            ++always.TotalBicycleGoalCumul;
            ++current.stats.TotalBicycleGoalCumul;
            ++session.TotalBicycleGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBicycleGoalCumul;
                ++always_gm[it->first].TotalBicycleGoalCumul;

                ++(iam_receiver ? stats[it->first].BicycleGoalCumul : stats[it->first].TeamBicycleGoalCumul);
                ++(iam_receiver ? always_gm[it->first].BicycleGoalCumul : always_gm[it->first].TeamBicycleGoalCumul);
            }

            AllGoalsBicycleGoal(true);
        }
        else if (name == "LongGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalLongGoal;
            ++current.stats.TotalLongGoal;
            ++session.TotalLongGoal;
            ++stats[current.playlist].TotalLongGoal;
            ++always_gm[current.playlist].TotalLongGoal;

            ++(iam_receiver ? always.LongGoal : always.TeamLongGoal);
            ++(iam_receiver ? current.stats.LongGoal : current.stats.TeamLongGoal);
            ++(iam_receiver ? session.LongGoal : session.TeamLongGoal);
            ++(iam_receiver ? stats[current.playlist].LongGoal : stats[current.playlist].TeamLongGoal);
            ++(iam_receiver ? always_gm[current.playlist].LongGoal : always_gm[current.playlist].TeamLongGoal);

            ++always.TotalLongGoalCumul;
            ++current.stats.TotalLongGoalCumul;
            ++session.TotalLongGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalLongGoalCumul;
                ++always_gm[it->first].TotalLongGoalCumul;

                ++(iam_receiver ? stats[it->first].LongGoalCumul : stats[it->first].TeamLongGoalCumul);
                ++(iam_receiver ? always_gm[it->first].LongGoalCumul : always_gm[it->first].TeamLongGoalCumul);
            }

            AllGoalsLongGoal(true);
        }
        else if (name == "TurtleGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalTurtleGoal;
            ++current.stats.TotalTurtleGoal;
            ++session.TotalTurtleGoal;
            ++stats[current.playlist].TotalTurtleGoal;
            ++always_gm[current.playlist].TotalTurtleGoal;

            ++(iam_receiver ? always.TurtleGoal : always.TeamTurtleGoal);
            ++(iam_receiver ? current.stats.TurtleGoal : current.stats.TeamTurtleGoal);
            ++(iam_receiver ? session.TurtleGoal : session.TeamTurtleGoal);
            ++(iam_receiver ? stats[current.playlist].TurtleGoal : stats[current.playlist].TeamTurtleGoal);
            ++(iam_receiver ? always_gm[current.playlist].TurtleGoal : always_gm[current.playlist].TeamTurtleGoal);

            ++always.TotalTurtleGoalCumul;
            ++current.stats.TotalTurtleGoalCumul;
            ++session.TotalTurtleGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalTurtleGoalCumul;
                ++always_gm[it->first].TotalTurtleGoalCumul;

                ++(iam_receiver ? stats[it->first].TurtleGoalCumul : stats[it->first].TeamTurtleGoalCumul);
                ++(iam_receiver ? always_gm[it->first].TurtleGoalCumul : always_gm[it->first].TeamTurtleGoalCumul);
            }

            AllGoalsTurtleGoal(true);
        }
        else if (name == "OvertimeGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalOvertimeGoal;
            ++current.stats.TotalOvertimeGoal;
            ++session.TotalOvertimeGoal;
            ++stats[current.playlist].TotalOvertimeGoal;
            ++always_gm[current.playlist].TotalOvertimeGoal;

            ++(iam_receiver ? always.OvertimeGoal : always.TeamOvertimeGoal);
            ++(iam_receiver ? current.stats.OvertimeGoal : current.stats.TeamOvertimeGoal);
            ++(iam_receiver ? session.OvertimeGoal : session.TeamOvertimeGoal);
            ++(iam_receiver ? stats[current.playlist].OvertimeGoal : stats[current.playlist].TeamOvertimeGoal);
            ++(iam_receiver ? always_gm[current.playlist].OvertimeGoal : always_gm[current.playlist].TeamOvertimeGoal);

            ++always.TotalOvertimeGoalCumul;
            ++current.stats.TotalOvertimeGoalCumul;
            ++session.TotalOvertimeGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalOvertimeGoalCumul;
                ++always_gm[it->first].TotalOvertimeGoalCumul;

                ++(iam_receiver ? stats[it->first].OvertimeGoalCumul : stats[it->first].TeamOvertimeGoalCumul);
                ++(iam_receiver ? always_gm[it->first].OvertimeGoalCumul : always_gm[it->first].TeamOvertimeGoalCumul);
            }

            AllGoalsOvertimeGoal(true);
        }
        else if (name == "HoopsSwishGoal")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalHoopsSwishGoal;
            ++current.stats.TotalHoopsSwishGoal;
            ++session.TotalHoopsSwishGoal;
            ++stats[current.playlist].TotalHoopsSwishGoal;
            ++always_gm[current.playlist].TotalHoopsSwishGoal;

            ++(iam_receiver ? always.HoopsSwishGoal : always.TeamHoopsSwishGoal);
            ++(iam_receiver ? current.stats.HoopsSwishGoal : current.stats.TeamHoopsSwishGoal);
            ++(iam_receiver ? session.HoopsSwishGoal : session.TeamHoopsSwishGoal);
            ++(iam_receiver ? stats[current.playlist].HoopsSwishGoal : stats[current.playlist].TeamHoopsSwishGoal);
            ++(iam_receiver ? always_gm[current.playlist].HoopsSwishGoal : always_gm[current.playlist].TeamHoopsSwishGoal);

            ++always.TotalHoopsSwishGoalCumul;
            ++current.stats.TotalHoopsSwishGoalCumul;
            ++session.TotalHoopsSwishGoalCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalHoopsSwishGoalCumul;
                ++always_gm[it->first].TotalHoopsSwishGoalCumul;

                ++(iam_receiver ? stats[it->first].HoopsSwishGoalCumul : stats[it->first].TeamHoopsSwishGoalCumul);
                ++(iam_receiver ? always_gm[it->first].HoopsSwishGoalCumul : always_gm[it->first].TeamHoopsSwishGoalCumul);
            }

            AllGoalsHoopsSwishGoal(true);
        }
        else if (name == "PoolShot")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalPoolShot;
            ++current.stats.TotalPoolShot;
            ++session.TotalPoolShot;
            ++stats[current.playlist].TotalPoolShot;
            ++always_gm[current.playlist].TotalPoolShot;

            ++(iam_receiver ? always.PoolShot : always.TeamPoolShot);
            ++(iam_receiver ? current.stats.PoolShot : current.stats.TeamPoolShot);
            ++(iam_receiver ? session.PoolShot : session.TeamPoolShot);
            ++(iam_receiver ? stats[current.playlist].PoolShot : stats[current.playlist].TeamPoolShot);
            ++(iam_receiver ? always_gm[current.playlist].PoolShot : always_gm[current.playlist].TeamPoolShot);

            ++always.TotalPoolShotCumul;
            ++current.stats.TotalPoolShotCumul;
            ++session.TotalPoolShotCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalPoolShotCumul;
                ++always_gm[it->first].TotalPoolShotCumul;

                ++(iam_receiver ? stats[it->first].PoolShotCumul : stats[it->first].TeamPoolShotCumul);
                ++(iam_receiver ? always_gm[it->first].PoolShotCumul : always_gm[it->first].TeamPoolShotCumul);
            }

            AllGoalsPoolShot(true);
        }
        else if (name == "FirstTouch")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.FirstTouch;
            ++current.stats.FirstTouch;
            ++session.FirstTouch;
            ++stats[current.playlist].FirstTouch;
            ++always_gm[current.playlist].FirstTouch;

            ++always.FirstTouchCumul;
            ++current.stats.FirstTouchCumul;
            ++session.FirstTouchCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].FirstTouchCumul;
                ++always_gm[it->first].FirstTouchCumul;
            }

            AllMiscsFirstTouch(true);
        }
        else if (name == "Savior")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalSavior;
            ++current.stats.TotalSavior;
            ++session.TotalSavior;
            ++stats[current.playlist].TotalSavior;
            ++always_gm[current.playlist].TotalSavior;

            ++(iam_receiver ? always.Savior : always.TeamSavior);
            ++(iam_receiver ? current.stats.Savior : current.stats.TeamSavior);
            ++(iam_receiver ? session.Savior : session.TeamSavior);
            ++(iam_receiver ? stats[current.playlist].Savior : stats[current.playlist].TeamSavior);
            ++(iam_receiver ? always_gm[current.playlist].Savior : always_gm[current.playlist].TeamSavior);

            ++always.TotalSaviorCumul;
            ++current.stats.TotalSaviorCumul;
            ++session.TotalSaviorCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalSaviorCumul;
                ++always_gm[it->first].TotalSaviorCumul;

                ++(iam_receiver ? stats[it->first].SaviorCumul : stats[it->first].TeamSaviorCumul);
                ++(iam_receiver ? always_gm[it->first].SaviorCumul : always_gm[it->first].TeamSaviorCumul);
            }

            AllMiscsSavior(true);
        }
        else if (name == "LowFive")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalLowFive;
            ++current.stats.TotalLowFive;
            ++session.TotalLowFive;
            ++stats[current.playlist].TotalLowFive;
            ++always_gm[current.playlist].TotalLowFive;

            ++(iam_receiver ? always.LowFive : always.TeamLowFive);
            ++(iam_receiver ? current.stats.LowFive : current.stats.TeamLowFive);
            ++(iam_receiver ? session.LowFive : session.TeamLowFive);
            ++(iam_receiver ? stats[current.playlist].LowFive : stats[current.playlist].TeamLowFive);
            ++(iam_receiver ? always_gm[current.playlist].LowFive : always_gm[current.playlist].TeamLowFive);

            ++always.TotalLowFiveCumul;
            ++current.stats.TotalLowFiveCumul;
            ++session.TotalLowFiveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalLowFiveCumul;
                ++always_gm[it->first].TotalLowFiveCumul;

                ++(iam_receiver ? stats[it->first].LowFiveCumul : stats[it->first].TeamLowFiveCumul);
                ++(iam_receiver ? always_gm[it->first].LowFiveCumul : always_gm[it->first].TeamLowFiveCumul);
            }

            AllMiscsLowFive(true);
        }
        else if (name == "HatTrick")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalHatTrick;
            ++current.stats.TotalHatTrick;
            ++session.TotalHatTrick;
            ++stats[current.playlist].TotalHatTrick;
            ++always_gm[current.playlist].TotalHatTrick;

            ++(iam_receiver ? always.HatTrick : always.TeamHatTrick);
            ++(iam_receiver ? current.stats.HatTrick : current.stats.TeamHatTrick);
            ++(iam_receiver ? session.HatTrick : session.TeamHatTrick);
            ++(iam_receiver ? stats[current.playlist].HatTrick : stats[current.playlist].TeamHatTrick);
            ++(iam_receiver ? always_gm[current.playlist].HatTrick : always_gm[current.playlist].TeamHatTrick);

            ++always.TotalHatTrickCumul;
            ++current.stats.TotalHatTrickCumul;
            ++session.TotalHatTrickCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalHatTrickCumul;
                ++always_gm[it->first].TotalHatTrickCumul;

                ++(iam_receiver ? stats[it->first].HatTrickCumul : stats[it->first].TeamHatTrickCumul);
                ++(iam_receiver ? always_gm[it->first].HatTrickCumul : always_gm[it->first].TeamHatTrickCumul);
            }

            AllMiscsHatTrick(true);
        }
        else if (name == "HighFive")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalHighFive;
            ++current.stats.TotalHighFive;
            ++session.TotalHighFive;
            ++stats[current.playlist].TotalHighFive;
            ++always_gm[current.playlist].TotalHighFive;

            ++(iam_receiver ? always.HighFive : always.TeamHighFive);
            ++(iam_receiver ? current.stats.HighFive : current.stats.TeamHighFive);
            ++(iam_receiver ? session.HighFive : session.TeamHighFive);
            ++(iam_receiver ? stats[current.playlist].HighFive : stats[current.playlist].TeamHighFive);
            ++(iam_receiver ? always_gm[current.playlist].HighFive : always_gm[current.playlist].TeamHighFive);

            ++always.TotalHighFiveCumul;
            ++current.stats.TotalHighFiveCumul;
            ++session.TotalHighFiveCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalHighFiveCumul;
                ++always_gm[it->first].TotalHighFiveCumul;

                ++(iam_receiver ? stats[it->first].HighFiveCumul : stats[it->first].TeamHighFiveCumul);
                ++(iam_receiver ? always_gm[it->first].HighFiveCumul : always_gm[it->first].TeamHighFiveCumul);
            }

            AllMiscsHighFive(true);
        }
        else if (name == "Playmaker")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalPlaymaker;
            ++current.stats.TotalPlaymaker;
            ++session.TotalPlaymaker;
            ++stats[current.playlist].TotalPlaymaker;
            ++always_gm[current.playlist].TotalPlaymaker;

            ++(iam_receiver ? always.Playmaker : always.TeamPlaymaker);
            ++(iam_receiver ? current.stats.Playmaker : current.stats.TeamPlaymaker);
            ++(iam_receiver ? session.Playmaker : session.TeamPlaymaker);
            ++(iam_receiver ? stats[current.playlist].Playmaker : stats[current.playlist].TeamPlaymaker);
            ++(iam_receiver ? always_gm[current.playlist].Playmaker : always_gm[current.playlist].TeamPlaymaker);

            ++always.TotalPlaymakerCumul;
            ++current.stats.TotalPlaymakerCumul;
            ++session.TotalPlaymakerCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalPlaymakerCumul;
                ++always_gm[it->first].TotalPlaymakerCumul;

                ++(iam_receiver ? stats[it->first].PlaymakerCumul : stats[it->first].TeamPlaymakerCumul);
                ++(iam_receiver ? always_gm[it->first].PlaymakerCumul : always_gm[it->first].TeamPlaymakerCumul);
            }

            AllMiscsPlaymaker(true);
        }
        else if (name == "Demolish")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            if (iam_receiver || iam_victim || team_receiver || team_victim)
            {
                ++((iam_receiver || team_receiver) ? always.TotalDemolitions : always.TotalDeath);
                ++((iam_receiver || team_receiver) ? current.stats.TotalDemolitions : current.stats.TotalDeath);
                ++((iam_receiver || team_receiver) ? session.TotalDemolitions : session.TotalDeath);
                ++((iam_receiver || team_receiver) ? stats[current.playlist].TotalDemolitions : stats[current.playlist].TotalDeath);
                ++((iam_receiver || team_receiver) ? always_gm[current.playlist].TotalDemolitions : always_gm[current.playlist].TotalDeath);

                ++((iam_receiver || team_receiver) ? always.TotalDemolitionsCumul : always.TotalDeathCumul);
                ++((iam_receiver || team_receiver) ? current.stats.TotalDemolitionsCumul : current.stats.TotalDeathCumul);
                ++((iam_receiver || team_receiver) ? session.TotalDemolitionsCumul : session.TotalDeathCumul);

                for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
                {
                    ++((iam_receiver || team_receiver) ? stats[it->first].TotalDemolitionsCumul : stats[it->first].TotalDeathCumul);
                    ++((iam_receiver || team_receiver) ? always_gm[it->first].TotalDemolitionsCumul : always_gm[it->first].TotalDeathCumul);
                }
            }

            if (iam_receiver || iam_victim)
            {
                ++(iam_receiver ? always.Demolitions : always.Death);
                ++(iam_receiver ? current.stats.Demolitions : current.stats.Death);
                ++(iam_receiver ? session.Demolitions : session.Death);
                ++(iam_receiver ? stats[current.playlist].Demolitions : stats[current.playlist].Death);
                ++(iam_receiver ? always_gm[current.playlist].Demolitions : always_gm[current.playlist].Death);

                ++(iam_receiver ? always.DemolitionsCumul : always.DeathCumul);
                ++(iam_receiver ? current.stats.DemolitionsCumul : current.stats.DeathCumul);
                ++(iam_receiver ? session.DemolitionsCumul : session.DeathCumul);

                for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
                {
                    ++(iam_receiver ? stats[it->first].DemolitionsCumul : stats[it->first].DeathCumul);
                    ++(iam_receiver ? always_gm[it->first].DemolitionsCumul : always_gm[it->first].DeathCumul);
                }

                if (iam_receiver)
                    AllMiscsDemolitions(true);
                else
                    AllMiscsDeath(true);
            }
            else if (team_receiver || team_victim)
            {
                ++(team_receiver ? always.TeamDemolitions : always.TeamDeath);
                ++(team_receiver ? current.stats.TeamDemolitions : current.stats.TeamDeath);
                ++(team_receiver ? session.TeamDemolitions : session.TeamDeath);
                ++(team_receiver ? stats[current.playlist].TeamDemolitions : stats[current.playlist].TeamDeath);
                ++(team_receiver ? always_gm[current.playlist].TeamDemolitions : always_gm[current.playlist].TeamDeath);

                ++(team_receiver ? always.TeamDemolitionsCumul : always.TeamDeathCumul);
                ++(team_receiver ? current.stats.TeamDemolitionsCumul : current.stats.TeamDeathCumul);
                ++(team_receiver ? session.TeamDemolitionsCumul : session.TeamDeathCumul);

                for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
                {
                    ++(team_receiver ? stats[it->first].TeamDemolitionsCumul : stats[it->first].TeamDeathCumul);
                    ++(team_receiver ? always_gm[it->first].TeamDemolitionsCumul : always_gm[it->first].TeamDeathCumul);
                }

                if (team_receiver)
                    AllMiscsDemolitions(true);
                else
                    AllMiscsDeath(true);
            }
        }
        else if (name == "BreakoutDamage")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBreakoutDamage;
            ++current.stats.TotalBreakoutDamage;
            ++session.TotalBreakoutDamage;
            ++stats[current.playlist].TotalBreakoutDamage;
            ++always_gm[current.playlist].TotalBreakoutDamage;

            ++(iam_receiver ? always.BreakoutDamage : always.TeamBreakoutDamage);
            ++(iam_receiver ? current.stats.BreakoutDamage : current.stats.TeamBreakoutDamage);
            ++(iam_receiver ? session.BreakoutDamage : session.TeamBreakoutDamage);
            ++(iam_receiver ? stats[current.playlist].BreakoutDamage : stats[current.playlist].TeamBreakoutDamage);
            ++(iam_receiver ? always_gm[current.playlist].BreakoutDamage : always_gm[current.playlist].TeamBreakoutDamage);

            ++always.TotalBreakoutDamageCumul;
            ++current.stats.TotalBreakoutDamageCumul;
            ++session.TotalBreakoutDamageCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBreakoutDamageCumul;
                ++always_gm[it->first].TotalBreakoutDamageCumul;

                ++(iam_receiver ? stats[it->first].BreakoutDamageCumul : stats[it->first].TeamBreakoutDamageCumul);
                ++(iam_receiver ? always_gm[it->first].BreakoutDamageCumul : always_gm[it->first].TeamBreakoutDamageCumul);
            }

            AllDropshotBreakoutDamage(true);
        }
        else if (name == "BreakoutDamageLarge")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalBreakoutDamageLarge;
            ++current.stats.TotalBreakoutDamageLarge;
            ++session.TotalBreakoutDamageLarge;
            ++stats[current.playlist].TotalBreakoutDamageLarge;
            ++always_gm[current.playlist].TotalBreakoutDamageLarge;

            ++(iam_receiver ? always.BreakoutDamageLarge : always.TeamBreakoutDamageLarge);
            ++(iam_receiver ? current.stats.BreakoutDamageLarge : current.stats.TeamBreakoutDamageLarge);
            ++(iam_receiver ? session.BreakoutDamageLarge : session.TeamBreakoutDamageLarge);
            ++(iam_receiver ? stats[current.playlist].BreakoutDamageLarge : stats[current.playlist].TeamBreakoutDamageLarge);
            ++(iam_receiver ? always_gm[current.playlist].BreakoutDamageLarge : always_gm[current.playlist].TeamBreakoutDamageLarge);

            ++always.TotalBreakoutDamageLargeCumul;
            ++current.stats.TotalBreakoutDamageLargeCumul;
            ++session.TotalBreakoutDamageLargeCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalBreakoutDamageLargeCumul;
                ++always_gm[it->first].TotalBreakoutDamageLargeCumul;

                ++(iam_receiver ? stats[it->first].BreakoutDamageLargeCumul : stats[it->first].TeamBreakoutDamageLargeCumul);
                ++(iam_receiver ? always_gm[it->first].BreakoutDamageLargeCumul : always_gm[it->first].TeamBreakoutDamageLargeCumul);
            }

            AllDropshotBreakoutDamageLarge(true);
        }
        else if (name == "KO_Knockout" && (iam_receiver || iam_victim))
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++(iam_receiver ? always.KnockoutKO : always.Death);
            ++(iam_receiver ? current.stats.KnockoutKO : current.stats.Death);
            ++(iam_receiver ? session.KnockoutKO : session.Death);
            ++(iam_receiver ? stats[current.playlist].KnockoutKO : stats[current.playlist].Death);
            ++(iam_receiver ? always_gm[current.playlist].KnockoutKO : always_gm[current.playlist].Death);

            ++(iam_receiver ? always.KnockoutKOCumul : always.DeathCumul);
            ++(iam_receiver ? current.stats.KnockoutKOCumul : current.stats.DeathCumul);
            ++(iam_receiver ? session.KnockoutKOCumul : session.DeathCumul);

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++(iam_receiver ? stats[it->first].KnockoutKOCumul : stats[it->first].DeathCumul);
                ++(iam_receiver ? always_gm[it->first].KnockoutKOCumul : always_gm[it->first].DeathCumul);
            }

            if (iam_receiver)
                AllKnockoutKO(true);
            else
                AllKnockoutDeath(true);
        }
        else if (name == "KO_KnockoutAssist")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutAssist;
            ++current.stats.KnockoutAssist;
            ++session.KnockoutAssist;
            ++stats[current.playlist].KnockoutAssist;
            ++always_gm[current.playlist].KnockoutAssist;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutAssistCumul;
                ++always_gm[it->first].KnockoutAssistCumul;
            }

            AllKnockoutAssist(true);
        }
        else if (name == "KO_DoubleKO" && iam_receiver)
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutDoubleKO;
            ++current.stats.KnockoutDoubleKO;
            ++session.KnockoutDoubleKO;
            ++stats[current.playlist].KnockoutDoubleKO;
            ++always_gm[current.playlist].KnockoutDoubleKO;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutDoubleKOCumul;
                ++always_gm[it->first].KnockoutDoubleKOCumul;
            }

            AllKnockoutDoubleKO(true);
        }
        else if (name == "KO_HeavyHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutHeavyHit;
            ++current.stats.KnockoutHeavyHit;
            ++session.KnockoutHeavyHit;
            ++stats[current.playlist].KnockoutHeavyHit;
            ++always_gm[current.playlist].KnockoutHeavyHit;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutHeavyHitCumul;
                ++always_gm[it->first].KnockoutHeavyHitCumul;
            }

            AllKnockoutHeavyHit(true);
        }
        else if (name == "KO_TripleKO")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutTripleKO;
            ++current.stats.KnockoutTripleKO;
            ++session.KnockoutTripleKO;
            ++stats[current.playlist].KnockoutTripleKO;
            ++always_gm[current.playlist].KnockoutTripleKO;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutTripleKOCumul;
                ++always_gm[it->first].KnockoutTripleKOCumul;
            }

            AllKnockoutTripleKO(true);
        }
        else if (name == "KO_HeavyBlock")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutHeavyBlock;
            ++current.stats.KnockoutHeavyBlock;
            ++session.KnockoutHeavyBlock;
            ++stats[current.playlist].KnockoutHeavyBlock;
            ++always_gm[current.playlist].KnockoutHeavyBlock;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutHeavyBlockCumul;
                ++always_gm[it->first].KnockoutHeavyBlockCumul;
            }

            AllKnockoutHeavyBlock(true);
        }
        else if (name == "KO_AerialHeavyHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutAerialHeavyHit;
            ++current.stats.KnockoutAerialHeavyHit;
            ++session.KnockoutAerialHeavyHit;
            ++stats[current.playlist].KnockoutAerialHeavyHit;
            ++always_gm[current.playlist].KnockoutAerialHeavyHit;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutAerialHeavyHitCumul;
                ++always_gm[it->first].KnockoutAerialHeavyHitCumul;
            }

            AllKnockoutAerialHeavyHit(true);
        }
        else if (name == "KO_AerialLightHit")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.KnockoutAerialLightHit;
            ++current.stats.KnockoutAerialLightHit;
            ++session.KnockoutAerialLightHit;
            ++stats[current.playlist].KnockoutAerialLightHit;
            ++always_gm[current.playlist].KnockoutAerialLightHit;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].KnockoutAerialLightHitCumul;
                ++always_gm[it->first].KnockoutAerialLightHitCumul;
            }

            AllKnockoutAerialLightHit(true);
        }
        else if (name == "MVP")
        {
            cvarManager->log(" --> " + name + " receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));

            ++always.TotalMVP;
            ++current.stats.TotalMVP;
            ++session.TotalMVP;
            ++stats[current.playlist].TotalMVP;
            ++always_gm[current.playlist].TotalMVP;

            ++(iam_receiver ? always.MVP : always.TeamMVP);
            ++(iam_receiver ? current.stats.MVP : current.stats.TeamMVP);
            ++(iam_receiver ? session.MVP : session.TeamMVP);
            ++(iam_receiver ? stats[current.playlist].MVP : stats[current.playlist].TeamMVP);
            ++(iam_receiver ? always_gm[current.playlist].MVP : always_gm[current.playlist].TeamMVP);

            ++always.TotalMVPCumul;
            ++current.stats.TotalMVPCumul;
            ++session.TotalMVPCumul;

            for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
            {
                ++stats[it->first].TotalMVPCumul;
                ++always_gm[it->first].TotalMVPCumul;

                ++(iam_receiver ? stats[it->first].MVPCumul : stats[it->first].TeamMVPCumul);
                ++(iam_receiver ? always_gm[it->first].MVPCumul : always_gm[it->first].TeamMVPCumul);
            }

            AllAccoladesMVP(true);
        }
        else
        {
            if (name == "Win" || name == "Loss")
                return;

            refresh = false;
            cvarManager->log("onStatTickerMessage " + name + "[" + std::to_string(event.GetPoints()) + "] receiver:" + std::string(iam_receiver ? "me" : (team_receiver ? "team" : "no")) + " victim:" + std::string(iam_victim ? "me" : (team_victim ? "team" : "no")));
        }
    }

    if (refresh)
        SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::onGoalScore(std::string eventName)
{
    TeamWrapper player = GetTeam(false);
    TeamWrapper opposite = GetTeam(true);

    int score_player = current.score_player;
    if (!player.IsNull())
        current.score_player = player.GetScore();

    int score_opposite = current.score_opposite;
    if (!opposite.IsNull())
        current.score_opposite = opposite.GetScore();

    if (current.score_player != score_player || current.score_opposite != score_opposite)
    {
        SendGameState("GoalScore");
        VarScorePlayer(true);
        VarScoreOpposite(true);
    }
}

void RocketStats::InitRank()
{
    int tier = current.tier;
    bool ranked = current.ranked;
    int playlist = current.playlist;

    last_rank = "";
    last_division = "";
    current = t_current();

    current.tier = tier;
    current.ranked = ranked;
    current.playlist = playlist;
}

void RocketStats::MajRank(bool isRanked, float _currentMMR, SkillRank playerRank)
{
    current.tier = playerRank.Tier;
    current.ranked = isRanked;

    if (isRanked)
    {
        current.preview_rank = GetRankName(playerRank.Tier, current.preview_rank_number);
        if (current.preview_rank_number)
            current.preview_rank += " {{Number}}";

        current.preview_division = "Div. {{Number}}";
        current.preview_division_number = (playerRank.Division + 1);

        if (current.playlist != 34 && playerRank.MatchesPlayed < 10)
        {
            current.rank = "Placement: " + std::to_string(playerRank.MatchesPlayed) + "/10";
            current.rank_number = 0;
            current.division = "";
            current.division_number = 0;
        }
        else
        {
            current.rank = current.preview_rank;
            current.rank_number = current.preview_rank_number;
            current.division = current.preview_division;
            current.division_number = current.preview_division_number;
        }
    }
    else
    {
        current.rank = GetPlaylistName(current.playlist);
        current.rank_number = 0;
        current.division = "";
        current.division_number = 0;

        current.preview_rank = current.rank;
        current.preview_rank_number = current.rank_number;
        current.preview_division = current.division;
        current.preview_division_number = current.division_number;
    }

    VarRank(true);
    VarDiv(true);

    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::UpdateMMR(UniqueIDWrapper id)
{
    cvarManager->log("===== UpdateMMR =====");
    /*
    if (id.GetIdString() != gameWrapper->GetUniqueID().GetIdString()) {
        cvarManager->log("Not the user");
        return;
    }
    cvarManager->log("User match");
    */

    if (current.playlist == 0)
    {
        cvarManager->log("Invalid playlist id. Have you just opened the game ?");
        return;
    }

    MMRWrapper mmrw = gameWrapper->GetMMRWrapper();
    float mmr = mmrw.GetPlayerMMR(id, current.playlist);
    SkillRank playerRank = mmrw.GetPlayerRank(id, current.playlist);

    if (stats[current.playlist].isInit)
    {
        float MMRChange = (mmr - stats[current.playlist].myMMR);

        always.MMRChange = MMRChange;
        session.MMRChange = MMRChange;
        stats[current.playlist].MMRChange = MMRChange;
        always_gm[current.playlist].MMRChange = MMRChange;

        always.MMRCumulChange += MMRChange;
        session.MMRCumulChange += MMRChange;
        stats[current.playlist].MMRCumulChange += MMRChange;
        always_gm[current.playlist].MMRCumulChange += MMRChange;
    }
    else
        stats[current.playlist].isInit = true;

    always.myMMR = mmr;
    session.myMMR = mmr;
    stats[current.playlist].myMMR = mmr;
    always_gm[current.playlist].myMMR = mmr;

    MajRank(mmrw.IsRanked(current.playlist), stats[current.playlist].myMMR, playerRank);
    SessionStats();
    VarMMR(true);
    VarMMRChange(true);

    SetRefresh(RefreshFlags_Refresh);
    cvarManager->log("===== !UpdateMMR =====");
}

void RocketStats::InitStats()
{
    session = Stats();
    for (auto& kv : stats)
        kv.second = Stats();

    always = Stats();
    always.isInit = true;
    for (auto& kv : always_gm)
    {
        kv.second = Stats();
        kv.second.isInit = true;
    }
}

void RocketStats::SessionStats()
{
    Stats tmp;

    for (auto it = playlist_name.begin(); it != playlist_name.end(); ++it)
        VarsSession(tmp, it->first, true);

    VarsSession(tmp);
    session.isInit = true;

    always.myMMR = session.myMMR;
    always.MMRChange = session.MMRChange;
    always.isInit = true;

    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::ResetStats()
{
    InitStats();

    WriteConfig();
    ResetFiles();

    InitRank();
    SetRefresh(RefreshFlags_Refresh);
}

void RocketStats::ResetBasicStats()
{
    current.stats = Stats();
    current.score_player = 0;
    current.score_opposite = 0;
}
```

## File: Managements/VarsManagement.cpp
```cpp
#include "../RocketStats.h"

void RocketStats::VarsReplace(std::map<std::string, std::string>& vars)
{
    ReplaceOther(vars);
    ReplaceShots(vars);
    ReplaceSaves(vars);
    ReplaceGoals(vars);
    ReplaceDropshot(vars);
    ReplaceKnockout(vars);
    ReplaceMiscs(vars);
    ReplaceAccolades(vars);
}

void RocketStats::VarsSession(Stats& stat, int index, bool playlists)
{
    SessionOther(stat, index, playlists);
    SessionShots(stat, index, playlists);
    SessionSaves(stat, index, playlists);
    SessionGoals(stat, index, playlists);
    SessionDropshot(stat, index, playlists);
    SessionKnockout(stat, index, playlists);
    SessionMiscs(stat, index, playlists);
    SessionAccolades(stat, index, playlists);
}

void RocketStats::VarsRead(Stats& stat, json& config)
{
    ReadOther(stat, config);
    ReadShots(stat, config);
    ReadSaves(stat, config);
    ReadGoals(stat, config);
    ReadDropshot(stat, config);
    ReadKnockout(stat, config);
    ReadMiscs(stat, config);
    ReadAccolades(stat, config);
}

void RocketStats::VarsWrite(Stats& stat, json& config, bool more)
{
    WriteOther(stat, config, more);
    WriteShots(stat, config, more);
    WriteSaves(stat, config, more);
    WriteGoals(stat, config, more);
    WriteDropshot(stat, config, more);
    WriteKnockout(stat, config, more);
    WriteMiscs(stat, config, more);
    WriteAccolades(stat, config, more);
}

#pragma region Other
void RocketStats::AllOther(bool force, bool default_value)
{
    VarGames(true, force, default_value);
    VarGameMode(true, force, default_value);
    VarRank(true, force, default_value);
    VarDiv(true, force, default_value);
    VarMMR(true, force, default_value);
    VarMMRChange(true, force, default_value);
    VarMMRCumulChange(true, force, default_value);
    VarWin(true, force, default_value);
    VarLoss(true, force, default_value);
    VarStreak(true, force, default_value);
    VarWinRatio(true, force, default_value);
    VarWinPercentage(true, force, default_value);
    VarScorePlayer(true, force, default_value);
    VarScoreOpposite(true, force, default_value);
    VarBoost(true, force, (!is_game_started || is_game_ended), false);
}
#pragma endregion

#pragma region Shots
void RocketStats::AllShots(bool force, bool default_value)
{
    AllShotsClear(force, default_value);
    AllShotsAssist(force, default_value);
    AllShotsCenter(force, default_value);
    AllShotsAerialHit(force, default_value);
    AllShotsBicycleHit(force, default_value);
    AllShotsShotOnGoal(force, default_value);
}

void RocketStats::AllShotsClear(bool force, bool default_value)
{
    VarShotsClear(true, force, default_value);
    VarShotsClearMatch(true, force, default_value);
    VarShotsClearCumul(true, force, default_value);
}

void RocketStats::AllShotsAssist(bool force, bool default_value)
{
    VarShotsAssist(true, force, default_value);
    VarShotsTeamAssist(true, force, default_value);
    VarShotsTotalAssist(true, force, default_value);

    VarShotsAssistMatch(true, force, default_value);
    VarShotsTeamAssistMatch(true, force, default_value);
    VarShotsTotalAssistMatch(true, force, default_value);

    VarShotsAssistCumul(true, force, default_value);
    VarShotsTeamAssistCumul(true, force, default_value);
    VarShotsTotalAssistCumul(true, force, default_value);
}

void RocketStats::AllShotsCenter(bool force, bool default_value)
{
    VarShotsCenter(true, force, default_value);
    VarShotsCenterMatch(true, force, default_value);
    VarShotsCenterCumul(true, force, default_value);
}

void RocketStats::AllShotsAerialHit(bool force, bool default_value)
{
    VarShotsAerialHit(true, force, default_value);
    VarShotsAerialHitMatch(true, force, default_value);
    VarShotsAerialHitCumul(true, force, default_value);
}

void RocketStats::AllShotsBicycleHit(bool force, bool default_value)
{
    VarShotsBicycleHit(true, force, default_value);
    VarShotsTeamBicycleHit(true, force, default_value);
    VarShotsTotalBicycleHit(true, force, default_value);

    VarShotsBicycleHitMatch(true, force, default_value);
    VarShotsTeamBicycleHitMatch(true, force, default_value);
    VarShotsTotalBicycleHitMatch(true, force, default_value);

    VarShotsBicycleHitCumul(true, force, default_value);
    VarShotsTeamBicycleHitCumul(true, force, default_value);
    VarShotsTotalBicycleHitCumul(true, force, default_value);
}

void RocketStats::AllShotsShotOnGoal(bool force, bool default_value)
{
    VarShotsShotOnGoal(true, force, default_value);
    VarShotsTeamShotOnGoal(true, force, default_value);
    VarShotsTotalShotOnGoal(true, force, default_value);

    VarShotsShotOnGoalMatch(true, force, default_value);
    VarShotsTeamShotOnGoalMatch(true, force, default_value);
    VarShotsTotalShotOnGoalMatch(true, force, default_value);

    VarShotsShotOnGoalCumul(true, force, default_value);
    VarShotsTeamShotOnGoalCumul(true, force, default_value);
    VarShotsTotalShotOnGoalCumul(true, force, default_value);

    VarShotsShootingPercentage(true, force, default_value);
    VarShotsTeamShootingPercentage(true, force, default_value);
    VarShotsTotalShootingPercentage(true, force, default_value);

    VarShotsShootingPercentageMatch(true, force, default_value);
    VarShotsTeamShootingPercentageMatch(true, force, default_value);
    VarShotsTotalShootingPercentageMatch(true, force, default_value);

    VarShotsShootingPercentageCumul(true, force, default_value);
    VarShotsTeamShootingPercentageCumul(true, force, default_value);
    VarShotsTotalShootingPercentageCumul(true, force, default_value);
}
#pragma endregion

#pragma region Saves
void RocketStats::AllSaves(bool force, bool default_value)
{
    AllSavesSave(force, default_value);
    AllSavesEpicSave(force, default_value);
}

void RocketStats::AllSavesSave(bool force, bool default_value)
{
    VarSavesSave(true, force, default_value);
    VarSavesTeamSave(true, force, default_value);
    VarSavesTotalSave(true, force, default_value);

    VarSavesSaveMatch(true, force, default_value);
    VarSavesTeamSaveMatch(true, force, default_value);
    VarSavesTotalSaveMatch(true, force, default_value);

    VarSavesSaveCumul(true, force, default_value);
    VarSavesTeamSaveCumul(true, force, default_value);
    VarSavesTotalSaveCumul(true, force, default_value);
}

void RocketStats::AllSavesEpicSave(bool force, bool default_value)
{
    VarSavesEpicSave(true, force, default_value);
    VarSavesTeamEpicSave(true, force, default_value);
    VarSavesTotalEpicSave(true, force, default_value);

    VarSavesEpicSaveMatch(true, force, default_value);
    VarSavesTeamEpicSaveMatch(true, force, default_value);
    VarSavesTotalEpicSaveMatch(true, force, default_value);

    VarSavesEpicSaveCumul(true, force, default_value);
    VarSavesTeamEpicSaveCumul(true, force, default_value);
    VarSavesTotalEpicSaveCumul(true, force, default_value);
}
#pragma endregion

#pragma region Goals
void RocketStats::AllGoals(bool force, bool default_value)
{
    AllGoalsGoal(force, default_value);
    AllGoalsOwnGoal(force, default_value);
    AllGoalsLongGoal(force, default_value);
    AllGoalsPoolShot(force, default_value);
    AllGoalsAerialGoal(force, default_value);
    AllGoalsTurtleGoal(force, default_value);
    AllGoalsBicycleGoal(force, default_value);
    AllGoalsOvertimeGoal(force, default_value);
    AllGoalsBackwardsGoal(force, default_value);
    AllGoalsHoopsSwishGoal(force, default_value);
}

void RocketStats::AllGoalsGoal(bool force, bool default_value)
{
    VarGoalsGoal(true, force, default_value);
    VarGoalsTeamGoal(true, force, default_value);
    VarGoalsTotalGoal(true, force, default_value);

    VarGoalsGoalMatch(true, force, default_value);
    VarGoalsTeamGoalMatch(true, force, default_value);
    VarGoalsTotalGoalMatch(true, force, default_value);

    VarGoalsGoalCumul(true, force, default_value);
    VarGoalsTeamGoalCumul(true, force, default_value);
    VarGoalsTotalGoalCumul(true, force, default_value);

    VarShotsShootingPercentage(true, force, default_value);
    VarShotsTeamShootingPercentage(true, force, default_value);
    VarShotsTotalShootingPercentage(true, force, default_value);

    VarShotsShootingPercentageMatch(true, force, default_value);
    VarShotsTeamShootingPercentageMatch(true, force, default_value);
    VarShotsTotalShootingPercentageMatch(true, force, default_value);

    VarShotsShootingPercentageCumul(true, force, default_value);
    VarShotsTeamShootingPercentageCumul(true, force, default_value);
    VarShotsTotalShootingPercentageCumul(true, force, default_value);
}

void RocketStats::AllGoalsOwnGoal(bool force, bool default_value)
{
    VarGoalsOwnGoal(true, force, default_value);
    VarGoalsOwnGoalMatch(true, force, default_value);
    VarGoalsOwnGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsLongGoal(bool force, bool default_value)
{
    VarGoalsLongGoal(true, force, default_value);
    VarGoalsTeamLongGoal(true, force, default_value);
    VarGoalsTotalLongGoal(true, force, default_value);

    VarGoalsLongGoalMatch(true, force, default_value);
    VarGoalsTeamLongGoalMatch(true, force, default_value);
    VarGoalsTotalLongGoalMatch(true, force, default_value);

    VarGoalsLongGoalCumul(true, force, default_value);
    VarGoalsTeamLongGoalCumul(true, force, default_value);
    VarGoalsTotalLongGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsPoolShot(bool force, bool default_value)
{
    VarGoalsPoolShot(true, force, default_value);
    VarGoalsTeamPoolShot(true, force, default_value);
    VarGoalsTotalPoolShot(true, force, default_value);

    VarGoalsPoolShotMatch(true, force, default_value);
    VarGoalsTeamPoolShotMatch(true, force, default_value);
    VarGoalsTotalPoolShotMatch(true, force, default_value);

    VarGoalsPoolShotCumul(true, force, default_value);
    VarGoalsTeamPoolShotCumul(true, force, default_value);
    VarGoalsTotalPoolShotCumul(true, force, default_value);
}

void RocketStats::AllGoalsAerialGoal(bool force, bool default_value)
{
    VarGoalsAerialGoal(true, force, default_value);
    VarGoalsTeamAerialGoal(true, force, default_value);
    VarGoalsTotalAerialGoal(true, force, default_value);

    VarGoalsAerialGoalMatch(true, force, default_value);
    VarGoalsTeamAerialGoalMatch(true, force, default_value);
    VarGoalsTotalAerialGoalMatch(true, force, default_value);

    VarGoalsAerialGoalCumul(true, force, default_value);
    VarGoalsTeamAerialGoalCumul(true, force, default_value);
    VarGoalsTotalAerialGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsTurtleGoal(bool force, bool default_value)
{
    VarGoalsTurtleGoal(true, force, default_value);
    VarGoalsTeamTurtleGoal(true, force, default_value);
    VarGoalsTotalTurtleGoal(true, force, default_value);

    VarGoalsTurtleGoalMatch(true, force, default_value);
    VarGoalsTeamTurtleGoalMatch(true, force, default_value);
    VarGoalsTotalTurtleGoalMatch(true, force, default_value);

    VarGoalsTurtleGoalCumul(true, force, default_value);
    VarGoalsTeamTurtleGoalCumul(true, force, default_value);
    VarGoalsTotalTurtleGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsBicycleGoal(bool force, bool default_value)
{
    VarGoalsBicycleGoal(true, force, default_value);
    VarGoalsTeamBicycleGoal(true, force, default_value);
    VarGoalsTotalBicycleGoal(true, force, default_value);

    VarGoalsBicycleGoalMatch(true, force, default_value);
    VarGoalsTeamBicycleGoalMatch(true, force, default_value);
    VarGoalsTotalBicycleGoalMatch(true, force, default_value);

    VarGoalsBicycleGoalCumul(true, force, default_value);
    VarGoalsTeamBicycleGoalCumul(true, force, default_value);
    VarGoalsTotalBicycleGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsOvertimeGoal(bool force, bool default_value)
{
    VarGoalsOvertimeGoal(true, force, default_value);
    VarGoalsTeamOvertimeGoal(true, force, default_value);
    VarGoalsTotalOvertimeGoal(true, force, default_value);

    VarGoalsOvertimeGoalMatch(true, force, default_value);
    VarGoalsTeamOvertimeGoalMatch(true, force, default_value);
    VarGoalsTotalOvertimeGoalMatch(true, force, default_value);

    VarGoalsOvertimeGoalCumul(true, force, default_value);
    VarGoalsTeamOvertimeGoalCumul(true, force, default_value);
    VarGoalsTotalOvertimeGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsBackwardsGoal(bool force, bool default_value)
{
    VarGoalsBackwardsGoal(true, force, default_value);
    VarGoalsTeamBackwardsGoal(true, force, default_value);
    VarGoalsTotalBackwardsGoal(true, force, default_value);

    VarGoalsBackwardsGoalMatch(true, force, default_value);
    VarGoalsTeamBackwardsGoalMatch(true, force, default_value);
    VarGoalsTotalBackwardsGoalMatch(true, force, default_value);

    VarGoalsBackwardsGoalCumul(true, force, default_value);
    VarGoalsTeamBackwardsGoalCumul(true, force, default_value);
    VarGoalsTotalBackwardsGoalCumul(true, force, default_value);
}

void RocketStats::AllGoalsHoopsSwishGoal(bool force, bool default_value)
{
    VarGoalsHoopsSwishGoal(true, force, default_value);
    VarGoalsTeamHoopsSwishGoal(true, force, default_value);
    VarGoalsTotalHoopsSwishGoal(true, force, default_value);

    VarGoalsHoopsSwishGoalMatch(true, force, default_value);
    VarGoalsTeamHoopsSwishGoalMatch(true, force, default_value);
    VarGoalsTotalHoopsSwishGoalMatch(true, force, default_value);

    VarGoalsHoopsSwishGoalCumul(true, force, default_value);
    VarGoalsTeamHoopsSwishGoalCumul(true, force, default_value);
    VarGoalsTotalHoopsSwishGoalCumul(true, force, default_value);
}
#pragma endregion

#pragma region Dropshot
void RocketStats::AllDropshot(bool force, bool default_value)
{
    AllDropshotBreakoutDamage(force, default_value);
    AllDropshotBreakoutDamageLarge(force, default_value);
}

void RocketStats::AllDropshotBreakoutDamage(bool force, bool default_value)
{
    VarDropshotBreakoutDamage(true, force, default_value);
    VarDropshotTeamBreakoutDamage(true, force, default_value);
    VarDropshotTotalBreakoutDamage(true, force, default_value);

    VarDropshotBreakoutDamageMatch(true, force, default_value);
    VarDropshotTeamBreakoutDamageMatch(true, force, default_value);
    VarDropshotTotalBreakoutDamageMatch(true, force, default_value);

    VarDropshotBreakoutDamageCumul(true, force, default_value);
    VarDropshotTeamBreakoutDamageCumul(true, force, default_value);
    VarDropshotTotalBreakoutDamageCumul(true, force, default_value);
}

void RocketStats::AllDropshotBreakoutDamageLarge(bool force, bool default_value)
{
    VarDropshotBreakoutDamageLarge(true, force, default_value);
    VarDropshotTeamBreakoutDamageLarge(true, force, default_value);
    VarDropshotTotalBreakoutDamageLarge(true, force, default_value);

    VarDropshotBreakoutDamageLargeMatch(true, force, default_value);
    VarDropshotTeamBreakoutDamageLargeMatch(true, force, default_value);
    VarDropshotTotalBreakoutDamageLargeMatch(true, force, default_value);

    VarDropshotBreakoutDamageLargeCumul(true, force, default_value);
    VarDropshotTeamBreakoutDamageLargeCumul(true, force, default_value);
    VarDropshotTotalBreakoutDamageLargeCumul(true, force, default_value);
}
#pragma endregion

#pragma region Knockout
void RocketStats::AllKnockout(bool force, bool default_value)
{
    AllKnockoutKO(force, default_value);
    AllKnockoutDeath(force, default_value);
    AllKnockoutAssist(force, default_value);
    AllKnockoutThrown(force, default_value);
    AllKnockoutWinner(force, default_value);
    AllKnockoutGrabbed(force, default_value);
    AllKnockoutDoubleKO(force, default_value);
    AllKnockoutHeavyHit(force, default_value);
    AllKnockoutHitTaken(force, default_value);
    AllKnockoutLightHit(force, default_value);
    AllKnockoutTripleKO(force, default_value);
    AllKnockoutBlockTaken(force, default_value);
    AllKnockoutHeavyBlock(force, default_value);
    AllKnockoutLightBlock(force, default_value);
    AllKnockoutPlayerThrown(force, default_value);
    AllKnockoutPlayerGrabbed(force, default_value);
    AllKnockoutAerialHeavyHit(force, default_value);
    AllKnockoutAerialLightHit(force, default_value);
}

void RocketStats::AllKnockoutKO(bool force, bool default_value)
{
    VarKnockoutKO(true, force, default_value);
    VarKnockoutKOMatch(true, force, default_value);
    VarKnockoutKOCumul(true, force, default_value);
}

void RocketStats::AllKnockoutDeath(bool force, bool default_value)
{
    VarKnockoutDeath(true, force, default_value);
    VarKnockoutDeathMatch(true, force, default_value);
    VarKnockoutDeathCumul(true, force, default_value);
}

void RocketStats::AllKnockoutAssist(bool force, bool default_value)
{
    VarKnockoutAssist(true, force, default_value);
    VarKnockoutAssistMatch(true, force, default_value);
    VarKnockoutAssistCumul(true, force, default_value);
}

void RocketStats::AllKnockoutThrown(bool force, bool default_value)
{
    VarKnockoutThrown(true, force, default_value);
    VarKnockoutThrownMatch(true, force, default_value);
    VarKnockoutThrownCumul(true, force, default_value);
}

void RocketStats::AllKnockoutWinner(bool force, bool default_value)
{
    VarKnockoutWinner(true, force, default_value);
    VarKnockoutWinnerMatch(true, force, default_value);
    VarKnockoutWinnerCumul(true, force, default_value);
}

void RocketStats::AllKnockoutGrabbed(bool force, bool default_value)
{
    VarKnockoutGrabbed(true, force, default_value);
    VarKnockoutGrabbedMatch(true, force, default_value);
    VarKnockoutGrabbedCumul(true, force, default_value);
}

void RocketStats::AllKnockoutDoubleKO(bool force, bool default_value)
{
    VarKnockoutDoubleKO(true, force, default_value);
    VarKnockoutDoubleKOMatch(true, force, default_value);
    VarKnockoutDoubleKOCumul(true, force, default_value);
}

void RocketStats::AllKnockoutHeavyHit(bool force, bool default_value)
{
    VarKnockoutHeavyHit(true, force, default_value);
    VarKnockoutHeavyHitMatch(true, force, default_value);
    VarKnockoutHeavyHitCumul(true, force, default_value);
}

void RocketStats::AllKnockoutHitTaken(bool force, bool default_value)
{
    VarKnockoutHitTaken(true, force, default_value);
    VarKnockoutHitTakenMatch(true, force, default_value);
    VarKnockoutHitTakenCumul(true, force, default_value);
}

void RocketStats::AllKnockoutLightHit(bool force, bool default_value)
{
    VarKnockoutLightHit(true, force, default_value);
    VarKnockoutLightHitMatch(true, force, default_value);
    VarKnockoutLightHitCumul(true, force, default_value);
}

void RocketStats::AllKnockoutTripleKO(bool force, bool default_value)
{
    VarKnockoutTripleKO(true, force, default_value);
    VarKnockoutTripleKOMatch(true, force, default_value);
    VarKnockoutTripleKOCumul(true, force, default_value);
}

void RocketStats::AllKnockoutBlockTaken(bool force, bool default_value)
{
    VarKnockoutBlockTaken(true, force, default_value);
    VarKnockoutBlockTakenMatch(true, force, default_value);
    VarKnockoutBlockTakenCumul(true, force, default_value);
}

void RocketStats::AllKnockoutHeavyBlock(bool force, bool default_value)
{
    VarKnockoutHeavyBlock(true, force, default_value);
    VarKnockoutHeavyBlockMatch(true, force, default_value);
    VarKnockoutHeavyBlockCumul(true, force, default_value);
}

void RocketStats::AllKnockoutLightBlock(bool force, bool default_value)
{
    VarKnockoutLightBlock(true, force, default_value);
    VarKnockoutLightBlockMatch(true, force, default_value);
    VarKnockoutLightBlockCumul(true, force, default_value);
}

void RocketStats::AllKnockoutPlayerThrown(bool force, bool default_value)
{
    VarKnockoutPlayerThrown(true, force, default_value);
    VarKnockoutPlayerThrownMatch(true, force, default_value);
    VarKnockoutPlayerThrownCumul(true, force, default_value);
}

void RocketStats::AllKnockoutPlayerGrabbed(bool force, bool default_value)
{
    VarKnockoutPlayerGrabbed(true, force, default_value);
    VarKnockoutPlayerGrabbedMatch(true, force, default_value);
    VarKnockoutPlayerGrabbedCumul(true, force, default_value);
}

void RocketStats::AllKnockoutAerialHeavyHit(bool force, bool default_value)
{
    VarKnockoutAerialHeavyHit(true, force, default_value);
    VarKnockoutAerialHeavyHitMatch(true, force, default_value);
    VarKnockoutAerialHeavyHitCumul(true, force, default_value);
}

void RocketStats::AllKnockoutAerialLightHit(bool force, bool default_value)
{
    VarKnockoutAerialLightHit(true, force, default_value);
    VarKnockoutAerialLightHitMatch(true, force, default_value);
    VarKnockoutAerialLightHitCumul(true, force, default_value);
}
#pragma endregion

#pragma region Miscs
void RocketStats::AllMiscs(bool force, bool default_value)
{
    AllMiscsDeath(force, default_value);
    AllMiscsSavior(force, default_value);
    AllMiscsLowFive(force, default_value);
    AllMiscsHatTrick(force, default_value);
    AllMiscsHighFive(force, default_value);
    AllMiscsPlaymaker(force, default_value);
    AllMiscsFirstTouch(force, default_value);
    AllMiscsDemolitions(force, default_value);
}

void RocketStats::AllMiscsDeath(bool force, bool default_value)
{
    VarMiscsDeath(true, force, default_value);
    VarMiscsTeamDeath(true, force, default_value);
    VarMiscsTotalDeath(true, force, default_value);

    VarMiscsDeathMatch(true, force, default_value);
    VarMiscsTeamDeathMatch(true, force, default_value);
    VarMiscsTotalDeathMatch(true, force, default_value);

    VarMiscsDeathCumul(true, force, default_value);
    VarMiscsTeamDeathCumul(true, force, default_value);
    VarMiscsTotalDeathCumul(true, force, default_value);
}

void RocketStats::AllMiscsSavior(bool force, bool default_value)
{
    VarMiscsSavior(true, force, default_value);
    VarMiscsTeamSavior(true, force, default_value);
    VarMiscsTotalSavior(true, force, default_value);

    VarMiscsSaviorMatch(true, force, default_value);
    VarMiscsTeamSaviorMatch(true, force, default_value);
    VarMiscsTotalSaviorMatch(true, force, default_value);

    VarMiscsSaviorCumul(true, force, default_value);
    VarMiscsTeamSaviorCumul(true, force, default_value);
    VarMiscsTotalSaviorCumul(true, force, default_value);
}

void RocketStats::AllMiscsLowFive(bool force, bool default_value)
{
    VarMiscsLowFive(true, force, default_value);
    VarMiscsTeamLowFive(true, force, default_value);
    VarMiscsTotalLowFive(true, force, default_value);

    VarMiscsLowFiveMatch(true, force, default_value);
    VarMiscsTeamLowFiveMatch(true, force, default_value);
    VarMiscsTotalLowFiveMatch(true, force, default_value);

    VarMiscsLowFiveCumul(true, force, default_value);
    VarMiscsTeamLowFiveCumul(true, force, default_value);
    VarMiscsTotalLowFiveCumul(true, force, default_value);
}

void RocketStats::AllMiscsHatTrick(bool force, bool default_value)
{
    VarMiscsHatTrick(true, force, default_value);
    VarMiscsTeamHatTrick(true, force, default_value);
    VarMiscsTotalHatTrick(true, force, default_value);

    VarMiscsHatTrickMatch(true, force, default_value);
    VarMiscsTeamHatTrickMatch(true, force, default_value);
    VarMiscsTotalHatTrickMatch(true, force, default_value);

    VarMiscsHatTrickCumul(true, force, default_value);
    VarMiscsTeamHatTrickCumul(true, force, default_value);
    VarMiscsTotalHatTrickCumul(true, force, default_value);
}

void RocketStats::AllMiscsHighFive(bool force, bool default_value)
{
    VarMiscsHighFive(true, force, default_value);
    VarMiscsTeamHighFive(true, force, default_value);
    VarMiscsTotalHighFive(true, force, default_value);

    VarMiscsHighFiveMatch(true, force, default_value);
    VarMiscsTeamHighFiveMatch(true, force, default_value);
    VarMiscsTotalHighFiveMatch(true, force, default_value);

    VarMiscsHighFiveCumul(true, force, default_value);
    VarMiscsTeamHighFiveCumul(true, force, default_value);
    VarMiscsTotalHighFiveCumul(true, force, default_value);
}

void RocketStats::AllMiscsPlaymaker(bool force, bool default_value)
{
    VarMiscsPlaymaker(true, force, default_value);
    VarMiscsTeamPlaymaker(true, force, default_value);
    VarMiscsTotalPlaymaker(true, force, default_value);

    VarMiscsPlaymakerMatch(true, force, default_value);
    VarMiscsTeamPlaymakerMatch(true, force, default_value);
    VarMiscsTotalPlaymakerMatch(true, force, default_value);

    VarMiscsPlaymakerCumul(true, force, default_value);
    VarMiscsTeamPlaymakerCumul(true, force, default_value);
    VarMiscsTotalPlaymakerCumul(true, force, default_value);
}

void RocketStats::AllMiscsFirstTouch(bool force, bool default_value)
{
    VarMiscsFirstTouch(true, force, default_value);
    VarMiscsFirstTouchMatch(true, force, default_value);
    VarMiscsFirstTouchCumul(true, force, default_value);
}

void RocketStats::AllMiscsDemolitions(bool force, bool default_value)
{
    VarMiscsDemolitions(true, force, default_value);
    VarMiscsTeamDemolitions(true, force, default_value);
    VarMiscsTotalDemolitions(true, force, default_value);

    VarMiscsDemolitionsMatch(true, force, default_value);
    VarMiscsTeamDemolitionsMatch(true, force, default_value);
    VarMiscsTotalDemolitionsMatch(true, force, default_value);

    VarMiscsDemolitionsCumul(true, force, default_value);
    VarMiscsTeamDemolitionsCumul(true, force, default_value);
    VarMiscsTotalDemolitionsCumul(true, force, default_value);
}
#pragma endregion

#pragma region Accolades
void RocketStats::AllAccolades(bool force, bool default_value)
{
    AllAccoladesMVP(force, default_value);
    AllAccoladesCarTouches(force, default_value);
    AllAccoladesFastestGoal(force, default_value);
    AllAccoladesSlowestGoal(force, default_value);
    AllAccoladesBoostPickups(force, default_value);
    AllAccoladesFurthestGoal(force, default_value);
    AllAccoladesMostBallTouches(force, default_value);
    AllAccoladesMostBoostPickups(force, default_value);
    AllAccoladesFewestBallTouches(force, default_value);
}

void RocketStats::AllAccoladesMVP(bool force, bool default_value)
{
    VarAccoladesMVP(true, force, default_value);
    VarAccoladesTeamMVP(true, force, default_value);
    VarAccoladesTotalMVP(true, force, default_value);

    VarAccoladesMVPMatch(true, force, default_value);
    VarAccoladesTeamMVPMatch(true, force, default_value);
    VarAccoladesTotalMVPMatch(true, force, default_value);

    VarAccoladesMVPCumul(true, force, default_value);
    VarAccoladesTeamMVPCumul(true, force, default_value);
    VarAccoladesTotalMVPCumul(true, force, default_value);
}

void RocketStats::AllAccoladesCarTouches(bool force, bool default_value)
{
    VarAccoladesCarTouches(true, force, default_value);
    VarAccoladesCarTouchesMatch(true, force, default_value);
    VarAccoladesCarTouchesCumul(true, force, default_value);
}

void RocketStats::AllAccoladesFastestGoal(bool force, bool default_value)
{
    VarAccoladesFastestGoal(true, force, default_value);
    VarAccoladesFastestGoalMatch(true, force, default_value);
    VarAccoladesFastestGoalCumul(true, force, default_value);
}

void RocketStats::AllAccoladesSlowestGoal(bool force, bool default_value)
{
    VarAccoladesSlowestGoal(true, force, default_value);
    VarAccoladesSlowestGoalMatch(true, force, default_value);
    VarAccoladesSlowestGoalCumul(true, force, default_value);
}

void RocketStats::AllAccoladesBoostPickups(bool force, bool default_value)
{
    VarAccoladesBoostPickups(true, force, default_value);
    VarAccoladesBoostPickupsMatch(true, force, default_value);
    VarAccoladesBoostPickupsCumul(true, force, default_value);
}

void RocketStats::AllAccoladesFurthestGoal(bool force, bool default_value)
{
    VarAccoladesFurthestGoal(true, force, default_value);
    VarAccoladesFurthestGoalMatch(true, force, default_value);
    VarAccoladesFurthestGoalCumul(true, force, default_value);
}

void RocketStats::AllAccoladesMostBallTouches(bool force, bool default_value)
{
    VarAccoladesMostBallTouches(true, force, default_value);
    VarAccoladesMostBallTouchesMatch(true, force, default_value);
    VarAccoladesMostBallTouchesCumul(true, force, default_value);
}

void RocketStats::AllAccoladesMostBoostPickups(bool force, bool default_value)
{
    VarAccoladesMostBoostPickups(true, force, default_value);
    VarAccoladesMostBoostPickupsMatch(true, force, default_value);
    VarAccoladesMostBoostPickupsCumul(true, force, default_value);
}

void RocketStats::AllAccoladesFewestBallTouches(bool force, bool default_value)
{
    VarAccoladesFewestBallTouches(true, force, default_value);
    VarAccoladesFewestBallTouchesMatch(true, force, default_value);
    VarAccoladesFewestBallTouchesCumul(true, force, default_value);
}
#pragma endregion
```

## File: Managements/WindowManagement.cpp
```cpp
#include "../RocketStats.h"

void RocketStats::Render()
{
    timer_30fps.tick();
    display_size = ImGui::GetIO().DisplaySize;

    is_online_game = gameWrapper->IsInOnlineGame();
    is_offline_game = gameWrapper->IsInGame();
    is_in_freeplay = gameWrapper->IsInFreeplay();
    is_in_game = (is_online_game || is_offline_game);

    // Capture of the escape key, to prevent the plugin from disappearing
    int idx = ImGui::GetKeyIndex(ImGuiKey_Escape);
    if (ImGui::IsKeyDown(idx))
        escape_state = true;
    else if (ImGui::IsKeyReleased(idx))
        escape_state = false;

    if (rs_recovery == RecoveryFlags_Files)
    {
        ImGui::SetNextWindowPos({ 10.f, (display_size.y - (95.f + 10.f)) }, ImGuiCond_Appearing);
        ImGui::SetNextWindowSize({ 0.f, 0.f });

        bool opened = true;
        ImGui::Begin((menu_title + "##Recovery").c_str(), &opened, (ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse));

        ImGui::Text(GetLang(LANG_MIGRATE_MESSAGE).c_str());

        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10.f);
        if (rs_buttons_x)
            ImGui::SetCursorPosX(rs_buttons_x);

        float x = ImGui::GetCursorPosX();
        if (ImGui::Button(GetLang(LANG_MIGRATE_BUTTON_MIGRATE).c_str()))
        {
            opened = false;
            MigrateFolder();
        }
        ImGui::SameLine();
        if (ImGui::Button(GetLang(LANG_MIGRATE_BUTTON_REMOVE).c_str()))
        {
            opened = false;
            MigrateRemove();
        }
        ImGui::SameLine();
        if (ImGui::Button(GetLang(LANG_MIGRATE_BUTTON_NOTHING).c_str()))
            opened = false;
        ImGui::SameLine();
        rs_buttons_x = ((ImGui::GetWindowWidth() - (ImGui::GetCursorPosX() - x)) / 2);

        ImGui::End();

        if (!opened)
            onInit();

        return;
    }

    RenderOverlay();

    // Displays the button allowing the display and the hiding of the menu
    CVarWrapper rs_toggle_logo = cvarManager->getCvar("rs_toggle_logo");
    if (rs_toggle_logo && rs_toggle_logo.getBoolValue())
        RenderIcon();

    if (!overlay_move && settings_open)
    {
        CloseWelcome();
        RenderSettings();
    }

    // Displays the message to introduce the new version
    if (rs_recovery == RecoveryFlags_Welcome && rs_welcome != nullptr && rs_welcome->IsLoadedForImGui())
    {
        ImVec2 mouse_pos = ImGui::GetIO().MousePos;
        Vector2F image_size = rs_welcome->GetSizeF();
        bool mouse_click = GetAsyncKeyState(VK_LBUTTON);

        float max_width = (display_size.x / 2);
        if (max_width < image_size.X)
            image_size = { max_width, ((image_size.Y / image_size.X) * max_width) };
        ImVec2 image_min = { ((display_size.x - image_size.X) / 2), ((display_size.y - image_size.Y) / 2) };
        ImVec2 image_max = { (image_min.x + image_size.X), (image_min.y + image_size.Y) };

        bool hover = (mouse_pos.x > image_min.x && mouse_pos.x < image_max.x);
        hover = (hover && (mouse_pos.y > image_min.y && mouse_pos.y < image_max.y));

        // Close the new version message when clicking on the image
        if (hover && mouse_click)
            CloseWelcome();
        else
            ImGui::GetBackgroundDrawList()->AddImage(rs_welcome->GetImGuiTex(), image_min, image_max);
    }
    else if (rs_recovery == RecoveryFlags_Finish)
        rs_recovery = RecoveryFlags_Off;
}

void RocketStats::RenderIcon()
{
    bool hide = (rs_recovery == RecoveryFlags_Off && !settings_open && (overlay_move || (is_in_game && !is_in_menu)));
    if (hide && rs_logo_flash < 0.f)
        return;

    float margin = 0.f;
    float icon_size = (42.f * rs_screen_scale[0]);
    float icon_scale = (1.f - rs_screen_scale[0]);
    ImVec2 icon_pos = { 0.f, (display_size.y * 0.459f * (icon_scale + (icon_scale * (0.18f - (1.f - rs_screen_scale[1]))) + 1.f)) };
    ImDrawList* drawlist = ImGui::GetBackgroundDrawList();

    // Flash on GameEnd
    if (rs_logo_flash >= 0.f)
    {
        rs_logo_flash += (0.1f * float(timer_30fps.frames()));
        if (rs_logo_flash > 2.f)
            rs_logo_flash = -1.f;
        else
            drawlist->AddCircleFilled({ icon_pos.x, icon_pos.y }, icon_size, ImColor{ 1.f, 1.f, 1.f, ((rs_logo_flash > 1.f) ? (2.f - rs_logo_flash) : rs_logo_flash) }, 25);
    }

    if (hide)
        return;

    ImVec2 mouse_pos = ImGui::GetIO().MousePos;
    bool mouse_click = GetAsyncKeyState(VK_LBUTTON);
    bool hover = (mouse_pos.x > (icon_pos.x - icon_size - margin) && mouse_pos.x < (icon_pos.x + icon_size + margin));
    hover = (hover && (mouse_pos.y > (icon_pos.y - icon_size - margin) && mouse_pos.y < (icon_pos.y + icon_size + margin)));

    // Handles logo movement
    rs_logo_rotate += ((rs_logo_mouv ? 0.3f : -0.3f) * float(timer_30fps.frames()));
    if (rs_logo_rotate < 0 || rs_logo_rotate >= 30.f)
    {
        rs_logo_mouv = !rs_logo_mouv;
        rs_logo_rotate = max(0.f, min(30.f, rs_logo_rotate));
    }

    // Displays the logo otherwise displays a circle instead
    if (rs_logo != nullptr && rs_logo->IsLoadedForImGui())
    {
        Vector2F image_size = rs_logo->GetSizeF();
        float rotate = ((90.f - rs_logo_rotate) * (float(M_PI) / 180.f));

        if (rs_llaunch < 1.f)
        {
            rs_llaunch += 0.05f;
            SetRefresh(RefreshFlags_Refresh);
        }

        ImRotateStart(drawlist);
        drawlist->AddImage(rs_logo->GetImGuiTex(), { icon_pos.x - icon_size, icon_pos.y - icon_size }, { icon_pos.x + icon_size, icon_pos.y + icon_size }, { 0, 0 }, { 1, 1 }, ImGui::ColorConvertFloat4ToU32({ 1.f, 1.f, 1.f, rs_llaunch }));
        ImRotateEnd(rotate);
    }
    else
    {
        drawlist->AddCircle({ icon_pos.x, icon_pos.y }, icon_size, ImColor{ 0.45f, 0.72f, 1.f, (hover ? 0.8f : 0.4f) }, 25, 4.f);
        drawlist->AddCircleFilled({ icon_pos.x, icon_pos.y }, icon_size, ImColor{ 0.04f, 0.52f, 0.89f, (hover ? 0.6f : 0.3f) }, 25);
    }

    // When hovering over the button area
    if (hover)
    {
        ImGui::SetTooltip(GetLang(LANG_TOGGLE_MENU_TOOLTIP).c_str());

        // When clicking in the button area
        if (mouse_click)
        {
            // Send the event only once to the click (not to each image)
            if (!mouse_state)
            {
                mouse_state = true;
                ToggleSettings("MouseEvent");
            }
        }
        else
            mouse_state = false;
    }
}

void RocketStats::RenderOverlay()
{
    bool show_overlay = ((rs_enable_inmenu && is_in_menu) || (rs_enable_ingame && is_in_game && (!is_in_scoreboard || is_in_freeplay)) || (rs_enable_inscoreboard && is_in_scoreboard && !is_in_freeplay));
    if (!rs_disp_overlay || !show_overlay || (rs_recovery != RecoveryFlags_Off && rs_recovery != RecoveryFlags_Finish))
        return;

    ImGui::SetNextWindowPos({ 0.f, 0.f }, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize({ 0.f, 0.f });

    ImGui::Begin(menu_title.c_str(), (bool*)1, (ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoFocusOnAppearing));

    int currentTheme = is_in_MainMenu ? rs_theme : rs_gameTheme;

    try
    {
        // Calculation each element of the theme (only during a modification)
        if (overlay_move || theme_refresh || theme_render.name == "" || (themes.size() > currentTheme && theme_render.name != themes.at(currentTheme).name))
        {
            Stats tstats = GetStats();

            theme_size = { 0, 0 };
            if (theme_config["width"].is_string())
                theme_size.x = float(Utils::EvaluateExpression(theme_config["width"], int(display_size.x), display_size));
            else if (theme_config["width"].is_number())
                theme_size.x = float(theme_config["width"]);
            if (theme_config["height"].is_string())
                theme_size.y = float(Utils::EvaluateExpression(theme_config["height"], int(display_size.y), display_size));
            else if (theme_config["height"].is_number())
                theme_size.y = float(theme_config["height"]);

            // Refresh all images
            if (theme_refresh == 2)
            {
                theme_images.clear();
                cvarManager->log("Refresh all images");
            }

            // Reset the menu variables if you change the theme
            if (theme_prev != theme_render.name)
            {
                if (rs_recovery != RecoveryFlags_Finish && !GetCVar("rs_scale", rs_scale))
                {
                    rs_scale = 1.f;
                    if (theme_config["scale"].is_number())
                        rs_scale = float(theme_config["scale"]);
                }

                if (!GetCVar("rs_rotate", rs_rotate))
                {
                    rs_rotate = 0.f;
                    if (theme_config["rotate"].is_number())
                        rs_rotate = float(theme_config["rotate"]);
                }

                if (!GetCVar("rs_opacity", rs_opacity))
                {
                    rs_opacity = 1.f;
                    if (theme_config["opacity"].is_number())
                        rs_opacity = float(theme_config["opacity"]);
                }

                if (rs_recovery != RecoveryFlags_Finish && !GetCVar("rs_x", rs_x))
                {
                    rs_x = 0.f;
                    if (theme_config["x"].is_string())
                        rs_x = (float(Utils::EvaluateExpression(theme_config["x"], int(theme_size.x * rs_scale), display_size)) / display_size.x);
                    else if (theme_config["x"].is_number())
                        rs_x = float(theme_config["x"]);
                }

                if (rs_recovery != RecoveryFlags_Finish && !GetCVar("rs_y", rs_y))
                {
                    rs_y = 0.f;
                    if (theme_config["y"].is_string())
                        rs_y = (float(Utils::EvaluateExpression(theme_config["y"], int(theme_size.y * rs_scale), display_size)) / display_size.y);
                    else if (theme_config["y"].is_number())
                        rs_y = float(theme_config["y"]);
                }
            }
            theme_prev = theme_render.name;

            // Checks if there is a rotation to apply and converts degrees to radians
            rs_rotate_enabled = (theme_config["rotate"].is_number() && (rs_rotate + float(theme_config["rotate"])));
            if (rs_rotate)
            {
                rs_rotate_enabled = true;
                rs_crotate = ((90.f - rs_rotate) * (float(M_PI) / 180.f));
            }
            else if (rs_rotate_enabled)
                rs_crotate = ((90.f - rs_rotate + float(theme_config["rotate"])) * (float(M_PI) / 180.f));

            // Different global options used when calculating elements
            std::vector<Element> elements;
            Options options = {
                int(rs_x * display_size.x),
                int(rs_y * display_size.y),
                int(theme_size.x),
                int(theme_size.y),
                rs_scale,
                (rs_launch * rs_opacity)
            };

            // Change the position of the overlay when moving with the mouse
            if (overlay_move)
            {
                options.x = int(overlay_cursor.x);
                options.y = int(overlay_cursor.y);
            }

            VarsReplace(theme_vars);

            // Calculation of each element composing the theme
            rs_drawlist->Clear(); // Clear the array of vertices for the next step
            for (auto& element : theme_config["elements"])
            {
                bool check = false;
                Element calculated = CalculateElement(element, options, check);
                if (check)
                    elements.push_back(calculated);
            }

            theme_refresh = 0;
            theme_render.elements = elements;
        }

        if (theme_render.elements.size())
        {
            ImDrawList* drawlist = ImGui::GetBackgroundDrawList();

            if (!theme_refresh && rs_drawlist->VtxBuffer.Size && windows_count == ImGui::GetIO().MetricsRenderWindows)
            {
                // Fill the DrawList with previously generated vertices
                drawlist->CmdBuffer = rs_drawlist->CmdBuffer;
                drawlist->IdxBuffer = rs_drawlist->IdxBuffer;
                drawlist->VtxBuffer = rs_drawlist->VtxBuffer;

                drawlist->Flags = rs_drawlist->Flags;
                drawlist->_VtxCurrentIdx = (unsigned int)drawlist->VtxBuffer.Size;
                drawlist->_VtxWritePtr = drawlist->VtxBuffer.end();
                drawlist->_IdxWritePtr = drawlist->IdxBuffer.end();
            }
            else
            {
                // Generates the vertices of each element
                int start = drawlist->VtxBuffer.Size;
                if (rs_rotate_enabled)
                    start = ImRotateStart(drawlist);

                for (auto& element : theme_render.elements)
                    RenderElement(drawlist, element);

                if (rs_rotate_enabled)
                    ImRotateEnd(rs_crotate, start, drawlist, ImRotationCenter(start, ImGui::GetBackgroundDrawList()));

                // Stores generated vertices for future frames
                rs_drawlist->Clear();
                rs_drawlist = drawlist->CloneOutput();

                // Avoid conflicts between different plugins using ImGui
                windows_count = ImGui::GetIO().MetricsRenderWindows;
            }

            // Displays a square and allows the movement of the overlay with the mouse
            if (settings_open)
            {
                float margin = 10.f;
                float rect_size = 10.f;
                bool mouse_click = GetAsyncKeyState(VK_LBUTTON);
                ImVec2 mouse_pos = ImGui::GetIO().MousePos;
                ImVec2 overlay_pos = { (rs_x * display_size.x), (rs_y * display_size.y) };
                ImVec2 rect_pos = { overlay_pos.x, overlay_pos.y };

                bool hover = (mouse_pos.x > (overlay_pos.x - rect_size - (margin * 2)) && mouse_pos.x < (overlay_pos.x + rect_size + (margin * 2)));
                hover = (hover && (mouse_pos.y > (overlay_pos.y - rect_size - (margin * 2)) && mouse_pos.y < (overlay_pos.y + rect_size + (margin * 2))));

                // If we hover over the area of the square or if we are moving it
                if (hover || overlay_move)
                {
                    ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);

                    // Moves the overlay when you hold down the mouse click
                    if (mouse_click)
                    {
                        if (!overlay_move)
                        {
                            overlay_move = true;
                            overlay_origin = { float(mouse_pos.x), float(mouse_pos.y) };
                        }

                        overlay_cursor = { float(mouse_pos.x), float(mouse_pos.y) };
                        rect_pos = overlay_cursor;
                    }
                    else
                    {
                        // Change positions when mouse click is released
                        if (overlay_move)
                        {
                            rs_x = (overlay_cursor.x / display_size.x);
                            rs_y = (overlay_cursor.y / display_size.y);

                            overlay_move = false;
                            SetRefresh(RefreshFlags_Refresh);
                        }
                        else
                            ImGui::SetTooltip(GetLang(LANG_OVERLAY_MOVE).c_str());
                    }
                }

                drawlist->AddRectFilled({ (rect_pos.x - rect_size), (rect_pos.y - rect_size) }, { (rect_pos.x + rect_size), (rect_pos.y + rect_size) }, ImGui::ColorConvertFloat4ToU32({ 1.f, 1.f, 1.f, 0.5f }), 4.f, ImDrawCornerFlags_All);
                drawlist->AddRect({ (rect_pos.x - rect_size), (rect_pos.y - rect_size) }, { (rect_pos.x + rect_size), (rect_pos.y + rect_size) }, ImGui::ColorConvertFloat4ToU32({ 0.f, 0.f, 0.f, 0.5f }), 4.f, ImDrawCornerFlags_All, 2.f);
            }
            else
                overlay_move = false;
        }

        // Allows spawn transition
        if (rs_launch < 1.f)
        {
            rs_launch += 0.05f;
            SetRefresh(RefreshFlags_Refresh);
        }
    }
    catch (const std::exception& err)
    {
        theme_refresh = 0;
        rs_drawlist->Clear();
        cvarManager->log("Error: " + std::string(err.what()));
    }

    ImGui::End();
}

void RocketStats::RenderSettings()
{
    std::string tooltip;
    ImVec2 settings_size = { 750.f, 0.f };

    CVarWrapper cvar_scale = cvarManager->getCvar("rs_scale");
    CVarWrapper cvar_rotate = cvarManager->getCvar("rs_rotate");
    CVarWrapper cvar_opacity = cvarManager->getCvar("rs_opacity");

    GuiManagerWrapper gui = gameWrapper->GetGUIManager();
    ImFont* font = gui.GetFont("Ubuntu-Regular28");
    bool menu_font = font->IsLoaded();

    if (menu_font)
        ImGui::PushFont(font);

    ImGui::SetNextWindowPos({ 128.f, 256.f }, (rs_menu_pos ? ImGuiCond_Appearing : ImGuiCond_FirstUseEver));
    ImGui::SetNextWindowSize(settings_size);

    if (rs_menu_pos)
        rs_menu_pos = false;

    ImGui::Begin((menu_title + "##Settings").c_str(), nullptr, (ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse));

    ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));

    // Show menu only if menu image is loaded
    if (rs_logo != nullptr && rs_title != nullptr && rs_logo->IsLoadedForImGui() && rs_title->IsLoadedForImGui())
    {
        bool select_all;
        float column_nb = 3;
        float column_space = 10.f;
        float column_start = 25.f;
        float column_width = ((settings_size.x - (column_start * 2.f) - (column_space * (column_nb - 1.f))) / column_nb);

        ImVec2 tpos;
        ImVec2 text_size;
        ImVec2 image_pos;
        ImVec2 win_pos = ImGui::GetWindowPos();
        ImVec2 win_size = ImGui::GetWindowSize();
        Vector2F image_size = rs_title->GetSizeF();
        ImDrawList* drawlist = ImGui::GetWindowDrawList();

        ImVec2 p0 = win_pos;
        ImVec2 p1 = { (win_pos.x + win_size.x), (win_pos.y + win_size.y) };

        p0.x += 1;
        p1.x -= 1;
        drawlist->PushClipRect(p0, p1); // Allows you to delimit the area of the window (without internal borders)

        std::time(&current_time);
        const auto time_error = localtime_s(&local_time, &current_time);

        // Documentation
        float circle_size = 21.5f;
        const float radian_min = (((210.f - 90.f) / 360.f) * ARC_SPAN);
        const float radian_max = (((270.f - 90.f) / 360.f) * ARC_SPAN);
        ImU32 circle_color = ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Border));
        ImVec2 circle_end = { (win_pos.x + win_size.x - 6.f), (win_pos.y + 1.f) };
        ImVec2 circle_start = { (circle_end.x + ((circle_size * cos(radian_min)))), (circle_end.y + ((circle_size * sin(radian_min)))) };

        ImGui::SetWindowFontScale(1.3f / (font ? 2.f : 1.f));
        drawlist->PathLineTo(circle_start);
        drawlist->PathArcTo(circle_end, circle_size, radian_min, radian_max, 20);
        drawlist->PathStroke(circle_color, false, 1.f);
        drawlist->AddLine({ (circle_start.x - 1.f), (circle_start.y - 1.f) }, { (circle_start.x + 15.f), (circle_start.y - 1.f) }, circle_color, 1.f);
        drawlist->AddText({ (win_pos.x + win_size.x - 14.f), win_pos.y }, ImGui::ColorConvertFloat4ToU32({ 1.f, 1.f, 1.f, 1.f }), "?");

        if (ImGui::GetMousePos().x >= (circle_start.x - 6.f) && ImGui::GetMousePos().x <= (win_pos.x + win_size.x - 1.f) && ImGui::GetMousePos().y >= win_pos.y && ImGui::GetMousePos().y <= circle_start.y)
        {
            tooltip = GetLang(LANG_DOCUMENTATION);
            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
            if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
                system("powershell -WindowStyle Hidden \"start https://github.com/Lyliya/RocketStats/wiki\"");
        }

        // First Part
        ImGui::SetCursorPos({ 0.f, 27.f });
        image_pos = { p0.x + ImGui::GetCursorPosX(), p0.y + ImGui::GetCursorPosY() };
        drawlist->AddImage(rs_title->GetImGuiTex(), image_pos, { (image_size.X / 2.f) + image_pos.x, (image_size.Y / 2.f) + image_pos.y });

        ImGui::SetWindowFontScale(1.7f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 23.f, 52.f });
        ImGui::Checkbox("##overlay", &rs_disp_overlay);
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_OVERLAY_TOOLTIP);

        ImGui::SetCursorPos({ 63.f, 54.f });
        ImGui::TextColored(ImVec4{ 0.2f, 0.2f, 0.2f, 1.f }, Utils::toupper(GetLang(LANG_OVERLAY)).c_str());

        ImGui::SetWindowFontScale(1.3f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 355.f, 43.f });
        ImGui::TextColored(ImVec4{ 0.8f, 0.8f, 0.8f, 1.f }, GetLang(LANG_MODE).c_str());

        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 295.f, 68.f });
        ImGui::SetNextItemWidth(142.f);
        if (ImGui::BeginCombo("##modes_combo", modes.at(rs_mode).c_str(), ImGuiComboFlags_NoArrowButton))
        {
            int Trs_mode = rs_mode;
            for (int i = 0; i < modes.size(); ++i)
            {
                bool is_selected = (Trs_mode == i);
                if (ImGui::Selectable(modes.at(i).c_str(), is_selected))
                    rs_mode = i;

                if (is_selected)
                    ImGui::SetItemDefaultFocus();
            }

            ImGui::EndCombo();
        }
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_IN_FILE_TOOLTIP);
        ImGui::SameLine(0.f, 0.f);
        if (ImGui::ArrowButton("##modes_left", ImGuiDir_Left) && rs_mode > 0)
            --rs_mode;
        ImGui::SameLine(0.f, 0.f);
        if (ImGui::ArrowButton("##modes_right", ImGuiDir_Right) && rs_mode < (modes.size() - 1))
            ++rs_mode;

        ImGui::SetWindowFontScale(1.3f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 565.f, 23.f });
        ImGui::TextColored(ImVec4{ 0.8f, 0.8f, 0.8f, 1.f }, GetLang(LANG_MENU_THEME).c_str());

        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 525.f, 43.f });
        ImGui::SetNextItemWidth(142.f);
        if (ImGui::BeginCombo("##themes_combo", themes.at(rs_theme).name.c_str(), ImGuiComboFlags_NoArrowButton))
        {
            int Trs_theme = rs_theme;
            for (int i = 0; i < themes.size(); ++i)
            {
                bool is_selected = (Trs_theme == i);
                if (ImGui::Selectable(themes.at(i).name.c_str(), is_selected))
                {
                    rs_theme = i;
                }

                if (is_selected)
                    ImGui::SetItemDefaultFocus();
            }

            ImGui::EndCombo();
        }
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_THEME_TOOLTIP);
        ImGui::SameLine(0.f, 0.f);
        if (ImGui::ArrowButton("##themes_left", ImGuiDir_Left) && rs_theme > 0)
        {
            --rs_theme;
        }
        ImGui::SameLine(0.f, 0.f);
        if (ImGui::ArrowButton("##themes_right", ImGuiDir_Right) && themes.size() && rs_theme < (themes.size() - 1))
        {
            ++rs_theme;
        }

        ImGui::SetWindowFontScale(0.8f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 545.f, 70.f });
        if (ImGui::Checkbox("##dualtheme", &dualtheme)) {
            // We activate dualtheme
            if (dualtheme && !is_in_MainMenu) {
                ChangeTheme(rs_gameTheme);
            }
            else {
                // We deactivate dualtheme;
                ChangeTheme(rs_theme);
            }
        };

        ImGui::SetWindowFontScale(1.3f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 565.f, 68.f });
        ImGui::TextColored(ImVec4{ 0.8f, 0.8f, 0.8f, 1.f }, (GetLang(LANG_GAME_THEME)).c_str());

        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        if (dualtheme) {
            ImGui::SetCursorPos({ 525.f, 88.f });
            ImGui::SetNextItemWidth(142.f);
            if (ImGui::BeginCombo("##themes2_combo", themes.at(rs_gameTheme).name.c_str(), ImGuiComboFlags_NoArrowButton))
            {
                int Trs_theme2 = rs_gameTheme;
                for (int i = 0; i < themes.size(); ++i)
                {
                    bool is_selected = (Trs_theme2 == i);
                    if (ImGui::Selectable(themes.at(i).name.c_str(), is_selected))
                    {
                            rs_gameTheme = i;
                    }

                    if (is_selected)
                        ImGui::SetItemDefaultFocus();
                }

                ImGui::EndCombo();
            }
            if (ImGui::IsItemHovered())
                tooltip = GetLang(LANG_THEME_TOOLTIP);
            ImGui::SameLine(0.f, 0.f);
            if (ImGui::ArrowButton("##themes2_left", ImGuiDir_Left) && rs_gameTheme > 0)
                --rs_gameTheme;
            {
            }
            ImGui::SameLine(0.f, 0.f);
            if (ImGui::ArrowButton("##themes2_right", ImGuiDir_Right) && themes.size() && rs_gameTheme < (themes.size() - 1))
                ++rs_gameTheme;
            {
            }
        }
        else {
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.5f);
            ImGui::SetCursorPos({ 525.f, 88.f });
            ImGui::SetNextItemWidth(142.f);
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.2f, 0.2f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.3f, 0.3f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.4f, 0.4f, 0.4f, 1.0f));
            ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.f, 0.5f));
            if (ImGui::Button(themes.at(rs_gameTheme).name.c_str(), ImVec2(142.f, ImGui::GetTextLineHeightWithSpacing()))) {
            }
            ImGui::PopStyleVar();
            ImGui::PopStyleColor(3);
            ImGui::SameLine(0.f, 0.f);
            ImGui::ArrowButton("##themes2_left", ImGuiDir_Left);
            ImGui::SameLine(0.f, 0.f);
            ImGui::ArrowButton("##themes2_right", ImGuiDir_Right);
            ImGui::PopStyleVar();
        }

        ImGui::SetCursorPos({ 103.f, 120.f });
        if (ImGui::Button(GetLang(LANG_X).c_str(), { 65.f, 0.f }))
            rs_x_edit = !rs_x_edit;
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_X_TOOLTIP);
        ImGui::SetCursorPos({ 158.f, 120.f });
        ImGui::SetNextItemWidth(rs_x_edit ? 170.f : 150.f);
        if (!rs_x_edit)
        {
            ImGui::SliderFloat("##x_position", &rs_x, 0.f, 1.f, "%.3f");
            ImGui::SetCursorPos({ 312.f, 120.f });
            if (ImGui::Button("R##Rx_position"))
            {
                rs_x = 0.f;
                if (theme_config["x"].is_string())
                    rs_x = (float(Utils::EvaluateExpression(theme_config["x"], int(theme_size.x * rs_scale), display_size)) / display_size.x);
                else if (theme_config["x"].is_number())
                    rs_x = float(theme_config["x"]);
            }
            if (ImGui::IsItemHovered())
                tooltip = GetLang(LANG_RESET_TOOLTIP);
        }
        else
            ImGui::InputFloat("##x_position", &rs_x, 0.001f, 0.1f, "%.3f");

        ImGui::SetCursorPos({ 421.f, 120.f });
        if (ImGui::Button(GetLang(LANG_Y).c_str(), { 65.f, 0.f }))
            rs_y_edit = !rs_y_edit;
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_Y_TOOLTIP);
        ImGui::SetCursorPos({ 476.f, 120.f });
        ImGui::SetNextItemWidth(rs_y_edit ? 170.f : 150.f);
        if (!rs_y_edit)
        {
            ImGui::SliderFloat("##y_position", &rs_y, 0.f, 1.f, "%.3f");
            ImGui::SetCursorPos({ 630.f, 120.f });
            if (ImGui::Button("R##Ry_position"))
            {
                rs_y = 0.f;
                if (theme_config["y"].is_string())
                    rs_y = (float(Utils::EvaluateExpression(theme_config["y"], int(theme_size.y * rs_scale), display_size)) / display_size.y);
                else if (theme_config["y"].is_number())
                    rs_y = float(theme_config["y"]);
            }
            if (ImGui::IsItemHovered())
                tooltip = GetLang(LANG_RESET_TOOLTIP);
        }
        else
            ImGui::InputFloat("##y_position", &rs_y, 0.001f, 0.1f, "%.3f");

        ImGui::SetCursorPos({ 24.f, 165.f });
        if (ImGui::Button(GetLang(LANG_SCALE).c_str(), { 65, 0 }))
            rs_scale_edit = !rs_scale_edit;
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_SCALE_TOOLTIP);
        ImGui::SetCursorPos({ 79.f, 165.f });
        ImGui::SetNextItemWidth(rs_scale_edit ? 170.f : 150.f);
        if (!rs_scale_edit)
        {
            ImGui::SliderFloat("##scale", &rs_scale, cvar_scale.GetMinimum(), cvar_scale.GetMaximum(), "%.3f");
            ImGui::SetCursorPos({ 233.f, 165.f });
            if (ImGui::Button("R##Rscale"))
            {
                rs_scale = 1.f;
                if (theme_config["scale"].is_number())
                    rs_scale = float(theme_config["scale"]);
            }
            if (ImGui::IsItemHovered())
                tooltip = GetLang(LANG_RESET_TOOLTIP);
        }
        else
            ImGui::InputFloat("##scale", &rs_scale, 0.01f, 0.1f, "%.3f");

        ImGui::SetCursorPos({ 263.f, 165.f });
        if (ImGui::Button(GetLang(LANG_ROTATE).c_str(), { 65, 0 }))
            rs_rotate_edit = !rs_rotate_edit;
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_ROTATE_TOOLTIP);
        ImGui::SetCursorPos({ 318.f, 165.f });
        ImGui::SetNextItemWidth(rs_rotate_edit ? 170.f : 150.f);
        if (!rs_rotate_edit)
        {
            ImGui::SliderFloat("##rotate", &rs_rotate, cvar_rotate.GetMinimum(), cvar_rotate.GetMaximum(), "%.3f");
            ImGui::SetCursorPos({ 472.f, 165.f });
            if (ImGui::Button("R##Rrotate"))
            {
                rs_rotate = 0.f;
                if (theme_config["rotate"].is_number())
                    rs_rotate = float(theme_config["rotate"]);
            }
            if (ImGui::IsItemHovered())
                tooltip = GetLang(LANG_RESET_TOOLTIP);
        }
        else
            ImGui::InputFloat("##rotate", &rs_rotate, 0.001f, 0.1f, "%.3f");

        ImGui::SetCursorPos({ 502.f, 165.f });
        if (ImGui::Button(GetLang(LANG_OPACITY).c_str(), { 65.f, 0.f }))
            rs_opacity_edit = !rs_opacity_edit;
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_OPACITY_TOOLTIP);
        ImGui::SetCursorPos({ 557.f, 165.f });
        ImGui::SetNextItemWidth(rs_opacity_edit ? 170.f : 150.f);
        if (!rs_opacity_edit)
        {
            ImGui::SliderFloat("##opacity", &rs_opacity, cvar_opacity.GetMinimum(), cvar_opacity.GetMaximum(), "%.3f");
            ImGui::SetCursorPos({ 711.f, 165.f });
            if (ImGui::Button("R##Ropacity"))
            {
                rs_opacity = 1.f;
                if (theme_config["opacity"].is_number())
                    rs_opacity = float(theme_config["opacity"]);
            }
            if (ImGui::IsItemHovered())
                tooltip = GetLang(LANG_RESET_TOOLTIP);
        }
        else
            ImGui::InputFloat("##opacity", &rs_opacity, 0.001f, 0.1f, "%.3f");

        text_size = ImGui::CalcTextSize(GetLang(LANG_OVERLAY_OBS).c_str());
        ImGui::SetCursorPos({ ((settings_size.x - text_size.x) / 2.f), 200.f });
        ImGui::TextColored(ImVec4{ 0.94f, 0.77f, 0.f, 1.f }, GetLang(LANG_OVERLAY_OBS).c_str());

        ImGui::SetCursorPosY(228.f);
        ImGui::Separator();

        // Second Part
        ImGui::SetCursorPos({ 0.f, 238.f });
        image_pos = { p0.x + ImGui::GetCursorPosX(), p0.y + ImGui::GetCursorPosY() };
        drawlist->AddImage(rs_title->GetImGuiTex(), image_pos, { (image_size.X / 2) + image_pos.x, (image_size.Y / 2) + image_pos.y });

        ImGui::SetWindowFontScale(1.7f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 23.f, 263.f });
        ImGui::Checkbox("##in_file", &rs_in_file);
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_IN_FILE_TOOLTIP);

        ImGui::SetCursorPos({ 63.f, 265.f });
        ImGui::TextColored(ImVec4{ 0.2f, 0.2f, 0.2f, 1.f }, Utils::toupper(GetLang(LANG_IN_FILE)).c_str());

        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ (settings_size.x - 135.f), 241.f });
        if (ImGui::Button(GetLang(LANG_OPEN_FOLDER).c_str(), { 125.f, 0.f }))
            system(("powershell -WindowStyle Hidden \"start \"\"" + GetPath() + "\"\"\"").c_str());
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_OPEN_FOLDER_TOOLTIP);
        ImGui::SetCursorPos({ (settings_size.x - 135.f), 266.f });
        if (ImGui::Button(GetLang(LANG_RELOAD_THEME).c_str(), { 103.f, 0.f }))
        {
            LoadImgs();
            ChangeTheme(dualtheme && !is_in_MainMenu ? rs_gameTheme: rs_theme);
        }
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_RELOAD_THEME_TOOLTIP);
        ImGui::SetCursorPos({ (settings_size.x - 27.f), 266.f });
        if (ImGui::Button(GetLang(LANG_RELOAD_THEME_A).c_str(), { 17.f, 0.f }))
        {
            LoadImgs();
            LoadThemes();
            SetTheme(theme_render.name);
            ChangeTheme(dualtheme && !is_in_MainMenu ? rs_gameTheme: rs_theme);
        }
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_RELOAD_THEME_A_TOOLTIP);
        ImGui::SetCursorPos({ (settings_size.x - 135.f), 291.f });
        if (ImGui::Button(GetLang(LANG_RESET_STATS).c_str(), { 125.f, 0.f }))
            ResetStats();
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_RESET_STATS_TOOLTIP);

        ImGui::SetWindowFontScale(1.7f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ 280.f, 258.f });
        text_size = ImGui::CalcTextSize(theme_render.name.c_str());
        ImGui::TextColored(ImVec4{ 1.f, 1.f, 1.f, 1.f }, theme_render.name.c_str());
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::SetCursorPos({ (285.f + text_size.x), 265.f });
        ImGui::TextColored(ImVec4{ 1.f, 1.f, 1.f, 0.5f }, (theme_render.version + (theme_render.date.size() ? (" - " + theme_render.date) : "")).c_str());
        ImGui::SetCursorPos({ 290.f, 282.f });
        ImGui::TextColored(ImVec4{ 1.f, 1.f, 1.f, 0.8f }, ((GetLang(LANG_THEME_BY) + " ").c_str() + theme_render.author).c_str());

        ImGui::SetCursorPos({ (column_start - 8.f), 350.f });
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::BeginChild("##column1", { (column_width + 16.f), 205.f }, false, ImGuiWindowFlags_AlwaysVerticalScrollbar);
        ImGui::Checkbox(GetLang(LANG_SHOW_IN_MENU).c_str(), &rs_enable_inmenu);
        ImGui::Checkbox(GetLang(LANG_SHOW_IN_GAME).c_str(), &rs_enable_ingame);
        ImGui::Checkbox(GetLang(LANG_SHOW_IN_SCOREBOARD).c_str(), &rs_enable_inscoreboard);
        ImGui::Checkbox(GetLang(LANG_FLOATING_POINT).c_str(), &rs_enable_float);
        ImGui::Checkbox(GetLang(LANG_PREVIEW_RANK).c_str(), &rs_preview_rank);
        ImGui::Checkbox(GetLang(LANG_ROMAN_NUMBERS).c_str(), &rs_roman_numbers);
        ImGui::Checkbox(GetLang(LANG_MMR_TO_MMRCHANGE).c_str(), &rs_replace_mmr);
        ImGui::Checkbox(GetLang(LANG_MMR_TO_MMRCUMULCHANGE).c_str(), &rs_replace_mmr_cc);
        ImGui::Checkbox(GetLang(LANG_MMRCHANGE_TO_MMR).c_str(), &rs_replace_mmrc);
        ImGui::Checkbox(GetLang(LANG_MMRCHANGE_TO_MMRCUMULCHANGE).c_str(), &rs_replace_mmrc_cc);
        ImGui::Checkbox(GetLang(LANG_MMRCUMULCHANGE_TO_MMR).c_str(), &rs_replace_mmrcc);
        ImGui::Checkbox(GetLang(LANG_MMRCUMULCHANGE_TO_MMRCHANGE).c_str(), &rs_replace_mmrcc_c);
        ImGui::EndChild();

        rs_select_all_file = (rs_file_games && rs_file_gm && rs_file_rank && rs_file_div &&
            rs_file_mmr && rs_file_mmrc && rs_file_mmrcc &&
            rs_file_win && rs_file_loss && rs_file_streak && rs_file_winratio && rs_file_winpercentage && rs_file_score &&
            rs_file_boost &&
            rs_file_shots && rs_file_saves && rs_file_goals && rs_file_dropshot && rs_file_knockout && rs_file_miscs && rs_file_accolades);
        select_all = rs_select_all_file;
        tpos = { (column_start + column_space + (column_width + 16.f) - 0.5f), 323.f };
        ImGui::SetCursorPos(tpos);
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, { 0.3f, 0.3f, 0.3f, 1.f });
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, { 0.3f, 0.3f, 0.3f, 1.f });
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, { 0.3f, 0.3f, 0.3f, 1.f });
        ImGui::PushStyleColor(ImGuiCol_CheckMark, { 0.f, 0.f, 0.f, 0.8f });
        ImGui::GetWindowDrawList()->AddLine({ (tpos.x + win_pos.x + 5.f), (tpos.y + win_pos.y + 17.f) }, { (tpos.x + win_pos.x + 200.f), (tpos.y + win_pos.y + 17.f) }, ImGui::ColorConvertFloat4ToU32({ 0.3f, 0.3f, 0.3f, 1.f }), 2.f);
        ImGui::Checkbox("##select_all_file", &select_all);
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_SELECT_ALL_TOOLTIP);
        ImGui::PopStyleColor(4);
        ImGui::SetWindowFontScale(1.2f / (font ? 2.f : 1.f));
        ImGui::SameLine();
        ImGui::SetCursorPosY(316.f);
        ImGui::TextColored(ImVec4{ 0.8f, 0.8f, 0.8f, 1.f }, GetLang(LANG_FILE_TITLE).c_str());
        ImGui::SetCursorPos({ (column_start + column_space + (column_width + 16.f)), 350.f });
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::BeginChild("##column2", { (column_width - 8.f), 205.f }, false, ImGuiWindowFlags_AlwaysVerticalScrollbar);
        if (!rs_in_file)
            ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.5f);
        ImGui::Checkbox(GetLang(LANG_GAMES).c_str(), &rs_file_games);
        ImGui::Checkbox(GetLang(LANG_GAMEMODE).c_str(), &rs_file_gm);
        ImGui::Checkbox(GetLang(LANG_RANK).c_str(), &rs_file_rank);
        ImGui::Checkbox(GetLang(LANG_DIVISION).c_str(), &rs_file_div);
        ImGui::Checkbox(GetLang(LANG_MMR).c_str(), &rs_file_mmr);
        ImGui::Checkbox(GetLang(LANG_MMRCHANGE).c_str(), &rs_file_mmrc);
        ImGui::Checkbox(GetLang(LANG_MMRCUMULCHANGE).c_str(), &rs_file_mmrcc);
        ImGui::Checkbox(GetLang(LANG_WINS).c_str(), &rs_file_win);
        ImGui::Checkbox(GetLang(LANG_LOSSES).c_str(), &rs_file_loss);
        ImGui::Checkbox(GetLang(LANG_STREAKS).c_str(), &rs_file_streak);
        ImGui::Checkbox(GetLang(LANG_WINRATIO).c_str(), &rs_file_winratio);
        ImGui::Checkbox(GetLang(LANG_WINPERCENTAGE).c_str(), &rs_file_winpercentage);
        ImGui::Checkbox(GetLang(LANG_SCORE).c_str(), &rs_file_score);
        ImGui::Checkbox(GetLang(LANG_SHOTS).c_str(), &rs_file_shots);
        ImGui::Checkbox(GetLang(LANG_SAVES).c_str(), &rs_file_saves);
        ImGui::Checkbox(GetLang(LANG_GOALS).c_str(), &rs_file_goals);
        ImGui::Checkbox(GetLang(LANG_DROPSHOT).c_str(), &rs_file_dropshot);
        ImGui::Checkbox(GetLang(LANG_KNOCKOUT).c_str(), &rs_file_knockout);
        ImGui::Checkbox(GetLang(LANG_MISCS).c_str(), &rs_file_miscs);
        ImGui::Checkbox(GetLang(LANG_ACCOLADES).c_str(), &rs_file_accolades);
        ImGui::Checkbox(GetLang(LANG_BOOST).c_str(), &rs_file_boost);
        if (!rs_in_file)
            ImGui::PopStyleVar();
        ImGui::EndChild();

        if (select_all != rs_select_all_file)
        {
            rs_select_all_file = !rs_select_all_file;

            rs_file_games = rs_select_all_file;
            rs_file_gm = rs_select_all_file;
            rs_file_rank = rs_select_all_file;
            rs_file_div = rs_select_all_file;
            rs_file_mmr = rs_select_all_file;
            rs_file_mmrc = rs_select_all_file;
            rs_file_mmrcc = rs_select_all_file;
            rs_file_win = rs_select_all_file;
            rs_file_loss = rs_select_all_file;
            rs_file_streak = rs_select_all_file;
            rs_file_winratio = rs_select_all_file;
            rs_file_winpercentage = rs_select_all_file;
            rs_file_score = rs_select_all_file;
            rs_file_shots = rs_select_all_file;
            rs_file_saves = rs_select_all_file;
            rs_file_goals = rs_select_all_file;
            rs_file_dropshot = rs_select_all_file;
            rs_file_knockout = rs_select_all_file;
            rs_file_miscs = rs_select_all_file;
            rs_file_accolades = rs_select_all_file;
            rs_file_boost = rs_select_all_file;
        }

        rs_select_all_hide = (rs_hide_games && rs_hide_gm && rs_hide_rank && rs_hide_div &&
            rs_hide_mmr && rs_hide_mmrc && rs_hide_mmrcc &&
            rs_hide_win && rs_hide_loss && rs_hide_streak && rs_hide_winratio && rs_hide_winpercentage && rs_hide_score &&
            rs_hide_shots && rs_hide_saves && rs_hide_goals && rs_hide_dropshot && rs_hide_knockout && rs_hide_miscs && rs_hide_accolades);
        select_all = rs_select_all_hide;
        tpos = { (column_start + (column_space * 2.f) + ((column_width * 2.f) + 16.f)), 323.f };
        ImGui::SetCursorPos(tpos);
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::PushStyleColor(ImGuiCol_FrameBg, { 0.3f, 0.3f, 0.3f, 1.f });
        ImGui::PushStyleColor(ImGuiCol_FrameBgActive, { 0.3f, 0.3f, 0.3f, 1.f });
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, { 0.3f, 0.3f, 0.3f, 1.f });
        ImGui::PushStyleColor(ImGuiCol_CheckMark, { 0.f, 0.f, 0.f, 0.8f });
        ImGui::GetWindowDrawList()->AddLine({ (tpos.x + win_pos.x + 5.f), (tpos.y + win_pos.y + 17.f) }, { (tpos.x + win_pos.x + 200.f), (tpos.y + win_pos.y + 17.f) }, ImGui::ColorConvertFloat4ToU32({ 0.3f, 0.3f, 0.3f, 1.f }), 2.f);
        ImGui::Checkbox("##select_all_hide", &select_all);
        if (ImGui::IsItemHovered())
            tooltip = GetLang(LANG_SELECT_ALL_TOOLTIP);
        ImGui::PopStyleColor(4);
        ImGui::SetWindowFontScale(1.2f / (font ? 2.f : 1.f));
        ImGui::SameLine();
        ImGui::SetCursorPosY(316.f);
        ImGui::TextColored(ImVec4{ 0.8f, 0.8f, 0.8f, 1.f }, GetLang(LANG_HIDE_TITLE).c_str());
        ImGui::SetCursorPos({ (column_start + (column_space * 2.f) + ((column_width * 2.f) + 16.f)), 350.f });
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::BeginChild("##column3", { (column_width - 8.f), 205.f }, false, ImGuiWindowFlags_AlwaysVerticalScrollbar);
        ImGui::Checkbox(GetLang(LANG_GAMES).c_str(), &rs_hide_games);
        ImGui::Checkbox(GetLang(LANG_GAMEMODE).c_str(), &rs_hide_gm);
        ImGui::Checkbox(GetLang(LANG_RANK).c_str(), &rs_hide_rank);
        ImGui::Checkbox(GetLang(LANG_DIVISION).c_str(), &rs_hide_div);
        ImGui::Checkbox(GetLang(LANG_MMR).c_str(), &rs_hide_mmr);
        ImGui::Checkbox(GetLang(LANG_MMRCHANGE).c_str(), &rs_hide_mmrc);
        ImGui::Checkbox(GetLang(LANG_MMRCUMULCHANGE).c_str(), &rs_hide_mmrcc);
        ImGui::Checkbox(GetLang(LANG_WINS).c_str(), &rs_hide_win);
        ImGui::Checkbox(GetLang(LANG_LOSSES).c_str(), &rs_hide_loss);
        ImGui::Checkbox(GetLang(LANG_STREAKS).c_str(), &rs_hide_streak);
        ImGui::Checkbox(GetLang(LANG_WINRATIO).c_str(), &rs_hide_winratio);
        ImGui::Checkbox(GetLang(LANG_WINPERCENTAGE).c_str(), &rs_hide_winpercentage);
        ImGui::Checkbox(GetLang(LANG_SCORE).c_str(), &rs_hide_score);
        ImGui::Checkbox(GetLang(LANG_SHOTS).c_str(), &rs_hide_shots);
        ImGui::Checkbox(GetLang(LANG_SAVES).c_str(), &rs_hide_saves);
        ImGui::Checkbox(GetLang(LANG_GOALS).c_str(), &rs_hide_goals);
        ImGui::Checkbox(GetLang(LANG_DROPSHOT).c_str(), &rs_hide_dropshot);
        ImGui::Checkbox(GetLang(LANG_KNOCKOUT).c_str(), &rs_hide_knockout);
        ImGui::Checkbox(GetLang(LANG_MISCS).c_str(), &rs_hide_miscs);
        ImGui::Checkbox(GetLang(LANG_ACCOLADES).c_str(), &rs_hide_accolades);
        ImGui::EndChild();

        if (select_all != rs_select_all_hide)
        {
            rs_select_all_hide = !rs_select_all_hide;

            rs_hide_games = rs_select_all_hide;
            rs_hide_gm = rs_select_all_hide;
            rs_hide_rank = rs_select_all_hide;
            rs_hide_div = rs_select_all_hide;
            rs_hide_mmr = rs_select_all_hide;
            rs_hide_mmrc = rs_select_all_hide;
            rs_hide_mmrcc = rs_select_all_hide;
            rs_hide_win = rs_select_all_hide;
            rs_hide_loss = rs_select_all_hide;
            rs_hide_streak = rs_select_all_hide;
            rs_hide_winratio = rs_select_all_hide;
            rs_hide_winpercentage = rs_select_all_hide;
            rs_hide_score = rs_select_all_hide;
            rs_hide_shots = rs_select_all_hide;
            rs_hide_saves = rs_select_all_hide;
            rs_hide_goals = rs_select_all_hide;
            rs_hide_dropshot = rs_select_all_hide;
            rs_hide_knockout = rs_select_all_hide;
            rs_hide_miscs = rs_select_all_hide;
            rs_hide_accolades = rs_select_all_hide;
        }

        /* Variable to use to animate images
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10.f);
        ImGui::Separator();
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10.f);
        float fps = ImGui::GetIO().Framerate;
        ImGui::Text(("Framerate: " + std::to_string(fps)).c_str());
        */

        // Footer
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10.f);
        ImGui::Separator();

        ImGui::TextColored(((time_error || local_time.tm_sec % 2) ? ImVec4{ 0.04f, 0.52f, 0.89f, 1.f } : ImVec4{ 1.f, 1.f, 1.f, 0.5f }), GetLang(LANG_DONATE).c_str());
        if (ImGui::IsItemHovered())
        {
            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
            if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
                system("powershell -WindowStyle Hidden \"start https://www.paypal.com/paypalme/rocketstats\"");
        }
        ImGui::SameLine();
        ImGui::Text("|");
        ImGui::SameLine();
        ImGui::TextColored(ImVec4{ 0.04f, 0.52f, 0.89f, 1.f }, "Discord");
        if (ImGui::IsItemHovered())
        {
            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
            if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
                system("powershell -WindowStyle Hidden \"start https://discord.gg/weBCBE4\"");
        }
        ImGui::SameLine();
        text_size = ImGui::CalcTextSize(GetLang(LANG_DEVELOPERS).c_str());
        ImGui::SetCursorPosX((settings_size.x - text_size.x) / 2.f);
        ImGui::Text(GetLang(LANG_DEVELOPERS).c_str());
        text_size = ImGui::CalcTextSize(menu_version.c_str());
        ImGui::SameLine();
        ImGui::SetCursorPosX(settings_size.x - text_size.x - 7.f);
        ImGui::Text(menu_version.c_str());

        drawlist->PopClipRect();
    }
    else
    {
        ImGui::SetWindowFontScale(1.5f / (font ? 2.f : 1.f));
        ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), (GetLang(LANG_ERROR) + ": data/RocketStats").c_str());
        ImGui::SameLine();
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));
        ImGui::SetCursorPosX(settings_size.x - 80.f - 7.f);
        if (ImGui::Button(GetLang(LANG_ERROR_RELOAD).c_str(), { 80.f, 0.f }))
        {
            LoadImgs();
            LoadThemes();
            ChangeTheme(rs_theme);
            rs_logo = LoadImg("RocketStats_images/logo.tga");
            rs_title = LoadImg("RocketStats_images/title.tga");
        }
    }

    ImGui::End();

    if (!tooltip.empty())
    {
        ImGui::Begin((menu_title + "##Tooltip").c_str(), nullptr, (ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoFocusOnAppearing));
        ImGui::SetWindowFontScale(1.f / (font ? 2.f : 1.f));

        ImVec4 color;
        float padding = 8.f;
        ImVec2 mouse_pos = ImGui::GetIO().MousePos;
        ImDrawList* drawlist = ImGui::GetForegroundDrawList();
        ImVec2 text_size = ImGui::CalcTextSize(tooltip.c_str());
        ImVec2 tooltip_min = { (mouse_pos.x + 25.f), (mouse_pos.y + 2.f) };
        ImVec2 tooltip_max = { (tooltip_min.x + text_size.x + (2.f * padding)), (tooltip_min.y + text_size.y + (2.f * padding)) };

        color = ImGui::GetStyleColorVec4(ImGuiCol_FrameBg);
        drawlist->AddRectFilled(tooltip_min, tooltip_max, ImGui::ColorConvertFloat4ToU32({ color.x, color.x, color.x, 0.7f }));
        color = ImGui::GetStyleColorVec4(ImGuiCol_Border);
        drawlist->AddRect(tooltip_min, tooltip_max, ImGui::ColorConvertFloat4ToU32({ color.x, color.x, color.x, 0.4f }));
        color = ImGui::GetStyleColorVec4(ImGuiCol_Text);
        drawlist->AddText({ (tooltip_min.x + padding), (tooltip_min.y + padding) }, ImGui::ColorConvertFloat4ToU32({ color.x, color.x, color.x, 0.7f }), tooltip.c_str());

        ImGui::End();
    }

    if (menu_font)
        ImGui::PopFont();

    RefreshVars();
}

// Name of the menu that is used to toggle the window.
std::string RocketStats::GetMenuName()
{
    return menu_name;
}

// Title to give the menu
std::string RocketStats::GetMenuTitle()
{
    return menu_title;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void RocketStats::SetImGuiContext(uintptr_t ctx)
{
    ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool RocketStats::ShouldBlockInput()
{
    return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool RocketStats::IsActiveOverlay()
{
    return (settings_open || rs_recovery == RecoveryFlags_Files);
}

void RocketStats::OnOpen()
{
    //ToggleSettings("OnOpen", ToggleFlags_Show);
}

void RocketStats::OnClose()
{
    // Displays the plugin immediately after pressing the escape key
    if (escape_state)
    {
        escape_state = false;
        gameWrapper->SetTimeout([&](GameWrapper* gameWrapper) {
            cvarManager->executeCommand("togglemenu " + GetMenuName());
        }, 0.02f);
    }

    ToggleSettings("OnClose", ToggleFlags_Hide);
}
```

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

## File: Utils.cpp
```cpp
#include "Utils.h"

#pragma region Colors
float Utils::GetAlpha(std::vector<float> color, float opacity)
{
    return (((color.size() == 4) ? color[3] : 1.f) * opacity);
}

ImColor Utils::GetImColor(std::vector<float> color, float opacity)
{
    return ImGui::ColorConvertFloat4ToU32({ (float(color[0]) / 255.f), (float(color[1]) / 255.f), (float(color[2]) / 255.f), GetAlpha(color, opacity) });
}

ImColor Utils::LinearColor2ImColor(LinearColor color)
{
    return ImColor{ color.R, color.G, color.B, color.A };
}

std::vector<float> Utils::ImColor2RGBA(ImColor color)
{
    ImVec4 rgba = ImGui::ColorConvertU32ToFloat4(color);
    return std::vector<float>{ (rgba.x * 255.f), (rgba.y * 255.f), (rgba.z * 255.f), rgba.w };
}

std::vector<float> Utils::LinearColor2RGBA(LinearColor color)
{
    return std::vector<float>{ (color.R * 255.f), (color.G * 255.f), (color.B * 255.f), color.A };
}
#pragma endregion

#pragma region Strings
LPSTR Utils::ConvertToLPSTR(const std::string& str)
{
    LPSTR cstr = new char[str.size() + 1]; // +1 for zero at the end
    copy(str.begin(), str.end(), cstr);
    cstr[str.size()] = 0; // zero at the end
    return cstr;
}

std::string Utils::ljust(std::string str, size_t n, char c)
{
    size_t size = str.size();
    if (size >= n)
        return str;

    return str.replace(str.end(), str.end(), (n - size), c);
}

std::string Utils::tolower(std::string str)
{
    std::string lower;
    for (auto& c : str)
        lower += std::tolower(c);

    return lower;
}

std::string Utils::toupper(std::string str)
{
    std::string upper;
    for (auto& c : str)
        upper += std::toupper(c);

    return upper;
}

std::string Utils::capitalize(std::string str)
{
    std::string capital;
    for (size_t i = 0; i < str.size(); ++i)
    {
        const char c = str[i];
        capital += (((!i || str[i - 1] == ' ') && c >= 'a' && c <= 'z') ? (c - 32) : c);
    }

    return capital;
}

void Utils::ReplaceAll(std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return;

    std::string::size_type start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

void Utils::ReplaceVars(std::string& str, std::map<std::string, std::string>& vars, std::function<void(const std::string&, std::string&)> passe)
{
    int i;
    int len = (int)str.length();
    int end = -1;

    for (i = (len - 1); i >= 0; --i)
    {
        if (end >= 0 && i > 0 && str[i] == '{' && str[i - 1] == '{')
        {
            const std::string key = str.substr((i + 1), ((end - 1) - (i + 1)));
            std::string value = ((vars.find(key) != vars.end()) ? vars[key] : "");

            if (passe != nullptr)
                passe(key, value);

            str.replace((i - 1), ((end + 1) - (i - 1)), value);
            end = -1;
        }
        else if (str[i] == '}' && i < (len - 1) && str[i + 1] == '}')
            end = (i + 1);
    }
}

std::string Utils::FloatFixer(float a_value, size_t n)
{
    return Utils::FloatFixer(std::to_string(a_value), n);
}

std::string Utils::FloatFixer(std::string str, size_t n)
{
    size_t pos = str.find('.');
    if (pos != std::string::npos)
    {
        if (n)
            ++pos;

        str = str.substr(0, (pos + n));
    }

    return str;
}

std::string Utils::PointFixer(float a_value, size_t n, size_t md)
{
    std::string str = std::to_string(a_value);
    size_t pos = (str.find('.') + 1);
    size_t len = str.length();

    if (len < n)
    {
        str.insert((len - 1), (n - len), '0');

        len = str.length();
        if ((len - pos) < md)
            str.insert((len - 1), (md - (len - pos)), '0');
    }
    else if (!n)
        str = FloatFixer(str, 0);
    else if (len > n)
        str = FloatFixer(str, max((int(n) - int(pos)), int(md)));

    return str;
}
#pragma endregion

#pragma region Arrays
std::vector<std::string> Utils::Split(const std::string& str, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;

    while (std::getline(ss, item, delim))
        result.push_back(item);

    return result;
}

std::map<std::string, int> Utils::SplitKeyInt(const std::string str, size_t offset)
{
    std::map<std::string, int> result;
    std::vector<std::string> values = Split(str.substr(offset), ' ');

    for (const auto& value : values)
    {
        size_t value_assign = value.find('=');
        if (value_assign != std::string::npos)
        {
            std::string key = value.substr(0, value_assign);
            result.insert(std::make_pair(value.substr(0, value_assign), std::stoi(value.substr(value_assign + 1))));
        }
    }

    return result;
}

size_t Utils::FindKeyInt(std::vector<std::map<std::string, int>> vector, std::string key, int value)
{
    size_t index = 0;
    for (auto& map : vector)
    {
        if (map[key] == value)
            return index;

        ++index;
    }

    return std::string::npos;
}
#pragma endregion

#pragma region Operations
int Utils::EvaluateExpression(std::string str, int percent2pixels, ImVec2 screen_size)
{
    char c;
    char lc;
    size_t pos;
    size_t lpos;

    ReplaceAll(str, " ", "");
    for (pos = 0, lpos = std::string::npos; pos < str.length(); ++pos)
    {
        c = str[pos];
        if (pos)
            lc = str[pos - 1];

        bool error = ((c == '%' || c == 'v' || c == 'p') && (!pos || (lc < '0' || lc > '9')));
        error = (error || ((c == 'w' || c == 'h') && (!pos || lc != 'v')));
        error = (error || (c == 'x' && (!pos || lc != 'p')));

        if (lpos != std::string::npos && c == '%')
        {
            float percent = (std::stof(str.substr(lpos, (pos - lpos))) / 100.f);
            str.replace(lpos, ((pos + 1) - lpos), std::to_string((int)std::round(percent * percent2pixels)));
            lpos = std::string::npos;
        }
        else if (lpos != std::string::npos && (c == 'w' || c == 'h'))
        {
            float percent = (std::stof(str.substr(lpos, ((pos - 1) - lpos))) / 100.f);
            str.replace(lpos, ((pos + 1) - lpos), std::to_string((int)std::round(percent * ((c == 'h') ? screen_size.y : screen_size.x))));
            lpos = std::string::npos;
        }
        else if (lpos == std::string::npos && c >= '0' && c <= '9')
            lpos = pos;

        if (error)
            throw std::invalid_argument("received bad string");
    }

    ReplaceAll(str, "px", "");

    int error;
    return int(te_interp(str.c_str(), &error));
}
#pragma endregion
```

## File: Utils.h
```c
#pragma once

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <functional>

#include <pch.h>
#include <tinyexpr/tinyexpr.h>

using namespace std;


class Utils
{
public:
	// Colors
	static float GetAlpha(std::vector<float> color, float opacity = 1.f);
	static ImColor GetImColor(std::vector<float> color, float opacity = 1.f);
	static ImColor LinearColor2ImColor(LinearColor color);
	static std::vector<float> ImColor2RGBA(ImColor color);
	static std::vector<float> LinearColor2RGBA(LinearColor color);

	// Strings
	static LPSTR ConvertToLPSTR(const std::string& s);
	static std::string ljust(std::string str, size_t n, char c);
	static std::string tolower(std::string str);
	static std::string toupper(std::string str);
	static std::string capitalize(std::string str);
	static void ReplaceAll(std::string& str, const std::string& from, const std::string& to);
	static void ReplaceVars(std::string& str, std::map<std::string, std::string>& vars, std::function<void(const std::string&, std::string&)> passe = nullptr);
	static std::string FloatFixer(float a_value, size_t n);
	static std::string FloatFixer(std::string str, size_t n);
	static std::string PointFixer(float a_value, size_t n, size_t md);

	// Arrays
	static std::vector<std::string> Split(const std::string& str, char delim);
	static std::map<std::string, int> SplitKeyInt(const std::string str, size_t offset = 0);
	static size_t FindKeyInt(std::vector<std::map<std::string, int>> vector, std::string key, int value);

	// Operations
	static int EvaluateExpression(std::string str, int percent2pixels, ImVec2 screen_size = { 0, 0 });
};
```
