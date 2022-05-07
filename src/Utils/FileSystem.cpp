#include "FileSystem.hpp"


sys_prx_id_t GetModuleHandle(const char* moduleName)
{
    return (moduleName) ? sys_prx_get_module_id_by_name(moduleName, 0, nullptr) : sys_prx_get_my_module_id();
}

sys_prx_module_info_t GetModuleInfo(sys_prx_id_t handle)
{
    sys_prx_module_info_t info{};
    static sys_prx_segment_info_t segments[10]{};
    static char filename[SYS_PRX_MODULE_FILENAME_SIZE]{};

    vsh::memset(segments, 0, sizeof(segments));
    vsh::memset(filename, 0, sizeof(filename));

    info.size = sizeof(info);
    info.segments = segments;
    info.segments_num = sizeof(segments) / sizeof(sys_prx_segment_info_t);
    info.filename = filename;
    info.filename_size = sizeof(filename);

    sys_prx_get_module_info(handle, 0, &info);
    return info;
}

std::string GetModuleFilePath(const char* moduleName)
{
    sys_prx_module_info_t info = GetModuleInfo(GetModuleHandle(moduleName));
    return std::string(info.filename);
}

std::string RemoveBaseNameFromPath(const std::string& filePath)
{
    size_t lastpath = filePath.find_last_of("/");
    if (lastpath == std::string::npos)
        return filePath;
    return filePath.substr(0, lastpath);
}

std::string GetFileName(const std::string& path)
{
    size_t lastslash = path.find_last_of("/");
    if (lastslash == std::string::npos)
        return path;
    return path.substr(lastslash + 1, path.length());
}

std::string GetCurrentDir()
{
    static std::string cachedModulePath;
    if (cachedModulePath.empty())
    {
        std::string path = RemoveBaseNameFromPath(GetModuleFilePath(nullptr));

        path += "/";  // include trailing slash

        cachedModulePath = path;
    }
    return cachedModulePath;
}

bool ReadFile(const std::string& filePath, void* data, size_t size)
{
    int fd;
    if (cellFsOpen(filePath.c_str(), CELL_FS_O_RDONLY, &fd, nullptr, 0) == CELL_FS_SUCCEEDED)
    {
        cellFsLseek(fd, 0, CELL_FS_SEEK_SET, nullptr);
        cellFsRead(fd, data, size, nullptr);
        cellFsClose(fd);

        return true;
    }
    return false;
}

bool WriteFile(const std::string& filePath, void* data, size_t size)
{
    int fd;
    if (cellFsOpen(filePath.c_str(), CELL_FS_O_WRONLY | CELL_FS_O_CREAT | CELL_FS_O_TRUNC, &fd, nullptr, 0) == CELL_FS_SUCCEEDED)
    {
        cellFsLseek(fd, 0, CELL_FS_SEEK_SET, nullptr);
        cellFsWrite(fd, data, size, nullptr);
        cellFsClose(fd);

        return true;
    }
    return false;
}

bool DirectoryExists(const std::string& directoryPath)
{
    CellFsStat stat;
    if (cellFsStat(directoryPath.c_str(), &stat) == CELL_FS_SUCCEEDED)
        return (stat.st_mode & CELL_FS_S_IFDIR);
    return false;
}

bool FileExist(const std::string& filePath)
{
    CellFsStat stat;
    if (cellFsStat(filePath.c_str(), &stat) == CELL_FS_SUCCEEDED)
        return (stat.st_mode & CELL_FS_S_IFREG);
    return false;
}

bool CreateDirectory(const std::string& directoryPath)
{
    if (!DirectoryExists(directoryPath))
    {
        std::string path = directoryPath;
        std::vector<std::string> directoryList;

        while (path != "")
        {
            directoryList.push_back(path);
            path = RemoveBaseNameFromPath(path);
        }

        for (int i = directoryList.size() - 1; i >= 0; i--)
            if (!DirectoryExists(directoryList[i]))
                if (cellFsMkdir(directoryList[i].c_str(), CELL_FS_S_IFDIR | 0777) != CELL_FS_SUCCEEDED)
                    return false;
    }
    return true;
}

bool DeleteFile(const std::string& filePath)
{
    if (FileExist(filePath))
        return (cellFsUnlink(filePath.c_str()) == CELL_FS_SUCCEEDED);
    return true;
}

int64_t GetFileSize(const std::string& filePath)
{
    CellFsStat stat;
    if (cellFsStat(filePath.c_str(), &stat) == CELL_FS_SUCCEEDED)
        return static_cast<int64_t>(stat.st_size);
    return -1;
}