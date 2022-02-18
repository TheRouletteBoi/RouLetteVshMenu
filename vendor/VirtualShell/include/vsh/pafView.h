#ifndef __PAFVIEW_H__
#define __PAFVIEW_H__
#include "vshtypes.h"
#include "paf.h"

_VSH_BEGIN
_PAF_BEGIN

class View
{
public:
   static View* Find(const char* pluginName)
   {
      return (View*)View_Find(pluginName);
   }

   PhWidget* FindWidget(const char* widgetName)
   {
      return (PhWidget*)View_FindWidget((int)this, widgetName);
   }

   const wchar_t* GetString(const char* stringName)
   {
      return View_GetString((int)this, stringName);
   }

   Surface* GetTexture(const char* textureName)
   {
      Surface* texture;
      View_GetTexture((uint32_t*)&texture, (int)this, textureName);
      return texture;
   }

   void PlaySound(const char* soundName, float f1, int r6)
   {
      View_PlaySound((int)this, soundName, f1, r6);
   }

   template<typename R>
   R GetInterface(uint32_t interfaceId)
   {
      return (R)View_GetInterface((uint32_t)this, interfaceId);
   }
};


_PAF_END
_VSH_END

#endif // __PAFVIEW_H__