/*
 * @file cards.h
 * @author fredstoller
 */
#ifndef CARD_H_
#define CARD_H_

#include <stdint.h>

/// Amount of cards in the deck
#define DECK_AMOUNT     52
/// Amount of cards in a suite
#define CARDS_IN_SUITE  13
/// The total amount of suites
#define SUITES_AMOUNT   4

/// The number of cards a player will use to determine their hand
#define HAND_SIZE       5

void init_deck(int8_t deck[DECK_AMOUNT]);
void shuffle_deck(int8_t deck[DECK_AMOUNT]);
int8_t card_cmp(int8_t a, int8_t b);

#endif
