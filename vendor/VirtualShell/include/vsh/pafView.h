#ifndef __PAFVIEW_H__
#define __PAFVIEW_H__
#include "vshtypes.h"
#include "paf.h"
#include <string>

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
        if (textureName[0] == '\0')
            return nullptr;

        Surface* texture = nullptr;
        View_GetTexture((int*)&texture, (int)this, textureName);
        return texture;
    }

    void PlaySound(const char* soundName)
    {
        View_PlaySound((int)this, soundName, 1.0, 0);
    }

    void SetInterface(uint32_t interfaceId, void* interfaceStruct)
    {
        View_SetInterface(this, interfaceId, interfaceStruct);
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