#ifndef LEVEL_H
#define LEVEL_H

#include "Graphics.h"



int fileReadSprite(Engine *engine, int entity, FILE *file_pointer);



static inline int fileOpen(FILE **file_pointer, char *file_name, char *mode)
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

static inline int fileRead(void *__restrict__ destination_buffer, size_t size, FILE *file_pointer)
{
    if (!fread(destination_buffer, 1, size, file_pointer))
    {
        perror("fileRead() failed");
        system("pause");
        return 0;
    }

    return 1;
}

#endif