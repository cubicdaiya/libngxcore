#include <stdio.h>

#include <ngx_core.h>
#include <ngx_file.h>
#include <ngx_palloc.h>
#include <ngx_string.h>

int main (int argc, char *argv[]) {
    ngx_str_t s = ngx_string("tmp");
    ngx_pool_t *pool;
    ngx_temp_file_t *tf;
    ngx_path_t *path;

    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);

    tf = ngx_pcalloc(pool, sizeof(ngx_temp_file_t));
    path = ngx_pcalloc(pool, sizeof(ngx_path_t));
    path->name = s;

    tf->file.fd  = NGX_INVALID_FILE;
    tf->file.log = NULL;
    tf->path     = path;
    tf->pool     = pool;

    ngx_create_temp_file(&tf->file, tf->path, tf->pool, 1, 0, 0600);
    ngx_close_file(tf->file.fd);
    printf("%s\n", tf->file.name.data);

    ngx_delete_file(tf->file.name.data);

    return 0;
}
