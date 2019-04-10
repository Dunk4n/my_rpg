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
    sfTexture *t_menu;
    sfMusic *music;
}menu_t;
