#include "Base.hpp"

Menu g_Menu;

Menu::Menu(Function mainSubmenu)
   : m_MainMenu(mainSubmenu) {}

bool Menu::IsOpened()
{
   return m_OpacityBackground > 0.0 || m_StateOpened;
}

bool Menu::IsMoving()
{
   return stateMoving;
}

void Menu::SetMovingState(bool state)
{
    stateMoving = state;
}

bool Menu::IsInitialized()
{
   return m_StateInitialized;
}

void Menu::Initialize()
{
   m_StateInitialized = true;
}

bool Menu::IsOpenPressed()
{
   if (g_Input.IsButtonBinds(CInput::BUTTON_L1, CInput::BUTTON_R3))
   {
      PlaySound("snd_system_ok");
      return true;
   }

   return false;
}

bool Menu::IsEnterPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_CROSS, 400))
   {
      PlaySound("snd_system_ok");
      return true;
   }

   return false;
}

bool Menu::IsBackPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_CIRCLE, 400))
   {
      PlaySound("snd_cancel");
      return true;
   }

   return false;
}

bool Menu::IsUpPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_UP, 250))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsDownPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_DOWN, 250))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsLeftPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_LEFT, m_SliderDelay))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsRightPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_RIGHT, m_SliderDelay))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsLeftOrRightPressed()
{
   if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_LEFT, m_SliderDelay) || g_Input.IsButtonDownFor(CInput::BUTTON_PAD_RIGHT, m_SliderDelay))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsHovered()
{
   return IsOpened() && (m_CurrentOption == m_PrintingOption);
}

bool Menu::IsPressed()
{
   if (IsHovered())
      return IsEnterPressed();

   return false;
}

void Menu::OnOpen()
{
   m_StateOpened = true;
   m_CurrentMenu = (m_SavedMenu == nullptr) ? m_MainMenu : m_SavedMenu;
   m_SubmenuLevel = (m_SavedMenu == nullptr) ? 0 : m_SavedSubmenuLevel;
   m_CurrentOption = (m_SavedMenu == nullptr) ? 1 : m_SavedCurrentOption;
   m_CurrentIndex = (m_SavedMenu == nullptr) ? 1 : m_SavedCurrentIndex;

   // opening animation
   g_ChangeOvertime.Add(&m_OpacityBackground, colorBackground.a, 200);
   g_ChangeOvertime.Add(&m_OpacityGlobal, 1, 200);
   g_ChangeOvertime.Add(&m_OpacityHighlightBar, 0.65, 200, 200);
   g_ChangeOvertime.Add(&m_OpacityText, 1, 200, 200);
   g_ChangeOvertime.Add(&m_HighlightBarPosY, (m_CurrentOption - m_CurrentIndex) * sizeText, 250, 0, true);
}

void Menu::OnClose()
{
   m_StateOpened = false;
   stateMoving = false;
   m_SavedMenu = m_CurrentMenu;
   m_SavedSubmenuLevel = m_SubmenuLevel;
   m_SavedCurrentOption = m_CurrentOption;
   m_SavedCurrentIndex = m_CurrentIndex;

   // closing animation
   g_ChangeOvertime.Add(&m_SizeBackground, 0, 200, 200, true);
   g_ChangeOvertime.Add(&m_OpacityBackground, 0, 200, 200);
   g_ChangeOvertime.Add(&m_OpacityGlobal, 0, 200, 200);
   g_ChangeOvertime.Add(&m_OpacityHighlightBar, 0, 200);
   g_ChangeOvertime.Add(&m_OpacityText, 0, 200);
}

void Menu::OnCancel()
{
   m_SubmenuLevel--;
   m_CurrentMenu = m_LastSubmenu[m_SubmenuLevel];
   m_CurrentOption = m_LastOption[m_SubmenuLevel];
   m_CurrentIndex = m_LastIndex[m_SubmenuLevel];

   g_ChangeOvertime.Add(&m_HighlightBarPosY, (m_CurrentOption - m_CurrentIndex) * sizeText, 250, 0, true);
}

