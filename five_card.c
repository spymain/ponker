/*
 * @file five_card.c
 * @author fredstoller
 *
 * @brief procedures for encoding poker hands
 */
#include <string.h>

#include "five_card.h"
#include "cards.h"
#include "sort.h"
#include "nibble.h"

void check_tuples(hand_t *encoding, int8_t *hand, int len);
void find_tuples(int8_t *hand, int len, int8_t *tuples);
void encode_tuples(hand_t *encoding, int8_t *tuples);

/*
 * @brief map list of cards to best poker hand that can be formed using them
 *
 * @param int *hand_cards list of cards to scan
 * @param int len amount of cards to consider
 * @return hand_t bitpacked encoding of hand;
 * Most signifigant nibble is hand ranking,
 * Next most signifigant nibble is highest card with respect to that ranking
 * (e.g., this is where two for pair of twos is stored; not necessarily high card)
 * Following nibbles store ranks of high cards (if applicable)
 */
hand_t encode_hand(int8_t *hand_cards, int len){
    int8_t hand[len];
    hand_t encoding = 0;

    for(int i = 0; i < len; i++)
        hand[i] = hand_cards[i];

    sort_cards(
            hand,
            len
        );

    check_tuples(
            &encoding,
            hand,
            len
        );

    // Count straights
    // Count suits
    return encoding;
}

/*
 * @brief check the hand for tuples or sets of tuples,
 * copy to encoding  if so; Assumes sorted by rank.
 *
 * @param hand_t *encoding pointer to data where encoding will be copied to
 * @param int8_t *hand list of cards to check
 * @param int len amount of cards to check
 */
void check_tuples(hand_t *encoding, int8_t *hand, int len){
    int8_t
        poss_tup    = len/2 + 1,
        tuples[poss_tup];

    memset(tuples, 0, sizeof(*tuples) * poss_tup);

    find_tuples(hand, len, tuples);

    quicksort(tuples, poss_tup, cmp_desc);

    encode_tuples(encoding, tuples);
}

/*
 * @brief loop through list of cards and count tuples
 *
 * @param int8_t *hand sorted list of cards to count (assumes sort by rank)
 * @param int len amount of cards to consider
 * @param int8_t *tuples list to copy found tuples to
 */
void find_tuples(int8_t *hand, int len, int8_t *tuples){
    int
        buff    = 0,
        current = 0;

    for(int i = 1; i <= len; i++)
        if(
            i < len && (
                (hand[i] - hand[i - 1]) %
                CARDS_IN_SUITE == 0
            )
        ){
            buff = tuples[current];
            nibble_inc(&buff, 1);
            tuples[current] = (int8_t)buff;
        } else {
            if(tuples[current]){
                buff = tuples[current];
                nibble_cpy(
                        &buff,
                        hand[i - 1] % 13,
                        0
                    );
                tuples[current] = (int8_t)buff;
                current++;
            }
        }
}

/*
 * @brief translate list of tuples to poker hand encoding
 *
 * @param hand_t *encoding data to copy encoding to
 * @param int8_t *tuples list of tuples to encode
 */
void encode_tuples(hand_t *encoding, int8_t *tuples){
    hand_t final_hand = 0;
    int8_t
        first_tup = tuples[0] >> NIB_BITS,
        second_tup = tuples[1] >> NIB_BITS;

    if(first_tup){
        final_hand =
            first_tup > 1 ?
                (first_tup == 3 ?
                    FOUR_KIND
                    :
                    (second_tup ?
                        FULL_HOUSE
                        :
                        THREE_KIND))
                :
                (second_tup ?
                    TWO_PAIR
                    :
                    ONE_PAIR);

        nibble_cpy(
                encoding,
                final_hand,
                HOLE_CARDS + 1
            );
        nibble_cpy(
                encoding,
                nibble_read(
                    *tuples,
                    0
                ),
                HOLE_CARDS
            );
        if(
                final_hand == TWO_PAIR ||
                final_hand == FULL_HOUSE
        )
            nibble_cpy(
                    encoding,
                    tuples[1],
                    HOLE_CARDS - 1
            );
    }
}
