/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory management
*/

#include "my.h"

static void show_items(my_game_t *game, item_t *items)
{
    sfSprite_setPosition((items[0]).sprite, (sfVector2f) 
    {1715.0 / 4 , 185.0 / 4});
    sfSprite_setPosition((items[1]).sprite, (sfVector2f)
    {1775.0 / 4 , 185.0 / 4});
    sfSprite_setPosition((items[2]).sprite, (sfVector2f)
    {1835.0 / 4 , 185.0 / 4});
    sfSprite_setScale((items[0]).sprite, (sfVector2f) {10.0 / 20 , 10.0 / 20});
    sfSprite_setScale((items[1]).sprite, (sfVector2f) {10.0 / 20 , 10.0 / 20});
    sfSprite_setScale((items[2]).sprite, (sfVector2f) {10.0 / 20 , 10.0 / 20});
    (play->items[0].active) ? sfRenderWindow_drawSprite(game->win->window, (items[0]).sprite, NULL) : 0;
    (play->items[0].active) ? sfRenderWindow_drawSprite(game->win->window, (items[1]).sprite, NULL) : 0;
    (play->items[0].active) ? sfRenderWindow_drawSprite(game->win->window, (items[2]).sprite, NULL) : 0;
}

static void inv_loop(play_t *play, my_game_t *game)
{
    sfVector2i mouse;

    sfRenderWindow_setMouseCursorVisible(game->win->window, sfTrue);
    while (sfRenderWindow_isOpen(game->win->window)) {
        mouse = sfMouse_getPositionRenderWindow(game->win->window);
        sfRenderWindow_drawSprite(game->win->window, play->s_inv, NULL);
<<<<<<< HEAD
        show_items(play, game, play->items);
        if (mouse.x >= 1370 && mouse.x <= 1580 && mouse.y >= 80 &&
            mouse.y <= 210 && sfMouse_isButtonPressed(sfMouseLeft)) {
=======
        show_items(game, play->items);
        if (mouse.x >= 1370 && mouse.x <= 1480 && mouse.y >= 80 &&
            mouse.y <= 160 && sfMouse_isButtonPressed(sfMouseLeft)) {
>>>>>>> 94cd0799c9d84eb197b1874eaf66c322240ac96c
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
<<<<<<< HEAD

=======
>>>>>>> 94cd0799c9d84eb197b1874eaf66c322240ac96c
    if (play->inventory == false)
        return;
    inv_loop(play, game);
}
