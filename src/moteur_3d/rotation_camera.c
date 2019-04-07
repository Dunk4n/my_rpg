/*
** EPITECH PROJECT, 2018
** src/moteur_3d/rotation_camera
** File description:
** hello world?
*/

#include <math.h>
#include "world.h"

void    round_roll_yaw_pitch(camera_t *camera,
float roll, float yaw, float pitch)
{
    camera->roll += roll;
    camera->yaw += yaw;
    camera->pitch += pitch;
    if (camera->roll >= 360 || camera->roll < 0)
        camera->roll += (camera->roll < 0) ? 360 : -360;
    if (camera->yaw >= 360 || camera->yaw < 0)
        camera->yaw += (camera->yaw < 0) ? 360 : -360;
    if (camera->pitch >= 360 || camera->pitch < 0)
        camera->pitch += (camera->pitch < 0) ? 360 : -360;
}

void    mul_matrix(float *result, float *mat1, float *mat2)
{
    int i = 0;
    float   res[9];

    res[0] = mat1[0] * mat2[0] + mat1[1] * mat2[3] + mat1[2] * mat2[6];
    res[1] = mat1[0] * mat2[1] + mat1[1] * mat2[4] + mat1[2] * mat2[7];
    res[2] = mat1[0] * mat2[2] + mat1[1] * mat2[5] + mat1[2] * mat2[8];
    res[3] = mat1[3] * mat2[0] + mat1[4] * mat2[3] + mat1[5] * mat2[6];
    res[4] = mat1[3] * mat2[1] + mat1[4] * mat2[4] + mat1[5] * mat2[7];
    res[5] = mat1[3] * mat2[2] + mat1[4] * mat2[5] + mat1[5] * mat2[8];
    res[6] = mat1[6] * mat2[0] + mat1[7] * mat2[3] + mat1[8] * mat2[6];
    res[7] = mat1[6] * mat2[1] + mat1[7] * mat2[4] + mat1[8] * mat2[7];
    res[8] = mat1[6] * mat2[2] + mat1[7] * mat2[5] + mat1[8] * mat2[8];
    while (i < 9) {
        result[i] = res[i];
        i++;
    }
}

sfVector3f      put_rotate_on_point(float *rot, sfVector3f point)
{
    sfVector3f res;

    res.x = point.x * rot[0] + point.y * rot[1] + point.z * rot[2];
    res.y = point.x * rot[3] + point.y * rot[4] + point.z * rot[5];
    res.z = point.x * rot[6] + point.y * rot[7] + point.z * rot[8];
    return (res);
}

void    inv_matrix(float *res, float *rot)
{
    int i = 0;
    int j;

    while (i < 3) {
        j = 0;
        while (j < 3) {
            res[j * 3 + i] = rot[i * 3 + j];
            j++;
        }
        i++;
    }
}

void    put_rotate_camera_point(my_game_t *game, float *rot)
{
    float res[9] = {0};

    inv_matrix(res, rot);
    game->camera->point[1] = put_rotate_on_point(res, (sfVector3f){1, 0, 0});
    game->camera->point[2] = put_rotate_on_point(res, (sfVector3f){0, 1, 0});
}

void    rotate_camera(my_game_t *game, float roll, float yaw, float pitch)
{
    float   sr = sin(roll * M_PI / 180);
    float   cr = cos(roll * M_PI / 180);
    float   sy = sin(yaw * M_PI / 180);
    float   cy = cos(yaw * M_PI / 180);
    float   sp = sin(pitch * M_PI / 180);
    float   cp = cos(pitch * M_PI / 180);
    float   x_rotation[9] = {1, 0, 0, 0, cr, sr, 0, -sr, cr};
    float   y_rotation[9] = {cy, 0, -sy, 0, 1, 0, sy, 0, cy};
    float   z_rotation[9] = {cp, sp, 0, -sp, cp, 0, 0, 0, 1};

    if (!roll && !yaw && !pitch)
        return ;
    mul_matrix(game->camera->rot, game->camera->rot, x_rotation);
    mul_matrix(game->camera->rot, game->camera->rot, y_rotation);
    mul_matrix(game->camera->rot, game->camera->rot, z_rotation);
    put_rotate_camera_point(game, game->camera->rot);
    round_roll_yaw_pitch(game->camera, roll, yaw, pitch);
}
