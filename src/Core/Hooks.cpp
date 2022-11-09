#include "Hooks.hpp"
#include "Menu/Base.hpp"
#include "Menu/Overlay.hpp"
#include "Memory/Pattern.hpp"
#include <vsh/stdc.hpp>
#include <cell/pad/pad_codes.h>

ImportExportDetour* pafFrameworkBeginHk;
Detour* cellPadGetDataExtraInternalHk;

void pafFrameworkBeginHook(void* framework, float frameTime)
{
    pafFrameworkBeginHk->GetOriginal<void>(framework, frameTime);

    g_Helpers.OnUpdate();
    g_Renderer.OnUpdate();
    g_Overlay.OnUpdate();
    g_Menu.OnUpdate();
}

int cellPadGetDataExtraInternalHook(void* r3, uint32_t portNum, uint32_t* deviceType, CellPadData* data, bool canReturnWithoutClearing)
{
    int returnValue = cellPadGetDataExtraInternalHk->GetOriginal<int>(r3, portNum, deviceType, data, canReturnWithoutClearing);
    if (portNum)
        return returnValue;

    g_Input.SetInputData(data);

    if (g_Menu.IsOpened())
    {
        data->button[CELL_PAD_BTN_OFFSET_DIGITAL1] &= ~(CELL_PAD_CTRL_LEFT | CELL_PAD_CTRL_DOWN | CELL_PAD_CTRL_RIGHT | CELL_PAD_CTRL_UP);
        data->button[CELL_PAD_BTN_OFFSET_DIGITAL2] &= ~(CELL_PAD_CTRL_CROSS | CELL_PAD_CTRL_CIRCLE);

        if (g_Menu.IsMoving())
        {
            data->button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_X] = 128;
            data->button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_Y] = 128;
        }
    }

    return returnValue;
}

void InstallHooks()
{
    pafFrameworkBeginHk = new ImportExportDetour(ImportExportDetour::Export, "paf", 0x59BDA198, (uintptr_t)pafFrameworkBeginHook);
    cellPadGetDataExtraInternalHk = new Detour(ResolveBranch(FindExportByName("sys_io", 0x3733EA3C)->func + 0x6C), (uintptr_t)cellPadGetDataExtraInternalHook);
}

void RemoveHooks()
{
    delete pafFrameworkBeginHk;
    delete cellPadGetDataExtraInternalHk;
}