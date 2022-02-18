
#include "Timers.hpp"

ChangeOvertime g_ChangeOvertime;

ValueTimer::ValueTimer(float* from, float to, uint64_t duration, uint64_t startDelay)
   : m_From(from), m_To(to), m_Duration(duration)
{
   m_Value = *from;
   m_StartTime = get_time_now() + startDelay;
}

bool ValueTimer::IsFinished()
{
   return (get_time_now() >= m_StartTime + m_Duration);
}

void ValueTimer::Update()
{
   if (!m_From)
      return;

   uint64_t timeNow = get_time_now();
   if (timeNow < m_StartTime)
      return;

   if (timeNow >= m_StartTime + m_Duration) // is finished
   {
      *m_From = m_To;
      m_From = nullptr;
      return;
   }

   uint64_t timePassed = timeNow - m_StartTime;
   float timeProgress = static_cast<float>(timePassed) / static_cast<float>(m_Duration);
   float progress = (m_To - m_Value) * timeProgress;

   *m_From = m_Value + progress;
}


bool ChangeOvertime::Add(float* from, float to, uint64_t duration, uint64_t startDelay)
{
   for (int i = 0; i < MAX_VALUE_TIMERS; i++)
   {
      if (this->m_Timers[i].IsFinished())
      {
         this->m_Timers[i] = ValueTimer(from, to, duration, startDelay);
         return true;
      }
   }
   return false;
}

void ChangeOvertime::Update()
{
   for (int i = 0; i < MAX_VALUE_TIMERS; i++)
   {
      //if (!this->_timers[i].IsFinished())
      this->m_Timers[i].Update();
   }
}

void sleep_for(uint64_t ms)
{
   sys_timer_usleep(ms * 1000);
}

uint64_t get_time_now()
{
   // is in microseconds, so divide by 1000
   return sys_time_get_system_time() / 1000;
}