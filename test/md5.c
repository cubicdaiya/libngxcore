#include <ngx_core.h>
#include <ngx_md5.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void md5_test001(void)
{
    ngx_int_t i;
    ngx_md5_t md5;
    u_char *p, md5_buf[16], md5_dump_buf[32];
    ngx_str_t s = ngx_string("bokko");
    char *sol = "fe9749f7f1d1c8ec7f6ddd1f0521cdb0";

    ngx_md5_init(&md5);
    ngx_md5_update(&md5, s.data, s.len);
    ngx_md5_final(md5_buf, &md5);

    p = md5_dump_buf;
    p = ngx_hex_dump(p, md5_buf, 16);
    for (i=0;i<32;i++) {
        CU_ASSERT_EQUAL_FATAL(sol[i], md5_dump_buf[i]);
    }

}
