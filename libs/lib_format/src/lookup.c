/*
** EPITECH PROJECT, 2024
** blabla
** File description:
** blabla
*/

#include "format/internal/lookup.h"
#include "format/internal/formats_pipelines.h"

#include <stddef.h>

static myp_function_t *const flag[255] = {
    ['d'] = &myp_piped,
    ['i'] = &myp_piped,
    ['s'] = &myp_pipes,
    ['c'] = &myp_pipec,
    ['o'] = &myp_pipeo,
    ['x'] = &myp_pipex,
    ['X'] = &myp_pipex,
    ['F'] = &myp_pipef,
    ['E'] = &myp_pipee,
    ['G'] = &myp_pipeg,
    ['A'] = &myp_pipea,
    ['Y'] = &myp_null_conv,
    ['v'] = &myp_null_conv,
    ['b'] = &myp_null_conv,
    ['w'] = &myp_null_conv,
    ['W'] = &myp_null_conv,
    ['V'] = &myp_null_conv,
    ['B'] = &myp_null_conv,
    ['n'] = &myp_pipen,
    ['u'] = &myp_pipeu,
    ['y'] = &myp_null_conv,
    ['e'] = &myp_pipee,
    ['p'] = &myp_pipep,
    ['T'] = &myp_null_conv,
    ['U'] = &myp_null_conv,
    ['f'] = &myp_pipef,
    ['a'] = &myp_pipea,
    ['g'] = &myp_pipeg,
    ['%'] = &myp_pipec
};

void myp_null_conv(va_list ap, myp_conversion_t *conv, my_buffer_mgr_t *mgr)
{
    (void)(ap);
    (void)(conv);
    myp_commitbuffer(' ', mgr);
}

myp_function_t *my_get_for_conversion(myp_conversion_t *conv)
{
    int key = conv->conv;

    if (flag[key] == NULL)
        return &myp_null_conv;
    return flag[key];
}
