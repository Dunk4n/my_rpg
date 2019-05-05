/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu for rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "world.h"
#include "my.h"
#include "struct.h"

static void move_menu(menu_t *menu, size_t val, opt_t *opt)
{
    (val == 0) ? menu->opt++ : 0;
    (val == 1) ? menu->opt-- : 0;
    (menu->opt < 1) ? menu->opt = 1 : 0;
    (menu->opt == 1) ? menu->p_select.y = 420 : 0;
    (menu->opt == 1) ? menu->p_anim.y = menu->p_select.y + 50 : 0;
    if (menu->opt == 2) {
        menu->p_select.y = 540;
        menu->p_anim.y = menu->p_select.y + 50;
    }
    if (menu->opt == 3) {
        menu->p_select.y = 670;
        menu->p_anim.y = menu->p_select.y + 50;
    }
    if (menu->opt == 4) {
        menu->p_select.y = 790;
        menu->p_anim.y = menu->p_select.y + 50;
    }
    sfSound_play(opt->button);
    (menu->opt > 4) ? menu->opt = 4 : 0;
    sfSprite_setPosition(menu->s_sel, menu->p_select);
    sfSprite_setPosition(menu->s_anim, menu->p_anim);
}

static void rectchoose(menu_t *menu, opt_t *opt)
{
    if (menu->opt == 1) {
        sfRenderWindow_close(menu->window);
        sfMusic_destroy(opt->music);
        choose_name(opt);
    }
    if (menu->opt == 2)
        option(menu, opt);
    if (menu->opt == 3)
        credit(menu);
    if (menu->opt == 4)
        sfRenderWindow_close(menu->window);
}

static void click(menu_t *menu, opt_t *opt)
{
    int clic_x = menu->event.mouseButton.x;
    int clic_y = menu->event.mouseButton.y;

    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 480 && clic_y <= 570) {
        sfSound_play(opt->button);
        sfRenderWindow_close(menu->window);
        sfMusic_destroy(opt->music);
        choose_name(opt);
    }
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 600 && clic_y <= 690) {
        sfSound_play(opt->button);
        option(menu, opt);
    }
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 723 && clic_y <= 808) {
        sfSound_play(opt->button);
        credit(menu);
    }
    if (clic_x >= 714 && clic_x <= 1204 && clic_y >= 845 && clic_y <= 930) {
        sfSound_play(opt->button);
        sfRenderWindow_close(menu->window);
    }
}

static void menu_opt_clic(menu_t *menu, opt_t *opt)
{
    static size_t button = 0;

    click(menu, opt);
    if (button == 0 && menu->event.type == sfEvtKeyPressed) {
        button = 1;
        (menu->event.key.code == sfKeyUp) ?  move_menu(menu, 1, opt) : 0;
        (menu->event.key.code == sfKeyDown) ? move_menu(menu, 0, opt) : 0;
    }
    else if (menu->event.type == sfEvtKeyReleased)
        button = 0;
    (sfKeyboard_isKeyPressed(sfKeyReturn)) ? rectchoose(menu, opt) : 0;
}

int menu_window(void)
{
    menu_t menu;
    opt_t opt;

    if (!init_default_option(&opt, &menu))
        return (0);
    init_menu(&menu, &opt);
    sfRenderWindow_setFramerateLimit(menu.window, 60);
    while (sfRenderWindow_isOpen(menu.window)) {
        while (sfRenderWindow_pollEvent(menu.window, &menu.event)) {
            (menu.event.type == sfEvtClosed) ?
sfRenderWindow_close(menu.window) : 0;
            (menu.event.type == sfEvtKeyPressed &&
menu.event.key.code == sfKeyEscape) ?
sfRenderWindow_close(menu.window) : 0;
        }
        display_menu(&menu);
        print_all_menu(&menu);
        menu_opt_clic(&menu, &opt);
        sfRenderWindow_display(menu.window);
    }
    return (1);
}
