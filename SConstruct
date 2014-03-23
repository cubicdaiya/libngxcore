# -*- coding: utf-8 -*-

import build.config
import build.src
import build.util

src = [
    Glob('src/core/*.c'),
    Glob('src/auto/*.c'),
    Glob('src/http/*.c'),
    build.src.http_modules,
    build.src.event_modules,
    build.src.events,
    build.src.systems,
]

env = Environment(
    CFLAGS=build.config.CFLAGS,
    CPPPATH=build.config.CPPPATH,
    LIBS=build.config.LIBS,
)

build.util.buildLibNgxcore(
    env,
    build.config.TARGET,
    src
)
