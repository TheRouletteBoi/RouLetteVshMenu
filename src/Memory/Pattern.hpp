#pragma once
#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/process.h>
#include "Memory.hpp"

constexpr uintptr_t gBaseAddress = 0x00010200;    // first sub in the eboot in ida
constexpr size_t gInfo_SizeOfImage = 0x008FFFFF;  // open the eboot in ida then go all the way to the end and then added FFFF to the last bytes

bool DataCompare(const uint8_t* pbData, const uint8_t* pbMask, const char* szMask);
uintptr_t FindPattern(uintptr_t address, uint32_t length, uint8_t* bytes, const char* mask);
uintptr_t FindPatternInTextSegment(uint8_t* bytes, const char* mask);
uint32_t ReadHighLow(uint32_t address, uint32_t highAdditive, uint32_t lowAdditive);
uint32_t ResolveBranch(uint32_t branchAddress);