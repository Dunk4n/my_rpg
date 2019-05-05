/*
** EPITECH PROJECT, 2018
** src/dialogue
** File description:
** don't forget to free at the end
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "struct.h"

static void text(sfText *text, sfText *t_name, sfFont *font,
char **tmp)
{
    sfText_setFont(text, font);
    sfText_setFont(t_name, font);
    sfText_setCharacterSize(text, 10);
    sfText_setCharacterSize(t_name, 10);
    sfText_setColor(text, sfBlack);
    sfText_setColor(t_name, sfBlack);
    sfText_setString(text, tmp[1]);
    sfText_setString(t_name, tmp[0]);
    sfText_setPosition(text, (sfVector2f){40, 18});
    sfText_setPosition(t_name, (sfVector2f){40, 4});
}

void dialogue(png_t *png, sfRenderWindow *window,
char const *name, char const *discuttion)
{
    char *tmp[2] = {(char*)name, (char*)discuttion};

    sfTexture *chatbox_t = sfTexture_createFromFile(CHATBOX, NULL);
    sfSprite *chatbox = sfSprite_create();
    sfText *texte = sfText_create();
    sfText *t_name = sfText_create();
    sfFont *font = sfFont_createFromFile(GOT);
    sfSprite_setTexture(chatbox, chatbox_t, sfTrue);
    sfSprite_setTexture(png->s_png, png->t_png, sfTrue);
    sfSprite_setScale(png->s_png, (sfVector2f){0.18, 0.18});
    sfSprite_setScale(chatbox, (sfVector2f){0.65, 0.2});
    sfSprite_setPosition(chatbox, (sfVector2f){0, -10});
    sfSprite_setPosition(png->s_png, (sfVector2f){10, 4});
    text(texte, t_name, font, tmp);
    sfRenderWindow_drawSprite(window, chatbox, NULL);
    sfRenderWindow_drawSprite(window, png->s_png, NULL);
    sfRenderWindow_drawText(window, texte, NULL);
    sfRenderWindow_drawText(window, t_name, NULL);
}
