#include <ngx_core.h>
#include <ngx_sha1.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void sha1_test001(void)
{
    ngx_int_t i;
    ngx_sha1_t   sha1;
    u_char *p, sha1_buf[20], sha1_dump_buf[40];
    ngx_str_t s = ngx_string("bokko");
    char *sol = "cea3d1bca602a6017e9a02520e3d392ba6b7838d";

    ngx_memzero(sha1_buf,      20);
    ngx_memzero(sha1_dump_buf, 40);

    ngx_sha1_init(&sha1);
    ngx_sha1_update(&sha1, s.data, s.len);
    ngx_sha1_final(sha1_buf, &sha1);

    p = sha1_dump_buf;
    p = ngx_hex_dump(p, sha1_buf, 20);
    for (i=0;i<40;i++) {
        CU_ASSERT_EQUAL_FATAL(sol[i], sha1_dump_buf[i]);
    }
}
