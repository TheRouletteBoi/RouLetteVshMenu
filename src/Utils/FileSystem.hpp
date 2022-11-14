#pragma once
#include <string>
#include <sys/prx.h>
#include <cell/cell_fs.h>
#undef vector
#include <vector>
#include <vshlib.hpp>

sys_prx_id_t GetModuleHandle(const char* moduleName);
sys_prx_module_info_t GetModuleInfo(sys_prx_id_t handle);
std::string GetModuleFilePath(const char* moduleName);
std::string RemoveBaseNameFromPath(const std::string& filePath);
std::string GetFileName(const std::string& path);
std::string GetCurrentDir();

bool DirectoryExists(const std::string& directoryPath);
bool FileExist(const std::string& filePath);
bool CreateDirectory(const std::string& directoryPath);
void GetFilesInDirectory(const char* dir, std::vector<std::string>& files);
void GetFilesInDirectory(const char* dir, std::vector<std::string>& files, const char* extensionToRead);
bool DeleteFile(const std::string& filePath);
int64_t GetFileSize(const std::string& filePath);
bool ReadFile(const std::string& fileName, char** buf, size_t& bytesRead);
void SaveFile(const std::string& fileName, const void* data, size_t size);