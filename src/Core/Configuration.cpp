#include "Configuration.hpp"
#include "Utils/FileSystem.hpp"

Config g_Config;

Config::Config()
{
    Load();
}

void Config::Load()
{
    const std::string& fileName = GetCurrentDir() + "VshFpsCounter.yaml";

    if (FileExist(fileName))
        LoadFile(fileName);
}

constexpr unsigned int hash_str(const char* s, int off = 0)
{
    return !s[off] ? 5381 : (hash_str(s, off + 1) * 33) ^ s[off];
}

void Config::LoadFile(const std::string& fileName)
{
    ss_yaml::Yaml doc;
    doc.parse(fileName.c_str());

    auto _version = doc.root()["version"].integer();
    auto _displayMode = doc.root()["overlay"]["displayMode"].str();
    auto _position = doc.root()["overlay"]["position"].str();
    auto _showFPS = doc.root()["overlay"]["showFPS"].boolean();
    auto _showCpuInfo = doc.root()["overlay"]["showCpuInfo"].boolean();
    auto _showGpuInfo = doc.root()["overlay"]["showGpuInfo"].boolean();
    auto _showRamInfo = doc.root()["overlay"]["showRamInfo"].boolean();
    auto _showFanSpeed = doc.root()["overlay"]["showFanSpeed"].boolean();
    auto _showFirmware = doc.root()["overlay"]["showFirmware"].boolean();
    auto _showAppName = doc.root()["overlay"]["showAppName"].boolean();

    bool _showClockSpeeds = true;
    std::string _temperatureType = "BOTH";
    if (_version >= 1)
    {
        _showClockSpeeds = doc.root()["overlay"]["showClockSpeeds"].boolean();
        _temperatureType = doc.root()["overlay"]["temperatureType"].str();
    }

    float _textSize = 20.0f;
    if (_version >= 2)
        _textSize = doc.root()["overlay"]["textSize"].dbl();


    switch (hash_str(_displayMode.c_str()))
    {
        case hash_str("XMB_GAME"):
            overlay.displayMode = DisplayMode::XMB_GAME;
            break;
        case hash_str("XMB"):
            overlay.displayMode = DisplayMode::XMB;
            break;
        case hash_str("GAME"):
            overlay.displayMode = DisplayMode::GAME;
            break;
        default:
            overlay.displayMode = DisplayMode::XMB_GAME;
            break;
    }

    switch (hash_str(_position.c_str()))
    {
        case hash_str("TOP_LEFT"):
            overlay.positionStyle = PostionStyle::TOP_LEFT;
            break;
        case hash_str("TOP_RIGHT"):
            overlay.positionStyle = PostionStyle::TOP_RIGHT;
            break;
        case hash_str("BOTTOM_LEFT"):
            overlay.positionStyle = PostionStyle::BOTTOM_LEFT;
            break;
        case hash_str("BOTTOM_RIGHT"):
            overlay.positionStyle = PostionStyle::BOTTOM_RIGHT;
            break;
        default:
            overlay.positionStyle = PostionStyle::TOP_LEFT;
            break;
    }

    switch (hash_str(_temperatureType.c_str()))
    {
        case hash_str("BOTH"):
            overlay.temperatureType = TemperatureType::BOTH;
            break;
        case hash_str("CELSIUS"):
            overlay.temperatureType = TemperatureType::CELSIUS;
            break;
        case hash_str("FAHRENHEIT"):
            overlay.temperatureType = TemperatureType::FAHRENHEIT;
            break;
        default:
            overlay.temperatureType = TemperatureType::BOTH;
            break;
    }


    overlay.showFPS = _showFPS;
    overlay.showCpuInfo = _showCpuInfo;
    overlay.showGpuInfo = _showGpuInfo;
    overlay.showRamInfo = _showRamInfo;
    overlay.showFanSpeed = _showFanSpeed;
    overlay.showFirmware = _showFirmware;
    overlay.showAppName = _showAppName;
    overlay.showClockSpeeds = _showClockSpeeds;
    overlay.textSize = _textSize;


    doc.parseEnd();
}