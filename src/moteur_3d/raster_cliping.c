/*
** EPITECH PROJECT, 2018
** src/moteur_3d/raster_cliping
** File description:
** M-x doctor
*/

#include "world.h"

void    raster_cliping_x(arg_interpolation_t *arg, double *tab, int *x12)
{
    tab[3] = 1 - (arg->xa - x12[0]);
    tab[4] = arg->iza + tab[3] * arg->dizdx;
    tab[5] = arg->uiza + tab[3] * arg->duizdx;
    tab[6] = arg->viza + tab[3] * arg->dvizdx;
    if (x12[0] < 0) {
        tab[4] += arg->dizdx * -x12[0];
        tab[5] += arg->duizdx * -x12[0];
        tab[6] += arg->dvizdx * -x12[0];
        x12[0] = 0;
    }
    (x12[1] > WM) ? x12[1] = WM : 0;
}

void    raster_cliping_y(arg_interpolation_t *arg)
{
    int tmp = (arg->y2 < 0) ? arg->y2 - arg->y1 : -arg->y1;

    arg->xa += arg->dxdya * tmp;
    arg->xb += arg->dxdyb * tmp;
    arg->iza += arg->dizdya * tmp;
    arg->uiza += arg->duizdya * tmp;
    arg->viza += arg->dvizdya * tmp;
    arg->y1 = 0;
}
