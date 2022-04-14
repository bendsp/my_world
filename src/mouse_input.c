/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** mouse_input.c
*/

#include "my_world.h"

float gauss(winbase_t *wb, float xdist, float ydist)
{
    float std_dev = wb->pen_size;
    float dist = sqrt(pow(xdist, 2) + pow(ydist, 2));
    float a = 1 / (std_dev * 2.5);
    float b = pow(2.7, 0 - (pow(dist, 2) / (2 * pow(std_dev, 2))));
    return wb->pen_strenght * a * b * 60 / WINFPS;
}

void adjust_points(winbase_t *wb, sfVector2i mouse_pos, float coef)
{
    int y = wb->coord.y;
    int x = wb->coord.x;
    wb->height_map[y][x] += coef *\
    gauss(wb, mouse_pos.x - x, mouse_pos.y - y);
}

sfVector2i scale_mouse(sfVector2i mouse_pos, int factor)
{
    sfVector2i scaledpoint;
    scaledpoint.x = mouse_pos.x / factor;
    scaledpoint.y = mouse_pos.y / factor;
    return scaledpoint;
}

void check_points(winbase_t *wb, sfVector2i mouse_pos, int factor)
{
    int height = wb->world.dim.y;
    int width = wb->world.dim.x;
    int left_button = sfMouse_isButtonPressed(sfMouseLeft);
    int right_button = sfMouse_isButtonPressed(sfMouseRight);
    mouse_pos = scale_mouse(mouse_pos, factor);
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            wb->coord.y = y;
            wb->coord.x = x;
            adjust_points(wb, mouse_pos, left_button - right_button);
        }
}

void handle_mouse(winbase_t *wb, int factor)
{
    sfVector2i mouse_pos;
    sfBool right_button;
    sfBool left_button;
    mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    left_button = sfMouse_isButtonPressed(sfMouseLeft);
    right_button = sfMouse_isButtonPressed(sfMouseRight);
    if (left_button || right_button)
        check_points(wb, mouse_pos, factor);
}
