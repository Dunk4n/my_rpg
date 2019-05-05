/*
** EPITECH PROJECT, 2019
** menu_ft
** File description:
** function for init and use menu
*/

#include "my.h"

static void init_menu_hard(menu_t *menu)
{
    menu->t_menu = sfTexture_createFromFile(MENU, NULL);
    menu->s_menu = sfSprite_create();
    menu->t_select = sfTexture_createFromFile(SELECT, NULL);
    menu->s_sel = sfSprite_create();
    menu->t_anim = sfTexture_createFromFile(ANIM, NULL);
    menu->s_anim = sfSprite_create();
    menu->t_particle = sfTexture_create(1920, 1080);
    menu->s_particle = sfSprite_create();
    sfSprite_setTexture(menu->s_particle, menu->t_particle, sfTrue);
    menu->p_select.x = 680;
    menu->p_select.y = 420;
    menu->opt = 1;
    menu->event.mouseButton.x = 0;
    menu->event.mouseButton.y = 0;
}

void init_menu(menu_t *menu, opt_t *opt)
{
    sfVideoMode video = {1920, 1080, 32};
    char const *n = "Dwarf game";

    init_menu_hard(menu);
    menu->p_anim.x = 570;
    menu->p_anim.y = 470;
    menu->r_anim.top = 0;
    menu->r_anim.left = 0;
    menu->r_anim.width = 110;
    menu->r_anim.height = 110;
    menu->clock = sfClock_create();
    menu->time = sfClock_getElapsedTime(menu->clock);
    menu->seconds = menu->time.microseconds / 10000.0;
    sfMusic_play(opt->music);
    sfMusic_setLoop(opt->music, sfTrue);
    menu->window = sfRenderWindow_create(video, n, sfFullscreen, NULL);
    sfSprite_setPosition(menu->s_sel, menu->p_select);
    sfSprite_setPosition(menu->s_anim, menu->p_anim);
}

void display_menu(menu_t *menu)
{
    make_particle(menu->buff, menu);
    sfTexture_updateFromPixels(menu->t_particle, menu->buff->pixels, 1920, 1080,
0, 0);
    sfSprite_setTexture(menu->s_menu, menu->t_menu, sfTrue);
    sfSprite_setTexture(menu->s_sel, menu->t_select, sfTrue);
    sfSprite_setTexture(menu->s_anim, menu->t_anim, sfTrue);
    sfRenderWindow_drawSprite(menu->window, menu->s_menu, NULL);
    sfRenderWindow_drawSprite(menu->window, menu->s_sel, NULL);
    menu->time = sfClock_getElapsedTime(menu->clock);
    menu->seconds = menu->time.microseconds / 1000000.0;
    if (menu->seconds > 0.15) {
        while (menu->seconds >= 0.15) {
            move_rect(&(menu->r_anim), 110, 880);
            menu->seconds -= 0.15;
        }
        sfClock_restart(menu->clock);
    }
    sfSprite_setTextureRect(menu->s_anim, menu->r_anim);
    sfRenderWindow_drawSprite(menu->window, menu->s_anim, NULL);
}
