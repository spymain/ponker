/*
 * @file five_card.c
 * @author fredstoller
 *
 * @brief procedures for encoding poker hands
 */
#include <string.h>

#include "five_card.h"
#include "sort.h"
#include "nibble.h"

#define FLUSH_BREAK_FLG 1
#define ACE_FLG         2

hand_t check_tuples(card_t *hand, int len);
int find_tuples(card_t *hand, int len, card_t *tuples);
void encode_tuples(hand_t *encoding, card_t *tuples);
hand_t check_straights(card_t *hand, int len);
void inline encode_straight(
        hand_t *encoding,
        card_t high_card,
        int s_counter,
        int sf_counter,
        int flags
);
void check_high_cards(hand_t *encoding, card_t *hand, int len);

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
hand_t encode_hand(card_t *hand_cards, int len){
    card_t
        hand[len],
        hand_rev[len];      //This is lazy
                            //It can be done better
    hand_t
        encoding = 0,
        current_encoding;

    memcpy(
        hand,
        hand_cards,
        sizeof(card_t) * len
    );

    sort_cards(
            hand,
            len
        );

    memcpy(
        hand_rev,
        hand,
        sizeof(card_t) * len
    );

    invert_list(hand_rev, len);

    encoding = check_straights(
            hand_rev,
            len
        );

    if(encoding >= (STRAIGHT_FLUSH << RANK_NIB))
        goto conclude;

    current_encoding = check_tuples(
        hand,
        len
    );
    encoding = (
            current_encoding > encoding ?
            current_encoding :
            encoding
        );
    /*
    if(
        encoding >= (FULL_HOUSE << RANK_NIB)
    ) goto conclude;
    //*/

    //Check for flush

    conclude:

    check_high_cards(
            &encoding,
            hand,
            len
        );

    return encoding;
}

/*
 * @brief check the hand for tuples or sets of tuples,
 * copy to encoding  if so; Assumes sorted by rank.
 *
 * @param hand_t *encoding pointer to data where encoding will be copied to
 * @param card_t *hand list of cards to check
 * @param int len amount of cards to check
 * @return hand_t encoding of best tuple found
 */
hand_t check_tuples(card_t *hand, int len){
    int poss_tuples = len/2 + 1;
    hand_t encoding = 0;
    card_t tuples[poss_tuples];
    memset(tuples, 0, sizeof(*tuples) * poss_tuples);

    int found_tuples = find_tuples(hand, len, tuples);

    if(found_tuples){
        invert_list(tuples, found_tuples);
        encode_tuples(&encoding, tuples);
    }
    return encoding;
}

/*
 * @brief loop through list of cards and count tuples
 *
 * @param card_t *hand sorted list of cards to count (assumes sort by rank)
 * @param int len amount of cards to consider
 * @param card_t *tuples list to copy found tuples to
 * @return int number of tuples found
 */
int find_tuples(card_t *hand, int len, card_t *tuples){
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
            tuples[current] = (card_t)buff;
        } else {
            if(tuples[current]){
                buff = tuples[current];
                nibble_cpy(
                        &buff,
                        hand[i - 1] % 13,
                        0
                    );
                tuples[current] = (card_t)buff;
                current++;
            }
        }
    return current;
}

/*
 * @brief translate list of tuples to poker hand encoding
 *
 * @param hand_t *encoding data to copy encoding to
 * @param card_t *tuples list of tuples to encode
 */
void encode_tuples(hand_t *encoding, card_t *tuples){
    hand_t final_hand = 0;
    card_t
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
                RANK_NIB
            );
        nibble_cpy(
                encoding,
                nibble_read(
                    *tuples,
                    0
                ),
                HOLE_NIB
            );
        if(
                final_hand == TWO_PAIR ||
                final_hand == FULL_HOUSE
        )
            nibble_cpy(
                    encoding,
                    tuples[1],
                    HOLE_NIB - 1
            );
    }
}

/*
 */
