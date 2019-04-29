/*
** EPITECH PROJECT, 2019
** print_opt.c
** File description:
** print_font for option
*/

#include <SFML/Graphics.h>
#include "my.h"

static void title(sfText *text, sfFont *font, menu_t *menu, char const *n)
{
    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){845, 200});
    sfText_setCharacterSize(text, 65);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, n);
    sfRenderWindow_drawText(menu->window, text, NULL);
}

static void print_move(sfText *text, sfFont *font, menu_t *menu, char const *n)
{
    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){275, 500});
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, n);
    sfRenderWindow_drawText(menu->window, text, NULL);
}

static void print_act(sfText *text, sfFont *font, menu_t *menu, char const *n)
{
    sfText_setFont(text, font);
    sfText_setPosition(text, (sfVector2f){300, 650});
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, n);
    sfRenderWindow_drawText(menu->window, text, NULL);
}

static void print_musique(sfText *text, sfFont *font, menu_t *menu, opt_t *opt)
{
    sfText *vol = sfText_create();
    char const *n = "Music :";

    sfText_setFont(text, font);
    sfText_setFont(vol, font);
    sfText_setPosition(vol, (sfVector2f){600, 800});
    sfText_setPosition(text, (sfVector2f){300, 800});
    sfText_setCharacterSize(text, 35);
    sfText_setCharacterSize(vol, 50);
    sfText_setColor(text, sfWhite);
    sfText_setColor(vol, sfWhite);
    sfText_setString(text, n);
    sfText_setString(vol, my_itoa(opt->vol_ac));
    sfRenderWindow_drawText(menu->window, text, NULL);
    sfRenderWindow_drawText(menu->window, vol, NULL);
}

void display_font(menu_t *menu, opt_t *opt)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);

    title(texte, font, menu, "Option / Touche");
    print_move(texte, font, menu, "Deplacement :");
    print_act(texte, font, menu, "Action :");
    print_musique(texte, font, menu, opt);
    sfText_destroy(texte);
    sfFont_destroy(font);
}
