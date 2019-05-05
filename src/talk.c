/*
** EPITECH PROJECT, 2018
** src/talk
** File description:
** M-x doctor
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"

const char      *dialog[6] = {"Bonjour.", "Tu doit tuer les chauve-souri de \
cette sale.", "Bien vous avez termine, vous pouvez partir.", "Aurevoir.",
"Door", "You go to room ONE!!!!"};

const int       d_cond_room[6] = {-1, 0, -1, -1, -1, -1};
const int       d_indice_ft[] = {0, 0, 0, 0, 0, 0};
const int       d_indice_ftr[] = {0, 0, 0, 2, 1, 2};
const int       d_cond_arg[] = {0, 0, 0, 0, 0, 0};
const int       d_rwd_arg[] = {-1, -1, -1, 1, -1, 0};
const sfVector3f    d_rwd_arg2[] = {(sfVector3f){0, 0, 0},
(sfVector3f){0, 0, 0}, (sfVector3f){0, 0, 0}, (sfVector3f){8.5, 3.8, 1.5},
(sfVector3f){0, 0, 0}, (sfVector3f){1.5, 3.8, 8.5}};
const int       to_dialog[] = {1, 2, 3, 3, 4, 5};

int     (*const ft_cond[])(my_game_t *game, int nb_room, int nb) =
{
kill_all_monster, vie_superior_of
};

void    (*const ft_reward[])(my_game_t *game, enemy_t *cible, int value,
sfVector3f new_pos) =
{
NULL, small_door, big_door
};

//printf("%s: %s\n\n", name[cible->name], dialog[cible->dialog]);
int     talk_pnj(my_game_t *game, enemy_t *cible)
{
    if (cible->dialog < 0)
        return (1);
    if (cible->nb_dialog > 0 && ft_cond[d_indice_ft[cible->dialog]](game,
d_cond_room[cible->dialog], d_cond_arg[cible->dialog]))
        cible->dialog = to_dialog[cible->dialog];
    game->value_talk = cible->dialog;
    if (ft_reward[d_indice_ftr[cible->dialog]])
        ft_reward[d_indice_ftr[cible->dialog]](game, cible,
d_rwd_arg[cible->dialog], d_rwd_arg2[cible->dialog]);
    game->value_name = cible->name;
    cible->nb_dialog++;
    return (1);
}
