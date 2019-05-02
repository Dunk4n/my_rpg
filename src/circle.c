/*
** EPITECH PROJECT, 2018
** src/circle
** File description:
** try not to segfault, good luck :)
*/

#include <math.h>
#include "my.h"
#include "world.h"

void    draw_simple_circle(my_framebuff_t *buff, sfVector2f pos, int size,
sfColor color)
{
    int size_2 = size / 2;
    sfVector2i start = {pos.x - size_2, pos.y - size_2};
    sfVector2i end = {pos.x + size_2, pos.y + size_2};
    size_t i = start.y;
    size_t j;

    if (pos.x - size < 0 || pos.y - size < 0)
        return ;
    while (i <= (size_t)end.y) {
        j = start.x;
        while (j <= (size_t)end.x) {
            (my_pow(j - pos.x, 2) + my_pow(i - pos.y, 2) <= my_pow(size_2, 2)) ?
put_pixel(buff, j, i, color) : 0;
            j++;
        }
        i++;
    }
}
