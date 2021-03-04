#ifndef _WORLD_H_
#define _WORLD_H_

#include <stdio.h>
#include <stdlib.h>

struct World {
    int w;
    int h;
    int ** cells;
};

struct World *create_world ( FILE * in );

#endif
