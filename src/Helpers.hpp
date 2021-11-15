#pragma once
#include <string>

struct Color
{
   uint8_t r;
   uint8_t g;
   uint8_t b;
   uint8_t a;
};

class Helpers
{
public:
   Color UpdateRGBInterpolation();

public:
   bool xmbRainbowMode = true;

private:
   int m_rainbowModeColorIndex = 0;
};

extern Helpers g_Helpers;