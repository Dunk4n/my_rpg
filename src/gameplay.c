/*
** EPITECH PROJECT, 2019
** gameplay
** File description:
** game and interface for play
*/

#include "my.h"

static void scale_sprite(play_t *play)
{
    sfSprite_setScale(play->s_hud, (sfVector2f){480.0 / 1920.0,
270.0 / 1080.0});
    sfSprite_setScale(play->s_inv, (sfVector2f) {480.0 / 1920.0 ,
270.0 / 1080.0});
    sfSprite_setScale(play->s_magie, (sfVector2f){52.5 / 150.0, 85.0 / 280.0});
    sfSprite_setScale(play->s_bag, (sfVector2f){45.5 / 150.0, 75.0 / 280.0});
    sfSprite_setScale(play->s_book, (sfVector2f){52.5 / 150.0, 85.0 / 280.0});
    sfSprite_setScale(play->s_fist, (sfVector2f){52.5 / 150.0, 85.0 / 280.0});
    sfSprite_setScale(play->s_beer, (sfVector2f){52.5 / 150.0, 85.0 / 280.0});
    sfSprite_setTexture(play->s_hud, play->t_hud, sfTrue);
    sfSprite_setTexture(play->s_inv, play->t_inv, sfTrue);
    sfSprite_setTexture(play->s_fist, play->t_fist, sfTrue);
    sfSprite_setTexture(play->s_magie, play->t_magie, sfTrue);
    sfSprite_setTexture(play->s_bag, play->t_bag, sfTrue);
    sfSprite_setTexture(play->s_beer, play->t_beer, sfTrue);
    sfSprite_setTexture(play->s_book, play->t_book, sfTrue);
}

static void display_hud(play_t *play, my_game_t *game)
{
    scale_sprite(play);
    sfSprite_setPosition(play->s_fist, (sfVector2f){141, 230});
    sfSprite_setPosition(play->s_magie, (sfVector2f){186, 230});
    sfSprite_setPosition(play->s_bag, (sfVector2f){236, 232});
    sfSprite_setPosition(play->s_beer, (sfVector2f){281, 230});
    sfSprite_setPosition(play->s_book, (sfVector2f){328, 230});
    square(game->win->framebuff, (sfVector2f){100, 230},
(sfVector2i){20, 10}, sfRed);
    square(game->win->framebuff, (sfVector2f){110, 230},
(sfVector2i){20, 10}, sfGreen);
    square(game->win->framebuff, (sfVector2f){120, 230},
(sfVector2i){20, 10}, sfBlue);
}

void users_interaction(play_t *play, my_game_t *game)
{
    sfRenderWindow_drawSprite(game->win->window, play->s_hud, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_fist, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_magie, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_bag, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_beer, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_book, NULL);
    display_hud(play, game);
}