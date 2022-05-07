#pragma once
#include <string>
#include <sys/prx.h>
#include <cell/cell_fs.h>
#undef vector
#include <vector>
#include <vsh/stdc.h>

sys_prx_id_t GetModuleHandle(const char* moduleName);
sys_prx_module_info_t GetModuleInfo(sys_prx_id_t handle);
std::string GetModuleFilePath(const char* moduleName);
std::string RemoveBaseNameFromPath(const std::string& filePath);
std::string GetFileName(const std::string& path);
std::string GetCurrentDir();

bool ReadFile(const std::string& filePath, void* data, size_t size);
bool WriteFile(const std::string& filePath, void* data, size_t size);
bool DirectoryExists(const std::string& directoryPath);
bool FileExist(const std::string& filePath);
bool CreateDirectory(const std::string& directoryPath);
bool DeleteFile(const std::string& filePath);
int64_t GetFileSize(const std::string& filePath);