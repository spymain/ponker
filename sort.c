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
