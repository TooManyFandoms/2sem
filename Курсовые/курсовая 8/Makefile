CC=gcc
LD=gcc

CFLAGS=-std=c99 -pedantic -Wall
LDFLAGS=

OBJ=main.o list.o
PROG=main

build=$(PROG)

$(PROG): $(OBJ)
		$(LD) $(LDFLAGS) $(OBJ) -o $(PROG)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

main.o: list.h

list.o: list.h

clean:
		rm $(PROG) $(OBJ)
