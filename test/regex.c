#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void regex_test001(void)
{
    int rc, captures[(1 + 2) * 3];
    ngx_str_t unparsed_uri = ngx_string("small_light(p=medium)");
    ngx_str_t pattern = ngx_string("small_light\\(([^\\)]*)\\)");
    ngx_pool_t *pool;
    ngx_regex_compile_t rgc;
    u_char errstr[NGX_MAX_CONF_ERRSTR];
    u_char *define_pattern_s;

    // TODO: move setup().
    ngx_regex_init();

    ngx_memzero(&rgc, sizeof(ngx_regex_compile_t));
 
    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    if (pool == NULL) {
        CU_FAIL_FATAL("ngx_create_pool() failed.");
    }

    rgc.pattern  = pattern;
    rgc.pool     = pool;
    rgc.err.len  = NGX_MAX_CONF_ERRSTR;
    rgc.err.data = errstr;

    if (ngx_regex_compile(&rgc) != NGX_OK) {
        ngx_destroy_pool(pool);
        CU_FAIL_FATAL("ngx_regex_compile() failed.");
    }

    rc = ngx_regex_exec(rgc.regex, &unparsed_uri, captures, (1 + 2) * 3);

    if (rc >= 0) {
        int capture_start = captures[2];
        int capture_end   = captures[3];
        int capture_len   = capture_end - capture_start;
        define_pattern_s  = ngx_pcalloc(pool, capture_len + 1);
        if (define_pattern_s == NULL) {
            ngx_destroy_pool(pool);
            CU_FAIL_FATAL("ngx_pcalloc() failed.");
        }
        ngx_cpystrn(define_pattern_s, unparsed_uri.data + capture_start, capture_len + 1);
        CU_ASSERT_STRING_EQUAL("p=medium", define_pattern_s);
    } else {
        ngx_destroy_pool(pool);
        CU_FAIL_FATAL("ngx_regex_exec() failed.");
    }

    ngx_destroy_pool(pool);
}
