/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** same as realloc
*/

#include <stdlib.h>
#include "my.h"

char *my_reallocstr(char *str, int size)
{
    char *temp = malloc(size);
    int i;

    my_strncpy(temp, str, size - 1);
    free(str);
    str = malloc(size + 1);
    my_strncpy(str, temp, size);
    free(temp);
    return str;
}
