/*
** EPITECH PROJECT, 2021
** deser
** File description:
** deser
*/

#include <string.h>
#include <iron_goat/deser.h>

static bool parse_with_intern_fun(struct json *conf,
    struct json_deser *deser, void *data, size_t i)
{
    void *dataptr = NULL;

    if (deser->data[i].intern(conf, &dataptr) == false)
        return (false);
    ememcpy(data + deser->data[i].offset, dataptr, 8);
    return (true);
}

bool iron_goat_deser(struct json *conf, struct json_deser *deser, void *data)
{
    struct json *ptr = conf;
    struct json base = *conf;

    for (size_t i = 0; i < deser->size; i++) {
        *conf = base;
        ptr = conf;
        if (json_getptr(conf, ptr, deser->data[i].data,
            deser->data[i].type) == false)
            return (false);
        if (deser->data[i].intern && 
            !parse_with_intern_fun(ptr, deser, data, i))
            return (false);
        else
            ememcpy(data + deser->data[i].offset,
                    &ptr->v.number, deser->data[i].size_data);
    }
    return (true);
}