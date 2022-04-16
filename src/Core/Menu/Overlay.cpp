#include "Overlay.hpp"
#include "Games/FindActiveGame.hpp"

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
      Sleep(refreshDelay * 1000 + 500);

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
       L"FPS: %.2f\nCPU: %.0f\u2109 / GPU: %.0f\u2109\nRAM: %.1f%% %.1f / %.1f MB\nFan speed: %.0f%%\nFirmware: %1.2f %s %s\n",
       m_FPS, 
       m_CPUTemp, m_GPUTemp, 
       m_MemoryUsage.percent, m_MemoryUsage.used, m_MemoryUsage.total,
       m_FanSpeed, 
       m_FirmwareVersion,
       kernelName.c_str(), payloadType);
   overlayText += buffer;


   vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
   if (gamePlugin)
   {
       char gameTitleId[16]{};
       char gameTitleName[64]{};
       g_FindActiveGame.GetGameName(gameTitleId, gameTitleName);

       vsh::swprintf(buffer, 120, L"App: %s / %s\n", gameTitleName, gameTitleId);
       overlayText += buffer;
   }


   g_Render.Text(
      overlayText,
      vsh::vec2(-vsh::paf::PhWidget::GetViewportWidth() / 2 + g_Menu.safeArea.x + 5, vsh::paf::PhWidget::GetViewportHeight() / 2 - g_Menu.safeArea.y - 5),
      g_Menu.sizeText,
      Render::Align::Left,
      Render::Align::Top,
      g_Menu.colorText);
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

void Overlay::UpdateInfoThread(uint64_t arg)
{
   g_Overlay.m_StateRunning = true;

   while (g_Overlay.m_StateRunning)
   {
      Sleep(refreshDelay * 1000);

      // Using syscalls in a loop on hen will cause a black screen when launching a game
      // so in order to fix this we need to sleep 10/15 seconds when a game is launched
      if (g_Helpers.m_StateGameJustLaunched)
      {
         Sleep(15 * 1000);
         g_Helpers.m_StateGameJustLaunched = false;
      }

      g_Overlay.m_MemoryUsage = GetMemoryUsage();
      // Convert to MB
      g_Overlay.m_MemoryUsage.total /= 1024;
      g_Overlay.m_MemoryUsage.free /= 1024;
      g_Overlay.m_MemoryUsage.used /= 1024;

      g_Overlay.m_FanSpeed = GetFanSpeed();

      g_Overlay.m_CPUTemp = GetTemperatureFahrenheit(0);
      g_Overlay.m_GPUTemp = GetTemperatureFahrenheit(1);

      int ret = get_target_type(&g_Overlay.m_KernelType);
      if (ret != SUCCEEDED)
          g_Overlay.m_KernelType = 0;

      g_Overlay.m_FirmwareVersion = GetFirmwareVersion();

      g_Overlay.m_PayloadVersion = GetPayloadVersion();

   }

   sys_ppu_thread_exit(0);
}