#pragma once
#include "GamePatching.hpp"

namespace Minecraft
{
    static void Initialize()
    {
        using namespace GamePatching;

        switch (g_FindActiveGame.m_MenuToLoad)
        {
            case CFindActiveGame::PatchedMenu::MinecraftModcraftV4:
            {
                const char* sprxInternalName = "DownCraftSPRX";
                SetBranch(Ida2Mem(sprxInternalName, 0x18ABC), Ida2Mem(sprxInternalName, 0x18B0C)); // skip all memory checks
                vsh::ShowNofityWithSound(L"Modcraft has been patched", vsh::eNotifyIcon::Pen, vsh::eNotifySound::Trophy);
                break;
            }
        }
    }
}