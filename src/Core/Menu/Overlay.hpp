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
   Overlay();

   void OnUpdate();
   void OnShutdown();

private:
   void DrawOverlay();
   void CalculateFps();
   void GetGameName(char outTitleId[16], char outTitleName[64]);
   static void UpdateInfoThread(uint64_t arg);

public:
   sys_ppu_thread_t UpdateInfoThreadId = SYS_PPU_THREAD_ID_INVALID;
   bool m_StateRunning{};
   float m_CPUTemp{};
   float m_GPUTemp{};
   float m_FanSpeed{};
   memUsage_s m_MemoryUsage{};
   uint64_t m_KernelType{};
   uint32_t m_FirmwareVersion{};
   uint16_t m_PayloadVersion{};

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
};

extern Overlay g_Overlay;