/*
** EPITECH PROJECT, 2024
** format
** File description:
** src/format2.c
*/

#include "format/format.h"
#include "format/cformat.h"
#include "format/internal/buffers.h"
#include "format/internal/parsing.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>



int vfprint(const char *fmt, va_list ap)
{
    return vdfprint(1, fmt, ap);
}

int cfprint(int *cols, const char *fmt, ...)
{
    va_list ap;
    int status = 0;

    va_start(ap, fmt);
    status = cvfprint(cols, fmt, ap);
    va_end(ap);
    return status;
}

int cdfprint(int *cols, int fd, const char *fmt, ...)
{
    va_list ap;
    int status = 0;

    va_start(ap, fmt);
    status = cvdfprint(cols, fd, fmt, ap);
    va_end(ap);
    return status;
}

int cvdfprint(int *cols, int fd, const char *fmt, va_list ap)
{
    char *out = cvformat(cols, fmt, ap);
    int len = 0;

    for (; out && out[len]; len++);
    if (out) {
        write(fd, out, len);
        free(out);
    }
    return out ? len : -1;
}

char *cformat(int *cols, const char *fmt, ...)
{
    va_list ap;
    char *out = NULL;

    va_start(ap, fmt);
    out = cvformat(cols, fmt, ap);
    va_end(ap);
    return out;
}
