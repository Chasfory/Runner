##
## EPITECH PROJECT, 2021
##
## File description:
##

SRC			=	src/main.c\
				src/clock_game.c\
				src/clock_game_infinite.c\
				src/create_game.c\
				src/draw_bis.c\
				src/draw.c\
				src/finish_game.c\
				src/game.c\
				src/game_infinite.c\
				src/init_struct.c\
				src/jump.c\
				src/maps.c\
				src/music.c\
				src/my_itoa.c\
				src/object.c\
				src/opt.c\
				src/opt_bis.c\
				src/destroy_struct.c\
				src/parallaxe.c\
				src/menu_pause.c\

OBJ			=	$(SRC:.c=.o)

NAME 		=	my_runner

CFLAGS		+=	-Wall -Wextra -g3

CPPFLAGS	+=	-iquote ./include

LDFLAGS		+=	-L ./lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my fclean

re: fclean all

./PHONY: all clean fclean

