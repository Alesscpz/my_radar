/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** simulation.h
*/

#include "struct/struct_plane.h"
#include "struct/struct_tower.h"
#include "struct/struct_simulation.h"

#ifndef SIMULATION_T
    #define SIMULATION_T

int simulation(sfRenderWindow *windows, sfClock *clock, char **av, sim_t *sim);

int create_from_script(char *file, tower_t **tower, plane_t **plane);
int create_tower(char **line, tower_t **tower);
int create_plane(char **line, plane_t **plane);

void move_plane(plane_t **plane, sim_t *sim);
void collision(plane_t **plane, tower_t **tower);

int draw_everything(sfRenderWindow *window, plane_t *plane,
    tower_t *tower, sim_t *sim);

#endif /*SIMULATION_T*/
