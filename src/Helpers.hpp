#pragma once
#include <string>
#include <vsh/system_plugin.h>
#include <vsh/pafPhWidget.h>
#include <vsh/pafView.h>
#include <vsh/vshcommon.h>
#include <vsh/vshmain.h>
#include "GamePad.hpp"
#include "GUI/Base.hpp"
#include "Util/FileSystem.hpp"

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

   bool testToggle1{};
   bool testToggle2{};

private:
   // Frames Per Second Options
   uint64_t m_FpsLastTime{};
   int m_FpsFrameCount{};
   int m_Fps{};

   // Screenshot Options
   uint64_t m_ScreenshotLastTime{};
};

template<class T>
std::string to_string(T value)
{
   char buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::snprintf(buf, sizeof(buf), "%d", value);
   return std::string(buf);
}

template<class T>
std::wstring to_wstring(T value)
{
   wchar_t buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::swprintf(buf, sizeof(buf), L"%d", value);
   return std::wstring(buf);
}

template<>
std::string to_string(uint64_t value);

template<>
std::string to_string(float value);

template<>
std::string to_string(double value);

template<>
std::wstring to_wstring(uint64_t value);

template<>
std::wstring to_wstring(float value);

template<>
std::wstring to_wstring(double value);

extern Helpers g_Helpers;