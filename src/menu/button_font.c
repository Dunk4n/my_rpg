/*
** EPITECH PROJECT, 2019
** button_font.c
** File description:
** all function for display font on menu
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"

static void print_start_button(win_t *win)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Play";

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){885, 500});
    sfText_setCharacterSize(texte, 40);
    sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void print_option_button(win_t *win)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Options";

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){870, 625});
    sfText_setCharacterSize(texte, 40);
    sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void print_credit_button(win_t *win)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Credits";

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){870, 750});
    sfText_setCharacterSize(texte, 40);
    sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void print_exit_button(win_t *win)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "Exit";

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){870, 870});
    sfText_setCharacterSize(texte, 40);
    sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

void print_all_menu(win_t *win)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(RUNES);
    char const *string = "The Dwarf Prophecy.";

    print_start_button(win);
    print_option_button(win);
    print_credit_button(win);
    print_exit_button(win);
    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){450, 100});
    sfText_setCharacterSize(texte, 80);
    sfText_setColor(texte, sfBlack);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(win->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}
