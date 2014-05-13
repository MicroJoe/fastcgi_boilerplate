# FastCGI test program

This is a simple program which aims to test FastCGI configuration and to be
used as a base architecture for C FastCGI applications.

## Requirements

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

## Use in production

This software configuration was not secured for production use. Please secure
your application and server configuration before putting it in a production
environment.

## Copyright

This project is brought to you under WTFPL. For further informations, please
read the COPYING file.
