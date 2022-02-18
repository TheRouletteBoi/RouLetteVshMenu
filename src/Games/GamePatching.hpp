#pragma once
#include "FindActiveGame.hpp"
#include "Memory/Memory.hpp"

namespace GamePatching
{
   bool StartSprx(const char* path)
   {
      vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
      if (!gamePlugin)
         return false;

      return (ps3mapi_load_process_modules(g_FindActiveGame.GetRunningGameProcessId(), (char*)path, nullptr, 0) == SUCCEEDED);
   }

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
      // li r3, 1
      // blr
      SetMem<uint64_t>(address, 0x386000004E800020);
   }

   uint32_t GetFirstUserModuleBaseAddress()
   {
      // MW3 0x23D0000
      // GTAV 0x24D0000
      return 0x24D0000;
   }

   uint32_t Ida2Mem(uint32_t address)
   {
      return (GetFirstUserModuleBaseAddress() + address);
   }
}