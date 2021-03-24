/*
** EPITECH PROJECT, 2021
** terrain
** File description:
** terrain
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_terrain(struct iron_goat_terrain *self)
{
    FREE(self->name);
    self->props->clear(&self->props);
}

static const struct json_deser_data IG_TERRAIN[] = {
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_terrain, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR
    },
    {
        .data = ".props",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_terrain, props),
        .intern = {
            .callback = //,
            .woff = false
        },
        .type = JSON_ARR
    },
    {
        .data = ".tile",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_terrain, tile),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
};

bool init_iron_goat_terrain(struct json *conf, struct iron_goat_terrain *self)
{
    DESER_LOOP(conf, self, IG_TERRAIN);
}