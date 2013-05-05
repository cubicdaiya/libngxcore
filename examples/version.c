#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_string.h>

int main (int argc, char *argv[]) {
    ngx_str_t s = ngx_string(NGINX_VERSION);

    printf("nginx version:%s\n", s.data);

    return 0;
}

