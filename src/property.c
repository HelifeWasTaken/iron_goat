/*
** EPITECH PROJECT, 2021
** property
** File description:
** prop
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_property(struct iron_goat_property *self)
{
    FREE(self->name);
    switch (self->type) {
        case PROP_STRING:
            FREE(self->v.str);
            break;
        case PROP_FILE:
            FREE(self->v.file);
            break;
        default:
            break;
    }
}