/*
** EPITECH PROJECT, 2021
** common
** File description:
** my_addchar.c
*/

#include "my.h"

char *my_addchar(char *str, char c)
{
    int len = my_strlen(str);
    str = my_reallocstr(str, len + 2);
    str[len] = c;
    str[len + 1] = 0;
    return str;
}
