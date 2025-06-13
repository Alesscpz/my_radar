/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** create a_tower.c
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "struct/struct_tower.h"
#include "libs/utilises.h"
#include "macro/macro_radar.h"

static int fill_stuct_by_line_tower(char **line, tower_t **tower)
{
    (*tower)->position = malloc(sizeof(sfVector2f));
    if (!(*tower)->position)
        return MY_EXIT_FAILURE;
    (*tower)->position->x = my_getnbr(line[T_COOR_X]);
    (*tower)->position->y = my_getnbr(line[T_COOR_Y]);
    (*tower)->radius = my_getnbr(line[T_RADIUS]);
    return MY_EXIT_SUCCESS;
}

static int create_graphic_tower(tower_t **tower)
{
    (*tower)->view_sprite = sfTrue;
    (*tower)->texture = sfTexture_createFromFile(PATH_TOWER, NULL);
    if (!(*tower)->texture) {
        free((*tower));
        return MY_EXIT_FAILURE;
    }
    (*tower)->sprite = sfSprite_create();
    if (!(*tower)->sprite) {
        sfTexture_destroy((*tower)->texture);
        free((*tower));
        return MY_EXIT_FAILURE;
    }
    sfSprite_setTexture((*tower)->sprite, (*tower)->texture, sfTrue);
    sfSprite_setPosition((*tower)->sprite, *((*tower)->position));
    return MY_EXIT_SUCCESS;
}

static int create_circle_tower(tower_t **tower)
{
    tower_t *t = *tower;
    sfVector2f pos = *(t->position);

    pos.x -= (t->radius - (T_WIDTH / 2));
    pos.y -= (t->radius - (T_HEIGHT / 2));
    t->view_circle = sfTrue;
    t->circle = sfCircleShape_create();
    if (!t->circle)
        return MY_EXIT_FAILURE;
    sfCircleShape_setRadius(t->circle, t->radius);
    sfCircleShape_setFillColor(t->circle, sfTransparent);
    sfCircleShape_setOutlineThickness(t->circle, 1);
    sfCircleShape_setOutlineColor(t->circle, sfWhite);
    sfCircleShape_setPosition(t->circle, pos);
    return MY_EXIT_SUCCESS;
}

int create_tower(char **line, tower_t **tower)
{
    tower_t *new_tower = malloc(sizeof(tower_t));

    memset(new_tower, 1, sizeof(tower_t));
    if (!new_tower)
        return MY_EXIT_FAILURE;
    if (!!fill_stuct_by_line_tower(line, &new_tower))
        return EXIT_FAILURE;
    if (!!create_graphic_tower(&new_tower))
        return EXIT_FAILURE;
    if (!!create_circle_tower(&new_tower))
        return EXIT_FAILURE;
    new_tower->next = *tower;
    *tower = new_tower;
    return MY_EXIT_SUCCESS;
}
