CC=gcc
CFLAGS=-W	-Wall
LDFLAGS=
EXEC=ordonnanceur

all: $(EXEC)

ordonnanceur:	fonctions.o	main.o
	$(CC) -o ordonnanceur	fonctions.o main.o $(LDFLAGS)

fonctions.o: fonctions.c
	$(CC) -o fonctions.o -c fonctions.c $(CFLAGS)

main.o: main.c fonctions.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)