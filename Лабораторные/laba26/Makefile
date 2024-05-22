CC = gcc
CFLAGS ?= -g -Wall -Wextra -pedantic -std=c99 -w -pipe -O3 -lm
main: main.o sdbl.o sort.o
	$(CC) -o main main.o sdbl.o sort.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sdbl.o: sdbl.c sdbl.h
	$(CC) $(CFLAGS) -c sdbl.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean:
	rm -rf *.o main
