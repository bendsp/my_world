/*
** EPITECH PROJECT, 2021
** common
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    char *dup = malloc(my_strlen(str) + 1);
    my_strcpy(dup, str);
    return dup;
}
