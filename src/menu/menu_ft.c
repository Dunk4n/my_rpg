/*
** EPITECH PROJECT, 2019
** menu_ft
** File description:
** function for init and use menu
*/

#include "my.h"

void init_menu(menu_t *menu)
{
    menu->t_menu = sfTexture_createFromFile(MENU, NULL);
    menu->s_menu = sfSprite_create();
    menu->music = sfMusic_createFromFile(MENU_MUSIC);
    sfMusic_play(menu->music);
    sfMusic_setLoop(menu->music, sfTrue);
}

int clic_menu(win_t *win)
{
    int clic_x = win->event.mouseButton.x;
    int clic_y = win->event.mouseButton.y;

}

void event_function(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->window);
    }
}

void display_menu(menu_t *menu)
{
    sfSprite_setTexture(menu->s_menu, menu->t_menu, sfTrue);
}
