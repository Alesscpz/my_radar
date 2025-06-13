/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** create_a_plane.c
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct/struct_plane.h"
#include "helpfull.h"
#include "macro/macro_radar.h"

static void know_rotate(plane_t **plane)
{
    float pi = 3.14159265358979323846;
    float angle_radians;
    plane_t *p = *plane;

    angle_radians = atan2(p->mouv.y, p->mouv.x);
    p->rotate = (angle_radians * (180.0f / pi));
    p->rotate += 90.0f;
}

static int fill_struct_by_line_plane(char **line, plane_t **plane)
{
    plane_t *p = *plane;

    p->pos_dep.x = my_getnbr(line[P_DEPART_X]);
    p->pos_dep.y = my_getnbr(line[P_DEPART_Y]);
    p->pos_end.x = my_getnbr(line[P_ARRIV_X]);
    p->pos_end.y = my_getnbr(line[P_ARRIV_Y]);
    p->speed = my_getnbr(line[P_SPEED]);
    p->waiting = (float)my_getnbr(line[P_DELAY]);
    return MY_EXIT_SUCCESS;
}

static int calculating_mouv(plane_t **plane)
{
    plane_t *p = *plane;

    p->mouv.x = (p->pos_end.x - p->pos_dep.x) / p->speed;
    p->mouv.y = (p->pos_end.y - p->pos_dep.y) / p->speed;
    know_rotate(&p);
    p->mouv.x /= FPS;
    p->mouv.y /= FPS;
    return MY_EXIT_SUCCESS;
}

static int create_hitbox(plane_t **plane)
{
    plane_t *p = *plane;
    sfVector2f size = {P_HEIGHT, P_WIDTH};

    p->hitbox = sfRectangleShape_create();
    if (!p->hitbox)
        return MY_EXIT_FAILURE;
    sfRectangleShape_setSize(p->hitbox, size);
    sfRectangleShape_setFillColor(p->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(p->hitbox, 1);
    sfRectangleShape_setOutlineColor(p->hitbox, sfGreen);
    return MY_EXIT_SUCCESS;
}

static int create_graphic_plane(plane_t **plane)
{
    plane_t *p = *plane;

    p->play = sfTrue;
    p->dead = sfFalse;
    p->def_dead = sfFalse;
    p->texture = sfTexture_createFromFile(PATH_PLANE, NULL);
    if (!p->texture) {
        free(p);
        return MY_EXIT_FAILURE;
    }
    p->sprite = sfSprite_create();
    if (!p->sprite) {
        sfTexture_destroy(p->texture);
        free(p);
        return MY_EXIT_FAILURE;
    }
    sfSprite_setTexture(p->sprite, p->texture, sfTrue);
    return calculating_mouv(plane);
}

int create_plane(char **line, plane_t **plane)
{
    plane_t *new_plane = malloc(sizeof(plane_t));

    if (!new_plane) {
        return MY_EXIT_FAILURE;
    }
    if (fill_struct_by_line_plane(line, &new_plane) != MY_EXIT_SUCCESS) {
        free(new_plane);
        return MY_EXIT_FAILURE;
    }
    new_plane->next = *plane;
    *plane = new_plane;
    if (create_graphic_plane(&new_plane) != MY_EXIT_SUCCESS) {
        free(new_plane);
        return MY_EXIT_FAILURE;
    }
    if (!!create_hitbox(&new_plane)) {
        free(new_plane);
        return MY_EXIT_FAILURE;
    }
    return MY_EXIT_SUCCESS;
}
