#include "Input.hpp"

CInput g_Input;

CellPadData* CInput::GetInputData()
{
   return &m_InputData;
}

void CInput::SetInputData(CellPadData* data)
{
   vsh::memcpy(&m_InputData, data, sizeof(CellPadData));
}

void CInput::ClearInputData()
{
   vsh::memset(&m_InputData, 0, sizeof(CellPadData));
   m_InputData.button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_X] =
      m_InputData.button[CELL_PAD_BTN_OFFSET_ANALOG_RIGHT_Y] =
      m_InputData.button[CELL_PAD_BTN_OFFSET_ANALOG_LEFT_X] =
      m_InputData.button[CELL_PAD_BTN_OFFSET_ANALOG_LEFT_Y] = 128;
}

bool CInput::IsButtonDownFor(Buttons button, uint64_t delay)
{
   uint64_t timeNow = GetTimeNow();
   if (timeNow - m_InputButtonLastTime[button] > delay)
   {
      uint32_t buttonData = ((m_InputData.button[CELL_PAD_BTN_OFFSET_DIGITAL1] << 8) | m_InputData.button[CELL_PAD_BTN_OFFSET_DIGITAL2]);
      if (buttonData & (1 << button))
      {
         m_InputButtonLastTime[button] = timeNow;
         return true;
      }
   }
   return false;
}

bool CInput::IsButtonBinds(Buttons button1, Buttons button2)
{
   return IsButtonDownFor(button1) && IsButtonDownFor(button2);
}

double CInput::GetAnalogInput(Analogs analog)
{
   int16_t input = m_InputData.button[4 + analog] - 128;
   if ((input > -m_InputAnalogDeadzone) && (input < m_InputAnalogDeadzone))
      return 0.0;

   return static_cast<double>(input) / 128.0;
}

double CInput::GetRightAnalogX()
{
   return GetAnalogInput(ANALOG_RIGHT_X);
}

double CInput::GetRightAnalogY()
{
   return GetAnalogInput(ANALOG_RIGHT_Y);
}

double CInput::GetLeftAnalogX()
{
   return GetAnalogInput(ANALOG_LEFT_X);
}

double CInput::GetLeftAnalogY()
{
   return GetAnalogInput(ANALOG_LEFT_Y);
}

void CInput::SetAnalogDeadzone(short deadzone)
{
   m_InputAnalogDeadzone = deadzone;
}