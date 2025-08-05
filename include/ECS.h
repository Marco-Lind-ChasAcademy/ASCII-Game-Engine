#ifndef ECS
#define ECS

#include "Config.h"

typedef enum
{
    NO_ENTITY,
    PLAYER,
    ENEMY
} EntityID;
typedef enum
{
    NO_ACTION,
    CIRCLING
} ActionID;

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
    int y_sprite_sheet[NUMBER_OF_ENTITIES];
} SizeSystem;

typedef struct
{
    int action[NUMBER_OF_ENTITIES];
    int animation[NUMBER_OF_ENTITIES];
} StateSystem;





typedef struct
{
    PositionSystem position;
    VelocitySystem velocity;
    HitBoxSystem hitbox;
    SizeSystem size;
    StateSystem state;
} EntityComponentSystem;




typedef struct
{
    LARGE_INTEGER current, last, frequency;
    double delta, frame, since_animation_start;
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
    char flat[SIZE_PLAYER_SPRITE_SHEET];
    char grid[HEGIHT_PLAYER_SPRITE_SHEET][WIDTH_PLAYER];
} SpritePlayer;

typedef union
{
    char flat[SIZE_ENEMY];
    char grid[HEIGHT_ENEMY_SPRITE_SHEET][WIDTH_ENEMY];
} SpriteEnemy;

typedef struct
{
    SpritePlayer player;
    SpriteEnemy enemy;
} SpriteSystem;


typedef struct
{
    MapBuffer map;
    FrameBuffer frame;
    SpriteSystem sprite;

} BufferSystem;

typedef struct
{
    TimeSystem time;
    EntityComponentSystem ecs;
    BufferSystem buffer;
} Engine;




#endif