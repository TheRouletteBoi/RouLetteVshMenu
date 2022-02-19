
#include "GUI.hpp"
#include "Helpers.hpp"

vsh::paf::PhPlane* GUI::GuiMakeWindow(const std::string& windowName)
{
   if (!g_Helpers.page_autooff_guide)
      return nullptr;

   vsh::paf::PhPlane* plane = new vsh::paf::PhPlane(g_Helpers.page_autooff_guide, nullptr);
   if (!plane)
      return nullptr;
   plane->SetName(windowName);
   plane->SetColor(vsh::vec4(0.0f, 0.0f, 0.0f, 0.0f));
   return plane;
}

vsh::paf::PhPlane* GUI::GuiGetWindow(int32_t windowIndex)
{
   if (m_PlaneList.empty())
      return nullptr;

   if (windowIndex > MAX_SHADERS || windowIndex < 0)
      return nullptr;

   return m_PlaneList[windowIndex];
}

bool GUI::GuiWindowValid(int32_t windowIndex)
{
   return GuiGetWindow(windowIndex) != nullptr;
}

void GUI::GuiCloseWindow(int32_t windowIndex)
{
   vsh::paf::PhPlane* phPlane = GuiGetWindow(windowIndex);
   if (!phPlane)
      return;

   delete phPlane;
}

vsh::paf::PhText* GUI::GuiMakeText(const std::string& textName)
{
   if (!g_Helpers.page_autooff_guide)
      return nullptr;

   vsh::paf::PhText* phText = new vsh::paf::PhText(g_Helpers.page_autooff_guide, nullptr);
   phText->SetName(textName);
   phText->SetColor(vsh::vec4(0.0f, 0.0f, 0.0f, 0.0f));
   phText->SetStyle(0x13, 0x70);
   return phText;
}

vsh::paf::PhText* GUI::GuiGetText(int32_t textIndex)
{
   if (m_TextList.empty())
      return nullptr;

   if (textIndex > MAX_SHADERS || textIndex < 0)
      return nullptr;

   return m_TextList[textIndex];
}

bool GUI::GuiTextValid(int32_t textIndex)
{
   return GuiGetText(textIndex) != nullptr;
}

void GUI::GuiCloseText(int32_t textIndex)
{
   vsh::paf::PhText* phText = GuiGetText(textIndex);
   if (!phText)
      return;

   delete phText;
}

void GUI::DrawRectImpl(vsh::vec2 position, vsh::vec2 size, vsh::vec4 color, Alignment alligment)
{
   vsh::paf::PhPlane* phPlane = GuiGetWindow(m_TotalConcurrentPhPlanes);
   if (!phPlane)
      return;
   phPlane->SetPosition(position);
   phPlane->SetSize(size);
   phPlane->SetColor(color);
   vsh::paf::PhWidget::AnchorStyle anchorStyle = vsh::paf::PhWidget::AnchorCenter;
   switch (alligment)
   {
   case Alignment::Left:
      anchorStyle = vsh::paf::PhWidget::AnchorLeft;
      break;
   case Alignment::Centered:
      anchorStyle = vsh::paf::PhWidget::AnchorCenter;
      break;
   case Alignment::Right:
      anchorStyle = vsh::paf::PhWidget::AnchorRight;
      break;
   }
   phPlane->SetStyle(vsh::paf::PhWidget::Anchor, anchorStyle);
   m_TotalConcurrentPhPlanes++;
}

