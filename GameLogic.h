#ifndef GAMELOGIC_H
#define GAMELOGIC_H



#include "Timers.h"



int collidingToTheRight(Engine *engine, int entity);
int collidingToTheLeft(Engine *engine, int entity);
int collidingFromtheTop(Engine *engine, int entity);
int collidingToTheBottom(Engine *engine, int entity);



static inline void posSet(Engine *engine, int entity, int x, int y)
{
    engine->ecs.position.x[entity] = x;
    engine->ecs.position.y[entity] = y;
}

static inline int keyIsPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x8000;
}

static inline int keyWasPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x0001;
}

static inline int topIsReached(Engine *engine, int entity)
{
    return engine->ecs.position.y[entity] <= 0 + engine->ecs.size.y[entity] / 2;
}

static inline int bottomIsReached(Engine *engine, int entity)
{
    return engine->ecs.position.y[entity] >= HEIGHT_SCREEN - engine->ecs.size.y[entity] / 2 - 1;
}

static inline int leftSideIsReached(Engine *engine, int entity)
{
    return engine->ecs.position.x[entity] <= 0 + engine->ecs.size.x[entity] / 2 + 1;
}

static inline int rightSideIsReached(Engine *engine, int entity)
{
    return engine->ecs.position.x[entity] >= WIDTH_SCREEN - engine->ecs.size.x[entity] / 2 + 1;
}

static int isEven(int number)
{
    return !(number % 2);
}

static inline void moveUp(Engine *engine, int entity)
{
    engine->ecs.position.y_next[entity] = engine->ecs.position.y[entity] - engine->time.delta * engine->ecs.velocity.y[entity];

    if (engine->ecs.position.y_next[entity] < engine->ecs.size.y[entity] / 2)
    {
        engine->ecs.position.y[entity] = engine->ecs.size.y[entity] / 2;
        return;
    }

    if (collidingFromtheTop(engine, entity))
    {
        return;
    }
    

    engine->ecs.position.y[entity] = engine->ecs.position.y_next[entity];
}

static inline void moveDown(Engine *engine, int entity)
{
    engine->ecs.position.y_next[entity] = engine->ecs.position.y[entity] + engine->time.delta * engine->ecs.velocity.y[entity];

    if (engine->ecs.position.y_next[entity] > HEIGHT_SCREEN - engine->ecs.size.y[entity] / 2)
    {
        engine->ecs.position.y[entity] = HEIGHT_SCREEN - engine->ecs.size.y[entity] / 2 - 1;
        return;
    }

    if (collidingToTheBottom(engine, entity))
    {
        return;
    }

    engine->ecs.position.y[entity] = engine->ecs.position.y_next[entity];
}

static inline void moveLeft(Engine *engine, int entity)
{
    engine->ecs.position.x_next[entity] = engine->ecs.position.x[entity] - engine->time.delta * engine->ecs.velocity.x[entity];

    if (engine->ecs.position.x_next[entity] < engine->ecs.size.x[entity] / 2)
    {
        engine->ecs.position.x[entity] = engine->ecs.size.x[entity] / 2;
        return;
    }

    if (collidingToTheLeft(engine, entity))
    {
        return;
    }
    

    engine->ecs.position.x[entity] = engine->ecs.position.x_next[entity];
}

static inline void moveRight(Engine *engine, int entity)
{
    engine->ecs.position.x_next[entity] = engine->ecs.position.x[entity] + engine->time.delta * engine->ecs.velocity.x[entity];

    if (engine->ecs.position.x_next[entity] > WIDTH_SCREEN - engine->ecs.size.x[entity] / 2)
    {
        engine->ecs.position.x[entity] = WIDTH_SCREEN - engine->ecs.size.x[entity] / 2;
        return;
    }

    if (collidingToTheRight(engine, entity))
    {
        return;
    }
    
    
    engine->ecs.position.x[entity] = engine->ecs.position.x_next[entity];
}

static inline void movePos(Engine *engine, int entity)
{
    if
    (
        keyIsPressed('W')
    )
    {
        moveUp(engine, entity);
    }

    if
    (
        keyIsPressed('S')
    )
    {
        moveDown(engine, entity);
    }

    if
    (
        keyIsPressed('A')
    )
    {
        moveLeft(engine, entity);
    }

    if
    (
        keyIsPressed('D')
    )
    {
        moveRight(engine, entity);
    }

}



#endif