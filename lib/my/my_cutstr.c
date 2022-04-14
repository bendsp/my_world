/*
** EPITECH PROJECT, 2021
** lib
** File description:
** cut character x to y from a string
*/

#include "my.h"

char *my_strcut(char *str, int start, int end)
{
    char *outstr = malloc(end - start + 1);
    int i;
    for (i = start; i < end; i++)
        outstr[i - start] = str[i];
    outstr[i - start] = 0;
    return outstr;
}
