/*
** EPITECH PROJECT, 2021
** string lenght
** File description:
** return number of character of a string
*/

int my_strlen(char *str)
{
    int i;
    for (i = 0; str[i] != 0; i++);
    return (i);
}
