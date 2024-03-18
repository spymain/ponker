/*
 * @file main.c
 * @author fredstoller
 * @date 3-18-24
 *
 * @brief Poker program
 */
#include <stdio.h>
#include "cards.h"
#include "textinterface.h"

#include "string.h"

#define BUFF_LEN 18

/*
 * @brief currently a unit test
 *
 * Create a deck of cards,
 * Shuffle it,
 * print the names of each card in their current order,
 * along with the number representing that card.
 * Then,
 * take the top two cards and print which card is higher.
 */
int main(void){
    //*
    char buff[2][BUFF_LEN];
    memset(
            buff,
            0,
            sizeof(char)*2*BUFF_LEN
        );

    int8_t deck[DECK_AMOUNT];
    init_deck(deck);

    for(int i = 0; i < DECK_AMOUNT; i++){
        card_name(
                deck[i],
                buff[0],
                BUFF_LEN
            );

        printf(
                "%i:\t%s\t%s(%i)\n",
                i,
                buff[0],
                strlen(buff[0]) < 16 ? "\t" : "",
                deck[i]
            );
    }
    //*
    printf(
            "%s is %s than %s\n",
            card_name(
                deck[0],
                buff[0],
                BUFF_LEN
            ),
            card_cmp(deck[0], deck[1]) > 0 ? "greater" : "lesser",
            card_name(
                deck[1],
                buff[1],
                BUFF_LEN
            )
        );
    //*/

    return 0;
}
