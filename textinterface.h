#ifndef TEXT_INTERFACE_H_
#define TEXT_INTERFACE_H_

#include "cards.h"

static const char *suites[] = {
    "Hearts",
    "Clubs",
    "Diamonds",
    "Spades"
};

static const char *cards[] = {
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Jack",
    "Queen",
    "King",
    "Ace"
};

void print_card(uint8_t card);

#endif
