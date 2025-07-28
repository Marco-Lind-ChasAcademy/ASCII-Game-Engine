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
            .x = {WIDTH_SCREEN / 4, POSITION_X_ENEMY},
            .y = {HEIGHT_SCREEN / 2, POSITION_Y_ENEMY}
        },
        .velocity =
        {
            .x = {VELOCITY_PLAYER_X},
            .y = {VELOCITY_PLAYER_Y}
        },
        .hitbox =
        {
            .height = {HEIGHT_PLAYER, HEIGHT_ENEMY},
            .width = {WIDTH_PLAYER, WIDTH_ENEMY}
        },
        .size =
        {
            .x = {WIDTH_PLAYER, WIDTH_ENEMY},
            .y = {HEIGHT_PLAYER, HEIGHT_ENEMY}
        }
    },
    .buffer =
    {
        .frame.newline = '\n'
    }
};