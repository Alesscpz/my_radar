/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/format/internal/formats_core.h
*/

#include "format/internal/buffers.h"
#include "format/internal/conversion.h"

#ifndef MY_FORMATS_CORE_H
    #define MY_FORMATS_CORE_H

int myp_fputf(
    long double number,
    unsigned long decimal,
    my_buffer_mgr_t *bmg,
    bool force_dp
);
int myp_fputa(
    long double num,
    unsigned long decimal,
    my_buffer_mgr_t *bmg,
    myp_conversion_t *conv
);
int myp_fputc(char c, my_buffer_mgr_t *bmg);
int myp_fputs(char *str, long max_width, my_buffer_mgr_t *bmg, bool ignore_b0);
int myp_fputpc(my_buffer_mgr_t *bmg);
int myp_fputxx(unsigned long long number, my_buffer_mgr_t *bmg);
int myp_fputx(unsigned long long number, my_buffer_mgr_t *bmg);
int myp_fputu(unsigned long long number, my_buffer_mgr_t *bmg);
int myp_fputo(unsigned long long number, my_buffer_mgr_t *bmg);
int myp_save_address(void *pointer, myp_convsize_t so, my_buffer_mgr_t *mgr);
int myp_fputp(long address, my_buffer_mgr_t *bmg);

#endif // !MY_FORMATS_CORE_H
