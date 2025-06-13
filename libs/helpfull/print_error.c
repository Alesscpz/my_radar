/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** print_error.c
*/

#include "libs/format.h"
#include "macro/macro_radar.h"

int print_error(const char *msg)
{
    fprint("%s\n", msg);
    return MY_EXIT_FAILURE;
}
