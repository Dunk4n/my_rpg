/*
** EPITECH PROJECT, 2019
** menu.h
** File description:
** menu.h
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define NB_PARTICLE 500

typedef struct  particle_s
{
    int         life;
    int         size;
    sfVector2f  speed;
    sfVector2f  pos;
    sfColor     color;
}               particle_t;

typedef struct window_t {
    sfRenderWindow *window;
    sfEvent event;
}win_t;

typedef struct  my_framebuff_s  my_framebuff_t;

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
    sfSprite *s_particle;
    sfTexture *t_particle;
    my_framebuff_t      *buff;
    particle_t  particle[NB_PARTICLE];
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

typedef struct png_s {
    sfTexture *t_png;
    sfSprite *s_png;
}png_t;

typedef struct gameplay_s {
    sfMusic *music;
    sfSound *magic;
    sfSound *m_punch;
    sfSoundBuffer *s_magic;
    sfSoundBuffer *s_hit;
    size_t   action;
    sfSprite *s_hud;
    sfSprite *s_fist;
    sfSprite *s_magie;
    sfSprite *s_book;
    sfSprite *s_beer;
    sfSprite *s_bag;
    sfSprite *s_att_magic;
    sfSprite *s_history;
    sfSprite *s_punch;
    sfTexture *t_hud;
    sfTexture *t_fist;
    sfTexture *t_magie;
    sfTexture *t_book;
    sfTexture *t_beer;
    sfTexture *t_bag;
    sfTexture *att_magic;
    sfTexture *t_history;
    sfTexture *t_punch;
    sfIntRect anim_rect;
    sfIntRect item_rect;
    sfEvent event;
    bool history;
}play_t;
