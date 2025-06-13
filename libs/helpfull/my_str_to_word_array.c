/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** my_str_to_word_array.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "macro/macro_radar.h"
#include "libs/utilises.h"
#include "macro/macro_helpfull.h"

static int count_str(char *s)
{
    int count = 0;

    for (int j = 0; s[j]; j++)
        if (is_in(s[j], UP) || is_in(s[j], LO) || is_in(s[j], NUM))
            count += 1;
    return count;
}

char **my_str_to_word_array(char *s)
{
    int i = 0;
    int nb = 0;
    int count = count_str(s);
    char **tab = malloc((sizeof(char *) * count) + sizeof(SIZE_END_TAB));

    if (tab == NULL)
        return NULL;
    for (int k = 0; s[k] && nb != count; k++) {
        if (!s[k + 1]) {
            tab[nb] = my_strndup(s + i, k - i - 1);
            nb += 1;
        }
        if (!(is_in(s[k], UP)) && !(is_in(s[k], LO)) && !(is_in(s[k], NUM))) {
            tab[nb] = my_strndup(s + i, k - i);
            i = k + ACTU_CHAR;
            nb++;
        }
    }
    tab[nb] = NULL;
    return tab;
}
