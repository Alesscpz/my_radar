/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** delete_sprite_texture.c
*/

#include <SFML/Graphics.h>

void delete_sprite_texture(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}
