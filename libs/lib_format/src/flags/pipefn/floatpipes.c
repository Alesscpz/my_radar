/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/pipefn/floatpipes.c
*/

#include "format/internal/formats_pipelines.h"

static void float_pipeline(
    double value,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg
)
{
    char positive_char = conv->flags.plus ? '+' : ' ';

    if (value < 0 || conv->flags.plus || conv->flags.space)
        myp_subresize(bmg, bmg->csize + 1, MYP_ALIGN_RIGHT);
    myp_subresize(bmg, conv->flags.zero && conv->width > bmg->csize
        ? conv->width : -1, !conv->flags.dash);
    if (value < 0 || conv->flags.plus || conv->flags.space)
        bmg->sub[0] = value < 0 ? '-' : positive_char;
    if (conv->width > bmg->csize)
        myp_subresize(bmg, conv->width, !conv->flags.dash);
}

void myp_pipef_direct(
    double value,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg,
    bool rm_tzeroes
)
{
    int precision = conv->precision < 0 ? MYP_PREC : conv->precision;

    myp_subbuffer(bmg, 0);
    myp_fputf(value > 0 ? value : - value, precision, bmg,
            conv->flags.hash);
    while (bmg->sub[bmg->csize - 1] == '0' && precision > 0 && rm_tzeroes
        && !(conv->flags.hash && bmg->csize <= precision + 1))
        myp_subresize(bmg, bmg->csize - 1, MYP_ALIGN_LEFT);
    if (bmg->sub[bmg->csize - 1] == '.' && precision > 0 && rm_tzeroes
        && !conv->flags.hash)
        myp_subresize(bmg, bmg->csize - 1, MYP_ALIGN_LEFT);
    float_pipeline(value, conv, bmg);
    myp_commitbuffer(conv->flags.zero ? '0' : ' ', bmg);
}

void myp_pipef(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    long double value;

    if (conv->size == MYP_LFLT)
        value = va_arg(ap, long double);
    else
        value = va_arg(ap, double);
    myp_pipef_direct(value, conv, bmg, false);
}
