/*
** EPITECH PROJECT, 2018
** src/particle
** File description:
** epitech > epita
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"
#include "struct.h"

void    rand_bottom(my_framebuff_t *buff)
{
    size_t  i = 0;
    size_t  line = buff->width * (buff->height - 1);

    while (i < (unsigned int)buff->width) {
        buff->pixels[(line + i) * 4] = 255;
        buff->pixels[(line + i) * 4 + 1] = rand() % 225;
        buff->pixels[(line + i) * 4 + 2] = 0;
        buff->pixels[(line + i) * 4 + 3] = 255;
        i++;
    }
}

void    get_other_color(my_framebuff_t *buff, int i, int j, sfVector3f *color)
{
    if (j - 1 < buff->width) {
        color->x += buff->pixels[(buff->width * (i + 1) + j - 1) * 4];
        color->y += buff->pixels[(buff->width * (i + 1) + j - 1) * 4 + 1];
        color->z += buff->pixels[(buff->width * (i + 1) + j - 1) * 4 + 2];
    }
    if (i + 2 < buff->height) {
        color->x += buff->pixels[(buff->width * (i + 2) + j) * 4];
        color->y += buff->pixels[(buff->width * (i + 2) + j) * 4 + 1];
        color->z += buff->pixels[(buff->width * (i + 2) + j) * 4 + 2];
    }
}

sfColor get_color_at(my_framebuff_t *buff, int i, int j)
{
    int tmp;
    sfVector3f color;

    if (i + 1 >= buff->height)
        return (sfRed);
    tmp = buff->width * (i + 1) + j;
    color.x = buff->pixels[tmp * 4];
    color.y = buff->pixels[tmp * 4 + 1];
    color.z = buff->pixels[tmp * 4 + 2];
    if (j + 1 < buff->width) {
        color.x += buff->pixels[(tmp + 1) * 4];
        color.y += buff->pixels[(tmp + 1) * 4 + 1];
        color.z += buff->pixels[(tmp + 1) * 4 + 2];
    }
    get_other_color(buff, i, j, &color);
    return ((sfColor){color.x / 4.08, color.y / 4.08, color.z / 4.08, 255});
}

void    make_fire(my_framebuff_t *buff)
{
    int     i = buff->height - 100;
    int     j;
    sfColor tmp;

    while (i < buff->height - 1) {
        j = 0;
        while (j < buff->width) {
            tmp = get_color_at(buff, i, j);
            buff->pixels[(buff->width * i + j) * 4] = tmp.r;
            buff->pixels[(buff->width * i + j) * 4 + 1] = tmp.g;
            buff->pixels[(buff->width * i + j) * 4 + 2] = tmp.b;
            buff->pixels[(buff->width * i + j) * 4 + 3] = 255;
            //(tmp.r > tmp.g) ? tmp.r : tmp.g;
            j++;
        }
        i++;
    }
}

void    make_particle(my_framebuff_t *buff)
{
    rand_bottom(buff);
    make_fire(buff);
}
