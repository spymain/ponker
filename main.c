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

#define BUFF_LEN 18

/*
 * @brief currently a unit test
 *
 * Shuffle deck, print, then sort and print
 */
int main(void){
    int8_t deck[DECK_AMOUNT];
    init_deck(deck);

    //*
    print_cards(deck, DECK_AMOUNT);

    sort_cards(deck, DECK_AMOUNT);
    puts("\n\nSorted:");

    print_cards(deck, DECK_AMOUNT);
    //*/

    return 0;
}
