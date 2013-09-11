# -*- coding: utf-8 -*-

import sys
import re

http_modules = [
    'src/http/modules/ngx_http_log_module.c',
    'src/http/modules/ngx_http_static_module.c',
    'src/http/modules/ngx_http_autoindex_module.c',
    'src/http/modules/ngx_http_index_module.c',
    'src/http/modules/ngx_http_auth_basic_module.c',
    'src/http/modules/ngx_http_access_module.c',
    'src/http/modules/ngx_http_limit_conn_module.c',
    'src/http/modules/ngx_http_limit_req_module.c',
    'src/http/modules/ngx_http_geo_module.c',
    'src/http/modules/ngx_http_map_module.c',
    'src/http/modules/ngx_http_split_clients_module.c',
    'src/http/modules/ngx_http_referer_module.c',
    'src/http/modules/ngx_http_rewrite_module.c',
    'src/http/modules/ngx_http_proxy_module.c',
    'src/http/modules/ngx_http_fastcgi_module.c',
    'src/http/modules/ngx_http_uwsgi_module.c',
    'src/http/modules/ngx_http_scgi_module.c',
    'src/http/modules/ngx_http_memcached_module.c',
    'src/http/modules/ngx_http_empty_gif_module.c',
    'src/http/modules/ngx_http_browser_module.c',
    'src/http/modules/ngx_http_upstream_ip_hash_module.c',
    'src/http/modules/ngx_http_upstream_least_conn_module.c',
    'src/http/modules/ngx_http_upstream_keepalive_module.c',
    'src/http/modules/ngx_http_chunked_filter_module.c',
    'src/http/modules/ngx_http_gzip_filter_module.c',
    'src/http/modules/ngx_http_ssi_filter_module.c',
    'src/http/modules/ngx_http_charset_filter_module.c',
    'src/http/modules/ngx_http_userid_filter_module.c',
    'src/http/modules/ngx_http_headers_filter_module.c',
    'src/http/modules/ngx_http_not_modified_filter_module.c',
    'src/http/modules/ngx_http_range_filter_module.c',
]

event_modules = [
    'src/event/modules/ngx_select_module.c',
]

events = [
    'src/event/ngx_event_accept.c',
    'src/event/ngx_event_busy_lock.c',
    'src/event/ngx_event.c',
    'src/event/ngx_event_connect.c',
    'src/event/ngx_event_mutex.c',
    'src/event/ngx_event_pipe.c',
    'src/event/ngx_event_posted.c',
    'src/event/ngx_event_timer.c',
]

systems = [
    'src/os/unix/ngx_time.c',
    'src/os/unix/ngx_errno.c',
    'src/os/unix/ngx_alloc.c',
    'src/os/unix/ngx_files.c',
    'src/os/unix/ngx_socket.c',
    'src/os/unix/ngx_recv.c',
    'src/os/unix/ngx_readv_chain.c',
    'src/os/unix/ngx_udp_recv.c',
    'src/os/unix/ngx_send.c',
    'src/os/unix/ngx_writev_chain.c',
    'src/os/unix/ngx_channel.c',
    'src/os/unix/ngx_shmem.c',
    'src/os/unix/ngx_process.c',
    'src/os/unix/ngx_daemon.c',
    'src/os/unix/ngx_setaffinity.c',
    'src/os/unix/ngx_setproctitle.c',
    'src/os/unix/ngx_posix_init.c',
    'src/os/unix/ngx_user.c',
    'src/os/unix/ngx_process_cycle.c',
]

if sys.platform == 'darwin':
    event_modules.append('src/event/modules/ngx_kqueue_module.c')
    systems.append('src/os/unix/ngx_darwin_init.c')
    systems.append('src/os/unix/ngx_darwin_sendfile_chain.c')
elif re.search('linux', sys.platform) != None:
    event_modules.append('src/event/modules/ngx_epoll_module.c')
    systems.append('src/os/unix/ngx_linux_init.c')
    systems.append('src/os/unix/ngx_linux_sendfile_chain.c')
else:
    print sys.platform + " is not supported"
    sys.exit(1)

src = [
    Glob('src/core/*.c'),
    Glob('src/auto/*.c'),
    Glob('src/http/*.c'),
    http_modules,
    event_modules,
    events,
    systems,
]

target = 'ngxcore'

env = Environment(
    CFLAGS=[
        '-g',
        #'-O2',
        '-Wall',
    ],
    CPPPATH=[
        'src/os/unix',
        'src/auto',
        'src/event',
        'src/http/modules',
        'src/http',
        'src/core',
    ],
    LIBS=[
        'pcre',
        'ssl',
        'crypto',
        'z',
        ],
)

if sys.platform == 'darwin':
    env.SharedLibrary(target, src)
elif re.search('linux', sys.platform) != None:
    env.StaticLibrary(target, src)
else:
    print sys.platform + " is not supported"
    sys.exit(1)
