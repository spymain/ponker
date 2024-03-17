#include <stdio.h>
#include "textinterface.h"
#include "cards.h"

void print_card(uint8_t card){
    printf(
            "%s of %s",
            cards[
                card % CARDS_IN_SUITE
            ],
            suites[
                (card / CARDS_IN_SUITE) % SUITES_AMOUNT
            ]
        );
}