void GUI::DrawTextImpl(const std::wstring& text, vsh::vec2 position, int32_t scale, vsh::vec4 color, Alignment alignment)
{
   vsh::paf::PhText* phText = GuiGetText(m_TotalConcurrentPhText);
   if (!phText)
      return;

   phText->SetPosition(position);
   phText->SetLayoutStyle(0, scale, 0.0f);
   phText->SetColor(color);
   switch (alignment)
   {
   case Alignment::Left:
      phText->SetStyle(vsh::paf::PhWidget::Anchor, vsh::paf::PhWidget::AnchorLeft);
      phText->SetStyle(vsh::paf::PhWidget::TextAlignment, vsh::paf::PhWidget::AnchorLeft);
      break;
   case Alignment::Centered:
      phText->SetStyle(vsh::paf::PhWidget::Anchor, vsh::paf::PhWidget::AnchorCenter);
      break;
   case Alignment::Right:
      phText->SetStyle(vsh::paf::PhWidget::Anchor, vsh::paf::PhWidget::AnchorRight);
      phText->SetStyle(vsh::paf::PhWidget::TextAlignment, vsh::paf::PhWidget::TextAlignRight);
      break;
   }
   phText->SetText(text);
   m_TotalConcurrentPhText++;
}

// tex_operation_guide_base box with rounded edges
// tex_circle hollow circle 
// tex_busy hollow circle with dot in the center
// tex_cross cross with transparent background
// tex_msgdialog_bar transparent on left and right edges but fading color in the center. good if you want to mix 2 of the textures with different colors
// tex_optionmenu_bg transparent on the right only but fading color to the left. good if you want to mix 2 of the textures with different colors
void GUI::DrawTextureImpl(const char* systemTexture, vsh::vec2 position, vsh::vec2 size, vsh::vec4 color, Alignment alligment)
{
   vsh::paf::PhPlane* phPlane = GuiGetWindow(m_TotalConcurrentPhPlanes);
   if (!phPlane)
      return;
   phPlane->SetSystemTexture(systemTexture);
   phPlane->SetPosition(position);
   phPlane->SetSize(size);
   phPlane->SetColor(color);
   vsh::paf::PhWidget::AnchorStyle anchorStyle = vsh::paf::PhWidget::AnchorCenter;
   switch (alligment)
   {
   case Alignment::Left:
      anchorStyle = vsh::paf::PhWidget::AnchorLeft;
      break;
   case Alignment::Centered:
      anchorStyle = vsh::paf::PhWidget::AnchorCenter;
      break;
   case Alignment::Right:
      anchorStyle = vsh::paf::PhWidget::AnchorRight;
      break;
   }
   phPlane->SetStyle(vsh::paf::PhWidget::Anchor, anchorStyle);
   m_TotalConcurrentPhPlanes++;
}

void GUI::CreatePlanesAndTextImpl()
{
   if (!g_Helpers.page_autooff_guide)
      return;

   // not required??
   if (g_Helpers.page_autooff_guide->FindChild("RouLetteVshMenuPlane_0", 0))
      return;

   for (int i = 0; i < MAX_SHADERS; i++)
   {
      vsh::paf::PhPlane* phPlane = GuiMakeWindow("RouLetteVshMenuPlane_" + to_string(i));
      if (!phPlane)
         break;
      m_PlaneList.push_back(phPlane);
   }

   for (int i = 0; i < MAX_SHADERS; i++)
   {
      vsh::paf::PhText* phText = GuiMakeText("RouLetteVshMenuText_" + to_string(i));
      if (!phText)
         break;
      m_TextList.push_back(phText);
   }
}

void GUI::DestoryPlanesAndTextImpl()
{
   for (int i = 0; i < MAX_SHADERS; i++)
   {
      vsh::paf::PhPlane* phPlane = GuiGetWindow(i);
      if (!phPlane)
         break;

      delete phPlane;
   }

   for (int i = 0; i < MAX_SHADERS; i++)
   {
      vsh::paf::PhText* phText = GuiGetText(i);
      if (!phText)
         break;

      delete phText;
   }

   m_PlaneList.clear();
   m_TextList.clear();
}

void GUI::ClearWidgetTextImpl()
{
   for (int i = 0; i < MAX_SHADERS; i++)
   {
      vsh::paf::PhText* phText = GuiGetText(i);
      if (!phText)
         break;

      phText->SetText(L"");
   }
}

void GUI::BeginDrawingImpl()
{
   m_TotalConcurrentPhPlanes = 0;
   m_TotalConcurrentPhText = 0;
}

void GUI::EndDrawingImpl()
{

}