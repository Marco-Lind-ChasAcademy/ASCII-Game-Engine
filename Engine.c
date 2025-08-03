#include "Engine.h"

/* Engine engine =
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
            .y = {HEIGHT_PLAYER, HEIGHT_ENEMY},
            .y_sprite_sheet = {HEGIHT_PLAYER_SPRITE_SHEET, HEIGHT_ENEMY}
        }
    },
    .buffer =
    {
        .frame.newline = '\n'
    }
}; */

Engine *engineInit(size_t engine_size)
{
    Engine* engine = malloc(engine_size);
    char *engine_raw = (char *)engine;

    for (size_t i = 0; i < engine_size; i += 4096)
    {
        engine_raw[i] = '\0';
    }
    
    
    engine->time.frame = TIME_FRAME;


    engine->ecs.position.x[PLAYER] = WIDTH_SCREEN / 4;
    engine->ecs.position.x[ENEMY] = POSITION_X_ENEMY;
    engine->ecs.position.y[PLAYER] = HEIGHT_SCREEN / 2;
    engine->ecs.position.y[ENEMY] = POSITION_Y_ENEMY;

    engine->ecs.velocity.x[PLAYER] = VELOCITY_PLAYER_X;
    engine->ecs.velocity.y[PLAYER] = VELOCITY_PLAYER_Y;

    engine->ecs.hitbox.height[PLAYER] = HEIGHT_PLAYER;
    engine->ecs.hitbox.height[ENEMY] = HEIGHT_ENEMY;

    engine->ecs.hitbox.width[PLAYER] = WIDTH_PLAYER;
    engine->ecs.hitbox.width[ENEMY] = WIDTH_ENEMY;

    engine->ecs.size.x[PLAYER] = WIDTH_PLAYER;
    engine->ecs.size.x[ENEMY] = WIDTH_ENEMY;
    engine->ecs.size.y[PLAYER] = HEIGHT_PLAYER;
    engine->ecs.size.y[ENEMY] = HEIGHT_ENEMY;
    engine->ecs.size.y_sprite_sheet[PLAYER] = HEGIHT_PLAYER_SPRITE_SHEET;
    engine->ecs.size.y_sprite_sheet[ENEMY] = HEIGHT_ENEMY_SPRITE_SHEET;

    engine->time.since_animation_start = 0;


    engine->buffer.frame.newline = '\n';
    

    return engine;
}