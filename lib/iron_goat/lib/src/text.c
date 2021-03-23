/*
** EPITECH PROJECT, 2021
** text
** File description:
** text
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_text(struct iron_goat_text *self)
{
    FREE(self->fontfamily);
    FREE(self->text);
}