#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void pool_test001(void)
{
    ngx_str_t s = ngx_string("bokko");
    u_char *sp;
    ngx_pool_t *pool;
    size_t len;

    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    if (pool == NULL) {
        CU_FAIL_FATAL("ngx_create_pool() failed.");
    }
    len = ngx_strlen(s.data);

    sp = ngx_palloc(pool, len + 1);
    if (sp == NULL) {
        CU_FAIL_FATAL("ngx_palloc() failed.");
    }

    ngx_cpystrn(sp, s.data, len + 1);

    CU_ASSERT_STRING_EQUAL(sp, s.data);
    CU_ASSERT_EQUAL(5, len);

    ngx_destroy_pool(pool);
}
