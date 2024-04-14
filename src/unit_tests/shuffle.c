/*
 * @file shuffle.c
 * @author fredstoller
 *
 * @brief Print cards of a shuffled deck
 */
#include "cards.h"
#include "textinterface.h"

int main(void){
    card_t deck[DECK_AMOUNT];
    init_deck(deck);

    print_cards(deck, DECK_AMOUNT);
    return 0;
}
