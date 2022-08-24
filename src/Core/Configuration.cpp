#include "Configuration.hpp"
#include "Utils/FileSystem.hpp"

Config g_Config;

Config::Config()
{
    ResetSettings();
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

    switch (hash_str(_displayMode.c_str()))
    {
    case hash_str("XMB"):
        overlay.displayMode = DisplayMode::XMB;
        break;
    case hash_str("GAME"):
        overlay.displayMode = DisplayMode::GAME;
        break;
    case hash_str("XMB_GAME"):
        overlay.displayMode = DisplayMode::XMB_GAME;
        break;
    }

    if (_version >= 3)
    {
        auto xmb_position = doc.root()["overlay"]["type"]["xmb"]["position"].str();
        auto xmb_showFPS = doc.root()["overlay"]["type"]["xmb"]["showFPS"].boolean();
        auto xmb_showCpuInfo = doc.root()["overlay"]["type"]["xmb"]["showCpuInfo"].boolean();
        auto xmb_showGpuInfo = doc.root()["overlay"]["type"]["xmb"]["showGpuInfo"].boolean();
        auto xmb_showRamInfo = doc.root()["overlay"]["type"]["xmb"]["showRamInfo"].boolean();
        auto xmb_showFanSpeed = doc.root()["overlay"]["type"]["xmb"]["showFanSpeed"].boolean();
        auto xmb_showFirmware = doc.root()["overlay"]["type"]["xmb"]["showFirmware"].boolean();
        auto xmb_showAppName = doc.root()["overlay"]["type"]["xmb"]["showAppName"].boolean();
        auto xmb_showClockSpeeds = doc.root()["overlay"]["type"]["xmb"]["showClockSpeeds"].boolean();
        std::string xmb_temperatureType = doc.root()["overlay"]["type"]["xmb"]["temperatureType"].str();
        float xmb_textSize = doc.root()["overlay"]["type"]["xmb"]["textSize"].dbl();
        auto xmb_showPlayTime = doc.root()["overlay"]["type"]["xmb"]["showPlayTime"].boolean();


        switch (hash_str(xmb_position.c_str()))
        {
        case hash_str("TOP_LEFT"):
            overlay.mode[DisplayMode::XMB].positionStyle = PostionStyle::TOP_LEFT;
            break;
        case hash_str("TOP_RIGHT"):
            overlay.mode[DisplayMode::XMB].positionStyle = PostionStyle::TOP_RIGHT;
            break;
        case hash_str("BOTTOM_LEFT"):
            overlay.mode[DisplayMode::XMB].positionStyle = PostionStyle::BOTTOM_LEFT;
            break;
        case hash_str("BOTTOM_RIGHT"):
            overlay.mode[DisplayMode::XMB].positionStyle = PostionStyle::BOTTOM_RIGHT;
            break;
        }

        switch (hash_str(xmb_temperatureType.c_str()))
        {
        case hash_str("BOTH"):
            overlay.mode[DisplayMode::XMB].temperatureType = TemperatureType::BOTH;
            break;
        case hash_str("CELSIUS"):
            overlay.mode[DisplayMode::XMB].temperatureType = TemperatureType::CELSIUS;
            break;
        case hash_str("FAHRENHEIT"):
            overlay.mode[DisplayMode::XMB].temperatureType = TemperatureType::FAHRENHEIT;
            break;
        }


        overlay.mode[DisplayMode::XMB].showFPS = xmb_showFPS;
        overlay.mode[DisplayMode::XMB].showCpuInfo = xmb_showCpuInfo;
        overlay.mode[DisplayMode::XMB].showGpuInfo = xmb_showGpuInfo;
        overlay.mode[DisplayMode::XMB].showRamInfo = xmb_showRamInfo;
        overlay.mode[DisplayMode::XMB].showFanSpeed = xmb_showFanSpeed;
        overlay.mode[DisplayMode::XMB].showFirmware = xmb_showFirmware;
        overlay.mode[DisplayMode::XMB].showAppName = xmb_showAppName;
        overlay.mode[DisplayMode::XMB].showClockSpeeds = xmb_showClockSpeeds;
        overlay.mode[DisplayMode::XMB].textSize = xmb_textSize;
        overlay.mode[DisplayMode::XMB].showPlayTime = xmb_showPlayTime;


        //////////////////////////////
        //////// GAME SETTINGS ///////
        //////////////////////////////


        auto game_position = doc.root()["overlay"]["type"]["game"]["position"].str();
        auto game_showFPS = doc.root()["overlay"]["type"]["game"]["showFPS"].boolean();
        auto game_showCpuInfo = doc.root()["overlay"]["type"]["game"]["showCpuInfo"].boolean();
        auto game_showGpuInfo = doc.root()["overlay"]["type"]["game"]["showGpuInfo"].boolean();
        auto game_showRamInfo = doc.root()["overlay"]["type"]["game"]["showRamInfo"].boolean();
        auto game_showFanSpeed = doc.root()["overlay"]["type"]["game"]["showFanSpeed"].boolean();
        auto game_showFirmware = doc.root()["overlay"]["type"]["game"]["showFirmware"].boolean();
        auto game_showAppName = doc.root()["overlay"]["type"]["game"]["showAppName"].boolean();
        bool game_showClockSpeeds = doc.root()["overlay"]["type"]["game"]["showClockSpeeds"].boolean();
        std::string game_temperatureType = doc.root()["overlay"]["type"]["game"]["temperatureType"].str();
        float game_textSize = doc.root()["overlay"]["type"]["game"]["textSize"].dbl();
        auto game_showPlayTime = doc.root()["overlay"]["type"]["xmb"]["showPlayTime"].boolean();

        switch (hash_str(game_position.c_str()))
        {
        case hash_str("TOP_LEFT"):
            overlay.mode[DisplayMode::GAME].positionStyle = PostionStyle::TOP_LEFT;
            break;
        case hash_str("TOP_RIGHT"):
            overlay.mode[DisplayMode::GAME].positionStyle = PostionStyle::TOP_RIGHT;
            break;
        case hash_str("BOTTOM_LEFT"):
            overlay.mode[DisplayMode::GAME].positionStyle = PostionStyle::BOTTOM_LEFT;
            break;
        case hash_str("BOTTOM_RIGHT"):
            overlay.mode[DisplayMode::GAME].positionStyle = PostionStyle::BOTTOM_RIGHT;
            break;
        }

        switch (hash_str(game_temperatureType.c_str()))
        {
        case hash_str("BOTH"):
            overlay.mode[DisplayMode::GAME].temperatureType = TemperatureType::BOTH;
            break;
        case hash_str("CELSIUS"):
            overlay.mode[DisplayMode::GAME].temperatureType = TemperatureType::CELSIUS;
            break;
        case hash_str("FAHRENHEIT"):
            overlay.mode[DisplayMode::GAME].temperatureType = TemperatureType::FAHRENHEIT;
            break;
        }


        overlay.mode[DisplayMode::GAME].showFPS = game_showFPS;
        overlay.mode[DisplayMode::GAME].showCpuInfo = game_showCpuInfo;
        overlay.mode[DisplayMode::GAME].showGpuInfo = game_showGpuInfo;
        overlay.mode[DisplayMode::GAME].showRamInfo = game_showRamInfo;
        overlay.mode[DisplayMode::GAME].showFanSpeed = game_showFanSpeed;
        overlay.mode[DisplayMode::GAME].showFirmware = game_showFirmware;
        overlay.mode[DisplayMode::GAME].showAppName = game_showAppName;
        overlay.mode[DisplayMode::GAME].showClockSpeeds = game_showClockSpeeds;
        overlay.mode[DisplayMode::GAME].textSize = game_textSize;
        overlay.mode[DisplayMode::GAME].showPlayTime = game_showPlayTime;
    }

    doc.parseEnd();
}

void Config::ResetSettings()
{
    overlay.displayMode = DisplayMode::XMB_GAME;

    for (int i = 0; i < 5; i++)
    {
        overlay.mode[i].positionStyle = PostionStyle::TOP_LEFT;
        overlay.mode[i].showFPS = true;
        overlay.mode[i].showCpuInfo = true;
        overlay.mode[i].showGpuInfo = true;
        overlay.mode[i].showRamInfo = false;
        overlay.mode[i].showFanSpeed = true;
        overlay.mode[i].showFirmware = true;
        overlay.mode[i].showAppName = true;
        overlay.mode[i].showClockSpeeds = true;
        overlay.mode[i].temperatureType = TemperatureType::BOTH;
        overlay.mode[i].textSize = 20.0f;
        overlay.mode[i].showPlayTime = false;
    }
}