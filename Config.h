#ifndef CONFIG_H
#define CONFIG_H

#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <windows.h>

#define NUMBER_OF_ENTITIES 2
#define WIDTH_PLAYER 6
#define HEIGHT_PLAYER 3

#define SIZE_MAP
#define WIDTH_SCREEN 98
#define HEIGHT_SCREEN 22
#define SIZE_FRAME ((WIDTH_SCREEN + 1) * HEIGHT_SCREEN + 1)

#define VELOCITY_PLAYER_X 20
#define VELOCITY_PLAYER_Y 10

#define TIME_FRAME (1.0 / 60.0)

#define WIDTH_SPRITE 16
#define HEIGHT_SPRITE 8
#define SIZE_SPRITE (WIDTH_SPRITE * HEIGHT_SPRITE)

#define WIDTH_ENEMY 10
#define HEIGHT_ENEMY 5
#define POSITION_X_ENEMY 60
#define POSITION_Y_ENEMY 10

#endif