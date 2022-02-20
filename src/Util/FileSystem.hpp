#pragma once
#include <string>
#include <sys/prx.h>

sys_prx_id_t GetModuleHandle(const char* moduleName);
sys_prx_module_info_t GetModuleInfo(sys_prx_id_t prxId);
std::string GetModuleFileName(const char* moduleName);
std::string RemoveBaseNameFromPath(const std::string& fileName);
std::string GetCurrentDir();