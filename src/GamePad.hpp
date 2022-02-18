#pragma once

#include <cell/pad/pad_codes.h>
#include "Util/Timers.hpp"

enum eButtons : uint8_t
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
   BUTTON_MASTER,
};

extern CellPadData gPadData;
bool IsButtonDownFor(eButtons button, uint64_t millis);
bool IsButtonBinds(eButtons button1, eButtons button2);