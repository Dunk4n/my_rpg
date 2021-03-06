/*
** EPITECH PROJECT, 2018
** world
** File description:
** try not to segfault, good luck :)
*/

#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include "struct.h"

const char      *img_name[3];
const char      *img_button[13];
const sfColor   color[11];
const char      char_obj[3];
const char      *name[21];
const char      type_enemy[4];
const int       pnj[5];

typedef struct  arg_interpolation_s
{
    double iza;
    double uiza;
    double viza;
    double dizdx;
    double duizdx;
    double dvizdx;
    double xa;
    double xb;
    double dxdya;
    double dxdyb;
    double dizdya;
    double duizdya;
    double dvizdya;
    int y1;
    int y2;
    int y1i;
    int y2i;
    int y3i;
}               arg_interpolation_t;

typedef struct  vector4f_s
{
    double x;
    double y;
    double z;
    double t;
    double bcy;
    double cbx;
    double cay;
    double acx;
    double div;
    sfVector3f c_point;
    sfVector3f a_uv;
    sfVector3f b_uv;
    sfVector3f c_uv;
    sfVector3f sz;
    sfVector3f su;
    sfVector3f sv;
}             vector4f_t;

typedef struct  my_framebuff_s
{
    int         width;
    int         height;
    sfUint8     *pixels;
}               my_framebuff_t;

typedef struct  obj_s obj_t;

typedef struct  triangle_s
{
    obj_t       *obj;
    sfVector3f  *point_3d[3];
    sfVector3f  *point_camera[3];
    sfVector3f  *point_2d[3];
    sfVector3f  *point_tx[3];
    sfColor     color;
    int         texture;
    int         indice_point[3];
    int         indice_texture[3];
}               triangle_t;

typedef struct  my_window_s
{
    sfRenderWindow      *window;
    sfView              *view;
    sfEvent             event;
    sfTexture           *texture;
    sfSprite            *sprite;
    my_framebuff_t      *framebuff;
    double              *z_buff;
    triangle_t          **t_buff;
    sfVector2u          pos;
    sfVector2i          mouse;
    sfVector2f          ang_per_pixel;
    sfContextSettings   *context_set;
}               my_window_t;

typedef struct  obj_s
{
    int         nb_point;
    int         nb_tr;
    int         nb_tx;
    sfVector3f  *point_3d;
    sfVector3f  *point_camera;
    sfVector3f  *point_2d;
    sfVector3f  *point_tx;
    triangle_t  *triangle;
}               obj_t;

typedef struct  camera_s
{
    sfVector3f  move;
    sfVector3f  point[3];
    float       rot[9];
    float       roll;
    float       yaw;
    float       pitch;
    float       roll_cam;
}               camera_t;

typedef struct  player_s
{
    int         vie;
    int         stamina;
    int         mana;
    int         exp;
    int         lvl;
    int         alcool;
    int         value_hit;
}               player_t;

typedef struct  enemy_s
{
    int         vie;
    int         degat;
    int         type;
    int         pnj;
    int         dialog;
    size_t      nb_dialog;
    int         name;
    float       yaw;
    sfVector3f  pos;
    obj_t       *obj;
}               enemy_t;

typedef struct  map_s
{
    float       roll_fg;
    float       yaw_fg;
    float       pitch_fg;
    float       roll;
    float       yaw;
    float       pitch;
    int         update;
    double      move_point_x;
    double      move_point_y;
    double      move_point_z;
    double      enlargement;
    float       lum;
    triangle_t  *ptr_tri;
    obj_t       **obj;
}               map_t;

typedef struct  room_s
{
    obj_t       **fix_obj;
    enemy_t     *enemy;
    char        ***room;
    int         nb_enemy;
    int         x_max;
    int         y_max;
    int         z_max;
    int         nb_obj;
}               room_t;

typedef struct  my_game_s
{
    room_t          **room;
    my_window_t     *win;
    map_t           *map;
    sfImage         **img;
    player_t        *player;
    camera_t        *camera;
    sfClock         *clock;
    sfInt64         time_fg;
    sfInt64         time_enemy_fg;
    int             obj;
    int             nb_room;
    int             actual_room;
    int             nb_img;
    int             nb_col_max;
    int             in_game;
    int             my_turn;
    int             value_talk;
    int             value_name;
    int             fg_color;
    char            name[11];
    char            last_input;
    int             nb_name;
    sfText          *name_text;
    sfText          *name_lvl;
    sfFont          *name_font;
}               my_game_t;

