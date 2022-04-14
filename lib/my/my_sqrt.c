/*
** EPITECH PROJECT, 2021
** squareroot
** File description:
** return square root of a number
*/

int my_sqrt(int nb)
{
    int i;
    for (i = 0; i <= nb; i++)
        if (i * i == nb)
            return (i);
    return (0);
}
