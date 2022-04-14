/*
** EPITECH PROJECT, 2021
** world
** File description:
** colors.c
*/

#include "my_world.h"

double rdm(void)
{
    return (double)rand() / (double)RAND_MAX;
}

sfColor build_color(w_colors_t colors, double vh)
{
    double max = colors.max;
    sfUint8 red = colors.low.r * (vh / max) + colors.high.r * (1 - vh / max);
    sfUint8 green = colors.low.g * (vh / max) + colors.high.g * (1 - vh / max);
    sfUint8 blue = colors.low.b * (vh / max) + colors.high.b * (1 - vh / max);
    return sfColor_fromRGB(red, green, blue);
}

double calc_sinlist(sin_t *x_list, sin_t *y_list, float x, float y)
{
    int i;
    double result = 0;
    for (i = 0; x_list[i].peak != 0; i++)
        result += sin(x_list[i].off + x / x_list[i].period) * x_list[i].peak;
    for (i = 0; y_list[i].peak != 0; i++)
        result += sin(y_list[i].off + y / y_list[i].period) * y_list[i].peak;
    return result;
}

void destroy_projmap(sfVector2i *dim, sfVector2f **projmap)
{
    int i;
    for (i = 0; i < dim->y; i++)
        free(projmap[i]);
    free(projmap);
}

void play_music(winbase_t *wb)
{
    wb->music = sfMusic_createFromFile("assets/my_music.ogg");
    sfMusic_setLoop(wb->music, true);
    sfMusic_play(wb->music);
}
