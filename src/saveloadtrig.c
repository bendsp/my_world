/*
** EPITECH PROJECT, 2021
** world
** File description:
** saveloadtrig.c
*/

#include "my_world.h"

int input_alpha(winbase_t *wb)
{
    if (0 <= wb->event.key.code && wb->event.key.code < 26) {
        return wb->event.key.code;
    } else if (sfKeyEnter == wb->event.key.code) {
        return -2;
    } else {
        return -1;
    }
}

void spe_event_sl(winbase_t *wb, char *text, int *i)
{
    int my_char;
    while (sfRenderWindow_pollEvent(wb->window, &wb->event))
        switch (wb->event.type) {
            case (sfEvtClosed):
                sfRenderWindow_close(wb->window);
                break;
            case (sfEvtKeyPressed):
                my_char = input_alpha(wb);
                if (my_char >= 0) {
                    text[*i] = my_char + 'a';
                    *i += 1;
                    text[*i] = 0;
                }
                if (my_char == -2 || *i > 99)
                    *i = -1;
                break;
            default:
        }
}

char *get_file_name(winbase_t *wb)
{
    sfVector2f **projmap;
    char *text = malloc(100);
    char *withextent;
    int i = 0;
    text[0] = 0;
    while (sfRenderWindow_isOpen(wb->window)) {
        spe_event_sl(wb, text, &i);
        if (i == -1)
            break;
        projmap = project_map(wb);
        display_str(wb, text, (sfVector2f){100, 90}, 1.5);
        draw_all(wb, projmap);
        destroy_projmap(&wb->world.dim, projmap);
    }
    withextent = my_strcat(text, ".wrld");
    free(text);
    text = my_strcat("saves/" ,withextent);
    free(withextent);
    return text;
}

void save_trigger(winbase_t *wb)
{
    char *file = get_file_name(wb);
    save(wb, file);
    free(file);
}

void load_trigger(winbase_t *wb)
{
    char *file = get_file_name(wb);
    load(wb, file);
    free(file);
}
