/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/pipefn/charpipes.c
*/

#include "format/internal/buffers.h"
#include "format/internal/utils.h"
#include "format/internal/formats_pipelines.h"
#include <stdbool.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdarg.h>

static const char *const BASE16 = "0123456789abcdef";

static void myp_reconstruct_attempt(
    char c, myp_conversion_t *conv, my_buffer_mgr_t *bmg
)
{
    int mindex = myp_is_in(c, FMT_SR_MATCH_ARRAY);

    if ((conv->flags.space && myp_is_in(c, FMT_SR_BMATCH_ARRAY) >= 0) ||
        (conv->flags.under && myp_is_in(c, FMT_SR_SMATCH_ARRAY) >= 0)) {
        myp_bputc(bmg, '\\');
        myp_bputc(bmg, c);
        return;
    }
    if (mindex >= 0 || c == '\0') {
        myp_bputc(bmg, '\\');
        myp_bputc(bmg, c == '\0' ? '0' : FMT_SR_OUTPUT_ARRAY[mindex]);
    } else if (c < FMT_SR_PRINT_LOW || c > FMT_SR_PRINT_HIGH) {
        myp_bputc(bmg, '\\');
        myp_bputc(bmg, 'x');
        myp_bputc(bmg, BASE16[c / 16]);
        myp_bputc(bmg, BASE16[c % 16]);
    } else {
        myp_bputc(bmg, c);
    }
}

static void myp_reconstruct_printable(
    myp_conversion_t *conv, my_buffer_mgr_t *bmg
)
{
    char *tmb = malloc(bmg->csize);
    size_t smb = bmg->csize;

    for (size_t i = 0; i < smb; i++)
        tmb[i] = bmg->sub[i];
    myp_subbuffer(bmg, 0);
    for (size_t i = 0; i < smb; i++)
        myp_reconstruct_attempt(tmb[i], conv, bmg);
    free(tmb);
}

void myp_pipec(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    wchar_t wc = 0;

    myp_subbuffer(bmg, 0);
    wc = conv->conv == '%' ? '%' : va_arg(ap, int);
    if (conv->size == MYP_LONG && conv->size == MYP_LLONG)
        myp_fputs(((char *)&wc), sizeof(wchar_t), bmg, false);
    else
        myp_fputc(wc, bmg);
    myp_commitbuffer(' ', bmg);
}

void myp_pipes(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg)
{
    char *string;
    int size = conv->precision < 0 || conv->flags.plus ? -1 : conv->precision;

    myp_subbuffer(bmg, 0);
    string = va_arg(ap, char *);
    if (string == NULL)
        myp_fputs("(nil)", size, bmg, false);
    myp_fputs(string, size, bmg, conv->flags.zero);
    if (conv->flags.under || conv->flags.hash || conv->flags.space)
        myp_reconstruct_printable(conv, bmg);
    if (bmg->csize > conv->precision && conv->flags.plus) {
        for (int i = 0; i < 3 && bmg->csize > 4; i++)
            bmg->sub[conv->precision - i - 1] = '.';
        myp_subresize(bmg, conv->precision, MYP_ALIGN_LEFT);
    }
    if (conv->width > bmg->csize)
        myp_subresize(bmg, conv->width, !conv->flags.dash);
    free(conv->flags.caret ? string : NULL);
    myp_commitbuffer(' ', bmg);
}
