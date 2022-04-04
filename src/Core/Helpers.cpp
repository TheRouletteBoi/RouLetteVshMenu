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

#ifdef LAUNCHER_DEBUG
   if (g_Input.IsButtonBinds(CInput::BUTTON_L1, CInput::BUTTON_PAD_UP))
       TakeScreenshot();
#endif // LAUNCHER_DEBUG
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