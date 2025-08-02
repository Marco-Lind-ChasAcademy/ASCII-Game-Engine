#ifndef GRAPHICS
#define GRAPHICS

#include "GameLogic.h"

int playerDrawAnimationCircling(Engine *engine, double time_between_animation_frames);

static inline void drawString(Engine *engine, int entity, char *string, int *map_y_index, int map_x_index)
{
    memcpy(&engine->buffer.frame.grid[*map_y_index][map_x_index], string, engine->ecs.size.x[entity]);
    *map_y_index += 1;
}

static inline void entityDrawFromRow(Engine *engine, int entity, int row, char *sprite_sheet)
{

    int map_x_index = engine->ecs.position.x[entity] - engine->ecs.size.x[entity] / 2;
    int map_y_index = engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2;
    int index_last_row = row + engine->ecs.size.y[entity];

    for (; row < index_last_row; row++)
    {
        drawString(engine, entity, &sprite_sheet[engine->ecs.size.x[entity] * row], &map_y_index, map_x_index);
    }

}

static inline void entityDrawAndMove(Engine *engine, int entity, int row, char *sprite_sheet)
{
    entityMovePos(engine, entity);
    entityDrawFromRow(engine, entity, row, sprite_sheet);
}

static inline void mapCopyToFrameBuffer(Engine *engine)
{
    memcpy(&engine->buffer.frame.flat, &engine->buffer.map.flat, sizeof(engine->buffer.frame.flat));
}

static inline void enemyDraw(Engine *engine)
{
    entityDrawFromRow(engine, ENEMY, 0, engine->buffer.sprite.enemy.flat);
}

static inline void playerDraw(Engine *engine)
{
    entityDrawAndMove(engine, PLAYER, 0, engine->buffer.sprite.enemy.flat);
}

static inline void playerDrawIndex(Engine *engine, int index)
{
    entityDrawAndMove(engine, PLAYER, index, engine->buffer.sprite.player.flat);
}

static inline void frameDraw(Engine *engine)
{
    fwrite(engine->buffer.frame.frame, 1, SIZE_FRAME, stdout);
}

// Returns 0 when done
static inline int entityDrawAnimation(Engine *engine, int entity, double animation_duration_in_seconds, int number_of_sprites_in_animation, char *sprite_sheet)
{
    double time_between_animation_frames;
    int case_num;

    if (animation_duration_in_seconds <= 0)
    {
        puts("animationDrawPlayerCircling(): animation_duration_in_seconds can't be 0 or negative!");
        system("pause");
        return 0;
    }

    time_between_animation_frames = animation_duration_in_seconds / number_of_sprites_in_animation;

    if (engine->time.since_animation_start < 0)
    {
        engine->time.since_animation_start = 0;
    }

    case_num = engine->time.since_animation_start / time_between_animation_frames;
    
    if (case_num >= (number_of_sprites_in_animation))
    {
        case_num = case_num % (number_of_sprites_in_animation);
    }
    
    entityDrawAndMove(engine, entity, (case_num + 1) * engine->ecs.size.y[entity], sprite_sheet);
    
    engine->time.since_animation_start += engine->time.delta;

    if (case_num == number_of_sprites_in_animation - 1)
    {
        engine->ecs.state.animation[entity] = 0;
    }
    else
    {
        engine->ecs.state.animation[entity] = 1;
    }
    

    return engine->ecs.state.animation[entity];
}

#endif