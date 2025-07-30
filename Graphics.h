#ifndef GRAPHICS
#define GRAPHICS

#include "GameLogic.h"

int animationDrawPlayerCircling(Engine *engine, double time_between_animation_frames);

static inline void mapToFrameBufferCopy(Engine *engine)
{
    memcpy(&engine->buffer.frame.flat, &engine->buffer.map.flat, sizeof(engine->buffer.frame.flat));
}

static inline void enemyDraw(Engine *engine)
{
    // Top left corner
    int x_index = engine->ecs.position.x[ENEMY] - engine->ecs.size.x[ENEMY] / 2;
    int y_index = engine->ecs.position.y[ENEMY] - engine->ecs.size.y[ENEMY] / 2;

    for (int i = 0; i < engine->ecs.size.y[ENEMY]; i++)
    {
        memcpy(&engine->buffer.frame.grid[y_index][x_index], engine->buffer.sprite.enemy.grid[i], engine->ecs.size.x[ENEMY]);
        y_index += 1;
    }
}

static inline void playerDraw(Engine *engine)
{
    movePos(engine, PLAYER);

    int x_index = engine->ecs.position.x[PLAYER] - engine->ecs.size.x[PLAYER] / 2;
    int y_index = engine->ecs.position.y[PLAYER] - engine->ecs.size.y[PLAYER] / 2;

    for (int i = 0; i < engine->ecs.size.y[PLAYER]; i++)
    {
        memcpy(&engine->buffer.frame.grid[y_index][x_index], engine->buffer.sprite.player.grid[i], engine->ecs.size.x[PLAYER]);
        y_index += 1;
    }
}

static inline void drawString(Engine *engine, int entity, char *string, int *map_y_index, int map_x_index)
{
    memcpy(&engine->buffer.frame.grid[*map_y_index][map_x_index], string, engine->ecs.size.x[entity]);
    *map_y_index += 1;
}

static inline void playerDrawIndex(Engine *engine, int index)
{
    movePos(engine, PLAYER);

    int map_x_index = engine->ecs.position.x[PLAYER] - engine->ecs.size.x[PLAYER] / 2;
    int map_y_index = engine->ecs.position.y[PLAYER] - engine->ecs.size.y[PLAYER] / 2;
    int index_last_row = index + HEIGHT_PLAYER;

    for (; index < index_last_row; index++)
    {
        drawString(engine, PLAYER, engine->buffer.sprite.player.grid[index], &map_y_index, map_x_index);
    }
}

static inline void frameDraw(Engine *engine)
{
    fwrite(engine->buffer.frame.frame, 1, SIZE_FRAME, stdout);
}

#endif