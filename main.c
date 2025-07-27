/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define SCREEN_WIDTH 98
#define SCREEN_HEIGHT 22
#define SPRITE_PLAYER_WIDTH 6
#define SPRITE_PLAYER_HEIGHT 3
#define SCREEN_BUFFER_SIZE (SCREEN_WIDTH + 1) * SCREEN_HEIGHT + 1
#define SPRITE_PLAYER_BUFFER_SIZE (SPRITE_PLAYER_WIDTH + 1) * SPRITE_PLAYER_HEIGHT
#define NUMBER_OF_ENTITIES 2

typedef enum
{
    PLAYER,
    ENEMY
} Entity;

typedef struct
{
    int abs[NUMBER_OF_ENTITIES];
    int x[NUMBER_OF_ENTITIES];
    int y[NUMBER_OF_ENTITIES];
} PositionSystem;

typedef struct
{
    int height[NUMBER_OF_ENTITIES];
    int width[NUMBER_OF_ENTITIES];
} SizeSystem;



FILE *map_file = NULL;
FILE *sprite_player_file = NULL;
//Entity entity;
PositionSystem pos;
SizeSystem size = {.height = {SPRITE_PLAYER_HEIGHT}, .width = {SPRITE_PLAYER_WIDTH}};
char map_buffer[SCREEN_BUFFER_SIZE];
char screen_buffer[SCREEN_BUFFER_SIZE];
char sprite_player_buffer[SPRITE_PLAYER_BUFFER_SIZE];


static inline void mapPos(PositionSystem *pos_sys, int entity, int x, int y)
{
    pos_sys->abs[entity] = (SCREEN_WIDTH + 1) * y + x;
    pos_sys->x[entity] = x;
    pos_sys->y[entity] = y;
}

static inline int keyIsPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x8000;
}

static inline int keyWasPressed(char key_uppercase)
{
    return GetAsyncKeyState(key_uppercase) & 0x0001;
}

static inline int topIsReached(PositionSystem *pos, SizeSystem *size, int entity)
{
    return pos->y[entity] <= 0 + size->height[entity] / 2;
}

static inline int bottomIsReached(PositionSystem *pos, SizeSystem *size, int entity)
{
    return pos->y[entity] >= SCREEN_HEIGHT - size->height[entity] / 2 - 1;
}

static inline int leftSideIsReached(PositionSystem *pos, SizeSystem *size, int entity)
{
    return pos->x[entity] <= 0 + size->width[entity] / 2 + 1;
}

static inline int rightSideIsReached(PositionSystem *pos, SizeSystem *size, int entity)
{
    return pos->x[entity] >= SCREEN_WIDTH - size->width[entity] / 2 + 1;
}

static inline void moveUp(PositionSystem *pos_sys, int entity)
{
    mapPos(pos_sys, entity, pos_sys->x[entity], pos_sys->y[entity] - 1);
}

static inline void moveDown(PositionSystem *pos_sys, int entity)
{
    mapPos(pos_sys, entity, pos_sys->x[entity], pos_sys->y[entity] + 1);
}

static inline void moveLeft(PositionSystem *pos_sys, int entity)
{
    mapPos(pos_sys, entity, pos_sys->x[entity] - 1, pos_sys->y[entity]);
}

static inline void moveRight(PositionSystem *pos_sys, int entity)
{
    mapPos(pos_sys, entity, pos_sys->x[entity] + 1, pos_sys->y[entity]);
}

static inline void movePos(PositionSystem *pos_sys, SizeSystem *size, int entity)
{
    if
    (
        keyIsPressed('W') &&
        !topIsReached(pos_sys, size, entity)
    )
    {
        moveUp(pos_sys, entity);
    }

    if
    (
        keyIsPressed('S') &&
        !bottomIsReached(pos_sys, size, entity)        
    )
    {
        moveDown(pos_sys, entity);
    }

    if
    (
        keyIsPressed('A') &&
        !leftSideIsReached(pos_sys, size, entity)
    )
    {
        moveLeft(pos_sys, entity);
    }

    if
    (
        keyIsPressed('D') &&
        !rightSideIsReached(pos_sys, size, entity)
    )
    {
        moveRight(pos_sys, entity);
    }

}

