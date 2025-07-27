#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Timers.h"

static inline void posSet(EntityComponentSystem *ecs, int entity, int x, int y)
{
    ecs->position.x[entity] = x;
    ecs->position.y[entity] = y;
}

static inline int keyIsPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x8000;
}

static inline int keyWasPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x0001;
}

static inline int topIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.y[entity] <= 0 + ecs->size.y[entity] / 2;
}

static inline int bottomIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.y[entity] >= HEIGHT_SCREEN - ecs->size.y[entity] / 2 - 1;
}

static inline int leftSideIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.x[entity] <= 0 + ecs->size.x[entity] / 2 + 1;
}

static inline int rightSideIsReached(EntityComponentSystem *ecs, int entity)
{
    return ecs->position.x[entity] >= WIDTH_SCREEN - ecs->size.x[entity] / 2 + 1;
}

static inline void moveUp(EntityComponentSystem *ecs, TimeSystem *time, int entity)
{
    ecs->position.y_next[entity] = ecs->position.y[entity] - time->delta * ecs->velocity.y[entity];

    if (ecs->position.y_next[entity] < ecs->size.y[entity] / 2)
    {
        ecs->position.y[entity] = ecs->size.y[entity] / 2;
        return;
    }

    ecs->position.y[entity] = ecs->position.y_next[entity];
}

static inline void moveDown(EntityComponentSystem *ecs, TimeSystem *time, int entity)
{
    ecs->position.y_next[entity] = ecs->position.y[entity] + time->delta * ecs->velocity.y[entity];

    if (ecs->position.y_next[entity] > HEIGHT_SCREEN - ecs->size.y[entity] / 2)
    {
        ecs->position.y[entity] = HEIGHT_SCREEN - ecs->size.y[entity] / 2 - 1;
        return;
    }

    ecs->position.y[entity] = ecs->position.y_next[entity];
}

static inline void moveLeft(EntityComponentSystem *ecs, TimeSystem *time, int entity)
{
    ecs->position.x_next[entity] = ecs->position.x[entity] - time->delta * ecs->velocity.x[entity];

    if (ecs->position.x_next[entity] < ecs->size.x[entity] / 2)
    {
        ecs->position.x[entity] = ecs->size.x[entity] / 2;
        return;
    }

    ecs->position.x[entity] = ecs->position.x_next[entity];
}

static inline void moveRight(EntityComponentSystem *ecs, TimeSystem *time, int entity)
{
    ecs->position.x_next[entity] = ecs->position.x[entity] + time->delta * ecs->velocity.x[entity];

    if (ecs->position.x_next[entity] > WIDTH_SCREEN - ecs->size.x[entity] / 2)
    {
        ecs->position.x[entity] = WIDTH_SCREEN - ecs->size.x[entity] / 2;
        return;
    }

    ecs->position.x[entity] = ecs->position.x_next[entity];
}

static inline void movePos(EntityComponentSystem *ecs, TimeSystem *time, int entity)
{
    if
    (
        keyIsPressed('W')
    )
    {
        moveUp(ecs, time, entity);
    }

    if
    (
        keyIsPressed('S')
    )
    {
        moveDown(ecs, time, entity);
    }

    if
    (
        keyIsPressed('A')
    )
    {
        moveLeft(ecs, time, entity);
    }

    if
    (
        keyIsPressed('D')
    )
    {
        moveRight(ecs, time, entity);
    }

}



#endif