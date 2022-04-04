#pragma once
#include "GamePatching.hpp"

namespace CODGhost
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case CFindActiveGame::PatchedMenu::GhostParadox:
         {
            SetNop(0x297B7D0); // stop downloading address from the server
            SetNop(0x297AD24); // stop connection to the server
            SetNop(0x297B8C4); // stop the admin thread
            SetNop(0x297BD0C); // stop the auto update

            uint32_t auth_data_1[] = { 0xD00189A0, 0x0012B344, 0x01000000, 0x000C0000 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x29A0E60, &auth_data_1, sizeof(auth_data_1));

            uint32_t auth_data_2[] = {
               0x0036DA70, 0x00A7F3C8, 0x006D2D08, 0x00A7F3C8,
               0x0046540C, 0x00A7F3C8, 0x00459C6C, 0x00A7F3C8,
               0x00472E78, 0x00A7F3C8, 0x00153680, 0x00A7F3C8,
               0x004731B8, 0x00A7F3C8, 0x005BB454, 0x00A7F3C8,
               0x002BB688, 0x00A7F3C8, 0x002D9394, 0x00A7F3C8,
               0x002D894C, 0x00A7F3C8, 0x002B1C14, 0x00A7F3C8,
               0x002E2374, 0x00A7F3C8, 0x00473658, 0x00A7F3C8,
               0x00787434, 0x00A7F3C8, 0x007872BC, 0x00A7F3C8,
               0x0056B1D4, 0x00A7F3C8, 0x002B32C8, 0x00A7F3C8,
               0x0056ABCC, 0x00A7F3C8, 0x006D9638, 0x00A7F3C8,
               0x00121550, 0x00A7F3C8, 0x007EFB84, 0x00A7F3C8,
               0x0014C018, 0x00A7F3C8
            };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x29A07D0, &auth_data_2, sizeof(auth_data_2));
            SetBranch(0x297ABA8, 0x297ACD8); // skip the bullshit
            SetBranch(0x297AD28, 0x297B7B8); // skip the bullshit
            break;
         }
         case CFindActiveGame::PatchedMenu::GhostEternity:
         {
            // wait because injecting menu too fast can result in a crash
            Sleep(50000);

            const std::string& fileName = GetCurrentDir() + "modmenus/enstone/eternity_by_enstone_105.bin";
            if (StartPayload(fileName.c_str(), KB(300), 0x7D0, 0x4000))
               vsh::ShowNofityWithSound(L"Eternity is now loaded", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
         }
      }
   }
}