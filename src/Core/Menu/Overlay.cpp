#include "Overlay.hpp"

Overlay g_Overlay;

Overlay::Overlay()
{
   sys_ppu_thread_create(&UpdateInfoThreadId, UpdateInfoThread, 0, 0xB01, 512, SYS_PPU_THREAD_CREATE_JOINABLE, "Overlay::UpdateInfoThread()");
}

void Overlay::OnUpdate()
{
   CalculateFps();
   DrawOverlay();
}

void Overlay::OnShutdown()
{
   if (UpdateInfoThreadId != SYS_PPU_THREAD_ID_INVALID)
   {
      m_StateRunning = false;

      sys_ppu_thread_yield();
      Sleep(refreshDelay + 500);

      uint64_t exitCode;
      sys_ppu_thread_join(UpdateInfoThreadId, &exitCode);
   }
}

void Overlay::DrawOverlay()
{
   wchar_t buffer[300]{};

   std::wstring overlayText = L"";

   std::string kernelName;
   switch (m_KernelType)
   {
      case 1: kernelName = "CEX"; break;
      case 2: kernelName = "DEX"; break;
      case 3: kernelName = "DEH"; break;
      default: kernelName = "N/A";  break;
   }

   char payloadType[64];
   vsh::snprintf(payloadType, sizeof(payloadType),
       "%s %X.%X%X",
       IsConsoleHen() ? "PS3HEN" : IsConsoleMamba() ? "Mamba" : "Cobra",
       m_PayloadVersion >> 8, (m_PayloadVersion & 0xF0) >> 4, (m_PayloadVersion & 0xF));


   vsh::swprintf(buffer, 150, 
       L"FPS: %.2f\nCPU: %.0f\u2109 / GPU: %.0f\u2109\nRAM: %.0f%% / %i KB Used\nFan speed: %.0f%%\nFirmware: %d.%d%d %s %s\n",
       m_FPS, 
       m_CPUTemp, m_GPUTemp, 
       m_MemoryUsage.percent, m_MemoryUsage.used,
       m_FanSpeed, 
       (m_FirmwareVersion & 0xFF000000) >> 24, (m_FirmwareVersion & 0xFF0000) >> 16, ((m_FirmwareVersion & 0xFF00) >> 8) >> 4,
       kernelName.c_str(), payloadType);
   overlayText += buffer;


   vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
   if (gamePlugin)
   {
       char gameTitleId[16]{};
       char gameTitleName[64]{};
       GetGameName(gameTitleId, gameTitleName);

       vsh::swprintf(buffer, 120, L"App: %s / %s\n", gameTitleName, gameTitleId);
       overlayText += buffer;
   }


   g_Render.Text(
      overlayText,
      vsh::vec2(m_Position.x = -vsh::paf::PhWidget::GetViewportWidth() / 2 + m_SafeArea.x + 5, m_Position.y = vsh::paf::PhWidget::GetViewportHeight() / 2 - m_SafeArea.y - 5),
      m_SizeText,
      Render::Align::Left,
      Render::Align::Top,
      m_ColorText);
}

void Overlay::CalculateFps()
{
   // FPS REPORTING
   // get current timing info
   float timeNow = (float)sys_time_get_system_time() * .000001f;
   float fElapsedInFrame = (float)(timeNow - m_FpsLastTime);
   m_FpsLastTime = timeNow;
   ++m_FpsFrames;
   m_FpsTimeElapsed += fElapsedInFrame;

   // report fps at appropriate interval
   if (m_FpsTimeElapsed >= m_FpsTimeReport)
   {
      m_FPS = (m_FpsFrames - m_FpsFramesLastReport) * 1.f / (float)(m_FpsTimeElapsed - m_FpsTimeLastReport);

      m_FpsTimeReport += m_FpsREPORT_TIME;
      m_FpsTimeLastReport = m_FpsTimeElapsed;
      m_FpsFramesLastReport = m_FpsFrames;
   }
}

void Overlay::GetGameName(char outTitleId[16], char outTitleName[64])
{
    vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
    if (!gamePlugin)
        return;

    vsh::game_plugin_interface* game_interface = gamePlugin->GetInterface<vsh::game_plugin_interface*>(1);
    if (!game_interface)
        return;

    char _gameInfo[0x120]{};
    game_interface->gameInfo(_gameInfo);
    vsh::snprintf(outTitleId, 10, "%s", _gameInfo + 0x04);
    vsh::snprintf(outTitleName, 63, "%s", _gameInfo + 0x14);
}

void Overlay::UpdateInfoThread(uint64_t arg)
{
   g_Overlay.m_StateRunning = true;

   while (g_Overlay.m_StateRunning)
   {
      while (!vsh::paf::View::Find("explore_plugin")) // wait until the xmb is loaded and running
         Sleep(100);

      Sleep(refreshDelay);

      // Using syscalls in a loop on hen will cause a black screen when launching a game
      // so in order to fix this we need to sleep 10/15 seconds when a game is launched
      if (g_Helpers.m_StateGameJustLaunched)
      {
         Sleep(15 * 1000);
         g_Helpers.m_StateGameJustLaunched = false;
      }

      g_Overlay.m_MemoryUsage = GetMemoryUsage();
      g_Overlay.m_FanSpeed = GetFanSpeed();

      g_Overlay.m_CPUTemp = GetTemperatureFahrenheit(0);
      g_Overlay.m_GPUTemp = GetTemperatureFahrenheit(1);

      int ret = get_target_type(&g_Overlay.m_KernelType);
      if (ret != SUCCEEDED)
          g_Overlay.m_KernelType = 0;

      platform_info_t info;
      lv2_get_platform_info(&info);
      g_Overlay.m_FirmwareVersion = info.firmware_version;

      g_Overlay.m_PayloadVersion = GetPayloadVersion();

   }

   sys_ppu_thread_exit(0);
}