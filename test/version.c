#include <nginx.h>
#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void version_test001(void)
{
    ngx_str_t s = ngx_string(NGINX_VERSION);
    CU_ASSERT_STRING_EQUAL("1.7.4", s.data);
}
