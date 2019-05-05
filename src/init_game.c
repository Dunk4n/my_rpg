/*
** EPITECH PROJECT, 2018
** init_game
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"
#include "struct.h"

static  void    init_name(my_game_t *game)
{
     size_t i = 0;

     while (i < 11)
         game->name[i++] = '\0';
     game->last_input = '\0';
     game->nb_name = 0;
     game->name_text = sfText_create();
     game->name_font = sfFont_createFromFile(GOT);
     sfText_setString(game->name_text, "insert name");
     sfText_setFont(game->name_text, game->name_font);
     sfText_setPosition(game->name_text, (sfVector2f){160, 130});
     sfText_setCharacterSize(game->name_text, 20);
     sfText_setCharacterSize(game->name_text, 20);
     sfText_setColor(game->name_text, sfRed);
}

static void    init_player(my_game_t *game)
{
    game->player->vie = 50;
    game->player->mana = 50;
    game->player->stamina = 50;
    game->player->exp = 0;
    game->player->lvl = 1;
    game->player->alcool = 0;
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
    init_name(game);
    game->value_talk = 0;
    game->value_name = 0;
    game->my_turn = 1;
    game->fg_color = 0;
    return (1);
}
