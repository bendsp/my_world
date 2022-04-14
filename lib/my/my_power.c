/*
** EPITECH PROJECT, 2021
** power rec
** File description:
** output nb to power p with recursive
*/

int my_power(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (nb * my_power(nb, p - 1));
}
