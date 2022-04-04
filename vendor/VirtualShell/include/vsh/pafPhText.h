#ifndef __PAF_PHTEXT_H__
#define __PAF_PHTEXT_H__
#include "vshtypes.h"
#include "pafPhWidget.h"
#include <algorithm>

_VSH_BEGIN
_PAF_BEGIN

class PhText : public PhWidget
{
public:
    PhText(PhWidget* parent, void* PhAppear = nullptr)
    {
        PhText_Constructor(this, parent, PhAppear);
    }

    ~PhText()
    {
        if (IsAttached())
            PhWidget_Destructor(this);
    }

    PhText& SetText(const std::wstring& text)
    {
        CallVirtualMethod<void>(70, this, text, 0);
        return *this;
    }

    PhText& SetText(const std::string& text)
    {
        std::wstring ws(text.begin(), text.end());
        return SetText(ws);
    }

    PhText& SetTextStyle(int style, float value)
    {
        PhSText_SetStyle(m_Data.sRender->PhSText, style, value);
        return *this;
    }

    PhText& SetTextHeight(float height)
    {
        ViewportScaleVertical(height);

        SetTextStyle(0x28, height); // line height
        //SetTextStyle(0x2D, 0); // line spacing
        return *this;
    }

    int GetLineCount()
    {
        return PhText_GetLineCount(this);

        //std::wstring text = m_Data.sRender->PhSText->text;
        //size_t occurrences = std::count(text.begin(), text.end(), '\n');
        //return 1 + occurrences;
    }

    float GetLineHeight()
    {
        float textHeight = PhText_GetLineHeight(this);
        RevertViewportScaleVertical(textHeight);
        return textHeight;
    }

    float GetTextHeight()
    {
        return static_cast<float>(GetLineCount()) * GetLineHeight();
    }

    float GetTextWidth()
    {
        return PhText_GetTextWidth(this);
    }

private:
    std::uint8_t __padding_0x290[0x14];
};

_PAF_END
_VSH_END

#endif // __PAF_PHTEXT_H__