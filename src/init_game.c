/*
** EPITECH PROJECT, 2018
** init_game
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <stdlib.h>
#include "world.h"

void    init_player(my_game_t *game)
{
    game->player->vie = 100;
    game->player->value_hit = 25;
}

int     init_game(my_game_t *game)
{
    if (!(game->room = charge_room(game)))
        return (0);
    if (!(init_enemy(game)))
        return (0);
    if (!(game->player = malloc(sizeof(player_t))))
        return (0);
    init_player(game);
    game->value_talk = 0;
    game->my_turn = 1;
    game->fg_color = 0;
    return (1);
}
