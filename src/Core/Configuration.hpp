#pragma once
#include <string>
#include <vsh/stdc.h>
#include <ss_yaml.hpp>

class Config
{
public:
    enum DisplayMode : uint8_t
    {
        XMB,
        GAME,
        XMB_GAME
    };

    enum class PostionStyle : uint8_t
    {
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT
    };

    enum class TemperatureType : uint8_t
    {
        BOTH,
        CELSIUS,
        FAHRENHEIT
    };

public:
    Config();

    void Load();
    void LoadFile(const std::string& fileName);
    void ResetSettings();

public:
    uint8_t version{};
    struct {
        DisplayMode displayMode = DisplayMode::XMB_GAME;
        struct {
            PostionStyle positionStyle = PostionStyle::TOP_LEFT;
            bool showFPS = true;
            bool showCpuInfo = true;
            bool showGpuInfo = true;
            bool showRamInfo = false;
            bool showFanSpeed = true;
            bool showFirmware = true;
            bool showAppName = true;
            bool showClockSpeeds = true;
            TemperatureType temperatureType = TemperatureType::BOTH;
            float textSize = 20.0f;
            bool showPlayTime = false;
        } mode[5]; // 0 = XMB, 1 = GAME, 2 = DEFAULT, 3 = DEFAULT, 4 = DEFAULT
    } overlay;
};

extern Config g_Config;