/*
** EPITECH PROJECT, 2018
** src/condition
** File description:
** fireplace 4k
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"

size_t  nb_monster_in_room(room_t *room)
{
    size_t  nb = 0;
    size_t  i = 0;
    size_t  j;
    size_t  k;

    while (i < (size_t)room->y_max) {
        j = 0;
        while (j < (size_t)room->z_max) {
            k = 0;
            while (k < (size_t)room->x_max) {
                (room->room[i][j][k] >= 'a' && room->room[i][j][k] - 'a' <
my_strlen(type_enemy) && pnj[room->room[i][j][k] - 'a' + 1] == 0) ? nb++ : 0;
                k++;
            }
            j++;
        }
        i++;
    }
    return (nb);
}

int     kill_all_monster(my_game_t *game, int nb_room, int nb)
{
    (void)game;
    (void)nb;
    if (nb_room < 0 || nb_room >= game->nb_room)
        return (1);
    if (!nb_monster_in_room(game->room[nb_room]))
        return (1);
    return (0);
}

int     vie_superior_of(my_game_t *game, int nb_room, int nb)
{
    (void)nb_room;
    if (game->player->vie >= nb)
        return (1);
    return (0);
}
