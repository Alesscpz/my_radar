/*
** EPITECH PROJECT, 2024
** flag_n
** File description:
** change the value of pointer
*/

#include "format/internal/buffers.h"
#include "format/internal/conversion.h"

int myp_save_address(void *pointer, myp_convsize_t so, my_buffer_mgr_t *mgr)
{
    switch (so) {
        case MYP_CHAR:
            *((char *) pointer) = mgr->_cursor;
        break;
        case MYP_SHORT:
            *((short *) pointer) = mgr->_cursor;
        break;
        case MYP_INT:
            *((int *) pointer) = mgr->_cursor;
        break;
        case MYP_LONG:
            *((long *) pointer) = mgr->_cursor;
        break;
        case MYP_LLONG:
            *((long long *) pointer) = mgr->_cursor;
        break;
        default:
            *((int *) pointer) = mgr->_cursor;
    }
    return 1;
}
