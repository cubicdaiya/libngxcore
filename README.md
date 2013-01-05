#libngxcore

libngxcore is the library builded from nginx core APIs.

## Why is libngxcore needed?

nginx has a powerful core APIs. but they is not used outside nginx.
If we write a nginx module, we must build a nginx module with nginx.
This way is a pain when we try as quick. libngxcore simplify to try nginx core APIs.


For example, Let's try the nginx string API with libngxcore.

```c
#include <stdio.h>

#include <nginx.h>
#include <ngx_core.h>
#include <ngx_string.h>

int main (int argc, char *argv[]) {
    ngx_str_t s = ngx_string("bokko");

    printf("s            :%s\n",  s.data);             // bokko
    printf("ngx_strlen(s):%ld\n", ngx_strlen(s.data)); // 5

    return 0;
}
```

Use examples as a reference about Building.

## Build libngxcore.a

```
$ scons
```

## Build examples

```
$ cd examples && scons
```
