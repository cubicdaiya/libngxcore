#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void list_test001(void)
{
    ngx_pool_t *pool;
    ngx_list_t *list;
    ngx_list_part_t *part;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *p;
    size_t i, c;

    c    = sizeof(a) / sizeof(int);
    pool = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    if (pool == NULL) {
        CU_FAIL_FATAL("ngx_create_pool() failed.");
    }
    list = ngx_list_create(pool, 10, sizeof(int));
    if (list == NULL) {
        CU_FAIL_FATAL("ngx_list_create() failed.");
    }

    for (i=0;i<c;i++) {
        p  = ngx_list_push(list);
        if (p == NULL) {
            CU_FAIL_FATAL("ngx_list_push() failed.");
        }
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
        CU_ASSERT_EQUAL_FATAL(i + 1, p[i]);
    }

    ngx_destroy_pool(pool);
}
