#libngxcore

libngxcore is the library built from nginx core APIs.

## Why is libngxcore needed?

nginx has powerful core APIs. but they are not able to used outside nginx.
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
    printf("ngx_strlen(s):%zd\n", ngx_strlen(s.data)); // 5

    return 0;
}
```

Use examples as a reference about Building.

## Build libngxcore.a

```
$ make
```

## Build examples

```
$ cd examples && scons
```

## Execute examples in Mac OS X

When libngxcore is build in Mac OS X, libngxcore.dylib as not a static library but a shared library is generated.
So set DYLD_LIBRARY_PATH when executing libngxcore examples.

```
$ cd examples
$ ./string
dyld: Library not loaded: libngxcore.dylib
  Referenced from: /Users/bokko/workspace/libngxcore/examples/./string
  Reason: image not found
zsh: trace trap  ./string
$ DYLD_LIBRARY_PATH=../ ./string
s            :bokko
ngx_strlen(s):5
$
```
