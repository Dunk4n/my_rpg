/*
** EPITECH PROJECT, 2018
** src/moteur_3d/transform_camera
** File description:
** fireplace 4k
*/

#include <math.h>
#include "world.h"

void    transform_move_camera(my_game_t *game)
{
    int i = 0;
    int j;

    while (i < game->obj) {
        j = 0;
        while (j < game->map->obj[i]->nb_point) {
            game->map->obj[i]->point_camera[j].x =
game->map->obj[i]->point_3d[j].x - game->camera->move.x;
            game->map->obj[i]->point_camera[j].y =
game->map->obj[i]->point_3d[j].y - game->camera->move.y;
            game->map->obj[i]->point_camera[j].z =
game->map->obj[i]->point_3d[j].z - game->camera->move.z;
            j++;
        }
        i++;
    }
}

void    transform_rotation_camera(my_game_t *game)
{
    int i = 0;
    int j = 0;
    float sr = sin(-game->camera->roll * M_PI / 180);
    float cr = cos(-game->camera->roll * M_PI / 180);
    float sy = sin(-game->camera->yaw * M_PI / 180);
    float cy = cos(-game->camera->yaw * M_PI / 180);
    float sp = sin(-game->camera->pitch * M_PI / 180);
    float cp = cos(-game->camera->pitch * M_PI / 180);
    double tmp;

    while (i < game->obj) {
        j = 0;
        while (j < game->map->obj[i]->nb_point) {
            tmp = game->map->obj[i]->point_camera[j].z;
            game->map->obj[i]->point_camera[j].z =
(sr * game->map->obj[i]->point_camera[j].y) + (cr * tmp);
            game->map->obj[i]->point_camera[j].y =
(cr * game->map->obj[i]->point_camera[j].y) - (sr * tmp);
            tmp = game->map->obj[i]->point_camera[j].x;
            game->map->obj[i]->point_camera[j].x =
(cy * tmp) + (sy * game->map->obj[i]->point_camera[j].z);
            game->map->obj[i]->point_camera[j].z =
-(sy * tmp) + (cy * game->map->obj[i]->point_camera[j].z);
            tmp = game->map->obj[i]->point_camera[j].x;
            game->map->obj[i]->point_camera[j].x =
(cp * tmp) - (sp * game->map->obj[i]->point_camera[j].y);
            game->map->obj[i]->point_camera[j].y =
(sp * tmp) + (cp * game->map->obj[i]->point_camera[j].y);
            j++;
        }
        i++;
    }
}

void    transform_camera(my_game_t *game)
{
    transform_move_camera(game);
    transform_rotation_camera(game);
}
