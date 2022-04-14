/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** setup_map.c
*/

#include "my_world.h"

w_colors_t setup_color(void)
{
    w_colors_t colors;
    colors.high = sfColor_fromRGB(rdm() * 255, rdm() * 255, rdm() * 255);
    colors.low = sfColor_fromRGB(rdm() * 255, rdm() * 255, rdm() * 255);
    colors.max = 200 + 200 * rdm();
    return colors;
}

sin_t *setup_sinlist(int n)
{
    sin_t *sin = malloc((n + 1) * sizeof(sin_t));
    int i;
    float off;
    float peak = 10 + 10 * rdm();
    float period = 15 + 30 * rdm();
    for (i = 0; i < n; i++) {
        off = rdm() * 100;
        sin[i] = (sin_t){off, peak, period};
        peak /= 1 + 2 * rdm();
        period /= 1 + 2 * rdm();
    }
    sin[i] = (sin_t){0, 0, 0};
    return sin;
}

world_t setup_world(void)
{
    world_t world;
    world.pos = (sfVector2f){WINWIDTH / 2, WINHEIGHT / 2};
    world.angle = (sfVector2f){15, 15};
    world.size = 1000;
    world.dim = (sfVector2i){200, 200};
    world.colors = setup_color();
    world.rota = 0;
    return world;
}

button_t setup_button(sfVector2f pos, sfVector2f size, char *file)
{
    button_t button;
    sfVector2u textsize;
    button.texture = sfTexture_createFromFile(file, NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfFalse);
    button.pos = pos;
    textsize = sfTexture_getSize(button.texture);
    button.scale = size;
    button.size = (sfVector2f){size.x * textsize.x, size.y * textsize.y};
    sfSprite_setOrigin(button.sprite, (sfVector2f)\
    {button.size.x / 2, button.size.y / 2});
    sfSprite_setScale(button.sprite, size);
    sfSprite_setPosition(button.sprite, pos);
    return button;
}

double **setup_map(int width, int height)
{
    double **map = malloc((height + 1) * sizeof(double *));
    int y;
    int x;
    sin_t *x_sin = setup_sinlist(5);
    sin_t *y_sin = setup_sinlist(5);
    for (y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(double));
        for (x = 0; x < width; x++)
            map[y][x] = calc_sinlist(x_sin, y_sin, x, y)\
            + (rdm() - rdm()) / 2;
    }
    free(x_sin);
    free(y_sin);
    map[y] = NULL;
    return map;
}
