#include <stdio.h>
#include <stdlib.h>

#include "game_of_life.h"
#include "world.h"

/*
 * 0 - dead	
 * 1 - alive
 * 2 - born 
 * 3 - died
 * */

int main ( int argc, char ** argv ){
	FILE *in = fopen ( argv[1], "r" );
	int iterations = 20;

	if ( in == NULL ) return 1;

	struct World *world = create_world ( in );

	printf("%d\n", sizeof(world));
	//game_of_life ( world, a, b, iterations );	
	return 0;
}