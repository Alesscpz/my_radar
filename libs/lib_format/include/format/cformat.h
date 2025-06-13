/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/my/printf.h
*/

#include <stdarg.h>

#ifndef CFORMAT_H
    #define CFORMAT_H

int bfprint(int *cols, const char *fmt, ...);
int bformat(int *cols, const char *fmt, ...);
int cfprint(int *cols, const char *fmt, ...);
int cdfprint(int *cols, int fd, const char *fmt, ...);
int cvfprint(int *cols, const char *fmt, va_list ap);
int cvdfprint(int *cols, int fd, const char *fmt, va_list ap);
char *cformat(int *cols, const char *fmt, ...);
char *cvformat(int *cols, const char *fmt, va_list ap);

#endif // !MYPRINTF_H
