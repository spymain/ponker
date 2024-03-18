#include <stdlib.h>
#include <time.h>

#include "cards.h"

void init_deck(int8_t deck[DECK_AMOUNT]){

    srand(time(NULL));

    for(int i = 0; i < DECK_AMOUNT; i++)
        deck[i] = i;

    shuffle_deck(deck);
}

void shuffle_deck(int8_t deck[DECK_AMOUNT]){
    for(int i = 0; i < DECK_AMOUNT - 1; i++)
        swap_int8_t(
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

int8_t card_cmp(int8_t a, int8_t b){
    int8_t
        diff =
            (a % CARDS_IN_SUITE) -
            (b % CARDS_IN_SUITE);

    return
        diff ?
        diff :
        a - b;
}

void swap_int8_t(int8_t *a, int8_t *b){
    if(a == b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
