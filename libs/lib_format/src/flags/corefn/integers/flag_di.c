/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "format/internal/buffers.h"

int myp_fputu(unsigned long long number, my_buffer_mgr_t *bmg)
{
    int divisor = 10;
    int accum = 0;

    if (number > 0) {
        if (number / divisor != 0)
            accum = accum + myp_fputu(number / divisor, bmg);
        accum = accum + myp_bputc(bmg, (number % divisor) + '0');
        return accum;
    }
    if (number == 0) {
        accum = accum + myp_bputc(bmg, '0');
    }
    return accum;
}
