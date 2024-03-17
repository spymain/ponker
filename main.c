#include <stdio.h>
#include "cards.h"

int main(void){
    uint8_t deck[DECK_AMOUNT];
    init_deck(deck);

    for(int i = 0; i < DECK_AMOUNT; i++)
        printf(
                "%i, ",
                deck[i]
            );

    puts("");
    return 0;
}
