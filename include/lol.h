    typedef struct iron_goat_layer ig_layer_t;
    typedef struct iron_goat_map ig_map_t;
    typedef struct iron_goat_chunk ig_chunk_t;
    typedef struct iron_goat_text ig_text_t;
    typedef struct iron_goat_tileset ig_tileset_t;
    typedef struct iron_goat_grid ig_grid_t;
    typedef struct iron_goat_tile_offset ig_tileoff_t;
    typedef struct iron_goat_tile ig_tile_t;
    typedef struct iron_goat_frame ig_frame_t;
    typedef struct iron_goat_terrain ig_terrain_t;

    INIT_VECTOR(ig_u32, unsigned int, NULL);
    INIT_VECTOR(ig_i32, int, NULL);
    INIT_VECTOR(ig_layer, ig_layer_t, NULL);
    INIT_VECTOR(ig_chunk, ig_chunk_t, NULL);
    INIT_VECTOR(ig_tileoff, ig_tileoff_t, NULL);
    INIT_VECTOR(ig_tile, ig_tile_t, NULL);
    INIT_VECTOR(ig_frame, ig_frame_t, NULL);
    INIT_VECTOR(ig_terrain, ig_terrain_t, NULL);


    struct wang_set_terrain {
        char *prop;
        char *type;
    };

    struct iron_goat_terrain {
        char *name;
        VECTOR(ig_prop) *properties;
        int tile;
    };

    struct iron_goat_frame {
        int duration;
        int tileid;
    };

    struct iron_goat_tile {
        VECTOR(ig_frame) *frame;
        int id;
        char *image;
        int imageheight;
        int imagewidth;
        ig_layer_t layer;
        double probability;
        VECTOR(ig_prop) *properties;
        VECTOR(ig_i32) *terrain;
        char *type;
    };

    struct iron_goat_tile_offset {
        int x;
        int y;
    };

    struct iron_goat_grid {
        int height;
        char *orientation;
        int width;
    };


