/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** collision.c
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdbool.h>
#include "struct/struct_plane.h"
#include "struct/struct_tower.h"
#include "helpfull.h"
#include "macro/macro_radar.h"

static bool is_in_tower_range(plane_t *plane, tower_t *tower)
{
    float dx;
    float dy;
    float distance;

    while (tower) {
        dx = plane->pos_dep.x - tower->position->x;
        dy = plane->pos_dep.y - tower->position->y;
        distance = sqrt(dx * dx + dy * dy);
        if (distance <= tower->radius)
            return true;
        tower = tower->next;
    }
    return false;
}

static void do_they_collide(plane_t *plane1, plane_t *plane2)
{
    if (plane1->def_dead || plane2->def_dead) {
        return;
    }
    if (plane1 == plane2) {
        return;
    }
    if (absolue((plane1->pos_dep.x - plane2->pos_dep.x)) <= P_WIDTH &&
        absolue((plane1->pos_dep.y - plane2->pos_dep.y)) <= P_HEIGHT) {
            plane1->def_dead = true;
            plane2->def_dead = true;
            return;
    }
    return;
}

void collision(plane_t **planes, tower_t **tower)
{
    plane_t *current_plane = *planes;
    plane_t *other_plane;
    tower_t *towers;
    bool in_tower_range;

    while (current_plane != NULL) {
        in_tower_range = false;
        towers = *tower;
        in_tower_range = is_in_tower_range(current_plane, towers);
        if (in_tower_range) {
            current_plane = current_plane->next;
            continue;
        }
        other_plane = *planes;
        while (other_plane != NULL) {
            do_they_collide(current_plane, other_plane);
            other_plane = other_plane->next;
        }
        current_plane = current_plane->next;
    }
}
