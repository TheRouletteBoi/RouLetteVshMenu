#pragma once
#include "GamePatching.hpp"

namespace CODBO1
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case FindActiveGame::PatchedMenu::BO1Paradox:
         {
            SetMem<uint32_t>(0x28F7CEC, 0x38600001);     // read license key return true
            
            uint32_t license_and_auth_vars[] = { 0xD0025720, 0x000EAAA5, 0x01000000, 0x00050000 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x29109F0, &license_and_auth_vars, sizeof(license_and_auth_vars));
            
            SetNop(0x28F7E6C);                           // stop connection to paradox.sh

            uint32_t address_data[] = { 0x00D223C4, 0x00C3DFB8, 0x00C3DFBC, 0x00C3DFC0 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x291EBDC, &address_data, sizeof(address_data));

            // addresses loaded from server
            uint32_t address_data2[] = {
               0x004C4FF0, 0x00B576E8, 0x00754B48, 0x00B576E8,
               0x00399CC8, 0x00B576E8, 0x007A21E0, 0x00B576E8,
               0x001B74F0, 0x00B576E8, 0x007458D8, 0x00B576E8,
               0x00734350, 0x00B576E8, 0x00751940, 0x00B576E8,
               0x00754410, 0x00B576E8, 0x0055A098, 0x00B576E8,
               0x00559E98, 0x00B576E8, 0x000F4BC8, 0x00B576E8,
               0x000FD7F0, 0x00B576E8, 0x00734570, 0x00B576E8,
               0x005B99C8, 0x00B576E8, 0x003A5650, 0x00B576E8,
               0x001A1C98, 0x00B576E8
            };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x29107B0, &address_data2, sizeof(address_data2));

            SetNop(0x28F8918);                  // request addresses from server
            SetNop(0x28F8A0C);                  // thread get admin commands
            SetNop(0x28F8E54);                  // update module
            SetBranch(0x28F7CF0, 0x28F7E20);    // skip the bullshit
            SetBranch(0x28F7E70, 0x28F8900);    // skip the bullshit
            SetBranch(0x28F8A18, 0x28F8FE4);    // skip the bullshit

            vsh::ShowNotificationWithIcon(L"Paradox has been patched", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
            break;
         }
         case FindActiveGame::PatchedMenu::BO1Fusion:
         {
            // wait because injecting menu too fast can result in a crash
            Sleep(50000);

            const std::string& fileName = GetCurrentDir() + "modmenus/enstone/fusion_by_enstone_114.bin";
            uint64_t pageTable[2]{};
            if (StartPayload(fileName.c_str(), KB(156), 0x7D0, 0x4000, pageTable))
               vsh::ShowNotificationWithIcon(L"Fusion is now loaded", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
            break;
         }
      }
   }
}