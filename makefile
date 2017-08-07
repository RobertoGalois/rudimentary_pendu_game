.PHONY: clean
.SUFFIXES:

Jeu: game.o main.o show.o system.o
	gcc game.o main.o show.o system.o -o Jeu
game.o: game.c system.h show.h
	gcc -c game.c
main.o: main.c show.h game.h
	gcc -c main.c
show.o: show.c show.h system.h
	gcc -c show.c
system.o: system.c
	gcc -c system.c
clean:
	rm -f *.o Jeu
