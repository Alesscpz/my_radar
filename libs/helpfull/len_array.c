/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** len_array.c
*/

int len_array(char **tab)
{
    int len = 0;

    while (tab[len]) {
        len++;
    }
    return len;
}
