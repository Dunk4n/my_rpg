/*
** EPITECH PROJECT, 2019
** gameplay
** File description:
** game and interface for play
*/

#include "my.h"

static void action_hub(play_t *play)
{
    static size_t button = 0;

    if (button == 0 && play->event.type == sfEvtKeyPressed) {
        button = 1;
        (play->event.key.code == sfKeyNum1) ? play->rect.width = 300, sfSprite_setTextureRect(play->s_fist, play->rect) : 0;
    } else if (play->event.type == sfEvtKeyReleased)
        button = 0;
    play->rect.width = 150;
    sfSprite_setTextureRect(play->s_fist, play->rect);
    sfSprite_setTextureRect(play->s_magie, play->rect);
    sfSprite_setTextureRect(play->s_bag, play->rect);
    sfSprite_setTextureRect(play->s_beer, play->rect);
    sfSprite_setTextureRect(play->s_book, play->rect);
}

static void display_hud(play_t *play, my_game_t *game)
{
    sfSprite_setTexture(play->s_hud, play->t_hud, sfTrue);
    sfSprite_setTexture(play->s_fist, play->t_fist, sfTrue);
    sfSprite_setTexture(play->s_magie, play->t_magie, sfTrue);
    sfSprite_setTexture(play->s_bag, play->t_bag, sfTrue);
    sfSprite_setTexture(play->s_beer, play->t_beer, sfTrue);
    sfSprite_setTexture(play->s_book, play->t_book, sfTrue);
    sfSprite_setPosition(play->s_fist, (sfVector2f){585, 935});
    sfSprite_setPosition(play->s_magie, (sfVector2f){780, 935});
    sfSprite_setPosition(play->s_bag, (sfVector2f){952, 935});
    sfSprite_setPosition(play->s_beer, (sfVector2f){1145, 935});
    sfSprite_setPosition(play->s_book, (sfVector2f){1345, 935});
    action_hub(play);
    sfRenderWindow_drawSprite(game->win->window, play->s_hud, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_fist, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_magie, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_bag, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_beer, NULL);
    sfRenderWindow_drawSprite(game->win->window, play->s_book, NULL);
}

void users_interaction(play_t *play, my_game_t *game)
{
    display_hud(play, game);
}
