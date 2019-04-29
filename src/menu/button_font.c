/*
** EPITECH PROJECT, 2019
** button_font.c
** File description:
** all function for display font on menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"

static void print_start_button(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Play";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){885, 500});
    sfText_setCharacterSize(texte, 40);
    if (mouse.x >= 714 && mouse.x <= 1204 && mouse.y >= 480 && mouse.y <= 570)
        sfText_setColor(texte, sfRed);
    else
        sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void print_option_button(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Options";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){870, 625});
    sfText_setCharacterSize(texte, 40);
    if (mouse.x >= 714 && mouse.x <= 1204 && mouse.y >= 600 && mouse.y <= 690)
        sfText_setColor(texte, sfRed);
    else
        sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void print_credit_button(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Credits";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){870, 750});
    sfText_setCharacterSize(texte, 40);
    if (mouse.x >= 714 && mouse.x <= 1204 && mouse.y >= 723 && mouse.y <= 808)
        sfText_setColor(texte, sfRed);
    else
        sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void print_exit_button(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Exit";
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){870, 870});
    sfText_setCharacterSize(texte, 40);
    if (mouse.x >= 714 && mouse.x <= 1204 && mouse.y >= 845 && mouse.y <= 930)
        sfText_setColor(texte, sfRed);
    else
        sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

void print_all_menu(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "The Dwarf Prophecy.";


    print_start_button(menu);
    print_option_button(menu);
    print_credit_button(menu);
    print_exit_button(menu);
    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){450, 100});
    sfText_setCharacterSize(texte, 80);
    sfText_setColor(texte, sfBlack);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}
