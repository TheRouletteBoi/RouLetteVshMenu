#pragma once
#include <string>
#include <stdint.h>
#include "SystemCalls.hpp"


struct memInfo_s
{ // in bytes;
   uint32_t total;
   uint32_t available;
};

struct memUsage_s
{ // in kilobytes
	float total;
	float free;
	float used;
	float percent;
};

struct idps_s
{	// https://www.psdevwiki.com/ps3/IDPS
   uint32_t magic;						// 0x00
   uint16_t product_code;				// 0x04
   uint16_t product_sub_code;			// 0x06
   uint8_t chassis_check;				// 0x08
   uint8_t unknown_model_identifier;	// 0x09
   uint8_t identifier[6];				// 0x0A
};

float GetTemperatureCelsius(int dev_id);
float GetTemperatureFahrenheit(int dev_id);
float GetTemperatureKelvin(int dev_id);
float GetFanSpeed();
memUsage_s GetMemoryUsage();
float GetFirmwareVersion();
std::string GetFirmwareType();
std::string GetCurrentIdps();
std::string GetCurrentPsid();

void RandomizeIdps();
void RandomizePsid();