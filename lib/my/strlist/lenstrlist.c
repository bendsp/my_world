/*
** EPITECH PROJECT, 2021
** common
** File description:
** lenstrlist.c
*/

#include "my.h"
#include <stdlib.h>

int lenstrlist(char **strlist)
{
    int i;
    for (i = 0; strlist[i] != NULL; i++);
    return i;
}
