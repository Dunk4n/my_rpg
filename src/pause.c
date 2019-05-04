/*
** EPITECH PROJECT, 2019
** pause.c
** File description:
** pause for rpg
*/

#include <stdlib.h>
#include "my.h"

static void replay(my_game_t *game, play_t *play)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);
    char const *string = "Continue";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win->window);

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){190, 90});
    sfText_setCharacterSize(texte, 20);
    if (mouse.x >= 714 && mouse.x <= 1204 && mouse.y >= 400 && mouse.y <= 500) {
        sfText_setColor(texte, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            play->pause = false;
            sfRenderWindow_setMouseCursorVisible(game->win->window, sfFalse);
        }
    }
    else
        sfText_setColor(texte, sfBlack);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(game->win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void quit(my_game_t *game, play_t *play)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);
    char const *string = "Quit";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win->window);

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){190, 135});
    sfText_setCharacterSize(texte, 20);
    if (mouse.x >= 714 && mouse.x <= 1204 && mouse.y >= 510 && mouse.y <= 610) {
        sfText_setColor(texte, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            free(game);
            sfRenderWindow_close(game->win->window);
            menu_window(game);
        }
    }
    else
        sfText_setColor(texte, sfBlack);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(game->win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static int text_pause(my_game_t *game, play_t *play)
{
    replay(game, play);
    quit(game, play);
    return 0;
}

void pause_game(play_t *play, my_game_t *game)
{
    sfSprite *pause = sfSprite_create();
    sfTexture *t_pause = sfTexture_createFromFile(PAUSE, NULL);

    sfSprite_setTexture(pause, t_pause, sfTrue);
    sfRenderWindow_setMouseCursorVisible(game->win->window, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        sfRenderWindow_drawSprite(game->win->window, pause, NULL);
        text_pause(game, play);
        if (play->pause == false)
            break;
        sfRenderWindow_display(game->win->window);
    }
    sfSprite_setColor(pause, sfWhite);
    sfSprite_destroy(pause);
    sfTexture_destroy(t_pause);
}
