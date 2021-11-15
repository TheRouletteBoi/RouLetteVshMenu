#include "Hooking.hpp"
#include <vsh/stdc.h>

ImportExportHook* paf_75295C38Hk;
ImportExportHook* paf_85D1D23BHk;
ImportExportHook* sys_io_3733EA3CHk;
DetourHook* RenderTextHk;

void paf_75295C38Hook(uint32_t r3, uint32_t r4)
{
   if (g_Helpers.xmbRainbowMode)
   {
      Color rgb = g_Helpers.UpdateRGBInterpolation();

      *(float*)(r4 + 0x120) = rgb.r / 255.0f;
      *(float*)(r4 + 0x124) = rgb.g / 255.0f;
      *(float*)(r4 + 0x128) = rgb.b / 255.0f;
   }

   paf_75295C38Hk->GetOriginal<void>(r3, r4);
}

uint32_t paf_85D1D23BHook(uint32_t r3, float f1)
{
   // text rendering?

   return paf_85D1D23BHk->GetOriginal<uint32_t>(r3, f1);
}

uint32_t sys_io_3733EA3CHook(uint32_t r3, uint32_t r4, uint32_t r5)
{
   // button monitoring?

   return sys_io_3733EA3CHk->GetOriginal<uint32_t>(r3, r4, r5);
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

   return RenderTextHk->GetOriginal<uint32_t>(r3, r4, r5, r6);
}

void InstallHooks()
{
   paf_75295C38Hk = new ImportExportHook(ImportExportHook::Export, "paf", 0x75295C38, (uintptr_t)paf_75295C38Hook, false);

   paf_85D1D23BHk = new ImportExportHook(ImportExportHook::Export, "paf", 0x85D1D23B, (uintptr_t)paf_85D1D23BHook);

   sys_io_3733EA3CHk = new ImportExportHook(ImportExportHook::Export, "sys_io", 0x3733EA3C, (uintptr_t)sys_io_3733EA3CHook);

   //RenderTextHk = new DetourHook(RenderTextSymbol, (uintptr_t)RenderTextHook);
}

void DestoryHooks()
{
   delete paf_75295C38Hk;
   delete paf_85D1D23BHk;
   delete sys_io_3733EA3CHk;
}