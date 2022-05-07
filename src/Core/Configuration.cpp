#include "Configuration.hpp"
#include "Utils/FileSystem.hpp"

constexpr unsigned int hash_str(const char* s, int off = 0)
{
    return !s[off] ? 5381 : (hash_str(s, off + 1) * 33) ^ s[off];
}

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

void Config::LoadFile(const std::string& fileName)
{
    FILE* fp = vsh::fopen(fileName.c_str(), "rb");
    if (!fp)
        return;

    // load the raw file data
    int retval = vsh::fseek(fp, 0, SEEK_END);
    if (retval != 0)
    {
        vsh::fclose(fp);
        return;
    }

    int fileSize = vsh::ftell(fp);
    if (fileSize <= 0)
    {
        vsh::fclose(fp);
        return;
    }

    // allocate and ensure NULL terminated
    char* pData = new char[fileSize + static_cast<size_t>(1)];
    if (!pData)
    {
        vsh::fclose(fp);
        return;
    }

    pData[fileSize] = 0;

    // load data into buffer
    vsh::fseek(fp, 0, SEEK_SET);
    size_t uRead = vsh::fread(pData, sizeof(char), fileSize, fp);
    if (uRead != (size_t)fileSize)
    {
        delete[] pData;
        vsh::fclose(fp);
        return;
    }


    ss_yaml::Yaml doc;
    doc.parse(pData);
    auto _version = doc.root()["version"].str();
    auto _displayMode = doc.root()["overlay"]["displayMode"].str();
    auto _position = doc.root()["overlay"]["position"].str();
    auto _showFPS = doc.root()["overlay"]["showFPS"].boolean();
    auto _showCpuInfo = doc.root()["overlay"]["showCpuInfo"].boolean();
    auto _showGpuInfo = doc.root()["overlay"]["showGpuInfo"].boolean();
    auto _showRamInfo = doc.root()["overlay"]["showRamInfo"].boolean();
    auto _showFanSpeed = doc.root()["overlay"]["showFanSpeed"].boolean();
    auto _showFirmware = doc.root()["overlay"]["showFirmware"].boolean();
    auto _showAppName = doc.root()["overlay"]["showAppName"].boolean();

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


    overlay.showFPS = _showFPS;
    overlay.showCpuInfo = _showCpuInfo;
    overlay.showGpuInfo = _showGpuInfo;
    overlay.showRamInfo = _showRamInfo;
    overlay.showFanSpeed = _showFanSpeed;
    overlay.showFirmware = _showFirmware;
    overlay.showAppName = _showAppName;




    if (pData)
        delete[] pData;
    vsh::fclose(fp);
}