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


OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = pushswap.a

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re