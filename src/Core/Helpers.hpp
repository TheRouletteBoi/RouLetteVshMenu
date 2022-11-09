#pragma once
#include <string>
#include <vsh/plugins.hpp>
#include <vsh/paf.hpp>
#include <vsh/vshcommon.hpp>
#include <vsh/vshmain.hpp>
#include "Utils/SystemCalls.hpp"
#include "Utils/Timers.hpp"
#include "Utils/FileSystem.hpp"
#include "Core/Input.hpp"

class Helpers
{
public:
   Helpers();

   void OnUpdate();
   void TakeScreenshot();

private:
   void MonitorGameState();

public:
   paf::View* m_SystemPlugin{};
   paf::View* m_GamePlugin{};
   paf::View* m_GameExtPlugin{};
   paf::View* m_XmbPlugin{};
   paf::PhWidget* m_PageAutoOffGuide{};

   bool m_IsHen{};
   bool m_StateGameRunning{};
   bool m_StateGameJustLaunched{};

private:
   uint64_t m_GameLaunchTime{};
   uint64_t m_ScreenshotLastTime{};
};

extern Helpers g_Helpers;