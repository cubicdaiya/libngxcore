#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_sha1.h>

int main (int argc, char *argv[])
{
    ngx_int_t i;
    ngx_sha1_t   sha1;
    u_char *p, sha1_buf[20], sha1_dump_buf[40];
    ngx_str_t s = ngx_string("bokko");

    memset(sha1_buf,      0, 20);
    memset(sha1_dump_buf, 0, 40);

    ngx_sha1_init(&sha1);
    ngx_sha1_update(&sha1, s.data, s.len);
    ngx_sha1_final(sha1_buf, &sha1);

    p = sha1_dump_buf;
    p = ngx_hex_dump(p, sha1_buf, 20);
    for (i=0;i<40;i++) {
        printf("%c", sha1_dump_buf[i]);
    }
    printf("\n");

    return 0;
}
