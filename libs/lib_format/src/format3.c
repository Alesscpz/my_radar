/*
** EPITECH PROJECT, 2024
** format
** File description:
** src/format3.c
*/

#include "format/format.h"
#include "format/cformat.h"
#include "format/internal/buffers.h"
#include "format/internal/parsing.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *cvformat(int *cols, const char *fmt, va_list ap)
{
    my_buffer_mgr_t mgr = {
        .cols = cols,
        .wcols = false,
        .ccols = 0
    };

    myp_init_buffer_mgr(&mgr, MYP_DEFAULT_BUFFER);
    myp_format_exec(fmt, ap, &mgr);
    mgr.buffer[mgr._cursor] = '\0';
    return mgr.buffer;
}

int cvfprint(int *cols, const char *fmt, va_list ap)
{
    return cvdfprint(cols, 1, fmt, ap);
}

static char *bvformat(int *cols, const char *fmt, va_list ap)
{
    my_buffer_mgr_t mgr = {
        .cols = cols,
        .wcols = true,
        .ccols = 0
    };

    myp_init_buffer_mgr(&mgr, MYP_DEFAULT_BUFFER);
    myp_format_exec(fmt, ap, &mgr);
    mgr.buffer[mgr._cursor] = '\0';
    return mgr.buffer;
}

int bfprint(int *cols, const char *fmt, ...)
{
    va_list ap;
    char *out = NULL;
    int len = 0;

    va_start(ap, fmt);
    out = bvformat(cols, fmt, ap);
    va_end(ap);
    for (; out && out[len]; len++);
    free(out);
    return len;
}

int bformat(int *cols, const char *fmt, ...)
{
    va_list ap;
    char *out = NULL;
    int len = 0;

    va_start(ap, fmt);
    out = bvformat(cols, fmt, ap);
    va_end(ap);
    for (; out && out[len]; len++);
    free(out);
    return len;
}
