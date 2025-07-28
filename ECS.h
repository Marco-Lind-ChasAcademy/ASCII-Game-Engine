#ifndef ECS
#define ECS

#include "Config.h"

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
    float width[NUMBER_OF_ENTITIES];
    float height[NUMBER_OF_ENTITIES];
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




typedef struct
{
    LARGE_INTEGER current, last, frequency;
    double delta, frame;
} TimeSystem;

typedef union
{
    char frame[SIZE_FRAME];
    struct
    {
        char newline;
        union
        {
            char flat[(WIDTH_SCREEN + 1) * HEIGHT_SCREEN];
            char grid[HEIGHT_SCREEN][WIDTH_SCREEN + 1];
        };
    };
    
} FrameBuffer;

typedef union
{
    char flat[(WIDTH_SCREEN + 1) * HEIGHT_SCREEN];
    char grid[HEIGHT_SCREEN][WIDTH_SCREEN + 1];
} MapBuffer;

typedef union
{
    char flat[SIZE_SPRITE];
    char grid[HEIGHT_SPRITE][WIDTH_SPRITE];
} Sprite;

typedef struct
{
    MapBuffer map;
    FrameBuffer frame;
    Sprite sprite[NUMBER_OF_ENTITIES];

} BufferSystem;

typedef struct
{
    TimeSystem time;
    EntityComponentSystem ecs;
    BufferSystem buffer;
} Engine;




#endif