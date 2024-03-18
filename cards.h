#ifndef CARD_H_
#define CARD_H_

#include <stdint.h>

#define DECK_AMOUNT     52
#define CARDS_IN_SUITE  13
#define SUITES_AMOUNT   4

#define HAND_SIZE       5

void init_deck(int8_t deck[DECK_AMOUNT]);
void shuffle_deck(int8_t deck[DECK_AMOUNT]);
int8_t card_cmp(int8_t a, int8_t b);
void swap_int8_t(int8_t *a, int8_t *b);

#endif
