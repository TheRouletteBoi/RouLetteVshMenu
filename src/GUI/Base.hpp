#pragma once

#include <vsh/pafPhPlane.h>
#include <vsh/pafPhText.h>
#include <vsh/pafView.h>
#include <vsh/vshcommon.h>
#include "Util/SystemCalls.hpp"
#include "Util/Timers.hpp"
#include "GamePad.hpp"
#include "GUI.hpp"

using Function = void(*)();

class Menu
{
public:
   explicit Menu() = default;
   explicit Menu(Function mainSubmenu);
   ~Menu() noexcept = default;

   bool IsOpened();
   void OnUpdate();
   void ShutDown();

   void title(const std::wstring& text);
   Menu& option(const std::wstring& text);
   void skip(const std::wstring& text);
   Menu& submenu(Function sub);
   Menu& toggle(bool& var);
   Menu& toggle(bool& var, Function onEnable, Function onDisable);
   Menu& action(Function fn);

private:
   bool IsInitialized();
   void Initialize();
   bool IsOpenPressed();
   bool IsEnterPressed();
   bool IsLeftPressed();
   bool IsRightPressed();
   bool IsLeftOrRightPressed();
   bool IsSquarePressed();
   void OnOpen();
   void OnClose();
   void OnBack();
   void OnScrollUp();
   void OnScrollDown();
   void EnterSubmenu(Function submenu);
   void ChangeSubmenu(Function submenu);
   void PlaySound(const char* sound);
   bool IsHovered();
   bool IsPressed();

   void UpdateButtons();
   void WhileOpen();
   void WhileClosed();
   void UpdateGUI();

   void DrawMenuText(const std::wstring& text);
   void DrawHeader();
   void DrawBackground();
   void DrawFooter();
   void DrawHighlightBar();

public:
   vsh::vec2 position{ 320.0f, 0.0f };

private:
   bool m_Initialized{};
   bool m_Opened{};
   Function m_OnMain{};
   Function m_MainMenu{};
   Function m_CurrentMenu{};
   Function m_SavedMenu{};
   Function m_SubmenuDelay{};

   static const unsigned maxSubmenuLevels = 50;
   Function m_LastSubmenu[maxSubmenuLevels]{};
   size_t m_LastOption[maxSubmenuLevels]{};
   int m_SavedSubmenuLevel = 0;
   size_t m_SavedCurrentOption = 1;
   int m_SubmenuLevel = 0;
   size_t m_PrintingOption = 0;
   size_t m_TotalOptions = 0;
   size_t m_CurrentOption = 0;
   size_t m_OptionsPerPage = 10;

   float m_OpacityHeaderAndFooter = 0.0f;
   float m_OpacityBackground = 0.0f;
   float m_OpacityHighlightBar = 0.0f;
   float m_OpacityText = 0.0f;
   float m_OpacityTitle = 0.0f;

   float m_SizeMenuWidth = 240.0f;
   float m_SizeMenuMaximumHeight = 346.0f;
   float m_SizeMenuMinimumHeight = 92.0f;
   float m_SizeHeader = 66.0f;
   float m_SizeFooter = 26.0f;
   float m_SizeMenu = 92.0f;
   float m_SizeHighlightBar = 20.0f;
   float m_SizeBackgroundMaximumHeight = 254.0f;
   float m_SizeBackgroundMinimumHeight = 92.0f;
   float m_SizeBackground = 92.0f;

   float m_HighlightBarStart = 40.0f;
   float m_HighlightBarPosY = 67.0f;

   vsh::vec4 m_MenuRectColor{ 1.0f, 0.64f, 0.0f, 85.0f };
   vsh::vec4 m_MenuTextColor{ 1.0f, 1.0f, 1.0f, 1.0f };
   vsh::vec4 m_MenuBackgroundColor{ 0.0, 0.0f, 0.0f, 0.85f };

   vsh::paf::View* m_system_plugin{};
   vsh::paf::PhWidget* m_page_autooff_guide{};
};

extern Menu g_Menu;