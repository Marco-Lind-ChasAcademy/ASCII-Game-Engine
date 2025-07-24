#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Graphics.h"
#include <winuser.h>

inline void mapPos(EntityComponentSystem *ecs, int entity, int x, int y)
{
    ecs->position.x[entity] = x;
    ecs->position.y[entity] = y;
}

inline int keyIsPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x8000;
}

inline int keyWasPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x0001;
}

inline int topIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.y[entity] <= 0 + ecs->size.y[entity] / 2;
}

inline int bottomIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.y[entity] >= SCREEN_HEIGHT - ecs->size.y[entity] / 2 - 1;
}

inline int leftSideIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.x[entity] <= 0 + ecs->size.x[entity] / 2 + 1;
}

inline int rightSideIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.x[entity] >= SCREEN_WIDTH - ecs->size.x[entity] / 2 + 1;
}

inline void moveUp(EntityComponentSystem *ecs, int entity)
{
    ecs->position.y[entity] += 1;
}

inline void moveDown(EntityComponentSystem *ecs, int entity)
{
    ecs->position.y[entity] -= 1;
}

inline void moveLeft(EntityComponentSystem *ecs, int entity)
{
    ecs->position.x[entity] -= 1;
}

inline void moveRight(EntityComponentSystem *ecs, int entity)
{
    ecs->position.x[entity] += 1;
}

inline void movePos(EntityComponentSystem *ecs, int entity)
{
    if
    (
        keyIsPressed('W') &&
        !topIsReached(ecs, entity)
    )
    {
        moveUp(ecs, entity);
    }

    if
    (
        keyIsPressed('S') &&
        !bottomIsReached(ecs, entity)        
    )
    {
        moveDown(ecs, entity);
    }

    if
    (
        keyIsPressed('A') &&
        !leftSideIsReached(ecs, entity)
    )
    {
        moveLeft(ecs, entity);
    }

    if
    (
        keyIsPressed('D') &&
        !rightSideIsReached(ecs, entity)
    )
    {
        moveRight(ecs, entity);
    }

}



#endif