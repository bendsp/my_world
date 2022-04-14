/*
** EPITECH PROJECT, 2021
** my
** File description:
** contain all the prototype
*/

#ifndef _MY_H_
    #define _MY_H_
    #define ABS(x) (((x) < 0 ? -(x) : (x)))
    #define MIN(x, y) ((x <= y) ? (x) : (y))
    #define MAX(x, y) ((x >= y) ? (x) : (y))
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
char *basestr(int nb, int base);
int my_atoi(const char *str);
char *my_getstr(int nb);
int my_is_prime(int nb);
int my_power(int nb, int power);
void my_putchar(char c);
void my_putnbr(int nb);
int my_putstr(char const *str);
char *my_reallocstr(char *str, int size);
char *my_revstr(char *str);
int my_sqrt(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);
int my_printf(const char *format, ...);
char *my_addchar(char *str, char c);
char *my_getline(int fd);
int countchar(char *str, char c);
char **splitstr(char *str, char c);
char *getcontent(int fd);
int lenstrlist(char **strlist);
char **strlistncpy(char **dest, char **src, int n);
void destroy_strlist(char **strlist);
char *my_strcat(char *dest, char const *src);
int int_len(int nb, int base);
char *my_strdup(char *str);
int countchar(char *str, char c);
bool my_strncmp(int n, char *str1, char *str2);
char *my_strcut(char *str, int start, int end);
bool my_strcmp(char *str1, char *str2);
#endif
