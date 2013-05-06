#include <stdio.h>

#include <ngx_core.h>
#include <ngx_palloc.h>
#include <ngx_string.h>

int main (int argc, char *argv[]) {
    ngx_str_t s = ngx_string("bokko");
    u_char *sp;
    ngx_pool_t *pool;
    size_t len;

    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    len  = ngx_strlen(s.data);

    sp = ngx_palloc(pool, len + 1);
    if (sp == NULL) {
        printf("alloc failed\n");
        return NGX_ERROR;
    }

    ngx_cpystrn(sp, s.data, len + 1);

    printf("sp            :%s\n",  sp);
    printf("ngx_strlen(sp):%ld\n", ngx_strlen(sp));

    ngx_destroy_pool(pool);

    return 0;
}
