/*
** EPITECH PROJECT, 2019
** menu.h
** File description:
** menu.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct window_t {
    sfRenderWindow *window;
    sfEvent event;
}win_t;

typedef struct menu_interface_s {
    sfRenderWindow *window;
    sfSprite *s_menu;
    sfSprite *s_sel;
    sfSprite *s_anim;
    sfTexture *t_select;
    sfTexture *t_menu;
    sfTexture *t_anim;
    sfIntRect r_anim;
    sfVector2f p_select;
    sfVector2f p_anim;
    sfEvent event;
    size_t opt;
}menu_t;

typedef struct credit_s {
    sfEvent event;
    sfSprite *s_credit;
    sfTexture *t_credit;
}credit_t;

typedef struct option_s {
    sfMusic *music;
}opt_t;
