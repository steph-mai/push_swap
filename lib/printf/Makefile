CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  utils/buffer.c \
	  utils/utils.c \
	  libft/ft_bzero.c \
	  libft/ft_strlen.c \
	  libft/ft_itoa.c \
	  libft/ft_unsigned_itoa.c \
	  libft/ft_itoa_base.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
HEADER = includes

all: $(NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADER) -o $@ -c $<

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
