#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fmiceli <fmiceli@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/26 11:24:48 by fmiceli       #+#    #+#                  #
#    Updated: 2019/03/26 11:24:49 by fmiceli       ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME=fillit
LIBFT=libft.a
SRCS=get_input.c check_tetriminos.c input_is_valid.c main.c ft_strequ_in.c\
	init_state.c evaluate.c evaluate_state.c
OBJS=$(SRCS:.c=.o)
VPATH=/libft
FLAGS= -Wall -Wextra -Werror

all : $(LIBFT) $(NAME) clean

$(NAME) :
	@gcc $(SRCS) -o $(NAME) $(FLAGS) -L ./libft/ -I ./libft/ -lft

$(LIBFT) :
	@make -C ./libft/ re

clean :
	@rm -f *~
	@rm -f \#*.c\#
	@make clean -C ./libft/

fclean : clean
	@rm -f *.o
	@rm -f $(NAME)
	@make fclean -C ./libft/

re : fclean all
