/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/format/internal/lookup.h
*/

#include <stdarg.h>

#include "format/internal/buffers.h"
#include "format/internal/conversion.h"

#ifndef MYP_LOOKUP_H
    #define MYP_LOOKUP_H

typedef void (myp_function_t)(va_list, myp_conversion_t *, my_buffer_mgr_t *);

myp_function_t *my_get_for_conversion(myp_conversion_t *conv);
void myp_null_conv(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *mgr);

#endif // !MYP_LOOKUP_H
