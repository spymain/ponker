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
#include "nibble.h"
#include "cards.h"

/*
 * @brief copy face value and suite of given card to a char buffer
 * @param card_t card value to parse
 * @param char *buff buffer to copy name to
 * @param int len max buff size to print name to
 * (should be NAME_MAX_LEN)
 */
char *card_name(card_t card, char* buff, int len){
    memset(
            buff,
            0,
            len
        );

    snprintf(
        buff,
        len,
        "%s of %s",
        cards[
            card % CARDS_IN_SUITE
        ],
        suites[
            (card / CARDS_IN_SUITE) % SUITES_AMOUNT
        ]
    );

    return buff;
}

/*
 * @brief sequentially print names of cards in an array
 *
 * @param card_t *deck list to print
 * @param int len amount of cards to print
 */
void print_cards(card_t *deck, int len){
    char buff[NAME_MAX_LEN];

    for(int i = 0; i < len; i++){
        card_name(
                deck[i],
                buff,
                NAME_MAX_LEN
            );

        /// Regular Print
        //puts(buff);
        //*
        /// Debug print
        printf(
                "%i:\t%s\t%s(%i)\n",
                i,
                buff,
                /// The text can be less than 16 but not less than 8;
                /// This keeps the card values in line with each other.
                strlen(buff) < 16 ? "\t" : "",
                deck[i]
            );//*/
    }
}

/*
 * @brief translates a hand encoding to text and prints it.
 *
 * @param hand_t hand the encoding to translate
 */
void print_hand(hand_t hand){
    int
        rank = hand >> RANK_NIB * NIB_BITS,
        card = nibble_read(
                        hand,
                        HOLE_NIB
                    );
    printf(
            "%s %s%s\n",
            hands[rank],
            cards[card],
            card == 4 ? "es" :
            rank == 0 ? ""   : "s"
        );
}
