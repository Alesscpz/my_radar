/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** draw_all.c
*/

#include <SFML/Graphics.h>
#include "struct/struct_plane.h"
#include "struct/struct_tower.h"
#include "struct/struct_simulation.h"
#include "helpfull.h"
#include "simulation.h"
#include "macro/macro_radar.h"

static int draw_a_plane(sfRenderWindow *window, plane_t *plane, sim_t *sim)
{
    if (plane->sprite == NULL)
        return print_error("We got a problem with a tower");
    if ((sim->time >= plane->waiting) && !plane->def_dead && plane->play) {
        sfSprite_setPosition(plane->sprite, plane->pos_dep);
        sfRectangleShape_setPosition(plane->hitbox, plane->pos_dep);
        sfRenderWindow_drawSprite(window, plane->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, plane->hitbox, NULL);
    }
    return MY_EXIT_SUCCESS;
}

static int draw_a_tower(sfRenderWindow *window, tower_t *tower)
{
    if (tower->sprite == NULL)
        return print_error("We got a problem with a tower");
    if (tower->view_sprite)
        sfRenderWindow_drawSprite(window, tower->sprite, NULL);
    if (tower->view_circle)
        sfRenderWindow_drawCircleShape(window, tower->circle, NULL);
    return MY_EXIT_SUCCESS;
}

int draw_everything(sfRenderWindow *window, plane_t *plane,
    tower_t *tower, sim_t *sim)
{
    tower_t *t = tower;
    plane_t *p = plane;

    if (window == NULL)
        return MY_EXIT_FAILURE;
    while (t) {
        if (!!(draw_a_tower(window, t)))
            return MY_EXIT_FAILURE;
        t = t->next;
    }
    move_plane(&plane, sim);
    collision(&plane, &tower);
    while (p) {
        if (!!(draw_a_plane(window, p, sim)))
            return MY_EXIT_FAILURE;
        p = p->next;
    }
    return MY_EXIT_SUCCESS;
}
