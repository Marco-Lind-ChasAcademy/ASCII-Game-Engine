#include "Level.h"



int fileReadSpritePlayer(Engine *engine, FILE *file_pointer)
{
    for (size_t i = 0; i < engine->ecs.size.y_sprite_sheet[PLAYER]; i++)
    {
        if (!fileRead(engine->buffer.sprite.player.grid[i], engine->ecs.size.x[PLAYER], file_pointer))
        {
            return 0;
        }
        
        getc(file_pointer);

    }

    return 1;
}

int fileReadSpriteEnemy(Engine *engine, FILE *file_pointer)
{
    for (size_t i = 0; i < engine->ecs.size.y_sprite_sheet[ENEMY]; i++)
    {
        if (!fileRead(engine->buffer.sprite.enemy.grid[i], engine->ecs.size.x[ENEMY], file_pointer))
        {
            return 0;
        }
        
        getc(file_pointer);

    }

    return 1;
}