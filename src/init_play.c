/*
** EPITECH PROJECT, 2019
** init_play
** File description:
** initialisaion of play structure
*/

#include "my.h"

static void music_play(play_t *play)
{
    play->music = sfMusic_createFromFile(G_MUSIC);
    play->s_magic = sfSoundBuffer_createFromFile(MAGIC_S);
    play->s_hit = sfSoundBuffer_createFromFile(PUNCH_S);
    play->magic = sfSound_create();
    play->m_punch = sfSound_create();
    sfSound_setBuffer(play->magic, play->s_magic);
    sfSound_setBuffer(play->m_punch, play->s_hit);
}

static void sprite_play(play_t *play)
{
    play->s_hud = sfSprite_create();
    play->s_fist = sfSprite_create();
    play->s_magie = sfSprite_create();
    play->s_book = sfSprite_create();
    play->s_beer = sfSprite_create();
    play->s_bag = sfSprite_create();
    play->s_att_magic = sfSprite_create();
    play->s_history = sfSprite_create();
    play->s_punch = sfSprite_create();
}

static void texture_play(play_t *play)
{
    play->t_hud = sfTexture_createFromFile(HUD, NULL);
    play->t_fist = sfTexture_createFromFile(FIST , NULL);
    play->t_magie = sfTexture_createFromFile(MAGIE , NULL);
    play->t_book = sfTexture_createFromFile(BOOK , NULL);
    play->t_beer = sfTexture_createFromFile(BEER , NULL);
    play->t_bag = sfTexture_createFromFile(BAG , NULL);
    play->att_magic = sfTexture_createFromFile(ATT_MAGIC, NULL);
    play->t_history = sfTexture_createFromFile(HISTORY, NULL);
    play->t_punch = sfTexture_createFromFile(PUNCH, NULL);
}

play_t init_play(void)
{
    play_t play;

    sprite_play(&play);
    texture_play(&play);
    music_play(&play);
    play.history = false;
    play.pause = false;
    play.action = 0;
    return play;
}
