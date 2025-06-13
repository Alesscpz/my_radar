/*
** EPITECH PROJECT, 2024
** putchar
** File description:
** print c
*/

#include <unistd.h>
#include "format/internal/buffers.h"

int myp_fputc(char c, my_buffer_mgr_t *bmg)
{
    myp_bputc(bmg, c);
    return 1;
}
