#include "Hooks.hpp"
#include "Menu/Base.hpp"
#include "Menu/Overlay.hpp"
#include <vsh/stdc.h>
#include <cell/pad/pad_codes.h>

ImportExportDetour* pafFrameworkUpdateHk;
ImportExportDetour* cellPadGetDataExtra0Hk;

void pafFrameworkUpdateHook(void* framework, float frameTime)
{
   pafFrameworkUpdateHk->GetOriginal<void>(framework, frameTime);

   g_Helpers.OnUpdate();
   g_Render.OnUpdate();
   g_Overlay.OnUpdate();
   g_Menu.OnUpdate();
}

int cellPadGetDataExtra0Hook(unsigned int port, unsigned int deviceType, CellPadData* data)
{
   if (port != 0)
      return cellPadGetDataExtra0Hk->GetOriginal<int>(port, deviceType, data);

   int returnValue = cellPadGetDataExtra0Hk->GetOriginal<int>(port, deviceType, g_Input.GetInputData());
   vsh::memcpy(data, g_Input.GetInputData(), sizeof(CellPadData));

   if (g_Menu.IsOpened())
   {
      // Clear button flags
      data->button[CELL_PAD_BTN_OFFSET_DIGITAL1] &= ~(CELL_PAD_CTRL_LEFT | CELL_PAD_CTRL_DOWN | CELL_PAD_CTRL_RIGHT | CELL_PAD_CTRL_UP);
      data->button[CELL_PAD_BTN_OFFSET_DIGITAL2] &= ~(CELL_PAD_CTRL_CROSS | CELL_PAD_CTRL_CIRCLE);

      if (g_Menu.IsMoving())
      {
         // Clear analog values
         data->button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_X] = 128;
         data->button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_Y] = 128;
      }
   }

   return returnValue;
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

   pafFrameworkUpdateHk = new ImportExportDetour(ImportExportDetour::Export, "paf", 0x85D1D23B, (uintptr_t)pafFrameworkUpdateHook);
   cellPadGetDataExtra0Hk = new ImportExportDetour(ImportExportDetour::Export, "sys_io", 0x3733EA3C, (uintptr_t)cellPadGetDataExtra0Hook);
}

void RemoveHooks()
{
   delete pafFrameworkUpdateHk;
   delete cellPadGetDataExtra0Hk;
}