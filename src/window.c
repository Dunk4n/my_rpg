/*
** EPITECH PROJECT, 2018
** window
** File description:
** well, real programmers use ed
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

void    ft_game(my_game_t *game)
{
    if (!(game = set_game()))
        return /*(84)*/;
    game->camera->move.x = 5.5;
    game->camera->move.y = 1.8;
    game->camera->move.z = 5.5;
    game->clock = sfClock_create();
    game->time_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->time_enemy_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->room[1]->enemy[2].dialog = 5;
    while (sfRenderWindow_isOpen(game->win->window)) {
        display_room(game);
        update(game);
        check(game);
        if (!game->my_turn)
            enemy_turn(game);
    }
}

int     window(void)
{
    my_game_t    *game = NULL;
    win_t win;

//    ft_game(game);
//    init_w(&win);
    menu_window(game);
    return (0);
}
