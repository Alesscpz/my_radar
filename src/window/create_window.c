/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** window.c
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_window(int width, int height,
    int bitsPerPixer, char *name)
{
    sfVideoMode mode;
    sfRenderWindow* window;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = bitsPerPixer;
    window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    return window;
}
