#pragma once
#include "ConfigParser.h"
#include <string>
#include <vector>

class DescriptionsLoader {
public:
    // Reads cvars_descriptions.json and sets friendlyDescription, uncertain,
    // and default_val on each cvar. Falls back to rawComment if cvar not in JSON.
    static void Enrich(std::vector<ParsedCvar>& cvars, const std::string& jsonPath);
};
