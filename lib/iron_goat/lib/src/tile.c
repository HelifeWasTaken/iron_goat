/*
** EPITECH PROJECT, 2021
** tile
** File description:
** tile
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_tile(struct iron_goat_tile *self)
{
    self->animation->clear(&self->animation);
    FREE(self->image);
    self->properties->clear(&self->properties);
    FREE(self->type);
}