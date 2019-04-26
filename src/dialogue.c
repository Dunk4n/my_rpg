/*
** EPITECH PROJECT, 2018
** src/dialogue
** File description:
** don't forget to free at the end
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "struct.h"

void dialogue(sfSprite *sprite, sfTexture *Texture, sfRenderWindow *window,
char *discuttion)
{
    sfTexture *chatbox_t = sfTexture_createFromFile(CHATBOX, NULL);
    sfSprite *chatbox = sfSprite_create();
    sfText *texte = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);

    sfSprite_setTexture(chatbox, chatbox_t, sfTrue);
    sfSprite_setTexture(sprite, Texture, sfTrue);
    sfText_setFont(texte, font);
    sfText_setCharacterSize(texte, 24);
    sfText_setColor(texte, sfBlack);
    sfText_setString(texte, discuttion);
    sfSprite_setPosition(chatbox, (sfVector2f){650, 440});
    sfSprite_setPosition(sprite, (sfVector2f){700, 520});
    sfText_setPosition(texte, (sfVector2f){850, 540});
    sfRenderWindow_drawSprite(window, chatbox, NULL);
    sfRenderWindow_drawText(window, texte, NULL);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
