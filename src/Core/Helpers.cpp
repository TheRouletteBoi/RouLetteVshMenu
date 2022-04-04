#include "Helpers.hpp"

Helpers g_Helpers;

Helpers::Helpers()
{
   m_IsHen = IsConsoleHen();
}

void Helpers::OnUpdate()
{
   // Update plugins and widgets pointers
   system_plugin = vsh::paf::View::Find("system_plugin");
   game_plugin = vsh::paf::View::Find("game_plugin");
   game_ext_plugin = vsh::paf::View::Find("game_ext_plugin");

   page_autooff_guide = system_plugin ? system_plugin->FindWidget("page_autooff_guide") : nullptr;


   MonitorGameState();

#ifdef DEBUG
   if (g_Input.IsButtonBinds(CInput::BUTTON_L1, CInput::BUTTON_PAD_UP))
       TakeScreenshot();
#endif // DEBUG
}

void Helpers::MonitorGameState()
{
   // Detect game launch 
   if (vsh::GetCooperationMode() != vsh::eCooperationMode::XMB && !m_StateGameRunning)
   {
      m_StateGameRunning = true;
      m_StateGameJustLaunched = true;
   }
   else if (vsh::GetCooperationMode() == vsh::eCooperationMode::XMB)
      m_StateGameRunning = false;
}

void Helpers::TakeScreenshot()
{
   unsigned int timeNow = GetTimeNow();

   if ((timeNow - m_ScreenshotLastTime) < 500)
      return;

   m_ScreenshotLastTime = timeNow;

   if (vsh::GetCooperationMode() == vsh::eCooperationMode::XMB)
   {
      if (!system_plugin)
         return;

      vsh::system_plugin_interface* system_interface = system_plugin->GetInterface<vsh::system_plugin_interface*>(1);
      if (!system_interface)
         return;

      std::string screenshotPath = GetCurrentDir() + "Screenshots";
      vsh::mkdir(screenshotPath.c_str(), 40777);

      time_t rawtime;
      vsh::time(&rawtime);
      tm* timeinfo = vsh::localtime(&rawtime);

      char datestr[100];
      vsh::strftime(datestr, 100, "%Y-%m-%d_%H-%M-%S", timeinfo);

      std::string screenshotName = screenshotPath + "/" + datestr + ".bmp";

      system_interface->saveBMP(screenshotName.c_str());

      wchar_t buffer[130];
      vsh::swprintf(buffer, 0xA0, L"Screenshot saved as: %s", screenshotName.c_str());
      vsh::ShowButtonNavigationMessage(buffer);
   }
   else
      vsh::ShowButtonNavigationMessage(L"Not supported in game");
}