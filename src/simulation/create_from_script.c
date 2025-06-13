/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** create_from_script.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "libs/utilises.h"
#include "struct/struct_plane.h"
#include "struct/struct_tower.h"
#include "simulation.h"
#include "macro/macro_radar.h"

static void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
}

static int add_element(char **line_in_tab, tower_t **tower, plane_t **plane)
{
    if (line_in_tab == NULL || line_in_tab[0] == NULL ||
            line_in_tab[0][0] == '\0') {
        print_error("Invalid input for element addition (NULL or empty).");
        return MY_EXIT_FAILURE;
    }
    switch (line_in_tab[0][0]) {
        case PLANE_SYMBOL:
            return create_plane(line_in_tab, plane);
        case TOWER_SYMBOL:
            return create_tower(line_in_tab, tower);
        default:
            print_error("Unknown element type of a line in the file .");
            return MY_EXIT_FAILURE;
    }
}

int create_from_script(char *file, tower_t **tower, plane_t **plane)
{
    int status = 0;
    long unsigned int size = 50;
    char *current_line = NULL;
    char **line_in_tab = NULL;
    FILE *stream = NULL;

    stream = fopen(file, "r");
    while (getline(&current_line, &size, stream) != -1) {
        line_in_tab = my_str_to_word_array(current_line);
        status = add_element(line_in_tab, tower, plane);
        free_tab(line_in_tab);
        if (status == MY_EXIT_FAILURE) {
            fclose(stream);
            return print_error("Cannot have all tower and plane");
        }
    }
    fclose(stream);
    free(current_line);
    return MY_EXIT_SUCCESS;
}
