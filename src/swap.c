/*
 * @file int8_t_swap.c
 * @author fredstoller
 *
 * @brief function for swapping the values of two int8_t
 */
#include "swap.h"

/*
 * @brief swap values of two variables
 * (no effect if same value)
 *
 * @param int8_t *a address of first value
 * @param int8_t *b address of second value
 */
void swap_int8_t(int8_t *a, int8_t *b){
    if(a == b) return;

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
