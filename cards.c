#include <stdlib.h>
#include <time.h>

#include "cards.h"

void init_deck(uint8_t deck[DECK_AMOUNT]){

    srand(time(NULL));

    for(int i = 0; i < DECK_AMOUNT; i++)
        deck[i] = i;

    shuffle_deck(deck);
}

void shuffle_deck(uint8_t deck[DECK_AMOUNT]){
    for(int i = 0; i < DECK_AMOUNT - 1; i++)
        swap_uint8_t(
                &deck[i],
                &deck[
                    i +
                    rand() % (
                        DECK_AMOUNT -
                        i
                    )
                ]
            );
}

void swap_uint8_t(uint8_t *a, uint8_t *b){
    if(a == b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
