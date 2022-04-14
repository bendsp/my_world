/*
** EPITECH PROJECT, 2021
** isprime
** File description:
** primality test
*/

int my_is_prime(int nb)
{
    int i;
    if (nb <= 1)
        return (0);
    for (i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}
