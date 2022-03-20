CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap_utils2.c \
	   push_swap_utils.c \
	   handle_long.c \
	   handle_simple.c \
	   push_swap.c \
	   actions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ftprintf
	$(CC) $(MLX) $(OBJS) -Lftprintf -lftprintf -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
