/*
** EPITECH PROJECT, 2018
** src/moteur_3d/rotation_camera_process
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    rotate_up(my_game_t *game, float weight)
{
    float pitch;
    float yaw = game->camera->yaw;
    float roll;

    if (game->camera->roll_cam + weight > 70 &&
game->camera->roll_cam + weight < 300)
        return;
    game->camera->roll_cam += weight;
    if (game->camera->roll_cam < 0)
        game->camera->roll_cam += 360;
    if (game->camera->roll_cam >= 360)
        game->camera->roll_cam -= 360;
    roll = ((yaw >= 0 && yaw < 180) ? yaw / -90.0 + 1 : (yaw - 180) / 90 - 1);
    yaw = (yaw + 90 >= 360) ? yaw - 270 : yaw + 90;
    pitch = ((yaw >= 0 && yaw < 180) ? yaw / -90.0 + 1 : (yaw - 180) / 90 - 1);
    rotate_camera(game, roll * weight, 0, pitch * weight);
}

void    rotate_right(my_game_t *game, float weight)
{
    rotate_camera(game, 0, weight, 0);
}
