#pragma once
#include "GamePatching.hpp"

namespace Minecraft
{
    static void Initialize()
    {
        using namespace GamePatching;

        switch (g_FindActiveGame.m_MenuToLoad)
        {
            case FindActiveGame::PatchedMenu::MinecraftModcraftV4:
            {
                const char* sprxInternalName = "DownCraftSPRX";
                SetBranch(Ida2Mem(sprxInternalName, 0x18ABC), Ida2Mem(sprxInternalName, 0x18B0C)); // skip all memory checks
                vsh::ShowNotificationWithIcon(L"Modcraft has been patched", vsh::NotifyIcon::Pen, vsh::NotifySound::Trophy);
                break;
            }
        }
    }
}