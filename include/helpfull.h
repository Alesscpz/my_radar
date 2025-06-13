/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** helpfull.h
*/

#include <stdbool.h>

#ifndef HELPFULL_T
    #define HELPFULL_T

int print_error(const char *msg);
int print_error_s(const char *msg);
int my_getnbr(char const *str);
int lenarray(void **tab);
bool is_in(char character, char *str);
bool my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strndup(char *src, int nb);
char **my_str_to_word_array(char *s);
int len_array(char **tab);
float absolue(float nb);

#endif /*HELPFULL_T*/
