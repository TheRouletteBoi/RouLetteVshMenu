#include "Hooks.hpp"
#include "Menu/Overlay.hpp"
#include <vsh/stdc.h>
#include <cell/pad/pad_codes.h>

ImportExportDetour* pafFrameworkRenderHk;

void pafFrameworkRenderHook(void* framework, float frameTime)
{
   pafFrameworkRenderHk->GetOriginal<void>(framework, frameTime);

   g_Helpers.OnUpdate();
   g_Render.OnUpdate();
   g_Overlay.OnUpdate();
}

void InstallHooks()
{
   pafFrameworkRenderHk = new ImportExportDetour(ImportExportDetour::Export, "paf", 0x85D1D23B, (uintptr_t)pafFrameworkRenderHook);
}

void RemoveHooks()
{
   delete pafFrameworkRenderHk;
}