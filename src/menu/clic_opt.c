/*
** EPITECH PROJECT, 2018
** clic_opt
** File description:
** clic_opt
*/

#include "my.h"

static void button_action(opt_t *opt, size_t action)
{
    sfSound_play(opt->button);
    (action == 1) ? opt->ctrl[0] = 0 : 0;
    (action == 2) ? opt->ctrl[0] = 1 : 0;
    (action == 3) ? opt->ctrl[1] = 0 : 0;
    (action == 4) ? opt->ctrl[1] = 1 : 0;
    (action == 5) ? opt->vol_ac = opt->vol_ac - 10 : 0;
    (action == 6) ? opt->vol_ac = opt->vol_ac + 10 : 0;
    if (opt->vol_ac < 0)
        opt->vol_ac = 0;
    if (opt->vol_ac > 100)
        opt->vol_ac = 100;
}

void clic_option(menu_t *menu, opt_t *opt)
{
    if (menu->event.mouseButton.x >= 610 && menu->event.mouseButton.x <= 833 &&
menu->event.mouseButton.y >= 420 && menu->event.mouseButton.y <= 560)
        button_action(opt, 1);
    if (menu->event.mouseButton.x >= 1100 && menu->event.mouseButton.x <= 1350 &&
menu->event.mouseButton.y >= 420 && menu->event.mouseButton.y <= 560)
        button_action(opt, 2);
    if (menu->event.mouseButton.x >= 490 && menu->event.mouseButton.x <= 800 &&
menu->event.mouseButton.y >= 585 && menu->event.mouseButton.y <= 715)
        button_action(opt, 3);
    if (menu->event.mouseButton.x >= 950 && menu->event.mouseButton.x <= 1280 &&
menu->event.mouseButton.y >= 585 && menu->event.mouseButton.y <= 715)
        button_action(opt, 4);
    if (menu->event.mouseButton.x >= 660 && menu->event.mouseButton.x <= 760 &&
menu->event.mouseButton.y >= 760 && menu->event.mouseButton.y <= 820)
        button_action(opt, 5);
    if (menu->event.mouseButton.x >= 800 && menu->event.mouseButton.x <= 900 &&
menu->event.mouseButton.y >= 760 && menu->event.mouseButton.y <= 820)
        button_action(opt, 6);
}
