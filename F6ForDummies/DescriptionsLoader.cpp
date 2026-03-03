#include "pch.h"
#include "DescriptionsLoader.h"
#include "IMGUI/json.hpp"
#include <fstream>

using json = nlohmann::json;

void DescriptionsLoader::Enrich(std::vector<ParsedCvar>& cvars, const std::string& jsonPath)
{
    std::ifstream file(jsonPath);
    if (!file.is_open()) {
        // Fallback: use rawComment for all
        for (auto& c : cvars) {
            if (c.friendlyDescription.empty()) c.friendlyDescription = c.rawComment;
        }
        return;
    }

    json j;
    try { file >> j; }
    catch (...) {
        for (auto& c : cvars) {
            if (c.friendlyDescription.empty()) c.friendlyDescription = c.rawComment;
        }
        return;
    }

    for (auto& cvar : cvars) {
        auto it = j.find(cvar.name);
        if (it == j.end()) {
            cvar.friendlyDescription = cvar.rawComment;
            continue;
        }
        const json& entry = *it;

        if (entry.contains("description") && entry["description"].is_string())
            cvar.friendlyDescription = entry["description"].get<std::string>();
        else
            cvar.friendlyDescription = cvar.rawComment;

        if (entry.contains("default") && entry["default"].is_string())
            cvar.default_val = entry["default"].get<std::string>();

        if (entry.contains("uncertain") && entry["uncertain"].is_boolean())
            cvar.uncertain = entry["uncertain"].get<bool>();
    }
}
