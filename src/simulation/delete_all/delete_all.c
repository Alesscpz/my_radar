/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** delete_all.c
*/

#include <SFML/Graphics.h>
#include "delete_all.h"
#include "struct/struct_plane.h"
#include "struct/struct_simulation.h"
#include "struct/struct_tower.h"

void delete_all(tower_t *tower, plane_t *plane)
{
    deleted_plane(plane);
    deleted_tower(tower);
}
