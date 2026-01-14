NAME	= push_swap
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I includes/ -I libft/
SRCS	= src/push_swap.c src/ft_swap.c src/ft_rotate.c src/ft_revrotate.c src/ft_dosort.c src/ft_push.c
OBJS	= $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT	= $(LIBFT_DIR)/libft.a
MAKE	= make

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re