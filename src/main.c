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
 * draw 7 cards,
 * call 2 "Hole Cards,"
 * the rest "Board Cards,"
 * evaluate strongest hand.
 */
int main(void){
    int8_t
        deck[DECK_AMOUNT];
    init_deck(deck);

    sort_cards(deck, HOLE_CARDS);
    sort_cards(deck + HOLE_CARDS, BOARD_CARDS);

    puts("Hole:");
        print_cards(deck,HOLE_CARDS);
    puts("\nBoard:");
    print_cards(deck + HOLE_CARDS, BOARD_CARDS);

    puts("");
    print_hand(
            encode_hand(deck, TOTAL_CARDS)
        );

    return 0;
}
