/*
** EPITECH PROJECT, 2018
** init_game
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <stdlib.h>
#include "world.h"

void    set_player(my_game_t *game)
{
    game->player->vie = 100;
    game->player->speed.x = 0;
    game->player->speed.y = 0;
    game->player->speed.z = 0;
    game->player->accel.x = 0;
    game->player->accel.y = 0;
    game->player->accel.z = 0;
}

int     init_game(my_game_t *game)
{
    if (!(game->room = charge_room(game)))
        return (0);
    if (!(game->player = malloc(sizeof(player_t))))
        return (0);
    set_player(game);
    return (1);
}
