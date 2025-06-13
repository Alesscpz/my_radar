/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/pipefn/extrapipes.c
*/

#include "format/internal/formats_pipelines.h"

static int myp_pv(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    switch (conv->size) {
        case MYP_CHAR:
            return myp_save_address(va_arg(ap, char *), MYP_CHAR, bmg);
        case MYP_SHORT:
            return myp_save_address(va_arg(ap, short *), MYP_SHORT, bmg);
        case MYP_INT:
            return myp_save_address(va_arg(ap, int *), MYP_INT, bmg);
        case MYP_LONG:
            return myp_save_address(va_arg(ap, long *), MYP_LONG, bmg);
        case MYP_LLONG:
            return myp_save_address(va_arg(ap, long long *), MYP_LLONG, bmg);
        default:
            return myp_save_address(va_arg(ap, int *), MYP_INT, bmg);
    }
    return 1;
}

void myp_pipen(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    myp_subbuffer(bmg, 0);
    myp_pv(ap, conv, bmg);
    myp_commitbuffer('0', bmg);
}

void myp_pipep(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    unsigned long long int value;

    myp_subbuffer(bmg, 0);
    value = va_arg(ap, unsigned long);
    myp_fputs("0x", -1, bmg, false);
    myp_fputx(value, bmg);
    myp_commitbuffer('0', bmg);
}
