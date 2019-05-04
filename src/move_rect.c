/*
** EPITECH PROJECT, 2019
** move_rect
** File description:
** animate sprite
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "struct.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value) {
        rect->left = 0;
    }
}
