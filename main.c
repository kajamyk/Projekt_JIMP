#include <stdio.h>
#include <stdlib.h>

#include "world.h"
#include "game_of_life.h"



int main ( int argc, char ** argv ){

	FILE *in = argc > 1 ? fopen ( argv[1], "r" ) : NULL;
	int iterations = argc > 2 ? atoi(argv[2]) : 20;
	FILE *out = argc > 3 ? fopen ( argv[3], "w") : fopen ( "out.txt", "w");

	if ( in == NULL ) return 1;
	if ( iterations < 1 ) return 1;

	// stworz i wypelnij plansze
	struct World *world;
	if (( world = create_world ( in )) == NULL )
		return 0;

	// // debug
	// printWorld( world );

	// przeprowadz iteracje 
	game_of_life ( world, iterations );	

	// stworz plik wyjsciowy
	write_file ( out, world );


	return 0;
}
