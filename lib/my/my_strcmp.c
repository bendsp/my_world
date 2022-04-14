/*
** EPITECH PROJECT, 2021
** antman
** File description:
** my_strcmp.c
*/

#include "my.h"

bool my_strcmp(char *str1, char *str2)
{
    int i;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    if (len1 != len2)
        return false;
    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}
