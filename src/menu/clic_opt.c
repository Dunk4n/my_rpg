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
    int clic_x = menu->event.mouseButton.x;
    int clic_y = menu->event.mouseButton.y;

    if (clic_x >= 610 && clic_x <= 833 && clic_y >= 420 && clic_y <= 560)
        button_action(opt, 1);
    else if (clic_x >= 1100 && clic_x <= 1350 && clic_y >= 420 && clic_y <= 560)
        button_action(opt, 2);
    else if (clic_x >= 490 && clic_x <= 800 && clic_y >= 585 && clic_y <= 715)
        button_action(opt, 3);
    else if (clic_x >= 950 && clic_x <= 1280 && clic_y >= 585 && clic_y <= 715)
        button_action(opt, 4);
    else if (clic_x >= 660 && clic_x <= 760 && clic_y >= 760 && clic_y <= 820)
        button_action(opt, 5);
    else if (clic_x >= 800 && clic_x <= 900 && clic_y >= 760 && clic_y <= 820)
        button_action(opt, 6);
}
