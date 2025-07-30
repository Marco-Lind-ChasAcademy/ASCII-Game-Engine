#include "Graphics.h"

// Returns 0 when done
int animationDrawPlayerCircling(Engine *engine, double animation_duration_in_seconds)
{
    if (animation_duration_in_seconds <= 0)
    {
        puts("animationDrawPlayerCircling(): animation_duration_in_seconds can't be 0 or negative!");
        system("pause");
        return 0;
    }

    double time_between_animation_frames = animation_duration_in_seconds / (NUMBER_OF_PLAYER_CIRCLING_SPRITES);

    if (engine->time.since_animation_start < 0)
    {
        engine->time.since_animation_start = 0;
    }

    int case_num = engine->time.since_animation_start / time_between_animation_frames;
    
    if (case_num >= (NUMBER_OF_PLAYER_CIRCLING_SPRITES))
    {
        case_num = case_num % (NUMBER_OF_PLAYER_CIRCLING_SPRITES);
    }
    
    switch(case_num)
    {
        case 0:
            playerDrawIndex(engine, 1 * HEIGHT_PLAYER);

            engine->ecs.state.animation[PLAYER] = 1;

            break;
        case 1:
            playerDrawIndex(engine, 2 * HEIGHT_PLAYER);

            break;
        case 2:
            playerDrawIndex(engine, 3 * HEIGHT_PLAYER);

            break;
        case 3:
            playerDrawIndex(engine, 4 * HEIGHT_PLAYER);

            break;
        case 4:
            playerDrawIndex(engine, 5 * HEIGHT_PLAYER);

            break;
        case 5:
            playerDrawIndex(engine, 6 * HEIGHT_PLAYER);

            break;
        case 6:
            playerDrawIndex(engine, 7 * HEIGHT_PLAYER);

            break;
        case 7:
            playerDrawIndex(engine, 8 * HEIGHT_PLAYER);
            
            engine->ecs.state.animation[PLAYER] = 0;

            break;
    }
    
    engine->time.since_animation_start += engine->time.delta;

    return engine->ecs.state.animation[PLAYER];
}