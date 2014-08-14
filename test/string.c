#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void string_test001(void)
{
    ngx_str_t s = ngx_string("bokko");
    CU_ASSERT_STRING_EQUAL("bokko", s.data);
    CU_ASSERT_EQUAL(5, ngx_strlen(s.data));
}
