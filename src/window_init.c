/*
** EPITECH PROJECT, 2019
** init_window
** File description:
** initilasation of struct window
*/

#include "my.h"
#include "struct.h"

void init_w(win_t *win)
{
    sfVideoMode video = {1080, 1920, 60};
    char const *name = "my_RPG";

    win->window = sfRenderWindow_create(video, name, sfDefaultStyle/*sfFullscreen*/, NULL);
}
