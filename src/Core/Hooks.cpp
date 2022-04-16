#include "Hooks.hpp"
#include "Menu/Base.hpp"
#include "Menu/Overlay.hpp"
#include "Memory/Pattern.hpp"
#include <vsh/stdc.h>
#include <cell/pad/pad_codes.h>

ImportExportDetour* pafFrameworkUpdateHk;
Detour* cellPadGetDataExtraInternalHk;

void pafFrameworkUpdateHook(void* framework, float frameTime)
{
   pafFrameworkUpdateHk->GetOriginal<void>(framework, frameTime);

   g_Helpers.OnUpdate();
   g_Render.OnUpdate();
   g_Overlay.OnUpdate();
   g_Menu.OnUpdate();
}

int cellPadGetDataExtraInternalHook(void* r3, unsigned int port, int* deviceType, CellPadData* data, bool r7)
{
   if (port != 0)
      return cellPadGetDataExtraInternalHk->GetOriginal<int>(r3, port, deviceType, data, r7);

   int returnValue = cellPadGetDataExtraInternalHk->GetOriginal<int>(r3, port, deviceType, g_Input.GetInputData(), r7);
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

void InstallHooks()
{
   pafFrameworkUpdateHk = new ImportExportDetour(ImportExportDetour::Export, "paf", 0x85D1D23B, (uintptr_t)pafFrameworkUpdateHook);
   cellPadGetDataExtraInternalHk = new Detour(ResolveBranch(FindExportByName("sys_io", 0x3733EA3C)->func + 0x6C), (uintptr_t)cellPadGetDataExtraInternalHook);
}

void RemoveHooks()
{
   delete pafFrameworkUpdateHk;
   delete cellPadGetDataExtraInternalHk;
}