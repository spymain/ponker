/*
 * @file textinterface.c
 * @author fredstoller
 *
 * @brief procedures for interfacing with the user via tty
 */
#include <stdio.h>
#include <string.h>

#include "textinterface.h"
#include "cards.h"

/*
 * @brief copy face value and suite of given card to a char buffer
 * @param int8_t card value to parse
 * @param char *buff buffer to copy name to
 */
char *card_name(int8_t card, char* buff, int len){
    int 
        cardnum     =   card % CARDS_IN_SUITE,
        suitenum    =   (card / CARDS_IN_SUITE) % SUITES_AMOUNT,
        cardlen     =   strlen(cards[cardnum]),
        suitelen    =   strlen(suites[suitenum]);

    memset(
            buff,
            0,
            len
        );

    strncpy(
            buff,
            cards[cardnum],
            cardlen
        );

    strncpy(
            buff + cardlen,
            " of ",
            5
        );

    strncpy(
            buff + cardlen + 4,
            suites[suitenum],
            suitelen
        );

    return buff;
}

void print_cards(int8_t *deck, int len){
    char buff[NAME_MAX_LEN];

    for(int i = 0; i < len; i++){
        card_name(
                deck[i],
                buff,
                NAME_MAX_LEN
            );

        printf(
                "%i:\t%s\t%s(%i)\n",
                i,
                buff,
                /// The text can be less than 16 but not less than 8;
                /// This keeps the card values in line with each other.
                strlen(buff) < 16 ? "\t" : "",
                deck[i]
            );
    }
}
