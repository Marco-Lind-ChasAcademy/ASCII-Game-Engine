#ifndef ECS
#define ECS

#include "Config.h"
#include "Engine.h"

typedef enum
{
    PLAYER,
    ENEMY
} EntityID;

typedef struct
{
    float x[NUMBER_OF_ENTITIES];
    float x_next[NUMBER_OF_ENTITIES];
    float y[NUMBER_OF_ENTITIES];
    float y_next[NUMBER_OF_ENTITIES];
} PositionSystem;

typedef struct
{
    float x[NUMBER_OF_ENTITIES];
    float y[NUMBER_OF_ENTITIES];
} VelocitySystem;

typedef struct
{
    float x_min[NUMBER_OF_ENTITIES];
    float x_max[NUMBER_OF_ENTITIES];
    float y_min[NUMBER_OF_ENTITIES];
    float y_max[NUMBER_OF_ENTITIES];
} HitBoxSystem;


typedef struct
{
    int x[NUMBER_OF_ENTITIES];
    int y[NUMBER_OF_ENTITIES];
} SizeSystem;




typedef struct
{
    PositionSystem position;
    VelocitySystem velocity;
    HitBoxSystem hitbox;
    SizeSystem size;
} EntityComponentSystem;









#endif