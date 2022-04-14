/*
** EPITECH PROJECT, 2021
** swap
** File description:
** swap to variable
*/

void my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
