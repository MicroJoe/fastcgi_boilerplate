# FastCGI test program

This is a simple program which aims to test FastCGI configuration and to be
used as a base architecture for C FastCGI applications.

## Installing FastCGI

You will need to download, compile and install FastCGI on your computer. Since
there are not many compiled versions of this, I personally recommend you to
build it from source.

Simply download [FastCGI source code from official website](http://fastcgi.com/dist/fastcgi.tar.gz)
and run the following commands :

    $ tar -xzvf fastcgi.tar.gz
    $ cd fcgi-2.x.x-SNAP-xxxxxxxxxx
    $ ./configure
    $ make
    $ sudo make install

But before running `make`, the source code needs to be applied the following
patch in order to compile (2014/05/14) :

    --- include/fcgio.h 2012-01-23 15:23:51.136063795 +0000
    +++ include/fcgio.h 2012-01-23 15:22:19.057221383 +0000
    @@ -31,6 +31,7 @@
     #define FCGIO_H

     #include <iostream>
    +#include <stdio.h>

     #include "fcgiapp.h"

[Source](http://stackoverflow.com/questions/4577453/fcgio-cpp50-error-eof-was-not-declared-in-this-scope).

## Other requirements

This configuration uses the popular `spawn-fcgi` tool in order to start the
application. You can then use a FastCGI capable proxy such as NGinx to serve
the app.

This program was successfully tested under NGinx with the following
configuration :

    server {
        listen 80 default_server;
        server_name localhost;

        location ~ $ {
            root /home/microjoe/dev/fastcgi_test/;
            fastcgi_pass 127.0.0.1:9000;
            include fastcgi_params;
        }
    }

## Building

Simply run `make`. If gcc complains about not finding the FastCGI library
because you installed it by hand, simply run the following instructions
instead :

    $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/
    $ make

## Use in production

This software configuration was not secured for production use. Please secure
your application and server configuration before putting it in a production
environment.

## Copyright

This project is brought to you under WTFPL. For further informations, please
read the COPYING file.
