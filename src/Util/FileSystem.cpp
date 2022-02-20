#include "FileSystem.hpp"


sys_prx_id_t GetModuleHandle(const char* moduleName)
{
   sys_prx_id_t id = 0;
   if (moduleName == nullptr)
      id = sys_prx_get_my_module_id();
   else
      id = sys_prx_get_module_id_by_name(moduleName, NULL, NULL);
   return id;
}

sys_prx_module_info_t GetModuleInfo(sys_prx_id_t prxId)
{
   sys_prx_module_info_t info{};
   sys_prx_segment_info_t segments[10]{};
   char filename[SYS_PRX_MODULE_FILENAME_SIZE]{};
   info.size = sizeof(info);
   info.segments = segments;
   info.segments_num = sizeof(segments) / sizeof(sys_prx_segment_info_t);
   info.filename = filename;
   info.filename_size = sizeof(filename);
   sys_prx_get_module_info(prxId, NULL, &info);
   return info;
}

std::string GetModuleFileName(const char* moduleName)
{
   sys_prx_module_info_t info = GetModuleInfo(GetModuleHandle(moduleName));
   return std::string(info.filename);
}

std::string RemoveBaseNameFromPath(const std::string& fileName)
{
   size_t lastpath = fileName.find_last_of("/");
   if (lastpath == std::string::npos) 
      return fileName;
   return fileName.substr(0, lastpath);
}

std::string GetCurrentDir()
{
   static std::string cachedModulePath;
   if (cachedModulePath.empty())
   {
      // GetModuleFileName(nullptr) returns  "/dev_hdd0/tmp/Semjases/SemjasesLauncher.sprx"
      std::string path = RemoveBaseNameFromPath(GetModuleFileName(nullptr));

      path += "/";  // include trailing slash

      cachedModulePath = path;
   }
   return cachedModulePath;
}