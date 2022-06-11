#pragma once
#include <stdint.h>
#include <unistd.h>
#include <sys/sys_time.h>
#include <sys/timer.h>
#include <sys/time_util.h>
#include "vsh/vshmath.h"

uint64_t GetTimeNow();
uint64_t GetCurrentTick();
void Sleep(uint64_t ms);

constexpr int MAX_VALUE_TIMERS = 20;
class ValueTimer
{
public:
   ValueTimer() {}
   ValueTimer(float* from, float to, uint64_t duration, uint64_t startDelay);

   bool IsFinished();
   bool IsSame(float* from);
   void Update();

private:
   float* m_From;
   float m_StartValue;
   float m_To;
   uint64_t m_StartTime;
   uint64_t m_Duration;
};

class ChangeOvertime
{
public:
   ChangeOvertime() {}
   bool Add(float* from, float to, uint64_t duration, uint64_t startDelay = 0, bool ignoreCheck = false);
   bool Add(vsh::vec2* from, vsh::vec2 to, uint64_t duration, uint64_t startDelay = 0, bool ignoreCheck = false);
   bool Add(vsh::vec3* from, vsh::vec3 to, uint64_t duration, uint64_t startDelay = 0, bool ignoreCheck = false);
   bool Add(vsh::vec4* from, vsh::vec4 to, uint64_t duration, uint64_t startDelay = 0, bool ignoreCheck = false);
   void Update();

private:
   bool AlreadyExist(float* from);

private:
   ValueTimer m_Timers[MAX_VALUE_TIMERS];
};
extern ChangeOvertime g_ChangeOvertime;