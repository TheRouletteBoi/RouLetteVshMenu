#pragma once
#include <sys/process.h>
#undef vector
#include <vector>
#include <vsh/vshmath.h>
#include <vsh/pafView.h>
#include <vsh/pafPhPlane.h>
#include <vsh/pafPhText.h>
#include "Utils/Std.hpp"
#include "Helpers.hpp"

class Render
{
public:
   enum Align
   {
      Centered,
      Left = (1 << 0),
      Right = (1 << 1),
      Top = (1 << 4),
      Bottom = (1 << 5)
   };

public:
   void OnUpdate();
   void DestroyWidgets();
   void Text(const std::wstring& text, vsh::vec2 position, float height, Align horizontalAlign, Align verticalAlign, vsh::vec4 color, float angle = 0);
   void Text(const std::string& text, vsh::vec2 position, float height, Align horizontalAlign, Align verticalAlign, vsh::vec4 color, float angle = 0);

private:
   vsh::paf::PhText* CreateText(const std::string& widgetName);
   vsh::paf::PhText* GetText(int index);

   void CreateWidgets();
   void ClearTexts();

private:
   std::vector<vsh::paf::PhText*> m_TextList{};
   int m_CurrentText = 0;

   static constexpr int MAX_TEXTS = 2;
};

extern Render g_Render;