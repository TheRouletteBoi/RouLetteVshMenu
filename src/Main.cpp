#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <cell/pad.h>
#include "Utils/NewDeleteOverride.hpp"
#include "Utils/SystemCalls.hpp"
#include "Utils/Timers.hpp"
#include "Core/Menu/Overlay.hpp"
#include "Core/Hooks.hpp"

// Macros defining our module informations as well as our entry/exit point
SYS_MODULE_INFO(RouLetteVshMenuFPS, 0, 1, 1);
SYS_MODULE_START(module_start);
SYS_MODULE_STOP(module_stop);

sys_ppu_thread_t gVshMenuPpuThreadId = SYS_PPU_THREAD_ID_INVALID;

CDECL_BEGIN
int module_start(unsigned int args, void* argp)
{
   sys_ppu_thread_create(&gVshMenuPpuThreadId, [](uint64_t arg) -> void
   {
      g_Render = Render();
      g_Helpers = Helpers();
      g_Overlay = Overlay();

      InstallHooks();

      sys_ppu_thread_exit(0);

   }, 0, 1059, 1500, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteVshMenuFPSStart");

   // Exit thread using directly the syscall and not the user mode library or else we will crash
   _sys_ppu_thread_exit(0);

   return 0;
}

int module_stop(unsigned int args, void* argp)
{
   sys_ppu_thread_t stopPpuThreadId;
   int ret = sys_ppu_thread_create(&stopPpuThreadId, [](uint64_t arg) -> void
   {
      RemoveHooks();

      g_Overlay.OnShutdown();
      g_Render.DestroyPlanesAndTexts();

      // Prevent unload too fast (give time to other threads to finish)
      sys_ppu_thread_yield();
      Sleep(1000);

      if (gVshMenuPpuThreadId != SYS_PPU_THREAD_ID_INVALID)
      {
         uint64_t exitCode;
         sys_ppu_thread_join(gVshMenuPpuThreadId, &exitCode);
      }

      sys_ppu_thread_exit(0);
   },
   0, 2816, 1024, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteVshMenuFPSStop");

   if (ret == SUCCEEDED)
   {
      uint64_t exitCode;
      sys_ppu_thread_join(stopPpuThreadId, &exitCode);
   }

   Sleep(5);

   // unloading prx from memory
   sys_prx_id_t prxId = _sys_prx_get_my_module_id();
   uint64_t meminfo[5]{ 0x28, 2, 0, 0, 0 };
   _sys_prx_stop_module(prxId, 0, meminfo, NULL, 0, NULL);

   // Exit thread using directly the syscall and not the user mode library or else we will crash
   _sys_ppu_thread_exit(0);

   return 0;
}
CDECL_END