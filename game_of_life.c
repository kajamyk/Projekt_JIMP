#include "game_of_life.h"
/*
 * 0 - dead	
 * 1 - alive
 * 2 - born 
 * 3 - died
*/

void fix_world(struct World * world){
    int i, j;

    for(i = 0; i < world->h; i++){
        for(j = 0; j < world->w; j++){
            if(world->cells[i*world->w + j] == 2)
                world->cells[i*world->w + j] = 1;
            else if(world->cells[i*world->w + j] == 3)
                world->cells[i*world->w + j] = 0;
        }
    }
}

int count_alive_neighbours(struct World * world, int x, int y){
        int alive = 0, i, j;
        for ( i = x - 1; i < x + 2; i++ ){
                for ( j = y - 1; j < y + 2; j++ ){
                        if (i >= 0 && i < world->h && j >= 0 && j < world->w && (i != x || j != y)){
                                if(world->cells[i * world->w + j] == 1 || world->cells[i * world->w + j] == 3)
                                        alive++;
                        }
                }
        }
        return alive;
}

// int count_helper ( struct World * world, int x, int y ){
//         if(world->cells[x * world->w + y] == 1 || world->cells[x * world->w + y] == 3)
//                 return 1;
//         return 0;
// }
// int count_alive_neighbours(struct World * world, int x, int y){
//         int alive = 0;
//         if ( x > 0 )
//                 alive += count_helper ( world, x - 1, y );
//         if ( x + 1 < world->h )
//                 alive += count_helper ( world, x + 1, y );
//         if ( y > 0 )
//                 alive += count_helper ( world, x, y - 1 );
//         if ( y + 1 < world->w )
//                 alive += count_helper ( world, x, y + 1 );
//         return alive;
// }

void update(struct World *world){
    int i, j, alive;

    for(i = 0; i < world->h; i++){
        for(j = 0; j < world->w; j++){
            alive = count_alive_neighbours(world, i, j);
            if(world->cells[i*world->w + j] == 1 && alive != 2 && alive != 3)
                world->cells[i*world->w + j] = 3;
            else if( world->cells[i*world->w + j] == 0 && alive == 3)
                world->cells[i*world->w + j] = 2;
        }
    }

    fix_world(world);
}

int game_of_life( struct World *world, int iterations){
    int i = 0;

    ge_GIF *gif = new_gif( world );

    for( i = 0; i < iterations; i++){
        update( world );
        add_frame( world, gif );

        // printWorld( world ); // debug
    }

    save_gif( gif );

    return 0;
}





