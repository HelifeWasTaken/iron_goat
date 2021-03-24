/*
** EPITECH PROJECT, 2021
** object
** File description:
** obj
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_object(struct iron_goat_object *self)
{
    FREE(self->name);
    if (self->properties)
        self->properties->clear(&self->properties);
    FREE(self->template);
    FREE(self->type);
    if (self->polygon)
        self->polygon->clear(&self->polygon);
    if (self->text)
        self->text->clear(&self->text);
}

static bool iron_goat_object_load_props(struct json *conf,
    struct iron_goat_object *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_property prop = {0};

    if ((self->properties = VECTOR_CREATE(ig_prop)) == NULL)
        return (false);
    for (size_t i = 0; data->size; i++) {
        prop = (struct iron_goat_property){0};
        init_iron_goat_props(&data->data[i], &prop);
        if (self->properties->push_back(&self->properties, prop) == -1)
            return (false);
    }
    return (true);
}

static bool iron_goat_object_load_polygon(struct json *conf,
    struct iron_goat_object *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_point point = {0};

    if ((self->polygon = VECTOR_CREATE(ig_point)) == NULL)
        return (false);
    for (size_t i = 0; data->size; i++) {
        point = (struct iron_goat_point){0};
        init_iron_goat_props(&data->data[i], &point);
        if (self->polygon->push_back(&self->polygon, point) == -1)
            return (false);
    }
    return (true);
}

static bool iron_goat_object_load_text(struct json *conf,
    struct iron_goat_object *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_text text = {0};

    if ((self->text = VECTOR_CREATE(ig_text)) == NULL)
        return (false);
    for (size_t i = 0; data->size; i++) {
        text = (struct iron_goat_text){0};
        init_iron_goat_props(&data->data[i], &text);
        if (self->text->push_back(&self->polygon, text) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_OBJECT[] = {
    {
        .data = ".height",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, height),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".id",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_object, id),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_object, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_object, properties),
        .intern = {
            .callback = iron_goat_object_load_props,
            .woff = false
        },
        .type = JSON_ARR
    },
    {
        .data = ".rotation",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, rotation),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".template",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_object, template),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR
    },
    {
        .data = ".type",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_object, type),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR
    },
    {
        .data = ".visible",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_object, visible),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL
    },
    {
        .data = ".width",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, width),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".gid",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_object, gid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM
    },
    {
        .data = ".polygon",
        .size_data = sizeof(VECTOR(ig_point) *),
        .offset = offsetof(struct iron_goat_object, polygon),
        .intern = {
            .callback = iron_goat_object_load_polygon,
            .woff = false
        },
        .type = JSON_ARR
    },
    {
        .data = ".text",
        .size_data = sizeof(VECTOR(ig_text)),
        .offset = offsetof(struct iron_goat_object, text),
        .intern = {
            .callback = iron_goat_object_load_text,
            .woff = false
        },
        .type = JSON_ARR
    }
};

static bool iron_goat_load_object(struct json *conf,
    struct iron_goat_object *self)
{
    DESER_LOOP(conf, self, IG_OBJECT);
}