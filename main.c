#include <stdio.h>
#include "cards.h"
#include "textinterface.h"

int main(void){
    uint8_t deck[DECK_AMOUNT];
    init_deck(deck);

    for(int i = 0; i < DECK_AMOUNT; i++){
        printf("%i:\t",i);
        print_card(deck[i]);
        printf("\t\t(%i)\n", deck[i]);
    }

    puts("");
    return 0;
}
