/*
** EPITECH PROJECT, 2019
** action game
** File description:
** touch and interaction for gameplay
*/

#include "my.h"
#include "world.h"

static void drink(play_t *play, my_game_t *game)
{
    sfSound_play(play->brup);
    game->player->alcool += 10;
    if (game->player->alcool == 100) {
        sfMusic_destroy(play->music);
        sfMusic_play(play->tekno);
        game->fg_color = 1;
    }
    if (game->player->alcool > 100)
        game->player->alcool = 100;
}

void action_game(play_t *play, my_game_t *game)
{
    (sfKeyboard_isKeyPressed(sfKeyNum2)) ? play->action = (size_t)2 : 0;
    (sfKeyboard_isKeyPressed(sfKeyNum1)) ? play->action = (size_t)1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyNum5)) ? play->history = true : 0;
    (sfKeyboard_isKeyPressed(sfKeyNum4)) ? drink(play, game): 0;
}
