/*
** EPITECH PROJECT, 2021
** gnl
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *my_getline(int fd)
{
    char *str = malloc(3);
    char *readed = malloc(2);
    read(fd, str, 1);
    str[1] = 0;
    do {
        if (read(fd, readed, 1) == 0) {
            free(readed);
            free(str);
            return NULL;
        }
        str = my_addchar(str, readed[0]);
    } while (readed[0] != '\n');
    free(readed);
    return str;
}
