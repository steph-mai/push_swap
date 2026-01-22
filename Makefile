NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -MMD -MP

LIBFT_PATH  = ./lib/libft
PRINTF_PATH = ./lib/printf

SRCS        = main.c \
              parsing/parsing.c \
			  parsing/free.c \
			  parsing/check_args.c \
			  parsing/flags.c \
              stack_utils/stack_nodes.c \
			  stack_utils/sort_numbers.c \
			  core/disorder.c \
			  operations/swap.c \
			  operations/push.c \
			  operations/rotate.c \
			  operations/reverse_rotate.c \
			  core/algo/simple/three_sort.c \
			  core/algo/simple/selection_sort.c \
			  core/algo/simple/insertion_sort.c \
			  core/algo/complex/radix_sort.c \
			  core/algo/medium/range_based_sort.c \
			  core/algo/adaptive/adaptive.c \
			  core/bench.c
			                
OBJS        = $(SRCS:.c=.o)

DEPS        = $(OBJS:.o=.d)

INCLUDES    = -I. -I$(LIBFT_PATH) -I$(PRINTF_PATH)

LIBFT       = $(LIBFT_PATH)/libft.a
PRINTF      = $(PRINTF_PATH)/libftprintf.a

LIBS_FLAGS  = -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean
	@echo "Object and dependency files cleaned."

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re