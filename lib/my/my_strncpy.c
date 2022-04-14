/*
** EPITECH PROJECT, 2021
** strn copy
** File description:
** copy n character of a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}
