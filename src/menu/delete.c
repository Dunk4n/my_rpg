/*
** EPITECH PROJECT, 2019
** delete
** File description:
** clean for option
*/

#include "my.h"

void delete(opt_t *new_opt)
{
    sfSprite_destroy(new_opt->s_vol);
    sfSprite_destroy(new_opt->s_touch_one);
    sfSprite_destroy(new_opt->s_touch_two);
    sfSprite_destroy(new_opt->s_opt);
    sfSprite_destroy(new_opt->ss_clavier);
    sfSprite_destroy(new_opt->sf_clavier);
    sfTexture_destroy(new_opt->tf_clavier);
    sfTexture_destroy(new_opt->ts_clavier);
    sfTexture_destroy(new_opt->t_opt);
    sfTexture_destroy(new_opt->t_vol);
    sfTexture_destroy(new_opt->t_touch_one);
    sfTexture_destroy(new_opt->t_touch_two);
}
