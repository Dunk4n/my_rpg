/*
** EPITECH PROJECT, 2018
** src/init_texture
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "world.h"

const char      *img_name[3] = {"img/wall2.png", "img/wall3.png",
"img/door.png"};

void    set_img(my_game_t *game)
{
    int i = 0;

    game->nb_col_max = 10;
    game->nb_img = 3;
    if (game->nb_img < 1 ||
    !(game->img = malloc(sizeof(sfImage*) * game->nb_img)))
        return ;
    while (i < game->nb_img) {
        game->img[i] = sfImage_createFromFile(img_name[i]);
        i++;
    }
}

void    set_identity_matrix(camera_t *camera)
{
    int i = 0;
    int nb = 0;

    while (i < 9) {
        if (i == nb) {
            camera->rot[i] = 1;
            nb += 4;
        }
        else
            camera->rot[i] = 0;
        i++;
    }
}

int     init_all_3d(my_game_t *game)
{
    game->nb_img = 0;
    game->map->obj = NULL;
    if (!(game->camera = malloc(sizeof(camera_t))))
        return (0);
    game->camera->point[0] = (sfVector3f){0, 0, 0};
    game->camera->point[1] = (sfVector3f){1, 0, 0};
    game->camera->point[2] = (sfVector3f){0, 1, 0};
    game->camera->move = (sfVector3f){0, 0, 0};
    set_identity_matrix(game->camera);
    game->camera->roll = 0;
    game->camera->yaw = 0;
    game->camera->pitch = 0;
    game->room = 0;
    set_img(game);
    if (!(charge_obj(game)))
        return (0);
    game->camera->roll_cam = 0;
    return (1);
}
