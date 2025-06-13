/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** Radar.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "delete_all.h"
#include "libs/format.h"
#include "helpfull.h"
#include "window.h"
#include "simulation.h"
#include "struct/struct_simulation.h"
#include "macro/macro_help.h"
#include "macro/macro_radar.h"

static int help_user(void)
{
    fprint("%s%s%s%s%s%s%s%s%s",
        END_LINE,
        USAGE,
        END_LINE,
        OPTION,
        HELP, HELP_DES,
        END_LINE, END_LINE,
        TEXT_MAN);
    return MY_EXIT_OPTION;
}

static int check_arg(int argc, char **argv)
{
    if (argc != 2)
        return print_error("Too many arguments");
    if (my_strcmp(argv[1], "-h") == true ||
        my_strcmp(argv[1], "--help") == true)
        return help_user();
    return MY_EXIT_SUCCESS;
}

static void free_end(sfRenderWindow * win, sfClock *clock, sim_t *sim)
{
    free(sim);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(win);
}

int radar(int argc, char **argv)
{
    int status;
    sfRenderWindow* window;
    sim_t *sim = malloc(sizeof(sim_t));
    sfClock *clock = sfClock_create();

    if (sim == NULL) {
        sfClock_destroy(clock);
        return MY_EXIT_FAILURE;
    }
    memset(sim, 1, sizeof(sim_t));
    status = check_arg(argc, argv);
    if (status != MY_EXIT_SUCCESS)
        return (status == MY_EXIT_OPTION ? MY_EXIT_SUCCESS : MY_EXIT_FAILURE);
    window = create_window(W_WIDTH, W_HEIGHT, BIT_PX, NAME_W);
    if (window == NULL)
        return print_error("The creation of the window dos'nt succeed\n");
    status = simulation(window, clock, argv, sim);
    free_end(window, clock, sim);
    return status;
}
