#pragma once
#include "GamePatching.hpp"

namespace CODAW
{
   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case CFindActiveGame::PatchedMenu::AWParadox:
         {
            SetMem<uint32_t>(0x32CABA4, 0x38600001);  // read license key return true
            uint32_t license_and_auth_vars[] = { 0xD00279A0, 0x0012B344, 0x01000000, 0x00050000 };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x32F0AA0, &license_and_auth_vars, sizeof(license_and_auth_vars));

            SetNop(0x32CAD24);                        // stop connection to paradox.sh

            // addresses loaded from server
            uint32_t address_data[] = {
               0x0000000B, 0x003D9920, 0x009D5530, 0x001BBD50, 0x009D5530, 0x004EB158,
               0x009D5530, 0x00244BB0, 0x009D5530, 0x005EEC20, 0x009D5530, 0x005FB288,
               0x009D5530, 0x005FAD38, 0x009D5530, 0x005FAFD0, 0x009D5530, 0x00010D90,
               0x009D5530, 0x003FF4A0, 0x009D5530, 0x0022B810, 0x009D5530, 0x006E2768,
               0x009D5530, 0x006E25F0, 0x009D5530, 0x00232658, 0x009D5530, 0x003AF41C,
               0x009D5530, 0x00227318, 0x009D5530, 0x00187830, 0x009D5530, 0x001B2CB0,
               0x009D5530
            };
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x32F07B4, &address_data, sizeof(address_data));

            SetNop(0x32CB7D0);                        // request addresses from server maybe
            SetNop(0x32CB8C4);                        // thread get admin commands
            SetNop(0x32CBD0C);                        // update module
            SetBranch(0x32CABB0, 0x32CACD8);          // skip the bullshit
            SetBranch(0x32CAD28, 0x32CB7B8);          // skip the bullshit
            SetBranch(0x32CB8D0, 0x32CBE9C);          // skip the bullshit

            vsh::ShowNofityWithSound(L"Paradox has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
         }
         case CFindActiveGame::PatchedMenu::AWFury:
         {
            if (StartPayload("/dev_hdd0/plugins/RouLetteVshMenu/modmenus/enstone/fury_by_enstone_220_patched.bin", KB(496), 0x7D0, 0x4000))
               vsh::ShowNofityWithSound(L"Fury is now loaded", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
            break;
         }
      }
   }
}