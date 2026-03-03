#pragma once
#include <string>
#include <vector>

enum class CvarType {
    Boolean,
    Number,
    Decimal,
    Range,
    Color,
    String
};

struct ParsedCvar {
    std::string name;
    std::string currentValue;
    std::string rawComment;
    std::string default_val;        // same as currentValue at parse time (from config.cfg)
    std::string friendlyDescription; // populated by DescriptionsLoader
    CvarType type = CvarType::String;
    bool uncertain = false;         // populated by DescriptionsLoader

    // Range type
    float rangeMin = 0.f;
    float rangeMax = 0.f;

    // Color type (0-255)
    float colorR = 0.f;
    float colorG = 0.f;
    float colorB = 0.f;
    float colorA = 255.f;
};

class ConfigParser {
public:
    // Parse config.cfg and return all CVars sorted A-Z case-insensitive
    static std::vector<ParsedCvar> Parse(const std::string& configPath);

private:
    static CvarType DetectType(const std::string& value);
    static void ParseRange(const std::string& value, float& minVal, float& maxVal);
    static void ParseColor(const std::string& value, float& r, float& g, float& b, float& a);
};
