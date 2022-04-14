/*
** EPITECH PROJECT, 2021
** get number
** File description:
** get int from a string
*/

#include "my.h"

int my_atoi(const char *str)
{
    int i;
    int res;

    if (str == 0)
        return 0;
    if (str[0] == '-')
        return (-my_atoi(str + 1));
    i = 0;
    res = 0;
    while (str[i] >= '0' && str[i] <= '9' && str[i]) {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res);
}
