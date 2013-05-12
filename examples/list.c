#include <stdio.h>
#include <ngx_core.h>
#include <ngx_palloc.h>
#include <ngx_string.h>

int main (int argc, char *argv[])
{
    ngx_pool_t *pool;
    ngx_list_t *list;
    ngx_list_part_t *part;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *p;
    size_t i, c;

    c    = sizeof(a) / sizeof(int);
    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    list = ngx_list_create(pool, 10, sizeof(int));

    for (i=0;i<c;i++) {
        p  = ngx_list_push(list);
        *p = a[i];
    }

    part = &list->part;
    p    = part->elts;
    for (i = 0 ;; i++) {
        if (i >= part->nelts) {
            if (part->next == NULL) {
                break;
            }
            part = part->next;
            p    = part->elts;
            i    = 0;
        }
        printf("%d\n", p[i]);
    }

    ngx_destroy_pool(pool);

    return 0;
}
