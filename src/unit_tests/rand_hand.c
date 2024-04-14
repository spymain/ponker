/*
 * @file rand_hand.c
 * @author fredstoller
 *
 * @brief Print a random 2 card hand and 5 card board,
 * then print best hand possible with given cards
 */
#include <stdio.h>

#include "cards.h"
#include "five_card.h"
#include "textinterface.h"

int main(void){
    card_t
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
