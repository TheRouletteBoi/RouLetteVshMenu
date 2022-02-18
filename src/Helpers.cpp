#include "Helpers.hpp"

Helpers g_Helpers;

void Helpers::Initialize()
{

}

void Helpers::OnUpdate()
{
   system_plugin = vsh::paf::View::Find("system_plugin");
   if (system_plugin)
      page_autooff_guide = system_plugin->FindWidget("page_autooff_guide");

   UpdateFPS();

}

// TODO(Roulette): Change into lerp function so it is easier to read
Color Helpers::UpdateRGBInterpolation()
{
   Color rgb;
   m_rainbowModeColorIndex += 1;

   rgb.r = ((m_rainbowModeColorIndex < 255) * m_rainbowModeColorIndex) + ((m_rainbowModeColorIndex >= 255) * 255) + ((m_rainbowModeColorIndex > 511) * (512 - m_rainbowModeColorIndex)) + ((m_rainbowModeColorIndex > 766) * (m_rainbowModeColorIndex - 766)) + ((m_rainbowModeColorIndex >= 1276) * (m_rainbowModeColorIndex - 1276)) + ((m_rainbowModeColorIndex > 1530) * (1530 - m_rainbowModeColorIndex)) + ((m_rainbowModeColorIndex > 1786) * (1786 - m_rainbowModeColorIndex));

   rgb.g = (m_rainbowModeColorIndex < 256) * (1) + (m_rainbowModeColorIndex > 255) * (m_rainbowModeColorIndex - 255) + (m_rainbowModeColorIndex > 510) * (510 - m_rainbowModeColorIndex) + (m_rainbowModeColorIndex > 1020) * (1020 - m_rainbowModeColorIndex) + (m_rainbowModeColorIndex > 1274) * (m_rainbowModeColorIndex - 1274) + (m_rainbowModeColorIndex > 1530) * (m_rainbowModeColorIndex - 1531) + (m_rainbowModeColorIndex > 1785) * (3571 - (2 * m_rainbowModeColorIndex));

   rgb.b = (m_rainbowModeColorIndex < 764) * (1) + (m_rainbowModeColorIndex > 765) * (m_rainbowModeColorIndex - 765) + (m_rainbowModeColorIndex > 1020) * (1020 - m_rainbowModeColorIndex) + (m_rainbowModeColorIndex > 1786) * (1786 - m_rainbowModeColorIndex);

   // reset to black
   if (m_rainbowModeColorIndex > 2040)
      m_rainbowModeColorIndex = 1;

   return rgb;
}

void Helpers::UpdateFPS()
{
   uint64_t timeNow = get_time_now();

   if (m_FpsLastTime == 0)
      m_FpsLastTime = timeNow;
   else
   {
      if ((timeNow - m_FpsLastTime) >= 1000)
      {
         m_Fps = m_FpsFrameCount;
         m_FpsFrameCount = 0;
         m_FpsLastTime = timeNow;
      }
   }

   m_FpsFrameCount++;
}

int Helpers::GetFramesPerSecond()
{
   return m_Fps;
}

// TODO: make a function to get current path to avoid this nonsense 
#include <cell/fs/cell_fs_file_api.h>
#include <sys/moduleexport.h>
extern SceModuleInfo __psp_moduleinfo;

void Helpers::TakeScreenshot()
{
   uint64_t timeNow = get_time_now();
   if ((timeNow - m_ScreenshotLastTime) < 500)
      return;

   m_ScreenshotLastTime = timeNow;

   if (vsh::GetCooperationMode() == vsh::XmbMode)
   {
      if (!system_plugin)
         return;

      vsh::system_plugin_interface* sys_interface = system_plugin->GetInterface<vsh::system_plugin_interface*>(1);
      if (!sys_interface)
         return;

      // Create directory if it doens't exist
      cellFsMkdir("/dev_hdd0/plugins", 40777);

      std::string modulePath = "/dev_hdd0/plugins/" + std::string(__psp_moduleinfo.modname);
      cellFsMkdir(modulePath.c_str(), 40777);
      std::string screenshotPath = "/dev_hdd0/plugins/" + std::string(__psp_moduleinfo.modname) + "/Screenshots";
      cellFsMkdir(screenshotPath.c_str(), 40777);

      time_t rawtime;
      vsh::time(&rawtime);
      struct tm* timeinfo = vsh::localtime(&rawtime);

      char datestr[80];
      vsh::strftime(datestr, sizeof(datestr), "%Y-%m-%d_%H-%M-%S", timeinfo);

      char screenshotName[0x80];
      vsh::snprintf(screenshotName, sizeof(screenshotName),
         "/dev_hdd0/plugins/%s/Screenshots/%s.bmp",
         __psp_moduleinfo.modname, datestr);

      sys_interface->saveBMP(screenshotName);

      wchar_t buffer[0xA0];
      vsh::swprintf(buffer, 0xA0, L"Screenshot saved in: %s", screenshotName);
      vsh::ShowButtonNavigationMessage(buffer);
   }
   else
      vsh::ShowButtonNavigationMessage(L"Not supported in game");
}