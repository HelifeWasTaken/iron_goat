/*
** EPITECH PROJECT, 2021
** getstring
** File description:
** string
*/

#include <iron_goat/deser.h>

bool iron_goat_get_string(struct json *conf, size_t offset, void *data)
{
    char *s = estrdup(conf->v.string);

    if (s == NULL) {
        ASSERT("json", "Allocation error");
        return (false);
    }
    ememcpy(data + offset, s, sizeof(char *));
    return (true);
}