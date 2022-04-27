#include "Overlay.hpp"
#include "Memory/Pattern.hpp"

Overlay g_Overlay;

Overlay::Overlay()
{
    sys_ppu_thread_create(&LoadExternalOffsetsThreadId, LoadExternalOffsets, 0, 0xB02, 512, SYS_PPU_THREAD_CREATE_JOINABLE, "Overlay::LoadExternalOffsets()");

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
      Sleep(refreshDelay * 1000 + 500);

      uint64_t exitCode;
      sys_ppu_thread_join(UpdateInfoThreadId, &exitCode);
   }
}

void Overlay::DrawOverlay()
{
   std::wstring overlayText;

   if (showFPS)
   {
       overlayText += L"FPS: " + to_wstring(m_FPS, 2) + L"\n";
   }

   if (showCpuGpuTemps)
   {
       std::wstring tempTypeStr = tempType == TempType::Fahrenheit ? L"\u2109" : L"\u2103";
       overlayText += L"CPU: " + to_wstring(m_CPUTemp) + tempTypeStr 
           + L" / GPU: " + to_wstring(m_GPUTemp) + tempTypeStr 
           + L"\n";
   }

   if (showClockSpeeds && m_GpuGddr3RamClock != 0)
   {
       overlayText += L"CPU Clock: " + to_wstring(m_CpuClock / 1000.0f, 1) + L" GHz\n";
       overlayText += L"GPU Clock: " + to_wstring(m_GpuClock) + L" MHz\n";
       overlayText += L"GDDR3 RAM Clock: " + to_wstring(m_GpuGddr3RamClock) + L" MHz\n";
   }

   /*if (showRAM)
   {
       overlayText += L"RAM: " + to_wstring(m_MemoryUsage.percent, 1) 
           + L"% " + to_wstring(m_MemoryUsage.used, 1) 
           + L" / " + to_wstring(m_MemoryUsage.total, 1) 
           + L" MB" 
           + L"\n";
   }*/

   if (showFanSpeed)
   {
       overlayText += L"Fan speed: " 
           + to_wstring(m_FanSpeed) 
           + L"%\n";
   }

   if (showFirmware)
   {
       std::wstring kernelName;
       switch (m_KernelType)
       {
           case 1: kernelName = L"CEX"; break;
           case 2: kernelName = L"DEX"; break;
           case 3: kernelName = L"DEH"; break;
           default: kernelName = L"N/A";  break;
       }

       std::wstring payloadName = IsConsoleHen() ? L"PS3HEN" : IsConsoleMamba() ? L"Mamba" : L"Cobra";
       std::wstring payloadStr = m_PayloadVersion == 0 ? L"" : payloadName;
       std::wstring payloadVerStr = m_PayloadVersion == 0 ? 
           L"" : 
           to_wstring(m_PayloadVersion >> 8) 
           + L"."
           + to_wstring((m_PayloadVersion & 0xF0) >> 4)
           + to_wstring(m_PayloadVersion & 0xF);

       overlayText += to_wstring(m_FirmwareVersion, 2) 
           + L" " + kernelName 
           + L" " + payloadStr 
           + L" " + payloadVerStr
           + L"\n";
   }

   vsh::paf::View* gamePlugin = vsh::paf::View::Find("game_plugin");
   if (showAppName && gamePlugin)
   {
       char gameTitleId[16]{};
       char gameTitleName[64]{};
       GetGameName(gameTitleId, gameTitleName);

       wchar_t appName[100]{};
       vsh::swprintf(appName, sizeof(appName), L"%s / %s\n", gameTitleName, gameTitleId);
       overlayText += appName;
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
    if (IsConsoleHen())
        return 0;

    if (!m_GpuClockSpeedOffsetInLv1)
        return 0;

    uint64_t frequency = PeekLv1(m_GpuClockSpeedOffsetInLv1);

    if (frequency == 0xFFFFFFFF80010003) // if cfw syscalls are disabled 
        return 0;

    return (static_cast<uint32_t>(frequency >> 32) / 0xF4240) & 0x1FFF;
}

uint32_t Overlay::GetGpuGddr3RamClockSpeed()
{
    if (IsConsoleHen())
        return 0;

    if (!m_GpuGddr3RamClockSpeedOffsetInLv1)
        return 0;

    uint64_t frequency = PeekLv1(m_GpuGddr3RamClockSpeedOffsetInLv1);

    if (frequency == 0xFFFFFFFF80010003) // if cfw syscalls are disabled 
        return 0;

    return (static_cast<uint32_t>(frequency >> 32) / 0xF4240) & 0x1FFF;

    // Get display clock speed
    /*uint64_t v7 = frequency;
    uint64_t v4 = frequency;
    uint32_t v11 = v7 / 0xF4240;
    uint32_t v10 = (0x431BDE83 * v7) >> 32;
    if ((v4 - 100) <= 7 && v11 > 0x31F)
        v11 = v10 >> 19;

    uint32_t gddr3RamClock = v11 & 0x1FFF;
    return gddr3RamClock;*/
}

uint32_t Overlay::GetCpuClockSpeed()
{
    if (IsConsoleHen())
        return 0;

    if (!m_CpuClockSpeedOffsetInLv1)
        return 0;

    uint64_t frequency = PeekLv1(m_CpuClockSpeedOffsetInLv1);

    if (frequency == 0xFFFFFFFF80010003) // if cfw syscalls are disabled 
        return 0;

    return ((static_cast<uint32_t>(frequency >> 32) / 0xF4240) & 0x1FFF) * 8;
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
    const int size = MAX_LV2_STRING_SIZE / 8;
    char text[size][8]{};
    vsh::memset(text, 0, sizeof(text));

    for (uint64_t i = 0; i < size; i++)
    {
        uint64_t bytes = PeekLv2(m_NotificationOffsetInLv2 + (i * 8));

        if (bytes == 0xFFFFFFFF80010003) // if cfw syscalls are disabled 
            goto clear_text;

        if (bytes != 0)
            vsh::memcpy(text[i], &bytes, 8);
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

      if (g_Overlay.m_CycleTemperatureType)
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

      uint64_t timeNow = GetTimeNow();
      if (timeNow - g_Overlay.m_TemperatureCycleTime > 5000)
      {
          g_Overlay.m_CycleTemperatureType ^= 1;
          g_Overlay.m_TemperatureCycleTime = timeNow;
      }

      int ret = get_target_type(&g_Overlay.m_KernelType);
      if (ret != SUCCEEDED)
          g_Overlay.m_KernelType = 0;

      g_Overlay.m_FirmwareVersion = GetFirmwareVersion();

      g_Overlay.m_PayloadVersion = GetPayloadVersion();

      g_Overlay.m_CpuClock = g_Overlay.GetCpuClockSpeed();
      g_Overlay.m_GpuClock = g_Overlay.GetGpuClockSpeed();
      g_Overlay.m_GpuGddr3RamClock = g_Overlay.GetGpuGddr3RamClockSpeed();

      g_Overlay.WaitAndQueueTextInLV2();
   }

   sys_ppu_thread_exit(0);
}

void Overlay::LoadExternalOffsets(uint64_t arg)
{
    uint32_t addr = FindPatternHypervisor(
        "be.0.ref_clk",
        vsh::strlen("be.0.ref_clk"),
        "be.0.ref_clk");
    g_Overlay.m_CpuClockSpeedOffsetInLv1 = addr + 0x24;

    addr = FindPatternHypervisor(
        "\x00\x00\x00\x01\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x40\x28\x00\x00\x40\x2C",
        20,
        "???x???x???x??xx??xx");
    g_Overlay.m_GpuClockSpeedOffsetInLv1 = addr + 0x14;

    addr = FindPatternHypervisor(
        "\x00\x00\x00\x05\x00\x00\x00\x03\x00\x00\x00\x06\x00\x00\x40\x10\x00\x00\x40\x14",
        20,
        "???x???x???x??xx??xx");
    g_Overlay.m_GpuGddr3RamClockSpeedOffsetInLv1 = addr + 0x14;

    sys_ppu_thread_exit(0);
}