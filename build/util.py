# -*- coding: utf-8 -*-

import sys
import re
import build.src

def isMac():
    if sys.platform == 'darwin':
        return True
    return False

def isLinux():
    if re.search('linux', sys.platform) != None:
        return True
    return False

def isSupportPlatform():
    if isMac() or isLinux():
        return True
    return False

def assertSupportPlatform():
    if isSupportPlatform() is False:
        print sys.platform + " is not supported"
        sys.exit(1)

def buildLibNgxcore(env, target, src):
    if isMac():
        env.SharedLibrary(target, src)
    elif isLinux():
        env.StaticLibrary(target, src)

def appendPlatformDependentSrc():
    if isMac():
        build.src.event_modules.append('src/event/modules/ngx_kqueue_module.c')
        build.src.systems.append('src/os/unix/ngx_darwin_init.c')
        build.src.systems.append('src/os/unix/ngx_darwin_sendfile_chain.c')
    elif isLinux():
        build.src.event_modules.append('src/event/modules/ngx_epoll_module.c')
        build.src.systems.append('src/os/unix/ngx_linux_init.c')
        build.src.systems.append('src/os/unix/ngx_linux_sendfile_chain.c')
