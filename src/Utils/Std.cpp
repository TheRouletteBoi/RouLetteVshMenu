#include "Std.hpp"

template<>
std::string to_string(uint64_t value)
{
   char buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::snprintf(buf, sizeof(buf), "%llu", value);
   return std::string(buf);
}

std::string to_string(float value, int decimalPlaces)
{
   char buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::snprintf(buf, sizeof(buf), "%.*f", decimalPlaces, value);
   return std::string(buf);
}

template<>
std::string to_string(double value)
{
   char buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::snprintf(buf, sizeof(buf), "%.2f", value);
   return std::string(buf);
}

template<>
std::wstring to_wstring(uint64_t value)
{
   wchar_t buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::swprintf(buf, sizeof(buf), L"%llu", value);
   return std::wstring(buf);
}

std::wstring to_wstring(float value, int decimalPlaces)
{
   wchar_t buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::swprintf(buf, sizeof(buf), L"%.*f", decimalPlaces, value);
   return std::wstring(buf);
}

template<>
std::wstring to_wstring(double value)
{
   wchar_t buf[25];
   vsh::memset(buf, 0, 25);
   int len = vsh::swprintf(buf, sizeof(buf), L"%.2f", value);
   return std::wstring(buf);
}

uint32_t mix_time_seed(std::clock_t a, std::time_t b, sys_pid_t c)
{
   a = a - b;  a = a - c;  a = a ^ (c >> 13);
   b = b - c;  b = b - a;  b = b ^ (a << 8);
   c = c - a;  c = c - b;  c = c ^ (b >> 13);
   a = a - b;  a = a - c;  a = a ^ (c >> 12);
   b = b - c;  b = b - a;  b = b ^ (a << 16);
   c = c - a;  c = c - b;  c = c ^ (b >> 5);
   a = a - b;  a = a - c;  a = a ^ (c >> 3);
   b = b - c;  b = b - a;  b = b ^ (a << 10);
   c = c - a;  c = c - b;  c = c ^ (b >> 15);
   return c;
}