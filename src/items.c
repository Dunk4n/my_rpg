/*
** EPITECH PROJECT, 2018
** items.c
** File description:
** programmers start to count from 0
*/

#include "my.h"

void set_beer(item_t *items)
{
    (items[0]).name = "Pinte de Chouffe";
    (items[0]).description = "Un petit remontant!";
    (items[0]).sprite = sfSprite_create();
    (items[0]).texture = sfTexture_createFromFile(CHAMP, NULL);
    sfSprite_setTexture((items[0]).sprite, (items[0]).texture, sfTrue);
    (items[0]).buff = 50;
}

void set_popo(item_t *items)
{
    items[1].name = "Potion de mana";
    items[1].description = "Du mana, merci!";
    items[1].sprite = sfSprite_create();
    items[1].texture = sfTexture_createFromFile(POPO, NULL);
    sfSprite_setTexture((items[1]).sprite, (items[1]).texture, sfTrue);
    items[1].buff = 50;
}

void set_apple(item_t *items)
{
    items[2].name = "Pomme";
    items[2].description = "Rien a déclarer";
    items[2].sprite = sfSprite_create();
    items[2].texture = sfTexture_createFromFile(APPLE, NULL);
    sfSprite_setTexture((items[2]).sprite, (items[2]).texture, sfTrue);
    items[2].buff = 50;
}

item_t *get_items(void)
{
    item_t *items = malloc(sizeof(item_t) * 3);
    if (!items)
        return NULL;    
    set_beer(items);
    set_popo(items);
    set_apple(items);

    return (items);
}