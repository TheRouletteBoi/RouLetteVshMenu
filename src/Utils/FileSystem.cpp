#include "FileSystem.hpp"
#include <vsh/stdc.hpp>
#include <vsh/allocator.hpp>


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

void GetFilesInDirectory(const char* dir, std::vector<std::string>& files)
{
    int fd;
    CellFsErrno err = cellFsOpendir(dir, &fd);
    if (err != CELL_FS_SUCCEEDED)
    {
        cellFsClosedir(fd);
        return;
    }

    uint64_t read;
    CellFsDirent ent;
    read = sizeof(CellFsDirent);
    while (!cellFsReaddir(fd, &ent, &read))
    {
        if (!read)
            break;

        files.push_back(ent.d_name);
    }

    cellFsClosedir(fd);
}

void GetFilesInDirectory(const char* dir, std::vector<std::string>& files, const char* extensionToRead)
{
    int fd;
    CellFsErrno err = cellFsOpendir(dir, &fd);
    if (err != CELL_FS_SUCCEEDED)
    {
        cellFsClosedir(fd);
        return;
    }

    uint64_t read;
    CellFsDirent ent;
    read = sizeof(CellFsDirent);
    while (!cellFsReaddir(fd, &ent, &read))
    {
        if (!read)
            break;

        if (strstr(ent.d_name, extensionToRead) != NULL)
            files.push_back(ent.d_name);
    }

    cellFsClosedir(fd);
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

/***
 * read a file from the disk into a buffer.
 * NOTE: this will allocate memory that needs to be free()d
 * @param fileName the file to open
 * @param buf where to put the file contents
 * @param bytesRead will be set to the number of bytes read
 * @returns 0 on success, -1 on failure
 */
bool ReadFile(const std::string& fileName, char** buf, size_t& bytesRead)
{
    struct stat st;
    if (vsh::stat(fileName.c_str(), &st) != 0)
        return false;

    std::FILE* file = vsh::fopen(fileName.c_str(), "rb");
    if (ferror(file) != 0)
        return false;

    // allocate memory
    *buf = (char*)vsh::malloc((size_t)st.st_size);
    if (buf == NULL)
        return false;

    // read file
    bytesRead = vsh::fread(*buf, 1, (size_t)st.st_size, file);
    if (vsh::feof(file) == 0 && vsh::ferror(file) != 0) // not at end of file, and we had an error
    {
        vsh::free(*buf);
        vsh::fclose(file);
        return false;
    }

    vsh::fclose(file);
    return true;
}

void SaveFile(const std::string& fileName, const void* data, size_t size)
{
    int flags = CELL_FS_O_CREAT | CELL_FS_O_TRUNC | CELL_FS_O_WRONLY;

    cellFsChmod(fileName.c_str(), 0777); // set permissions for overwrite

    int fileHandle;
    if (cellFsOpen(fileName.c_str(), flags, &fileHandle, NULL, 0) != CELL_FS_SUCCEEDED)
        return;

    uint64_t read_size = 0;
    if (cellFsWrite(fileHandle, data, size, &read_size) != CELL_FS_SUCCEEDED)
    {
        cellFsClose(fileHandle);
        return;
    }

    cellFsClose(fileHandle);

    cellFsChmod(fileName.c_str(), 0777); // set permissions if created
}