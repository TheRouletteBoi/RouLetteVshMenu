#pragma once
#include <stdint.h>
#include <unistd.h>
#include <sys/sys_time.h>
#include <sys/timer.h>

static void sleep_for(uint64_t ms)
{
   sys_timer_usleep(ms * 1000);
}

static uint64_t get_time_now()
{
   // is in microseconds, so divide by 1000
   return sys_time_get_system_time() / 1000;
}