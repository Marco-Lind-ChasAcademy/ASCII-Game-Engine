#include "Engine.h"



int main()
{
    FILE *map_file = NULL;
    FILE *sprite_player_file = NULL;
    FILE *sprite_enemy_file = NULL;

    if (!fileOpen(&map_file, "map.bin", "r"))
    {
        return 1;
    }
    
    if (!fileOpen(&sprite_player_file, "sprite_player.bin", "r"))
    {
        fclose(map_file);
        return 1;
    }
    
    if (!fileOpen(&sprite_enemy_file, "sprite_enemy.bin", "r"))
    {
        fclose(map_file);
        fclose(sprite_player_file);
        return 1;
    }

    if
    (
        !fileRead(engine.buffer.map.flat, SIZE_FRAME - 1, map_file) ||
        !fileReadSprite(&engine, PLAYER, sprite_player_file) ||
        !fileReadSprite(&engine, ENEMY, sprite_enemy_file)
    )
    {
        fclose(map_file);
        fclose(sprite_player_file);
        fclose(sprite_enemy_file);
        return 1;
    }
    
    fclose(map_file);
    fclose(sprite_player_file);
    fclose(sprite_enemy_file);

    timeSystemInit(&engine);


    // Game loop
    while (!keyWasPressed(VK_ESCAPE))
    {
        timeDeltaCalculate(&engine);

        if (engine.time.delta < engine.time.frame)
        {
            continue;
        }

        engine.time.last = engine.time.current;
        
        mapToFrameBufferCopy(&engine);

        entityDraw(&engine, ENEMY);
        playerDraw(&engine, PLAYER);
        
        frameDraw(&engine);
    }
    

    return 0;
}