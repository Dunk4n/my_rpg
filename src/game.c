/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** after menu the game
*/

#include "my.h"

void    ft_game(my_game_t *game, opt_t *opt)
{
    play_t play = init_play();

    if (!(game = set_game()))
        return;
    game->camera->move.x = 5.5;
    game->camera->move.y = 1.8;
    game->camera->move.z = 5.5;
    game->clock = sfClock_create();
    game->time_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->time_enemy_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->room[1]->enemy[2].dialog = 5;
    while (sfRenderWindow_isOpen(game->win->window)) {
        display_room(game);
        update(game, &play);
        check(game, opt);
        if (!game->my_turn)
            enemy_turn(game);
    }
}
