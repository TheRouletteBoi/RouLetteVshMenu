
#include "Base.hpp"

Menu g_Menu;

Menu::Menu(Function mainSubmenu)
   : m_MainMenu(mainSubmenu)
{
   while (!vsh::paf::View::Find("explore_plugin")) // wait until the xmb is loaded and running
      sleep_for(100);
}

bool Menu::IsInitialized()
{
   return m_Initialized;
}

void Menu::Initialize()
{
   // Display menu instructions
   vsh::ShowButtonNavigationMessage(L"Press \uF888 + \uF88D to open the menu"); // L1 + R3 to open

   m_Initialized = true;
}

bool Menu::IsOpenPressed()
{
   return IsButtonBinds(BUTTON_L1, BUTTON_R3);
}

bool Menu::IsEnterPressed()
{
   if (IsButtonDownFor(BUTTON_CROSS, 200))
   {
      PlaySound("snd_system_ok");
      return true;
   }

   return false;
}

bool Menu::IsLeftPressed()
{
   if (IsButtonDownFor(BUTTON_PAD_LEFT, 200))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsRightPressed()
{
   if (IsButtonDownFor(BUTTON_PAD_RIGHT, 200))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsLeftOrRightPressed()
{
   if (IsButtonDownFor(BUTTON_PAD_LEFT, 200) || IsButtonDownFor(BUTTON_PAD_RIGHT, 200))
   {
      PlaySound("snd_cursor");
      return true;
   }

   return false;
}

bool Menu::IsSquarePressed()
{
   if (IsButtonDownFor(BUTTON_SQUARE, 200))
   {
      PlaySound("snd_system_ok");
      return true;
   }

   return false;
}

bool Menu::IsOpened()
{
   return m_Opened;
}

void Menu::OnOpen()
{
   m_Opened = true;
   m_CurrentMenu = (m_SavedMenu == nullptr) ? m_MainMenu : m_SavedMenu;
   m_SubmenuLevel = (m_SavedMenu == nullptr) ? 0 : m_SavedSubmenuLevel;
   m_CurrentOption = (m_SavedMenu == nullptr) ? 1 : m_SavedCurrentOption;

   GUI::CreatePlanesAndText();
   GUI::ClearWidgetText();

   // Opening animation
   g_ChangeOvertime.Add(&m_OpacityHeaderAndFooter, 0.7f, 500);
   g_ChangeOvertime.Add(&m_OpacityTitle, 1.0f, 500);
   g_ChangeOvertime.Add(&m_OpacityText, 1.0f, 500, 500);
   g_ChangeOvertime.Add(&m_OpacityBackground, 0.5f, 500);
   g_ChangeOvertime.Add(&m_SizeMenu, m_SizeMenuMaximumHeight, 500);
   g_ChangeOvertime.Add(&m_SizeBackground, m_SizeBackgroundMaximumHeight, 500);
   g_ChangeOvertime.Add(&m_OpacityHighlightBar, 0.7f, 500, 500);
   m_HighlightBarPosY = position.y + (m_SizeMenuMaximumHeight / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar;

   PlaySound("snd_system_ok");
}

void Menu::OnClose()
{
   m_Opened = false;
   m_SavedMenu = m_CurrentMenu;
   m_SavedSubmenuLevel = m_SubmenuLevel;
   m_SavedCurrentOption = m_CurrentOption;

   // Closing animation
   g_ChangeOvertime.Add(&m_OpacityHeaderAndFooter, 0.0f, 500, 500);
   g_ChangeOvertime.Add(&m_OpacityTitle, 0.0f, 500, 500);
   g_ChangeOvertime.Add(&m_OpacityText, 0.0f, 500);
   g_ChangeOvertime.Add(&m_OpacityBackground, 0.0f, 500, 500);
   g_ChangeOvertime.Add(&m_SizeMenu, m_SizeMenuMinimumHeight, 500, 500);
   g_ChangeOvertime.Add(&m_SizeBackground, m_SizeBackgroundMinimumHeight, 500, 500);
   g_ChangeOvertime.Add(&m_OpacityHighlightBar, 0.0f, 500);

   PlaySound("snd_cancel");
}

void Menu::OnBack()
{
   m_SubmenuLevel--;
   m_CurrentMenu = m_LastSubmenu[m_SubmenuLevel];
   m_CurrentOption = m_LastOption[m_SubmenuLevel];

   GUI::ClearWidgetText();

   // Highlight bar movement 
   if (m_TotalOptions > m_OptionsPerPage)
      if (m_CurrentOption > m_OptionsPerPage)
         g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_OptionsPerPage - 1) * m_SizeHighlightBar, 200);
      else
         g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar, 200);
   else
      g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar, 200);

   PlaySound("snd_cancel");
}

