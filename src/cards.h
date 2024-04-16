/*
 * @file cards.h
 * @author fredstoller
 */
#ifndef CARD_H_
#define CARD_H_

#include <stdint.h>

typedef int8_t card_t;

/// Amount of cards in the deck
#define DECK_AMOUNT     52
/// The total amount of suites
#define SUITES_AMOUNT   4
/// The number of hole cards each player has

/// (Max high cards to consider)
#define HOLE_CARDS      2
/// The number of cards on the board (community cards)
#define BOARD_CARDS     5

#define TOTAL_CARDS     HOLE_CARDS + BOARD_CARDS

enum card_names {
    CARD_TWO,
    CARD_THREE,
    CARD_FOUR,
    CARD_FIVE,
    CARD_SIX,
    CARD_SEVEN,
    CARD_EIGHT,
    CARD_NINE,
    CARD_TEN,
    CARD_JACK,
    CARD_QUEEN,
    CARD_KING,
    CARD_ACE,
    CARDS_IN_SUITE
};

void init_deck(card_t deck[DECK_AMOUNT]);
void shuffle_deck(card_t deck[DECK_AMOUNT]);
card_t card_cmp(card_t a, card_t b);
void sort_cards(card_t *stack, int len);

#endif
