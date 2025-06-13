/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/format/internal/parsing.h
*/

#include <stdarg.h>

#include "format/internal/buffers.h"
#include "format/internal/conversion.h"

#ifndef MYP_PARSING_H
    #define MYP_PARSING_H

typedef enum my_parse_stages {
    MYP_PFLAGS,
    MYP_PWIDTH,
    MYP_PPREC,
    MYP_PSIZE,
    MYP_PCONV,
    MYP_END
} my_parse_stages_t;

/**
 * @brief Parses the format string and executes
 *        the correct formatting functions.
 *
 * @param fmt The format string to use.
 * @param ap The parameter array (variadic arg list) for other executors.
 * @param mgr The buffer manager, it needs to be initialized.
*/
void myp_format_exec(const char *fmt, va_list ap, my_buffer_mgr_t *mgr);
void myp_parse_stage_flags(
    char fmc,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
);
void myp_parse_stage_width(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
);
void myp_parse_stage_precision(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
);
void myp_parse_stage_size(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
);
void myp_parse_stage_conversion(
    const char *fmt,
    int *i,
    myp_conversion_t *conv,
    my_buffer_mgr_t *mgr
);

#endif // !MYP_PARSING_H
