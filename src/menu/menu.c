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

static void option(menu_t *menu)
{
    return ;
}

static void credit(menu_t *menu)
{
    sfTexture *t_credit = sfTexture_createFromFile(CREDIT, NULL);
    sfSprite *s_credit = sfSprite_create();
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Credit:\n";

    while (sfRenderWindow_isOpen(menu->window)) {
        sfSprite_setTexture(s_credit, t_credit, sfTrue);
        sfText_setFont(texte, font);
        sfText_setPosition(texte, (sfVector2f){100, 100});
        sfText_setCharacterSize(texte, 40);
        sfText_setColor(texte, sfWhite);
        sfText_setString(texte, string);
        sfRenderWindow_drawText(menu->window, texte, NULL);
        sfText_destroy(texte);
        sfFont_destroy(font);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            return ;
    }
}

static void echap(menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        (menu->event.type == sfEvtClosed) ?
sfRenderWindow_close(menu->window) : 0;
        (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) ?
sfRenderWindow_close(menu->window) : 0;
    }
}

static void menu_opt_clic(menu_t *menu, my_game_t *game)
{
    int clic_x = menu->event.mouseButton.x;
    int clic_y = menu->event.mouseButton.y;

    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 480 && clic_y <= 570) {
        sfRenderWindow_close(menu->window);
        ft_game(game);
    }
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 600 && clic_y <= 690)
        option(menu);
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 723 && clic_y <= 808)
        credit(menu);
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 845 && clic_y <= 930)
        sfRenderWindow_close(menu->window);
}

int menu_window(my_game_t *game)
{
    menu_t *menu = malloc(sizeof(menu_t) + 1);

    init_menu(menu);
    while (sfRenderWindow_isOpen(menu->window)) {
        echap(menu);
        sfRenderWindow_setFramerateLimit(menu->window, 60);
        sfRenderWindow_drawSprite(menu->window, menu->s_menu, NULL);
        display_menu(menu);
        print_all_menu(menu);
        menu_opt_clic(menu, game);
        sfRenderWindow_display(menu->window);
    }
    return (1);
}
