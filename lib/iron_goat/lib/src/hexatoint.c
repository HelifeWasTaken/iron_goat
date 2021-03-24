/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** hexatoint.c
*/

#include <stddef.h>
#include <stdint.h>

int64_t check_base(char c, char *base)
{
    for (int64_t index = 0; base[index] != '\0'; index++) {
        if (base[index] == c)
            return (index);
    }
    return (-1);
}

int64_t hextoint(char *str)
{
    char base[17] = "0123456789ABCDEF\0";
    int64_t nb = 0;
    int64_t tmp = 0;

    for (int64_t i = 0; str[i] != '\0'; i++) {
        nb *= 16;
        tmp = check_base(str[i], base);
        if (tmp != -1)
            nb += tmp;
    }
    return (nb);
}
