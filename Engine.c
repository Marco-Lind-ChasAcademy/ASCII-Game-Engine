#include "Engine.h"

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