/*
 * @file sort.h
 * @author fredstoller
 */
#ifndef SORT_H_
#define SORT_H_

#include <stdint.h>

void quicksort(int8_t *list, int len, int8_t (*cmp)(int8_t, int8_t));
void invert_list(int8_t *list, int len);

#endif
