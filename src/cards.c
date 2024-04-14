/*
 * @file cards.c
 * @author fredstoller
 *
 * @brief Operations on "cards" (8bit ints)
 */
#include <stdlib.h>
#include <time.h>

#include "cards.h"
#include "swap.h"
#include "sort.h"

/**
 * @brief Fill an array of size DECK_AMOUNT
 * with ascending int8 then shuffle.
 *
 * @param card_t deck[DECK_AMOUNT] "deck" (array) of "cards" (bytes)
 */
void init_deck(card_t deck[DECK_AMOUNT]){

    srand(time(NULL));

    for(int i = 0; i < DECK_AMOUNT; i++)
        deck[i] = i;

    shuffle_deck(deck);
}

/**
 * @brief randomly order array akin to shuffling a deck of cards.
 *
 * @param card_t deck[DECK_AMOUNT] "deck" (array) of "cards" (bytes)
 */
void shuffle_deck(card_t deck[DECK_AMOUNT]){
    for(int i = 0; i < DECK_AMOUNT - 1; i++)
        swap_int8_t(
                &deck[i],
                &deck[
                    i +
                    rand() % (
                        DECK_AMOUNT -
                        i
                    )
                ]
            );
}

/*
 * @brief Compare value of cards by number or suite if they are the same
 *
 * @param card_t a First "card" (byte)
 * @param card_t b Second "card" (byte)
 * @return card_t difference of face value unless face value is equivalent,
 * instead returning absolute difference in a sorted deck
 * (2 to ace, heart, club, diamond, spade)
 */
card_t card_cmp(card_t a, card_t b){
    card_t
        diff =
            (a % CARDS_IN_SUITE) -
            (b % CARDS_IN_SUITE);

    return
        diff ?
        diff :
        a - b;
}

/*
 * @brief sort an array of cards in ascending order with card_cmp
 *
 * @param card_t *stack array of cards to sort
 * @param int len num of cards in stack
 */
void sort_cards(card_t *stack, int len){
    quicksort(
            stack,
            len,
            card_cmp
        );
}
