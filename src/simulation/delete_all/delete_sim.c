/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** delete_plane.c
*/

#include <stdlib.h>
#include "delete_all.h"
#include "struct/struct_simulation.h"

void delete_a_sim(sim_t *sim)
{
    free(sim);
}
