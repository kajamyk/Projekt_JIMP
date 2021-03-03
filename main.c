#include <stdio.h>
#include <stdlib.h>
#include "update.h"
#define iterations 30
/*
 * 0 - dead	
 * 1 - alive
 * 2 - born 
 * 3 - died
 * */
int main ( int argc, char ** argv ){
	FILE *in = argc > 2 ? fopen ( argv[1], "r" ) : stdin;
	if ( in == NULL ) return 1;
	int a, b;
	fscanf ( in, "%d %d", &a, &b );
	printf ("%d%d", a, b);
	int tab [a][b];
	update ( a, b, tab, in );
	game_of_life ( tab, a, b );	
	return 0;
}
