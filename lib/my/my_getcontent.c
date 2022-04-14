/*
** EPITECH PROJECT, 2021
** common
** File description:
** my_getcontent.c
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *getcontent(int fd)
{
    char *str = malloc(1);
    char *readed = malloc(2);
    str[0] = 0;
    while (read(fd, readed, 1) != 0) {
        str = my_addchar(str, readed[0]);
    }
    free(readed);
    return str;
}
