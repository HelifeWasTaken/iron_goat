/*
** EPITECH PROJECT, 2021
** u64vec
** File description:
** vec
*/

#include <iron_goat/deser.h>

bool load_iron_goat_u64_vector(struct json *conf, void **data)
{
    VECTOR(ig_u64) *self = NULL;
    struct json_array *real_data = conf->v.array;

    if ((self = VECTOR_CREATE(ig_u64)) == NULL) {
        ASSERT("IronGoat", "Allocation error");
        return (false);
    }
    for (size_t i = 0; i < real_data->size; i++) {
        if (real_data->data[i].t != JSON_NUM) {
            ASSERT("IronGoat", "Data chunk field is corrupted");
            return (false);
        }
        if (self->push_back(&self, real_data->data[i].v.number) == -1) {
            ASSERT("IronGoat", "Allocation error");
            return (false);
        }
    }
    *data = self;
    return (true);
}