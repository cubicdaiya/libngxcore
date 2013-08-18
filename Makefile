
NGINX_VERSION=1.4.2
OPENSSL_VERSION=1.0.1e
SCONS_JOBS=1

all: libngxcore.a

prepare_ngxcore:
	rm -rf work
	mkdir work
	cd work && wget http://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz && tar zxvf openssl-${OPENSSL_VERSION}.tar.gz
	cd work && wget http://nginx.org/download/nginx-${NGINX_VERSION}.tar.gz && tar zxvf nginx-${NGINX_VERSION}.tar.gz
	cd work/nginx-${NGINX_VERSION} && ./configure --with-pcre --with-http_spdy_module --with-openssl=../openssl-${OPENSSL_VERSION}
	cp -r work/nginx-${NGINX_VERSION}/objs/ngx_auto_config.h src/auto/
	cp -r work/nginx-${NGINX_VERSION}/objs/ngx_auto_headers.h src/auto/
	cp -r work/nginx-${NGINX_VERSION}/objs/ngx_modules.c src/auto/
	# uncomment following when install latest version
	# cp -r work/nginx-${NGINX_VERSION}/src/core/* src/core/
	# cp -r work/nginx-${NGINX_VERSION}/src/event/* src/event/
	# cp -r work/nginx-${NGINX_VERSION}/src/http/* src/http/
	# cp -r work/nginx-${NGINX_VERSION}/src/os/unix/* src/os/unix/
	# @echo "remove main function in src/core/nginx.c!"

libngxcore.a: prepare_ngxcore
	scons -j ${SCONS_JOBS}

clean:
	scons -c
	rm -rf work
