/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/parsing/exec.c
*/

#include "format/internal/buffers.h"
#include "format/internal/parsing.h"
#include "format/internal/conversion.h"
#include "format/internal/utils.h"
#include "format/internal/lookup.h"

#include <stddef.h>

/**
 * @brief Commits one character to the buffer.
 *
 * @param c The character to commit
 * @param bmg The buffer manager to write with
*/
static void myp_quickcmt(char c, my_buffer_mgr_t *bmg)
{
    myp_subbuffer(bmg, 1);
    *bmg->sub = c;
    myp_commitbuffer(' ', bmg);
}

/**
 * @brief Parses a format in a format string.;
 *
 * @param i The current format string cursor
 * @param conv The current conversion buffer
 * @param bf The buffer manager
*/
static myp_function_t *myp_parse_fmt(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg
)
{
    myp_subbuffer(bmg, 0);
    for (size_t i = 0; i < sizeof(myp_conversion_t); i++)
        ((char *)conv)[i] = 0;
    myp_bputc(bmg, fmt[myp_inc(i)]);
    if (fmt[*i] == '\0')
        return myp_null_conv;
    while (myp_is_in(fmt[*i], MYP_FLAG_STRING) >= 0) {
        myp_bputc(bmg, fmt[*i]);
        myp_parse_stage_flags(fmt[myp_inc(i)], conv, bmg);
    }
    myp_parse_stage_width(fmt, i, conv, bmg);
    myp_parse_stage_precision(fmt, i, conv, bmg);
    myp_parse_stage_size(fmt, i, conv, bmg);
    myp_parse_stage_conversion(fmt, i, conv, bmg);
    return my_get_for_conversion(conv);
}

static void parse_ssz(
    myp_function_t *function,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr,
    va_list ap
)
{
    long offset = 0;

    conv->width = conv->width == -2 ? va_arg(ap, int) : conv->width;
    conv->precision = conv->precision == -2 ? va_arg(ap, int)
        : conv->precision;
    conv->size = conv->size == MYP_INTMAX ? MYP_LONG : conv->size;
    conv->size = conv->size == MYP_SIZE ? MYP_LONG : conv->size;
    conv->size = conv->size == MYP_PTRDIFF ? MYP_LONG : conv->size;
    conv->size = conv->size == MYP_LLONGQ ? MYP_LLONG : conv->size;
    offset = mgr->_cursor;
    function(ap, conv, mgr);
    offset = mgr->_cursor - offset;
    if (conv->flags.excl && mgr->cols) {
        if (mgr->wcols && mgr->cols[mgr->ccols] < offset)
            mgr->cols[mgr->ccols] = offset;
        mgr->ccols++;
    }
}

/**
 * @brief Parses the format string and executes
 *        the correct formatting functions.
 *
 * @param fmt The format string to use.
 * @param ap The parameter array (variadic arg list) for other executors.
 * @param mgr The buffer manager, it needs to be initialized.
*/
void myp_format_exec(const char *fmt, va_list ap, my_buffer_mgr_t *mgr)
{
    myp_conversion_t conv = {};
    myp_function_t *function;

    for (int i = 0; fmt[i]; i++) {
        if (fmt[i] == '%') {
            function = myp_parse_fmt(fmt, &i, &conv, mgr);
            parse_ssz(function, &conv, mgr, ap);
        } else {
            myp_quickcmt(fmt[i], mgr);
        }
    }
}
