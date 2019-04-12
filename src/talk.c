/*
** EPITECH PROJECT, 2018
** src/talk
** File description:
** M-x doctor
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"

const char      *dialog[] = {"Hello.", "To complete your training you must kill\
 all shadow on the lower floor.", "Well you finish your task.\nYou are now a\
 true warrior and you can leave the fortress.", "Goodbye."};
const int       d_cond_room[] = {-1, 0, -1, -1};
const int       d_indice_ft[] = {0, 0, 0, 0};
const int       d_cond_arg[] = {0, 0, 0, 0};
const int       to_dialog[] = {1, 2, 3, 3};

//=======================================================
int       (*ft_cond[])(my_game_t *game, int nb_room, int nb) =
{kill_all_monster, vie_superior_of};
//=======================================================

int     talk_pnj(my_game_t *game, enemy_t *cible)
{
    if (cible->nb_dialog > 0 && ft_cond[d_indice_ft[cible->dialog]](game,
d_cond_room[cible->dialog], d_cond_arg[cible->dialog]))
        cible->dialog = to_dialog[cible->dialog];
    printf("%s: %s\n\n", name[cible->name], dialog[cible->dialog]);
    cible->nb_dialog++;
    return (1);
}
