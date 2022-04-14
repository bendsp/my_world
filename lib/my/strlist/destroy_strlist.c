/*
** EPITECH PROJECT, 2021
** common
** File description:
** destroy_strlist.c
*/

#include "my.h"
#include <stdlib.h>

void destroy_strlist(char **strlist)
{
    int i;
    for (i = 0; strlist[i] != NULL; i++)
        free(strlist[i]);
    free(strlist);
}
