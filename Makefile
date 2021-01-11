# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcloves <hcloves@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 20:40:24 by hcloves           #+#    #+#              #
#    Updated: 2020/01/23 13:03:49 by hcloves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c

SRC = fillit.c tetraddition.c validation.c clearfunc.c help_solve_ft.c \
	solve.c


OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -g -c -I libft/ $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ) -silent
	@make -C libft clean -silent

fclean: clean
	@/bin/rm -f $(NAME) -silent
	@make -C libft fclean -silent

re: fclean all

.PHONY: clean fclean