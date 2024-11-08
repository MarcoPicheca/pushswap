# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 12:00:18 by mapichec          #+#    #+#              #
#    Updated: 2024/03/23 16:56:41 by mapichec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ft_split.c \
      list_utils.c \
      ft_putstr_fd.c \
      libft_utils.c \
	  ft_free.c \
	  check_nbr.c \
	  gen_lis.c \
	  lis_and_solve.c \
	  five_nbr.c \
	  five_nbr2.c \
	  push.c \
	  swap.c \
	  rotate.c \
	  reverse.c \
      main.c \
	  list_moves.c \
	  list_moves2.c \
	  from_b_to_a.c \
	  move_utils.c \
	  select_sort.c \
	

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): printf $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

printf:
	@make -sC ft_printf
	@echo "ft_printf compiled --> archive created"

clean:
	@make clean -sC ft_printf
	rm -rf $(OBJ)

fclean: clean
	@make fclean -sC ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re printf