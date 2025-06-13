##
## EPITECH PROJECT, 2024
## make lib
## File description:
## make lib
##

#
# BINARY CREATION
#

SRCDIR = src/

SRCDIR = lib/

SRC = 		main.c															\
			src/radar.c														\
			src/window/create_window.c										\
			src/simulation/delete_all/delete_sprite_texture.c				\
			src/simulation/delete_all/delete_plane.c						\
			src/simulation/delete_all/delete_sim.c							\
			src/simulation/delete_all/delete_tower.c						\
			src/simulation/delete_all/delete_all.c						\
			src/simulation/create_from_script.c								\
			src/simulation/create_a_tower.c									\
			src/simulation/create_a_plane.c									\
			src/simulation/move_plane.c										\
			src/simulation/collision.c										\
			src/simulation/draw_all.c										\
			src/simulation/lunch_simulation.c								\
			libs/helpfull/print_error.c										\
			libs/helpfull/abs.c												\
			libs/helpfull/my_getnbr.c										\
			libs/helpfull/len_array.c										\
			libs/helpfull/my_strlen.c										\
			libs/helpfull/my_strndup.c										\
			libs/helpfull/is_in.c											\
			libs/helpfull/my_str_to_word_array.c							\
			libs/helpfull/my_strcmp.c

OBJ = $(SRC:.c=.o)

NAME	=	my_radar

CFLAGS = -Wall -Wextra -I include

C_FLAGS	+=	-g3 -lformat -lcsfml-audio -lcsfml-graphics
C_FLAGS	+=	-lcsfml-network -lcsfml-system -lcsfml-window -lm

FLAGLIB = -L./libs/lib_format/ -L.

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C libs/lib_format
	cp libs/lib_format/libformat.a .
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(FLAGLIB) $(C_FLAGS)

clean:
	$(MAKE) clean -C libs/lib_format
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libs/lib_format
	rm -r libformat.a
	rm -f $(NAME)

re:	fclean all
