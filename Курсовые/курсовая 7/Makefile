CC=gcc
LD=gcc

CFLAGS=-std=c99 -pedantic -Wall
LDFLAGS=

OBJ=main.o matrix.o vector.o
PROG=main

build=$(PROG)

$(PROG): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(PROG)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

main.o: vector_dbl.h vector_int.h matrix.h

vector.o: vector_int.h vector_dbl.h

matrix.o: vector_int.h vector_dbl.h matrix.h

clean:
	rm $(PROG) $(OBJ)
