#ifndef _game_of_life_h_
#define _game_of_life_h_

#include <stdio.h>
#include <stdlib.h>
#include "world.h"
#include "generate_image.h"

int game_of_life( struct World *world, int iterations);

#endif