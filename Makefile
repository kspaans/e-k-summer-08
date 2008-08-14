CC = gcc
CFLAGS = -O -Wall

#.o.c:

Test: test.o main.o dict.o
	gcc $(CFLAGS) -o $@ $^
