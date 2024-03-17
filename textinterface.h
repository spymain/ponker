#ifndef TEXT_INTERFACE_H_
#define TEXT_INTERFACE_H_

#include <stdint.h>

static const char * const suites[] = {
    "Hearts",
    "Clubs",
    "Diamonds",
    "Spades"
};

static const char * const cards[] = {
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
