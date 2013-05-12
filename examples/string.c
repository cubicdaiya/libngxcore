#include <stdio.h>

#include <ngx_core.h>
#include <ngx_string.h>

int main (int argc, char *argv[])
{
    ngx_str_t s = ngx_string("bokko");

    printf("s            :%s\n",  s.data);
    printf("ngx_strlen(s):%ld\n", ngx_strlen(s.data));

    return 0;
}
