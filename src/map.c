/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_map(struct iron_goat_map *self)
{
    self->layers->clear(&self->layers);
    self->properties->clear(&self->properties);
    FREE(self->tiledversion);
    self->tilesets->clear(&self->tilesets);
}