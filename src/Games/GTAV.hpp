#pragma once
#include "GamePatching.hpp"
#include "Memory/Pattern.hpp"

namespace GTAV
{
    namespace CHEATS
    {
        using namespace GamePatching;

        struct Vector3
        {
            float x, y, z;
        };

        static uintptr_t globalPtr = 0;

        static void FindExternalOffsets()
        {
            uintptr_t addr = FindPatternGameProcess(g_FindActiveGame.GetRunningGameProcessId(),
                0x00010200, 0x2269700, 4,
                "\x60\x7F\x00\x00\x3B\xC0\x00\x00\x80\x64\x00\x00\x30\x63\x00\x00\x2C\x03\x00\x00\x90\x64\x00\x00\x40\x82\x00\x00",
                28,
                "xx??xx??xx??xx??xx??xx??xx??");

            uint32_t low = GetMem<uint32_t>(addr + 0x1C);
            uint32_t high = GetMem<uint32_t>(addr + 0x28);

            uint32_t combineAddr = (((uint16_t)(low) << 16) | (uint16_t)(high));
            uint32_t combineFinal = (combineAddr & 0x8000) ? combineAddr - 0x10000 : combineAddr;

            globalPtr = combineFinal;
        }

        template <typename T>
        T GetGlobal(int globalId)
        {
            if (!globalPtr)
                return {};

            uintptr_t ptr = GetMem<uintptr_t>(globalPtr + (((globalId / 0x40000) & 0x3F) * 4));

            if (ptr)
                return GetMem<T>(ptr + ((globalId % 0x40000) * 4));

            return {};
        }

        template <typename T>
        void SetGlobal(int globalId, T value)
        {
            if (!globalPtr)
                return;

            uintptr_t ptr = GetMem<uintptr_t>(globalPtr + (((globalId / 0x40000) & 0x3F) * 4));

            if (ptr)
                SetMem<T>(ptr + ((globalId % 0x40000) * 4), value);
        }
    }

   static void Initialize()
   {
      using namespace GamePatching;

      switch (g_FindActiveGame.m_MenuToLoad)
      {
         case FindActiveGame::PatchedMenu::GTAVLexicon:
         {
             const char* sprxInternalName = "Lexicon";
             if (IsModuleLoaded(sprxInternalName))
             {
                 SetBranch(Ida2Mem(sprxInternalName, 0x57BC0), Ida2Mem(sprxInternalName, 0x57C5C)); // so you can load the menu offline
                 SetNop(Ida2Mem(sprxInternalName, 0x561E8));                                        // nop read license key
                 SetBranch(Ida2Mem(sprxInternalName, 0x56200), Ida2Mem(sprxInternalName, 0x57AE8)); // skip to hooking
                 SetNop(Ida2Mem(sprxInternalName, 0x57B28));                                        // nop address decrypter
                 SetNop(Ida2Mem(sprxInternalName, 0x57B3C));                                        // nop thread for server settings
                 SetNop(Ida2Mem(sprxInternalName, 0x57B40));                                        // nop thread for server settings 2
                 SetMem<uint32_t>(0x1C2BB80, Ida2Mem(sprxInternalName, 0x50878));                   // hook is player online
                 //SetMem<uint32_t>(0x1C271E0, Ida2Mem(sprxInternalName, 0x50878));                 // hook GET_INDEX_OF_CURRENT_LEVEL  an old hook he used in his previous versions of lexicon
                 SetMem<uint32_t>(0x1C2A3D0, Ida2Mem(sprxInternalName, 0x50DEC));                   // hook disable control actions
                 SetMem<uint32_t>(0x1C2E9F8, Ida2Mem(sprxInternalName, 0x50EFC));                   // hook set ped current weapon
                 vsh::ShowNotificationWithIcon(L"Lexicon has been patched", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
             }
             else
                 vsh::ShowNotificationWithIcon(L"Lexicon sprx not detected", vsh::NotifyIcon::Caution, vsh::NotifySound::Trophy);
             break;
         }
         case FindActiveGame::PatchedMenu::GTAVSerendipity:
         {
             const char* sprxInternalName = "GTA5_Menu";
             if (IsModuleLoaded(sprxInternalName))
             {
                 SetNop(Ida2Mem(sprxInternalName, 0x4194));                         // read key | 0x3968
                 SetNop(Ida2Mem(sprxInternalName, 0x41D0));                         // first auth request
                 SetNop(Ida2Mem(sprxInternalName, 0x42B0));                         // seconds auth request
                 SetMem<uint32_t>(Ida2Mem(sprxInternalName, 0x60064), 0x3E3A20);    // Main Hook Address 
                 SetMem<uint32_t>(Ida2Mem(sprxInternalName, 0x61B40), 0x3F30A3D7);  // Text Position X
                 SetMem<uint32_t>(Ida2Mem(sprxInternalName, 0x61B44), 0x3F4CCCCD);  // Text Position Y

                 uint32_t menu_rgba[] = {
                    0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF,
                    0x000000FF, 0x000000FF, 0x0000000F, 0x0000000F, 0x0000000F, 0x00000078,
                    0x000000FF, 0x0000007D, 0x00000000, 0x000000AF, 0x000000FF, 0x0000007D,
                    0x00000000, 0x000000AF, 0x000000FF, 0x0000007D, 0x00000000, 0x000000AF
                 };
                 WriteProcessMemory(g_FindActiveGame.GetRunningGameProcessId(), (void*)Ida2Mem(sprxInternalName, 0x61C10), &menu_rgba, sizeof(menu_rgba));

                 vsh::ShowNotificationWithIcon(L"Serendipity has been patched", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
             }
             else
                 vsh::ShowNotificationWithIcon(L"Serendipity sprx not detected", vsh::NotifyIcon::Caution, vsh::NotifySound::Trophy);
             break;
         }
         case FindActiveGame::PatchedMenu::GTAVTerrorizer:
         {
             const char* sprxInternalName = "GTAOTerrorizer";
             if (IsModuleLoaded(sprxInternalName))
             {
                 SetNop(Ida2Mem(sprxInternalName, 0x4FD58));                       // nop auther thread
                 SetNop(Ida2Mem(sprxInternalName, 0x48B40));                       // bypass check in PatchInJump
                 SetMem<uint32_t>(Ida2Mem(sprxInternalName, 0x48D74), 0x2C030001); // set some check to true
                 SetMem<uint32_t>(Ida2Mem(sprxInternalName, 0x48E48), 0x38600001); // set check to true
                 SetBranchless(Ida2Mem(sprxInternalName, 0x48BF4));                // branch where he sets up all the hooks
                 vsh::ShowNotificationWithIcon(L"Terrorizer has been patched", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
             }
             else
                 vsh::ShowNotificationWithIcon(L"Terrorizer sprx not detected", vsh::NotifyIcon::Caution, vsh::NotifySound::Trophy);
             break;
         }
         case FindActiveGame::PatchedMenu::GTAVDebugPayload:
         {
             // wait because injecting menu too fast can result in a crash
             Sleep(50000);

             const std::string& fileName = GetCurrentDir() + "modmenus/GTAV/gtav.bin";
             uint64_t pageTable[2]{};
             if (StartPayload(fileName.c_str(), KB(4), 0x7D0, 0x4000, pageTable))
                 vsh::ShowNotificationWithIcon(L"GTAV Payload is now loaded", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
             break;
         }
      }
   }
}