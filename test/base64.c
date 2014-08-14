#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void base64_test001(void)
{
    ngx_pool_t *pool;
    ngx_str_t dst, src = ngx_string("cubicdaiya");
    u_char *encoded;
    size_t encoded_len;

    encoded_len = ngx_base64_encoded_length(src.len);
    pool        = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    if (pool == NULL) {
        CU_FAIL_FATAL("ngx_create_pool() failed.");
    }
    if ((encoded = ngx_pcalloc(pool, encoded_len + 1)) == NULL) {
        CU_FAIL_FATAL("ngx_pcalloc() failed.");
    }

    dst.data = encoded;
    dst.len  = encoded_len;
    ngx_encode_base64(&dst, &src);

    CU_ASSERT_STRING_EQUAL("Y3ViaWNkYWl5YQ==", dst.data);
}
