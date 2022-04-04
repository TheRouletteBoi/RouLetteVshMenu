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

void RemoveCCAPIHooks()
{
    opd_s* ccapiDetourPaf_85D1D23B = FindExportByName("paf", 0x85D1D23B);
    opd_s* ccapiDetourSysio_3733EA3C = FindExportByName("sys_io", 0x3733EA3C);

    if (ccapiDetourPaf_85D1D23B && ccapiDetourSysio_3733EA3C)
    {
        // Checks if the exports haven't been detoured by CCAPI to avoid crashing
        if (VshGetMem<uint32_t>(ccapiDetourPaf_85D1D23B->func + 0x14) != 0xF80100D0)
            VshSetMem<uint32_t>(ccapiDetourPaf_85D1D23B->func + 0x14, 0xF80100D0);

        if (VshGetMem<uint32_t>(ccapiDetourSysio_3733EA3C->func + 0x0C) != 0xF8010080) // || 0x4E800420 
            VshSetMem<uint32_t>(ccapiDetourSysio_3733EA3C->func + 0x0C, 0xF8010080);
    }
}

void InstallHooks()
{
   if (!IsConsoleHen())
      RemoveCCAPIHooks();

   pafFrameworkRenderHk = new ImportExportDetour(ImportExportDetour::Export, "paf", 0x85D1D23B, (uintptr_t)pafFrameworkRenderHook);
}

void RemoveHooks()
{
   delete pafFrameworkRenderHk;
}