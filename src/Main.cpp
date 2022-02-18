#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <cell/pad.h>
#include "Util/NewDeleteOverride.hpp"
#include "Util/SystemCalls.hpp"
#include "Util/Timers.hpp"
#include "Helpers.hpp"
#include "Hooking.hpp"

SYS_MODULE_INFO(RouLetteVshMenu, 0, 1, 1);
SYS_MODULE_START(RouLetteVshMenu_Main);
SYS_MODULE_STOP(RouLetteVshMenu_Stop);


/***
* 
* PS Vita Vsh Menu, they hook into sceDisplaySetFrameBuf to draw text
* https://github.com/joel16/PSV-VSH-Menu/blob/master/source/vsh.c
* 
* 
* TODO:
* Smoother closing animation
* 
*/ 

sys_ppu_thread_t gVshMenuPpuThreadId = SYS_PPU_THREAD_ID_INVALID;

CDECL_BEGIN
int RouLetteVshMenu_Main(unsigned int args, void* argp)
{
   sys_ppu_thread_create(&gVshMenuPpuThreadId, [](uint64_t arg)
   {
      g_Helpers = Helpers();
      g_Menu = Menu(MainSubmenu);

      HookingInitiate();

      sys_ppu_thread_exit(0);

   }, 0, 1057, 4096, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteVshMenu");

   // Exit thread using directly the syscall and not the user mode library or else we will crash
   _sys_ppu_thread_exit(0);

   return 0;
}

int RouLetteVshMenu_Stop(unsigned int args, void* argp)
{
   sys_ppu_thread_t stopPpuThreadId;
   int ret = sys_ppu_thread_create(&stopPpuThreadId, [](uint64_t arg)
   {
      HookingRemoveAll();

      g_Menu.ShutDown();

      // Prevent unload too fast (give time to other threads to finish)
      sys_ppu_thread_yield();
      sys_timer_sleep(2);

      uint64_t exitCode;
      sys_ppu_thread_join(gVshMenuPpuThreadId, &exitCode);

      sys_ppu_thread_exit(0);
   },
   0, 2816, 2048, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteVshMenuStop");

   uint64_t exitCode;
   if (ret == SUCCEEDED) 
      sys_ppu_thread_join(stopPpuThreadId, &exitCode);

   sys_timer_usleep(5000);

   // Exit thread using directly the syscall and not the user mode library or else we will crash
   _sys_ppu_thread_exit(0);

   return 0;
}
CDECL_END