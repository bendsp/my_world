/*
** EPITECH PROJECT, 2021
** common
** File description:
** main
*/

#include "my_world.h"

void launch(void)
{
    winbase_t *wb = create_winbase();
    sfVector2f **projmap;
    play_music(wb);
    while (sfRenderWindow_isOpen(wb->window)) {
        projmap = project_map(wb);
        mousedrag(wb);
        draw_all(wb, projmap);
        destroy_projmap(&wb->world.dim, projmap);
        handle_event(wb);
        wb->world.angle.x += wb->world.rota;
        if (wb->editor)
            editor(wb);
    }
    destroy_winbase(wb);
}

void print_help(void)
{
    my_putstr("\nUSAGE:\n");
    my_putstr("    ARROWS | Left Click   : move\n");
    my_putstr("    ZQSD | Right Click    : change angle\n");
    my_putstr("    PM | Mouse Wheel      : zoom and unzoom\n");
    my_putstr("    R                     : generate a new map\n");
    my_putstr("    B                     : flatten the map\n");
    my_putstr("    BACKSPACE             : close window\n");
    my_putstr("\nEDITOR:\n");
    my_putstr("    Left Click            : add terrain\n");
    my_putstr("    Right Click           : remove terrain\n");
    my_putstr("    UJ | Mouse Wheel      : change pen size\n");
    my_putstr("    IK                    : change pen strenght\n\n");
}

int main(int ac, char **av)
{
    if (ac >= 2 && my_strcmp(av[1], "-h")) {
        print_help();
    } else {
        launch();
    }
    return 0;
}
