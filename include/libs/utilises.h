/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** utilises.h
*/

#include <stdbool.h>

#ifndef UTILISES_T
    #define UTILISES_T

int print_error(const char *msg);
int print_error_s(const char *msg);
int my_getnbr(char const *str);
int lenarray(void **tab);
bool is_in(char character, char *str);
bool my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strndup(const char *s, int len);
char **my_str_to_word_array(char *s);

#endif /*UTILISES_T*/
