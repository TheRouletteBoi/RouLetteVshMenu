#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <cell/pad.h>
#include "Utils/NewDeleteOverride.hpp"
#include "Utils/SystemCalls.hpp"
#include "Utils/Timers.hpp"
#include "Core/Input.hpp"
#include "Core/Menu/Submenus.hpp"
#include "Core/Menu/Overlay.hpp"
#include "Core/Hooks.hpp"
#include "Games/FindActiveGame.hpp"

// Macros defining our module informations as well as our entry/exit point
SYS_MODULE_INFO(RouLetteVshMenu, 0, 1, 1);
SYS_MODULE_START(module_start);
SYS_MODULE_STOP(module_stop);


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
* you can check if module is loaded into process by using the ps3mapi functions. use it to check if sprx is loaded into game for patching
* 
* 
* 
* ----------------------
* DEBUG
* ----------------------
* DrawText(void* unk const std::wstring& text, void*, void*, 0x40, 0, 0, size_t stringLen); // DrawTextSymbol
* paf_BE04476B(paf::PhFont::GlyphType, paf::SurfaceRCPtr<paf::Surface> &, int, int, wchar_t const*, unsigned int, paf::PhFont const&, paf::PhTextLetterSpace const*);
*
* FindLoadedPlugin();
* FindWidget();
* LoadRCOTexture();
* paf_8ABAE2F3();
* paf_7F0930C6();
* plugin_GetInterface();
* paf_2CBA5A33();
* PlayRCOSound();
* paf_EAA28B8();
* paf_85D1D23B();
* paf_0C74837D();
* paf_CC51D56();
* paf_C9826818();
* paf_4192B349();
*
* vshcommon_F1918912(); // notification?
*
* vshnet_FC7303C5(); // sceNpGetNpId
* 
*/ 

sys_ppu_thread_t gVshMenuPpuThreadId = SYS_PPU_THREAD_ID_INVALID;

CDECL_BEGIN
int module_start(unsigned int args, void* argp)
{
   sys_ppu_thread_create(&gVshMenuPpuThreadId, [](uint64_t arg) -> void
   {
      g_Input = CInput();
      g_Render = Render();
      g_Helpers = Helpers();
      g_Menu = Menu(MainSubmenu);
      g_Overlay = Overlay();
      g_FindActiveGame = CFindActiveGame();

      InstallHooks();

      sys_ppu_thread_exit(0);

   }, 0, 1059, 4096, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteVshMenuStart");

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
      g_FindActiveGame.ShutDown();
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
   0, 2816, 1024, SYS_PPU_THREAD_CREATE_JOINABLE, "RouLetteVshMenuStop");

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