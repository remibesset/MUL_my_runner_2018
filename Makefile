##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## TasK02 day10
##

SRC = src/main.c \
	src/game.c \
	src/my_lib.c \
	src/set.c \
	src/event.c \
	src/init_set_make_functions.c \
	src/menu/menu.c \
	src/menu/condition.c \
	src/load_score.c \
	src/init/init_text_music.c \
	src/init/init_text.c \
	src/init/init_text2.c \
	src/init/init_texture_sprite.c \
	src/init/init_sprite_parrallax.c \
	src/init/init_sprite_parrallax2.c \
	src/draw/draw.c \
	src/draw/draw2.c \
	src/load_map.c \
	src/utils.c \

CFLAGS = -g3

OBJ = $(SRC:.c=.o)

NAME = my_runner

LIBFLAG = gcc -o

GRAPHIC = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFLAG) $(NAME) $(OBJ) $(VAL_FLAG) $(GRAPHIC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
