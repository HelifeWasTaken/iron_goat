/*
** EPITECH PROJECT, 2021
** wangcolor
** File description:
** color
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_wangcolor(struct iron_goat_wangcolor *self)
{
    FREE(self->name);
}

static const struct json_deser_data IG_WANGCOLOR[] = {
    {
        .data = ".color",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_wangcolor, color),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_wangcolor, name),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_STR
    },
    {
        .data = ".probability",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_wangcolor, probability),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".tile",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_wangcolor, tile),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    }
};

bool init_iron_goat_wangcolor(struct json *conf,
                            struct iron_goat_wangcolor *self)
{
    DESER_LOOP(conf, self, IG_WANGCOLOR);
}