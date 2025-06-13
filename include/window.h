/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** wnindow.h
*/

#include <SFML/Graphics.h>

#ifndef WINDOW_T
    #define WINDOW_T

sfRenderWindow *create_window(int width, int height,
    int bitsPerPixer, char *name);

#endif /*WINDOW_T*/
