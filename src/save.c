/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** save.c
*/

#include "my_world.h"
#include "my.h"
#include<stdio.h>

void write_file(winbase_t *wb, int fd, int y, int x)
{
    char *buffer;
    char ret[1] = "\n";
    int value = wb->height_map[y][x] * 10;
    buffer = my_getstr(value);
    write(fd, buffer, get_digits(value));
    write(fd, ret, 1);
}

void write_map_size(winbase_t *wb, int fd)
{
    char *buffer;
    char space[1] = " ";
    char ret[1] = "\n";
    buffer = my_getstr(wb->world.dim.y);
    write(fd, buffer, get_digits(wb->world.dim.y));
    write(fd, space, 1);
    buffer = my_getstr(wb->world.dim.x);
    write(fd, buffer, get_digits(wb->world.dim.x));
    write(fd, ret, 1);
}

int open_file(const char *filepath)
{
    int fd;
    FILE *fp;
    fd = open(filepath, O_CREAT | O_WRONLY, 0664);
    fp = fopen(filepath, "w");
    fclose(fp);
    return fd;
}

void save(winbase_t *wb, const char *filepath)
{
    int fd;
    fd = open_file(filepath);
    write_map_size(wb, fd);
    for (int y = 0; y < wb->world.dim.y; ++y)
        for (int x = 0; x < wb->world.dim.x; x++)
            write_file(wb, fd, y, x);
    close(fd);
    return;
}
