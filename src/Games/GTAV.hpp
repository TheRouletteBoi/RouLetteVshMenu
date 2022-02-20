#pragma once
#include "GamePatching.hpp"

namespace GTAV
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case CFindActiveGame::PatchedMenu::GTAVLexicon:
            SetBranch(Ida2Mem(0x57BC0), Ida2Mem(0x57C5C));  // so you can load the menu offline
            SetNop(Ida2Mem(0x561E8));                       // nop read license key
            SetBranch(Ida2Mem(0x56200), Ida2Mem(0x57AE8));  // skip to hooking
            SetNop(Ida2Mem(0x57B28));                       // nop address decrypter
            SetNop(Ida2Mem(0x57B3C));                       // nop thread for server settings
            SetNop(Ida2Mem(0x57B40));                       // nop thread for server settings 2
            SetMem<uint32_t>(0x1C2BB80, 0x2520878);         // hook is player online
            //SetMem<uint32_t>(0x1C271E0, 0x2520878);       // hook GET_INDEX_OF_CURRENT_LEVEL  an old hook he used in his previous versions of lexicon
            SetMem<uint32_t>(0x1C2A3D0, 0x2520DEC);         // hook disable control actions
            SetMem<uint32_t>(0x1C2E9F8, 0x2520EFC);         // hook set ped current weapon
            vsh::ShowNofityWithSound(L"Lexicon has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
         case CFindActiveGame::PatchedMenu::GTAVSerendipity:
         {
            SetNop(0x24D4194);                        // read key | 0x24D3968
            SetNop(0x24D41D0);                        // first auth request
            SetNop(0x24D42B0);                        // seconds auth request
            SetMem<uint32_t>(0x2530064, 0x3E3A20);    // Main Hook Address 
            SetMem<uint32_t>(0x2531B40, 0x3F30A3D7);  // Text Position X
            SetMem<uint32_t>(0x2531B44, 0x3F4CCCCD);  // Text Position Y

            uint32_t menu_rgba[] = {
               0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF,
               0x000000FF, 0x000000FF, 0x0000000F, 0x0000000F, 0x0000000F, 0x00000078,
               0x000000FF, 0x0000007D, 0x00000000, 0x000000AF, 0x000000FF, 0x0000007D,
               0x00000000, 0x000000AF, 0x000000FF, 0x0000007D, 0x00000000, 0x000000AF
            };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x2531C10, &menu_rgba, sizeof(menu_rgba));

            vsh::ShowNofityWithSound(L"Serendipity has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
         }
         case CFindActiveGame::PatchedMenu::GTAVTerrorizer:
            SetNop(Ida2Mem(0x4FD58));                       // nop auther thread
            SetNop(Ida2Mem(0x48B40));                       // bypass check in PatchInJump
            SetMem<uint32_t>(Ida2Mem(0x48D74), 0x2C030001); // set some check to true
            SetMem<uint32_t>(Ida2Mem(0x48E48), 0x38600001); // set check to true
            SetBranchless(Ida2Mem(0x48BF4));                // branch where he sets up all the hooks
            vsh::ShowNofityWithSound(L"Terrorizer has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
      }
   }
}