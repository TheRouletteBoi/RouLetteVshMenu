#pragma once
#include <string>
#include <vsh/system_plugin.h>
#include <vsh/pafPhWidget.h>
#include <vsh/pafView.h>
#include <vsh/vshcommon.h>
#include <vsh/vshmain.h>
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
   vsh::paf::View* system_plugin{};
   vsh::paf::View* game_plugin{};
   vsh::paf::View* game_ext_plugin{};
   vsh::paf::PhWidget* page_autooff_guide{};

   bool m_IsHen{};
   bool m_StateGameRunning{};
   bool m_StateGameJustLaunched{};

private:
   unsigned int m_ScreenshotLastTime{};
};

extern Helpers g_Helpers;