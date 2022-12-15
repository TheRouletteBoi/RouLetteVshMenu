#pragma once
#include "GamePatching.hpp"

namespace CODMW2
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case FindActiveGame::PatchedMenu::MW2Paradox:
         {
            SetNop(0x25CAC18); // stop connect to paradox.sh
            SetNop(0x25CB6C4); // request addresses from server
            SetNop(0x25CB7B8); // thread get admin commands
            SetNop(0x25CBC00); // stop auto update module

            uint32_t auth_data_1[] = { 0xD00179A0, 0x00128D72, 0x01000000, 0x00050000 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x25F0B48, &auth_data_1, sizeof(auth_data_1));

            uint32_t auth_data_2[] = { 0x00915258, 0x0091527C, 0x00915254, 0x009FD590, 0x000A2060 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x26004DC, &auth_data_2, sizeof(auth_data_2));

            uint32_t server_data[] = {
               0x000A1A88, 0x00724C38, 0x00052738, 0x00724C38,
               0x0005EFB0, 0x00724C38, 0x0045B298, 0x00724C38,
               0x004C6CC8, 0x00724C38, 0x00096178, 0x00724C38,
               0x00200E38, 0x00724C38, 0x004C6D28, 0x00724C38,
               0x001E59A0, 0x00724C38, 0x000335D8, 0x00724C38,
               0x00032898, 0x00724C38, 0x00238070, 0x00724C38,
               0x002539F8, 0x00724C38, 0x001D9EC0, 0x00724C38,
               0x0004FE80, 0x00724C38, 0x000A8510, 0x00724C38,
               0x004C7168, 0x00724C38, 0x004C7248, 0x00724C38
            };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x25F07DC, &server_data, sizeof(server_data));
            SetBranch(0x25CAA9C, 0x25CABCC); // skip the bullshit
            SetBranch(0x25CAC1C, 0x25CB6AC); // skip the bullshit
            break;
         }
         case FindActiveGame::PatchedMenu::MW2Reborn:
         {
            // wait because injecting menu too fast can result in a crash
            Sleep(50000);

            const std::string& fileName = GetCurrentDir() + "modmenus/enstone/reborn_by_enstone_446.bin";
            uint64_t pageTable[2]{};
            if (StartPayload(fileName.c_str(), KB(140), 0x7D0, 0x4000, pageTable))
               vsh::ShowNotificationWithIcon(L"Reborn is now loaded", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
            break;
         }
      }
   }
}