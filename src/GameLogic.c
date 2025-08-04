#include "../include/GameLogic.h"



int entityCollidingToTheRight(Engine *engine, int entity)
{
    for (int i = 0; i < NUMBER_OF_ENTITIES; i++)
    {
        
        if (i == entity)
        {
            continue;
        }

        if
        (
            engine->ecs.position.x_next[entity] + engine->ecs.hitbox.width[entity] / 2 > engine->ecs.position.x[i] - engine->ecs.hitbox.width[i] / 2 &&
            engine->ecs.position.x[entity] - engine->ecs.hitbox.width[entity] / 2 < engine->ecs.position.x[i] + engine->ecs.hitbox.width[i] / 2 &&
            engine->ecs.position.y[entity] - engine->ecs.hitbox.height[entity] / 2 < engine->ecs.position.y[i] + engine->ecs.hitbox.height[i] / 2 &&
            engine->ecs.position.y[entity] + engine->ecs.hitbox.height[entity] / 2 > engine->ecs.position.y[i] - engine->ecs.hitbox.height[i] / 2 + 1
        )
        {
            engine->ecs.position.x[entity] = (engine->ecs.position.x[i] - engine->ecs.hitbox.width[i] / 2) - engine->ecs.hitbox.width[entity] / 2;
            return 1;
        }
        
    }

    return 0;
}

int entityCollidingToTheLeft(Engine *engine, int entity)
{
    for (int i = 0; i < NUMBER_OF_ENTITIES; i++)
    {
        
        if (i == entity)
        {
            continue;
        }

        if
        (
            engine->ecs.position.x_next[entity] - engine->ecs.hitbox.width[entity] / 2 < engine->ecs.position.x[i] + engine->ecs.hitbox.width[i] / 2 &&
            engine->ecs.position.x[entity] + engine->ecs.hitbox.width[entity] / 2 > engine->ecs.position.x[i] - engine->ecs.hitbox.width[i] / 2 + 1 &&
            engine->ecs.position.y[entity] + engine->ecs.hitbox.height[entity] / 2 > engine->ecs.position.y[i] - engine->ecs.hitbox.height[i] / 2 + 1 &&
            engine->ecs.position.y[entity] - engine->ecs.hitbox.height[entity] / 2 < engine->ecs.position.y[i] + engine->ecs.hitbox.height[i] / 2
        )
        {
            engine->ecs.position.x[entity] = (engine->ecs.position.x[i] + engine->ecs.hitbox.width[i] / 2) + engine->ecs.hitbox.width[entity] / 2;
            return 1;
        }
        
    }

    return 0;
}

int entityCollidingFromtheTop(Engine *engine, int entity)
{
    for (int i = 0; i < NUMBER_OF_ENTITIES; i++)
    {
        
        if (i == entity)
        {
            continue;
        }

        if
        (
            engine->ecs.position.y_next[entity] - engine->ecs.hitbox.height[entity] / 2 < engine->ecs.position.y[i] + engine->ecs.hitbox.height[i] / 2 &&
            engine->ecs.position.y[entity] + engine->ecs.hitbox.height[entity] / 2 > engine->ecs.position.y[i] - engine->ecs.hitbox.height[i] / 2 + 1 &&
            engine->ecs.position.x[entity] + engine->ecs.hitbox.width[entity] / 2 > engine->ecs.position.x[i] - engine->ecs.hitbox.width[i] / 2 + 1 &&
            engine->ecs.position.x[entity] - engine->ecs.hitbox.width[entity] / 2 < engine->ecs.position.x[i] + engine->ecs.hitbox.width[i] / 2
        )
        {
            engine->ecs.position.y[entity] = (engine->ecs.position.y[i] + engine->ecs.hitbox.height[i] / 2) + engine->ecs.hitbox.height[entity] / 2;
            return 1;
        }
        
    }

    return 0;
}

int entityCollidingToTheBottom(Engine *engine, int entity)
{
    for (int i = 0; i < NUMBER_OF_ENTITIES; i++)
    {
        
        if (i == entity)
        {
            continue;
        }

        if
        (
            engine->ecs.position.y_next[entity] + engine->ecs.hitbox.height[entity] / 2 > engine->ecs.position.y[i] - engine->ecs.hitbox.height[i] / 2 &&
            engine->ecs.position.y[entity] - engine->ecs.hitbox.height[entity] / 2 < engine->ecs.position.y[i] + engine->ecs.hitbox.height[i] / 2 &&
            engine->ecs.position.x[entity] - engine->ecs.hitbox.width[entity] / 2 < engine->ecs.position.x[i] + engine->ecs.hitbox.width[i] / 2 &&
            engine->ecs.position.x[entity] + engine->ecs.hitbox.width[entity] / 2 > engine->ecs.position.x[i] - engine->ecs.hitbox.width[i] / 2 + 1
        )
        {
            engine->ecs.position.y[entity] = (engine->ecs.position.y[i] - engine->ecs.hitbox.height[i] / 2) - engine->ecs.hitbox.height[entity] / 2;
            return 1;
        }
        
    }

    return 0;
}