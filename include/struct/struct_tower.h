/*
** EPITECH PROJECT, 2024
** undefined
** File description:
** struct_tower.h
*/

#include <SFML/Graphics.h>

#ifndef STRUCT_TOWER_T
    #define STRUCT_TOWER_T

typedef struct tower {
    sfTexture *texture;
    sfSprite *sprite;
    sfBool view_sprite;
    sfVector2f *position;
    int radius;
    sfCircleShape *circle;
    sfBool view_circle;
    struct tower *next;
} tower_t;

#endif /*STRUCT_TOWER_T*/
