/*
** EPITECH PROJECT, 2018
** src/get_name
** File description:
** xkcd.com/378
*/

#include <SFML/Graphics.h>
#include "struct.h"
#include "world.h"

const   int letter[40] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF,
sfKeyG, sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO, sfKeyP,
sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ,
sfKeySlash, sfKeyPeriod, sfKeyNum0, sfKeyNum1, sfKeyNum2,
sfKeyNum3, sfKeyNum4, sfKeyNum5, sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9};

const char *list_letters = "abcdefghijklmnopqrstuvwxyz/.0123456789";

static void    write_on_txt(my_game_t *game)
{
    int i = 0;

    while (list_letters[i]) {
        if (sfKeyboard_isKeyPressed(letter[i]) &&
(game->last_input != list_letters[i])) {
            game->name[game->nb_name] = list_letters[i];
            game->nb_name++;
            game->name[game->nb_name] = '\0';
        }
        if (sfKeyboard_isKeyPressed(letter[i]))
            game->last_input =
(game->last_input != list_letters[i]) ? list_letters[i] : '\0';
        i++;
    }
}

int     get_name(my_game_t *game)
{
    if (game->nb_name > 9 || (sfKeyboard_isKeyPressed(sfKeyReturn) &&
game->nb_name)) {
        game->nb_name = 0;
        return (1);
    }
    if (game->nb_name > 0 && sfKeyboard_isKeyPressed(sfKeyBack)) {
        game->nb_name--;
        game->name[game->nb_name] = '\0';
        return (0);
    }
    write_on_txt(game);
    sfText_setFont(game->name_text, game->name_font);
    sfText_setPosition(game->name_text, (sfVector2f){160, 130});
    sfText_setCharacterSize(game->name_text, 20);
    sfText_setCharacterSize(game->name_text, 20);
    sfText_setColor(game->name_text, sfRed);
    sfText_setString(game->name_text, game->name);
    return (0);
}
