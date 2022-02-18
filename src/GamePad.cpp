
#include "GamePad.hpp"

bool IsButtonDownFor(eButtons button, uint64_t millis)
{
   uint64_t timeNow = get_time_now();
   if (timeNow - g_Helpers.buttonLastTime[button] > millis)
   {
      uint32_t keyData = ((g_Helpers.padData.button[CELL_PAD_BTN_OFFSET_DIGITAL1] << 8) | g_Helpers.padData.button[CELL_PAD_BTN_OFFSET_DIGITAL2]);
      if (keyData & (1 << button))
      {
         g_Helpers.buttonLastTime[button] = timeNow;
         return true;
      }
   }
   return false;
}

bool IsButtonBinds(eButtons button1, eButtons button2)
{
   return IsButtonDownFor(button1, 0) && IsButtonDownFor(button2, 0);
}