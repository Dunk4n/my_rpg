/*
** EPITECH PROJECT, 2019
** dead.c
** File description:
** menu when u dead
*/

#include "my.h"

const char *quit = "Quitter";

static void option_dead(my_game_t *game, sfText *t_quit)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win->window);

    if (mouse.x >= 1160  && mouse.x <= 1560 && mouse.y >= 770 && mouse.y <= 970)  {
        sfText_setColor(t_quit, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(game->win->window);
    }
    else
        sfText_setColor(t_quit, sfWhite);
}

static void text_dead(my_game_t *game)
{
    sfText *t_quit = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);

    sfText_setFont(t_quit, font);
    sfText_setPosition(t_quit, (sfVector2f){350, 200});
    sfText_setCharacterSize(t_quit, 24);
    option_dead(game, t_quit);
    sfText_setString(t_quit, quit);
    sfRenderWindow_drawText(game->win->window, t_quit, NULL);
    sfText_destroy(t_quit);
    sfFont_destroy(font);
}

void dead(my_game_t *game)
{
    sfSprite *s_dead = sfSprite_create();
    sfTexture *t_dead = sfTexture_createFromFile(DEAD, NULL);

    sfSprite_setTexture(s_dead, t_dead, sfTrue);
    sfRenderWindow_setMouseCursorVisible(game->win->window, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        sfRenderWindow_drawSprite(game->win->window, s_dead, NULL);
        text_dead(game);
        sfRenderWindow_display(game->win->window);
    }
}
