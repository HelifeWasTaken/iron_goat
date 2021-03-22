/*
** EPITECH PROJECT, 2021
** tileset
** File description:
** tilese
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_tileset(struct iron_goat_tileset *self)
{
    FREE(self->image);
    self->properties->clear(&self->properties);
    FREE(self->source);
    self->tiles->clear(&self->tiles);
    self->wangsets->clear(&self->wangsets);
}