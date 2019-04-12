/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu for rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "world.h"
#include "my.h"
#include "struct.h"

static void option(win_t *win)
{
    return ;
}

static void credit(win_t *win)
{
    sfTexture *t_credit = sfTexture_createFromFile(CREDIT, NULL);
    sfSprite *s_credit = sfSprite_create();
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Credit:\n this game is a epitech project create by :\
\nVictor Rouxel\nNicolas Duchesne\nAlexandre Wagner\n";

    while (sfRenderWindow_isOpen(win->window)) {
        sfSprite_setTexture(s_credit, t_credit, sfTrue);
        sfText_setFont(texte, font);
        sfText_setPosition(texte, (sfVector2f){100, 100});
        sfText_setCharacterSize(texte, 40);
        sfText_setColor(texte, sfWhite);
        sfText_setString(texte, string);
        sfRenderWindow_drawText(win->window, texte, NULL);
        sfText_destroy(texte);
        sfFont_destroy(font);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            return ;
    }
}

static void echap(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        (win->event.type == sfEvtClosed) ?
sfRenderWindow_close(win->window) : 0;
        (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) ?
sfRenderWindow_close(win->window) : 0;
    }
}

static void menu_opt_clic(win_t *win, my_game_t *game)
{
    int clic_x = win->event.mouseButton.x;
    int clic_y = win->event.mouseButton.y;

    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 480 && clic_y <= 570)
        ft_game(game);
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 600 && clic_y <= 690)
        option(win);
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 723 && clic_y <= 808)
        credit(win);
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 845 && clic_y <= 930)
        sfRenderWindow_close(win->window);
}

int menu_window(win_t *win, my_game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t) + 1);

    init_menu(menu);
    while (sfRenderWindow_isOpen(win->window)) {
        echap(win);
        sfRenderWindow_setFramerateLimit(win->window, 60);
        sfRenderWindow_drawSprite(win->window, menu->s_menu, NULL);
        display_menu(menu);
        print_all_menu(win);
        menu_opt_clic(win, game);
        sfRenderWindow_display(win->window);
    }
    return (1);
}
