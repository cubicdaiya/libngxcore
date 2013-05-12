#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_crc32.h>

int main (int argc, char *argv[])
{
    uint32_t crc32;
    ngx_str_t s = ngx_string("bokko");

    ngx_crc32_init(crc32);
    ngx_crc32_update(&crc32, s.data, s.len);
    ngx_crc32_final(crc32);

    printf("%d\n", crc32);
    printf("ngx_crc32_long(%s, ngx_strlen(%s)) = %d\n", 
           s.data, s.data, ngx_crc32_long(s.data, ngx_strlen(s.data)));

    return 0;
}
