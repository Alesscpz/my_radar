/*
** EPITECH PROJECT, 2024
** undefined
** File description:
** struct_plane.h
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef STRUCT_PLANE_T
    #define STRUCT_PLANE_T

typedef struct plane {
    sfSprite *sprite;
    sfTexture *texture;
    float rotate;
    int speed;
    float waiting;
    sfVector2f pos_dep;
    sfVector2f mouv;
    sfVector2f pos_end;
    bool play;
    bool dead;
    bool def_dead;
    sfRectangleShape *hitbox;
    struct plane *next;
} plane_t;

#endif /*STRUCT_PLANE_T*/
