#include "Rendering.hpp"

Render g_Render;

void Render::OnUpdate()
{
   if (!g_Helpers.system_plugin)
      return;

   if (!g_Helpers.page_autooff_guide)
   {
      DestroyWidgets();
      return;
   }

   vsh::paf::PhPlane* phPlane = GetPlane(0);
   if (phPlane)
   {
      if (!phPlane->IsAttached())
      {
         DestroyWidgets();
         return;
      }
   }
   else
   {
      CreateWidgets();
      return;
   }

   m_CurrentPlane = 0;
   m_CurrentText = 0;

   ClearPlanes();
   ClearTexts();
}

void Render::Rectangle(vsh::vec2 position, vsh::vec2 size, Align horizontalAlign, Align verticalAlign, vsh::vec4 color, const char* texture, float angle)
{
   vsh::paf::PhPlane* phPlane = GetPlane(m_CurrentPlane);
   if (!phPlane)
      return;

   if (!phPlane->IsAttached())
      return;

   phPlane->SetPosition(position)
      .SetSize(size)
      .SetColor(color)
      .SetStyle(vsh::paf::PhWidget::Anchor, int(horizontalAlign | verticalAlign))
      .SetRotation(angle, false)
      .SetSystemTexture(texture);

   m_CurrentPlane++;
}

void Render::RectangleGradient(vsh::vec2 position, vsh::vec2 size, Align horizontalAlign, Align verticalAlign, vsh::vec4 colorLeft, vsh::vec4 colorRight, float angle)
{
   Rectangle(position, size, horizontalAlign, verticalAlign, colorLeft, "tex_optionmenu_game");
   Rectangle(position, size, horizontalAlign, verticalAlign, colorRight, "tex_optionmenu_game", 180);
}

// Untested

double radians(double degrees)
{
   return degrees * (M_PI / 180.0);
}

double degrees(double radians)
{
   return radians * (180.0 / M_PI);
}

void Render::Line(vsh::vec2 from, vsh::vec2 to, float thickness, vsh::vec4 color)
{
   float width, height, hypotenuse, x, y, angle;

   width = to.x - from.x;
   height = to.y - from.y;
   hypotenuse = vsh::sqrtf(width * width + height * height);

   x = from.x + ((width - hypotenuse) / 2);
   y = from.y + (height / 2) - (thickness / 2);
   angle = degrees(vsh::atan2f(height, width));

   Rectangle(vsh::vec2(x, y), vsh::vec2(hypotenuse, thickness), Left, Top, color, "", angle);
}

void Render::Text(const std::wstring& text, vsh::vec2 position, float height, Align horizontalAlign, Align verticalAlign, vsh::vec4 color, float angle)
{
   vsh::paf::PhText* phText = GetText(m_CurrentText);
   if (!phText)
      return;

   if (!phText->IsAttached())
      return;

   position.y += (height * 0.15);

   phText->SetText(text)
      .SetTextHeight(height * 0.8)
      .SetPosition(position)
      .SetColor(color)
      .SetStyle(vsh::paf::PhWidget::Anchor, int(horizontalAlign | verticalAlign))
      .SetStyle(vsh::paf::PhWidget::TextAlignment, int(horizontalAlign))
      .SetRotation(angle, false);

   m_CurrentText++;
}

void Render::Text(const std::string& text, vsh::vec2 position, float height, Align horizontalAlign, Align verticalAlign, vsh::vec4 color, float angle)
{
    std::wstring ws(text.begin(), text.end());
    Text(ws, position, height, horizontalAlign, verticalAlign, color, angle);
}

vsh::paf::PhPlane* Render::CreatePlane(const std::string& widgetName)
{
   vsh::paf::PhPlane* phPlane = new vsh::paf::PhPlane(g_Helpers.page_autooff_guide);
   phPlane->SetName(widgetName)
      .SetColor(vsh::vec4());
   return phPlane;
}

vsh::paf::PhText* Render::CreateText(const std::string& widgetName)
{
   if (!g_Helpers.page_autooff_guide)
      return nullptr;

   vsh::paf::PhText* phText = new vsh::paf::PhText(g_Helpers.page_autooff_guide);
   phText->SetName(widgetName)
      .SetColor(vsh::vec4())
      .SetStyle(0x13, 0x70);
   return phText;
}

vsh::paf::PhPlane* Render::GetPlane(int index)
{
   if (m_PlaneList.empty())
      return nullptr;

   if (index > MAX_PLANES || index < 0)
      return nullptr;

   return m_PlaneList[index];
}

vsh::paf::PhText* Render::GetText(int index)
{
   if (m_TextList.empty())
      return nullptr;

   if (index > MAX_TEXTS || index < 0)
      return nullptr;

   return m_TextList[index];
}

void Render::CreateWidgets()
{
   if (!g_Helpers.page_autooff_guide)
      return;

   // don't create any more planes if we already created the first one
   if (vsh::paf::PhPlane* phPlane = GetPlane(0))
      return;
   else
   {
      m_PlaneList.clear();
      m_TextList.clear();
   }

   vsh::srand(mix_time_seed(clock(), time(NULL), sys_process_getpid()));
   for (int i = 0; i < MAX_PLANES; i++)
   {
      // Using a randomized name add compatibility with other menus if they use the same name template
      vsh::paf::PhPlane* phPlane = CreatePlane("CRenderPlane_" + to_string(vsh::rand()));
      if (!phPlane)
         break;

      m_PlaneList.push_back(phPlane);
   }

   vsh::srand(mix_time_seed(clock(), time(NULL), sys_process_getpid()));
   for (int i = 0; i < MAX_TEXTS; i++)
   {
      vsh::paf::PhText* phText = CreateText("CRenderText_" + to_string(vsh::rand()));
      if (!phText)
         break;

      m_TextList.push_back(phText);
   }
}

void Render::DestroyWidgets()
{
   if (!g_Helpers.page_autooff_guide)
      return;

   // clear pointers if no longer valid
   if (vsh::paf::PhPlane* phPlane = GetPlane(0))
   {
      if (!phPlane->IsAttached())
      {
         m_PlaneList.clear();
         m_TextList.clear();
         return;
      }
   }

   for (int i = 0; i < MAX_PLANES; i++)
   {
      vsh::paf::PhPlane* phPlane = GetPlane(i);
      if (!phPlane)
         continue;

      delete phPlane;
   }

   for (int i = 0; i < MAX_TEXTS; i++)
   {
      vsh::paf::PhText* phText = GetText(i);
      if (!phText)
         continue;

      delete phText;
   }

   m_PlaneList.clear();
   m_TextList.clear();
}

void Render::ClearPlanes()
{
   if (!g_Helpers.page_autooff_guide)
      return;

   if (vsh::paf::PhPlane* phPlane = GetPlane(0))
      if (!phPlane->IsAttached())
         return;

   for (int i = 0; i < MAX_PLANES; i++)
   {
      vsh::paf::PhPlane* phPlane = GetPlane(i);
      if (!phPlane)
         continue;

      if (!phPlane->IsAttached())
         continue;

      phPlane->SetColor(vsh::vec4());
   }
}

void Render::ClearTexts()
{
   if (!g_Helpers.page_autooff_guide)
      return;

   if (vsh::paf::PhPlane* phPlane = GetPlane(0))
      if (!phPlane->IsAttached())
         return;

   for (int i = 0; i < MAX_TEXTS; i++)
   {
      vsh::paf::PhText* phText = GetText(i);
      if (!phText)
         continue;

      if (!phText->IsAttached())
         continue;

      phText->SetColor(vsh::vec4());
   }
}