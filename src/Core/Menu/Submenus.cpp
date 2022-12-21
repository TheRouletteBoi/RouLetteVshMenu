#include "Submenus.hpp"
#include "Games/GamePatching.hpp"

void MainSubmenu()
{
    g_Menu.Title(L"Main menu");
    g_Menu.Option(L"GTAV Menus \uF477\uF477").Submenu(GtavSubmenu);
    g_Menu.Option(L"Minecraft Menus").Submenu(MinecraftSubmenu);
    g_Menu.Option(L"Black Ops 1 Menus").Submenu(CodBo1Submenu);
    g_Menu.Option(L"Black Ops 2 Menus \uF476").Submenu(CodBo2Submenu);
    g_Menu.Option(L"Black Ops 3 Menus").Submenu(CodBo3Submenu);
    g_Menu.Option(L"Modern Warfare 2 Menus \uF5BC").Submenu(CodMw2Submenu);
    g_Menu.Option(L"Modern Warfare 3 Menus \uF46E").Submenu(CodMw3Submenu);
    g_Menu.Option(L"COD Ghost Menus").Submenu(CodGhostSubmenu);
    g_Menu.Option(L"Advance Warfare Menus").Submenu(CodAwSubmenu);
#ifdef LAUNCHER_DEBUG
    g_Menu.Option(L"Developer").Submenu(DeveloperSubmenu);
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
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::GTAVLexicon))
            vsh::ShowNotificationWithIcon(L"Lexicon GTAV is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Serendipity").RightText(L"\uF882 + \uF887").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::GTAVSerendipity))
            vsh::ShowNotificationWithIcon(L"Serendipity GTAV is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);

    });

    g_Menu.Option(L"Terrorizer").RightText(L"\uF88B + \uF886").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::GTAVTerrorizer))
            vsh::ShowNotificationWithIcon(L"Terrorizer GTAV is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);

    });

    g_Menu.Option(L"Debug Payload").Action([]
    {
        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::GTAVDebugPayload))
            vsh::ShowNotificationWithIcon(L"GTAV Debug payload is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void MinecraftSubmenu()
{
    g_Menu.Title(L"Minecraft Menus");
    g_Menu.Option(L"Modcraft V4").RightText(L"\uF888 + \uF884").Action([]
    {
        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::MinecraftModcraftV4))
            vsh::ShowNotificationWithIcon(L"Modcraft Minecraft is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodBo1Submenu()
{
    g_Menu.Title(L"Black Ops 1 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO1Paradox))
            vsh::ShowNotificationWithIcon(L"Paradox BO1 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Fusion").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO1Fusion))
            vsh::ShowNotificationWithIcon(L"Fusion BO1 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodBo2Submenu()
{
    g_Menu.Title(L"Black Ops 2 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO2Paradox))
            vsh::ShowNotificationWithIcon(L"Paradox BO2 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

#ifdef DEPRECATED_MENU
    g_Menu.Option(L"SPRX.IO").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO2Sprxio))
            vsh::ShowNotificationWithIcon(L"SPRX.IO BO2 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
#endif // DEPRECATED_MENU

    g_Menu.Option(L"Destiny").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO2Destiny))
            vsh::ShowNotificationWithIcon(L"Destiny BO2 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Kebab").RightText(L"\uF886 + \uF88D").Description(L"\uF5B5 CEX/DEX/HEN menu").Action([] 
    {
        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO2Kebab))
            vsh::ShowNotificationWithIcon(L"Kebab BO2 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodBo3Submenu()
{
    g_Menu.Title(L"Black Ops 3 Menus");
    g_Menu.Option(L"Fatality").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::BO3Fatality))
            vsh::ShowNotificationWithIcon(L"Fatality BO3 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodMw2Submenu()
{
    g_Menu.Title(L"Modern Warfare 2 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::MW2Paradox))
            vsh::ShowNotificationWithIcon(L"Paradox MW2 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Reborn").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::MW2Reborn))
            vsh::ShowNotificationWithIcon(L"Reborn MW2 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodMw3Submenu()
{
    g_Menu.Title(L"Modern Warfare 3 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::MW3Paradox))
            vsh::ShowNotificationWithIcon(L"Paradox MW3 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Phantom").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::MW3Phantom))
            vsh::ShowNotificationWithIcon(L"Phantom MW3 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Project Memories").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::MW3ProjectMemories))
            vsh::ShowNotificationWithIcon(L"Project Memories MW3 is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodGhostSubmenu()
{
    g_Menu.Title(L"Cod Ghost Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::GhostParadox))
            vsh::ShowNotificationWithIcon(L"Paradox Ghost is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Eternity").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::GhostEternity))
            vsh::ShowNotificationWithIcon(L"Eternity COD Ghost is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });
}

void CodAwSubmenu()
{
    g_Menu.Title(L"Advance Warfare Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        if (!IsConsoleDex())
        {
            vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::AWParadox))
            vsh::ShowNotificationWithIcon(L"Paradox Advance Warfare is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    });

    g_Menu.Option(L"Fury").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        if (IsConsoleHen())
        {
            vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
            return;
        }

        if (g_FindActiveGame.LoadMenu(FindActiveGame::PatchedMenu::AWFury))
            vsh::ShowNotificationWithIcon(L"Fury Advance Warfare is ready to load", vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
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

void DeveloperSubmenu()
{
    g_Menu.Title(L"Developer");
    g_Menu.Option(L"Load /dev_hdd0/tmp/plugin.sprx into game process").Action([]
    {
        if (FileExist("/dev_hdd0/tmp/plugin.sprx"))
        {
            bool couldLoad = GamePatching::StartSprx("/dev_hdd0/tmp/plugin.sprx");
            if (couldLoad)
                vsh::ShowNavigationMessage(L"Successfully loaded /dev_hdd0/tmp/plugin.sprx into process");
            else
                vsh::ShowNavigationMessage(L"You are not in game");
        }
        else
        {
            vsh::ShowNavigationMessage(L"File does not exist");
        }
    });

    g_Menu.Option(L"Unload /dev_hdd0/tmp/plugin.sprx from game process").Action([] 
    {
        if (FileExist("/dev_hdd0/tmp/plugin.sprx"))
        {
            sys_pid_t processId = vsh::GetGameProcessId();
            if (processId)
            {
                sys_prx_id_t prxId = GamePatching::GetProcessModuleIdByFilePath(processId, "/dev_hdd0/tmp/plugin.sprx");
                if (prxId)
                {
                    ps3mapi_unload_process_modules(vsh::GetGameProcessId(), prxId);
                    vsh::ShowNavigationMessage(L"Successfully unloaded /dev_hdd0/tmp/plugin.sprx from process");
                }
                else
                    vsh::ShowNavigationMessage(L"sprx is not loaded into game");
            }
            else
                vsh::ShowNavigationMessage(L"You are not in game");
        }
        else
        {
            vsh::ShowNavigationMessage(L"File does not exist");
        }
    });

    static uint64_t pageTable[2]{};

    g_Menu.Option(L"Load /dev_hdd0/tmp/payload.bin into game process").Action([]
    {
        const char* fileName = "/dev_hdd0/tmp/payload.bin";
        if (FileExist(fileName))
        {
            int64_t fileSize = GetFileSize(fileName) + 0x4000; // is + 0x4000 enough or will we crash??
            if (GamePatching::StartPayload(fileName, fileSize, 0x7D0, 0x4000, pageTable))
            {
                vsh::printf("Payload injected at table[0] = 0x%016llX\n", pageTable[0]);
                vsh::printf("Payload injected at table[1] = 0x%016llX\n", pageTable[1]);
                vsh::ShowNavigationMessage(L"Successfully loaded /dev_hdd0/tmp/payload.bin into process");
            }
        }
        else
        {
            vsh::ShowNavigationMessage(L"File does not exist");
        }
    });

    g_Menu.Option(L"Unload /dev_hdd0/tmp/payload.bin from game process").Action([]
    {
        sys_pid_t processId = vsh::GetGameProcessId();
        if (processId)
        {
            if (pageTable[0] && pageTable[1])
            {
                int ret = ps3mapi_process_page_free(processId, 0x2F, pageTable);
                vsh::memset(pageTable, 0, sizeof(pageTable));
                if (ret == SUCCEEDED)
                    vsh::ShowNavigationMessage(L"page sucessfully free'd");
                else
                {
                    vsh::printf("failed to free page 0x%X\n", ret);
                    vsh::ShowNavigationMessage(L"failed to free page");
                }
            }
            else
            {
                vsh::ShowNavigationMessage(L"page has not been allocated");
            }
        }
        else
            vsh::ShowNavigationMessage(L"You are not in game");
    });
}