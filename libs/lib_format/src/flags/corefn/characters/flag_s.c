/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** displays ch 1 by 1
*/

#include "format/internal/buffers.h"
#include "format/internal/utils.h"

int myp_fputs(char *str, long max_width, my_buffer_mgr_t *bmg, bool ignore_b0)
{
    int i = 0;

    if (ignore_b0 && max_width < 0)
        return 0;
    while ((str[i] != '\0' || ignore_b0) && (max_width < 0 || i < max_width)) {
        myp_bputr(bmg, str[i], ignore_b0);
        i = i + 1;
    }
    return (i - 1);
}