void Menu::OnScrollUp()
{
   m_CurrentOption--;

   /*if (m_CurrentOption < m_CurrentIndex)
      m_CurrentIndex = m_CurrentOption;*/

      // Better infinite scrolling
   if (m_CurrentOption == m_CurrentIndex + 1 && m_CurrentIndex > 1)
      m_CurrentIndex--;

   if (m_CurrentOption < 1)
   {
      m_CurrentOption = m_TotalOptions;
      m_CurrentIndex = (m_TotalOptions > maxOptionsPerPage) ? m_CurrentOption - maxOptionsPerPage + 1 : 1;
   }

   g_ChangeOvertime.Add(&m_HighlightBarPosY, (m_CurrentOption - m_CurrentIndex) * sizeText, 250, 0, true);
}

void Menu::OnScrollDown()
{
   m_CurrentOption++;

   /*if (m_CurrentOption >= (m_CurrentIndex + maxOptionsPerPage))
      m_CurrentIndex = m_CurrentOption - maxOptionsPerPage + 1;*/

      // Better infinite scrolling
   if (m_CurrentOption == m_CurrentIndex + maxOptionsPerPage - 2 && m_CurrentIndex < m_TotalOptions - maxOptionsPerPage + 1)
      m_CurrentIndex++;

   if (m_CurrentOption > m_TotalOptions)
   {
      m_CurrentOption = 1;
      m_CurrentIndex = 1;
   }

   g_ChangeOvertime.Add(&m_HighlightBarPosY, (m_CurrentOption - m_CurrentIndex) * sizeText, 250, 0, true);
}

void Menu::EnterSubmenu(Function submenu)
{
   if (submenu == nullptr)
      return;

   m_LastSubmenu[m_SubmenuLevel] = m_CurrentMenu;
   m_LastOption[m_SubmenuLevel] = m_CurrentOption;
   m_LastIndex[m_SubmenuLevel] = m_CurrentIndex;
   m_CurrentMenu = submenu;
   m_CurrentOption = 1;
   m_CurrentIndex = 1;
   m_SubmenuLevel++;

   g_ChangeOvertime.Add(&m_HighlightBarPosY, (m_CurrentOption - m_CurrentIndex) * sizeText, 200, 0, true);
}

void Menu::ChangeSubmenu(Function submenu)
{
   if (submenu != nullptr)
      m_SubmenuDelay = submenu;
}

void Menu::PlaySound(const char* sound)
{
   if (!g_Helpers.system_plugin)
      return;

   g_Helpers.system_plugin->PlaySound(sound);
}

void Menu::UpdateButtons()
{
   if (stateMoving)
   {
      if (IsBackPressed() || IsEnterPressed())
          stateMoving = false;
   }
   else
   {
      if (!m_StateOpened && (m_OpacityGlobal == 0.0)) // fully closed
      {
         if (IsOpenPressed())
            OnOpen();

         WhileClosed();
      }
      else if (m_StateOpened && (m_OpacityText == 1.0)) // fully opened
      {
         if (IsOpenPressed())
            OnClose();
         else if (IsBackPressed())
         {
            if (m_CurrentMenu == m_MainMenu)
               OnClose();
            else
               OnCancel();
         }
         else if (IsUpPressed())
            OnScrollUp();
         else if (IsDownPressed())
            OnScrollDown();

         WhileOpen();
      }
   }
}

void Menu::UpdatePosition()
{
   if (stateMoving)
   {
      double stickX = g_Input.GetRightAnalogX();
      double stickY = -g_Input.GetRightAnalogY();

      if (stickX != 0.0)
      {
         float xAdvance = position.x + stickX * 5.0;
         float xSafeLimit = vsh::paf::PhWidget::GetViewportWidth() / 2 - sizeWidth / 2;

         if (xAdvance > -xSafeLimit && xAdvance < xSafeLimit)
            position.x += stickX * 5.0;

         if (position.x > xSafeLimit)
            position.x = xSafeLimit;

         if (position.x < -xSafeLimit)
            position.x = -xSafeLimit;
      }

      if (stickY != 0.0)
      {
         float yAdvance = position.y + stickY * 5.0;
         float ySafeLimit = vsh::paf::PhWidget::GetViewportHeight() / 2 - m_SizeBackground / 2 - sizeText;

         if (yAdvance > -ySafeLimit && yAdvance < ySafeLimit)
            position.y += stickY * 5.0;

         if (position.y > ySafeLimit)
            position.y = ySafeLimit;

         if (position.y < -ySafeLimit)
            position.y = -ySafeLimit;
      }
   }
}

