/*
** EPITECH PROJECT, 2019
** perso.c
** File description:
** choose name
*/

#include "my.h"
#include "struct.h"
#include "world.h"

void choose_name(opt_t *opt)
{
    my_game_t *game = set_game();
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(NAME, NULL);

    if (!game)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        sfRenderWindow_drawSprite(game->win->window, sprite, NULL);
        while (sfRenderWindow_pollEvent(game->win->window,
&(game->win->event))) {
            if (get_name(game)) {
                ft_game(game, opt);
                return;
            }
        }
        sfRenderWindow_drawText(game->win->window, game->name_text, NULL);
        sfRenderWindow_display(game->win->window);
     }
}
