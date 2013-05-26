#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_crypt.h>

int main (int argc, char *argv[])
{
    ngx_pool_t *pool;
    ngx_str_t dst, src = ngx_string("cubicdaiya");
    u_char *encoded;
    size_t encoded_len;

    encoded_len = ngx_base64_encoded_length(src.len);
    pool        = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    if ((encoded = ngx_pcalloc(pool, encoded_len + 1)) == NULL) {
        return 1;
    }

    dst.data = encoded;
    dst.len  = encoded_len;
    ngx_encode_base64(&dst, &src);

    printf("src:%s, dst:%s\n", src.data, dst.data);

    return 0;
}
