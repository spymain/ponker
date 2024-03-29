/*
 * @file nibble.c
 * @author fredstoller
 *
 * @brief procedures for manipuating nibbles
 * (read/write 4 bit chunks)
 */
#include "nibble.h"

/*
 * @brief copy 4 bits (one nibble) from start of source to specified slot in dest
 *
 * @param hand_t *dest place to copy bits to
 * @param hand_t *source place to copy bits from (first nibble)
 * @param int offset which nibble slot in dest to copy source bits to
 * (e.g. 0 is to first nibble, 1 is to second nibble, etc.)
 */
void nibble_cpy(int *dest, int source, int offset){
    *dest =
        (*dest       & ~(NIB_MASK    << offset * NIB_BITS)) |
        ((source    & NIB_MASK)     << offset * NIB_BITS);
}

/*
 * @brief read one nibble from an int
 *
 * @param int source the data to collect the nibble from
 * @param int offset which nibble to collect
 * (e.g. 1 collects the first nibble, 2 collects the second, etc.)
 */
int8_t nibble_read(int source, int offset){
    return NIB_MASK & source >> offset * NIB_BITS;
}

/*
 * @brief increment a nibble by 1
 *
 * @param int *source where the nibble is located
 * @param int offset which nibble to increment
 */
void nibble_inc(int *source, int offset){
    int8_t tmp = nibble_read(*source, offset);
    nibble_cpy(source, (int)++tmp, offset);
}
