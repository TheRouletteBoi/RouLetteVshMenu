
#include "GamePad.hpp"

CellPadData gPadData;
uint64_t gButtonLastTime[17];

bool IsButtonDownFor(eButtons button, uint64_t millis)
{
   uint64_t timeNow = get_time_now();
   if (timeNow - gButtonLastTime[button] > millis)
   {
      uint32_t keyData = ((gPadData.button[CELL_PAD_BTN_OFFSET_DIGITAL1] << 8) | gPadData.button[CELL_PAD_BTN_OFFSET_DIGITAL2]);
      if (keyData & (1 << button))
      {
         gButtonLastTime[button] = timeNow;
         return true;
      }
   }
   return false;
}

bool IsButtonBinds(eButtons button1, eButtons button2)
{
   return IsButtonDownFor(button1, 0) && IsButtonDownFor(button2, 0);
}