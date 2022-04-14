/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** cases
*/

#include "my_printf.h"

void i_case(va_list args)
{
    my_putnbr(va_arg(args, int));
}

void c_case(va_list args)
{
    my_putchar(va_arg(args, int));
}

void s_case(va_list args)
{
    my_putstr(va_arg(args, char *));
}

void b_case(va_list args)
{
    my_putstr(basestr(va_arg(args, int), 2));
}
