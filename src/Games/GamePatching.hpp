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
      var value = 0;
      int ret = ReadProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)address, &value, sizeof(var));
      if (ret != SUCCEEDED)
         return 0;

      return value;
   }

   template <typename var>
   bool SetMem(uint32_t address, var value)
   {
      return (WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)address, &value, sizeof(var)) == SUCCEEDED);
   }

   void SetBreakPoint(uint32_t address)
   {
      SetMem<uint32_t>(address, 0x7FE00008); // tw 31, r0, r0
   }

   void SetNop(uint32_t address)
   {
      SetMem<uint32_t>(address, 0x60000000); // nop
   }

   void SetBlr(uint32_t address)
   {
      SetMem<uint32_t>(address, 0x4E800020); // blr
   }

   void SetBranch(uint32_t from, uint32_t to)
   {
      uint32_t branch = (0x48000000 + ((to - (uint32_t)from) & 0x3FFFFFF));
      SetMem<uint32_t>(from, branch);
   }

   void SetBranchless(uint32_t address)
   {
      uint32_t orginal = GetMem<uint32_t>(address);
      uint32_t branch = 0x48000000;
      uint32_t bit = 0xFF00FFFF;
      branch |= orginal;
      branch &= bit;

      SetMem<uint32_t>(address, branch);
   }

   void SetReturnTrue(uint32_t address)
   {
      // li r3, 1
      // blr
      SetMem<uint64_t>(address, 0x386000014E800020);
   }

   void SetReturnFalse(uint32_t address)
   {
      // li r3, 0
      // blr
      SetMem<uint64_t>(address, 0x386000004E800020);
   }

   sys_prx_id_t GetProcessModuleIdByName(sys_pid_t pid, const char* moduleName)
   {
      constexpr int MAX_MODULES = 128;
      sys_prx_id_t moduleList[MAX_MODULES]{};
      vsh::memset(moduleList, 0, sizeof(moduleList));
      ps3mapi_get_all_process_modules_prx_id(pid, moduleList);

      sys_prx_module_info_t moduleInfo{};
      sys_prx_segment_info_t segments[10]{};
      char filename[SYS_PRX_MODULE_FILENAME_SIZE]{};
      moduleInfo.size = sizeof(moduleInfo);
      moduleInfo.segments = segments;
      moduleInfo.segments_num = sizeof(segments) / sizeof(sys_prx_segment_info_t);
      moduleInfo.filename = filename;
      moduleInfo.filename_size = sizeof(filename);

      for (int i = 0; i < MAX_MODULES; i++)
      {
         if (moduleList[i] != 0)
         {
            vsh::memset(moduleInfo.segments, 0, sizeof(moduleInfo.segments));
            vsh::memset(moduleInfo.filename, 0, sizeof(moduleInfo.filename));

            ps3mapi_get_process_module_segments(pid, moduleList[i], &moduleInfo);

            if (vsh::strcmp(moduleInfo.name, moduleName) == 0)
            {
               return moduleList[i];
            }
         }
      }

      return 0;
   }

   sys_prx_module_info_t GetProcessModuleInfoByName(sys_pid_t pid, const char* moduleName)
   {
      constexpr int MAX_MODULES = 128;
      sys_prx_id_t moduleList[MAX_MODULES]{};
      vsh::memset(moduleList, 0, sizeof(moduleList));
      ps3mapi_get_all_process_modules_prx_id(pid, moduleList);

      sys_prx_module_info_t moduleInfo{};
      sys_prx_segment_info_t segments[10]{};
      char filename[SYS_PRX_MODULE_FILENAME_SIZE]{};
      moduleInfo.size = sizeof(moduleInfo);
      moduleInfo.segments = segments;
      moduleInfo.segments_num = sizeof(segments) / sizeof(sys_prx_segment_info_t);
      moduleInfo.filename = filename;
      moduleInfo.filename_size = sizeof(filename);

      for (int i = 0; i < MAX_MODULES; i++)
      {
         if (moduleList[i] != 0)
         {
            vsh::memset(moduleInfo.segments, 0, sizeof(moduleInfo.segments));
            vsh::memset(moduleInfo.filename, 0, sizeof(moduleInfo.filename));

            ps3mapi_get_process_module_segments(pid, moduleList[i], &moduleInfo);

            if (vsh::strcmp(moduleInfo.name, moduleName) == 0)
            {
               return moduleInfo;
            }
         }
      }

      return {};
   }

   sys_prx_module_info_t GetProcessModuleInfoByPrxId(sys_pid_t pid, sys_prx_id_t prxId)
   {
      sys_prx_module_info_t info{};
      sys_prx_segment_info_t segments[10]{};
      char filename[SYS_PRX_MODULE_FILENAME_SIZE]{};
      info.size = sizeof(info);
      info.segments = segments;
      info.segments_num = sizeof(segments) / sizeof(sys_prx_segment_info_t);
      info.filename = filename;
      info.filename_size = sizeof(filename);
      ps3mapi_get_process_module_segments(pid, prxId, &info);
      return info;
   }

   bool IsModuleLoaded(const char* moduleName)
   {
       constexpr int MAX_MODULES = 128;
       sys_prx_id_t moduleList[MAX_MODULES]{};
       vsh::memset(moduleList, 0, sizeof(moduleList));
       ps3mapi_get_all_process_modules_prx_id(g_FindActiveGame.GetRunningGameProcessId(), moduleList);

       sys_prx_module_info_t moduleInfo{};
       sys_prx_segment_info_t segments[10]{};
       char filename[SYS_PRX_MODULE_FILENAME_SIZE]{};
       moduleInfo.size = sizeof(moduleInfo);
       moduleInfo.segments = segments;
       moduleInfo.segments_num = sizeof(segments) / sizeof(sys_prx_segment_info_t);
       moduleInfo.filename = filename;
       moduleInfo.filename_size = sizeof(filename);

       for (int i = 0; i < MAX_MODULES; i++)
       {
           if (moduleList[i] != 0)
           {
               vsh::memset(moduleInfo.segments, 0, sizeof(moduleInfo.segments));
               vsh::memset(moduleInfo.filename, 0, sizeof(moduleInfo.filename));

               ps3mapi_get_process_module_segments(g_FindActiveGame.GetRunningGameProcessId(), moduleList[i], &moduleInfo);

               if (vsh::strcmp(moduleInfo.name, moduleName) == 0)
               {
                   return true;
               }
           }
       }

       return false;
   }

   uint32_t GetModuleBaseAddress(const char* moduleName)
   {
      sys_prx_module_info_t info = GetProcessModuleInfoByName(g_FindActiveGame.GetRunningGameProcessId(), moduleName);
      return info.segments[(int)eSegmentType::Text].base;
   }

   uint32_t Ida2Mem(const char* moduleName, uint32_t address)
   {
      return (GetModuleBaseAddress(moduleName) + address);
   }

   bool StartSprx(const char* path)
   {
      // check that we are in game
      paf::View* gamePlugin = paf::View::Find("game_plugin");
      if (!gamePlugin)
         return false;

      return (ps3mapi_load_process_modules(g_FindActiveGame.GetRunningGameProcessId(), (char*)path, nullptr, 0) == SUCCEEDED);
   }

   int WritePayload(uintptr_t startAddr, const char* fileName)
   {
      constexpr int BYTES_PER_WRITE = 0x6000;
      int next_write = 0;

      int fd = 0; uint64_t read_amount = 1;

      if (cellFsOpen(fileName, CELL_FS_O_RDONLY, &fd, NULL, 0) == CELL_FS_SUCCEEDED)
      {
         while (read_amount)
         {
            char* data = (char*)vsh::malloc(BYTES_PER_WRITE);
            if (cellFsRead(fd, (void*)(data), BYTES_PER_WRITE, &read_amount) == CELL_FS_SUCCEEDED)
            {
               WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)(startAddr + next_write), data, (size_t)read_amount);
               next_write += read_amount;
               if (data)
                  vsh::free(data);
            }
         }

         cellFsClose(fd);
      }
      else
      {
         return ENOENT;
      }

      return SUCCEEDED;
   }

   bool StartPayload(const char* fileName, uint32_t fileSize, int prio, size_t stacksize)
   {
      vsh::printf("Starting to inject payload %s\n", fileName);
      uint64_t executableMemoryAddress = 0;
      int ret = ps3mapi_process_page_allocate(g_FindActiveGame.GetRunningGameProcessId(), fileSize, 0x100, 0x2F, 0x1, &executableMemoryAddress);
      vsh::printf("executableMemoryAddress 0x%X\n", executableMemoryAddress);
      if (ret != SUCCEEDED)
      {
         vsh::printf("Failed to allocate executable memory 0x%X\n", ret);
         vsh::ShowNotificationWithIcon(L"Failed to allocate executable memory", vsh::NotifyIcon::Pen, vsh::NotifySound::Error);
         return false;
      }

      Sleep(1000);

      uint32_t temp_bytes = 0;
      ret = ReadProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)(uintptr_t)executableMemoryAddress, (void*)&temp_bytes, 4);
      if (ret != SUCCEEDED)
      {
         vsh::printf("Failed to read executable memory 0x%X\n", ret);
         vsh::ShowNotificationWithIcon(L"Failed to read executable memory", vsh::NotifyIcon::Pen, vsh::NotifySound::Error);
         return false;
      }

      Sleep(1000);

      ret = WritePayload((uintptr_t)executableMemoryAddress, fileName);
      if (ret != SUCCEEDED)
      {
         vsh::printf("Failed to read payload file %s 0x%X\n", fileName, ret);
         vsh::ShowNotificationWithIcon(L"Failed to read payload file", vsh::NotifyIcon::Pen, vsh::NotifySound::Error);
         return false;
      }

      Sleep(1000);

      uint32_t threadOpd[2]{};
      threadOpd[0] = executableMemoryAddress;
      threadOpd[1] = 0x00000000;
      thread_t th;
      ret = ps3mapi_create_process_thread(g_FindActiveGame.GetRunningGameProcessId(), &th, threadOpd, 0, prio, stacksize, "PayloadThread");
      if (ret != SUCCEEDED)
      {
         vsh::printf("Failed to start payload 0x%X\n", ret);
         vsh::ShowNotificationWithIcon(L"Failed to start payload", vsh::NotifyIcon::Pen, vsh::NotifySound::Error);
         return false;
      }

      vsh::printf("Successfully started payload\n");
      return true;
   }
}