#pragma once
#include <string>
#include <vsh/stdc.h>
#include <ss_yaml.hpp>

class Config
{
public:
    Config();

    void Load();
    void LoadFile(const std::string& fileName);

public:
    uint8_t version{};
    struct {
        uint8_t displayMode{};
        uint8_t positionMode{};
        bool showFPS = true;
        bool showCpuInfo = true;
        bool showGpuInfo = true;
        bool showRAM = false;
        bool showFanSpeed = true;
        bool showFirmware = true;
        bool showAppName = true;
    } overlay;
};

extern Config g_Config;