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
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);

    if (mouse.x >= 610 && mouse.x <= 833 &&
 mouse.y >= 420 && mouse.y <= 560 && sfMouse_isButtonPressed(sfMouseLeft))
        button_action(opt, 1);
    if (mouse.x >= 1100 && mouse.x <= 1350 &&
mouse.y >= 420 && mouse.y <= 560 && sfMouse_isButtonPressed(sfMouseLeft))
        button_action(opt, 2);
    if (mouse.x >= 490 && mouse.x <= 800 &&
mouse.y >= 585 && mouse.y <= 715 && sfMouse_isButtonPressed(sfMouseLeft))
        button_action(opt, 3);
    if (mouse.x >= 950 && mouse.x <= 1280 &&
mouse.y >= 585 && mouse.y <= 715 && sfMouse_isButtonPressed(sfMouseLeft))
        button_action(opt, 4);
    if (mouse.x > 480 && mouse.x <= 570 &&
        mouse.y >= 780 && mouse.y <= 870 && sfMouse_isButtonPressed(sfMouseLeft))
        button_action(opt, 5);
    if (mouse.x >= 740 && mouse.x <= 810 &&
        mouse.y >= 780 && mouse.y <= 870 && sfMouse_isButtonPressed(sfMouseLeft))
        button_action(opt, 6);
}
