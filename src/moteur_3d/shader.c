/*
** EPITECH PROJECT, 2018
** src/moteur_3d/shader
** File description:
** well, real programmers use ed
*/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "world.h"

float   get_intencity_of_face(sfVector3f a, sfVector3f b, sfVector3f c)
{
    float       res;
    sfVector3f  normal = normal_vec(a, b, c);
    double      norme = sqrt(normal.x * normal.x + normal.y *
normal.y + normal.z * normal.z);

    res = (norme) ? normal.z / norme : 0;
    if (res < 0)
        res *= -1;
    res += 0.2;
    if (res > 0.6)
        res = 0.6;
    return (res);
}
