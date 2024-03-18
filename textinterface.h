/*
 * @file textinterface.h
 * @author
 */
#ifndef TEXT_INTERFACE_H_
#define TEXT_INTERFACE_H_

#include <stdint.h>

/// Names of suites
static const char * const suites[] = {
    "Hearts",
    "Clubs",
    "Diamonds",
    "Spades"
};

/// Names of cards (numbers)
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

char *card_name(int8_t card, char* buff, int len);

#endif
