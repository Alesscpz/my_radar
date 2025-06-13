/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/utilities/inc.c
*/

#include "format/internal/utils.h"

/**
 * @brief Increments an integer and returns its previous value.
*/
int myp_inc(int *i)
{
    (*i)++;
    return (*i) - 1;
}