void Menu::UpdateBackgroundSize()
{
   if (m_StateOpened)
   {
      static bool done = false;
      static uint64_t lastTime = 0;


      int optionsCount = (m_TotalOptions > maxOptionsPerPage) ? maxOptionsPerPage : m_TotalOptions;
      if (!optionsCount)
         return;

      float size = sizeText * optionsCount + m_SizeBackgroundSpace * 2;
      uint64_t timeNow = GetTimeNow();

      if (done && (timeNow - lastTime >= 200))
         done = false;

      if ((m_SizeBackground != size) && !done)
      {
         done = g_ChangeOvertime.Add(&m_SizeBackground, size, 200);
         lastTime = timeNow;
      }

   }
}

void Menu::UpdateHighlightBarPos()
{
   if (m_StateOpened)
   {
      static bool done = false;
      static uint64_t lastTime = 0;

      float pos = (m_CurrentOption - m_CurrentIndex) * sizeText;
      uint64_t timeNow = GetTimeNow();

      if (done && (timeNow - lastTime >= 200))
         done = false;

      if ((m_HighlightBarPosY != pos) && !done)
      {
         done = g_ChangeOvertime.Add(&m_HighlightBarPosY, pos, 200);
         lastTime = timeNow;
      }
   }
}

void Menu::WhileOpen()
{

}

void Menu::WhileClosed()
{

}

void Menu::UpdateUI()
{
   DrawInstructions();

   if (m_OpacityGlobal > 0.0)
   {
      m_TotalOptions = m_PrintingOption;
      m_PrintingOption = 0;
      m_DescriptionText.clear();

      UpdatePosition();
      UpdateBackgroundSize();
      UpdateHighlightBarPos();

      // Update background opacity
      if (m_OpacityGlobal == 1.0)
         m_OpacityBackground = colorBackground.a;

      DrawHeader();
      DrawBody();
      DrawHighlightBar();

      // Display current menu
      if (m_CurrentMenu != nullptr)
         m_CurrentMenu();

      // Enter selected submenu
      if (m_SubmenuDelay != nullptr)
      {
         EnterSubmenu(m_SubmenuDelay);
         m_SubmenuDelay = nullptr;
      }

      DrawFooter();
      DrawDescription();
   }

   DrawMovingHelp();
}

void Menu::OnUpdate()
{
   if (!IsInitialized())
      Initialize();

   g_ChangeOvertime.Update();

   // Close the menu if the xmb isn't loaded
   if (!vsh::paf::View::Find("xmb_plugin"))
   {
      if (m_StateOpened)
         OnClose();
      return;
   }

   UpdateButtons();
   UpdateUI();
}

void Menu::DrawHeader()
{
   // Background
   g_Render.Rectangle(
      vsh::vec2(position.x, position.y + m_SizeBackground / 2 + sizeText / 2 + sizeHeader / 2),
      vsh::vec2(sizeWidth, sizeHeader),
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorMenu.r, colorMenu.g, colorMenu.b, m_OpacityBackground));

   // Title
   g_Render.Text(
      L"RouLette's Launcher",
      vsh::vec2(position.x, position.y + m_SizeBackground / 2 + sizeTextHeader / 2 + sizeHeader / 2),
      sizeTextHeader,
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
}

void Menu::DrawBody()
{
   // Background
   g_Render.Rectangle(
      position,
      vsh::vec2(sizeWidth, m_SizeBackground),
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorBackground.r, colorBackground.g, colorBackground.b, m_OpacityBackground));
}

void Menu::DrawHighlightBar()
{
   vsh::vec2 pos = vsh::vec2(position.x, position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - m_HighlightBarPosY - sizeText / 2);

   g_Render.Rectangle(
      pos,
      vsh::vec2(sizeWidth, sizeText),
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorMenu.r, colorMenu.g, colorMenu.b, m_OpacityHighlightBar));
}

