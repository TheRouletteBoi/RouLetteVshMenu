#include "Helpers.hpp"

Helpers g_Helpers;

// TODO(Roulette): Change into lerp function so it is easier to read
Color Helpers::UpdateRGBInterpolation()
{
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