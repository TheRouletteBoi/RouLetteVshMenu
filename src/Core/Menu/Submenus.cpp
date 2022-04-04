
#include "Submenus.hpp"

void MainSubmenu()
{
    g_Menu.Title(L"Main menu");
    g_Menu.Option(L"GTAV Menus \uF477\uF477").Submenu(GtavSubmenu);
    g_Menu.Option(L"Black Ops 1 Menus").Submenu(CodBo1Submenu);
    g_Menu.Option(L"Black Ops 2 Menus \uF476").Submenu(CodBo2Submenu);
    g_Menu.Option(L"Black Ops 3 Menus").Submenu(CodBo3Submenu);
    g_Menu.Option(L"Modern Warfare 2 Menus \uF5BC").Submenu(CodMw2Submenu);
    g_Menu.Option(L"Modern Warfare 3 Menus \uF46E").Submenu(CodMw3Submenu);
    g_Menu.Option(L"COD Ghost Menus").Submenu(CodGhostSubmenu);
    g_Menu.Option(L"Advance Warfare Menus").Submenu(CodAwSubmenu);
#ifdef LAUNCHER_DEBUG
    g_Menu.Option(L"Settings").Submenu(SettingsSubmenu);
#endif // LAUNCHER_DEBUG
}

void GtavSubmenu()
{
    g_Menu.Title(L"GTAV Menus");
    g_Menu.Option(L"Lexicon").RightText(L"\uF888 + \uF88B").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVLexicon))
            vsh::ShowNofityWithSound(L"Lexicon GTAV is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Serendipity").RightText(L"\uF882 + \uF887").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVSerendipity))
            vsh::ShowNofityWithSound(L"Serendipity GTAV is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);

    });

    g_Menu.Option(L"Terrorizer").RightText(L"\uF88B + \uF886").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVTerrorizer))
            vsh::ShowNofityWithSound(L"Terrorizer GTAV is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);

    });

    g_Menu.Option(L"Debug Payload").Action([]
    {
        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GTAVDebugPayload))
            vsh::ShowNofityWithSound(L"GTAV Debug payload is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });
}

void CodBo1Submenu()
{
    g_Menu.Title(L"Black Ops 1 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO1Paradox))
            vsh::ShowNofityWithSound(L"Paradox BO1 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Fusion").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
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
    g_Menu.Title(L"Black Ops 2 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO2Paradox))
            vsh::ShowNofityWithSound(L"Paradox BO2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"SPRX.IO").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::BO2Sprxio))
            vsh::ShowNofityWithSound(L"SPRX.IO BO2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Destiny").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
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
    g_Menu.Title(L"Black Ops 3 Menus");
    g_Menu.Option(L"Fatality").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
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
    g_Menu.Title(L"Modern Warfare 2 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW2Paradox))
            vsh::ShowNofityWithSound(L"Paradox MW2 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Reborn").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
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
    g_Menu.Title(L"Modern Warfare 3 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW3Paradox))
            vsh::ShowNofityWithSound(L"Paradox MW3 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Phantom").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::MW3Phantom))
            vsh::ShowNofityWithSound(L"Phantom MW3 is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Project Memories").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
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
    g_Menu.Title(L"Cod Ghost Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::GhostParadox))
            vsh::ShowNofityWithSound(L"Paradox Ghost is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Eternity").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
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
    g_Menu.Title(L"Advance Warfare Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::AWParadox))
            vsh::ShowNofityWithSound(L"Paradox Advance Warfare is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });

    g_Menu.Option(L"Fury").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowButtonNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(CFindActiveGame::PatchedMenu::AWFury))
            vsh::ShowNofityWithSound(L"Fury Advance Warfare is ready to load", vsh::eNotifyIcon::BlueVerifiedCheckmark, vsh::eNotifySound::Trophy);
    });
}

void SettingsSubmenu()
{
    g_Menu.Title(L"Settings");
    g_Menu.Option(L"Edit position").Toggle(g_Menu.stateMoving);
    g_Menu.Option(L"Text size").Slider(g_Menu.sizeText, 10.f, 40.f, 0.25f, 2);
    g_Menu.Option(L"Menu width").Slider(g_Menu.sizeWidth, 200.f, 500.f, 2.f, 2);
    g_Menu.Option(L"Menu Color").EditColor(g_Menu.colorMenu, true);
    g_Menu.Option(L"Background opacity").Slider(g_Menu.colorBackground.a, 0.f, 1.f, 0.01f, 2);
}