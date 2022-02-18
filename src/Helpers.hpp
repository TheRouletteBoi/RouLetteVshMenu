#pragma once
#include <string>
#include <vsh/system_plugin.h>
#include <vsh/pafPhWidget.h>
#include <vsh/pafView.h>
#include <vsh/vshcommon.h>
#include <vsh/vshmain.h>
#include "GamePad.hpp"
#include "GUI/Base.hpp"

class Helpers
{
public:
   void Initialize();
   void OnUpdate();
   void TakeScreenshot();

private:
   void UpdateCalculateFps();
   int GetFps();



public:
   // Common
   vsh::paf::View* system_plugin{};
   vsh::paf::PhWidget* page_autooff_guide{};

private:
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

template<class T>
std::wstring to_wstring(T in)
{
   wchar_t buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::swprintf(buf, sizeof(buf), L"%d", in);
   return std::wstring(buf);
}

extern Helpers g_Helpers;