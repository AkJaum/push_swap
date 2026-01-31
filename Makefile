NAME	= push_swap
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I includes/
SRCS	= src/push_swap.c src/ft_swap.c src/ft_rotate.c src/ft_revrotate.c src/ft_dosort.c src/ft_push.c src/ft_aux.c
OBJS	= $(SRCS:.c=.o)
LIBFT = libft/libft.a
MAKE	= make

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	#Tem que tirar esse wild seu porra
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re