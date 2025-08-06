#include "../include/Engine.h"



int main()
{
    Engine *engine = engineInit(sizeof(Engine));

    FILE *map_file = NULL;
    FILE *sprite_player_file = NULL;
    FILE *sprite_enemy_file = NULL;

    if (!fileOpen(&map_file, "assets/map.bin", "r"))
    {
        free(engine);
        return 1;
    }
    
    if (!fileOpen(&sprite_player_file, "assets/sprite_player.bin", "r"))
    {
        free(engine);
        fclose(map_file);
        return 1;
    }
    
    if (!fileOpen(&sprite_enemy_file, "assets/sprite_enemy.bin", "r"))
    {
        free(engine);
        fclose(map_file);
        fclose(sprite_player_file);
        return 1;
    }

    if
    (
        !fileRead(engine->buffer.map.flat, SIZE_FRAME - 1, map_file) ||
        !fileReadSpritePlayer(engine, sprite_player_file) ||
        !fileReadSpriteEnemy(engine, sprite_enemy_file)
    )
    {
        free(engine);
        fclose(map_file);
        fclose(sprite_player_file);
        fclose(sprite_enemy_file);
        return 1;
    }
    
    fclose(map_file);
    fclose(sprite_player_file);
    fclose(sprite_enemy_file);

    timeSystemInit(engine);


    // Game loop
    while (!keyWasPressed(VK_ESCAPE))
    {
        timeDeltaCalculate(engine);

        if (engine->time.delta < engine->time.frame)
        {
            continue;
        }

        engine->time.last = engine->time.current;
        
        mapCopyToFrameBuffer(engine);

        entityDrawAnimation(engine, ENEMY, 8, NUMBER_OF_ENEMY_BLINKING_SPRITES, engine->buffer.sprite.enemy.flat);

        //enemyDraw(engine);

        playerDrawAnimationCircling(engine, 0.5);

        entityDrawDialogue(engine, PLAYER, "Hi, I'm Bob!", 12, 0.05, LEFT);

        stringDrawCentered(engine, "Marco's locker:", 16, 2);
        
        frameDraw(engine);
    }

    free(engine);
    

    return 0;
}