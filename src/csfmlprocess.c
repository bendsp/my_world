/*
** EPITECH PROJECT, 2021
** my_tower
** File description:
** csfmlprocess.c
*/

#include "my_world.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WINWIDTH, WINHEIGHT, WINBPP};
    const char *title = "my_world";
    return sfRenderWindow_create(mode, title,\
    sfClose | sfResize | sfFullscreen, NULL);
}

void handle_event(winbase_t *wb)
{
    while (sfRenderWindow_pollEvent(wb->window, &wb->event))
        switch (wb->event.type) {
            case (sfEvtClosed):
                sfRenderWindow_close(wb->window);
                break;
            case (sfEvtKeyPressed):
                kbd_input(wb);
                break;
            case (sfEvtMouseButtonPressed):
                test_buttons(wb);
                break;
            case (sfEvtMouseWheelMoved):
                mousescroll(wb);
                break;
            default:
                break;
        }
}

winbase_t *create_winbase(void)
{
    winbase_t *wb = malloc(sizeof(winbase_t));
    srand(4);
    wb->window = create_window();
    wb->world = setup_world();
    wb->height_map = setup_map(wb->world.dim.x, wb->world.dim.y);
    sfRenderWindow_setFramerateLimit(wb->window, WINFPS);
    wb->menu.draw = 1;
    setup_buttons(wb);
    wb->font = sfFont_createFromFile("assets/font.otf");
    wb->pen_size = 10;
    wb->pen_strenght = 20;
    wb->editor = false;
    wb->circle = create_circle();
    wb->premousepos = sfMouse_getPositionRenderWindow(wb->window);
    return wb;
}

void destroy_winbase(winbase_t *wb)
{
    int i;
    sfRenderWindow_destroy(wb->window);
    for (i = 0; wb->height_map[i] != NULL; i++)
        free(wb->height_map[i]);
    free(wb->height_map);
    sfMusic_destroy(wb->music);
    sfFont_destroy(wb->font);
    free(wb);
}

void draw_all(winbase_t *wb, sfVector2f **map)
{
    draw_x_lines(wb, map);
    draw_y_lines(wb, map);
    if (wb->menu.draw == 1) {
        draw_button(wb, &wb->menu.flatten);
        draw_button(wb, &wb->menu.redim);
        draw_button(wb, &wb->menu.auto_rota);
        draw_button(wb, &wb->menu.save);
        draw_button(wb, &wb->menu.load);
    }
    sfRenderWindow_display(wb->window);
    sfRenderWindow_clear(wb->window, sfBlack);
}
