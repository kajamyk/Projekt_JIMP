
game: main.o game_of_life.o world.o generate_image.o
	$(CC) -ansi -o bin/$@ $^ -lm


world.o: world.h world.c
game_of_life.o: game_of_life.h game_of_life.c
main.o: world.o game_of_life.o generate_image.o main.c
generate_image.o: generate_image.h generate_image.c


.PHONY: clean

