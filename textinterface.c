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
