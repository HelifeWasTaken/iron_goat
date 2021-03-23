/*
** EPITECH PROJECT, 2021
** chunk
** File description:
** chunk
*/

#include <iron_goat/deser.h>

static const struct json_deser_data CHUNK_DATA[] = {
    {
        .data = ".data",
        .size_data = sizeof(VECTOR(ig_u64) *),
        .offset = offsetof(struct iron_goat_chunk, data),
        .intern = load_iron_goat_u64_vector,
        .type = JSON_ARR
    },
    {
        .data = ".height",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_chunk, height),
        .intern = NULL,
        .type = JSON_NUM,
    },
    {
        .data = ".width",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_chunk, width),
        .intern = NULL,
        .type = JSON_NUM
    },
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_chunk, x),
        .intern = NULL,
        .type = JSON_NUM
    },
    {
        .data = ".y",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_chunk, y),
        .intern = NULL,
        .type = JSON_NUM
    }
};

void destroy_iron_goat_chunk(struct iron_goat_chunk *self)
{
    if (self->data)
        self->data->clear(&self->data);
}

bool init_iron_goat_chunk(struct json *conf, void *data)
{
    struct iron_goat_chunk new = {0};
    bool res = iron_goat_deser(conf, &JSON_DESER(CHUNK_DATA), &new);

    if (res == true)
        ememcpy(data, &new, sizeof(struct iron_goat_chunk));
    return (res);
}