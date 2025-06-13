/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/format/internal/formats_pipelines.h
*/

#include <stdarg.h>
#include "format/internal/formats_core.h"

#ifndef FORMATS_PIPELINES_H
    #define FORMATS_PIPELINES_H

    // Pending rename
    #define MYP_PREC 6

    #define FMT_SR_MATCH_ARRAY "\a\b\f\n\r\t\v"
    #define FMT_SR_OUTPUT_ARRAY "abfnrtv"
    #define FMT_SR_SMATCH_ARRAY "\"\'\\"
    #define FMT_SR_BMATCH_ARRAY "!#$?>< *~&\'\"=[()\\"

    #define FMT_SR_PRINT_LOW 0x20
    #define FMT_SR_PRINT_HIGH 0x7E

void myp_pipec(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipes(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);

void myp_piped(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipeu(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipex(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipeo(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);

void myp_pipef(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipee(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipeg(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipea(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);

void myp_pipen(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);
void myp_pipep(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *bmg);

void myp_pipef_direct(
    double value,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg,
    bool rm_tzeroes
);
void myp_pipee_direct(
    double value,
    myp_conversion_t *conv,
    my_buffer_mgr_t *bmg,
    bool rm_tzeroes
);

#endif // !FORMATS_PIPELINES_H
