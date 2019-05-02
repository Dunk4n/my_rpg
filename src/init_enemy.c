/*
** EPITECH PROJECT, 2018
** init_enemy
** File description:
** programmers start to count from 0
*/

#include <stdlib.h>
#include "world.h"

const char      type_enemy[4] = "abcd";
const int       pnj[5] = {0, 0, 0, 1, 1};
const int       enemy_vie[] = {50, 50, 100, 100, 100};
const int       enemy_deg[] = {25, 25, 50, 100, 0};
const int       to_copy[] = {2, 2, 3, 4, 5};
const int       start_dialog[] = {-1, -1, -1, 0, 4};
const char      *name[21] = {"Balin", "Bifur", "Bofur", "Borin", "Dori",
"Dwalin", "Dain", "Farin", "Floi", "Frar", "Gloin", "Gror", "Kili", "Ibum",
"Mim", "Nain", "Nori", "Oin", "Telchar", "Thrain", "Thror"};


int     get_nb_enemy(room_t *room)
{
    int nb = 0;
    int i = 0;
    int j;
    int k;

    while (i < room->y_max) {
        j = 0;
        while (j < room->z_max) {
            k = 0;
            while (k < room->x_max) {
                (room->room[i][j][k] >= 'a') ? nb++ : 0;
                k++;
            }
            j++;
        }
        i++;
    }
    return (nb);
}

int     get_nb_type(char type)
{
    int i = 0;

    while (type_enemy[i]) {
        if (type_enemy[i] == type)
            return (i + 1);
        i++;
    }
    return (0);
}

void    set_enemy(my_game_t *game, enemy_t *enemy, char type, int *tab)
{
    enemy->type = get_nb_type(type);
    enemy->pnj = pnj[enemy->type];
    enemy->vie = enemy_vie[enemy->type];
    enemy->degat = enemy_deg[enemy->type];
    enemy->dialog = start_dialog[enemy->type];
    enemy->nb_dialog = 0;
    enemy->name = rand() % 21;
    enemy->pos.y = tab[0] + 0.5;
    enemy->pos.z = tab[1] + 0.5;
    enemy->pos.x = tab[2] + 0.5;
    enemy->yaw = 0;
    if (!(enemy->obj = malloc(sizeof(obj_t)))) {
        enemy->vie = 0;
        return ;
    }
    copy_obj(&(enemy->obj), game->map->obj[to_copy[enemy->type]]);
    if (!enemy->obj)
        enemy->vie = 0;
}

void    set_all_enemy(my_game_t *game, room_t *room)
{
    int nb = 0;
    int tab[3] = {0, 0, 0};

    while (tab[0] < room->y_max) {
        tab[1] = 0;
        while (tab[1] < room->z_max) {
            tab[2] = 0;
            while (tab[2] < room->x_max) {
                (room->room[tab[0]][tab[1]][tab[2]] >= 'a') ? set_enemy(game,
&(room->enemy[nb]), room->room[tab[0]][tab[1]][tab[2]], tab) : 0;
                (room->room[tab[0]][tab[1]][tab[2]] >= 'a') ? nb++ : 0;
                tab[2]++;
            }
            tab[1]++;
        }
        tab[0]++;
    }
}

int     init_enemy(my_game_t *game)
{
    int i = 0;

    while (i < game->nb_room) {
        game->room[i]->nb_enemy = get_nb_enemy(game->room[i]);
        if (game->room[i]->nb_enemy <= 0 ||
!(game->room[i]->enemy = malloc(sizeof(enemy_t) * game->room[i]->nb_enemy)))
            return (0);
        set_all_enemy(game, game->room[i]);
        i++;
    }
    return (1);
}
