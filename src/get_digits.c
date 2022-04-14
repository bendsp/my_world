/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** get_digits.c
*/

int get_digits(int num)
{
    int r = 1;
    if (num >= 0) {
        while (num > 9) {
            num /= 10;
            r++;
        }
    } else {
        while (num < 0 - 9) {
            num /= 10;
            r++;
        }
        r++;
    }
    return r;
}
