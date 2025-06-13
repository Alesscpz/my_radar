/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/printf.c
*/

#include "format/format.h"
#include "format/cformat.h"
#include "format/internal/buffers.h"
#include "format/internal/parsing.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int fprint(const char *fmt, ...)
{
    va_list ap;
    int status = 0;

    va_start(ap, fmt);
    status = vfprint(fmt, ap);
    va_end(ap);
    return status;
}

int dfprint(int fd, const char *fmt, ...)
{
    va_list ap;
    int status = 0;

    va_start(ap, fmt);
    status = vdfprint(fd, fmt, ap);
    va_end(ap);
    return status;
}

int vdfprint(int fd, const char *fmt, va_list ap)
{
    return cvdfprint(NULL, fd, fmt, ap);
}

char *format(const char *fmt, ...)
{
    va_list ap;
    char *out = NULL;

    va_start(ap, fmt);
    out = vformat(fmt, ap);
    va_end(ap);
    return out;
}

char *vformat(const char *fmt, va_list ap)
{
    return cvformat(NULL, fmt, ap);
}
