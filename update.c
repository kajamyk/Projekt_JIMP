#include <stdio.h>
void update (  int a, int b, int tab[a][b], FILE *in ) {
	for ( int i = 0; i < a; i++ ) {
		for ( int j = 0; j< b; j++ ) {
			fscanf ( in, "%d", &tab[i][j] );
			printf ("%d ", tab[i][j]);
		}
	}
}
