#include <stdio.h>

#include <ngx_core.h>
#include <ngx_palloc.h>
#include <ngx_string.h>

int main (int argc, char *argv[])
{
    int rc, captures[(1 + 2) * 3];
    ngx_str_t unparsed_uri = ngx_string("small_light(p=medium)");
    ngx_str_t pattern = ngx_string("small_light\\(([^\\)]*)\\)");
    ngx_pool_t *pool;
    ngx_regex_compile_t rgc;
    u_char errstr[NGX_MAX_CONF_ERRSTR];
    u_char *define_pattern_s;

    ngx_regex_init();

    ngx_memzero(&rgc, sizeof(ngx_regex_compile_t));
 
    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);

    printf("string:%s\n", pattern.data);

    rgc.pattern  = pattern;
    rgc.pool     = pool;
    rgc.err.len  = NGX_MAX_CONF_ERRSTR;
    rgc.err.data = errstr;

    if (ngx_regex_compile(&rgc) != NGX_OK) {
        ngx_destroy_pool(pool);
        printf("not matched\n");
        return NGX_ERROR;
    }

    rc = ngx_regex_exec(rgc.regex, &unparsed_uri, captures, (1 + 2) * 3);

    if (rc >= 0) {
        int capture_start = captures[2];
        int capture_end   = captures[3];
        int capture_len   = capture_end - capture_start;
        define_pattern_s  = ngx_pcalloc(pool, capture_len + 1);
        if (define_pattern_s == NULL) {
            ngx_destroy_pool(pool);
            return NGX_ERROR;
        }
        ngx_cpystrn(define_pattern_s, unparsed_uri.data + capture_start, capture_len + 1);
        printf("matched:%s\n", define_pattern_s);
    } else {
        ngx_destroy_pool(pool);
        return NGX_ERROR;
    }

    ngx_destroy_pool(pool);
    return 0;
}
