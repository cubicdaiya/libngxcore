# -*- coding: utf-8 -*-

import sys
import re
import build.src

def assertSupportPlatform():
    if sys.platform == 'darwin' or re.search('linux', sys.platform) != None:
        return
    print sys.platform + " is not supported"
    sys.exit(1)

def buildLibNgxcore(env, target, src):
    if sys.platform == 'darwin':
        env.SharedLibrary(target, src)
    elif re.search('linux', sys.platform) != None:
        env.StaticLibrary(target, src)

def appendEnvDependentSrc():
    if sys.platform == 'darwin':
        build.src.event_modules.append('src/event/modules/ngx_kqueue_module.c')
        build.src.systems.append('src/os/unix/ngx_darwin_init.c')
        build.src.systems.append('src/os/unix/ngx_darwin_sendfile_chain.c')
    elif re.search('linux', sys.platform) != None:
        build.src.event_modules.append('src/event/modules/ngx_epoll_module.c')
        build.src.systems.append('src/os/unix/ngx_linux_init.c')
        build.src.systems.append('src/os/unix/ngx_linux_sendfile_chain.c')
