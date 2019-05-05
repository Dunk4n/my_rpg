/*
** EPITECH PROJECT, 2018
** src/get_name
** File description:
** xkcd.com/378
*/

#include <SFML/Graphics.h>
#include "struct.h"

const   int letter[40] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF,
sfKeyG, sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO, sfKeyP,
sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ,
sfKeySlash, sfKeyPeriod, sfKeyNum0, sfKeyNum1, sfKeyNum2,
sfKeyNum3, sfKeyNum4, sfKeyNum5, sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9};

const char *list_letters = "abcdefghijklmnopqrstuvwxyz/.0123456789";

void    write_on_txt(play_t *play)
{
    int i = 0;

    while (list_letters[i]) {
        if (sfKeyboard_isKeyPressed(letter[i]) &&
(play->last_input != list_letters[i])) {
            play->name[play->nb_name] = list_letters[i];
            play->nb_name++;
            play->name[play->nb_name] = '\0';
        }
        if (sfKeyboard_isKeyPressed(letter[i]))
            play->last_input =
(play->last_input != list_letters[i]) ? list_letters[i] : '\0';
        i++;
    }
}

int     get_name(play_t *play)
{
    if (play->nb_name > 9 || (sfKeyboard_isKeyPressed(sfKeyReturn) &&
play->nb_name)) {
        text_nb = 0;
        return (1);
    }
    if (play->nb_name > 0 && sfKeyboard_isKeyPressed(sfKeyBack)) {
        play->nb_name--;
        play->name[play->nb_name] = '\0';
        return (0);
    }
    write_on_text(play);
    sfText_setString(play->name_text, play->name);
    return (0);
}
