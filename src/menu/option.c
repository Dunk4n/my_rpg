/*
** EPITECH PROJECT, 2019
** option
** File description:
** option
*/

#include <stdbool.h>
#include "my.h"
#include "struct.h"

static opt_t init_option()
{
    opt_t opt;

    opt.t_opt = sfTexture_createFromFile(CREDIT, NULL);
    opt.s_opt = sfSprite_create();
    return opt;
}

static int echap(opt_t *opt, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(menu->window);
        if (menu->event.type == sfEvtKeyPressed &&
            menu->event.key.code == sfKeyEscape) {
            sfSprite_destroy(opt->s_opt);
            sfTexture_destroy(opt->t_opt);
            return true;
        }
    }
    return false;
}

void option(menu_t *menu)
{
    opt_t opt = init_option();

    sfRenderWindow_setFramerateLimit(menu->window, 60);
    while (sfRenderWindow_isOpen(menu->window)) {
        if (echap(&opt, menu))
            break;
        sfRenderWindow_drawSprite(menu->window, opt.s_opt, NULL);
        sfSprite_setTexture(opt.s_opt, opt.t_opt, sfTrue);
        sfRenderWindow_display(menu->window);
    }
}
