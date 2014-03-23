# -*- coding: utf-8 -*-

import sys
import re

def buildLibNgxcore(env, target, src):
    if sys.platform == 'darwin':
        env.SharedLibrary(target, src)
    elif re.search('linux', sys.platform) != None:
        env.StaticLibrary(target, src)
    else:
        print sys.platform + " is not supported"
        sys.exit(1)
