#include "../include/Graphics.h"

// Returns 0 when done
int playerDrawAnimationCircling(Engine *engine, double animation_duration_in_seconds)
{
    return entityDrawAndMoveAnimation(engine, PLAYER, animation_duration_in_seconds, NUMBER_OF_PLAYER_CIRCLING_SPRITES, engine->buffer.sprite.player.flat);
}

// Enter orientation enum for left, center or right. Returns 1 when done
int entityDrawDialogue(Engine *engine, int entity, char *string, size_t length, double time_between_chars)
{
    int orientation = CENTER;

    if (engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2 < 0)
    {
        engine->ecs.state.printing_index[entity] = 0;
        
        return 0;
    }
    
    if (engine->ecs.position.x[entity] - length / 2 <= 3)
    {
        orientation = RIGHT;
    }
    else if (engine->ecs.position.x[entity] - length / 2 + length >= WIDTH_SCREEN + 1)
    {
        orientation = LEFT;
    }
    else
    {
    }
    
    
    
    
    
    switch (orientation)
    {
    case LEFT:
        if (stringDrawRolling(engine, &engine->time.dialogue_accumulated_time[entity], string, length, &engine->ecs.state.printing_index[entity], engine->ecs.position.x[entity] + engine->ecs.size.x[entity] / 2 - length, engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2, time_between_chars))
        {
            return 1;
        }
        
        break;
    
    case RIGHT:
        if (stringDrawRolling(engine, &engine->time.dialogue_accumulated_time[entity], string, length, &engine->ecs.state.printing_index[entity], engine->ecs.position.x[entity] - engine->ecs.size.x[entity] / 2, engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2, time_between_chars))
        {
            return 1;
        }
        
        break;
    
    default:
        if (stringDrawRolling(engine, &engine->time.dialogue_accumulated_time[entity], string, length, &engine->ecs.state.printing_index[entity], engine->ecs.position.x[entity] - length / 2, engine->ecs.position.y[entity] - engine->ecs.size.y[entity] / 2 - 2, time_between_chars))
        {
            return 1;
        }

        break;
    }

    return 0;
}