#include "Level.h"



int fileReadSprite(Engine *engine, int entity, FILE *file_pointer)
{
    for (size_t i = 0; i < engine->ecs.size.y[entity]; i++)
    {
        if (!fileRead(engine->buffer.sprite[entity].grid[i], engine->ecs.size.x[entity] + 1, file_pointer))
        {
            return 0;
        }

    }

    return 1;
}