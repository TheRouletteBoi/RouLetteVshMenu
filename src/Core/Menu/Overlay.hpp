#pragma once
#include <string>
#include <sys/ppu_thread.h>
#include <vsh/netctl_main.h>
#include <vsh/vshmain.h>
#include <vsh/vshcommon.h>
#include <vsh/pafView.h>
#include <vsh/explore_plugin.h>
#include <vsh/game_plugin.h>
#include "Utils/ConsoleInfo.hpp"
#include "Core/Helpers.hpp"
#include "Core/Rendering.hpp"

class Overlay
{
public:
    enum class TempType : uint8_t
    {
        Fahrenheit,
        Celsius,
    };

public:
   Overlay();

   void OnUpdate();
   void OnShutdown();
   void Lv2LabelUpdate();
   void WaitAndQueueTextInLV2();

private:
   void DrawOverlay();
   void CalculateFps();
   void GetGameName(char outTitleId[16], char outTitleName[64]);
   uint32_t GetGpuClockSpeed();
   uint32_t GetGpuGddr3RamClockSpeed();
   uint32_t GetCpuClockSpeed();
   static void UpdateInfoThread(uint64_t arg);

public:
   sys_ppu_thread_t UpdateInfoThreadId = SYS_PPU_THREAD_ID_INVALID;
   bool m_StateRunning{};
   float m_CPUTemp{};
   float m_GPUTemp{};
   float m_FanSpeed{};
   memUsage_s m_MemoryUsage{};
   uint64_t m_KernelType{};
   float m_FirmwareVersion{};
   uint16_t m_PayloadVersion{};
   uint64_t m_TemperatureCycleTime{};
   bool cycleTempType{};
   TempType tempType{};

   uint8_t displayMode{}; // XMB + IN-GAME or XMB or IN-GAME
   bool showFPS = true;
   bool showCpuGpuTemps = true;
   bool showCpuGpuClock = true;
   bool showRAM = true;
   bool showFanSpeed = true;
   bool showFirmware = true;
   bool showAppName = true;

   uint32_t m_CpuClock{};
   uint32_t m_GpuClock{};
   uint64_t m_GpuClockSpeedOffsetInLv1{};
   uint64_t m_GpuGddr3RamClockSpeedOffsetInLv1{};
   uint64_t m_CpuClockSpeedOffsetInLv1{};

private:
   vsh::vec2 m_Position{};
   vsh::vec2 m_SafeArea{ 31, 18 };
   float m_SizeText = 20;
   vsh::vec4 m_ColorText{ 1, 1, 1, 1 };
   static const int refreshDelay = 500;

   float m_FPS = 100.0f;
   float m_FpsLastTime = 0;
   int m_FpsFrames = 0;
   int m_FpsFramesLastReport = 0;
   double m_FpsTimeElapsed = 0;
   double m_FpsTimeReport = 0;
   double m_FpsTimeLastReport = 0;
   float m_FpsREPORT_TIME = 1.0f;

   static constexpr size_t MAX_LV2_STRING_SIZE = 0x80;
   std::string m_Lv2Label;
   uint64_t m_NotificationOffsetInLv2 = 0x8000000000700000;
};

extern Overlay g_Overlay;