/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** delete_plane.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "delete_all.h"
#include "struct/struct_tower.h"

static void delete_a_tower(tower_t *tower)
{
    delete_sprite_texture(tower->sprite, tower->texture);
    sfCircleShape_destroy(tower->circle);
    free(tower->position);
    free(tower);
}

void deleted_tower(tower_t *tower)
{
    tower_t *cur_t = tower;
    tower_t *next_t = tower->next;

    while (next_t != NULL) {
        delete_a_tower(cur_t);
        cur_t = next_t;
        next_t = cur_t->next;
    }
    delete_a_tower(cur_t);
}
