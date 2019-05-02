/*
** EPITECH PROJECT, 2018
** ../particle_water
** File description:
** csfml is the best thing ever
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"
#include "struct.h"

void    reset_particle(particle_t *particle, sfVector2i pos)
{
    float       angl;
    float       speed;

    angl = rand() % 60 + 60;
    speed = (10.0 + (float)(rand() % 30)) / 10.0;
    particle->life = 25 + rand() % 50;
    particle->size = 5 + rand() % 10;
    particle->pos.x = pos.x;
    particle->pos.y = pos.y;
    particle->speed.x = speed * cos(angl * M_PI / 180.0);
    particle->speed.y = -speed * sin(angl * M_PI / 180.0);
    particle->color = (sfColor){150 + 100 * particle->life / 75, 20, 20, 255};
}

void    display_particle(my_framebuff_t *buff, particle_t *particle,
int nb_particle, sfVector2i pos)
{
    size_t i = 0;

    while (i < (size_t)nb_particle) {
        if (particle[i].life <= 0) {
            reset_particle(&(particle[i]), pos);
            i++;
            continue;
        }
        draw_simple_circle(buff, particle[i].pos, particle[i].size,
particle[i].color);
        particle[i].pos.x += particle[i].speed.x;
        particle[i].pos.y += particle[i].speed.y;
        particle[i].speed.y += 0.5;
        particle[i].life -= 1;
        (particle[i].color.b < 100) ? particle[i].color.b += 2 : 0;
        (particle[i].color.g < 100) ? particle[i].color.g += 2 : 0;
        i++;
    }
}
