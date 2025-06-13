/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** create_window.c
*/

#include <SFML/Graphics.h>
#include "macro/macro_radar.h"

sfRenderWindow *create_window(int width, int height,
    int bitsPerPixer, char *name)
{
    sfVideoMode mode;
    sfRenderWindow* window;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = bitsPerPixer;
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, FPS);
    return window;
}
