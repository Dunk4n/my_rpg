/*
** EPITECH PROJECT, 2018
** src/update
** File description:
** you're a bad developer
*/

#include "world.h"
#include "my.h"

extern const char *dialog[];
extern const char *name[];

static void update_stat(my_game_t *game)
{
    square(game->win->framebuff, (sfVector2f){78, 202},
(sfVector2i){game->player->vie, 12}, sfRed);
    square(game->win->framebuff, (sfVector2f){100, 202},
(sfVector2i){game->player->stamina, 12}, sfGreen);
    square(game->win->framebuff, (sfVector2f){122, 202},
(sfVector2i){game->player->mana, 12}, sfBlue);
    square(game->win->framebuff, (sfVector2f){148, 225},
(sfVector2i){12, game->player->exp}, sfMagenta);
    sfTexture_updateFromPixels(game->win->texture, game->win->framebuff->pixels,
WM, HM, 0, 0);
}

void    clear_buff(my_framebuff_t *buff, double *z_buff)
{
    int i = 0;
    int len = WM * HM;

    while (i < len) {
        z_buff[i] = -1;
        buff->pixels[i * 4] = 0;
        buff->pixels[i * 4 + 1] = 0;
        buff->pixels[i * 4 + 2] = 0;
        buff->pixels[i * 4 + 3] = 0;
        i++;
    }
}

void    update(my_game_t *game, play_t *play, png_t *png)
{
    sfRenderWindow_clear(game->win->window, sfBlack);
    update_stat(game);
    sfRenderWindow_drawSprite(game->win->window, game->win->sprite, NULL);
    users_interaction(play, game);
    action_game(play, game);
    if (game->player->exp >= 230) {
        game->player->lvl++;
        game->player->exp = 0;
    }
    if (game->value_talk == 0)
        dialogue(&png[game->value_name], game->win->window, "", "");
    else
        dialogue(&png[game->value_name], game->win->window,
name[game->value_name], dialog[game->value_talk]);
}
