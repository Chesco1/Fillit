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
SRCS=get_input.c check_tetriminos.c input_is_valid.c main.c
OBJS=$(SRCS:.c=.o)
VPATH=/libft
FLAGS= -Wall -Wextra -Werror

all : $(LIBFT) $(NAME) clean

$(NAME) :
	@gcc -c $(SRCS) $(FLAGS) -I./ -I./libft/

$(LIBFT) :
	@make -C ./libft/

test : $(LIBFT) $(NAME)
	@gcc $(TESTSRC) $(OBJS) -o $(NAME) $(FLAGS) -L ./libft/ -I ./libft/ -lft
	@make clean
	@rm -f *.o

clean :
	@rm -f *~
	@rm -f \#*.c\#
	@make clean -C ./libft/

fclean : clean
	@rm -f *.o
	@make fclean -C ./libft/

re : fclean all
