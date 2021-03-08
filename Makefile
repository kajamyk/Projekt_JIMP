
game: main.o game_of_life.o world.o generate_gif.o gifenc.o
	$(CC) -ansi -o bin/$@ $^ -lm


world.o: world.h world.c
game_of_life.o: game_of_life.h game_of_life.c
main.o: world.o game_of_life.o generate_gif.o gifenc.o main.c
generate_gif.o: generate_gif.h generate_gif.c
gifenc.o: gifenc.h gifenc.c


.PHONY: clean