void Menu::OnScrollUp()
{
   m_CurrentOption--;
   if (m_CurrentOption < 1)
      m_CurrentOption = m_TotalOptions;

   // Highlight bar movement 
   if (m_TotalOptions > m_OptionsPerPage)
      if (m_CurrentOption > m_OptionsPerPage)
         g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_OptionsPerPage - 1) * m_SizeHighlightBar, 200);
      else
         g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar, 200);
   else
      g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar, 200);

   PlaySound("snd_cursor");
}

void Menu::OnScrollDown()
{
   m_CurrentOption++;
   if (m_CurrentOption > m_TotalOptions)
      m_CurrentOption = 1;

   // Highlight bar movement 
   if (m_TotalOptions > m_OptionsPerPage)
      if (m_CurrentOption > m_OptionsPerPage)
         g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_OptionsPerPage - 1) * m_SizeHighlightBar, 200);
      else
         g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar, 200);
   else
      g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + (m_SizeMenu / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar, 200);

   PlaySound("snd_cursor");
}

void Menu::EnterSubmenu(Function submenu)
{
   if (submenu == nullptr)
      return;

   m_LastSubmenu[m_SubmenuLevel] = m_CurrentMenu;
   m_LastOption[m_SubmenuLevel] = m_CurrentOption;
   m_CurrentMenu = submenu;
   m_CurrentOption = 1;
   m_SubmenuLevel++;

   GUI::ClearWidgetText();

   g_ChangeOvertime.Add(&m_HighlightBarPosY, position.y + ((m_SizeMenuMaximumHeight / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (m_CurrentOption - 1) * m_SizeHighlightBar), 200);
}

void Menu::ChangeSubmenu(Function submenu)
{
   if (submenu != nullptr)
      m_SubmenuDelay = submenu;
}

void Menu::PlaySound(const char* sound)
{
   if (!m_system_plugin)
      return;

   m_system_plugin->PlaySound(sound, 1.0f, 0);
}

bool Menu::IsHovered()
{
   return m_Opened && (m_CurrentOption == m_PrintingOption);
}

bool Menu::IsPressed()
{
   if (IsHovered())
      return IsEnterPressed();

   return false;
}

void Menu::UpdateButtons()
{
   if (!m_Opened && m_OpacityHeaderAndFooter == 0.0f) // fully closed
   {
      if (IsOpenPressed())
         OnOpen();
   }
   else if (m_Opened && m_OpacityText == 1.0f) // fully opened
   {
      WhileOpen();

      if (IsButtonDownFor(BUTTON_CIRCLE, 200))
      {
         if (m_CurrentMenu == m_MainMenu)
            OnClose();
         else
            OnBack();
      }
      else if (IsButtonDownFor(BUTTON_PAD_UP, 200))
         OnScrollUp();
      else if (IsButtonDownFor(BUTTON_PAD_DOWN, 200))
         OnScrollDown();

      if (IsOpenPressed())
         OnClose();
   }
}

void Menu::WhileOpen()
{

}

void Menu::WhileClosed()
{
   // Delete widgets if the menu is closed
   GUI::DestoryPlanesAndText();
}

void Menu::UpdateGUI()
{
   m_TotalOptions = m_PrintingOption;
   m_PrintingOption = 0;

   DrawHeader();
   DrawBackground();
   DrawFooter();
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
}

void Menu::DrawHeader()
{
   GUI::DrawRect(
      vsh::vec2(position.x, position.y + (m_SizeMenu / 2) - (m_SizeHeader / 2)),
      vsh::vec2(m_SizeMenuWidth, m_SizeHeader),
      vsh::vec4(m_MenuRectColor[0], m_MenuRectColor[1], m_MenuRectColor[2], m_OpacityHeaderAndFooter),
      GUI::Alignment::Centered);

   GUI::DrawText(
      L"RouLette's Launcher",
      vsh::vec2(position.x, position.y + (m_SizeMenu / 2) - (m_SizeHeader / 2)),
      18,
      vsh::vec4(m_MenuTextColor[0], m_MenuTextColor[1], m_MenuTextColor[2], m_OpacityTitle),
      GUI::Alignment::Centered);
}

void Menu::DrawBackground()
{
   GUI::DrawRect(
      vsh::vec2(position.x, position.y - (m_SizeHeader / 2) + (m_SizeFooter / 2)),
      vsh::vec2(m_SizeMenuWidth, m_SizeBackground),
      vsh::vec4(m_MenuBackgroundColor[0], m_MenuBackgroundColor[1], m_MenuBackgroundColor[2], m_OpacityBackground),
      GUI::Alignment::Centered);
}

void Menu::DrawFooter()
{
   GUI::DrawRect(
      vsh::vec2(position.x, position.y - (m_SizeMenu / 2) + (m_SizeFooter / 2)),
      vsh::vec2(m_SizeMenuWidth, m_SizeFooter),
      vsh::vec4(m_MenuRectColor[0], m_MenuRectColor[1], m_MenuRectColor[2], m_OpacityHeaderAndFooter),
      GUI::Alignment::Centered);

   GUI::DrawText(
      L"By TheRouLetteBoi",
      vsh::vec2(position.x - (m_SizeMenuWidth / 2) + 5, position.y - (m_SizeMenu / 2) + (m_SizeFooter / 2)),
      21,
      vsh::vec4(m_MenuTextColor[0], m_MenuTextColor[1], m_MenuTextColor[2], m_OpacityText),
      GUI::Alignment::Left);
}

void Menu::DrawHighlightBar()
{
   GUI::DrawRect(
      vsh::vec2(position.x, m_HighlightBarPosY),
      vsh::vec2(m_SizeMenuWidth, m_SizeHighlightBar),
      vsh::vec4(m_MenuRectColor[0], m_MenuRectColor[1], m_MenuRectColor[2], m_OpacityHighlightBar),
      GUI::Alignment::Centered);
}

void Menu::DrawMenuText(const std::wstring& text)
{
   int optionIndex = 0;
   if (m_CurrentOption <= m_OptionsPerPage && m_PrintingOption <= m_OptionsPerPage)
      optionIndex = m_PrintingOption;
   else if ((m_PrintingOption > (m_CurrentOption - m_OptionsPerPage)) && m_PrintingOption <= m_CurrentOption)
      optionIndex = m_PrintingOption - (m_CurrentOption - m_OptionsPerPage);

   if (optionIndex != 0)
      GUI::DrawText(
         text,
         vsh::vec2(position.x - (m_SizeMenuWidth / 2) + 5, position.y + (m_SizeMenuMaximumHeight / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (optionIndex - 1) * m_SizeHighlightBar + 3),
         20,
         vsh::vec4(m_MenuTextColor[0], m_MenuTextColor[1], m_MenuTextColor[2], m_OpacityText),
         GUI::Alignment::Left);
}

void Menu::DrawMenuToggle(bool var)
{
   int optionIndex = 0;
   if (m_CurrentOption <= m_OptionsPerPage && m_PrintingOption <= m_OptionsPerPage)
      optionIndex = m_PrintingOption;
   else if ((m_PrintingOption > (m_CurrentOption - m_OptionsPerPage)) && m_PrintingOption <= m_CurrentOption)
      optionIndex = m_PrintingOption - (m_CurrentOption - m_OptionsPerPage);

   if (optionIndex != 0)
   {
      vsh::vec4 toggleColor =
         var ? vsh::vec4(m_MenuToggleColorOn[0], m_MenuToggleColorOn[1], m_MenuToggleColorOn[2], m_OpacityHighlightBar)
         : vsh::vec4(m_MenuToggleColorOff[0], m_MenuToggleColorOff[1], m_MenuToggleColorOff[2], m_OpacityHighlightBar);

      GUI::DrawTexture(
         "tex_busy",
         vsh::vec2(position.x + (m_SizeMenuWidth / 2) - 5, position.y + (m_SizeMenuMaximumHeight / 2) - m_SizeHeader - m_HighlightBarStart - (m_SizeHighlightBar / 2) - (optionIndex - 1) * m_SizeHighlightBar),
         vsh::vec2(20.0f, m_SizeHighlightBar),
         toggleColor,
         GUI::Alignment::Right);
   }
}

void Menu::OnUpdate()
{
   m_system_plugin = vsh::paf::View::Find("system_plugin");
   if (!m_system_plugin)
      return;

   m_page_autooff_guide = m_system_plugin->FindWidget("page_autooff_guide");
   if (!m_page_autooff_guide)
      return;

   if (!IsInitialized())
      Initialize();

   // Update animations
   g_ChangeOvertime.Update();

   if (!m_Opened && m_OpacityHeaderAndFooter == 0.0f)
      WhileClosed();

   // Close the menu if the xmb isn't loaded
   if (!vsh::paf::View::Find("xmb_plugin"))
   {
      if (m_Opened)
         OnClose();
      return;
   }

   UpdateButtons();
   GUI::BeginDrawing();
   UpdateGUI();
   if (m_UpdateHelperGui != nullptr)
      m_UpdateHelperGui();
   GUI::EndDrawing();


   Color _col = UpdateRGBInterpolation();
   m_MenuRectColor[0] = _col.r / 255.0f;
   m_MenuRectColor[1] = _col.g / 255.0f;
   m_MenuRectColor[2] = _col.b / 255.0f;
}

void Menu::OnHelperGUI(Function onUpdate)
{
   m_UpdateHelperGui = onUpdate;
}

void Menu::ShutDown()
{
   // Used only when the module is unloaded manually
   m_Opened = false;
   GUI::DestoryPlanesAndText();
}

void Menu::title(const std::wstring& text)
{
   GUI::DrawText(
      text, 
      vsh::vec2(position.x, position.y + (m_SizeMenuMaximumHeight / 2) - m_SizeHeader - (m_HighlightBarStart / 2)),
      20, 
      vsh::vec4(m_MenuTextColor[0], m_MenuTextColor[1], m_MenuTextColor[2], m_OpacityText),
      GUI::Alignment::Centered);
}

Menu& Menu::option(const std::wstring& text)
{
   m_PrintingOption++;
   DrawMenuText(text);
   return *this;
}

void Menu::skip(const std::wstring& text)
{
   m_PrintingOption++;
   DrawMenuText(text);

   if (IsHovered())
   {
      if (IsButtonDownFor(BUTTON_PAD_UP, 200))
      {
         OnScrollUp();
      }
      else if (IsButtonDownFor(BUTTON_PAD_DOWN, 200))
      {
         OnScrollDown();
      }
   }
}

Menu& Menu::submenu(Function sub)
{
   if (IsPressed())
      ChangeSubmenu(sub);

   return *this;
}

Menu& Menu::action(Function fn)
{
   if (IsHovered())
   {
      if (IsEnterPressed())
      {
         if (fn != nullptr)
            fn();
      }
   }

   return *this;
}

Menu& Menu::toggle(bool& var)
{
   DrawMenuToggle(var);

   if (IsPressed())
      var ^= 1;

   return *this;
}

Menu& Menu::toggle(bool& var, Function onEnable, Function onDisable)
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

// Clamps a value between a minimum float and maximum float value.
float Clamp(float value, float min, float max)
{
   if (value < min)
      value = min;
   else if (value > max)
      value = max;
   return value;
}

// Clamps value between 0 and 1 and returns value
float Clamp01(float value)
{
   if (value < 0.0f)
      return 0.0f;
   else if (value > 1.0f)
      return 1.0f;
   else
      return value;
}

// Interpolates between /a/ and /b/ by /t/. /t/ is clamped between 0 and 1.
float Lerp(float a, float b, float t)
{
   return a + (b - a) * Clamp01(t);
}

// Interpolates between /a/ and /b/ by /t/ without clamping the interpolant.
float LerpUnclamped(float a, float b, float t)
{
   return a + (b - a) * t;
}

// Interpolates between colors /a/ and /b/ by /t/.
vsh::vec4 Lerp(vsh::vec4 a, vsh::vec4 b, float t)
{
   t = Clamp01(t);
   return vsh::vec4(
      a.x + (b.x - a.x) * t,
      a.y + (b.y - a.y) * t,
      a.z + (b.z - a.z) * t,
      a.w + (b.w - a.w) * t
   );
}

// Interpolates between colors /a/ and /b/ by /t/ without clamping the interpolant
vsh::vec4 LerpUnclamped(vsh::vec4 a, vsh::vec4 b, float t)
{
   return vsh::vec4(
      a.x + (b.x - a.x) * t,
      a.y + (b.y - a.y) * t,
      a.z + (b.z - a.z) * t,
      a.w + (b.w - a.w) * t
   );
}

// Loops the value t, so that it is never larger than length and never smaller than 0.
float Repeat(float t, float length)
{
   return Clamp(t - vsh::floor(t / length) * length, 0.0f, length);
}

// PingPongs the value t, so that it is never larger than length and never smaller than 0.
float PingPong(float t, float length)
{
   t = Repeat(t, length * 2.0f);
   return length - vsh::fabs(t - length);
}

// TODO(Roulette): Change into lerp function so it is easier to read
Color Menu::UpdateRGBInterpolation()
{
   // Fades between -> Red, Orange, Yellow, Green, Blue, Purple, Pink, White, Black
   Color rgb;
   m_rainbowModeColorIndex += 1;

   rgb.r = ((m_rainbowModeColorIndex < 255) * m_rainbowModeColorIndex) + ((m_rainbowModeColorIndex >= 255) * 255) + ((m_rainbowModeColorIndex > 511) * (512 - m_rainbowModeColorIndex)) + ((m_rainbowModeColorIndex > 766) * (m_rainbowModeColorIndex - 766)) + ((m_rainbowModeColorIndex >= 1276) * (m_rainbowModeColorIndex - 1276)) + ((m_rainbowModeColorIndex > 1530) * (1530 - m_rainbowModeColorIndex)) + ((m_rainbowModeColorIndex > 1786) * (1786 - m_rainbowModeColorIndex));

   rgb.g = (m_rainbowModeColorIndex < 256) * (1) + (m_rainbowModeColorIndex > 255) * (m_rainbowModeColorIndex - 255) + (m_rainbowModeColorIndex > 510) * (510 - m_rainbowModeColorIndex) + (m_rainbowModeColorIndex > 1020) * (1020 - m_rainbowModeColorIndex) + (m_rainbowModeColorIndex > 1274) * (m_rainbowModeColorIndex - 1274) + (m_rainbowModeColorIndex > 1530) * (m_rainbowModeColorIndex - 1531) + (m_rainbowModeColorIndex > 1785) * (3571 - (2 * m_rainbowModeColorIndex));

   rgb.b = (m_rainbowModeColorIndex < 764) * (1) + (m_rainbowModeColorIndex > 765) * (m_rainbowModeColorIndex - 765) + (m_rainbowModeColorIndex > 1020) * (1020 - m_rainbowModeColorIndex) + (m_rainbowModeColorIndex > 1786) * (1786 - m_rainbowModeColorIndex);

   // reset to black
   if (m_rainbowModeColorIndex > 2040)
      m_rainbowModeColorIndex = 1;

   return rgb;
}