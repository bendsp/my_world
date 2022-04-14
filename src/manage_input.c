/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** mange_input.c
*/

#include "my_world.h"

void angle_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case (sfKeyD):
            wb->world.angle.x -= 2;
            break;
        case (sfKeyQ):
            wb->world.angle.x += 2;
            break;
        case (sfKeyZ):
            wb->world.angle.y -= 2;
            break;
        case (sfKeyS):
            wb->world.angle.y += 2;
            break;
        default:
            break;
    }
}

void pos_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case (sfKeyLeft):
            wb->world.pos.x -= 10;
            break;
        case (sfKeyRight):
            wb->world.pos.x += 10;
            break;
        case (sfKeyDown):
            wb->world.pos.y += 10;
            break;
        case (sfKeyUp):
            wb->world.pos.y -= 10;
            break;
        default:
            break;
    }
}

void size_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case (sfKeyP):
            wb->world.size *= 1.03;
            break;
        case (sfKeyM):
            wb->world.size /= 1.03;
            break;
        case (sfKeyU):
            wb->pen_size *= 1.05;
            break;
        case (sfKeyJ):
            wb->pen_size /= 1.05;
            break;
        case (sfKeyI):
            wb->pen_strenght *= 1.05;
            break;
        case (sfKeyK):
            wb->pen_strenght /= 1.05;
            break;
        default:
    }
}

void reset_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case sfKeyR:
            switch_map(wb);
            break;
        case sfKeyB:
            switch_blank(wb);
            break;
        case sfKeyBackspace:
            sfRenderWindow_close(wb->window);
            break;
        case sfKeyH:
            wb->menu.draw *= 0 - 1;
            break;
        case sfKeyE:
            wb->editor = 1 - wb->editor;
        default:
    }
}

void kbd_input(winbase_t *wb)
{
    angle_input(wb);
    pos_input(wb);
    size_input(wb);
    reset_input(wb);
}
