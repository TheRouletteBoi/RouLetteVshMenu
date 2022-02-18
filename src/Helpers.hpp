#pragma once
#include <string>
#include <vsh/system_plugin.h>
#include <vsh/pafPhWidget.h>
#include <vsh/pafView.h>
#include <vsh/vshcommon.h>
#include <vsh/vshmain.h>
#include "GamePad.hpp"

struct Color
{
   uint8_t r;
   uint8_t g;
   uint8_t b;
   uint8_t a;
};

class Helpers
{
public:
   void Initialize();
   void OnUpdate();
   Color UpdateRGBInterpolation();
   void TakeScreenshot();

private:
   void UpdateFPS();
   int GetFramesPerSecond();



public:
   // Common
   vsh::paf::View* system_plugin{};
   vsh::paf::PhWidget* page_autooff_guide{};

   // Controller Options
   CellPadData padData;
   uint64_t buttonLastTime[17];

private:
   // Rainbow Options
   int m_rainbowModeColorIndex = 0;

   // Frames Per Second Options
   uint64_t m_FpsLastTime{};
   int m_FpsFrameCount{};
   int m_Fps{};

   // Screenshot Options
   uint64_t m_ScreenshotLastTime{};
};

template<class T>
std::string to_string(T in)
{
   char buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::snprintf(buf, sizeof(buf), "%d", in);
   return std::string(buf);
}

extern Helpers g_Helpers;