/*
** EPITECH PROJECT, 2021
** terrain
** File description:
** terrain
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_terrain(struct iron_goat_terrain *self)
{
    FREE(self->name);
    self->props->clear(&self->props);
}