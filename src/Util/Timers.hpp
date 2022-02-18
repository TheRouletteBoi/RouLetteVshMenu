#pragma once
#include <stdint.h>
#include <unistd.h>
#include <sys/sys_time.h>
#include <sys/timer.h>

void sleep_for(uint64_t ms);
uint64_t get_time_now();

constexpr int MAX_VALUE_TIMERS = 20;
class ValueTimer
{
public:
   ValueTimer() {}
   ValueTimer(float* from, float to, uint64_t duration, uint64_t startDelay);
   bool IsFinished();
   void Update();

private:
   float* m_From;
   float m_Value;
   float m_To;
   uint64_t m_StartTime;
   uint64_t m_Duration;
};

class ChangeOvertime
{
public:
   ChangeOvertime() {}
   bool Add(float* from, float to, uint64_t duration, uint64_t startDelay = 0);
   void Update();

private:
   ValueTimer m_Timers[MAX_VALUE_TIMERS];
};

extern ChangeOvertime g_ChangeOvertime;