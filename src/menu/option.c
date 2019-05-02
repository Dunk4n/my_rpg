/*
** EPITECH PROJECT, 2019
** option
** File description:
** option
*/

#include <stdbool.h>
#include "my.h"
#include "struct.h"

static opt_t init_new_opt(void)
{
    opt_t new_opt;

    new_opt.s_vol = sfSprite_create();
    new_opt.s_touch_one = sfSprite_create();
    new_opt.s_touch_two = sfSprite_create();
    new_opt.t_vol = sfTexture_createFromFile(VOL, NULL);
    new_opt.t_touch_two = sfTexture_createFromFile(TOUCH_T, NULL);
    new_opt.t_touch_one = sfTexture_createFromFile(TOUCH_O, NULL);
    new_opt.tf_clavier = sfTexture_createFromFile(F_CLAVIER, NULL);
    new_opt.sf_clavier = sfSprite_create();
    new_opt.ts_clavier = sfTexture_createFromFile(S_CLAVIER, NULL);
    new_opt.ss_clavier = sfSprite_create();
    new_opt.s_opt = sfSprite_create();
    new_opt.t_opt = sfTexture_createFromFile(CREDIT, NULL);
    return new_opt;
}

static void color_opt_choose(menu_t *menu, opt_t *new_opt, opt_t *opt)
{
    (opt->ctrl[0] == 0) ? sfSprite_setColor(new_opt->ss_clavier, sfRed):
sfSprite_setColor(new_opt->ss_clavier, sfWhite);
    (opt->ctrl[0] == 1) ? sfSprite_setColor(new_opt->sf_clavier, sfRed):
sfSprite_setColor(new_opt->sf_clavier, sfWhite);
    (opt->ctrl[1] == 0) ? sfSprite_setColor(new_opt->s_touch_one, sfRed):
sfSprite_setColor(new_opt->s_touch_one, sfWhite);
    (opt->ctrl[1] == 1) ? sfSprite_setColor(new_opt->s_touch_two, sfRed):
sfSprite_setColor(new_opt->s_touch_two, sfWhite);
    clic_option(menu, opt);
}

static void display_opt(menu_t *menu, opt_t *new_opt)
{
    sfSprite_setTexture(new_opt->s_touch_one, new_opt->t_touch_one, sfTrue);
    sfSprite_setTexture(new_opt->s_touch_two, new_opt->t_touch_two, sfTrue);
    sfSprite_setTexture(new_opt->sf_clavier, new_opt->tf_clavier, sfTrue);
    sfSprite_setTexture(new_opt->ss_clavier, new_opt->ts_clavier, sfTrue);
    sfSprite_setTexture(new_opt->s_opt, new_opt->t_opt, sfTrue);
    sfSprite_setTexture(new_opt->s_vol, new_opt->t_vol, sfTrue);
    sfRenderWindow_drawSprite(menu->window, new_opt->s_opt, NULL);
    sfRenderWindow_drawSprite(menu->window, new_opt->sf_clavier, NULL);
    sfRenderWindow_drawSprite(menu->window, new_opt->ss_clavier, NULL);
    sfRenderWindow_drawSprite(menu->window, new_opt->s_touch_one, NULL);
    sfRenderWindow_drawSprite(menu->window, new_opt->s_touch_two, NULL);
    sfRenderWindow_drawSprite(menu->window, new_opt->s_vol, NULL);
    sfSprite_setPosition(new_opt->ss_clavier, (sfVector2f){500, 350});
    sfSprite_setPosition(new_opt->sf_clavier, (sfVector2f){1000, 350});
    sfSprite_setPosition(new_opt->s_touch_one, (sfVector2f){500, 550});
    sfSprite_setPosition(new_opt->s_touch_two, (sfVector2f){1000, 550});
    sfSprite_setPosition(new_opt->s_vol, (sfVector2f){350, 625});
}

static int echap(opt_t *new_opt, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(menu->window, &menu->event)) {
        if (menu->event.type == sfEvtClosed)
            sfRenderWindow_close(menu->window);
        if (menu->event.type == sfEvtKeyPressed &&
            menu->event.key.code == sfKeyEscape) {
            delete(new_opt);
            return true;
        }
    }
    return false;
}

void option(menu_t *menu, opt_t *opt)
{
    opt_t new_opt = init_new_opt();

    while (sfRenderWindow_isOpen(menu->window)) {
        if (echap(&new_opt, menu))
            break;
        display_opt(menu, &new_opt);
        display_font(menu, opt);
        color_opt_choose(menu, &new_opt, opt);
        sfRenderWindow_display(menu->window);
    }
}
