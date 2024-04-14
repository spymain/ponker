/*
 * @file best_hand.c
 * @author fredstoller
 *
 * @brief Input integers as cards,
 * then print cards and best hand possible from cards
 * (not input safe)
 */
#include <stdio.h>
#include <stdlib.h>

#include "textinterface.h"
#include "cards.h"

int main(int argc, char *argv[]){
    card_t hand[argc - 1];
    hand_t final_hand = 0;
    if(argc < 2){
        printf(
            "Usage %s [cards]\n",
            *argv
        );
        return -1;
    }
    for(int i = 0; i < argc - 1; i++)
        hand[i] = atoi(argv[i + 1]);

    final_hand = encode_hand(
            hand,
            argc - 1
        );

    sort_cards(hand, argc - 1);
    print_cards(hand, argc - 1);

    print_hand(final_hand);
}
