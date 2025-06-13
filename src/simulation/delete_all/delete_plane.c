/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** delete_plane.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "delete_all.h"
#include "struct/struct_plane.h"

static void delete_a_plane(plane_t *plane)
{
    sfRectangleShape_destroy(plane->hitbox);
    delete_sprite_texture(plane->sprite, plane->texture);
    free(plane);
}

void deleted_plane(plane_t *plane)
{
    plane_t *cur_p = plane;
    plane_t *next_p = plane->next;

    while (next_p != NULL) {
        delete_a_plane(cur_p);
        cur_p = next_p;
        next_p = cur_p->next;
    }
    delete_a_plane(cur_p);
}
