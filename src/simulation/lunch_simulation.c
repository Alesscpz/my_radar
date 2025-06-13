/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** lunch_simulation.c
*/

#include <SFML/Graphics.h>
#include "helpfull.h"
#include "delete_all.h"
#include "simulation.h"
#include "libs/format.h"
#include "struct/struct_plane.h"
#include "struct/struct_simulation.h"
#include "struct/struct_tower.h"
#include "macro/macro_radar.h"

static void events(sfRenderWindow *windows)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(windows, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(windows);
    }
}

static int create_all(char **argv, tower_t **tower, plane_t **plane)
{
    int status = 0;

    status = create_from_script(NUMBER_FILE(argv), tower, plane);
    if (status == MY_EXIT_FAILURE)
        return status;
    return MY_EXIT_SUCCESS;
}

static int loop(sfRenderWindow *w, tower_t *t, plane_t *p, sim_t *sim)
{
    if (!!draw_everything(w, p, t, sim)) {
        sfRenderWindow_close(w);
        fprint("Cannot display sprite\n");
        return MY_EXIT_FAILURE;
    }
    events(w);
    return MY_EXIT_SUCCESS;
}

static void set_the_window_bg(sfRenderWindow *win, sim_t *sim, sfSprite *bg)
{
    sim->time += TIME_FRAME;
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, bg, NULL);
}

int simulation(sfRenderWindow *windows, sfClock *clock, char **av, sim_t *sim)
{
    tower_t *begin_tower = NULL;
    plane_t *begin_plane = NULL;
    sfTexture *bg_t = sfTexture_createFromFile(PATH_BACKGROUND, NULL);
    sfSprite *bg_s = sfSprite_create();

    sfSprite_setTexture(bg_s, bg_t, sfTrue);
    if (!(!create_all(av, &begin_tower, &begin_plane)))
        return MY_EXIT_FAILURE;
    sfClock_restart(clock);
    while (sfRenderWindow_isOpen(windows)) {
        set_the_window_bg(windows, sim, bg_s);
        if (!!loop(windows, begin_tower, begin_plane, sim))
            break;
        sfRenderWindow_display(windows);
    }
    delete_all(begin_tower, begin_plane);
    delete_sprite_texture(bg_s, bg_t);
    return MY_EXIT_SUCCESS;
}
