#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_string.h>
#include <ngx_parse.h>

int main (int argc, char *argv[])
{
    ngx_str_t size_s = ngx_string("10M");
    ssize_t size = ngx_parse_size(&size_s);
    if (size == NGX_ERROR) {
        perror("ngx_parse_size() failed.");
        return 1;
    }

    printf("parse size:%zd\n", size);

    return 0;
}
