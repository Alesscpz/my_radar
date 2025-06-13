/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/parsing/stages.c
*/

#include "format/internal/parsing.h"
#include "format/internal/utils.h"

void myp_parse_stage_flags(char fmc, myp_conversion_t *conv,
    my_buffer_mgr_t *mgr)
{
    *((uint16_t *) &conv->flags) += 1 << myp_is_in(fmc, MYP_FLAG_STRING);
}

void myp_parse_stage_width(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
)
{
    bool ok = false;
    int width = 0;

    conv->width = conv->flags.excl && mgr->cols ? mgr->cols[mgr->ccols] : -1;
    if (fmt[*i] == '*') {
        conv->width = -2;
        myp_bputc(mgr, fmt[myp_inc(i)]);
    } else {
        while (fmt[*i] >= '0' && fmt[*i] <= '9') {
            ok = true;
            width = width * 10 + (fmt[*i] - '0');
            myp_bputc(mgr, fmt[myp_inc(i)]);
        }
    }
    if (ok)
        conv->width = width;
}

void myp_parse_stage_precision(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
)
{
    bool ok = false;
    int precision = 0;

    conv->precision = -1;
    if (fmt[*i] != '.')
        return;
    conv->precision = 0;
    myp_bputc(mgr, fmt[myp_inc(i)]);
    if (fmt[*i] == '*') {
        conv->precision = -2;
        myp_bputc(mgr, fmt[myp_inc(i)]);
    } else {
        while (fmt[*i] >= '0' && fmt[*i] <= '9') {
            ok = true;
            precision = precision * 10 + (fmt[*i] - '0');
            myp_bputc(mgr, fmt[myp_inc(i)]);
        }
    }
    if (ok)
        conv->precision = precision;
}

void myp_parse_stage_size(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
)
{
    char xcu = fmt[*i];
    int cur = myp_is_in(xcu, MYP_SIZE_STRING);

    if (cur < 0)
        return;
    myp_bputc(mgr, fmt[myp_inc(i)]);
    if (fmt[*i] == xcu && myp_is_in(fmt[*i], MYP_DUPS_STRING) >= 0) {
        xcu *= -1;
        myp_bputc(mgr, fmt[myp_inc(i)]);
    }
    conv->size = xcu;
}

void myp_parse_stage_conversion(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
)
{
    if (myp_is_in(fmt[*i], MYP_CONV_STRING) >= 0)
        conv->conv = fmt[*i];
    myp_bputc(mgr, fmt[*i]);
}
