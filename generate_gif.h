#ifndef _generate_image_h_
#define _generate_image_h_

#include <stdio.h>
#include <string.h>

#include "world.h"
#include "gifenc.h"


ge_GIF *new_gif ( struct World *world );

void add_frame( struct World *world , ge_GIF * gif);

void save_gif( ge_GIF *gif );

#endif