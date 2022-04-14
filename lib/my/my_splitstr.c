/*
** EPITECH PROJECT, 2021
** common
** File description:
** my_splitstr.c
*/

#include "my.h"
#include <stdlib.h>

int indexnextchar(char *str, char c, int start)
{
    int i;
    for (i = start; str[i] != c && str[i] != '\0'; i++);
    i++;
    return i;
}

char **splitstr(char *str, char c)
{
    int i;
    int j;
    int previ;
    int nexti;
    int cnum = countchar(str, c);
    char **strlist = malloc((cnum + 2) * sizeof(char *));

    previ = 0;
    for (i = 0; i < cnum + 1; i++) {
        nexti = indexnextchar(str, c, previ);
        strlist[i] = malloc(nexti - previ + 1);
        for (j = 0; j < nexti - previ; j++)
            strlist[i][j] = str[j + previ];
        strlist[i][j - 1] = 0;
        previ = nexti;
    }
    strlist[i] = NULL;
    return strlist;
}
