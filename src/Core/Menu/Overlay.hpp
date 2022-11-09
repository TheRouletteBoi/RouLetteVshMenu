#pragma once
#include <string>
#include <sys/ppu_thread.h>
#include <vsh/netctl_main.hpp>
#include "Utils/ConsoleInfo.hpp"
#include "Core/Helpers.hpp"
#include "Core/Renderer.hpp"
#include "Core/Menu/Base.hpp"

class Overlay
{
public:
   Overlay();

   void OnUpdate();
   void OnShutdown();

private:
   void DrawOverlay();
   void CalculateFps();
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
   static const uint64_t refreshDelay = 1;

private:
   paf::vec2 m_Position{};

   float m_FPS = 100.0f;
   float m_FpsLastTime = 0;
   int m_FpsFrames = 0;
   int m_FpsFramesLastReport = 0;
   double m_FpsTimeElapsed = 0;
   double m_FpsTimeReport = 0;
   double m_FpsTimeLastReport = 0;
   float m_FpsREPORT_TIME = 1.0f;
};

extern Overlay g_Overlay;