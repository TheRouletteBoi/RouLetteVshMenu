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

   UpdateCalculateFps();

   g_Menu.OnHelperGUI([] 
   {
      const std::wstring& fps = L"Frames per second: " + to_wstring(g_Helpers.GetFps());
      GUI::DrawText(fps, vsh::vec2(-590.0f, 310.0f), 20, vsh::vec4(1.0f, 1.0f, 1.0f, 1.0f), GUI::Alignment::Left);
   });

   if (IsButtonBinds(BUTTON_L1, BUTTON_PAD_UP))
      TakeScreenshot();
}

void Helpers::UpdateCalculateFps()
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

int Helpers::GetFps()
{
   return m_Fps;
}

void Helpers::TakeScreenshot()
{
   uint64_t timeNow = get_time_now();
   if ((timeNow - m_ScreenshotLastTime) < 500)
      return;

   m_ScreenshotLastTime = timeNow;

   if (vsh::GetCooperationMode() == vsh::eCooperationMode::XmbMode)
   {
      if (!system_plugin)
         return;

      vsh::system_plugin_interface* sys_interface = system_plugin->GetInterface<vsh::system_plugin_interface*>(1);
      if (!sys_interface)
         return;

      const std::string& screenshotPath = GetCurrentDir() + "Screenshots";
      vsh::mkdir(screenshotPath.c_str(), 40777);

      time_t rawtime;
      vsh::time(&rawtime);
      struct tm* timeinfo = vsh::localtime(&rawtime);

      char datestr[80];
      vsh::strftime(datestr, sizeof(datestr), "%Y-%m-%d_%H-%M-%S", timeinfo);

      const std::string& screenshotName = screenshotPath + "/" + datestr + ".bmp";

      sys_interface->saveBMP(screenshotName.c_str());

      wchar_t buffer[0xA0];
      vsh::swprintf(buffer, 0xA0, L"Screenshot saved in: %s", screenshotName.c_str());
      vsh::ShowButtonNavigationMessage(buffer);
   }
   else
      vsh::ShowButtonNavigationMessage(L"Not supported in game");
}