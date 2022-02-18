#include "Hooking.hpp"
#include <vsh/stdc.h>
#include <cell/pad/pad_codes.h>

ImportExportHook* pafFrameworkRenderHk;
ImportExportHook* cellPadGetDataRawHk;

uint32_t pafFrameworkRenderHook(void* framework, float frameTime)
{
   g_Menu.OnUpdate();
   g_Helpers.OnUpdate();
   return pafFrameworkRenderHk->GetOriginal<uint32_t>(framework, frameTime);
}

int32_t cellPadGetDataRawHook(uint32_t portNo, uint32_t deviceType, CellPadData* data)
{
   int32_t ret = cellPadGetDataRawHk->GetOriginal<int32_t>(portNo, deviceType, data);
   if (ret == SUCCEEDED && portNo == 0) // first controller
   {
      if (data->len)
      {
         vsh::memcpy(&g_Helpers.padData, data, sizeof(CellPadData));

         // Clear VSH pad data when our menu is opened
         if (g_Menu.IsOpened())
            vsh::memset(&data->button[CELL_PAD_BTN_OFFSET_DIGITAL1], 0, 4);
      }
      else
         vsh::memset(&g_Helpers.padData, 0, sizeof(CellPadData));
   }
   return ret;
}

uint32_t RenderTextHook(uint32_t r3, uint32_t r4, uint32_t r5, uint32_t r6)
{
   // DrawText(void* unk const std::wstring& text, void*, void*, 0x40, 0, 0, size_t stringLen); // DrawTextSymbol
   // paf_BE04476B(paf::PhFont::GlyphType, paf::SurfaceRCPtr<paf::Surface> &, int, int, wchar_t const*, unsigned int, paf::PhFont const&, paf::PhTextLetterSpace const*);

   // FindLoadedPlugin();
   // FindWidget();
   // LoadRCOTexture();
   // paf_8ABAE2F3();
   // paf_7F0930C6();
   // plugin_GetInterface();
   // paf_2CBA5A33();
   // PlayRCOSound();
   // paf_EAA28B8();
   // paf_85D1D23B();
   // paf_0C74837D();
   // paf_CC51D56();
   // paf_C9826818();
   // paf_4192B349();

   // vshcommon_F1918912(); // notification?

   // vshnet_FC7303C5(); // sceNpGetNpId

   return 0;
}

void HookingInitiate()
{
   pafFrameworkRenderHk = new ImportExportHook(ImportExportHook::Export, "paf", 0x85D1D23B, (uintptr_t)pafFrameworkRenderHook);
   cellPadGetDataRawHk = new ImportExportHook(ImportExportHook::Export, "sys_io", 0x3733EA3C, (uintptr_t)cellPadGetDataRawHook);
}

void HookingRemoveAll()
{
   delete pafFrameworkRenderHk;
   delete cellPadGetDataRawHk;
}