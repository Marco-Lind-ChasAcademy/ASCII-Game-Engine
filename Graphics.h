#ifndef GRAPHICS
#define GRAPHICS

#include "ECS.h"
#include "string.h"

#define MAP_SIZE
#define SCREEN_WIDTH 98
#define SCREEN_HEIGHT 22
#define FRAME_SIZE ((SCREEN_WIDTH + 1) * SCREEN_HEIGHT + 1)

typedef union
{
    char frame[FRAME_SIZE];
    struct
    {
        char newline;
        union
        {
            char flat[(SCREEN_WIDTH + 1) * SCREEN_HEIGHT];
            char grid[SCREEN_HEIGHT][SCREEN_WIDTH + 1];
        };
    };
    
} FrameBuffer;

typedef union
{
    int flat[(SCREEN_WIDTH + 1) * SCREEN_HEIGHT];
    int grid[SCREEN_HEIGHT][SCREEN_WIDTH + 1];
} MapBuffer;


FrameBuffer frame = {'\n'};
MapBuffer map;

inline void copyMapToFrameBuffer()
{
    memcpy(&frame.flat, &map.flat, sizeof(frame.flat));
}

#endif