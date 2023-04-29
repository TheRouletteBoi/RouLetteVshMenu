#pragma once
#include <vsh/allocator.hpp>
#include "FindActiveGame.hpp"
#include "Memory/Memory.hpp"
#include "Utils/Timers.hpp"
#include "Utils/FileSystem.hpp"

#define KB(n) (1024*n)

namespace GamePatching
{
   enum class eSegmentType
   {
      Text = 0,   // text
      Data,       // data/bss
      RoData,     // rodata
      RoData2,    // rodata 2
   };

   template <typename var>
   var GetMem(uint32_t address)
   {
      var value{};
      int ret = ReadProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)address, &value, sizeof(var));
      if (ret != SUCCEEDED)
         return {};

      return value;
   }

   template <typename var>
   bool SetMem(uint32_t address, var value)
   {
      return (WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)address, &value, sizeof(var)) == SUCCEEDED);
   }

   void SetBreakPoint(uint32_t address);
   void SetNop(uint32_t address);
   void SetBlr(uint32_t address);
   void SetBranch(uint32_t from, uint32_t to);
   void SetBranchless(uint32_t address);
   void SetReturnTrue(uint32_t address);
   void SetReturnFalse(uint32_t address);

   sys_prx_id_t GetProcessModuleIdByName(sys_pid_t pid, const char* moduleName);
   sys_prx_id_t GetProcessModuleIdByFilePath(sys_pid_t pid, const char* filePath);
   sys_prx_module_info_t GetProcessModuleInfoByName(sys_pid_t pid, const char* moduleName);
   sys_prx_module_info_t GetProcessModuleInfoByPrxId(sys_pid_t pid, sys_prx_id_t prxId);

   bool IsModuleLoaded(const char* moduleName);
   uint32_t GetModuleBaseAddress(const char* moduleName);
   uint32_t Ida2Mem(const char* moduleName, uint32_t address);

   bool StartSprx(const char* path);
   int WritePayload(uintptr_t startAddr, const char* fileName);
   bool StartPayload(const char* fileName, uint64_t fileSizeOnDisk, int prio, size_t stacksize, uint64_t outPageTable[2]);
}