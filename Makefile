# Blah, makefile?

tester: test.c main.c
	gcc -O -Wall -c main.c
	gcc -O -Wall -c test.c
	gcc -o Test test.o main.o
