/*
** EPITECH PROJECT, 2021
** deser
** File description:
** deser
*/

#ifndef __LIB_IRON_GOAT_DESER_H__
    #define __LIB_IRON_GOAT_DESER_H__

    #include <iron_goat/tiled.h>

    typedef struct {
        char *data;
        usize_t size_data;
        usize_t offset;
    } json_deser_t;

#endif