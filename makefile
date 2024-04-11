all: LIST EXEC
liste.o: liste.c liste.h
	gcc -c liste.c -Wall
main.o: main.c liste.h
	gcc -c main.c -Wall
LIST: main.o liste.o
	gcc -o LIST main.o liste.o -Wall

EXEC:
	./LIST