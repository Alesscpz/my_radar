/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "format/internal/buffers.h"

int myp_fputo(unsigned long long number, my_buffer_mgr_t *bmg)
{
    int divisor = 8;
    int accum = 0;

    if (number > 0) {
        if (number / divisor != 0)
            accum += myp_fputo(number / divisor, bmg);
        accum += myp_bputc(bmg, (number % divisor) + 48);
    }
    if (number == 0) {
        accum += myp_bputc(bmg, 48);
    }
    return accum;
}
