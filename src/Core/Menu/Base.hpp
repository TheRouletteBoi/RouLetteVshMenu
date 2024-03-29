#pragma once

#include <vsh/paf.hpp>
#include <vsh/vshcommon.hpp>
#include "Utils/SystemCalls.hpp"
#include "Utils/Timers.hpp"
#include "Utils/Std.hpp"
#include "Core/Input.hpp"
#include "Core/Renderer.hpp"
#include "Core/Helpers.hpp"

using Function = void(*)();
using KeyboardHandler = void(*)(const std::wstring&);

class Menu
{
public:
   Menu() = default;
   Menu(Function mainSubmenu);

   bool IsOpened();
   bool IsMoving();
   void SetMovingState(bool state);
   void OnUpdate();

   void Title(const std::wstring& text);
   Menu& Option(const std::wstring& text);
   Menu& Submenu(Function sub);
   Menu& Skip();
   Menu& Toggle(bool& var);
   Menu& Toggle(bool& var, Function onEnable, Function onDisable);
   Menu& Action(Function fn);
   //Menu& ActionHeavyweight(boost::function<void()> fn);
   Menu& RightText(const std::wstring& text);
   Menu& Description(const std::wstring& text);
   Menu& WhileHovered(Function fn);
   Menu& Slider(float& var, float min, float max, float step, int decimalPlaces);
   Menu& Slider(int& var, int min, int max);
   Menu& Strings(const std::vector<std::wstring>& display, int& index);
   Menu& ColorPreview(float& var);
   Menu& EditColor(paf::vec4& color, bool editAlpha, Function onChangeFn = nullptr);
   Menu& Keyboard(KeyboardHandler handler);

private:
   bool IsInitialized();
   void Initialize();

   bool IsOpenPressed();
   bool IsEnterPressed();
   bool IsBackPressed();
   bool IsUpPressed();
   bool IsDownPressed();
   bool IsLeftPressed();
   bool IsRightPressed();
   bool IsLeftOrRightPressed();
   bool IsHovered();
   bool IsPressed();

   void OnOpen();
   void OnClose();
   void OnBack();
   void OnScrollUp();
   void OnScrollDown();

   void EnterSubmenu(Function submenu);
   void ChangeSubmenu(Function submenu);
   void PlaySound(const char* sound);

   void WhileOpen();
   void WhileClosed();

   void UpdateButtons();
   void UpdatePosition();
   void UpdateBackgroundSize();
   void UpdateHighlightBarPos();
   void UpdateUI();

   void DrawHeader();
   void DrawBody();
   void DrawHighlightBar();
   void DrawFooter();
   void DrawDescription();
   void DrawInstructions();
   void DrawMovingHelp();
   void DrawYesNoPrompt(const std::wstring& text);

   void DrawMenuTitle(const std::wstring& text);
   void DrawMenuOption(const std::wstring& text);
   void DrawMenuToggle(bool var);
   void DrawMenuSlider(const std::wstring& text, float progress);
   void DrawMenuStringOption(const std::wstring& item);
   void DrawMenuColorPreview(const paf::vec4& color);

   template <typename T>
   void processOptionItemControls(T& var, T min, T max, T step)
   {
      if (IsHovered())
      {
         if (IsLeftPressed())
         {
            if (var <= min)
               var = min;
            else
               var -= step;
         }

         if (var < min)
            var = min;

         if (IsRightPressed())
         {
            if (var >= max)
               var = max;
            else
               var += step;
         }

         if (var > max)
            var = max;
      }
   }

public:
   bool stateMoving{};
   paf::vec2 position{ 297.0, 14.0 };
   paf::vec2 safeArea{ 31.0, 18.0 };
   float sizeHeader = 60.0;
   float sizeWidth = 300.0;
   float sizeText = 20.0;
   float sizeTextHeader = 30.0;
   float sizeTextDescription = 18.0;
   paf::vec4 colorMenu{ 1.0, 0.0, 0.0, 0.80 };
   paf::vec4 colorBackground{ 0, 0, 0, 0.65 };
   paf::vec4 colorText{ 1, 1, 1, 1 };
   paf::vec4 colorFillerBar{ 0.0, 1.0, 1.0, 0.9 };
   paf::vec4 colorFillerCursor{ 0.423, 0.443, 0.415, 0.9 };
   paf::vec4 colorToggleOn{ 0.0, 1.0, 0.0, 1.0 };
   paf::vec4 colorToggleOff{ 1.0, 0.0, 0.0, 1.0 };
   bool displayYesNoPrompt{};

private:
   bool m_StateInitialized{};
   bool m_StateOpened{};

   Function m_OnMain{};
   Function m_MainMenu{};
   Function m_CurrentMenu{};
   Function m_SavedMenu{};
   Function m_SubmenuDelay{};

   static const unsigned maxSubmenuLevels = 20;
   static const unsigned maxOptionsPerPage = 10;
   Function m_LastSubmenu[maxSubmenuLevels]{};
   int m_LastOption[maxSubmenuLevels]{};
   int m_LastIndex[maxSubmenuLevels]{};

   int m_SavedSubmenuLevel = 0;
   int m_SavedCurrentOption = 1;
   int m_SavedCurrentIndex = 1;

   int m_SubmenuLevel = 0;
   int m_PrintingOption = 0;
   int m_TotalOptions = 0;
   int m_CurrentOption = 0;
   int m_CurrentIndex = 0;

   float m_OpacityGlobal = 0;
   float m_OpacityBackground = 0;
   float m_OpacityHighlightBar = 0;
   float m_OpacityText = 0;

   float m_SizeBackground = 0;
   float m_SizeBackgroundSpace = 10;

   float m_HighlightBarPosY = 0;

   uint64_t m_SliderDelay = 200;

   std::wstring m_DescriptionText;

   bool m_EditingAlpha = true;
   paf::vec4* m_ColorToEdit{};
   Function m_ColorChangeFn{};
};

extern Menu g_Menu;