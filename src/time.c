/*
** EPITECH PROJECT, 2018
** src/time
** File description:
** man man
*/

#include <stdlib.h>
#include "world.h"

void    make_time(my_game_t *game)
{
    if (sfClock_getElapsedTime(game->clock).microseconds >= game->time_fg) {
        if (game->player->accel.y != 0 || game->player->speed.y != 0 ||
game->player->accel.x != 0 || game->player->speed.x != 0 ||
game->player->accel.z != 0 || game->player->speed.z != 0) {
            printf("speed: %f, %f, %f\naccel: %f, %f, %f\n\n", game->player->speed.x, game->player->speed.y, game->player->speed.z, game->player->accel.x, game->player->accel.y, game->player->accel.z);
        }
        game->player->accel.y -= 0.05;
        game->player->speed.x += game->player->accel.x;
        game->player->speed.y += game->player->accel.y;
        game->player->speed.z += game->player->accel.z;
        movement(game, game->player->speed.x, game->player->speed.y,
game->player->speed.z);
        //game->player->x_speed = 0;
        //game->player->y_speed = 0;
        //game->player->z_speed = 0;
        /*
        game->player->accel.x = 0;
        game->player->accel.y = 0;
        game->player->accel.z = 0;
        */
        game->time_fg += 16000;
    }
}
