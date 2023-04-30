#include "Submenus.hpp"
#include "Games/GamePatching.hpp"
#include "Games/GTAV.hpp"

void LoadMenuThatSupportsAllSyscalls(FindActiveGame::PatchedMenu menuId, const char* menuName, const char* gameName)
{
    if (g_FindActiveGame.LoadMenu(menuId))
    {
        const wchar_t* message = vsh::wva(L"%s %s is ready to load", menuName, gameName);
        vsh::ShowNotificationWithIcon(message, vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    }
}

void LoadDexMenu(FindActiveGame::PatchedMenu menuId, const char* menuName, const char* gameName)
{
    if (!IsConsoleDex())
    {
        vsh::ShowNavigationMessage(L"This menu is only for DEX consoles");
        return;
    }

    if (g_FindActiveGame.LoadMenu(menuId))
    {
        const wchar_t* message = vsh::wva(L"%s %s is ready to load", menuName, gameName);
        vsh::ShowNotificationWithIcon(message, vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    }
}

void LoadCcapiMenu(FindActiveGame::PatchedMenu menuId, const char* menuName, const char* gameName)
{
    if (IsConsoleHen())
    {
        vsh::ShowNavigationMessage(L"This menu is only for CEX/DEX consoles");
        return;
    }

    if (!DoesConsoleHaveCCAPI())
    {
        vsh::ShowNavigationMessage(L"CCAPI is not installed on your console");
        return;
    }

    if (g_FindActiveGame.LoadMenu(menuId))
    {
        const wchar_t* message = vsh::wva(L"%s %s is ready to load", menuName, gameName);
        vsh::ShowNotificationWithIcon(message, vsh::NotifyIcon::BlueVerifiedCheckmark, vsh::NotifySound::Trophy);
    }
}

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
        LoadDexMenu(FindActiveGame::PatchedMenu::GTAVLexicon, "Lexicon", "GTAV");
    });

    g_Menu.Option(L"Serendipity").RightText(L"\uF882 + \uF887").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::GTAVSerendipity, "Serendipity", "GTAV");
    });

    g_Menu.Option(L"Terrorizer").RightText(L"\uF88B + \uF886").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::GTAVTerrorizer, "Terrorizer", "GTAV");
    });

    g_Menu.Option(L"Debug Payload").Action([]
    {
        LoadMenuThatSupportsAllSyscalls(FindActiveGame::PatchedMenu::GTAVDebugPayload, "Debug Payload", "GTAV");
    });

    g_Menu.Option(L"[Step 1] Load Offsets For 1.12").Action([]
    {
        if (vsh::GetCooperationMode() == vsh::CooperationMode::Game)
        {
            GTAV::CHEATS::FindExternalOffsets();
        }
        else
            vsh::ShowNotificationWithIcon(L"You must be in game", vsh::NotifyIcon::Error, vsh::NotifySound::None);
    });

    g_Menu.Option(L"[Step 2] Spawn Adder For 1.12").Description(L"Spawned in last death location").Action([]
    {
        if (vsh::GetCooperationMode() == vsh::CooperationMode::Game)
        {
            int selfPlayerId = GTAV::CHEATS::GetGlobal<int>(2385027 + 1); // PlayerId
            int totalNumPlayers = GTAV::CHEATS::GetGlobal<int>(2390805); // totalNumPlayers

            GTAV::CHEATS::SetGlobal<int>(2394760 + 1657, 1); // required for spawning
            GTAV::CHEATS::SetGlobal<int>(2394760 + 1656, 1); // required for spawning
            GTAV::CHEATS::SetGlobal<int>(2394760 + 1660, 3); // required for spawning
            int vehicleNetId = GTAV::CHEATS::GetGlobal<int>(2394760 + 1665); // vehicleNetId
            GTAV::CHEATS::SetGlobal<uint32_t>(2394760 + 1603 + 42, 0xB779A091); // vehicle hash
            GTAV::CHEATS::Vector3 deathCoordinates = GTAV::CHEATS::GetGlobal<GTAV::CHEATS::Vector3>(2382711 + 279); // last death coordinates
            GTAV::CHEATS::SetGlobal<GTAV::CHEATS::Vector3>(2394760 + 1661, deathCoordinates); // coordinates 
            GTAV::CHEATS::SetGlobal<float>(2394760 + 1664, 0); // heading
        }
        else
            vsh::ShowNotificationWithIcon(L"You must be in game", vsh::NotifyIcon::Error, vsh::NotifySound::None);
    });
}

