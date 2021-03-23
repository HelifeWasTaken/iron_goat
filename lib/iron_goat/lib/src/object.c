/*
** EPITECH PROJECT, 2021
** object
** File description:
** obj
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_object(struct iron_goat_object *self)
{
    FREE(self->name);
    self->properties->clear(&self->properties);
    FREE(self->template);
    FREE(self->type);
    self->polygon->clear(&self->polygon);
    self->text->clear(&self->text);
}