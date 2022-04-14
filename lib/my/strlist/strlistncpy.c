/*
** EPITECH PROJECT, 2021
** common
** File description:
** strlistncpy.c
*/

#include "my.h"
#include <stdlib.h>

char **strlistncpy(char **dest, char **src, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = malloc(my_strlen(src[i]) + 1);
        my_strcpy(dest[i], src[i]);
    }
    dest[i] = NULL;
    return (dest);
}