int     window(void);
my_framebuff_t  *my_framebuff_create(int width, int height);
int     init_all_3d(my_game_t *game);
void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color);
void    put_pixel3d(my_game_t *game, sfVector3f cord, sfColor color);
void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color);
void    clear_buff(my_framebuff_t *buff, double *z_buff);
void    clear_z_buff(double *z_buff);
void    clear_t_buff(triangle_t **t_buff);
void    transform_move(my_game_t *game, obj_t *obj);
void    transform_lower(my_game_t *game, obj_t *obj);
void    rotation(obj_t *obj, float yaw);
void    display(my_game_t *game, obj_t *obj);
my_game_t        *set_game(void);
void    update(my_game_t *game, play_t *play, png_t *png);
void    check(my_game_t *game, opt_t *opt, play_t *play);
void horz_line(my_game_t *game, sfVector3f pos, vector4f_t nor, sfColor color);
void    draw_triangle(my_game_t *game, sfVector3f *pos, sfColor color);
void    draw_poly(my_game_t *game, triangle_t *tri);
void    draw_poly_interpolation(my_game_t *game, triangle_t *tri,
arg_interpolation_t *arg);
void    init_draw_poly(my_game_t *game, triangle_t *tri, double *tab);
double  my_getfloat(char *str);
obj_t   *init_obj(void);
int     get_nbr_arg(obj_t *obj, char *name);
int     set_obj(my_game_t *game, obj_t *obj, char *name);
void    set_triangle_tx(my_game_t *game, obj_t *obj, char **array, int nb);
void    set_point(my_game_t *game, obj_t *obj, char **array);
void    set_point_tx(my_game_t *game, obj_t *obj, char **array);
void    free_array(char **array);
int     cond_inter(double *tab, int y1i, int y2i, int y3i);
void    init_arg(arg_interpolation_t *arg, double *tab);
int     calc_side(double *tab);
void    set_value_game(my_game_t *game);
obj_t   *open_file_obj(my_game_t *game, const char *name);
void    set_img(my_game_t *game);
void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color);
void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color);
int     charge_obj(my_game_t *game);
sfVector3f      normal_vec(sfVector3f a, sfVector3f b, sfVector3f c);
int     move_forward(my_game_t *game, int dir);
int     move_right(my_game_t *game, int dir);
void    rotation_roll(my_game_t *game, float coef);
void    rotation_yaw(my_game_t *game, float coef);
void    rotation_pitch(my_game_t *game, float coef);
void    rotate_camera(my_game_t *game, float roll, float yaw, float pitch);
int     init_game(my_game_t *game);
room_t  **charge_room(my_game_t *game);
void    transform_camera(my_game_t *game, room_t *room);
void    to_2d(my_game_t *game, room_t *room);
void    display_room(my_game_t *game);
void    movement(my_game_t *game, double x, double y, double z);
void    copy_obj(obj_t **obj, obj_t *to_copy);
void    move_obj_to(obj_t *obj, int y, int z, int x);
void    set_all_obj_in_room(my_game_t *game, room_t *room);
int     set_obj_in_room(my_game_t *game, room_t *room);
int     set_tab_and_obj(my_game_t *game, room_t *room, int fd);
int     get_nb_of_obj(room_t *room);
obj_t   *get_obj_of_char(my_game_t *game, char c);
void    copy_adresse_face(obj_t *obj, int i);
void    copy_face(obj_t *obj, obj_t *to_copy);
void    copy_info_of_obj(obj_t *obj, obj_t *to_copy);
int     set_each_line(room_t *room, char **tab, int fd);
void    rotate_camera_up(my_game_t *game, float roll);
sfVector3f      put_rotate_on_point(float *rot, sfVector3f point);
void    rotate_up(my_game_t *game, float weight);
void    rotate_right(my_game_t *game, float weight);
int     on_ground(my_game_t *game);
int     init_enemy(my_game_t *game);
void    to_2d_enemy(room_t *room);
float   round_angle(float angle);
void    enemy_turn(my_game_t *game);
int     beat(my_game_t *game, play_t *play);
int     talk_pnj(my_game_t *game, enemy_t *cible);
size_t  nb_monster_in_room(room_t *room);
int     kill_all_monster(my_game_t *game, int nb_room, int nb);
int     vie_superior_of(my_game_t *game, int nb_room, int nb);
void    small_door(my_game_t *game, enemy_t *cible, int value,
sfVector3f new_pos);
void    big_door(my_game_t *game, enemy_t *cible, int value,
sfVector3f new_pos);
float   get_intencity_of_face(sfVector3f a, sfVector3f b, sfVector3f c);
void    put_rotate_camera_point(my_game_t *game, float *rot);
void    inv_matrix(float *res, float *rot);
void    raster_cliping_y(arg_interpolation_t *arg);
void    raster_cliping_x(arg_interpolation_t *arg, double *tab, int *x12);
void    make_particle(my_framebuff_t *buff, menu_t *menu);
void    display_particle(my_framebuff_t *buff, particle_t *particle,
int nb_particle, sfVector2i pos);
void    draw_simple_circle(my_framebuff_t *buff, sfVector2f pos, int size,
sfColor color);
void    clear_framebuff(my_framebuff_t *buff);

#define WM 480.0
//#define WM 1920.0
//1920  1280  960  480
#define HM 270.0
//#define HM 1080.0
//1080  720   540  270

#endif
