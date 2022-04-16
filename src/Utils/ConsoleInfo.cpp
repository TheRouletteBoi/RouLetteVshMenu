#include "ConsoleInfo.hpp"

float GetTemperatureCelsius(int dev_id)
{
   uint32_t temperature = 0;
   int ret = sys_game_get_temperature(dev_id, &temperature);
   if (ret != SUCCEEDED)
       return 0.0f;
   temperature = (temperature >> 24);
   return static_cast<float>(temperature);
}

float GetTemperatureFahrenheit(int dev_id)
{
   float temp = GetTemperatureCelsius(dev_id);
   if (temp == 0.0f)
       return 0.0f;
   return (temp * 1.8) + 32.0;
}

float GetTemperatureKelvin(int dev_id)
{
   float temp = GetTemperatureCelsius(dev_id);
   if (temp == 0.0f)
       return 0.0f;
   return temp + 273.15;
}

float GetFanSpeed()
{
   uint8_t st, mode, fan_speed, duty;
   int ret = sys_sm_get_fan_policy(0, &st, &mode, &fan_speed, &duty);
   if (ret != SUCCEEDED)
       return 0.0f;
   return (static_cast<float>(fan_speed) * 100.0) / 255.0; // Fan speed is between 0x0 and 0xFF
}

memUsage_s GetMemoryUsage()
{
   memInfo_s mem_info;
   { system_call_1(352, (uint64_t)&mem_info); } // sys_memory_get_user_memory_size

   memUsage_s mem_usage;
   mem_usage.total = static_cast<float>(mem_info.total) / 1024.0;
   mem_usage.free = static_cast<float>(mem_info.available) / 1024.0;
   mem_usage.used = mem_usage.total - mem_usage.free;
   mem_usage.percent = (mem_usage.used * 100.0) / mem_usage.total;

   return mem_usage;
}

float GetFirmwareVersion()
{
    platform_info_t platform_info;
    memset(&platform_info, 0, sizeof(platform_info));
    lv2_get_platform_info(&platform_info);

    // for exemple:
    // 4.84 : 04 08 40 00
    float firmware = 0.0f;
    firmware = (float)(platform_info.firmware_version[0] & 0xF);
    firmware += (float)(platform_info.firmware_version[1] & 0xF) * 0.1f;
    firmware += (float)((platform_info.firmware_version[2] & 0xF0) >> 4) * 0.01f;

    return firmware;
}

std::string GetFirmwareType()
{
    uint64_t kernelType = 0;
    int ret = get_target_type(&kernelType);
    if (ret != SUCCEEDED)
        kernelType = 0;

    switch (kernelType)
    {
    case (uint64_t)ConsoleType::CEX:
        return "CEX";
    case (uint64_t)ConsoleType::DEX:
        return "DEX";
    case (uint64_t)ConsoleType::DEH:
        return "DEH";
    }

    return "[Unknown]";
}