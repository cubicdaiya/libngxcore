#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_string.h>
#include <ngx_parse.h>

int main (int argc, char *argv[]) {
    ngx_str_t size_s = ngx_string("10M");

    printf("parse size:%zd\n", ngx_parse_size(&size_s));

    return 0;
}

