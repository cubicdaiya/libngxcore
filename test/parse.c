#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void parse_test001(void)
{
    ngx_str_t size_s = ngx_string("10M");
    ssize_t size = ngx_parse_size(&size_s);
    if (size == NGX_ERROR) {
        CU_FAIL_FATAL("ngx_parse_size() failed.");
    }

    CU_ASSERT_EQUAL(10485760, size);
}
