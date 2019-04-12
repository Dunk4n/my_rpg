/*
** EPITECH PROJECT, 2018
** src/moteur_3d/transform_camera
** File description:
** fireplace 4k
*/

#include <math.h>
#include "world.h"

void    transform_move_camera_enemy(my_game_t *game, room_t *room)
{
    int i = -1;
    int j;

    while (++i < room->nb_enemy) {
        if (room->enemy[i].vie < 0)
            continue;
        j = 0;
        while (j < room->enemy[i].obj->nb_point) {
            room->enemy[i].obj->point_camera[j].x = room->enemy[i].obj->
point_3d[j].x + room->enemy[i].pos.x - game->camera->move.x;
            room->enemy[i].obj->point_camera[j].y = room->enemy[i].obj->
point_3d[j].y + room->enemy[i].pos.y - game->camera->move.y;
            room->enemy[i].obj->point_camera[j].z = room->enemy[i].obj->
point_3d[j].z + room->enemy[i].pos.z - game->camera->move.z;
            j++;
        }
    }
}

void    transform_move_camera(my_game_t *game, room_t *room)
{
    int i = -1;
    int j;

    while (++i < room->nb_obj) {
        if (!room->fix_obj[i])
            continue;
        j = 0;
        while (j < room->fix_obj[i]->nb_point) {
            room->fix_obj[i]->point_camera[j].x =
room->fix_obj[i]->point_3d[j].x - game->camera->move.x;
            room->fix_obj[i]->point_camera[j].y =
room->fix_obj[i]->point_3d[j].y - game->camera->move.y;
            room->fix_obj[i]->point_camera[j].z =
room->fix_obj[i]->point_3d[j].z - game->camera->move.z;
            j++;
        }
    }
}

void    transform_rotation_camera_enemy(my_game_t *game, room_t *room)
{
    int i = -1;
    int j;

    while (++i < room->nb_enemy) {
        if (room->enemy[i].vie < 0)
            continue;
        j = 0;
        while (j < room->enemy[i].obj->nb_point) {
            room->enemy[i].obj->point_camera[j] =
put_rotate_on_point(game->camera->rot, room->enemy[i].obj->point_camera[j]);
            j++;
        }
    }
}

void    transform_rotation_camera(my_game_t *game, room_t *room)
{
    int i = -1;
    int j;

    while (++i < room->nb_obj) {
        if (!room->fix_obj[i])
            continue;
        j = 0;
        while (j < room->fix_obj[i]->nb_point) {
            room->fix_obj[i]->point_camera[j] =
put_rotate_on_point(game->camera->rot, room->fix_obj[i]->point_camera[j]);
            j++;
        }
    }
}

void    transform_camera(my_game_t *game, room_t *room)
{
    transform_move_camera(game, room);
    transform_move_camera_enemy(game, room);
    transform_rotation_camera(game, room);
    transform_rotation_camera_enemy(game, room);
    to_2d_enemy(room);
}
