/*
** EPITECH PROJECT, 2018
** src/check
** File description:
** don't forget to free at the end
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

static void touche_opt_one(my_game_t *game, opt_t *opt)
{
    if (sfClock_getElapsedTime(game->clock).microseconds >=
 game->time_fg + 128000) {
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            (move_forward(game, 1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeyS))
            (move_forward(game, -1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeyD))
            (move_right(game, 1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            (move_right(game, -1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeySpace) && opt->ctrl[1] == 0)
            (beat(game)) ? game->my_turn = 0 : 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) && opt->ctrl[1] == 1)
            (beat(game)) ? game->my_turn = 0 : 0;
        game->time_fg = sfClock_getElapsedTime(game->clock).microseconds;
    }
}

static void touche_opt_two(my_game_t *game, opt_t *opt)
{
    if (sfClock_getElapsedTime(game->clock).microseconds >=
 game->time_fg + 128000) {
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            (move_forward(game, 1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            (move_forward(game, -1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            (move_right(game, 1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            (move_right(game, -1)) ? game->my_turn = 0 : 0;
        if (sfKeyboard_isKeyPressed(sfKeySpace) && opt->ctrl[1] == 0)
            (beat(game)) ? game->my_turn = 0 : 0;
        if (sfMouse_isButtonPressed(sfMouseLeft) && opt->ctrl[1] == 1)
            (beat(game)) ? game->my_turn = 0 : 0;
        game->time_fg = sfClock_getElapsedTime(game->clock).microseconds;
    }
}

void    movement_input(my_game_t *game, opt_t *opt)
{
    if (opt->ctrl[0] == 0)
        touche_opt_one(game, opt);
    if (opt->ctrl[0] == 1)
        touche_opt_two(game, opt);
}

void    check(my_game_t *game, opt_t *opt)
{
    while (sfRenderWindow_pollEvent(game->win->window, &(game->win->event))) {
        if (((game->win->event).type == sfEvtClosed) ||
sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->win->window);
        if (game->my_turn)
            movement_input(game, opt);
        if (game->in_game == 1 && game->win->event.type == sfEvtMouseMoved) {
            rotate_up(game, (game->win->event.mouseMove.y - game->win->mouse.y)
* game->win->ang_per_pixel.y * 10);
            rotate_right(game, (game->win->event.mouseMove.x -
game->win->mouse.x) * game->win->ang_per_pixel.x * 15);
            if (game->win->event.mouseMove.x - game->win->mouse.x != 0 &&
game->win->event.mouseMove.y - game->win->mouse.y != 0)
                sfMouse_setPositionRenderWindow(game->win->mouse,
game->win->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyB))
            printf("x= %f, y= %f, z= %f\n",
game->camera->move.x, game->camera->move.y, game->camera->move.z);
    }
}
        /*if (sfKeyboard_isKeyPressed(sfKeyJ))
            rotate_up(game, 1);
        if (sfKeyboard_isKeyPressed(sfKeyU))
            rotate_up(game, -1);
        if (sfKeyboard_isKeyPressed(sfKeyK))
            rotate_right(game, 1);
        if (sfKeyboard_isKeyPressed(sfKeyI))
            rotate_right(game, -1);
        if (sfKeyboard_isKeyPressed(sfKeyL))
            rotate_camera(game, 0, 0, 1);
        if (sfKeyboard_isKeyPressed(sfKeyO))
            rotate_camera(game, 0, 0, -1);
            */
