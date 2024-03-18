#ifndef CARD_H_
#define CARD_H_

#include <stdint.h>

#define DECK_AMOUNT     52
#define CARDS_IN_SUITE  13
#define SUITES_AMOUNT   4

void init_deck(uint8_t deck[DECK_AMOUNT]);
void shuffle_deck(uint8_t deck[DECK_AMOUNT]);
void swap_uint8_t(uint8_t *a, uint8_t *b);

#endif
