#ifndef LEVEL_H
#define LEVEL_H

#include "Graphics.h"

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

static inline int fileReadSprite(char destination_buffer[][16], size_t x_length, size_t y_length, FILE *file_pointer)
{
    for (size_t i = 0; i < y_length; i++)
    {
        if (!fileRead(destination_buffer[i], x_length, file_pointer))
        {
            return 0;
        }

    }

    return 1;
}

#endif