hand_t check_straights(card_t *hand, int len){
    hand_t encoding = 0;
    int
        s_counter = 1,
        sf_counter = 1,
        flags = FLUSH_BREAK_FLG;

    card_t 
        high_card = *hand,
        run_suite = *hand/CARDS_IN_SUITE;

    if(high_card % CARDS_IN_SUITE == CARD_ACE)
        flags |= ACE_FLG;

    for(int i = 1; i < len; i++){
        switch(
            hand[i-1]   % CARDS_IN_SUITE -
            hand[i]     % CARDS_IN_SUITE
        ){
            case 1:
                s_counter++;

                if(
                    hand[i]/CARDS_IN_SUITE ==
                    run_suite
                ) sf_counter++;
                else {
                    if(flags & FLUSH_BREAK_FLG){
                        flags &= ~FLUSH_BREAK_FLG;
                    } else {
                        sf_counter = 1;
                        run_suite = hand[i]/CARDS_IN_SUITE;
                        flags |= FLUSH_BREAK_FLG;
                    }
                }
                break;
            case 0:
                ///Cards not yet checked < cards needed for a straight
                if(len - i + 1 < HAND_SIZE - s_counter)
                    return 0;

                if(hand[i]/CARDS_IN_SUITE == run_suite)
                    flags |= FLUSH_BREAK_FLG;
                break;
            default:
                if(len - i + 1 < HAND_SIZE)
                    return 0;

                high_card = hand[i];
                run_suite = hand[i]/CARDS_IN_SUITE;
                s_counter = 1;
                sf_counter = 1;
                flags |= FLUSH_BREAK_FLG;
                break;
        }

    }

    high_card %= CARDS_IN_SUITE;

    encode_straight(
            &encoding,
            high_card,
            s_counter,
            sf_counter,
            flags
        );
    return encoding;
}

void encode_straight(
        hand_t *encoding,
        card_t high_card,
        int s_counter,
        int sf_counter,
        int flags
){
    int
        five_high = (
            high_card == CARD_FIVE &&
            flags & ACE_FLG
        ),

        final_hand = (
            (
                s_counter >= HAND_SIZE ||
                (
                    s_counter == HAND_SIZE - 1 &&
                    five_high
                )
            ) ? (
                (
                    sf_counter >= HAND_SIZE ||
                    (
                        sf_counter == HAND_SIZE - 1 &&
                        five_high
                    )
                ) ? STRAIGHT_FLUSH : STRAIGHT

            ) : 0
        );

    if(final_hand){
        nibble_cpy(
                encoding,
                final_hand,
                RANK_NIB
            );
        nibble_cpy(
                encoding,
                high_card,
                HOLE_NIB
            );
    }
}

/*
 * @brief copy high card to encoding as necessary
 *
 * Straight, flush, full house and straight flush have no hole cards.
 * copy the hole cards of the hand from highest to lowest to the hand,
 * only copy as many as the hand can hold.
 *
 * @param hand_t *encoding data to copy hole cards to
 * @param card_t *hand list of cards in hand (assume sort by rank desc)
 * @param int len length of list
 */
void check_high_cards(hand_t *encoding, card_t *hand, int len){
    int
        rank = *encoding >> (RANK_NIB) * NIB_BITS;

    if(
        rank == STRAIGHT    ||
        rank == FLUSH       ||
        rank == FULL_HOUSE  ||
        rank == STRAIGHT_FLUSH
    ) return;

    int
        i, j, k = 0,
        relevants,
        holes;

    relevants = num_cards[rank];
    holes = num_holes[rank];

    card_t hand_holes[holes];
    memset(hand_holes, 0, sizeof(*hand_holes) * holes);

    for(i = 0; i < len; i++){
        for(j = 0; j < relevants; j++)
            if(
                (hand[i] -
                nibble_read(
                    *encoding,
                    HOLE_NIB - j
                )) %
                CARDS_IN_SUITE == 0
            ) break;

        hand_holes[k++] = hand[i] % 13;
        if(k >= holes) break;
    }

    for(i = 0; i < holes; i++)
        nibble_cpy(
                encoding,
                hand_holes[i],
                HOLE_NIB - relevants - i
            );
}
