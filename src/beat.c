/*
** EPITECH PROJECT, 2018
** src/beat
** File description:
** man man
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"

int     if_hit_posible(my_game_t *game, int z, int x)
{
    if (z < 0 || z >= game->room[game->actual_room]->z_max || x < 0 ||
x >= game->room[game->actual_room]->x_max)
        return (0);
    if (game->room[game->actual_room]->room[(int)game->camera->move.y][z][x] <
'a')
        return (0);
    return (1);
}

enemy_t *get_cible(my_game_t *game, int z, int x)
{
    int i = 0;

    while (i < game->room[game->actual_room]->nb_enemy) {
        if ((int)game->room[game->actual_room]->enemy[i].pos.x == x &&
(int)game->room[game->actual_room]->enemy[i].pos.z == z &&
(int)game->room[game->actual_room]->enemy[i].pos.y == (int)game->camera->move.y)
            return (&(game->room[game->actual_room]->enemy[i]));
        i++;
    }
    return (NULL);
}

int     beat_monster(my_game_t *game, enemy_t *cible)
{
    cible->vie -= game->player->value_hit;
    if (cible->vie <= 0) {
        game->player->exp += 55;
        cible->vie = 0;
        game->room[game->actual_room]->room[(int)cible->pos.y]
[(int)cible->pos.z][(int)cible->pos.x] = '.';
    }
    return (1);
}

int     beat(my_game_t *game)
{
    enemy_t     *cible;
    int cord[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dir_z = cord[(int)(round_angle(game->camera->yaw + 45) / 90)][0];
    int dir_x = cord[(int)(round_angle(game->camera->yaw + 45) / 90)][1];

    if (!if_hit_posible(game, (int)game->camera->move.z + dir_z,
(int)game->camera->move.x + dir_x))
        return 0;
    if (!(cible = get_cible(game, (int)game->camera->move.z + dir_z,
(int)game->camera->move.x + dir_x)))
        return 0;
    if (cible->pnj == 0)
        return (beat_monster(game, cible));
    if (cible->pnj == 1)
        return (talk_pnj(game, cible));
    return (0);
}
