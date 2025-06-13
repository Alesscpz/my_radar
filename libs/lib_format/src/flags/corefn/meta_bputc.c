/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/flags/corefn/meta_bputc.c
*/

#include "format/internal/buffers.h"
#include <stdbool.h>
#include <stddef.h>

int myp_bputr(my_buffer_mgr_t *bmg, char c, bool raw)
{
    if (bmg->sub == NULL)
        myp_subbuffer(bmg, 1);
    if (bmg->csize < 1 || bmg->sub[bmg->csize - 1] != '\0' || raw)
        myp_subresize(
            bmg,
            bmg->csize < 0 ? 1 : bmg->csize + 1,
            MYP_ALIGN_LEFT
        );
    bmg->sub[bmg->csize - 1] = c;
    return 1;
}

int myp_bputc(my_buffer_mgr_t *bmg, char c)
{
    return myp_bputr(bmg, c, true);
}
