/*
** EPITECH PROJECT, 2021
** wangset
** File description:
** wang
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_wangset(struct iron_goat_wangset *self)
{
    self->cornercolors->clear(&self->cornercolors);
    self->edgecolors->clear(&self->edgecolors);
    self->properties->clear(&self->properties);
    self->wangtiles->clear(&self->wangtiles);
}