#pragma once
#include "GamePatching.hpp"

namespace CODMW3
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case FindActiveGame::PatchedMenu::MW3Paradox:
         {
            SetNop(0x23CBA3C); // stops connecting the server
            SetNop(0x23CCA20); // stops the auto updater
            SetNop(0x23CC4E8); // stops downloading server addresses

            uint32_t auth_data_1[] = { 0xD00189A0, 0x001379A5, 0x01000000, 0x00050000 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x2405438, &auth_data_1, sizeof(auth_data_1));

            uint32_t auth_data_2[] = { 0x007F0ECC, 0x007BD008, 0x007BD010, 0x007BD00C };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x2416934, &auth_data_2, sizeof(auth_data_2));

            uint32_t server_data[] = {
               0x00393640, 0x0072DCE8, 0x004A38B8, 0x0072DCE8,
               0x004A3740, 0x0072DCE8, 0x000C0878, 0x0072DCE8,
               0x0006DE58, 0x0072DCE8, 0x001DB240, 0x0072DCE8,
               0x003937C0, 0x0072DCE8, 0x00068308, 0x0072DCE8,
               0x003930D0, 0x0072DCE8, 0x00211A24, 0x0072DCE8,
               0x001F9D74, 0x0072DCE8, 0x000C568C, 0x0072DCE8,
               0x00291060, 0x0072DCE8, 0x002911A8, 0x0072DCE8,
               0x000C42A8, 0x0072DCE8, 0x0007A5C8, 0x0072DCE8,
               0x003F8DE8, 0x0072DCE8, 0x0003CAD8, 0x0072DCE8,
               0x000BC550, 0x0072DCE8, 0x000402C0, 0x0072DCE8,
               0x004A4B20, 0x0072DCE8, 0x0038B044, 0x0072DCE8,
               0x003808B8, 0x0072DCE8, 0x00392D78, 0x0072DCE8,
               0x004A568C, 0x0072DCE8, 0x0002B620, 0x0072DCE8,
               0x00023890, 0x0072DCE8, 0x000BE498, 0x0072DCE8,
               0x00277158, 0x0072DCE8, 0x000CD63C, 0x0072DCE8
            };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x2400C18, &server_data, sizeof(server_data));
            SetBranch(0x23CB8C0, 0x23CB9F0); // skip the bullshit
            SetBranch(0x23CBA40, 0x23CC4D0); // skip the bullshit
            break;
         }
         case FindActiveGame::PatchedMenu::MW3Phantom:
         {
            // wait because injecting menu too fast can result in a crash
            Sleep(50000);

            const std::string& fileName = GetCurrentDir() + "modmenus/enstone/phantom_by_enstone_221.bin";
            if (StartPayload(fileName.c_str(), KB(484), 0x7D0, 0x4000))
               vsh::ShowNotificationWithIcon(L"Phantom is now loaded", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
            break;
         }
         case FindActiveGame::PatchedMenu::MW3ProjectMemories:
         {
            // wait because injecting menu too fast can result in a crash
            Sleep(50000);

            const std::string& fileName = GetCurrentDir() + "modmenus/enstone/project_memories_by_enstone_388.bin";
            if (StartPayload(fileName.c_str(), KB(112), 0x7D0, 0x4000))
               vsh::ShowNotificationWithIcon(L"Project Memories is now loaded", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
            break;
         }
      }
   }
}