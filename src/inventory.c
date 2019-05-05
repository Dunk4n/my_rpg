/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory management
*/

#include "my.h"

static  void use_item(play_t *play, my_game_t *game, sfVector2i mouse)
{
    if (mouse.x >= 1715 && mouse.x <= 1765 && mouse.y >= 185 &&
        mouse.y <= 210 && sfMouse_isButtonPressed(sfMouseLeft)) {
        play->items[0].active = false;
        game->player->vie += play->items[0].life;
        game->player->stamina += play->items[0].stamina;
        game->player->mana += play->items[0].mana;
    }
    if (mouse.x >= 1775 && mouse.x <= 1825 && mouse.y >= 185 &&
        mouse.y <= 210 && sfMouse_isButtonPressed(sfMouseLeft)) {
        play->items[1].active = false;
        game->player->vie += play->items[1].life;
        game->player->stamina += play->items[1].stamina;
    }
    if (mouse.x >= 1835 && mouse.x <= 1885 && mouse.y >= 185 &&
        mouse.y <= 210 && sfMouse_isButtonPressed(sfMouseLeft)) {
        play->items[2].active = false;
        game->player->vie += play->items[2].life;
        game->player->stamina += play->items[2].stamina;
        game->player->mana += play->items[2].mana;
    }
}

static void show_items(play_t *play, my_game_t *game, sfVector2i mouse)
{
    sfSprite_setPosition(play->items[0].sprite, (sfVector2f) 
    {1715.0 / 4 , 185.0 / 4});
    sfSprite_setPosition(play->items[1].sprite, (sfVector2f)
    {1775.0 / 4 , 185.0 / 4});
    sfSprite_setPosition(play->items[2].sprite, (sfVector2f)
    {1835.0 / 4 , 185.0 / 4});
    sfSprite_setScale(play->items[0].sprite, (sfVector2f) {10.0 / 20 , 10.0 / 20});
    sfSprite_setScale(play->items[1].sprite, (sfVector2f) {10.0 / 20 , 10.0 / 20});
    sfSprite_setScale(play->items[2].sprite, (sfVector2f) {10.0 / 20 , 10.0 / 20});
    (play->items[0].active) ? sfRenderWindow_drawSprite(game->win->window, play->items[0].sprite, NULL) : 0;
    (play->items[1].active) ? sfRenderWindow_drawSprite(game->win->window, play->items[1].sprite, NULL) : 0;
    (play->items[2].active) ? sfRenderWindow_drawSprite(game->win->window, play->items[2].sprite, NULL) : 0;
    use_item(play, game, mouse);
}

static void inv_loop(play_t *play, my_game_t *game)
{
    sfVector2i mouse;

    sfRenderWindow_setMouseCursorVisible(game->win->window, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        mouse = sfMouse_getPositionRenderWindow(game->win->window);
        sfRenderWindow_drawSprite(game->win->window, play->s_inv, NULL);
        show_items(play, game, mouse);
        if (mouse.x >= 1370 && mouse.x <= 1580 && mouse.y >= 80 &&
            mouse.y <= 210 && sfMouse_isButtonPressed(sfMouseLeft)) {
            play->inventory = false;
            break;
        }
        sfRenderWindow_display(game->win->window);
    }
    sfRenderWindow_setMouseCursorVisible(game->win->window, sfFalse);
}

void inventory(play_t *play, my_game_t *game)
{
    play->inventory = !play->inventory;
    if (play->inventory == false)
        return;
    inv_loop(play, game);
}
