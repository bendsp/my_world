/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** projection.c
*/

#include "my_world.h"

sfVector2f scale_point(winbase_t *wb, sfVector2f **map, int y, int x)
{
    sfVector2f scaledpoint;
    scaledpoint.x = map[y][x].x * wb->world.size / wb->world.dim.x + wb->world.pos.x;
    scaledpoint.y = map[y][x].y * wb->world.size / wb->world.dim.y + wb->world.pos.y;
    return scaledpoint;
}

sfVector2f project_point(sfVector3f point_3d, sfVector2f angle)
{
    sfVector2f point_2d;
    point_2d.x = cos(angle.x) * point_3d.x - sin(angle.x) * point_3d.y;
    point_2d.y = sin(angle.y) * sin(angle.x) * point_3d.x + sin(angle.y) * cos(angle.x) * point_3d.y - cos(angle.y) * point_3d.z;
    return point_2d;
}

sfVector2f **project_map(winbase_t *wb)
{
    int y;
    int x;
    int width = wb->world.dim.x;
    int height = wb->world.dim.y;
    sfVector2f **projmap = malloc(height * sizeof(sfVector2f *));
    sfVector2f angle;
    sfVector3f point_3d;
    int realx;
    int realy;
    angle.x = wb->world.angle.x * PI / 180;
    angle.y = wb->world.angle.y * PI / 180;
    for (y = 0; y < height; y++) {
        projmap[y] = malloc(width * sizeof(sfVector2f));
        for (x = 0; x < width; x++) {
            realx = x - wb->world.dim.x / 2;
            realy = y - wb->world.dim.y / 2;
            point_3d = (sfVector3f){realx, realy, wb->height_map[y][x]};
            projmap[y][x] = project_point(point_3d, angle);
        }
    }
    return projmap;
}

void draw_x_lines(winbase_t *wb, sfVector2f **map)
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
            scaledpoint = scale_point(wb, map, y, x);
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

void draw_y_lines(winbase_t *wb, sfVector2f **map)
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
            scaledpoint = scale_point(wb, map, y, x);
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
