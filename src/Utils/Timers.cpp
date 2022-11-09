#include "Timers.hpp"

Timer g_Timer;

uint64_t GetTimeNow()
{
    return sys_time_get_system_time() / 1000;
} 

/*
* Example useage: 
*  while (true)
*  {
*      uint64_t elapse = GetElapseAsMsec(mUpdateTime);
*      if (elapse > 1000) 
*      {
*          // update status every 1 second
*          SYS_TIMEBASE_GET(mUpdateTime);
*
*          // your code...
*      }
*  } 
*/
uint64_t GetElapseAsMsec(uint64_t from)
{
    uint64_t now;
    SYS_TIMEBASE_GET(now);
    uint64_t freq = sys_time_get_timebase_frequency(); // This function returns the Time Base frequency in Hz
    return ((now - from) * 1000 / freq);
}

void Sleep(uint64_t ms)
{
    sys_timer_usleep(ms * 1000);
}

void TimerData::Process()
{
    uint64_t timeNow = GetTimeNow();
    if (timeNow < m_StartTime)
        return;

    uint64_t endTime = m_StartTime + m_Duration;
    bool isBoolean = IsValueBoolean();

    // if it is a boolean, we aint gonna interpolate it
    if (!isBoolean && timeNow < endTime)
    {
        uint64_t timePassed = timeNow - m_StartTime;
        float deltaTime = static_cast<float>(timePassed) / static_cast<float>(m_Duration); // should be between 0.0 and 1.0
        float progress = (m_EndValue - m_StartValue) * m_Interpolate(deltaTime);

        *m_From = m_StartValue + progress;
    }

    // if is finished
    if (timeNow >= endTime)
    {
        if (!isBoolean)
            *m_From = m_EndValue;

        // find our current index in the timer stack
        for (int i = 0; i < g_Timer.m_TimerStack.size(); i++)
        {
            if (m_From == g_Timer.m_TimerStack[i].m_From)
            {
                // execute the callback
                auto cb = g_Timer.m_TimerStack[i].m_Callback;
                if (cb)
                    cb(m_From);

                // done, we erase our timer data from the stack
                g_Timer.m_TimerStack.erase(g_Timer.m_TimerStack.begin() + i);
            }
        }
    }
}

bool TimerData::IsValueBoolean()
{
    uint8_t* pToggle = reinterpret_cast<uint8_t*>(m_From);
    if (*pToggle < 2) // in case u dont know, a bool is 8 bits and is either a 0 or a 1
        return m_Interpolate == nullptr && m_Callback != nullptr;

    return false;
}

bool Timer::IsAlreadyPresent(float* pFrom)
{
    for (auto t : m_TimerStack)
        if (t.m_From == pFrom)
            return true;

    return false;
}

TimerData* Timer::FindTimer(float* pFrom)
{
    for (int i = 0; i < m_TimerStack.size(); i++)
        if (m_TimerStack[i].m_From == pFrom)
            return &m_TimerStack[i];

    return nullptr;
}

void Timer::Add(float* from, float to, uint64_t duration, uint64_t startDelay, float(*interpolation)(float), void(*callback)(float*))
{
    if (!from || (*from == to))
        return;

    bool isPresent = IsAlreadyPresent(from);

    TimerData newTimer = TimerData();
    TimerData& currentTimer = isPresent ? *FindTimer(from) : newTimer;
    currentTimer.m_From = from;
    currentTimer.m_StartValue = *from;
    currentTimer.m_EndValue = to;
    currentTimer.m_Interpolate = interpolation;
    currentTimer.m_Callback = callback;
    currentTimer.m_StartTime = GetTimeNow() + startDelay;
    currentTimer.m_Duration = duration;

    if (!isPresent)
        m_TimerStack.push_back(newTimer);
}

void Timer::Add(paf::vec2* from, paf::vec2 to, uint64_t duration, uint64_t startDelay, float(*interpolation)(float))
{
    if (!from)
        return;

    for (int i = 0; i < 2; i++)
        Add(&from->operator[](i), to[i], duration, startDelay, interpolation, nullptr);
}

void Timer::Add(paf::vec3* from, paf::vec3 to, uint64_t duration, uint64_t startDelay, float(*interpolation)(float))
{
    if (!from)
        return;

    for (int i = 0; i < 3; i++)
        Add(&from->operator[](i), to[i], duration, startDelay, interpolation, nullptr);
}

void Timer::Add(paf::vec4* from, paf::vec4 to, uint64_t duration, uint64_t startDelay, float(*interpolation)(float))
{
    if (!from)
        return;

    for (int i = 0; i < 4; i++)
        Add(&from->operator[](i), to[i], duration, startDelay, interpolation, nullptr);
}

void Timer::Add(int* from, int to, uint64_t duration, uint64_t startDelay, float(*interpolation)(float), void(*callback)(int*))
{
    Add((float*)from, *(float*)&to, duration, startDelay, interpolation, (void(*)(float*))callback);
}

void Timer::Add(bool* toggle, uint64_t delayBeforeToggle)
{
    if (!toggle)
        return;

    // it just works
    int to = *toggle ^ 1;
    Add((float*)toggle, *(float*)&to, 0, delayBeforeToggle, nullptr, [](float* pFrom)
    {
        if (pFrom)
        {
            bool* pToggle = reinterpret_cast<bool*>(pFrom);
            *pToggle ^= 1;
        }
    });
}

void Timer::OnUpdate()
{
    for (auto t : m_TimerStack)
        t.Process();
}