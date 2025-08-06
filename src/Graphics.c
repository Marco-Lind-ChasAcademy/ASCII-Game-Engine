#include "../include/Graphics.h"

// Returns 0 when done
int playerDrawAnimationCircling(Engine *engine, double animation_duration_in_seconds)
{
    return entityDrawAndMoveAnimation(engine, PLAYER, animation_duration_in_seconds, NUMBER_OF_PLAYER_CIRCLING_SPRITES, engine->buffer.sprite.player.flat);
}

// Enter orientation enum for left, center or right. Returns 1 when done
int entityDrawDialogue(Engine *engine, int entity, char *string, size_t length, double time_between_chars, int orientation)
{
    if (engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2 < 0)
    {
        return 0;
    }
    

    switch (orientation)
    {
    case LEFT:
        if (length >= (engine->ecs.position.x[entity] + engine->ecs.size.x[entity] / 2) - 3)
        {
            length = (engine->ecs.position.x[entity] + engine->ecs.size.x[entity] / 2) - 3;
        }

        if (stringDrawRolling(engine, &engine->time.dialogue_accumulated_time[entity], string, length, &engine->ecs.state.printing_index[entity], engine->ecs.position.x[entity] + engine->ecs.size.x[entity] / 2 - length, engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2, time_between_chars))
        {
            return 1;
        }
        
        break;
    
    case RIGHT:
        if (length >= WIDTH_SCREEN - (engine->ecs.position.x[entity] - engine->ecs.size.x[entity] / 2))
        {
            length = WIDTH_SCREEN - (engine->ecs.position.x[entity] - engine->ecs.size.x[entity] / 2) - 1;
        }
        
        if (stringDrawRolling(engine, &engine->time.dialogue_accumulated_time[entity], string, length, &engine->ecs.state.printing_index[entity], engine->ecs.position.x[entity] - engine->ecs.size.x[entity] / 2, engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2, time_between_chars))
        {
            return 1;
        }
        
        break;
    
    default:
        puts("entityDrawDialogue(): Invalid orientation");
        return 0;

        break;
    }
}