/*
** EPITECH PROJECT, 2018
** display_room
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include "world.h"

void    display_room(my_game_t *game)
{
    int i = 0;

    clear_z_buff(game->win->z_buff);
    clear_t_buff(game->win->t_buff);
    clear_buff(game->win->framebuff);
    to_2d(game, game->room[game->actual_room]);
    while (i < game->room[game->actual_room]->nb_obj) {
        display(game, game->room[game->actual_room]->fix_obj[i]);
        i++;
    }
}
