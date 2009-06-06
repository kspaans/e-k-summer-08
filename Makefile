CC = gcc
CFLAGS = -ansi -pedantic -Wall

#.o.c:

Test: test.o main.o dict.o
	gcc $(CFLAGS) -O -o $@ $^

debug: test.c main.c dict.c
	gcc $(CFLAGS) -DDEBUG -g -o $@ dict.c test.c main.c
