#pragma once
#undef vector
#include <vector>
#include <vsh/pafView.h>
#include <vsh/pafPhPlane.h>
#include <vsh/pafPhText.h>

class GUI
{
public:
   enum class Alignment
   {
      Left,
      Centered,
      Right
   };

public:
   GUI(const GUI&) = delete;

   static GUI& Get()
   {
      static GUI instance;
      return instance;
   }

   static void CreatePlanesAndText() { Get().CreatePlanesAndTextImpl(); }
   static void DestoryPlanesAndText() { Get().DestoryPlanesAndTextImpl(); }
   static void ClearWidgetText() { Get().ClearWidgetTextImpl(); }
   static void BeginDrawing() { Get().BeginDrawingImpl(); }
   static void EndDrawing() { Get().EndDrawingImpl(); }
   static void DrawRect(vsh::vec2 position, vsh::vec2 size, vsh::vec4 color, Alignment alligment)
   {
      Get().DrawRectImpl(position, size, color, alligment);
   }

   static void DrawText(const std::wstring& text, vsh::vec2 position, int32_t scale, vsh::vec4 color, Alignment alignment)
   {
      Get().DrawTextImpl(text, position, scale, color, alignment);
   }

   static void DrawTexture(const char* systemTexture, vsh::vec2 position, vsh::vec2 size, vsh::vec4 color, Alignment alligment)
   {
      Get().DrawTextureImpl(systemTexture, position, size, color, alligment);
   }

private:
   vsh::paf::PhPlane* GuiMakeWindow(const std::string& windowName);
   vsh::paf::PhPlane* GuiGetWindow(int32_t windowIndex);
   bool GuiWindowValid(int32_t windowIndex);
   void GuiCloseWindow(int32_t windowIndex);

   vsh::paf::PhText* GuiMakeText(const std::string& textName);
   vsh::paf::PhText* GuiGetText(int32_t textIndex);
   bool GuiTextValid(int32_t textIndex);
   void GuiCloseText(int32_t textIndex);

   void DrawRectImpl(vsh::vec2 position, vsh::vec2 size, vsh::vec4 color, Alignment alligment);
   void DrawTextImpl(const std::wstring& text, vsh::vec2 position, int32_t scale, vsh::vec4 color, Alignment alignment);
   void DrawTextureImpl(const char* systemTexture, vsh::vec2 position, vsh::vec2 size, vsh::vec4 color, Alignment alligment);

   void CreatePlanesAndTextImpl();
   void DestoryPlanesAndTextImpl();
   void ClearWidgetTextImpl();
   void BeginDrawingImpl();
   void EndDrawingImpl();


private:
   GUI() {}
   static constexpr int MAX_SHADERS = 20; // 99

   std::vector<vsh::paf::PhPlane*> m_PlaneList;
   int m_TotalConcurrentPhPlanes;

   std::vector<vsh::paf::PhText*> m_TextList;
   int m_TotalConcurrentPhText;
};