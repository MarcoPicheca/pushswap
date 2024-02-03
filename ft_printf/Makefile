NAME = libftprintf.a

SRC =	main.c \
		numeri.c \
		length.c \
		pointers.c \
		hexa.c \
		caratteri.c \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	ar -crs $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $<

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re