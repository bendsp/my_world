/*
** EPITECH PROJECT, 2021
** common
** File description:
** my_countchar.c
*/

#include "my.h"

int countchar(char *str, char c)
{
    int i;
    int counter = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            counter++;
    return counter;
}
