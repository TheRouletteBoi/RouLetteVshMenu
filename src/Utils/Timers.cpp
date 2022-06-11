
#include "Timers.hpp"

ChangeOvertime g_ChangeOvertime;

uint64_t GetTimeNow()
{
   return sys_time_get_system_time() / 1000;
}

uint64_t GetCurrentTick()
{
    uint64_t freq = sys_time_get_timebase_frequency(); // This function returns the Time Base frequency in Hz
    double dFreq = ((double)freq) / 1000.0;

    uint64_t newTime;
    SYS_TIMEBASE_GET(newTime); // Get the current Time Base

    return (uint64_t)((double(newTime)) / dFreq);
}

void Sleep(uint64_t ms)
{
   sys_timer_usleep(ms * 1000);
}

ValueTimer::ValueTimer(float* from, float to, uint64_t duration, uint64_t startDelay)
   : m_From(from), m_To(to), m_Duration(duration)
{
   m_StartValue = *from;
   m_StartTime = GetTimeNow() + startDelay;
}

bool ValueTimer::IsFinished()
{
   return m_From == nullptr;
}

bool ValueTimer::IsSame(float* from)
{
   return m_From == from;
}

void ValueTimer::Update()
{
   if (!m_From)
      return;

   uint64_t timeNow = GetTimeNow();
   if (timeNow < m_StartTime)
      return;

   if (timeNow >= m_StartTime + m_Duration)
   {
      *m_From = m_To;
      m_From = nullptr;
      return;
   }

   uint64_t timePassed = timeNow - m_StartTime;
   float timeProgress = static_cast<float>(timePassed) / static_cast<float>(m_Duration);
   float progress = (m_To - m_StartValue) * timeProgress;

   *m_From = m_StartValue + progress;
}


bool ChangeOvertime::Add(float* from, float to, uint64_t duration, uint64_t startDelay, bool ignoreCheck)
{
   if (!ignoreCheck && AlreadyExist(from))
      return false;

   for (int i = 0; i < MAX_VALUE_TIMERS; i++)
   {
      if (m_Timers[i].IsFinished())
      {
         m_Timers[i] = ValueTimer(from, to, duration, startDelay);
         return true;
      }
   }
   return false;
}

bool ChangeOvertime::Add(vsh::vec2* from, vsh::vec2 to, uint64_t duration, uint64_t startDelay, bool ignoreCheck)
{
   for (int i = 0; i < 2; i++)
      if (!Add(&from->v[i], to.v[i], duration, startDelay, ignoreCheck))
         return false;
   return true;
}

bool ChangeOvertime::Add(vsh::vec3* from, vsh::vec3 to, uint64_t duration, uint64_t startDelay, bool ignoreCheck)
{
   for (int i = 0; i < 3; i++)
      if (!Add(&from->v[i], to.v[i], duration, startDelay, ignoreCheck))
         return false;
   return true;
}

bool ChangeOvertime::Add(vsh::vec4* from, vsh::vec4 to, uint64_t duration, uint64_t startDelay, bool ignoreCheck)
{
   for (int i = 0; i < 4; i++)
      if (!Add(&from->v[i], to.v[i], duration, startDelay, ignoreCheck))
         return false;
   return true;
}

void ChangeOvertime::Update()
{
   for (int i = 0; i < MAX_VALUE_TIMERS; i++)
      m_Timers[i].Update();
}

bool ChangeOvertime::AlreadyExist(float* from)
{
   for (int i = 0; i < MAX_VALUE_TIMERS; i++)
   {
      if (m_Timers[i].IsSame(from))
         return true;
   }

   return false;
}