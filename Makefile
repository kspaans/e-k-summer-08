# Blah, makefile?

Test: test.c main.c body.c
	gcc -O -Wall -c main.c
	gcc -O -Wall -c test.c
	gcc -O -Wall -c body.c
	gcc -o Test test.o main.o body.o
