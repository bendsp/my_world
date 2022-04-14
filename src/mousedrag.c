/*
** EPITECH PROJECT, 2021
** world
** File description:
** mousedrag.c
*/

#include "my_world.h"

void mousescroll(winbase_t *wb)
{
    if (wb->editor) {
        wb->pen_size /= pow(1.15, (float)wb->event.mouseWheel.delta);
    } else {
        wb->world.size *= pow(1.15, (float)wb->event.mouseWheel.delta);
    }
}

void mousedrag(winbase_t *wb)
{
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(wb->window);
    sfVector2i delta = {mousepos.x - wb->premousepos.x, \
    mousepos.y - wb->premousepos.y};
    if (!wb->editor) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            wb->world.pos.x += delta.x;
            wb->world.pos.y += delta.y;
        }
        if (sfMouse_isButtonPressed(sfMouseRight)) {
            wb->world.angle.x -= delta.x / 9;
            wb->world.angle.y += delta.y / 9;
        }
        wb->premousepos = mousepos;
    }
}
