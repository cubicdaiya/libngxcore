#include <stdio.h>

#include <ngx_core.h>
#include <ngx_file.h>
#include <ngx_palloc.h>
#include <ngx_string.h>

int main (int argc, char *argv[])
{
    ngx_int_t rc;
    ngx_str_t s = ngx_string("tmp");
    ngx_pool_t *pool;
    ngx_temp_file_t *tf;
    ngx_path_t *path;

    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    if (pool == NULL) {
        perror("ngx_create_pool() failed.");
        return 1;
    }

    tf = ngx_pcalloc(pool, sizeof(ngx_temp_file_t));
    if (tf == NULL) {
        perror("ngx_pcalloc() failed.");
        return 1;
    }
    path = ngx_pcalloc(pool, sizeof(ngx_path_t));
    if (path == NULL) {
        perror("ngx_pcalloc() failed.");
        return 1;
    }
    path->name = s;

    tf->file.fd  = NGX_INVALID_FILE;
    tf->file.log = NULL;
    tf->path     = path;
    tf->pool     = pool;

    rc = ngx_create_temp_file(&tf->file, tf->path, tf->pool, 1, 0, 0600);
    if (rc == NGX_ERROR) {
        perror("ngx_create_temp_file() failed.");
        return 1;
    }
    rc = ngx_close_file(tf->file.fd);
    if (rc == NGX_FILE_ERROR) {
        perror("ngx_close_file() failed.");
        return 1;
    }
    printf("%s\n", tf->file.name.data);

    rc = ngx_delete_file(tf->file.name.data);
    if (rc == NGX_FILE_ERROR) {
        perror("ngx_delete_file() failed.");
        return 1;
    }

    return 0;
}
