#ifndef ECS
#define ECS

#define NUMBER_OF_ENTITIES 2
#define SPRITE_PLAYER_WIDTH 6
#define SPRITE_PLAYER_HEIGHT 3

typedef enum
{
    PLAYER,
    ENEMY
} EntityID;

typedef struct
{
    float x[NUMBER_OF_ENTITIES];
    float y[NUMBER_OF_ENTITIES];
} PositionSystem;

typedef struct
{
    float x[NUMBER_OF_ENTITIES];
    float y[NUMBER_OF_ENTITIES];
} VelocitySystem;

typedef struct
{
    int x[NUMBER_OF_ENTITIES];
    int y[NUMBER_OF_ENTITIES];
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




EntityComponentSystem ecs = {.size.x = {SPRITE_PLAYER_WIDTH}, {SPRITE_PLAYER_HEIGHT}};




#endif