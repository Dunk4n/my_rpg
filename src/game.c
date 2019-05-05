/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** after menu the game
*/

#include "my.h"

static void start_game(my_game_t *game)
{
    game->camera->move.x = 5.5;
    game->camera->move.y = 1.8;
    game->camera->move.z = 5.5;
    game->clock = sfClock_create();
    game->time_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->time_enemy_fg = sfClock_getElapsedTime(game->clock).microseconds;
    game->room[1]->enemy[2].dialog = 5;
}

static void history(play_t *play, my_game_t *game)
{
    if (play->history != true) {
        sfSprite_setPosition(play->s_history, (sfVector2f){0, 0});
        sfSprite_setTexture(play->s_history, play->t_history, sfTrue);
        sfRenderWindow_drawSprite(game->win->window, play->s_history, NULL);
    }
}

void    ft_game(my_game_t *game, opt_t *opt)
{
    play_t play = init_play();
    png_t *png = init_png();

    if (!(game = set_game()))
        return;
    start_game(game);
    sfMusic_play(play.music);
    sfMusic_setLoop(play.music, sfTrue);
    sfMusic_setVolume(play.music, opt->vol_ac);
    while (sfRenderWindow_isOpen(game->win->window)) {
        if (play.pause == false) {
            display_room(game);
            update(game, &play, png);
            history(&play, game);
            check(game, opt, &play);
            if (!game->my_turn)
                enemy_turn(game);
            sfRenderWindow_display(game->win->window);
        }
        (play.pause == true) ? pause_game(&play, game) : 0;
    }
}
