#ifndef GRAPHICS
#define GRAPHICS

#include "GameLogic.h"
//#include "Engine.h"
#include <stdio.h>

typedef union
{
    char frame[SIZE_FRAME];
    struct
    {
        char newline;
        union
        {
            char flat[(WIDTH_SCREEN + 1) * HEIGHT_SCREEN];
            char grid[HEIGHT_SCREEN][WIDTH_SCREEN + 1];
        };
    };
    
} FrameBuffer;

typedef union
{
    char flat[(WIDTH_SCREEN + 1) * HEIGHT_SCREEN];
    char grid[HEIGHT_SCREEN][WIDTH_SCREEN + 1];
} MapBuffer;

typedef union
{
    char flat[SIZE_SPRITE];
    char grid[HEIGHT_SPRITE][WIDTH_SPRITE];
} Sprite;

typedef struct
{
    MapBuffer map;
    FrameBuffer frame;
    Sprite sprite[NUMBER_OF_ENTITIES];

} BufferSystem;






static inline void mapToFrameBufferCopy(BufferSystem *buffer)
{
    memcpy(&buffer->frame.flat, &buffer->map.flat, sizeof(buffer->frame.flat));
}

static inline void entityDraw(EntityComponentSystem *ecs, BufferSystem *buffer, TimeSystem *time, int entity)
{
    movePos(ecs, time, entity);
    // Top left corner
    int x_index = ecs->position.x[entity] - ecs->size.x[entity] / 2;
    int y_index = ecs->position.y[entity] - ecs->size.y[entity] / 2;

    for (int i = 0; i < ecs->size.y[entity]; i++)
    {
        memcpy(&buffer->frame.grid[y_index][x_index], buffer->sprite[PLAYER].grid[i], ecs->size.x[entity]);
        y_index += 1;
    }
}

static inline void frameDraw(BufferSystem *buffer)
{
    fwrite(buffer->frame.frame, 1, SIZE_FRAME, stdout);
}

#endif