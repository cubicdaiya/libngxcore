#include <stdio.h>
#include <nginx.h>
#include <ngx_core.h>
#include <ngx_string.h>

int main (int argc, char *argv[])
{
    printf("nginx version:%s\n", NGINX_VERSION);
    return 0;
}
