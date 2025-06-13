/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/my/internal/utils.h
*/

#include <stdbool.h>

#ifndef MYP_UTILS_H
    #define MYP_UTILS_H

    #define MYP_BASE16L "0123456789abcdef"
    #define MYP_BASE16U "0123456789ABCDEF"
    #define MYP_BASE16(s) (s ? MYP_BASE16U : MYP_BASE16L)

/**
 * @brief Checks wherther a character is contained within a string.
 *
 * @param c The character to check
 * @param str The string the character is to be found in
 * @returns The index of the character, or -1 if not found.
*/
int myp_is_in(char c, const char *str);

/**
 * @brief Increments an integer and returns its previous value.
*/
int myp_inc(int *i);

long double my_round(long double number, int multip, int index);
long double my_pow(long double number, unsigned long power);
long double my_fmod(long double v, long double d);
long double my_floor(long double v);

#endif // !MYP_UTILS_H
