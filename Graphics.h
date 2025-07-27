#ifndef GRAPHICS
#define GRAPHICS

#include "GameLogic.h"

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