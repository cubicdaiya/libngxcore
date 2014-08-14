#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void crc32_test001(void)
{
    uint32_t crc32;
    ngx_str_t s = ngx_string("bokko");

    ngx_crc32_init(crc32);
    ngx_crc32_update(&crc32, s.data, s.len);
    ngx_crc32_final(crc32);

    CU_ASSERT_EQUAL(1494474241, crc32);
    CU_ASSERT_EQUAL(1494474241, ngx_crc32_long(s.data, ngx_strlen(s.data)));
}
