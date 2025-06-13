/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_strlen.c
*/

#include "macro/macro_radar.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != CHAR_END_STR){
        i = i + 1;
    }
    return (i);
}
