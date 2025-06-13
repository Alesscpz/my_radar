/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/utilities/is_in.c
*/

#include "format/internal/utils.h"

/**
 * @brief Checks wherther a character is contained within a string.
 *
 * @param c The character to check
 * @param str The string the character is to be found in
 * @returns The index of the character, or -1 if not found.
*/
int myp_is_in(char c, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (c == str[i])
            return i;
    return -1;
}
