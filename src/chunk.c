/*
** EPITECH PROJECT, 2021
** chunk
** File description:
** chunk
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_chunk(struct iron_goat_chunk *self)
{
    self->data->clear(&self->data);
}