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
   NotificationUpdate();
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


   uint64_t timeNow = GetTimeNow();
   if (timeNow - m_TemperatureCycleTime > 5000)
   {
       cycleTempType ^= 1;
       m_TemperatureCycleTime = timeNow;
   }

   vsh::swprintf(buffer, 150, 
       L"FPS: %.2f\nCPU: %.0f%s / GPU: %.0f%s\nRAM: %.0f%% / %i KB Used\nFan speed: %.0f%%\nFirmware: %d.%d%d %s %s\n",
       m_FPS, 
       m_CPUTemp, tempType == TempType::Fahrenheit ? "\u2109" : "\u2103",
       m_GPUTemp, tempType == TempType::Fahrenheit ? "\u2109" : "\u2103",
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
      vsh::vec2(-vsh::paf::PhWidget::GetViewportWidth() / 2 + m_SafeArea.x + 5, vsh::paf::PhWidget::GetViewportHeight() / 2 - m_SafeArea.y - 5),
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

void Overlay::Notify(const std::string& text)
{
    Lv2Notification notification;
    notification.text = text;
    notification.timeToClear = GetTimeNow() + 5500;
    m_NotificationQueue.push(notification);

    // Clear string in LV2 because it is now stored in the queue
    const int size = MAX_LV2_STRING_SIZE / sizeof(uint64_t);
    for (uint64_t i = 0; i < size; i++)
        ps3mapi_lv2_poke(0x8000000000000000 + (i * sizeof(uint64_t)), 0x0000000000000000);
}

void Overlay::NotificationUpdate()
{
    if (m_NotificationQueue.empty())
        return;

    /* 
    float textWrap = paf_6941C365();
    int lineCount = GetLineCount();
    float textHeight = GetTextHeight();
    float rectangleHeight = (static_cast<float>(lineCount) * textHeight);
    g_Render.Rectangle(
        vsh::vec2(vsh::paf::PhWidget::GetViewportWidth() / 2 - m_SafeArea.x - 5, vsh::paf::PhWidget::GetViewportHeight() / 2 - m_SafeArea.y - 100),
        notificationWidth,
        rectangleHeight);*/

    g_Render.Text(
        m_NotificationQueue.front().text,
        vsh::vec2(vsh::paf::PhWidget::GetViewportWidth() / 2 - m_SafeArea.x - 5, vsh::paf::PhWidget::GetViewportHeight() / 2 - m_SafeArea.y - 100),
        m_SizeText,
        Render::Align::Right,
        Render::Align::Top,
        m_ColorText);

    // Clear notification after 5 seconds
    if (GetTimeNow() > m_NotificationQueue.front().timeToClear)
        m_NotificationQueue.pop();
}

void Overlay::WaitForTextInLV2Update()
{
    const int size = MAX_LV2_STRING_SIZE / sizeof(uint64_t);
    char text[size][sizeof(uint64_t)]{};
    for (uint64_t i = 0; i < size; i++)
    {
        uint64_t bytes = ps3mapi_lv2_peek(0x8000000000000000 + (i * sizeof(uint64_t)));

        if (bytes != 0)
            vsh::memcpy(text[i], &bytes, sizeof(uint64_t));
    }

    // force null terminator
    text[size - 1][8 - 1] = 0;

    // check if string is not empty
    if (text[0] != 0 && text[0][0] != '\0')
        Notify(reinterpret_cast<char*>(text));
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

      if (g_Overlay.cycleTempType)
      {
          g_Overlay.m_CPUTemp = GetTemperatureFahrenheit(0);
          g_Overlay.m_GPUTemp = GetTemperatureFahrenheit(1);
          g_Overlay.tempType = TempType::Fahrenheit;
      }
      else
      {
          g_Overlay.m_CPUTemp = GetTemperatureCelsius(0);
          g_Overlay.m_GPUTemp = GetTemperatureCelsius(1);
          g_Overlay.tempType = TempType::Celsius;
      }

      int ret = get_target_type(&g_Overlay.m_KernelType);
      if (ret != SUCCEEDED)
          g_Overlay.m_KernelType = 0;

      platform_info_t info;
      lv2_get_platform_info(&info);
      g_Overlay.m_FirmwareVersion = info.firmware_version;

      g_Overlay.m_PayloadVersion = GetPayloadVersion();

      g_Overlay.WaitForTextInLV2Update();
   }

   sys_ppu_thread_exit(0);
}