/*
** EPITECH PROJECT, 2018
** src/init
** File description:
** man man
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

void            delete_framebuff(my_framebuff_t *framebuff)
{
    free(framebuff->pixels);
    free(framebuff);
}

my_framebuff_t  *my_framebuff_create(int width, int height)
{
    my_framebuff_t      *buff;

    if ((buff = malloc(sizeof(my_framebuff_t))) == NULL)
        return (NULL);
    if ((buff->pixels = malloc(sizeof(sfUint8) * width * height * 4)) == NULL) {
        free (buff);
        return (NULL);
    }
    buff->width = width;
    buff->height = height;
    return (buff);
}

my_window_t     *set_window(my_window_t *win)
{
    win->view = sfView_createFromRect((sfFloatRect){0, 0, WM, HM});
    win->texture = sfTexture_create(WM, HM);
    win->sprite = sfSprite_create();
    win->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "my_rpg",
sfFullscreen, NULL);
    sfRenderWindow_setView(win->window, win->view);
    sfSprite_setTexture(win->sprite, win->texture, sfTrue);
    sfTexture_setSmooth(win->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    if ((win->framebuff = my_framebuff_create(WM, HM)) == NULL)
        return (NULL);
    win->z_buff = malloc(sizeof(double) * WM * HM);
    win->t_buff = malloc(sizeof(triangle_t*) * WM * HM);
    win->mouse.x = WM / 2;
    win->mouse.y = HM / 2;
    sfMouse_setPositionRenderWindow(win->mouse, win->window);
    win->ang_per_pixel.x = M_PI / 2 / WM;
    win->ang_per_pixel.y = M_PI / 2 / HM;
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    return (win);
}

void            set_map(map_t **map)
{
    if (!(*map = malloc(sizeof(map_t)))) {
        *map = NULL;
        return ;
    }
    (*map)->roll_fg = 0;
    (*map)->yaw_fg = 0;
    (*map)->pitch_fg = 0;
    (*map)->roll = 0;
    (*map)->yaw = 0;
    (*map)->pitch = 0;
    (*map)->update = 1;
    (*map)->move_point_x = 0;
    (*map)->move_point_y = 0;
    (*map)->move_point_z = 0;
    (*map)->enlargement = 1;
    (*map)->lum = 0;
    (*map)->ptr_tri = NULL;
}

my_game_t        *set_game(void)
{
    my_game_t    *game = malloc(sizeof(my_game_t));

    if (!game || !(game->win = malloc(sizeof(my_window_t))) ||
!(game->win = set_window(game->win))) {
        (game->win) ? free(game->win) : 0;
        (game) ? free(game) : 0;
        return (NULL);
    }
    game->in_game = 1;
    set_map(&(game->map));
    if (!game->map) {
        (game->win) ? free(game->win) : 0;
        (game) ? free(game) : 0;
        return (NULL);
    }
    if (!init_all_3d(game))
        return (NULL);
    if (!init_game(game))
        return (NULL);
    sfView_zoom(game->win->view, 0.25);
    return (game);
}
