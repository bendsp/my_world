/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** editor.c
*/

#include "my_world.h"

sfVector2f scale_editor(int y, int x, int factor)
{
    sfVector2f scaledpoint;
    scaledpoint.y = y * factor;
    scaledpoint.x = x * factor;
    return scaledpoint;
}

void editor_x_lines(winbase_t *wb, int factor)
{
    sfVertexArray *vertex_array;
    sfVertex vertex;
    sfVector2f scaledpoint;
    int x;
    int y;
    sfColor color;
    double vh;
    for (y = 0; y < wb->world.dim.y; y++) {
        vertex_array = sfVertexArray_create();
        for (x = 0; x < wb->world.dim.x; x++) {
            scaledpoint = scale_editor(y, x, factor);
            vh = wb->height_map[y][x] * 10;
            color = build_color(wb->world.colors, vh);
            vertex = (sfVertex){.position = scaledpoint, .color = color};
            sfVertexArray_append(vertex_array, vertex);
        }
        sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
        sfRenderWindow_drawVertexArray(wb->window, vertex_array, NULL);
        sfVertexArray_destroy(vertex_array);
    }
}

void editor_y_lines(winbase_t *wb, int factor)
{
    sfVertexArray *vertex_array;
    sfVertex vertex;
    sfVector2f scaledpoint;
    int x;
    int y;
    sfColor color;
    double vh;
    for (x = 0; x < wb->world.dim.x; x++) {
        vertex_array = sfVertexArray_create();
        for (y = 0; y < wb->world.dim.y; y++) {
            scaledpoint = scale_editor(y, x, factor);
            vh = wb->height_map[y][x] * 10;
            color = build_color(wb->world.colors, vh);
            vertex = (sfVertex){.position = scaledpoint, .color = color};
            sfVertexArray_append(vertex_array, vertex);
        }
        sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
        sfRenderWindow_drawVertexArray(wb->window, vertex_array, NULL);
        sfVertexArray_destroy(vertex_array);
    }
}

sfCircleShape *create_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setOutlineColor(circle, sfWhite);
    return circle;
}

void editor(winbase_t *wb)
{
    int factor = 4;
    float rad = wb->pen_size * 5;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    char *pen_str = my_getstr(wb->pen_strenght);
    display_str(wb, "Pen Strength", (sfVector2f){820, 30}, 0.8);
    display_str(wb, pen_str, (sfVector2f){820, 70}, 0.8);
    editor_x_lines(wb, factor);
    editor_y_lines(wb, factor);
    handle_mouse(wb, factor);
    sfCircleShape_setRadius(wb->circle, rad);
    sfCircleShape_setPosition(wb->circle, (sfVector2f)\
    {mouse_pos.x - rad, mouse_pos.y - rad});
    sfRenderWindow_drawCircleShape(wb->window, wb->circle, NULL);
}
