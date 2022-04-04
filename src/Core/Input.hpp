#pragma once
#include <cell/pad/pad_codes.h>
#include "Utils/Timers.hpp"

class CInput
{
public:
   enum Buttons
   {
      BUTTON_L2,
      BUTTON_R2,
      BUTTON_L1,
      BUTTON_R1,
      BUTTON_TRIANGLE,
      BUTTON_CIRCLE,
      BUTTON_CROSS,
      BUTTON_SQUARE,
      BUTTON_SELECT,
      BUTTON_L3,
      BUTTON_R3,
      BUTTON_START,
      BUTTON_PAD_UP,
      BUTTON_PAD_RIGHT,
      BUTTON_PAD_DOWN,
      BUTTON_PAD_LEFT,
      BUTTON_PS
   };

   enum Analogs
   {
      ANALOG_RIGHT_X,
      ANALOG_RIGHT_Y,
      ANALOG_LEFT_X,
      ANALOG_LEFT_Y
   };

public:
   explicit CInput() = default;
   ~CInput() noexcept = default;

   CellPadData* GetInputData();
   void SetInputData(CellPadData* data);
   void ClearInputData();
   bool IsButtonDownFor(Buttons button, uint64_t delay = 0);
   bool IsButtonBinds(Buttons button1, Buttons button2);
   // X Axis: -1.00 = Left, 1.00 = Right
   // Y Axis: -1.00 = Top, 1.00 = Bottom
   double GetAnalogInput(Analogs analog);
   double GetRightAnalogX();
   double GetRightAnalogY();
   double GetLeftAnalogX();
   double GetLeftAnalogY();
   // Deadzone is set to 20 by default
   void SetAnalogDeadzone(short deadzone);

private:
   CellPadData m_InputData{};
   unsigned int m_InputButtonLastTime[16]{};
   short m_InputAnalogDeadzone = 20;
};

extern CInput g_Input;