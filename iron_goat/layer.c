/*
** EPITECH PROJECT, 2021
** layer
** File description:
** layer
*/

#include <iron_goat/deser.h>
#include "priv/layer/layer.h"

void destroy_iron_goat_layer(struct iron_goat_layer *self)
{
    FREE(self->name);
    if (self->chunks)
        self->chunks->clear(&self->chunks);
    FREE(self->data.data);
    self->data.size = 0;
    if (self->layers)
        self->layers->clear(&self->layers);
    if (self->properties)
        self->properties->clear(&self->properties);
}

bool load_iron_goat_layer_objects(struct json *conf,
    struct iron_goat_layer *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_object obj = {0};

    if ((self->objects = VECTOR_CREATE(ig_obj)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        obj = (struct iron_goat_object){0};
        if (init_iron_goat_object(&data->data[i], &obj) == false)
            return (false);
        if (self->objects->push_back(&self->objects, obj) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_layer_layers(struct json *conf,
    struct iron_goat_layer *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_layer layer = {0};

    if ((self->layers = VECTOR_CREATE(ig_layer)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        layer = (struct iron_goat_layer){0};
        if (init_iron_goat_layer(&data->data[i], &layer) == false)
            return (false);
        if (self->layers->push_back(&self->layers, layer) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_layer_properties(struct json *conf,
    struct iron_goat_layer *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_property prop = {0};

    if ((self->properties = VECTOR_CREATE(ig_prop)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        prop = (struct iron_goat_property){0};
        if (init_iron_goat_props(&data->data[i], &prop) == false)
            return (false);
        if (self->properties->push_back(&self->properties, prop) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_LAYER[] = {
    {
        .data = ".chunks",
        .size_data = sizeof(VECTOR(ig_chunk) *),
        .offset = offsetof(struct iron_goat_layer, chunks),
        .intern = {
            .callback = load_iron_goat_layer_chunks,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".data",
        .size_data = sizeof(u64_t *),
        .offset = offsetof(struct iron_goat_layer, data),
        .intern = {
            .callback = load_iron_goat_layer_data,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".draworder",
        .size_data = sizeof(ig_layer_draworder_t),
        .offset = offsetof(struct iron_goat_layer, draworder),
        .intern = {
            .callback = load_iron_goat_layer_draworder,
            .woff = false
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".encoding",
        .size_data = sizeof(ig_layer_encoding_t),
        .offset = offsetof(struct iron_goat_layer, encoding),
        .intern = {
            .callback = load_iron_goat_layer_encoding,
            .woff = false
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".height",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_layer, height),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".id",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_layer, id),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".image",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_layer, image),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".layers",
        .size_data = sizeof(VECTOR(ig_layer) *),
        .offset = offsetof(struct iron_goat_layer, layers),
        .intern = {
            .callback = load_iron_goat_layer_layers,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_layer, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".objects",
        .size_data = sizeof(VECTOR(ig_obj) *),
        .offset = offsetof(struct iron_goat_layer, objects),
        .intern = {
            .callback = load_iron_goat_layer_objects,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".offsetx",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_layer, offsetx),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".offsety",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_layer, offsety),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".opacity",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_layer, opacity),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_layer, properties),
        .intern = {
            .callback = load_iron_goat_layer_properties,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".startx",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_layer, startx),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".starty",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_layer, starty),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".tintcolor",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_layer, tintcolor),
        .intern = {
            .callback = iron_goat_get_color,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".transparentcolor",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_layer, transparentcolor),
        .intern = {
            .callback = iron_goat_get_color,
            .woff = true
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".type",
        .size_data = sizeof(ig_layer_type_t),
        .offset = offsetof(struct iron_goat_layer, type),
        .intern = {
            .callback = load_iron_goat_layer_type,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".visible",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_layer, visible),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".width",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_layer, width),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_layer, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".y",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_layer, y),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
};

bool init_iron_goat_layer(struct json *conf, struct iron_goat_layer *self)
{
    DESER_LOOP(conf, self, IG_LAYER);
}
