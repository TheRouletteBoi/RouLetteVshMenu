#pragma once
#include "GamePatching.hpp"

namespace GTAV
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
      case CFindActiveGame::PatchedMenu::Terrorizer:
         vsh::printf("loading terrorizer menu\n");
         SetNop(Ida2Mem(0x4FD58)); // nop auther thread
         SetNop(Ida2Mem(0x48B40)); // bypass check in PatchInJump
         SetMem<uint32_t>(Ida2Mem(0x48D74), 0x2C030001); // set some check to true
         SetMem<uint32_t>(Ida2Mem(0x48E48), 0x38600001); // set check to true
         SetBranchless(Ida2Mem(0x48BF4)); // branch where he sets up all the hooks
         vsh::ShowNofityWithSound(L"Terrorizer has been patched", vsh::eNotifyIcon::Mediaserver, vsh::eNotifySound::Trophy);
         break;
      }
   }
}