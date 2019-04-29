/*
** EPITECH PROJECT, 2019
** init_opt
** File description:
** init_option
*/

#include "my.h"

void init_default_option(opt_t *opt)
{
    opt->vol_ac = 100;
    opt->ctrl[0] = 0;
    opt->ctrl[1] = 0;
    opt->music = sfMusic_createFromFile(MENU_MUSIC);
    opt->s_button = sfSoundBuffer_createFromFile(BUTTON);
    opt->button = sfSound_create();
    sfSound_setBuffer(opt->button, opt->s_button);
    sfMusic_setVolume(opt->music, opt->vol_ac);
}