void drawPlayer();
int openFile(FILE **file_pointer, char *file_name, char *mode);
int readFile(void *__restrict__ destination_buffer, size_t element_size, int count, FILE *file_pointer);
void drawEntity(PositionSystem *pos_sys, SizeSystem *size_sys, int entity);


int main()
{
    if (!openFile(&map_file, "map.bin", "r"))
    {
        return 1;
    }
    
    if (!openFile(&sprite_player_file, "sprite_player.bin", "r"))
    {
        fclose(map_file);
        return 1;
    }

    if
    (
        !readFile(&map_buffer[1], 1, SCREEN_BUFFER_SIZE, map_file) ||
        !readFile(sprite_player_buffer, 1, SPRITE_PLAYER_BUFFER_SIZE, sprite_player_file)
    )
    {
        fclose(map_file);
        fclose(sprite_player_file);
    }

    map_buffer[0] = '\n';
    //map_buffer[SCREEN_BUFFER_SIZE - 1] = '\0';
    //sprite_player_buffer[SPRITE_PLAYER_BUFFER_SIZE - 1] = '\0';
    
    memcpy(screen_buffer, map_buffer, SCREEN_BUFFER_SIZE);

    mapPos(&pos, PLAYER, 24, 11);

    LARGE_INTEGER current_time, last_time, freq;
    double delta_time;
    double frame_time = 1.0 / 60.0;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&last_time);


    // Game loop
    while (!keyWasPressed(VK_ESCAPE))
    {
        QueryPerformanceCounter(&current_time);
        delta_time = (double)(current_time.QuadPart - last_time.QuadPart) / freq.QuadPart;

        if (delta_time < frame_time)
        {
            continue;
        }
        
        memcpy(screen_buffer, map_buffer, SCREEN_BUFFER_SIZE);

        // Move above the timer later. Also add velocity
        drawEntity(&pos, &size, PLAYER);
        
        fwrite(screen_buffer, 1, SCREEN_BUFFER_SIZE, stdout);

        QueryPerformanceCounter(&last_time);
    }

    fclose(map_file);
    fclose(sprite_player_file);
    

    return 0;
}

void drawPlayer()
{
    movePos(&pos, &size, PLAYER);
    // Top left corner
    int screen_buffer_index = (pos.abs[PLAYER] - SPRITE_PLAYER_WIDTH / 2) - (SCREEN_WIDTH + 1) * (SPRITE_PLAYER_HEIGHT / 2);
    int sprite_player_buffer_index = 0;

    for (; sprite_player_buffer_index < SPRITE_PLAYER_BUFFER_SIZE; screen_buffer_index += SCREEN_WIDTH + 1)
    {
        memcpy(&screen_buffer[screen_buffer_index], &sprite_player_buffer[sprite_player_buffer_index], SPRITE_PLAYER_WIDTH);
        sprite_player_buffer_index += SPRITE_PLAYER_WIDTH + 1;
    }
}

int openFile(FILE **file_pointer, char *file_name, char *mode)
{
    if ((*file_pointer = fopen(file_name, mode)) == NULL)
    {
        char error_message[64];
        sprintf(error_message, "Couldn't open %s", file_name);
        perror(error_message);
        system("pause");
        return 0;
    }

    return 1;
}

int readFile(void *__restrict__ destination_buffer, size_t element_size, int count, FILE *file_pointer)
{
    if (!fread(destination_buffer, element_size, count, file_pointer))
    {
        perror("readFile() failed");
        system("pause");
        return 0;
    }

    return 1;
}

void drawEntity(PositionSystem *pos_sys, SizeSystem *size_sys, int entity)
{
    movePos(pos_sys, size_sys, entity);
    // Top left corner
    int screen_buffer_index = (pos.abs[entity] - *size_sys->width / 2) - (SCREEN_WIDTH + 1) * (*size_sys->height / 2);
    int sprite_player_buffer_index = 0;

    for (; sprite_player_buffer_index < ((*size_sys->width + 1) * *size_sys->height); screen_buffer_index += SCREEN_WIDTH + 1)
    {
        memcpy(&screen_buffer[screen_buffer_index], &sprite_player_buffer[sprite_player_buffer_index], *size_sys->width);
        sprite_player_buffer_index += *size_sys->width + 1;
    }
} */