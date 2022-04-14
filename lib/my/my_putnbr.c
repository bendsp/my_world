/*
** EPITECH PROJECT, 2021
** putnbr
** File description:
** display number given as parameter
*/

#include "my.h"

void my_putnbr(int nb)
{
    char *str = my_getstr(nb);
    my_putstr(str);
    free(str);
}
