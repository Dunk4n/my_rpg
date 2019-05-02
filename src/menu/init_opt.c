/*
** EPITECH PROJECT, 2019
** init_opt
** File description:
** init_option
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "world.h"

void    init_particle(menu_t *menu, sfVector2i pos)
{
    size_t  i = 0;
    float   angl;
    float   speed;

    while (i < NB_PARTICLE) {
        angl = rand() % 360;
        speed = (10.0 + (float)(rand() % 30)) / 10.0;
        menu->particle[i].life = 25 + rand() % 50;
        menu->particle[i].size = 10 + rand() % 20;
        menu->particle[i].pos.x = pos.x;
        menu->particle[i].pos.y = pos.y;
        menu->particle[i].speed.x = speed * cos(angl * M_PI / 180.0);
        menu->particle[i].speed.y = -speed * sin(angl * M_PI / 180.0);
        menu->particle[i].color = (sfColor){150 + 100 *
menu->particle[i].life / 75, 20, 20, 255};
        i++;
    }
}

int     init_default_option(opt_t *opt, menu_t *menu)
{
    if (!(menu->buff = my_framebuff_create(1920, 1080)))
        return (0);
    init_particle(menu, (sfVector2i){960, 540});
    opt->vol_ac = 100;
    opt->ctrl[0] = 0;
    opt->ctrl[1] = 0;
    opt->music = sfMusic_createFromFile(MENU_MUSIC);
    opt->s_button = sfSoundBuffer_createFromFile(BUTTON);
    opt->button = sfSound_create();
    sfSound_setBuffer(opt->button, opt->s_button);
    sfMusic_setVolume(opt->music, opt->vol_ac);
    return (1);
}
