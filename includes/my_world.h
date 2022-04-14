/*
** EPITECH PROJECT, 2021
** common
** File description:
** common.h
*/

#ifndef _MY_RADAR_
    #define _MY_RADAR_
    #include <SFML/Graphics.h>
    #include <time.h>
    #include <SFML/Window/Mouse.h>
    #include <math.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my.h"
    #include <SFML/Audio/Music.h>
    #define WINWIDTH 1920
    #define WINHEIGHT 1080
    #define WINFPS 60
    #define WINBPP 32
    #define PI 3.14159265359

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
} button_t;

typedef struct slider_s {
    sfSprite *bar_spr;
    sfSprite *ball_spr;
    sfTexture *bar_text;
    sfTexture *ball_text;
    sfVector2f pos;
    sfVector2f size;
    float value;
} slider_t;

typedef struct w_colors_s {
    sfColor high;
    sfColor low;
    int max;
} w_colors_t;

typedef struct sin_s {
    float off;
    float peak;
    float period;
} sin_t;

typedef struct gen_proc_s {
    int sin_count;
    sin_t *height;
} gen_proc_t;

typedef struct world_s {
    sfVector2i dim;
    sfVector2f pos;
    sfVector2f angle;
    float size;
    w_colors_t colors;
    sin_t *x_sin;
    sin_t *y_sin;
    float rota;
} world_t;

typedef struct menu_s {
    int draw;
    button_t flatten;
    button_t redim;
    button_t auto_rota;
    button_t save;
    button_t load;
} menu_t;

typedef struct winbase_s {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i coord;
    double **height_map;
    world_t world;
    sfMusic *music;
    menu_t menu;
    sfFont *font;
    float pen_size;
    float pen_strenght;
    bool editor;
    sfCircleShape *circle;
    sfVector2i premousepos;
} winbase_t;

sfVector2f scale_point(winbase_t *wb, sfVector2f **map, int y, int x);
winbase_t *create_winbase(void);
void handle_event(winbase_t *);
sfRenderWindow *create_window(void);
void destroy_winbase(winbase_t *);
void draw_all(winbase_t *, sfVector2f **);
double **setup_map(int, int);
void draw_x_lines(winbase_t *, sfVector2f **);
void draw_y_lines(winbase_t *, sfVector2f **);
sfVector2f **project_map(winbase_t *);
world_t setup_world(void);
void kbd_input(winbase_t *);
void destroy_projmap(sfVector2i *, sfVector2f **);
w_colors_t setup_color(void);
sfColor build_color(w_colors_t, double vh);
void switch_map(winbase_t *wb);
void reset_input(winbase_t *wb);
double rdm(void);
double calc_sinlist(sin_t *x_list, sin_t *y_list, float x, float y);
void play_music(winbase_t *wb);
void switch_blank(winbase_t *wb);
button_t setup_button(sfVector2f pos, sfVector2f size, char *file);
bool is_clicked(winbase_t *wb, button_t *button);
void test_buttons(winbase_t *wb);
void display_str(winbase_t *wb, char *str, sfVector2f pos, float size);
void redim_trigger(winbase_t *wb);
void setup_buttons(winbase_t *wb);
void editor(winbase_t *wb);
void handle_mouse(winbase_t *wb, int factor);
sfCircleShape *create_circle(void);
void draw_button(winbase_t *wb, button_t *button);
void mousedrag(winbase_t *wb);
void mousescroll(winbase_t *wb);
int get_digits(int num);
void save_trigger(winbase_t *wb);
void load_trigger(winbase_t *wb);
void load(winbase_t *wb, const char *filepath);
void save(winbase_t *wb, const char *filepath);

#endif
