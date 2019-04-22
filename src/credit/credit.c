/*
** EPITECH PROJECT, 2019
** credit
** File description:
** credit_menu
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "struct.h"

const char *s = "Projet realiser dans le cadre du module graphique d'Epitech";
const char *s2 = "Createur: Nicolas Duchesne-Alexandre Wagner-Victor Rouxel";

static credit_t init_credit()
{
    credit_t credit;

    credit.t_credit = sfTexture_createFromFile(CREDIT, NULL);
    credit.s_credit = sfSprite_create();
    return credit;
}

static int echap(credit_t *credit, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(menu->window);
        if (menu->event.type == sfEvtKeyPressed &&
menu->event.key.code == sfKeyEscape) {
            sfSprite_destroy(credit->s_credit);
            sfTexture_destroy(credit->t_credit);
            return true;
        }
    }
    return false;
}

static void credit_text(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);
    char const *string = "Credit :";

    sfText_setFont(texte, font);
    sfText_setPosition(texte, (sfVector2f){945, 150});
    sfText_setCharacterSize(texte, 80);
    sfText_setColor(texte, sfWhite);
    sfText_setString(texte, string);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfText_destroy(texte);
    sfFont_destroy(font);
}

static void credit_text_2(menu_t *menu)
{
    sfText *texte = sfText_create();
    sfText *texte2 = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);

    sfText_setFont(texte, font);
    sfText_setFont(texte2, font);
    sfText_setPosition(texte, (sfVector2f){400, 400});
    sfText_setPosition(texte2, (sfVector2f){400, 500});
    sfText_setCharacterSize(texte, 40);
    sfText_setCharacterSize(texte2, 40);
    sfText_setColor(texte, sfWhite);
    sfText_setColor(texte2, sfWhite);
    sfText_setString(texte, s);
    sfText_setString(texte2, s2);
    sfRenderWindow_drawText(menu->window, texte, NULL);
    sfRenderWindow_drawText(menu->window, texte2, NULL);
    sfText_destroy(texte);
    sfText_destroy(texte2);
    sfFont_destroy(font);
}

void credit(menu_t *menu)
{
    credit_t credit = init_credit();

    sfRenderWindow_setFramerateLimit(menu->window, 60);
    while (sfRenderWindow_isOpen(menu->window)) {
        if (echap(&credit, menu))
            break;
        sfRenderWindow_drawSprite(menu->window, credit.s_credit, NULL);
        sfSprite_setTexture(credit.s_credit, credit.t_credit, sfTrue);
        credit_text(menu);
        credit_text_2(menu);
        sfRenderWindow_display(menu->window);
    }
}
