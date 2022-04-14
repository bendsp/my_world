/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** header
*/

#ifndef _my_printf_
    #define _my_printf_
    #include "my.h"
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #define NBFUNC 5

typedef struct cases_s {
    char c;
    void (*print_case)(va_list args);
} cases_t;

int my_printf(const char *format, ...);
void i_case(va_list args);
void c_case(va_list args);
void s_case(va_list args);
void b_case(va_list args);

#endif
