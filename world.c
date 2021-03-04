#include "world.h"

void read_file( FILE * in, struct World *world){
	int i;

	fscanf( in, "%d %d", &world->w, &world->h);

	// alokowanie pamieci na plansze
	world->cells = malloc( world->w * world->h * sizeof world->cells);
	
	// uzupelnianie tablicy 
	for ( i = 0; i < world->w; i++ ) {
		for ( int j = 0; j < world->h; j++ ) {
			fscanf ( in, "%d", &world->cells[i*world->w + j] );
		}
	}
}

struct World *create_world ( FILE *in ) {

	struct World *world = malloc(sizeof(struct World));

	read_file(in, world);

	return world;
}

void printWorld ( struct World *world) {
	int i;
	printf("\n");
	for ( i = 0; i < world->w; i++ ) {
		for ( int j = 0; j < world->h; j++ ) {
			printf ("%d ", world->cells[i*world->w + j]);
		}
		printf("\n");
	}
}

void write_file( FILE * out, struct World * world){
	// TODO
}