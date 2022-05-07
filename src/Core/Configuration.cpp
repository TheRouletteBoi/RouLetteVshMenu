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

void Config::LoadFile(const std::string& fileName)
{
    vsh::printf("ReadYamlFile\n");
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












    vsh::printf("Start to parse yaml file\n\n\n");
    vsh::printf("%s\n\n\n", pData);

    ss_yaml::Yaml doc;
    doc.parse(pData);
    vsh::printf("done reading yaml file\n");

    auto s = doc.root()["version"].str();
    vsh::printf("version %s\n", s.c_str());

    auto _displayMode = doc.root()["overlay"]["displayMode"].str();
    vsh::printf("_displayMode %s\n", _displayMode.c_str());





    overlay.displayMode = 0;
    overlay.positionMode = 0;
    overlay.showFPS = true;
    overlay.showCpuInfo = true;
    overlay.showGpuInfo = true;
    overlay.showRAM = false;
    overlay.showFanSpeed = true;
    overlay.showFirmware = true;
    overlay.showAppName = true;










    if (pData)
        delete[] pData;
    vsh::fclose(fp);
}