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
   Lv2LabelUpdate();
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
   std::wstring overlayText = L"";
   wchar_t buffer[300]{};

   if (showFPS)
   {
       vsh::swprintf(buffer, 20, L"FPS: %.2f\n", m_FPS);
       overlayText += buffer;
   }

   if (showCpuGpuTemps)
   {
       uint64_t timeNow = GetTimeNow();
       if (timeNow - m_TemperatureCycleTime > 5000)
       {
           cycleTempType ^= 1;
           m_TemperatureCycleTime = timeNow;
       }

       vsh::swprintf(buffer, 50, L"CPU: %.0f%s / GPU: %.0f%s\n",
           m_CPUTemp, tempType == TempType::Fahrenheit ? "\u2109" : "\u2103",
           m_GPUTemp, tempType == TempType::Fahrenheit ? "\u2109" : "\u2103");
       overlayText += buffer;
   }

   if (showCpuGpuClock && m_GpuClock != 0)
   {
       vsh::swprintf(buffer, 50, L"CPU Clock: %d MHz / GPU Clock: %d MHz\n", m_CpuClock, m_GpuClock);
       overlayText += buffer;
   }

   if (showRAM)
   {
       vsh::swprintf(buffer, 50, L"RAM: %.0f%% / %i KB Used\n", m_MemoryUsage.percent, m_MemoryUsage.used);
       overlayText += buffer;
   }

   if (showFanSpeed)
   {
       vsh::swprintf(buffer, 50, L"Fan speed: %.0f%%\n", m_FanSpeed);
       overlayText += buffer;
   }

   if (showFirmware)
   {
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

       vsh::swprintf(buffer, 50, L"Firmware: %d.%d%d %s %s\n",
           (m_FirmwareVersion & 0xFF000000) >> 24, (m_FirmwareVersion & 0xFF0000) >> 16, ((m_FirmwareVersion & 0xFF00) >> 8) >> 4,
           kernelName.c_str(), 
           m_PayloadVersion == 0 ? "" : payloadType);
       overlayText += buffer;
   }

   vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
   if (showAppName && gamePlugin)
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

uint32_t Overlay::GetGpuClockSpeed()
{
    if (!IsConsoleDex())
        return 0;

    uint64_t frequency = PeekLv1(m_GpuDisplayClockSpeedOffsetInLv1);

    if (frequency == 0xFFFFFFFF80010003) // if cfw syscalls are disabled 
        return 0;

    return (static_cast<uint32_t>(frequency >> 32) / 0xF4240) & 0x1FFF;

    // Get the secondary clock speed
    /*uint64_t v7 = frequency;
    uint64_t v4 = frequency;
    uint32_t v11 = v7 / 0xF4240;
    uint32_t v10 = (0x431BDE83 * v7) >> 32;
    if ((v4 - 100) <= 7 && v11 > 0x31F)
        v11 = v10 >> 19;

    uint32_t gpuClock2 = v11 & 0x1FFF;
    return gpuClock2;*/
}

void Overlay::Lv2LabelUpdate()
{
    if (m_Lv2Label.empty())
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
        m_Lv2Label,
        vsh::vec2(vsh::paf::PhWidget::GetViewportWidth() / 2 - m_SafeArea.x - 5, vsh::paf::PhWidget::GetViewportHeight() / 2 - m_SafeArea.y - 100),
        m_SizeText,
        Render::Align::Right,
        Render::Align::Top,
        m_ColorText);
}

void Overlay::WaitAndQueueTextInLV2()
{
    const int size = MAX_LV2_STRING_SIZE / sizeof(uint64_t);
    char text[size][8]{};
    vsh::memset(text, 0, sizeof(text));

    for (uint64_t i = 0; i < size; i++)
    {
        uint64_t bytes = PeekLv2(m_NotificationOffsetInLv2 + (i * sizeof(uint64_t)));

        if (bytes == 0xFFFFFFFF80010003) // if cfw syscalls are disabled 
            goto clear_text;

        if (bytes != 0)
            vsh::memcpy(text[i], &bytes, sizeof(uint64_t));
    }

    // force null terminator
    text[size - 1][8 - 1] = 0;

    // check if string is not empty
    if (text[0] != 0 && text[0][0] != '\0')
        m_Lv2Label = reinterpret_cast<char*>(text);
    else
    {
    clear_text:
        if (!m_Lv2Label.empty())
            m_Lv2Label.clear();
    }
}

void Overlay::UpdateInfoThread(uint64_t arg)
{
   g_Overlay.m_StateRunning = true;

   while (g_Overlay.m_StateRunning)
   {
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

      g_Overlay.WaitAndQueueTextInLV2();

      g_Overlay.m_CpuClock = 0;
      g_Overlay.m_GpuClock = g_Overlay.GetGpuClockSpeed();
   }

   sys_ppu_thread_exit(0);
}