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
   xmb_plugin = vsh::paf::View::Find("xmb_plugin");

   page_autooff_guide = system_plugin ? system_plugin->FindWidget("page_autooff_guide") : nullptr;


   MonitorGameState();

#ifdef LAUNCHER_DEBUG
   if (g_Input.IsButtonBinds(Input::BUTTON_L1, Input::BUTTON_PAD_UP))
       TakeScreenshot();
#endif // LAUNCHER_DEBUG
}

void Helpers::MonitorGameState()
{
    //uint64_t timeNow = GetTimeNow();

   // Detect game launch 
   if (vsh::GetCooperationMode() != vsh::eCooperationMode::XMB && !m_StateGameRunning)
   {
      m_StateGameRunning = true;
      m_StateGameJustLaunched = true;
      //m_GameLaunchTime = timeNow;
   }
   else if (vsh::GetCooperationMode() == vsh::eCooperationMode::XMB)
      m_StateGameRunning = false;

   //if (timeNow - m_GameLaunchTime > 15 * 1000)
   //    m_StateGameJustLaunched = false;
}

void Helpers::TakeScreenshot()
{
   uint64_t timeNow = GetTimeNow();

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
      vsh::strftime(datestr, sizeof(datestr), "%Y-%m-%d_%H-%M-%S", timeinfo);

      std::string screenshotName = screenshotPath + "/" + datestr + ".bmp";

      system_interface->saveBMP(screenshotName.c_str());

      wchar_t buffer[130];
      vsh::swprintf(buffer, sizeof(buffer), L"Screenshot saved as: %s", screenshotName.c_str());
      vsh::ShowButtonNavigationMessage(buffer);
   }
   else
      vsh::ShowButtonNavigationMessage(L"Screenshots aren't supported in game");
}