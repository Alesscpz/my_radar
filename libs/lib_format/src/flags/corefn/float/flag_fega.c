/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/corefn/float/flag_x.c
*/

#include "format/internal/formats_core.h"
#include "format/internal/utils.h"

static int myp_fput_float_acc(long double number, my_buffer_mgr_t *bmg)
{
    int divisor = 10;
    int accum = 0;

    if (number >= 1) {
        if (number / divisor != 0)
            accum = accum + myp_fput_float_acc(number / divisor, bmg);
        accum = accum + myp_bputc(bmg, (int)my_fmod(number, divisor) + '0');
    }
    if (number == 0) {
        accum = accum + myp_bputc(bmg, '0');
    }
    return accum;
}

static int my_put_decimals(
    unsigned long number,
    unsigned long index_max,
    unsigned long index,
    my_buffer_mgr_t *bmg
)
{
    int multip = 10;
    int accum = 0;

    if (index_max > index - 1) {
        accum = accum + my_put_decimals(number / multip, index_max,
            index - 1, bmg);
        accum = accum + myp_bputc(bmg, ((number / 10) % multip) + 48);
        return accum;
    }
    return accum;
}

static int my_put_hdecimals(
    long double number,
    unsigned long index_max,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg
)
{
    int multip = 16;
    int accum = 0;
    unsigned long index = index_max;

    while (index > 0) {
        accum = accum + myp_bputc(bmg,
            MYP_BASE16(conv->conv == 'A')[(int) my_fmod(number, multip)]);
        number *= multip;
        index--;
    }
    return accum;
}

int myp_fputf(
    long double num,
    unsigned long decimal,
    my_buffer_mgr_t *bmg,
    bool force_dp
)
{
    long double divisor = 10;
    long double number = num + my_round(num, divisor, decimal);
    long double floored = my_floor(number);
    long double show = ((number - floored) * my_pow(divisor, decimal + 1));
    int accum = 0;

    accum = myp_fput_float_acc(floored, bmg);
    if (decimal > 0 || force_dp)
        accum += myp_bputc(bmg, '.');
    accum += my_put_decimals(show, decimal, decimal, bmg);
    return accum;
}

int myp_fputa(
    long double num,
    unsigned long decimal,
    my_buffer_mgr_t *bmg,
    myp_conversion_t *conv
)
{
    long double divisor = 16;
    long double number = num + my_round(num, divisor, decimal);
    long double floored = my_floor(number);
    int accum = 0;

    accum += myp_fput_float_acc(floored, bmg);
    accum += myp_bputc(bmg, '.');
    accum += my_put_hdecimals(number * divisor, decimal, conv, bmg);
    return accum;
}
