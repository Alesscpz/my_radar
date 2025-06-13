/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** src/buffers/mgmt.c
*/

#include "format/internal/buffers.h"
#include <stddef.h>
#include <stdlib.h>

static void myp_buffer_expand(my_buffer_mgr_t *bmg)
{
    char *tmp = malloc(bmg->size * 2 + MYP_BUFFER_PADDING);

    for (int i = 0; i < bmg->size; i++)
        tmp[i] = bmg->buffer[i];
    bmg->size *= 2;
    for (int i = bmg->size; i < bmg->size; i++)
        tmp[i] = 0;
    free(bmg->buffer);
    bmg->buffer = tmp;
}

/**
 * @brief Initializes a buffer manager
 *
 * The buffer manager is automatically given a memory
 * region of size `size` and its cursor is immediately set to zero.
 *
 * The current buffer is still NULL at this stage.
 *
 * @param bmg A region to initialize as a buffer manager
 *            (stack is recommended)
 * @param size The size of the master buffer to allocate.
*/
void myp_init_buffer_mgr(my_buffer_mgr_t *bmg, int size)
{
    bmg->sub = NULL;
    bmg->size = size;
    bmg->csize = -1;
    bmg->_cursor = 0;
    bmg->buffer = malloc(size + MYP_BUFFER_PADDING);
    for (int i = 0; i < size + MYP_BUFFER_PADDING; i++)
        bmg->buffer[i] = 0;
}

/**
 * @brief Initializes a sub-buffer
 *
 * A sub-buffer is a buffer used for one single task, or,
 * here, conversion pipeline.
 *
 * If an existing uncommitted sub-buffer exists, it is reset.
 *
 * @param bmg The buffer manager to initialize the sub-buffer in
 * @param size The size of the sub-buffer.
*/
void myp_subbuffer(my_buffer_mgr_t *bmg, int size)
{
    if (bmg->sub)
        for (int i = 0; i < bmg->csize; i++)
            bmg->sub[i] = 0;
    while (bmg->_cursor + size > bmg->size)
        myp_buffer_expand(bmg);
    bmg->sub = &bmg->buffer[bmg->_cursor];
    bmg->csize = size;
}

/**
 * @brief Resizes a sub-buffer in both directions
 *
 * @param bmg The buffer manager containing the sub-buffer
 * @param size The new size of the sub-buffer
 * @param align The alignment algorithm for the resize
*/
void myp_subresize(my_buffer_mgr_t *bmg, int nsize, my_buffer_align_t align)
{
    int n = 0;
    int oldsize = bmg->csize;

    if (nsize < 0)
        return;
    if (nsize < bmg->csize)
        for (int i = nsize; i < bmg->csize; i++)
            bmg->sub[i] = 0;
    while (bmg->_cursor + nsize > bmg->size)
        myp_buffer_expand(bmg);
    bmg->sub = &bmg->buffer[bmg->_cursor];
    bmg->csize = nsize;
    if (align == MYP_ALIGN_RIGHT) {
        for (; bmg->sub[n]; n++);
        for (int i = nsize - 1; i >= nsize - n; i--)
            bmg->sub[i] = bmg->sub[i - (nsize - n)];
        for (int i = 0; i < nsize - oldsize; i++)
            bmg->sub[i] = '\0';
    }
}

/**
 * @brief Commits a sub-buffer, aka flushing it to the master buffer
 *
 * @param filler The filling value used to replace null bytes
 * @param bmg The buffer manager containing the sub-buffer
*/
void myp_commitbuffer(char filler, my_buffer_mgr_t *bmg)
{
    for (int i = 0; i < bmg->csize; i++)
        if (bmg->sub[i] == 0)
            bmg->sub[i] = filler;
    bmg->_cursor += bmg->csize;
    bmg->csize = -1;
    bmg->sub = NULL;
}

/**
 * @brief Ends the usage of the buffer manager,
 *        freeing the memory in the process.
 *
 * @param bmg The buffer manager to end
*/
void myp_end_buffer_mgr(my_buffer_mgr_t *bmg)
{
    free(bmg->buffer);
}
