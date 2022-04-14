/*
** EPITECH PROJECT, 2021
** putstr
** File description:
** print string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i;
    for (i = 0; str[i] != 0; i++)
        my_putchar(str[i]);
}
