#include "../include/Graphics.h"

// Returns 0 when done
int playerDrawAnimationCircling(Engine *engine, double animation_duration_in_seconds)
{
    return entityDrawAndMoveAnimation(engine, PLAYER, animation_duration_in_seconds, NUMBER_OF_PLAYER_CIRCLING_SPRITES, engine->buffer.sprite.player.flat);
}