/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** move_plane.c
*/

#include "struct/struct_plane.h"
#include "struct/struct_tower.h"
#include "struct/struct_simulation.h"

static void move_a_plane(plane_t *plane)
{
    plane_t *p = plane;
    sfBool x = p->mouv.x > 0 ? sfTrue : sfFalse;
    sfBool y = p->mouv.y > 0 ? sfTrue : sfFalse;

    if (x && p->pos_dep.x >= p->pos_end.x) {
        if (y && p->pos_dep.y >= p->pos_end.y)
            p->play = sfFalse;
        if (!y && p->pos_dep.y <= p->pos_end.y)
            p->play = sfFalse;
    }
    if (!x && p->pos_dep.x <= p->pos_end.x) {
        if (y && p->pos_dep.y >= p->pos_end.y)
            p->play = sfFalse;
        if (!y && p->pos_dep.y <= p->pos_end.y)
            p->play = sfFalse;
    }
    if (p->play) {
        p->pos_dep.x += p->mouv.x;
        p->pos_dep.y += p->mouv.y;
    }
}

void move_plane(plane_t **plane, sim_t *sim)
{
    plane_t *p = *plane;

    while (p) {
        if (!(p->dead) && (p->waiting < sim->time))
            move_a_plane(p);
        p = p->next;
    }
    return;
}
