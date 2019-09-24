

CC=gcc-mp-9
CFLAGS=-O2 -march=native -mtune=native -pipe

INSTALLPREFIX=/usr/local

all: eweniq

avl.o: avl.c avl.h
	$(CC) $(CFLAGS) -c avl.c -o avl.o 

eweniq.o: eweniq.c
	$(CC) $(CFLAGS) -c eweniq.c -o eweniq.o 

eweniq: avl.o eweniq.o
	$(CC) $(CFLAGS) -o eweniq eweniq.o avl.o


clean:
	rm -f ./*.o
	rm -f eweniq

install:
	cp eweniq $(INSTALLPREFIX)/bin/
