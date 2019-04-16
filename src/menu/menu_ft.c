/*
** EPITECH PROJECT, 2019
** menu_ft
** File description:
** function for init and use menu
*/

#include "my.h"

void init_menu(menu_t *menu)
{
    sfVideoMode video = {1920, 1080, 32};
    char const *n = "Dwarf game";
    menu->t_menu = sfTexture_createFromFile(MENU, NULL);
    menu->s_menu = sfSprite_create();
    menu->music = sfMusic_createFromFile(MENU_MUSIC);
    sfMusic_play(menu->music);
    sfMusic_setLoop(menu->music, sfTrue);
    menu->window = sfRenderWindow_create(video, n, sfDefaultStyle, NULL);
}

int clic_menu(menu_t *menu)
{
    int clic_x = menu->event.mouseButton.x;
    int clic_y = menu->event.mouseButton.y;

}

void event_function(menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(menu->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(menu->window);
    }
}

void display_menu(menu_t *menu)
{
    sfSprite_setTexture(menu->s_menu, menu->t_menu, sfTrue);
}
