#pragma once
#include "GamePatching.hpp"

namespace CODBO3
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case CFindActiveGame::PatchedMenu::BO3Fatality:
         {
            if (StartPayload("/dev_hdd0/plugins/RouLetteVshMenu/modmenus/enstone/fatality_by_enstone_102_patched.bin", KB(444), 0x7D0, 0x4000))
               vsh::ShowNofityWithSound(L"Fatality is now loaded", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
         }
      }
   }
}