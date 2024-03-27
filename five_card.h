/*
 * @file five_card.h
 * @author fredstoller
 */
#ifndef FIVE_CARD_H_
#define FIVE_CARD_H_

#include <stdint.h>

#define HAND_SIZE   5

/// With a 5 card hand,
/// you can only have a maximum of 2 tuples
/// (e.g. 2 pairs, 1 pair and 1 triple, or 1 quad)
#define MAX_TUPLES  2

typedef  int32_t    hand_t;

enum hand_rank {
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_KIND,
    STRAIGHT_FLUSH
};

hand_t encode_hand(int8_t *hand_cards, int len);

#endif
