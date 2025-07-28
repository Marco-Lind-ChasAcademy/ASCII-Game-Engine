#ifndef TIMERS_H
#define TIMERS_H

#include "ECS.h"

static inline void timeSystemInit(Engine *engine)
{
    QueryPerformanceFrequency(&engine->time.frequency);
    QueryPerformanceCounter(&engine->time.last);
}

static inline void timeDeltaCalculate(Engine *engine)
{
    QueryPerformanceCounter(&engine->time.current);
    engine->time.delta = (double)(engine->time.current.QuadPart - engine->time.last.QuadPart) / engine->time.frequency.QuadPart;
}

#endif