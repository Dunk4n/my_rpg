/*
** EPITECH PROJECT, 2018
** src/moteur_3d/rotation_camera
** File description:
** hello world?
*/

#include <math.h>
#include "world.h"

void    rotate_camera(my_game_t *game, float roll, float yaw, float pitch)
{
    int i = -1;
    float sr = sin(roll * M_PI / 180);
    float cr = cos(roll * M_PI / 180);
    float sy = sin(yaw * M_PI / 180);
    float cy = cos(yaw * M_PI / 180);
    float sp = sin(pitch * M_PI / 180);
    float cp = cos(pitch * M_PI / 180);
    double tmp;

    game->camera->roll += roll;
    if (game->camera->roll >= 360 || game->camera->roll < 0)
        game->camera->roll += (game->camera->roll < 0) ? 360 : -360;
    game->camera->yaw += yaw;
    if (game->camera->yaw >= 360 || game->camera->yaw < 0)
        game->camera->yaw += (game->camera->yaw < 0) ? 360 : -360;
    game->camera->pitch += pitch;
    if (game->camera->pitch >= 360 || game->camera->pitch < 0)
        game->camera->pitch += (game->camera->pitch < 0) ? 360 : -360;
    while (++i < 3) {
        tmp = game->camera->point[i].z;
        game->camera->point[i].z = (sr * game->camera->point[i].y) + (cr * tmp);
        game->camera->point[i].y = (cr * game->camera->point[i].y) - (sr * tmp);
        tmp = game->camera->point[i].x;
        game->camera->point[i].x = (cy * tmp) + (sy * game->camera->point[i].z);
        game->camera->point[i].z =
-(sy * tmp) + (cy * game->camera->point[i].z);
        tmp = game->camera->point[i].x;
        game->camera->point[i].x = (cp * tmp) - (sp * game->camera->point[i].y);
        game->camera->point[i].y = (sp * tmp) + (cp * game->camera->point[i].y);
    }
}

/*void    rotate_camera_roll(my_game_t *game, float a, float b)
{
    double tmp;

    tmp = game->camera->point[0].z;
    game->camera->point[0].z = (a * game->camera->point[0].y) + (b * tmp);
    game->camera->point[0].y = (b * game->camera->point[0].y) + (a * tmp);
    tmp = game->camera->point[1].z;
    game->camera->point[1].z = (a * game->camera->point[1].y) + (b * tmp);
    game->camera->point[1].y = (b * game->camera->point[1].y) + (a * tmp);
    tmp = game->camera->point[2].z;
    game->camera->point[2].z = (a * game->camera->point[2].y) + (b * tmp);
    game->camera->point[2].y = (b * game->camera->point[2].y) + (a * tmp);
}

void    rotation_roll(my_game_t *game, float coef)
{
    int tab[2] = {0};
    float ang[2];
    double tmp;

    if (coef == 0)
        return ;
    ang[0] = sin(-coef * M_PI / 180);
    ang[1] = cos(-coef * M_PI / 180);
    rotate_camera_roll(game, -ang[0], -ang[1]);
    while (tab[0] < game->obj) {
        tab[1] = 0;
        while (tab[1] < game->map->obj[tab[0]]->nb_point) {
            tmp = game->map->obj[tab[0]]->point_3d[tab[1]].z;
            game->map->obj[tab[0]]->point_3d[tab[1]].z =
(ang[0] * game->map->obj[tab[0]]->point_3d[tab[1]].y) + (ang[1] * tmp);
            game->map->obj[tab[0]]->point_3d[tab[1]].y =
(ang[1] * game->map->obj[tab[0]]->point_3d[tab[1]].y) - (ang[0] * tmp);
            tab[1]++;
        }
        tab[0]++;
    }
}

void    rotate_camera_yaw(my_game_t *game, float a, float b)
{
    double tmp;

    tmp = game->camera->point[0].x;
    game->camera->point[0].x = (a * tmp) + (b * game->camera->point[0].z);
    game->camera->point[0].z = -(b * tmp) + (a * game->camera->point[0].z);
    tmp = game->camera->point[1].x;
    game->camera->point[1].x = (a * tmp) + (b * game->camera->point[0].z);
    game->camera->point[1].z = -(b * tmp) + (a * game->camera->point[0].z);
    tmp = game->camera->point[2].x;
    game->camera->point[2].x = (a * tmp) + (b * game->camera->point[0].z);
    game->camera->point[2].z = -(b * tmp) + (a * game->camera->point[0].z);
}

void    rotation_yaw(my_game_t *game, float coef)
{
    int tab[2] = {0};
    float ang[2];
    double tmp;

    if (coef == 0)
        return ;
    ang[0] = sin(-coef * M_PI / 180);
    ang[1] = cos(-coef * M_PI / 180);
    rotate_camera_yaw(game, -ang[0], -ang[1]);
    while (tab[0] < game->obj) {
        tab[1] = 0;
        while (tab[1] < game->map->obj[tab[0]]->nb_point) {
            tmp = game->map->obj[tab[0]]->point_3d[tab[1]].x;
            game->map->obj[tab[0]]->point_3d[tab[1]].x =
(ang[0] * tmp) + (ang[0] * game->map->obj[tab[0]]->point_3d[tab[1]].z);
            game->map->obj[tab[0]]->point_3d[tab[1]].z =
-(ang[0] * tmp) + (ang[0] * game->map->obj[tab[0]]->point_3d[tab[1]].z);
            tab[1]++;
        }
        tab[0]++;
    }
}

void    rotate_camera_pitch(my_game_t *game, float a, float b)
{
    double tmp;

    tmp = game->camera->point[0].x;
    game->camera->point[0].x = (a * tmp) - (b * game->camera->point[0].y);
    game->camera->point[0].y = (b * tmp) + (a * game->camera->point[0].y);
    tmp = game->camera->point[1].x;
    game->camera->point[1].x = (a * tmp) - (b * game->camera->point[1].y);
    game->camera->point[1].y = (b * tmp) + (a * game->camera->point[1].y);
    tmp = game->camera->point[2].x;
    game->camera->point[2].x = (a * tmp) - (b * game->camera->point[2].y);
    game->camera->point[2].y = (b * tmp) + (a * game->camera->point[2].y);
}

void    rotation_pitch(my_game_t *game, float coef)
{
    int tab[2] = {0};
    float ang[2];
    double tmp;

    if (coef == 0)
        return ;
    ang[0] = sin(-coef * M_PI / 180);
    ang[1] = cos(-coef * M_PI / 180);
    rotate_camera_pitch(game, -ang[1], -ang[0]);
    while (tab[0] < game->obj) {
        tab[1] = 0;
        while (tab[1] < game->map->obj[tab[0]]->nb_point) {
            tmp = game->map->obj[tab[0]]->point_3d[tab[1]].x;
            game->map->obj[tab[0]]->point_3d[tab[1]].x =
(ang[1] * tmp) - (ang[0] * game->map->obj[tab[0]]->point_3d[tab[1]].y);
            game->map->obj[tab[0]]->point_3d[tab[1]].y =
(ang[0] * tmp) + (ang[1] * game->map->obj[tab[0]]->point_3d[tab[1]].y);
            tab[1]++;
        }
        tab[0]++;
    }
}*/
