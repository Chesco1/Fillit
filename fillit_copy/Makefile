#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ccoers <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 15:57:58 by ccoers        #+#    #+#                  #
#    Updated: 2019/04/22 20:05:39 by ccoers        ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = 	fillit
SRCS =	main.c \
		get_input.c \
		check_tetriminos.c \
		clean_field.c \
		count_dots.c \
		expand_field.c \
		fillit_solve.c \
		ft_strequ_ignore_nl.c \
		ft_strcmp_ignore_nl.c \
		get_max_dots.c \
		index_latest_clone.c \
		input_is_valid.c \
		is_legal.c \
		make_field.c \
		one_square_check.c \
		place_tetrimino.c \
		remove_tetrimino.c \
		was_bad_move.c \
		free_tets.c

MKLIB = make -C libft/ re

OBJECTS = $(SRCS:.c=.o) 

INCLUDES = fillit.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(MKLIB)
	gcc $(SRCS) -I $(INCLUDES) $(FLAGS) -o $(NAME) libft/libft.a

clean:
	rm -f $(OBJECTS)
	make -C libft/ clean
	rm -f *~

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all