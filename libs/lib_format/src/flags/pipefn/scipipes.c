/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/pipefn/scipipes.c
*/

#include "format/internal/formats_pipelines.h"
#include "format/internal/utils.h"

static void sci_pipeline(
    long double value,
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

static long double reach_sci_number(long double *number, int npower)
{
    long double power = 0.0;

    while ((*number) >= npower){
        (*number) = (*number) / npower;
        power = power + 1;
    }
    if ((*number) == 0.0)
        return 0;
    while ((*number) < 1){
        (*number) = (*number) * npower;
        power = power - 1;
    }
    return power;
}

static void write_sci_power(
    long double v,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg,
    bool rm_tzeroes
)
{
    int power = reach_sci_number(&v, 10);
    int precision = conv->precision < 0 ? MYP_PREC : conv->precision;

    myp_fputf(v > 0 ? v : - v, precision, bmg, conv->flags.hash);
    while (bmg->sub[bmg->csize - 1] == '0' && rm_tzeroes
        && !(v == 0 && conv->flags.hash))
        myp_subresize(bmg, bmg->csize - 1, MYP_ALIGN_LEFT);
    if (bmg->sub[bmg->csize - 1] == '.' && precision > 0 && rm_tzeroes
        && !conv->flags.hash)
        myp_subresize(bmg, bmg->csize - 1, MYP_ALIGN_LEFT);
    myp_bputc(bmg, conv->conv == 'e' || conv->conv == 'g' ? 'e' : 'E');
    myp_bputc(bmg, power < 0 ? '-' : '+');
    power = power < 0 ? - power : power;
    myp_fputu(power / 10.0, bmg);
    myp_fputu(my_fmod(power, 10), bmg);
}

void myp_pipee_direct(
    double value,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg,
    bool rm_tzeroes
)
{
    myp_subbuffer(bmg, 0);
    write_sci_power(value > 0 ? value : - value, conv, bmg, rm_tzeroes);
    myp_commitbuffer(conv->flags.zero ? '0' : ' ', bmg);
}

void myp_pipee(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    long double value;

    if (conv->size == MYP_LFLT)
        value = va_arg(ap, long double);
    else
        value = va_arg(ap, double);
    sci_pipeline(value, conv, bmg);
    myp_pipee_direct(value, conv, bmg, false);
}

void myp_pipeg(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    long double value;
    long double value2;
    int exp;
    int precision = (conv->precision < 0 ? 6 : conv->precision);

    if (conv->size == MYP_LFLT)
        value = va_arg(ap, long double);
    else
        value = va_arg(ap, double);
    value2 = value;
    exp = reach_sci_number(&value2, 10);
    if (exp < -4 || exp > precision)
        myp_pipee_direct(value, conv, bmg, true);
    else
        myp_pipef_direct(value, conv, bmg, true);
}

static void write_hex_power(
    long double v,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg
)
{
    int power = reach_sci_number(&v, 2);
    int precision = conv->precision < 0 ? MYP_PREC : conv->precision;

    myp_fputa(v > 0 ? v : - v, precision, bmg, conv);
    while (bmg->sub[bmg->csize - 1] == '0' && conv->precision < 0)
        myp_subresize(bmg, bmg->csize - 1, MYP_ALIGN_LEFT);
    if (bmg->sub[bmg->csize - 1] == '.' && conv->precision < 0
        && !conv->flags.hash)
        myp_subresize(bmg, bmg->csize - 1, MYP_ALIGN_LEFT);
    myp_bputc(bmg, conv->conv == 'a' ? 'p' : 'P');
    myp_bputc(bmg, power < 0 ? '-' : '+');
    power = power < 0 ? - power : power;
    myp_fputu(power, bmg);
}

void myp_pipea(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    long double value;

    if (conv->size == MYP_LFLT)
        value = va_arg(ap, long double);
    else
        value = va_arg(ap, double);
    myp_subbuffer(bmg, 0);
    write_hex_power(value > 0 ? value : - value, conv, bmg);
    myp_subresize(bmg, bmg->csize + 2, MYP_ALIGN_RIGHT);
    bmg->sub[0] = '0';
    bmg->sub[1] = 'x';
    myp_commitbuffer(conv->flags.zero ? '0' : ' ', bmg);
}
