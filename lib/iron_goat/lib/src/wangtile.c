/*
** EPITECH PROJECT, 2021
** wangtile
** File description:
** wang
*/

#include <iron_goat/deser.h>

static const struct json_deser_data IG_WANGTILE[] = {
    {
        .data = ".dflip",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_wangtile, dflip),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL
    },
    {
        .data = ".hflip",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_wangtile, hflip),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL
    },
    {
        .data = ".tileid",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_wangtile, tileid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".vflip",
        .size_data = sizeof(u8_t),
        .offset = offsetof(struct iron_goat_wangtile, wangid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    } 
};

bool init_json_wangtile(struct json *conf, struct iron_goat_wangtile *self)
{
    DESER_LOOP(conf, self, IG_WANGTILE);
}