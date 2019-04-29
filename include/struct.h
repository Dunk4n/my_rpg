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
    sfSound *button;
    sfSoundBuffer *s_button;
    sfEvent event;
    sfSprite *s_vol;
    sfSprite *s_opt;
    sfSprite *s_touch_two;
    sfSprite *s_touch_one;
    sfSprite *sf_clavier;
    sfSprite *ss_clavier;
    sfTexture *t_opt;
    sfTexture *t_vol;
    sfTexture *tf_clavier;
    sfTexture *ts_clavier;
    sfTexture *t_touch_two;
    sfTexture *t_touch_one;
    int vol_ac;
    int ctrl[1];
}opt_t;

typedef struct gameplay_s {
    sfSprite *s_hud;
    sfSprite *s_fist;
    sfSprite *s_magie;
    sfSprite *s_book;
    sfSprite *s_beer;
    sfSprite *s_bag;
    sfTexture *t_hud;
    sfTexture *t_fist;
    sfTexture *t_magie;
    sfTexture *t_book;
    sfTexture *t_beer;
    sfTexture *t_bag;
    sfIntRect rect;
    sfEvent event;
}play_t;
