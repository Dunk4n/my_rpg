/*
** EPITECH PROJECT, 2018
** movement_camera
** File description:
** don't forget to free at the end
*/

#include "world.h"

float   round_angle(float angle)
{
    if (angle < 0)
        angle += 360;
    if (angle >= 360)
        angle -= 360;
    return (angle);
}

int     move_to_slab(my_game_t *game, char ***room, int z, int x)
{
    if ((int)game->camera->move.y + 1 < game->room[game->actual_room]->y_max &&
room[(int)game->camera->move.y][z][x] == 'V' && room[(int)game->camera->move.y +
1][z][x] == '.') {
        game->camera->move.y += 0.5;
        return (1);
    }
    if ((int)game->camera->move.y - 2 >= 0 && room[(int)game->camera->move.y][z]
[x] == '.' && room[(int)game->camera->move.y - 1][z][x] == '.' &&
room[(int)game->camera->move.y - 2][z][x] == 'O') {
        game->camera->move.y -= 0.5;
        return (1);
    }
    return (0);
}

int     move_to(my_game_t *game, int z, int x)
{
    char ***room = game->room[game->actual_room]->room;

    if (z < 0 || z >= game->room[game->actual_room]->z_max ||
x < 0 || x >= game->room[game->actual_room]->x_max || (int)game->camera->move.y
>= game->room[game->actual_room]->y_max)
        return (0);
    if ((int)game->camera->move.y - 1 >= 0 && room[(int)game->camera->move.y][z]
[x] == '.') {
        if (room[(int)game->camera->move.y - 1][z][x] == 'O') {
            (room[(int)game->camera->move.y - 1][(int)game->camera->move.z]
[(int)game->camera->move.x] == 'V') ? game->camera->move.y += 0.5 : 0;
            return (1);
        }
        if (room[(int)game->camera->move.y - 1][z][x] == 'V') {
            game->camera->move.y -= 0.5;
            return (1);
        }
    }
    if (move_to_slab(game, room, z, x))
        return (1);
    return (0);
}

int     move_forward(my_game_t *game, int dir)
{
    int cord[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int dir_z = cord[(int)(round_angle(game->camera->yaw + 45) / 90)][0] * dir;
    int dir_x = cord[(int)(round_angle(game->camera->yaw + 45) / 90)][1] * dir;

    if (move_to(game, (int)game->camera->move.z + dir_z,
(int)game->camera->move.x + dir_x)) {
        game->camera->move.z += dir_z;
        game->camera->move.x += dir_x;
        return (1);
    }
    return (0);
}

int     move_right(my_game_t *game, int dir)
{
    int cord[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int dir_z = cord[(int)(round_angle(game->camera->yaw + 45) / 90)][0] * dir;
    int dir_x = cord[(int)(round_angle(game->camera->yaw + 45) / 90)][1] * dir;

    if (move_to(game, (int)game->camera->move.z + dir_z,
(int)game->camera->move.x + dir_x)) {
        game->camera->move.z += dir_z;
        game->camera->move.x += dir_x;
        return (1);
    }
    return (0);
}
