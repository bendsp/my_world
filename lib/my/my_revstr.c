/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** reverse string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    char buffer = 0;
    for (i = 0; i < len / 2; i++) {
        buffer = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = buffer;
    }
}
