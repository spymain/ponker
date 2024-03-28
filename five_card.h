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

/// Number of cards important to rank
static const int num_cards[] = {
    0, // HIGH_CARD
    1, // ONE_PAIR
    2, // TWO_PAIR
    1, // THREE_KIND
    1, // STRAIGHT          (nominal)
    5, // FLUSH             (nominal)
    2, // FULL_HOUSE        (nominal)
    1, // FOUR_KIND
    1  // STRAIGHT_FLUSH    (nominal)
};

/// Number of hole cards in a rank
static const int num_holes[] = {
    5, // HIGH_CARD
    3, // ONE_PAIR
    1, // TWO_PAIR
    2, // THREE_KIND
    0, // STRAIGHT
    5, // FLUSH
    0, // FULL_HOUSE
    1, // FOUR_KIND
    0  // STRAIGHT_FLUSH
};

hand_t encode_hand(int8_t *hand_cards, int len);

#endif
