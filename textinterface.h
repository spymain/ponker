/*
 * @file textinterface.h
 * @author
 */
#ifndef TEXT_INTERFACE_H_
#define TEXT_INTERFACE_H_

#include <stdint.h>

#include "five_card.h"

#define NAME_MAX_LEN 18

/// Names of suites
static const char * const suites[] = {
    "Hearts",
    "Clubs",
    "Diamonds",
    "Spades"
};

/// Names of ranks (numbers)
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

/// Names of hands
static const char * const hands[] = {
    "High",
    "Pair",
    "Two Pair",
    "Three",
    "Straight",
    "Flush",
    "Full House",
    "Four",
    "Straight Flush",
    "Royal Flush"
};

char *card_name(int8_t card, char* buff, int len);
void print_cards(int8_t *deck, int len);
void print_hand(hand_t hand);

#endif
