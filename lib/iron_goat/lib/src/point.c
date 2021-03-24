/*
** EPITECH PROJECT, 2021
** point
** File description:
** point
*/

#include <iron_goat/deser.h>

static const struct json_deser_data IG_POINT[] = {
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_point, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".y",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_point, y),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    }
};

bool init_iron_goat_point(struct json *conf, struct iron_goat_point *self)
{
    DESER_LOOP(conf, self, IG_POINT);
}