void Menu::DrawFooter()
{
   // Background
   g_Render.Rectangle(
      vsh::vec2(position.x, position.y - m_SizeBackground / 2 - sizeText / 2),
      vsh::vec2(sizeWidth, sizeText),
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorMenu.r, colorMenu.g, colorMenu.b, m_OpacityBackground));
}

void Menu::DrawDescription()
{
   if (m_DescriptionText.empty())
      return;

   g_Render.Rectangle(
      vsh::vec2(position.x, position.y - m_SizeBackground / 2 - sizeTextDescription / 2 - 22.0f),
      vsh::vec2(sizeWidth, sizeTextDescription),
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorBackground.r, colorBackground.g, colorBackground.b, m_OpacityBackground));

   g_Render.Text(
      m_DescriptionText,
      vsh::vec2(
         position.x - sizeWidth / 2 + m_SizeBackgroundSpace / 4,
         position.y - m_SizeBackground / 2 - sizeTextDescription / 2 - 20.0f),
       sizeTextDescription,
      Render::Left,
      Render::Centered,
      vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
}

void Menu::DrawInstructions()
{
   if (m_StateOpened)
       return;

   vsh::vec2 pos = vsh::vec2(vsh::paf::PhWidget::GetViewportWidth() / 2 - g_Menu.safeArea.x - 5, vsh::paf::PhWidget::GetViewportHeight() / 2 - g_Menu.safeArea.y - 5);

   g_Render.Text(
      L"Press \uF888 & \uF88D to open RouLette's Launcher",
      pos,
      sizeText,
      Render::Right,
      Render::Top,
      colorText);
}

void Menu::DrawMovingHelp()
{
   if (!stateMoving)
      return;

   g_Render.Text(
      L"Use \uF88D to move the menu",
      vsh::vec2(),
      sizeText,
      Render::Centered,
      Render::Centered,
      colorText);

   g_Render.Text(
      L"X: " + to_wstring(position.x) + L"\nY: " + to_wstring(position.y),
      vsh::vec2(0, -sizeText * 2),
      sizeText,
      Render::Centered,
      Render::Centered,
      colorText);
}

void Menu::DrawMenuTitle(const std::wstring& text)
{
    // Background
   g_Render.Rectangle(
      vsh::vec2(position.x, position.y + m_SizeBackground / 2 + sizeText / 2),
      vsh::vec2(sizeWidth, sizeText),
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorBackground.r, colorBackground.g, colorBackground.b, m_OpacityBackground));

   // Version Number
   /*g_Render.Text(
       L"1.2",
       vsh::vec2(position.x - sizeWidth / 2 + m_SizeBackgroundSpace / 4, position.y + m_SizeBackground / 2 + sizeText / 2),
       sizeText,
       Render::Left,
       Render::Centered,
       vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));*/

   g_Render.Text(
      text,
      vsh::vec2(position.x, position.y + m_SizeBackground / 2 + sizeText / 2),
      sizeText,
      Render::Centered,
      Render::Centered,
      vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));

   // Current option counter
   g_Render.Text(
       to_wstring(m_CurrentOption) + L" / " + to_wstring(m_TotalOptions),
       vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 4, position.y + m_SizeBackground / 2 + sizeText / 2),
       sizeText,
       Render::Right,
       Render::Centered,
       vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
}

