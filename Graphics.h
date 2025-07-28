#ifndef GRAPHICS
#define GRAPHICS

#include "GameLogic.h"

static inline void mapToFrameBufferCopy(Engine *engine)
{
    memcpy(&engine->buffer.frame.flat, &engine->buffer.map.flat, sizeof(engine->buffer.frame.flat));
}

static inline void entityDraw(Engine *engine, int entity)
{
    // Top left corner
    int x_index = engine->ecs.position.x[entity] - engine->ecs.size.x[entity] / 2;
    int y_index = engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2;

    for (int i = 0; i < engine->ecs.size.y[entity]; i++)
    {
        memcpy(&engine->buffer.frame.grid[y_index][x_index], engine->buffer.sprite[entity].grid[i], engine->ecs.size.x[entity]);
        y_index += 1;
    }
}

static inline void playerDraw(Engine *engine, int entity)
{
    movePos(engine, entity);
    entityDraw(engine, entity);
}

static inline void frameDraw(Engine *engine)
{
    fwrite(engine->buffer.frame.frame, 1, SIZE_FRAME, stdout);
}

#endif