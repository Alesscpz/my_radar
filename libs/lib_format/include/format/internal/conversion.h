/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/format/internal/conversion.h
*/

#include <stdbool.h>
#include <stdint.h>

#ifndef MYP_CONVERSION_H
    #define MYP_CONVERSION_H

    #define MYP_FLAG_STRING "#0+ -^_&!\r\r\r\r\r\r\r"
    #define MYP_SIZE_STRING "hlLtzjq"
    #define MYP_DUPS_STRING "hl"
    #define MYP_CONV_STRING "discoxXFEGAYvbwWVBnuyepTUfag%"
    #define MYP_TEST_STRING "giasfelfebrehber"

typedef enum myp_convsize {
    MYP_CHAR = -'h',
    MYP_SHORT = 'h',
    MYP_INT = 0,
    MYP_LONG = 'l',
    MYP_LLONG = -'l',
    MYP_LFLT = 'L',
    MYP_INTMAX = 't',
    MYP_SIZE = 'z',
    MYP_PTRDIFF = 'j',
    MYP_LLONGQ = 'q'
} myp_convsize_t;

typedef struct myp_conversion {
    char conv;
    myp_convsize_t size;

    int width;
    int precision;

    struct {
        bool hash : 1;
        bool zero : 1;
        bool plus : 1;
        bool space : 1;
        bool dash : 1;
        bool caret : 1; // Bonus flags
        bool under : 1; // Bonus flags
        bool amper : 1; // Bonus flags
        bool excl : 1; // Width retrieval
        int __pad : 7;
    } flags;
} myp_conversion_t;

#endif // !MYP_CONVERSION_H
