/*
** EPITECH PROJECT, 2021
** world
** File description:
** handlebutton.c
*/

#include "my_world.h"

void test_buttons(winbase_t *wb)
{
    if (is_clicked(wb, &wb->menu.flatten))
        switch_blank(wb);
    if (is_clicked(wb, &wb->menu.redim))
        redim_trigger(wb);
    if (is_clicked(wb, &wb->menu.save))
        save_trigger(wb);
    if (is_clicked(wb, &wb->menu.load))
        load_trigger(wb);
    if (is_clicked(wb, &wb->menu.auto_rota)) {
        if (wb->event.mouseButton.button == sfMouseLeft)
            wb->world.rota += 0.2 * 60 / WINFPS;
        if (wb->event.mouseButton.button == sfMouseRight)
            wb->world.rota -= 0.2 * 60 / WINFPS;
    }
}

void setup_buttons(winbase_t *wb)
{
    sfVector2f scale = {0.5, 0.5};
    wb->menu.flatten = setup_button((sfVector2f){1750, 60},\
    scale, "assets/flattenmap.png");
    wb->menu.redim = setup_button((sfVector2f){1750, 120},\
    scale, "assets/redimension.png");
    wb->menu.auto_rota = setup_button((sfVector2f){1750, 180},\
    scale, "assets/autorota.png");
    wb->menu.save = setup_button((sfVector2f){1750, 940},\
    scale, "assets/save.png");
    wb->menu.load = setup_button((sfVector2f){1750, 1000},\
    scale, "assets/load.png");
}

void draw_button(winbase_t *wb, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    int minx = button->pos.x;
    int miny = button->pos.y;
    int maxx = button->pos.x + button->size.x;
    int maxy = button->pos.y + button->size.y;
    sfVector2f scale = button->scale;
    if (mouse_pos.x > minx && mouse_pos.x < maxx && \
    mouse_pos.y > miny && mouse_pos.y < maxy) {
        scale = (sfVector2f){scale.x * 1.1, scale.y * 1.1};
        if (sfMouse_isButtonPressed(sfMouseLeft) || \
        sfMouse_isButtonPressed(sfMouseRight))
            scale = (sfVector2f){scale.x * 0.8, scale.y * 0.8};
    }
    sfSprite_setScale(button->sprite, scale);
    sfRenderWindow_drawSprite(wb->window, button->sprite, NULL);
}

bool is_clicked(winbase_t *wb, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    int minx = button->pos.x;
    int miny = button->pos.y;
    int maxx = button->pos.x + button->size.x;
    int maxy = button->pos.y + button->size.y;
    if (mouse_pos.x > minx && mouse_pos.x < maxx && \
    mouse_pos.y > miny && mouse_pos.y < maxy)
        return true;
    return false;
}
