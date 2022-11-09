#pragma once
#include <stdint.h>
#include <unistd.h>
#include <sys/sys_time.h>
#include <sys/timer.h>
#include <sys/time_util.h>
#include <vsh/paf.hpp>

uint64_t GetTimeNow();
uint64_t GetElapseAsMsec(uint64_t from);
void Sleep(uint64_t ms);

namespace Ease
{
    static float Linear(float t) 
    {
        return t;
    }

    static float InSine(float t) 
    {
        return vsh::f_sinf(1.5707963 * t);
    }

    static float OutSine(float t) 
    {
        return 1 + vsh::f_sinf(1.5707963 * (--t));
    }

    static float InOutSine(float t) 
    {
        return 0.5 * (1 + vsh::f_sinf(3.1415926 * (t - 0.5)));
    }

    static float InQuad(float t) 
    {
        return t * t;
    }

    static float OutQuad(float t) 
    {
        return t * (2 - t);
    }

    static float InOutQuad(float t) 
    {
        return t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1;
    }

    static float InCubic(float t) 
    {
        return t * t * t;
    }

    static float OutCubic(float t) 
    {
        return 1 + (--t) * t * t;
    }

    static float InOutCubic(float t) 
    {
        return t < 0.5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
    }

    static float InQuart(float t) 
    {
        t *= t;
        return t * t;
    }

    static float OutQuart(float t) 
    {
        t = (--t) * t;
        return 1 - t * t;
    }

    static float InOutQuart(float t) 
    {
        if (t < 0.5) 
        {
            t *= t;
            return 8 * t * t;
        }
        t = (--t) * t;
        return 1 - 8 * t * t;
    }

    static float InQuint(float t) 
    {
        float t2 = t * t;
        return t * t2 * t2;
    }

    static float OutQuint(float t) 
    {
        float t2 = (--t) * t;
        return 1 + t * t2 * t2;
    }

    static float InOutQuint(float t) 
    {
        float t2;
        if (t < 0.5) 
        {
            t2 = t * t;
            return 16 * t * t2 * t2;
        }
        t2 = (--t) * t;
        return 1 + 16 * t * t2 * t2;
    }

    static float InExpo(float t) 
    {
        return (vsh::pow(2, 8 * t) - 1) / 255;
    }

    static float OutExpo(float t) 
    {
        return 1 - vsh::pow(2, -8 * t);
    }

    static float InOutExpo(float t) 
    {
        if (t < 0.5)
            return (vsh::pow(2, 16 * t) - 1) / 510;
        return 1 - 0.5 * vsh::pow(2, -16 * (t - 0.5));
    }

    static float InCirc(float t) 
    {
        return 1 - vsh::sqrtf(1 - t);
    }

    static float OutCirc(float t) 
    {
        return vsh::sqrtf(t);
    }

    static float InOutCirc(float t) 
    {
        if (t < 0.5)
            return (1 - vsh::sqrtf(1 - 2 * t)) * 0.5;
        return (1 + vsh::sqrtf(2 * t - 1)) * 0.5;
    }

    static float InBack(float t) 
    {
        return t * t * (2.70158 * t - 1.70158);
    }

    static float OutBack(float t) 
    {
        return 1 + (--t) * t * (2.70158 * t + 1.70158);
    }

    static float InOutBack(float t) 
    {
        if (t < 0.5)
            return t * t * (7 * t - 2.5) * 2;
        return 1 + (--t) * t * 2 * (7 * t + 2.5);
    }

    static float InElastic(float t) 
    {
        float t2 = t * t;
        return t2 * t2 * vsh::f_sinf(t * 3.1415926 * 4.5);
    }

    static float OutElastic(float t) 
    {
        float t2 = (t - 1) * (t - 1);
        return 1 - t2 * t2 * vsh::f_cosf(t * 3.1415926 * 4.5);
    }

    static float InOutElastic(float t) 
    {
        float t2;
        if (t < 0.45) 
        {
            t2 = t * t;
            return 8 * t2 * t2 * vsh::f_sinf(t * 3.1415926 * 9);
        }

        if (t < 0.55)
            return 0.5 + 0.75 * vsh::f_sinf(t * 3.1415926 * 4);

        t2 = (t - 1) * (t - 1);
        return 1 - 8 * t2 * t2 * vsh::f_sinf(t * 3.1415926 * 9);
    }

    static float InBounce(float t) 
    {
        return vsh::pow(2, 6 * (t - 1)) * vsh::fabs(vsh::f_sinf(t * 3.1415926 * 3.5));
    }

    static float OutBounce(float t) 
    {
        return 1 - vsh::pow(2, -6 * t) * vsh::fabs(vsh::f_sinf(t * 3.1415926 * 3.5));
    }

    static float InOutBounce(float t) 
    {
        if (t < 0.5)
            return 8 * vsh::pow(2, 8 * (t - 1)) * vsh::fabs(vsh::f_sinf(t * 3.1415926 * 7));
        return 1 - 8 * vsh::pow(2, -8 * t) * vsh::fabs(vsh::f_sinf(t * 3.1415926 * 7));
    }
}

class TimerData
{
public:
    TimerData() = default;
    void Process();

    bool IsValueBoolean();

public:
    float* m_From{};
    float m_StartValue{};
    float m_EndValue{};

    float(*m_Interpolate)(float timeFactor){};
    void(*m_Callback)(float* pFrom){};

    uint64_t m_StartTime{};
    uint64_t m_Duration{};
};

class Timer
{
public:
    Timer() = default;

    bool IsAlreadyPresent(float* pFrom);
    TimerData* FindTimer(float* pFrom);

    void Add(float* from, float to, uint64_t duration, uint64_t startDelay = 0, float(*interpolation)(float) = Ease::Linear, void(*callback)(float*) = nullptr);
    void Add(paf::vec2* from, paf::vec2 to, uint64_t duration, uint64_t startDelay = 0, float(*interpolation)(float) = Ease::Linear);
    void Add(paf::vec3* from, paf::vec3 to, uint64_t duration, uint64_t startDelay = 0, float(*interpolation)(float) = Ease::Linear);
    void Add(paf::vec4* from, paf::vec4 to, uint64_t duration, uint64_t startDelay = 0, float(*interpolation)(float) = Ease::Linear);
    void Add(int* from, int to, uint64_t duration, uint64_t startDelay = 0, float(*interpolation)(float) = Ease::Linear, void(*callback)(int*) = nullptr);
    void Add(bool* toggle, uint64_t delayBeforeToggle);

    void OnUpdate();
public:
    std::vector<TimerData> m_TimerStack{};
};

extern Timer g_Timer;