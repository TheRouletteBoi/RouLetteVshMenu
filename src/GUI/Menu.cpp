
#include "Menu.hpp"

void MainSubmenu()
{
   g_Menu.title(L"Main menu");
   g_Menu.option(L"GTAV Menus").submenu(GtavSubmenu);
   g_Menu.option(L"Black Ops 1 Menus");
   g_Menu.option(L"Black Ops 2 Menus");
   g_Menu.option(L"Black Ops 3 Menus");
   g_Menu.option(L"Modern Warfare 2 Menus");
   g_Menu.option(L"Modern Warfare 3 Menus");
   g_Menu.option(L"Ghosts Menus");
   g_Menu.option(L"Advance Warfare Menus");
   g_Menu.option(L"Take screenshot").action([] { g_Helpers.TakeScreenshot(); });
}

void GtavSubmenu()
{
   g_Menu.title(L"GTAV Menus");
   g_Menu.option(L"Menu 1");
   g_Menu.option(L"Menu 2");
   g_Menu.option(L"Menu 3");
   g_Menu.option(L"Menu 4");
   g_Menu.option(L"Menu 5");
}