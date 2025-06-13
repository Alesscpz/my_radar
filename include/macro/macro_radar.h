/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** macro_radar.h
*/

#ifndef MACRO_RADAR_T
    #define MACRO_RADAR_T

    #define MY_EXIT_FAILURE (84)
    #define MY_EXIT_OPTION (42)
    #define MY_EXIT_SUCCESS (0)

    #define W_WIDTH (1920)
    #define W_HEIGHT (1080)
    #define BIT_PX (32)
    #define NAME_W ("My Radar")
    #define FPS (60)
    #define TIME_FRAME (0.01667)

    #define PATH_BACKGROUND ("assets/backgrounds/world_map.jpeg")
    #define PATH_PLANE ("assets/textures/plane.png")
    #define PATH_TOWER ("assets/textures/tower.png")

    #define T_WIDTH (40)
    #define T_HEIGHT (40)
    #define P_WIDTH (20)
    #define P_HEIGHT (20)

    #define PLANE_SYMBOL 'A'
    #define TOWER_SYMBOL 'T'

    #define CHAR_END_STR '\0'
    #define CHAR_END_LINE '\n'

    #define ACTU_CHAR (1)

    #define NUMBER_FILE(argv) (argv[1])
    #define END_LINE ("\n")

    #define SIZE_END_STR (sizeof(char))
    #define SIZE_END_TAB (sizeof(char *))

enum TAB_PLANE {
    P_SYMB = 0,
    P_DEPART_X,
    P_DEPART_Y,
    P_ARRIV_X,
    P_ARRIV_Y,
    P_SPEED,
    P_DELAY,
};

enum TAB_TOWER {
    T_SYMB = 0,
    T_COOR_X,
    T_COOR_Y,
    T_RADIUS,
};
#endif /*MACRO_RADAR_T */
