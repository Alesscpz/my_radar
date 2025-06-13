/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** include/format/internal/buffers.h
*/

#include <stdbool.h>

#ifndef BUFFERS_H
    #define BUFFERS_H

    #define MYP_DEFAULT_BUFFER 1020
    #define MYP_BUFFER_PADDING 4

typedef struct my_buffer_mgr {
    char *buffer;
    char *sub;
    int size;
    int csize;
    int _cursor;
    int *cols;
    int ccols;
    bool wcols;

} my_buffer_mgr_t;

typedef enum my_buffer_align {
    MYP_ALIGN_LEFT,
    MYP_ALIGN_RIGHT
} my_buffer_align_t;

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
void myp_init_buffer_mgr(my_buffer_mgr_t *bmg, int size);

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
void myp_subbuffer(my_buffer_mgr_t *bmg, int size);

/**
 * @brief Resizes a sub-buffer in both directions
 *
 * @param bmg The buffer manager containing the sub-buffer
 * @param size The new size of the sub-buffer
 * @param align The alignment algorithm for the resize
*/
void myp_subresize(my_buffer_mgr_t *bmg, int nsize, my_buffer_align_t align);

/**
 * @brief Commits a sub-buffer, aka flushing it to the master buffer
 *
 * @param filler The filling value used to replace null bytes
 * @param bmg The buffer manager containing the sub-buffer
*/
void myp_commitbuffer(char filler, my_buffer_mgr_t *bmg);

/**
 * @brief Ends the usage of the buffer manager,
 *        freeing the memory in the process.
 *
 * @param bmg The buffer manager to end
*/
void myp_end_buffer_mgr(my_buffer_mgr_t *bmg);

int myp_bputc(my_buffer_mgr_t *bmg, char c);
int myp_bputr(my_buffer_mgr_t *bmg, char c, bool raw);

#endif // !BUFFERS_H
