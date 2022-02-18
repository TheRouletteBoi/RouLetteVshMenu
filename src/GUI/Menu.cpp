
#include "Menu.hpp"

void MainSubmenu()
{
   g_Menu.title(L"Main menu");
   g_Menu.option(L"GTAV Menus \uF477\uF477").submenu(GtavSubmenu);
   g_Menu.option(L"Black Ops 1 Menus");
   g_Menu.option(L"Black Ops 2 Menus \uF476");
   g_Menu.option(L"Black Ops 3 Menus");
   g_Menu.option(L"Modern Warfare 2 Menus \uF5BC");
   g_Menu.option(L"Modern Warfare 3 Menus \uF46E");
   g_Menu.option(L"Ghosts Menus");
   g_Menu.option(L"Advance Warfare Menus");
}

bool testToggle1 = false;
bool testToggle2 = false;

void GtavSubmenu()
{
   g_Menu.title(L"GTAV Menus");
   g_Menu.option(L"Menu 1");
   g_Menu.option(L"Menu 2");
   g_Menu.option(L"Menu 3").toggle(testToggle1);
   g_Menu.option(L"Menu 4");
   g_Menu.option(L"Menu 5");
   g_Menu.option(L"Menu 6");
   g_Menu.option(L"Menu 7");
   g_Menu.option(L"Menu 8");
   g_Menu.option(L"Menu 9");
   g_Menu.option(L"Menu 10");
   g_Menu.option(L"Menu 11");
   g_Menu.option(L"Menu 12");
   g_Menu.option(L"Menu 13");
   g_Menu.option(L"Menu 14");
   g_Menu.option(L"Menu 15").toggle(testToggle2);
   g_Menu.option(L"Menu 16");
   g_Menu.option(L"Menu 17");
   g_Menu.option(L"Menu 18");
   g_Menu.option(L"Menu 19");
   g_Menu.option(L"Menu 20");
}