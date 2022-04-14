/*
** EPITECH PROJECT, 2021
** concastr
** File description:
** concatenate 2 strings
*/
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i;
    int destlen = my_strlen(dest);
    int srclen = my_strlen(src);
    char *result = malloc(destlen + srclen + 1);
    my_strcpy(result, dest);
    for (i = 0; i < srclen + 1; i++)
        result[i + destlen] = src[i];
    result[destlen + i - 1] = 0;
    return result;
}
