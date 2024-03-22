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
    /*
    char buff[2][BUFF_LEN];
    memset(
            buff,
            0,
            sizeof(char)*2*BUFF_LEN
        );
    //*/

    int8_t deck[DECK_AMOUNT];
    init_deck(deck);

    print_deck(deck);

    return 0;
}
