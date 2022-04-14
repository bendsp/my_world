/*
** EPITECH PROJECT, 2021
** common
** File description:
** compare 2 string
*/

#include <stdbool.h>

bool my_strncmp(int n, char *str1, char *str2)
{
    int i;
    for (i = 0; i < n; i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}
