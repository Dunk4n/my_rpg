/*
** EPITECH PROJECT, 2018
** display_room
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include "world.h"

//int global = 0;

    //sfInt64 time;

    //time = sfClock_getElapsedTime(game->clock).microseconds;
    /*if (global < 400)
        printf("%d\n",
(int)(1000 / ((double)(sfClock_getElapsedTime(game->clock).microseconds - time)
/ 1000) + 0.5));
    global++;
    */
void    display_room(my_game_t *game)
{
    int i = 0;
    clear_buff(game->win->framebuff, game->win->z_buff);
    to_2d(game, game->room[game->actual_room]);
    while (i < game->room[game->actual_room]->nb_obj) {
        if (game->room[game->actual_room]->fix_obj[i]) {
            display(game, game->room[game->actual_room]->fix_obj[i]);
        }
        i++;
    }
    i = 0;
    while (i < game->room[game->actual_room]->nb_enemy) {
        if (game->room[game->actual_room]->enemy[i].obj &&
game->room[game->actual_room]->enemy[i].vie > 0)
            display(game, game->room[game->actual_room]->enemy[i].obj);
        i++;
    }
}
