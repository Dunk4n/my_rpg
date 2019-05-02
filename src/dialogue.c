/*
** EPITECH PROJECT, 2018
** src/dialogue
** File description:
** don't forget to free at the end
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "struct.h"

void dialogue(png_t *png, sfRenderWindow *window, char *name, char *discuttion)
{
    sfTexture *chatbox_t = sfTexture_createFromFile(CHATBOX, NULL);
    sfSprite *chatbox = sfSprite_create();
    sfText *texte = sfText_create();
    sfText *t_name = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);

    sfSprite_setTexture(chatbox, chatbox_t, sfTrue);
    sfSprite_setTexture(png->s_png, png->t_png, sfTrue);
    sfText_setFont(texte, font);
    sfText_setFont(t_name, font);
    sfText_setCharacterSize(texte, 24);
    sfText_setCharacterSize(t_name, 24);
    sfText_setColor(texte, sfBlack);
    sfText_setColor(t_name, sfBlack);
    sfText_setString(texte, discuttion);
    sfText_setString(t_name, name);
    sfSprite_setPosition(chatbox, (sfVector2f){650, 440});
    sfSprite_setPosition(png->s_png, (sfVector2f){700, 520});
    sfText_setPosition(texte, (sfVector2f){850, 540});
    sfText_setPosition(t_name, (sfVector2f){850, 540});
    sfRenderWindow_drawSprite(window, chatbox, NULL);
    sfRenderWindow_drawSprite(window, png->s_png, NULL);
    sfRenderWindow_drawText(window, texte, NULL);
}
