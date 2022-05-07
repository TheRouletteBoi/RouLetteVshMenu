#pragma once
#include <string>
#include <vsh/stdc.h>
#include <ss_yaml.hpp>

class Config
{
public:
    enum class DisplayMode : uint8_t
    {
        XMB_GAME,
        XMB,
        GAME
    };

    enum class PostionStyle : uint8_t
    {
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT
    };

public:
    Config();

    void Load();
    void LoadFile(const std::string& fileName);

public:
    uint8_t version{};
    struct {
        DisplayMode displayMode = DisplayMode::XMB_GAME;
        PostionStyle positionStyle = PostionStyle::TOP_LEFT;
        bool showFPS = true;
        bool showCpuInfo = true;
        bool showGpuInfo = true;
        bool showRamInfo = false;
        bool showFanSpeed = true;
        bool showFirmware = true;
        bool showAppName = true;
    } overlay;
};

extern Config g_Config;