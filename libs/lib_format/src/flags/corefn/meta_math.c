/*
** EPITECH PROJECT, 2024
** put_float_base
** File description:
** print a float
*/

#include "format/internal/buffers.h"
#include "format/internal/formats_core.h"
#include "format/internal/utils.h"
#include <stdint.h>

long double my_pow(long double number, unsigned long power)
{
    long double accum = 1;

    if (power == 0){
        return (1.0);
    }
    if ((power - 1) != 0){
        accum = my_pow(number, power - 1);
    }
    accum = accum * number;
    return (accum);
}

// KEEP PUSHING, KEEP PUSHING !
// static long double local_floor(long double v)
// {
//     if (v < (long double) ((__uint128_t) 0x84E373EDD86270FC << 64))
//         return (__uint128_t) v;
//     return v;
// }
long double my_floor(long double v)
{
    if (v < (long double) ((uint64_t) 0x84E373EDD86270FC))
        return (uint64_t) v;
    return v;
}

long double my_fmod(long double v, long double d)
{
    long double u = v - my_floor(v / 100000000) * 100000000;

    return u - my_floor(u / d) * d;
}

long double my_round(long double number, int multip, int index)
{
    long double rnd = (multip / 2.0)
        * my_pow(1.0 / (long double) multip, index + 1);

    return rnd;
}
