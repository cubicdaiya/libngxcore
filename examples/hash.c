#include <stdio.h>
#include <ngx_core.h>

int main (int argc, char *argv[])
{
    ngx_pool_t *pool1, *pool2;
    ngx_hash_t hash;
    ngx_hash_init_t hash_init;
    ngx_hash_keys_arrays_t hash_array;

    ngx_str_t k1 = ngx_string("hn1");
    ngx_str_t k2 = ngx_string("hn2");
    ngx_str_t k3 = ngx_string("dummy");
    ngx_str_t v1 = ngx_string("bokko");
    ngx_str_t v2 = ngx_string("cubicdaiya");

    // nginx's hash utility depends on this variable
    // it is not necessary in ngx_modules
    ngx_cacheline_size = NGX_CPU_CACHE_LINE;

    pool1 = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    pool2 = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);

    hash_array.keys.pool = pool1;
    hash_array.temp_pool = pool2;
    if (ngx_hash_keys_array_init(&hash_array, NGX_HASH_SMALL) != NGX_OK) {
        return NGX_ERROR;
    }
    ngx_hash_add_key(&hash_array, &k1, v1.data, NGX_HASH_READONLY_KEY);
    ngx_hash_add_key(&hash_array, &k2, v2.data, NGX_HASH_READONLY_KEY);

    hash_init.hash        = &hash;
    hash_init.key         = ngx_hash_key_lc;
    hash_init.max_size    = 128;
    hash_init.bucket_size = ngx_cacheline_size;
    hash_init.name        = "hash_array_name";
    hash_init.pool        = hash_array.keys.pool;
    hash_init.temp_pool   = NULL;

    if (ngx_hash_init(&hash_init, hash_array.keys.elts, hash_array.keys.nelts) != NGX_OK) {
        return 1;
    }

    u_char *r1 = ngx_hash_find(&hash, ngx_hash_key_lc((u_char *)k1.data, ngx_strlen(k1.data)), (u_char *)k1.data, ngx_strlen(k1.data));
    u_char *r2 = ngx_hash_find(&hash, ngx_hash_key_lc((u_char *)k2.data, ngx_strlen(k2.data)), (u_char *)k2.data, ngx_strlen(k2.data));
    u_char *r3 = ngx_hash_find(&hash, ngx_hash_key_lc((u_char *)k3.data, ngx_strlen(k2.data)), (u_char *)k3.data, ngx_strlen(k3.data));
    printf("r1:%s, r2:%s, r3:%s\n", r1, r2, r3);

    return 0;
}
