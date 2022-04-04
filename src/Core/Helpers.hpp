#pragma once
#include <string>
#include <vsh/system_plugin.h>
#include <vsh/pafPhWidget.h>
#include <vsh/pafView.h>
#include <vsh/vshcommon.h>
#include <vsh/vshmain.h>
#include "Utils/SystemCalls.hpp"
#include "Utils/Timers.hpp"

class Helpers
{
public:
   Helpers();

   void OnUpdate();

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
};

extern Helpers g_Helpers;