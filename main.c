#include <erty/json.h>
#include <iron_goat/deser.h>


struct abc {
    int a;
    int b;
};


static const struct json_deser_data ALED[] = {
    {
        .data = ".height",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct abc, a),
        .intern = NULL,
        .type = JSON_NUM
    },
    {
        .data = ".height",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct abc, b),
        .intern = NULL,
        .type = JSON_NUM,
    }
};

void load_test(struct json conf)
{
    struct abc a;
    iron_goat_deser(&conf, &JSON_DESER(ALED), &a);
}

int main(void)
{
    struct json conf = {0};
 //   struct iron_goat_chunk chnk = {0};

    if (json_parser(&conf, "conf.json") == false)
        return (1);
    load_test((conf));
   // init_iron_goat_chunk(&conf, &chnk);
   // destroy_iron_goat_chunk(&chnk);
    destroy_json(&conf);
    return (0);
}