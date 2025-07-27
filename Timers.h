#ifndef TIMERS_H
#define TIMERS_H

#include "ECS.h"
#include <windows.h>

typedef struct
{
    LARGE_INTEGER current, last, frequency;
    double delta, frame;
} TimeSystem;

static inline void timeSystemInit(TimeSystem *time)
{
    QueryPerformanceFrequency(&time->frequency);
    QueryPerformanceCounter(&time->last);
}

static inline void timeDeltaCalculate(TimeSystem *time)
{
    QueryPerformanceCounter(&time->current);
    time->delta = (double)(time->current.QuadPart - time->last.QuadPart) / time->frequency.QuadPart;
}

#endif