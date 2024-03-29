/*
 * @file nibble.h
 * @author fred_stoller.h
 */
#ifndef NIBBLE_H_
#define NIBBLE_H_

#include <stdint.h>

#define NIB_MASK    15
#define NIB_BITS    4

void nibble_cpy(int *dest, int source, int offset);
int8_t nibble_read(int source, int offset);
void nibble_inc(int *source, int offset);

#endif
