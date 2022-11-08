#pragma once
#include "GamePatching.hpp"

namespace CODBO2
{
    static void Initialize()
    {
        using namespace GamePatching;

        switch (g_FindActiveGame.m_MenuToLoad)
        {

        case CFindActiveGame::PatchedMenu::BO2Kebab:

            const char* moduleName = "BO2_Retro";
            char HookAddresses[] = {
                0x00, 0xD4, 0xA0, 0x00, 0x00, 0x67, 0xC4, 0x8C, 0x00,0x76, 0xBD, 0x90, 0x00, 0x04, 0x2F, 0xC8, 0x00, 0x8D,0xDD, 0x84, 0x00, 0x76, 0xF1, 0xB0, 0x00, 0x45, 0xC0,0x38, 0x00, 0x0E, 0x9B, 0xE8, 0x00, 0x0C, 0x57, 0x5C,0x00, 0x08, 0x59, 0x6C, 0x00, 0x05, 0x55, 0x48, 0x00,0x10, 0x30, 0x24, 0x00, 0x11, 0x65, 0x24, 0x00, 0x08,0x9D, 0xA0, 0x00, 0x10, 0x52, 0x44, 0x00, 0x04, 0x8A,0x48, 0x00, 0x1F, 0xCB, 0x3C, 0x00, 0x04, 0xC1, 0x88,0x00, 0x5E, 0x79, 0xE4, 0x00, 0x0E, 0x0D, 0xF0, 0x00,0x35, 0xDF, 0xB0, 0x00, 0x05, 0x4E, 0xA8, 0x00, 0x0F,0x38, 0x68, 0x00, 0x08, 0x29, 0xD0, 0x00, 0x32, 0x54,0x8C, 0x00, 0x67, 0xB3, 0x90, 0x00, 0x34, 0xAB, 0x44,0x00, 0x13, 0xA9, 0x80, 0x00, 0x11, 0xEB, 0xD8, 0x00,0x15, 0x45, 0x88, 0x00, 0x0B, 0xDF, 0x90, 0x00, 0x67,0xB5, 0xC4, 0x00, 0x84, 0x25, 0xB0, 0x00, 0x32, 0xB6,0xC0, 0x00, 0x32, 0xB7, 0x20, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x2D, 0x38, 0x00,0x00, 0x01, 0xCF, 0x02, 0x69, 0x46, 0x08, 0x00, 0x02,0x00, 0x50, 0xC3, 0x9A, 0xE1, 0xF5, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00
            };

            char CrackedByStr[]{
                0x43, 0x72, 0x61, 0x63, 0x6B, 0x65, 0x64, 0x20, 0x62, 0x79, 0x20, 0x53, 0x79, 0x6E, 0x66, 0x75, 0x6C, 0x00
            };

            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)Ida2Mem(moduleName, 0x529BC), CrackedByStr, sizeof(CrackedByStr));
            WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x316AC80, HookAddresses, 38 * 4);
            SetBranch(Ida2Mem(moduleName, 0x253D8), Ida2Mem(moduleName, 0x25EB4));
            SetBranch(Ida2Mem(moduleName, 0x25EBC), Ida2Mem(moduleName, 0x26040));
            SetMem<short>(Ida2Mem(moduleName, 0x2539F), 0x3333);
            break;

            case CFindActiveGame::PatchedMenu::BO2Paradox:
            {
                SetMem<uint32_t>(0x30FADB8, 0x38600001);            // read license key return true

                uint32_t license_and_auth_vars[] = { 0x1CC1D99A, 0xD0025C50, 0x001337EA, 0x01000000 };
                WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x3140E40, &license_and_auth_vars, sizeof(license_and_auth_vars));

                SetNop(0x30FAF5C);                                  // stop connection to paradox.sh

                // addresses loaded from server
                uint32_t xor_addresses[] = {
                    0x1C175042, 0x1C23F682, 0x1C23F686, 0x1C23F6BA, 0x1CC5F652, 0x1CD0BCBE,
                    0x1CB7EBBA, 0x1CB47B5A, 0x1CB77A72, 0x1CB7708A, 0x1C841702, 0x1C84175A,
                    0x1CC08012, 0x1CC08E92, 0x1C8934F2, 0x1CC54EBA, 0x1CF0E582, 0x1CB77DDE,
                    0x1CC77402, 0x1CC77456, 0x1CD10D8A, 0x1CFC70D2, 0x1CFC7FB2, 0x1CB47AA2,
                    0x1CB47C4A, 0x1C9ED052, 0x1C87F7AE, 0x1CC58F62
                };
                uint32_t malloc_0x70_address = GetMem<uint32_t>(0x3130094);
                if (malloc_0x70_address != 0)
                    WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)malloc_0x70_address, &xor_addresses, sizeof(xor_addresses));

                // offsets for 'malloc_0x70' structure
                uint32_t server_data[] = {
                    0x00000000, 0x00000004, 0x00000008, 0x0000000C, 0x00000010, 0x00000000,
                    0x00000014, 0x00000000, 0x00000018, 0x00000000, 0x0000001C, 0x00000000,
                    0x00000020, 0x00000000, 0x00000024, 0x00000000, 0x00000028, 0x00000000,
                    0x0000002C, 0x00000000, 0x00000030, 0x00000000, 0x00000034, 0x00000000,
                    0x00000038, 0x00000000, 0x0000003C, 0x00000000, 0x00000040, 0x00000000,
                    0x00000044, 0x00000000, 0x00000048, 0x00000000, 0x0000004C, 0x00000000,
                    0x00000050, 0x00000000, 0x00000054, 0x00000000, 0x00000058, 0x00000000,
                    0x0000005C, 0x00000000, 0x00000060, 0x00000000, 0x00000064, 0x00000000,
                    0x00000068, 0x00000000, 0x0000006C
                };
                WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)0x3150EF0, &server_data, sizeof(server_data));

                SetNop(0x30FBB2C);                                  // update module
                SetBranch(0x30FADC4, 0x30FAEEC);                    // skip the bullshit
                SetBranch(0x30FAF60, 0x30FB800);                    // skip the bullshit
                SetBranch(0x30FAB04, 0x30FAD40);                    // skip the bullshit
                SetBranch(0x312525C, 0x31255B0);                    // skip everything except for malloc
                SetMem<uint32_t>(0x10021594, 0xDE7BBE46);           // xor value 2
                SetBranch(0x311DBAC, 0x311DC24);                    // skip thread exit. ##Crashes sometimes if load too quickly or too slowly

                vsh::ShowNofityWithSound(L"Paradox has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
                break;
            }
            case CFindActiveGame::PatchedMenu::BO2Sprxio:
            {
                // Incomplete... ##Crashes as soon as you press load 'yes'
                /*SetBlr(0x3101A34);								// block read license key
                SetBlr(0x3101CBC);								// block updates
                SetBlr(0x3101C28);								// block get psid
                SetBlr(0x3101E7C);								// block auth sprx
                SetBlr(0x3102190);								// block auth welcome
                SetMem<uint32_t>(0x313D224, 0x00000001);	// has auth success
                vsh::ShowNofityWithSound(L"SPRX.IO has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);*/
                vsh::ShowNofityWithSound(L"Unable to patch SPRX.IO", vsh::eNotifyIcon::Caution, vsh::eNotifySound::Trophy);
                break;
            }
            case CFindActiveGame::PatchedMenu::BO2Destiny:
            {
                // wait because injecting menu too fast can result in a crash
                Sleep(50000);

                const std::string& fileName = GetCurrentDir() + "modmenus/enstone/destiny_by_enstone_120_patched.bin";
                if (StartPayload(fileName.c_str(), KB(628), 0x7D0, 0x4000))
                    vsh::ShowNofityWithSound(L"Destiny is now loaded", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
                break;
            }
        }
    }
}