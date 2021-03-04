#include "generate_gif.h"

int frame_length = 50;  // dlugosc 1 klatki w 10*ms

ge_GIF *new_gif ( struct World *world ){
    ge_GIF *gif = ge_new_gif(
        "gif.gif",
        world->w,
        world->h,
        (uint8_t []) { // paleta kolorow
            0x00, 0x00, 0x00, // 0 - czarny
            0xFF, 0xFF, 0xFF, // 1 - bialy
        },
        1,  // glebia kolorow == log2(liczba kolorow)
        0   // liczba petli gifa, 0 dla nieskonczonosci
    );

    add_frame( world, gif ); // dodaj pierwsza klatke (stan poczatkowy planszy)

    return gif;
}

void add_frame( struct World *world , ge_GIF * gif){

    // dodawanie pixeli do nastepnej klatki
    for(int i = 0; i < world->w*world->h; i++){
        gif->frame[i] = world->cells[i];
    }

    ge_add_frame(gif, frame_length);
}

void save_gif( ge_GIF *gif ){
    ge_close_gif( gif );
}