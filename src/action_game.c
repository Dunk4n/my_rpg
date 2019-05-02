/*
** EPITECH PROJECT, 2019
** action game
** File description:
** touch and interaction for gameplay
*/

#include "my.h"
#include "world.h"

void action_game(play_t *play, my_game_t *game)
{
    static size_t press = 0;

    (sfKeyboard_isKeyPressed(sfKeyNum2)) ? play->action = (size_t)2 : 0;
    (sfKeyboard_isKeyPressed(sfKeyNum1)) ? play->action = (size_t)1 : 0;
    (sfKeyboard_isKeyPressed(sfKeyNum5)) ? play->history = true : 0;

}
