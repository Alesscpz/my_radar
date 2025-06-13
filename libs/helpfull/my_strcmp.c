/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_strcmp.c
*/

#include <stdbool.h>
#include "helpfull.h"

bool my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
