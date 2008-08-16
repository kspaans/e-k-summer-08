CC = gcc
CFLAGS = -std=c99 -O -Wall

#.o.c:

Test: test.o main.o dict.o
	gcc $(CFLAGS) -o $@ $^
