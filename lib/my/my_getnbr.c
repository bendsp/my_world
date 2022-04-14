/*
** EPITECH PROJECT, 2021
** getnbr
** File description:
** get number in str
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int res = 0;

    for (i = 0; str[i] <= '9' && str[i] >= '0'; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    return (res);
}
