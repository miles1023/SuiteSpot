#include "pch.h"
#include "ConfigParser.h"
#include <fstream>
#include <algorithm>
#include <regex>
#include <cstdio>

std::vector<ParsedCvar> ConfigParser::Parse(const std::string& configPath)
{
    std::vector<ParsedCvar> results;
    std::ifstream file(configPath);
    if (!file.is_open()) return results;

    // Matches: cvar_name "value" //optional comment
    std::regex lineRe(R"regex(^([a-zA-Z_][a-zA-Z0-9_]*)\s+"([^"]*)"\s*(?://(.*))?$)regex");

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        // Skip comment lines, alias lines, bind lines
        if (line.rfind("//", 0) == 0) continue;
        if (line.rfind("alias", 0) == 0) continue;
        if (line.rfind("bind", 0) == 0) continue;

        std::smatch m;
        if (!std::regex_match(line, m, lineRe)) continue;

        ParsedCvar cvar;
        cvar.name         = m[1].str();
        cvar.currentValue = m[2].str();
        cvar.default_val  = m[2].str();
        cvar.rawComment   = (m.size() > 3 && m[3].matched) ? m[3].str() : "";
        cvar.type         = DetectType(cvar.currentValue);

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

CvarType ConfigParser::DetectType(const std::string& v)
{
    if (v == "0" || v == "1") return CvarType::Boolean;

    if (!v.empty() && v[0] == '(') {
        int commas = (int)std::count(v.begin(), v.end(), ',');
        return (commas == 3) ? CvarType::Color : CvarType::Range;
    }

    if (v.find('.') != std::string::npos) {
        try { float f = std::stof(v); (void)f; return CvarType::Decimal; } catch (...) {}
    }

    try { int n = std::stoi(v); (void)n; return CvarType::Number; } catch (...) {}

    return CvarType::String;
}

void ConfigParser::ParseRange(const std::string& v, float& minVal, float& maxVal)
{
    std::sscanf(v.c_str(), "(%f, %f)", &minVal, &maxVal);
}

void ConfigParser::ParseColor(const std::string& v, float& r, float& g, float& b, float& a)
{
    std::sscanf(v.c_str(), "(%f, %f, %f, %f)", &r, &g, &b, &a);
}
