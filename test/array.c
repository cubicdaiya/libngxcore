#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void array_test001(void)
{
    ngx_pool_t  *pool;
    ngx_array_t *array;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int i, c, *p;

    c     = sizeof(a) / sizeof(int);
    pool  = ngx_create_pool(NGX_DEFAULT_POOL_SIZE, NULL);
    array = ngx_array_create(pool, c, sizeof(int));

    for (i=0;i<c;i++) {
        p = ngx_array_push(array);
        if (p == NULL) {
            CU_FAIL_FATAL("ngx_array_push() failed.");
        }
        *p = a[i];
    }

    {
        int *elts = array->elts;
        int i, n;
        n = array->nelts;
        for (i=0;i<n;i++) {
            CU_ASSERT_EQUAL_FATAL(i + 1, elts[i]);
        }
    }

    ngx_array_destroy(array);
    ngx_destroy_pool(pool);
}
