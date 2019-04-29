/*
** EPITECH PROJECT, 2019
** init_play
** File description:
** initialisaion of play structure
*/

#include "my.h"

static void sprite_play(play_t *play)
{
    play->s_hud = sfSprite_create();
    play->s_fist = sfSprite_create();
    play->s_magie = sfSprite_create();
    play->s_book = sfSprite_create();
    play->s_beer = sfSprite_create();
    play->s_bag = sfSprite_create();
}

static void texture_play(play_t *play)
{
    play->t_hud = sfTexture_createFromFile(HUD, NULL);
    play->t_fist = sfTexture_createFromFile(FIST , NULL);
    play->t_magie = sfTexture_createFromFile(MAGIE , NULL);
    play->t_book = sfTexture_createFromFile(BOOK , NULL);
    play->t_beer = sfTexture_createFromFile(BEER , NULL);
    play->t_bag = sfTexture_createFromFile(BAG , NULL);
}

play_t init_play(void)
{
    play_t play;

    sprite_play(&play);
    texture_play(&play);
    play.rect.top = 0;
    play.rect.left = 0;
    play.rect.width = 150;
    play.rect.height = 150;
    return play;
}
