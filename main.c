#include <erty/json.h>
#include <iron_goat/deser.h>

int main(void)
{
    struct json conf = {0};
    struct iron_goat_chunk chnk = {0};

    if (json_parser(&conf, "conf.json") == false)
        return (1);
   // printf("%ld\n", (size_t)&conf);
    init_iron_goat_chunk(&conf, &chnk);
   // destroy_iron_goat_chunk(&chnk);
   // printf("%ld\n", (size_t)&conf);
    destroy_json(&conf);
   // printf("%ld\n", (size_t)&conf);
    printf("%ld %ld %ld %ld\n", chnk.data->data[0], chnk.height, chnk.width, chnk.y);
    chnk.data->clear(&chnk.data);
    return (0);
}