void Menu::DrawMenuOption(const std::wstring& text)
{
   if ((m_PrintingOption >= m_CurrentIndex) && (m_PrintingOption < (m_CurrentIndex + maxOptionsPerPage)))
   {
      g_Render.Text(
         text,
         vsh::vec2(position.x - sizeWidth / 2 + m_SizeBackgroundSpace / 2,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         sizeText,
         Render::Left,
         Render::Centered,
         vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
   }
}

void Menu::DrawMenuToggle(bool var)
{
   if ((m_PrintingOption >= m_CurrentIndex) && (m_PrintingOption < (m_CurrentIndex + maxOptionsPerPage)))
   {
      g_Render.Rectangle(
         vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         vsh::vec2(sizeText * 0.7, sizeText * 0.7),
         Render::Right,
         Render::Centered,
         var ? vsh::vec4(colorToggleOn.r, colorToggleOn.g, colorToggleOn.b, m_OpacityText)
         : vsh::vec4(colorToggleOff.r, colorToggleOff.g, colorToggleOff.b, m_OpacityText), 
          "tex_busy");
   }
}

void Menu::DrawMenuSlider(const std::wstring& text, float progress)
{
   if ((m_PrintingOption >= m_CurrentIndex) && (m_PrintingOption < (m_CurrentIndex + maxOptionsPerPage)))
   {
      float sliderWidth = sizeWidth / 4;

      // Bar
      g_Render.Rectangle(
         vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2 - sliderWidth,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         vsh::vec2(sliderWidth, 6),
         Render::Left,
         Render::Centered,
         vsh::vec4(0.15, 0.15, 0.15, m_OpacityText), 
         "tex_operation_guide_base");

      // Filled bar
      g_Render.Rectangle(
         vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2 - sliderWidth,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         vsh::vec2((sliderWidth * progress), 6),
         Render::Left,
         Render::Centered,
         vsh::vec4(colorFillerBar.r, colorFillerBar.g, colorFillerBar.b, m_OpacityText),
         "tex_operation_guide_base");

      // Cursor
      g_Render.Rectangle(
         vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2 - sliderWidth + (sliderWidth * progress),
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         vsh::vec2(sizeText * 0.7, sizeText * 0.7),
         Render::Centered,
         Render::Centered,
         vsh::vec4(colorFillerCursor.r, colorFillerCursor.g, colorFillerCursor.b, m_OpacityText),
         "tex_busy");

#ifdef LAUNCHER_DEBUG
      // Value
      g_Render.Text(
          text,
          vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2 - sliderWidth - 5,
              position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
          sizeText,
          Render::Right,
          Render::Centered,
          vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
#endif // LAUNCHER_DEBUG
   }
}

void Menu::DrawMenuStringOption(const std::wstring& item)
{
   if ((m_PrintingOption >= m_CurrentIndex) && (m_PrintingOption < (m_CurrentIndex + maxOptionsPerPage)))
   {
      g_Render.Text(
         item,
         vsh::vec2(position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         sizeText,
         Render::Right,
         Render::Centered,
         vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
   }
}

void Menu::DrawMenuColorPreview(const vsh::vec4& color)
{
   if (IsHovered())
   {
      vsh::vec2 pos = vsh::vec2(
         position.x + sizeWidth,
         position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - m_HighlightBarPosY - sizeText / 2);

      g_Render.Rectangle(
         pos,
         vsh::vec2(50, 50),
         Render::Right,
         Render::Centered,
         color);
   }
}

void Menu::Title(const std::wstring& text)
{
   DrawMenuTitle(text);
}

Menu& Menu::Option(const std::wstring& text)
{
   m_PrintingOption++;
   DrawMenuOption(text);
   return *this;
}

Menu& Menu::Submenu(Function sub)
{
   if (IsPressed())
      ChangeSubmenu(sub);
   return *this;
}

Menu& Menu::Skip()
{
   if (IsHovered())
   {
      if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_UP))
      {
         OnScrollUp();
      }
      else if (g_Input.IsButtonDownFor(CInput::BUTTON_PAD_DOWN))
      {
         OnScrollDown();
      }
   }

   return *this;
}

Menu& Menu::Toggle(bool& var)
{
   DrawMenuToggle(var);
   if (IsPressed())
      var ^= 1;
   return *this;
}

Menu& Menu::Toggle(bool& var, Function onEnable, Function onDisable)
{
   DrawMenuToggle(var);
   if (IsPressed())
   {
      var ^= 1;
      if (var)
      {
         if (onEnable != nullptr)
            onEnable();
      }
      else
      {
         if (onDisable != nullptr)
            onDisable();
      }
   }
   return *this;
}

Menu& Menu::Action(Function fn)
{
   if (fn != nullptr && IsPressed())
      fn();

   return *this;
}

/*Menu& Menu::ActionHeavyweight(boost::function<void()> fn)
{
   if (IsHovered() && IsPressed())
      fn();

   return *this;
}*/

Menu& Menu::RightText(const std::wstring& text)
{
   if ((m_PrintingOption >= m_CurrentIndex) && (m_PrintingOption < (m_CurrentIndex + maxOptionsPerPage)))
   {
      g_Render.Text(
         text,
         vsh::vec2(
            position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         sizeText,
         Render::Right,
         Render::Centered,
         vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
   }

   return *this;
}

Menu& Menu::Description(const std::wstring& text)
{
   if (IsHovered())
      m_DescriptionText = text;

   return *this;
}

Menu& Menu::WhileHovered(Function fn)
{
   if (fn != nullptr && IsHovered())
      fn();

   return *this;
}

Menu& Menu::Slider(float& var, float min, float max, float step, int decimalPlaces)
{
   processOptionItemControls<float>(var, min, max, step);
   DrawMenuSlider(to_wstring(var, decimalPlaces), (var - min) / (max - min));

   if (IsHovered())
      m_SliderDelay = 50;

   return *this;
}

Menu& Menu::Slider(int& var, int min, int max)
{
   processOptionItemControls<int>(var, min, max, 1);
   DrawMenuSlider(to_wstring(var), static_cast<float>(var - min) / static_cast<float>(max - min));

   if (IsHovered())
      m_SliderDelay = 50;

   return *this;
}

Menu& Menu::Strings(const std::vector<std::wstring>& items, int& index)
{
   int min = 0;
   int max = static_cast<int>(items.size()) - 1;
   processOptionItemControls<int>(index, min, max, 1);

   if (index > static_cast<int>(items.size()) || index < 0)
   {
      g_Render.Text(
         L"error (" + to_wstring(index) + L")",
         vsh::vec2(
            position.x + sizeWidth / 2 - m_SizeBackgroundSpace / 2,
            position.y + m_SizeBackground / 2 - m_SizeBackgroundSpace - (m_PrintingOption - m_CurrentIndex) * sizeText - sizeText / 2),
         sizeText,
         Render::Right,
         Render::Centered,
         vsh::vec4(colorText.r, colorText.g, colorText.b, m_OpacityText));
      return *this;
   }

   if (IsHovered())
   {
      std::wstring selectedItem = items[index];
      std::wstring item = ((index > 0) ? L"\uF886" : L"");
      item += L" " + selectedItem + L" " + ((index < max) ? L"\uF887" : L"");

      DrawMenuStringOption(item); // L"< " + items[index] + L" >"

      m_SliderDelay = 200;
   }
   else
      DrawMenuStringOption(items[index]);

   return *this;
}

Menu& Menu::ColorPreview(float& var)
{
   Slider(var, 0.0f, 1.0f, 0.01f, 2);

   DrawMenuColorPreview(*m_ColorToEdit);
   return *this;
}

Menu& Menu::EditColor(vsh::vec4& color, bool editAlpha, Function onChangeFn)
{
   if (IsPressed())
   {
      // can't use [this]() {} PS3 compiler is GREAT isn't it! haha. NO! it's completely ass.
      // Yes I did change submenu functions to boost::function<void()> but there were so many errors and I can't be fucked
      auto ColorEditorSubmenu = [] {
         g_Menu.Title(L"Color Editor");
         g_Menu.Option(L"Red").ColorPreview(g_Menu.m_ColorToEdit->r);
         g_Menu.Option(L"Green").ColorPreview(g_Menu.m_ColorToEdit->g);
         g_Menu.Option(L"Blue").ColorPreview(g_Menu.m_ColorToEdit->b);
         if (g_Menu.m_EditingAlpha)
         {
            g_Menu.Option(L"Opacity").ColorPreview(g_Menu.m_ColorToEdit->a);
         }
         if (g_Menu.IsLeftOrRightPressed() && g_Menu.m_ColorChangeFn != nullptr)
         {
            g_Menu.m_ColorChangeFn();
            g_Menu.m_SliderDelay = 50;
         }
      };

      m_ColorToEdit = &color;
      m_EditingAlpha = editAlpha;
      m_ColorChangeFn = onChangeFn;
      ChangeSubmenu(ColorEditorSubmenu);
   }
   return *this;
}