#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:21:51 by ohesheli          #+#    #+#              #
#    Updated: 2017/03/17 17:25:10 by ohesheli         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRC = commands.c commands2.c commands3.c commands4.c handler.c solver3.c\
operate_stacks.c operations.c pivot.c solver.c solver2.c stack.c ft_atol.c\
push_swap.c checker.c

OBJ = $(SRC:.c=.o)

POBJ = commands.o commands2.o commands3.o commands4.o handler.o solver3.o\
operate_stacks.o operations.o pivot.o solver.o solver2.o stack.o ft_atol.c\
push_swap.o

COBJ = commands.o commands2.o commands3.o commands4.o handler.o\
operate_stacks.o operations.o pivot.o solver.o solver2.o stack.o ft_atol.c\
checker.o

HEADER = push_swap.h

all: lib $(OBJ) exec

lib:
	cd libft && $(MAKE)

exec:
	gcc -o push_swap $(POBJ) -Llibft -lft
	gcc -o checker $(COBJ) -Llibft -lft

%.o: %.c $(HEADER)
	gcc -Wall -Werror -Wextra -c $<

clean:
	cd libft && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f push_swap
	rm -f checker

re: relib fclean all

relib:
	cd libft && $(MAKE) re