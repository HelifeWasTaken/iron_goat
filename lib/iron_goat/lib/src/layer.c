/*
** EPITECH PROJECT, 2021
** layer
** File description:
** layer
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_layer(struct iron_goat_layer *self)
{
    FREE(self->name);
    self->chunks->clear(&self->chunks);
    self->data->clear(&self->data);
    self->layers->clear(&self->layers);
    self->properties->clear(&self->properties);
}