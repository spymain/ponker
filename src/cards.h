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
/// Amount of cards in a suite
#define CARDS_IN_SUITE  13
/// The total amount of suites
#define SUITES_AMOUNT   4
/// The number of hole cards each player has

/// (Max high cards to consider)
#define HOLE_CARDS      2
/// The number of cards on the board (community cards)
#define BOARD_CARDS     5

#define TOTAL_CARDS     HOLE_CARDS + BOARD_CARDS

void init_deck(int8_t deck[DECK_AMOUNT]);
void shuffle_deck(int8_t deck[DECK_AMOUNT]);
int8_t card_cmp(int8_t a, int8_t b);
void sort_cards(int8_t *stack, int len);

#endif
