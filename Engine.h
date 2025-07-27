#ifndef ENGINE_H
#define ENGINE_H

#include "Level.h"

typedef struct
{
    TimeSystem time;
    EntityComponentSystem ecs;
    BufferSystem buffer;
} Engine;

Engine engine =
{
    .time =
    {
        .frame = TIME_FRAME
    },
    .ecs =
    {
        .position =
        {
            .x = {WIDTH_SCREEN / 4},
            .y = {HEIGHT_SCREEN / 2}
        },
        .velocity =
        {
            .x = {VELOCITY_PLAYER_X},
            .y = {VELOCITY_PLAYER_Y}
        },
        .size =
        {
            .x = {WIDTH_PLAYER},
            .y = {HEIGHT_PLAYER}
        }
    },
    .buffer =
    {
        .frame.newline = '\n'
    }
};


#endif