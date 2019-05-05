/*
** EPITECH PROJECT, 2019
** init_png
** File description:
** init_png
*/

#include <stdlib.h>
#include "my.h"

const char      *avatar[24] = {"./img/avatar/Avatar1.png",
"./img/avatar/Avatar2.png", "./img/avatar/Avatar3.png",
"./img/avatar/Avatar4.png", "./img/avatar/Avatar5.png",
"./img/avatar/Avatar6.png", "./img/avatar/Avatar7.png",
"./img/avatar/Avatar8.png", "./img/avatar/Avatar9.png",
"./img/avatar/Avatar10.png", "./img/avatar/Avatar11.png",
"./img/avatar/Avatar12.png", "./img/avatar/Avatar13.png",
"./img/avatar/Avatar14.png", "./img/avatar/Avatar15.png",
"./img/avatar/Avatar16.png", "./img/avatar/Avatar17.png",
"./img/avatar/Avatar18.png", "./img/avatar/Avatar19.png",
"./img/avatar/Avatar20.png", "./img/avatar/Avatar21.png",
"./img/avatar/Avatar22.png","./img/avatar/Avatar23.png",
"./img/avatar/Avatar24.png"};

png_t *init_png(void)
{
    png_t *png = malloc(sizeof(png_t) * 24);
    size_t i = 0;

    if (png == NULL)
        return NULL;
    while (i < 24) {
        png[i].s_png = sfSprite_create();
        png[i].t_png = sfTexture_createFromFile(avatar[i], NULL);
        i++;
    }
    return png;
}
