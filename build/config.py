# -*- coding: utf-8 -*-

TARGET = 'ngxcore'

CFLAGS = [
    '-g',
    #'-O2',
    '-Wall',
    '-Wno-deprecated-declarations',
    '-Wno-unused-parameter',
]

CPPPATH = [
    'src/os/unix',
    'src/auto',
    'src/event',
    'src/http/modules',
    'src/http',
    'src/core',
]

LIBS = [
    'pcre',
    'ssl',
    'crypto',
    'z',
]
