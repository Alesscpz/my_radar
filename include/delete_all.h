/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** delete_all.h
*/

#include <SFML/Graphics.h>
#include "struct/struct_plane.h"
#include "struct/struct_simulation.h"
#include "struct/struct_tower.h"

#ifndef DELETE_ALL
    #define DELETE_ALL

void delete_sprite_texture(sfSprite *sprite, sfTexture *texture);

void deleted_plane(plane_t *plane);
void deleted_tower(tower_t *tower);
void delete_a_sim(sim_t *sim);

void delete_all(tower_t *tower, plane_t *plane);

#endif /*DELETE_ALL*/
