#include <ngx_core.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void time_test001(void)
{
    time_t now;
    u_char http_buf[sizeof("Thu, 14 Aug 2014 23:02:53 GMT") - 1];
    u_char cookie_buf[BUFSIZ];

    // TODO: move setup().
    ngx_time_init();

    now = 1408024973;
    ngx_http_time(http_buf, now);
    ngx_http_cookie_time(cookie_buf, now);

    CU_ASSERT_NSTRING_EQUAL(
        "Thu, 14 Aug 2014 14:02:53 GMT",
        http_buf,
        sizeof("Thu, 14 Aug 2014 23:02:53 GMT") - 1
    );

    CU_ASSERT_NSTRING_EQUAL(
        "Thu, 14-Aug-14 14:02:53 GMT",
        cookie_buf,
        sizeof("Thu, 14-Aug-14 14:02:53 GMT") - 1
    );
}
