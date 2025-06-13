/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/pipefn/intpipes.c
*/

#include "format/internal/buffers.h"
#include "format/internal/formats_pipelines.h"

static void integer_pipeline(
    long long int value,
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

void myp_piped(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    long long int value;

    myp_subbuffer(bmg, 0);
    if (conv->size == MYP_LONG || conv->size == MYP_LLONG)
        value = va_arg(ap, long long);
    else
        value = va_arg(ap, int);
    myp_fputu(value > 0 ? value : - value, bmg);
    integer_pipeline(value, conv, bmg);
    myp_commitbuffer(conv->flags.zero && !conv->flags.dash ? '0' : ' ', bmg);
}

void myp_pipeu(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    unsigned long long int value;

    myp_subbuffer(bmg, 0);
    value = va_arg(ap, unsigned int);
    myp_fputu(value, bmg);
    integer_pipeline(value / 10, conv, bmg);
    myp_commitbuffer(conv->flags.zero ? '0' : ' ', bmg);
}

void myp_pipex(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    unsigned long long int value;

    myp_subbuffer(bmg, 0);
    if (conv->size == MYP_LONG || conv->size == MYP_LLONG)
        value = va_arg(ap, unsigned long long);
    else
        value = va_arg(ap, unsigned int);
    if (conv->conv == 'X')
        myp_fputxx(value, bmg);
    else
        myp_fputx(value, bmg);
    if (conv->flags.hash && value != 0) {
        myp_subresize(bmg, conv->flags.zero && conv->width > bmg->csize + 2
            ? conv->width : bmg->csize + 2, !conv->flags.dash);
        bmg->sub[0] = '0';
        bmg->sub[1] = conv->conv;
    }
    if (conv->width > bmg->csize)
        myp_subresize(bmg, conv->width, !conv->flags.dash);
    myp_commitbuffer(conv->flags.zero ? '0' : ' ', bmg);
}

void myp_pipeo(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    unsigned long long int value;

    myp_subbuffer(bmg, 0);
    if (conv->size == MYP_LONG || conv->size == MYP_LLONG)
        value = va_arg(ap, unsigned long long);
    else
        value = va_arg(ap, unsigned int);
    myp_fputo(value, bmg);
    if (conv->flags.hash && value != 0) {
        myp_subresize(bmg, conv->flags.zero && conv->width > bmg->csize + 1
            ? conv->width : bmg->csize + 1, !conv->flags.dash);
        bmg->sub[0] = '0';
    }
    if (conv->width > bmg->csize)
        myp_subresize(bmg, conv->width, !conv->flags.dash);
    myp_commitbuffer(conv->flags.zero ? '0' : ' ', bmg);
}
