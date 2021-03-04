#include "game_of_life.h"
/*
 * 0 - dead	
 * 1 - alive
 * 2 - born 
 * 3 - died
*/

void fix_world(struct World * world){
    int i, j;

    for(i = 0; i < world->w; i++){
        for(j = 0; j < world->h; j++){
            if(world->cells[i][j] == 2)
                world->cells[i][j] = 1;
            else if(world->cells[i][j] == 3)
                world->cells[i][j] = 0;
        }
    }
}

int count_alive_neighbours(struct World * world, int x, int y){
    int alive = 0, i, j;

    for(i = 0; i < x; i++){
        for(j = 0; j < y; j++){
            if( x >= 0 && x < world->w && y >= 0 && y < world->h && (x != i || y != j)){
                if(world->cells[x][y] == 1 || world->cells[x][y] == 3)
                    alive++;
            }

        }
    }
}

void update(struct World *world){
    int i, j, alive;

    for(i = 0; i < world->w; i++){
        for(j = 0; j < world->h; j++){
            alive = count_alive_neighbours(world, i, j);
            if(world->cells[i][j] == 1 && alive != 2 && alive != 3)
                world->cells[i][j] = 3;
            else if( world->cells[i][j] == 0 && alive == 3)
                world->cells[i][j] = 2;
        }
    }

    fix_world(world);
}

int game_of_life( struct World *world, int iterations){
    int i = 0;
    
    generate_image( world );
    for( i = 0; i < iterations; i++){
        update( world );
        generate_image( world );

        printWorld( world ); // debug
    }

    return 0;
}





