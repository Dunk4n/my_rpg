/*
** EPITECH PROJECT, 2019
** dead.c
** File description:
** menu when u dead
*/

#include "struct.h"
#include "world.h"
#include "my.h"

const char *leave = "Quitter";

static void option_win(my_game_t *game, sfText *t_leave)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win->window);

    if (mouse.x >= 1160  && mouse.x <= 1560 && mouse.y >= 770 && mouse.y
<= 970) {
        sfText_setColor(t_leave, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(game->win->window);
    }
    else
        sfText_setColor(t_leave, sfWhite);
}

static void text_win(my_game_t *game)
{
    sfText *t_leave = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);

    sfText_setFont(t_leave, font);
    sfText_setPosition(t_leave, (sfVector2f){350, 200});
    sfText_setCharacterSize(t_leave, 24);
    option_win(game, t_leave);
    sfText_setString(t_leave, leave);
    sfRenderWindow_drawText(game->win->window, t_leave, NULL);
    sfText_destroy(t_leave);
    sfFont_destroy(font);
}

void win(my_game_t *game)
{
    sfSprite *s_win = sfSprite_create();
    sfTexture *t_win = sfTexture_createFromFile(WIN, NULL);

    sfSprite_setTexture(s_win, t_win, sfTrue);
    sfRenderWindow_setMouseCursorVisible(game->win->window, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        sfRenderWindow_drawSprite(game->win->window, s_win, NULL);
        text_win(game);
        sfRenderWindow_display(game->win->window);
    }
}
