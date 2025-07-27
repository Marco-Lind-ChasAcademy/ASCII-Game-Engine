#include "Engine.h"



int main()
{
    FILE *map_file = NULL;
    FILE *sprite_player_file = NULL;

    if (!fileOpen(&map_file, "map.bin", "r"))
    {
        return 1;
    }
    
    if (!fileOpen(&sprite_player_file, "sprite_player.bin", "r"))
    {
        fclose(map_file);
        return 1;
    }

    if
    (
        !fileRead(engine.buffer.map.flat, SIZE_FRAME - 1, map_file) ||
        !fileReadSprite(engine.buffer.sprite[PLAYER].grid, WIDTH_PLAYER + 1, HEIGHT_PLAYER, sprite_player_file)
    )
    {
        fclose(map_file);
        fclose(sprite_player_file);
        return 1;
    }
    
    fclose(map_file);
    fclose(sprite_player_file);

    timeSystemInit(&engine.time);


    // Game loop
    while (!keyWasPressed(VK_ESCAPE))
    {
        timeDeltaCalculate(&engine.time);

        if (engine.time.delta < engine.time.frame)
        {
            continue;
        }

        engine.time.last = engine.time.current;
        
        mapToFrameBufferCopy(&engine.buffer);

        // Move above the timer later. Also add velocity
        entityDraw(&engine.ecs, &engine.buffer, &engine.time, PLAYER);
        
        frameDraw(&engine.buffer);
    }

    fclose(map_file);
    fclose(sprite_player_file);
    

    return 0;
}