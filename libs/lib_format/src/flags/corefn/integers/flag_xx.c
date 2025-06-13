/*
** EPITECH PROJECT, 2024
** put number hexad
** File description:
** my_put_nbr_hexa
*/

#include "format/internal/buffers.h"

int myp_fputx(unsigned long long number, my_buffer_mgr_t *bmg)
{
    int divisor = 16;
    int accum = 0;

    if (number > 0) {
        if (number / divisor != 0)
            accum = accum + myp_fputx(number / divisor, bmg);
        if ((number % divisor) < 10) {
            accum = accum + myp_bputc(bmg, (number % divisor) + 48);
        } else {
            accum = accum + myp_bputc(bmg, (number % divisor) + 87);
        }
    }
    if (number == 0 && accum == 0) {
        accum = accum + myp_bputc(bmg, '0');
    }
    return accum;
}

int myp_fputxx(unsigned long long number, my_buffer_mgr_t *bmg)
{
    int divisor = 16;
    int accum = 0;

    if (number > 0) {
        if (number / divisor != 0)
            accum = accum + myp_fputxx(number / divisor, bmg);
        if ((number % divisor) < 10) {
            accum = accum + myp_bputc(bmg, (number % divisor) + 48);
        } else {
            accum = accum + myp_bputc(bmg, (number % divisor) + 55);
        }
        return accum;
    }
    if (number == 0 && accum == 0) {
        accum = accum + myp_bputc(bmg, '0');
    }
    return 0;
}
