/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** stdncat.c
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strndup(const char *s, int len)
{
    char *dup = malloc(len + 1);

    if (dup == NULL) {
        return NULL;
    }
    for (int i = 0; i < len && s[i] != '\0'; i++) {
        dup[i] = s[i];
    }
    dup[len] = '\0';
    return dup;
}
