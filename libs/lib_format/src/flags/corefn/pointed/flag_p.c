/*
** EPITECH PROJECT, 2024
** flag_p
** File description:
** write the adress pointer
*/

#include "format/internal/formats_core.h"

int myp_fputp(long address, my_buffer_mgr_t *bmg)
{
    return myp_fputx(address, bmg);
}
