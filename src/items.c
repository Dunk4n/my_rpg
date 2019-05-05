/*
** EPITECH PROJECT, 2018
** items.c
** File description:
** programmers start to count from 0
*/

#include "my.h"

void set_champ(item_t *items)
{
    (items[0]).name = "Amanite tue mouche";
    (items[0]).description = "Un petit remontant!";
    (items[0]).sprite = sfSprite_create();
    (items[0]).texture = sfTexture_createFromFile(CHAMP, NULL);
    sfSprite_setTexture((items[0]).sprite, (items[0]).texture, sfTrue);
    (items[0]).stamina = 25;
    (items[0]).mana = 10;
    (items[0]).life = 50;
    (items[0]).active = false;
}

void set_popo(item_t *items)
{
    items[1].name = "Potion de mana";
    items[1].description = "Du mana, merci!";
    items[1].sprite = sfSprite_create();
    items[1].texture = sfTexture_createFromFile(POPO, NULL);
    sfSprite_setTexture((items[1]).sprite, (items[1]).texture, sfTrue);
    items[1].mana = 50;
    items[1].life = 0;
    items[1].stamina = 25;
    items[1].active = false;
}

void set_apple(item_t *items)
{
    items[2].name = "Pomme";
    items[2].description = "Rien a déclarer";
    items[2].sprite = sfSprite_create();
    items[2].texture = sfTexture_createFromFile(APPLE, NULL);
    sfSprite_setTexture((items[2]).sprite, (items[2]).texture, sfTrue);
    items[2].stamina = 50;
    items[2].life = 0;
    items[2].mana = 10;
    items[2].active = false;
}

item_t *get_items(void)
{
    item_t *items = malloc(sizeof(item_t) * 3);
    if (!items)
        return NULL;
    set_champ(items);
    set_popo(items);
    set_apple(items);

    return (items);
}
