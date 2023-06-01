SRCS = push_swap.c\
ft_atoi.c\
ft_itoa.c\
ft_lstsize.c\
ft_lstnew.c\
ft_strlen.c\
ft_lstadd_front.c\
ft_lstadd_back.c\
push.c\
swap.c\
rotate.c\
reverse.c\
ft_swap_5.c\
input_checks.c\
min_max.c\

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g

NAME = pushswapp

all: $(NAME)

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			$(RM)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re