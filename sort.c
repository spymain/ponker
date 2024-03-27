/*
 * @file sort.c
 * @author fredstoller
 *
 * @brief functions for sorting int8_t with generic compare
 */
#include "sort.h"
#include "swap_int8_t.h"

/*
 * @brief Lomuto partitioned quicksort
 *
 * @param int8_t *list array of elements to sort
 * @param int len length of list
 * @param int8_t (*cmp)(int8_t,int8_t) function pointer for comparing two values
 */
void quicksort(int8_t *list, int len, int8_t (*cmp)(int8_t, int8_t)){
    int tmp_pivot;

    if(len <= 1) return;

    tmp_pivot = -1;

    for(int i = 0; i < len - 1; i++)
        if(
            cmp(
                list[len - 1],
                list[i]
            ) > 0
        ){
            swap_int8_t(
                    list + i,
                    list + ++tmp_pivot
                );
        }
    swap_int8_t(
            list + len - 1,
            list + ++tmp_pivot
        );

    quicksort(
            list,
            tmp_pivot,
            cmp
        );
    quicksort(
            list + tmp_pivot + 1,
            len - (tmp_pivot + 1),
            cmp
        );
}

/*
 * @brief compare two int8_t, report lesser as more signifigant
 *
 * @param int8_t a first to compare
 * @param int8_t b second to compare
 * @return difference between a & b;
 * > 0 if b is larger
 */
int8_t cmp_desc(int8_t a, int8_t b){
    return b - a;
}
