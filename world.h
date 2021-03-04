#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 

struct World {
    int w;
    int h;
    int * cells;
};

struct World *create_world ( FILE * in );

void printWorld ( struct World *world );

void write_file( FILE * out, struct World * world);

#endif
