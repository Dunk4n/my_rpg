/*
** EPITECH PROJECT, 2018
** src/reward
** File description:
** programmers start to count from 0
*/

#include <stdlib.h>
#include "world.h"

void    small_door(my_game_t *game, enemy_t *cible, int value,
sfVector3f new_pos)
{
    (void)value;
    (void)new_pos;
    if (game->room[game->actual_room]->room
[(int)game->camera->move.y][(int)(cible->pos.z - ((int)game->camera->move.z -
(int)cible->pos.z))][(int)(cible->pos.x - ((int)game->camera->move.x -
(int)cible->pos.x))] == '.') {
        game->camera->move.z = cible->pos.z -
((int)game->camera->move.z - (int)cible->pos.z);
        game->camera->move.x = cible->pos.x -
((int)game->camera->move.x - (int)cible->pos.x);
    }
}

void    big_door(my_game_t *game, enemy_t *cible, int value, sfVector3f new_pos)
{
    (void)cible;
    if (game->actual_room != value)
        game->actual_room = value;
    game->camera->move.x = new_pos.x;
    game->camera->move.y = new_pos.y;
    game->camera->move.z = new_pos.z;
}
