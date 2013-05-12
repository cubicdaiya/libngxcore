#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>

int main (int argc, char *argv[])
{
    time_t now;
    u_char http_buf[BUFSIZ];
    u_char cookie_buf[BUFSIZ];

    ngx_time_init();

    now = ngx_time();
    ngx_http_time(http_buf, now);
    ngx_http_cookie_time(cookie_buf, now);

    printf("current timestamp:%zu\n", now);
    printf("http   time:%s\n", http_buf);
    printf("cookie time:%s\n", cookie_buf);

    sleep(10);
    ngx_time_update();
    now = ngx_time();
    ngx_http_time(http_buf, now);
    ngx_http_cookie_time(cookie_buf, now);
    printf("current timestamp:%zu\n", now);
    printf("http   time:%s\n", http_buf);
    printf("cookie time:%s\n", cookie_buf);
    
    return 0;
}
