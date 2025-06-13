/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** is_in.c
*/

#include <stdbool.h>

bool is_in(char character, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == character)
            return true;
    }
    if (character == '\0')
        return true;
    return false;
}
