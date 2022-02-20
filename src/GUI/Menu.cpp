
#include "Menu.hpp"

void MainSubmenu()
{
   g_Menu.title(L"Main menu");
   g_Menu.option(L"GTAV Menus \uF477\uF477").submenu(GtavSubmenu);
   g_Menu.option(L"Black Ops 1 Menus").submenu(CodBo1Submenu);
   g_Menu.option(L"Black Ops 2 Menus \uF476").submenu(CodBo2Submenu);
   g_Menu.option(L"Black Ops 3 Menus").submenu(CodBo3Submenu);
   g_Menu.option(L"Modern Warfare 2 Menus \uF5BC").submenu(CodMw2Submenu);
   g_Menu.option(L"Modern Warfare 3 Menus \uF46E").submenu(CodMw3Submenu);
   g_Menu.option(L"COD Ghost Menus").submenu(CodGhostSubmenu);
   g_Menu.option(L"Advance Warfare Menus").submenu(CodAwSubmenu);
   g_Menu.option(L"Debug Toggles").submenu(DebugTogglesSubmenu);
}

void GtavSubmenu()
{
   g_Menu.title(L"GTAV Menus");
   g_Menu.option(L"Lexicon         \uF888 + \uF88B").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVLexicon))
         vsh::ShowNofityWithSound(L"Lexicon GTAV is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Serendipity    \uF882 + \uF887").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVSerendipity))
         vsh::ShowNofityWithSound(L"Serendipity GTAV is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);

   });

   g_Menu.option(L"Terrorizer      \uF888 + \uF886").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVTerrorizer))
         vsh::ShowNofityWithSound(L"Terrorizer GTAV is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);

   });
}

void CodBo1Submenu()
{
   g_Menu.title(L"Black Ops 1 Menus");
   g_Menu.option(L"Paradox         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO1Paradox))
         vsh::ShowNofityWithSound(L"Paradox BO1 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Fusion           \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO1Fusion))
         vsh::ShowNofityWithSound(L"Fusion BO1 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

}

void CodBo2Submenu()
{
   g_Menu.title(L"Black Ops 2 Menus");
   g_Menu.option(L"Paradox         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO2Paradox))
         vsh::ShowNofityWithSound(L"Paradox BO2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"SPRX.IO         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO2Sprxio))
         vsh::ShowNofityWithSound(L"SPRX.IO BO2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Destiny          \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO2Destiny))
         vsh::ShowNofityWithSound(L"Destiny BO2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });
}

void CodBo3Submenu()
{
   g_Menu.title(L"Black Ops 3 Menus");
   g_Menu.option(L"Fatality         \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO3Fatality))
         vsh::ShowNofityWithSound(L"Fatality BO3 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });
}

void CodMw2Submenu()
{
   g_Menu.title(L"Modern Warfare 2 Menus");
   g_Menu.option(L"Paradox         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW2Paradox))
         vsh::ShowNofityWithSound(L"Paradox MW2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Reborn          \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW2Reborn))
         vsh::ShowNofityWithSound(L"Reborn MW2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });
}

void CodMw3Submenu()
{
   g_Menu.title(L"Modern Warfare 3 Menus");
   g_Menu.option(L"Paradox         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW3Paradox))
         vsh::ShowNofityWithSound(L"Paradox MW3 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Phantom        \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW3Phantom))
         vsh::ShowNofityWithSound(L"Phantom MW3 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Project Memories     \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW3ProjectMemories))
         vsh::ShowNofityWithSound(L"Project Memories MW3 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

}

void CodGhostSubmenu()
{
   g_Menu.title(L"Cod Ghost Menus");
   g_Menu.option(L"Paradox         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GhostParadox))
         vsh::ShowNofityWithSound(L"Paradox Ghost is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Eternity         \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GhostEternity))
         vsh::ShowNofityWithSound(L"Eternity COD Ghost is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });
}

void CodAwSubmenu()
{
   g_Menu.title(L"Advance Warfare Menus");
   g_Menu.option(L"Paradox         \uF88D + \uF884").action([]
   {
      if (!IsConsoleDex())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::AWParadox))
         vsh::ShowNofityWithSound(L"Paradox Advance Warfare is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });

   g_Menu.option(L"Fury              \uF888 + \uF88D").action([]
   {
      if (ps3mapi_get_is_hen())
      {
         vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
         return;
      }

      if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::AWFury))
            vsh::ShowNofityWithSound(L"Fury Advance Warfare is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
   });
}

void DebugTogglesSubmenu()
{
   g_Menu.title(L"Debug Toggles");
   g_Menu.option(L"Option 1");
   g_Menu.option(L"Option 2");
   g_Menu.option(L"Option 3").toggle(g_Helpers.testToggle1);
   g_Menu.option(L"Option 4");
   g_Menu.option(L"Option 5");
   g_Menu.option(L"Option 6");
   g_Menu.option(L"Option 7");
   g_Menu.option(L"Option 8");
   g_Menu.option(L"Option 9");
   g_Menu.option(L"Option 10").rightText(L"ON\uF8B4 OFF\uF8B5");
   g_Menu.option(L"Option 11");
   g_Menu.option(L"Option 12");
   g_Menu.option(L"Option 13");
   g_Menu.option(L"Option 14");
   g_Menu.option(L"Option 15").toggle(g_Helpers.testToggle2);
   g_Menu.option(L"Option 16");
   g_Menu.option(L"Option 17");
   g_Menu.option(L"Option 18");
   g_Menu.option(L"Option 19");
   g_Menu.option(L"Option 20");
}