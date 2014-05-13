EXEC=test
SRC=main.c
CFLAGS=-Wall -Wextra
LDFLAGS=-lfcgi
HOST=127.0.0.1
PORT=9000

all: $(SRC)
	gcc -o $(EXEC) $(SRC) $(LDFLAGS) $(CFLAGS)

server:
	spawn-fcgi -a$(HOST) -p$(PORT) -n $(EXEC)
