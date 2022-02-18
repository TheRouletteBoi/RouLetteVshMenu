#ifndef __PAF_PHTEXT_H__
#define __PAF_PHTEXT_H__
#include "vshtypes.h"
#include "pafPhWidget.h"

_VSH_BEGIN
_PAF_BEGIN

class PhText : public PhWidget
{
public:
   PhText(PhWidget* parent, void* PhAppear)
   {
      PhText_Constructor(this, parent, PhAppear);
   }

   ~PhText()
   {
      if (this->IsAttached())
         PhWidget_Destructor(this);
   }

   void SetText(const std::wstring& text)
   {
      this->CallMethod<void>(70, this, text, 0);
   }

   void SetText(const std::string& text)
   {
      std::wstring ws(text.begin(), text.end());;
      this->SetText(ws);
   }

   int GetLineCount()
   {
      return PhText_GetLineCount(this);
   }

   float GetLineHeight()
   {
      return PhText_GetLineHeight(this);
   }

   float GetTextHeight()
   {
      return static_cast<float>(this->GetLineCount()) * this->GetLineHeight();
   }

   float GetTextWidth()
   {
      return PhText_GetTextWidth(this);
   }

private: // Data - size: 0x2A4
   char __padding_0x290[0x14];
};

_PAF_END
_VSH_END

#endif // __PAF_PHTEXT_H__