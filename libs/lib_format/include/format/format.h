/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/my/printf.h
*/

#include <stdarg.h>

#ifndef MYPRINTF_H
    #define MYPRINTF_H

int fprint(const char *fmt, ...);
int dfprint(int fd, const char *fmt, ...);
int vfprint(const char *fmt, va_list ap);
int vdfprint(int fd, const char *fmt, va_list ap);
char *format(const char *fmt, ...);
char *vformat(const char *fmt, va_list ap);

#endif // !MYPRINTF_H
