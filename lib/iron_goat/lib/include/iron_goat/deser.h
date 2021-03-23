/*
** EPITECH PROJECT, 2021
** deser
** File description:
** deser
*/

#ifndef __LIB_IRON_GOAT_DESER_H__
    #define __LIB_IRON_GOAT_DESER_H__

    #include <iron_goat/tiled.h>

    struct json_deser_data {
        char *data;
        const usize_t size_data;
        const usize_t offset;
        bool (*intern)(struct json *, void **);
        const int type;
    };

    struct json_deser {
        const struct json_deser_data *data;
        const usize_t size;
    };

    #define JSON_DESER(data) \
        (struct json_deser){data, ARRAY_SIZE(data)}

    bool iron_goat_deser(struct json *conf,
        struct json_deser *deser, void *data);

    void destroy_iron_goat_wangset(struct iron_goat_wangset *self);
    void destroy_iron_goat_chunk(struct iron_goat_chunk *self);
    void destroy_iron_goat_layer(struct iron_goat_layer *self);
    void destroy_iron_goat_map(struct iron_goat_map *self);
    void destroy_iron_goat_object(struct iron_goat_object *self);
    void destroy_iron_goat_property(struct iron_goat_property *self);
    void destroy_iron_goat_terrain(struct iron_goat_terrain *self);
    void destroy_iron_goat_text(struct iron_goat_text *self);
    void destroy_iron_goat_tile(struct iron_goat_tile *self);
    void destroy_iron_goat_tileset(struct iron_goat_tileset *self);
    void destroy_iron_goat_wangcolor(struct iron_goat_wangcolor *self);
    void destroy_iron_goat_wangset(struct iron_goat_wangset *self);

    bool load_iron_goat_u64_vector(struct json *conf, void **data);

    bool init_iron_goat_chunk(struct json *conf, void *data);

#endif