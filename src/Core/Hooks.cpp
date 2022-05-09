#include "Hooks.hpp"
#include "Overlay.hpp"
#include <vsh/stdc.h>
#include <cell/pad/pad_codes.h>

ImportExportDetour* pafFrameworkBeginHk;

void pafFrameworkBeginHook(void* framework, float frameTime)
{
   pafFrameworkBeginHk->GetOriginal<void>(framework, frameTime);

   g_Helpers.OnUpdate();
   g_Render.OnUpdate();
   g_Overlay.OnUpdate();
}

void InstallHooks()
{
    pafFrameworkBeginHk = new ImportExportDetour(ImportExportDetour::Export, "paf", 0x59BDA198, (uintptr_t)pafFrameworkBeginHook);
}

void RemoveHooks()
{
   delete pafFrameworkBeginHk;
}