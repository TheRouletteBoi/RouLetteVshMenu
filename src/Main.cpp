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
#include "Games/FindActiveGame.hpp"

SYS_MODULE_INFO(RouLetteVshMenu, 0, 1, 1);
SYS_MODULE_START(RouLetteVshMenu_Main);
SYS_MODULE_STOP(RouLetteVshMenu_Stop);


/***
* 
* PS Vita Vsh Menu, they hook into sceDisplaySetFrameBuf to draw text. This will allow drawing in XMB and In Game if done on PS3
* https://github.com/joel16/PSV-VSH-Menu/blob/master/source/vsh.c
* 
* 
* TODO:
* Enhancement: Smoother closing animation
* BUG: When there are 20 options and you scroll to the bottom then close the menu and open it again the highlight bar is out of bounds
* BUG: We need a way to clear textures just like text because they are still visible after leaving the submenu with toggle's
* BUG: Closing the menu destroy's FPS counter and or Any Helper Drawing
* BUG: Menu stretches when in game XMB
* MISSING PARTS: to load a enstone menu you need to load the RouLetteVshMenu in game using webman. the reason is because the ccapi vsh enables ccapi syscall 0x123 (Enable CCAPI). To solve this we need to enable it ourselfs 
* Enhancement: Find a way to load eboot alongside it's own sprx (kernel -> load_process)
* Enhancement: add LUA scripting support
* Enhancement: add config to load your favorite menu
* 
*/ 

sys_ppu_thread_t gVshMenuPpuThreadId = SYS_PPU_THREAD_ID_INVALID;

CDECL_BEGIN
int RouLetteVshMenu_Main(unsigned int args, void* argp)
{
   sys_ppu_thread_create(&gVshMenuPpuThreadId, [](uint64_t arg)
   {
      // prevent crashing when both vsh menu and ccapi menu are loaded
      uint32_t ccapiDetourSysio_3733EA3C = ImportExportHook::FindExportByName("sys_io", 0x3733EA3C)->func + 0x0C;
      uint32_t ccapiDetourPaf_85D1D23B = ImportExportHook::FindExportByName("paf", 0x85D1D23B)->func + 0x14;
      uint32_t sysio_3733EA3C_default = 0xF8010080;
      uint32_t paf_85D1D23B_default = 0xF80100D0;
      WriteProcessMemory(sys_process_getpid(), (void*)ccapiDetourSysio_3733EA3C, &sysio_3733EA3C_default, sizeof(sysio_3733EA3C_default));
      WriteProcessMemory(sys_process_getpid(), (void*)ccapiDetourPaf_85D1D23B, &paf_85D1D23B_default, sizeof(paf_85D1D23B_default));

      g_Helpers = Helpers();
      g_Menu = Menu(MainSubmenu);
      g_FindActiveGame = CFindActiveGame();

      HookingInitiate();
      g_FindActiveGame.Initialize();

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
      g_FindActiveGame.ShutDown();

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