/*
** EPITECH PROJECT, 2021
** wangcolor
** File description:
** color
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_wangcolor(struct iron_goat_wangcolor *self)
{
    FREE(self->name);
}