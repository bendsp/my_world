/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** emulate printf but not as good
*/

#include "my_printf.h"

static const cases_t funclist[NBFUNC] = {
    {'i', i_case},
    {'d', i_case},
    {'c', c_case},
    {'s', s_case},
    {'b', b_case}
};

void foundflags(va_list args, const char *format, int *i)
{
    int funci = 0;

    for (funci = 0; funci < NBFUNC; funci++)
        if (format[*i + 1] == funclist[funci].c)
            funclist[funci].print_case(args);
    *i += 1;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int i;
    va_start(args, format);
    for (i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            foundflags(args , format, &i);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
    return 0;
}