void MinecraftSubmenu()
{
    g_Menu.Title(L"Minecraft Menus");
    g_Menu.Option(L"Modcraft V4").RightText(L"\uF888 + \uF884").Action([]
    {
        LoadMenuThatSupportsAllSyscalls(FindActiveGame::PatchedMenu::MinecraftModcraftV4, "Modcraft", "Minecraft");
    });
}

void CodBo1Submenu()
{
    g_Menu.Title(L"Black Ops 1 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::BO1Paradox, "Paradox", "BO1");
    });

    g_Menu.Option(L"Fusion").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::BO1Fusion, "Fusion", "BO1");
    });
}

void CodBo2Submenu()
{
    g_Menu.Title(L"Black Ops 2 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::BO2Paradox, "Paradox", "BO2");
    });

#ifdef DEPRECATED_MENU
    g_Menu.Option(L"SPRX.IO").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::BO2Sprxio, "SPRX.IO", "BO2");
    });
#endif // DEPRECATED_MENU

    g_Menu.Option(L"Destiny").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::BO2Destiny, "Destiny", "BO2");
    });

    g_Menu.Option(L"Kebab").RightText(L"\uF886 + \uF88D").Description(L"\uF5B5 CEX/DEX/HEN menu").Action([] 
    {
        LoadMenuThatSupportsAllSyscalls(FindActiveGame::PatchedMenu::BO2Kebab, "Kebab", "BO2");
    });
}

void CodBo3Submenu()
{
    g_Menu.Title(L"Black Ops 3 Menus");
    g_Menu.Option(L"Fatality").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::BO3Fatality, "Fatality", "BO3");
    });
}

void CodMw2Submenu()
{
    g_Menu.Title(L"Modern Warfare 2 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::MW2Paradox, "Paradox", "MW2");
    });

    g_Menu.Option(L"Reborn").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::MW2Reborn, "Reborn", "MW2");
    });
}

void CodMw3Submenu()
{
    g_Menu.Title(L"Modern Warfare 3 Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::MW3Paradox, "Paradox", "MW3");
    });

    g_Menu.Option(L"Phantom").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::MW3Phantom, "Phantom", "MW3");
    });

    g_Menu.Option(L"Project Memories").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::MW3ProjectMemories, "Project Memories", "MW3");
    });
}

void CodGhostSubmenu()
{
    g_Menu.Title(L"Cod Ghost Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::GhostParadox, "Paradox", "COD Ghost");
    });

    g_Menu.Option(L"Eternity").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::GhostEternity, "Eternity", "COD Ghost");
    });
}

void CodAwSubmenu()
{
    g_Menu.Title(L"Advance Warfare Menus");
    g_Menu.Option(L"Paradox").RightText(L"\uF88D + \uF884").Description(L"\uF5B5 DEX only menu").Action([]
    {
        LoadDexMenu(FindActiveGame::PatchedMenu::AWParadox, "Paradox", "COD Advance Warfare");
    });

    g_Menu.Option(L"Fury").RightText(L"\uF888 + \uF88D").Description(L"\uF5B5 CEX/DEX only menu").Action([]
    {
        LoadCcapiMenu(FindActiveGame::PatchedMenu::AWFury, "Fury", "COD Advance Warfare");
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
    g_Menu.Option(L"Display [Yes | No] Prompt").Toggle(g_Menu.displayYesNoPrompt);
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
            // I need to find a way to get file size on disk; see https://imgur.com/a/bSFHbGT
            CellFsStat st;
            cellFsStat(fileName, &st);
            uint64_t fileSize = st.st_size;
            uint64_t blockSize = st.st_blksize;
            uint64_t payloadPadding = 0x4000; // https://imgur.com/a/aFEfVIM
            uint64_t fileSizeOnDisk = fileSize + (4 * blockSize);
            uint64_t fileSizeOnDisk2 = fileSize + payloadPadding;
            vsh::printf("fileSize = %d | blockSize = %d | payloadPadding = %d | fileSizeOnDisk = %d | fileSizeOnDisk2 = %d\n", fileSize, blockSize, payloadPadding, fileSizeOnDisk, fileSizeOnDisk2);

            if (GamePatching::StartPayload(fileName, KB(4), 0x7D0, 0x4000, pageTable))
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