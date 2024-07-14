#!/bin/bash
gcc fcgi.c -lfcgi -o hello_fcgi
spawn-fcgi -a 127.0.0.1 -p 8080 -f -n hello_fcgi
nginx -g 'daemon off;'