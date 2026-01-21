NAME	= push_swap
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I includes/
SRCS	= src/push_swap.c src/ft_swap.c src/ft_rotate.c src/ft_revrotate.c src/ft_dosort.c src/ft_push.c src/ft_aux.c
OBJS	= $(SRCS:.c=.o)
MAKE	= make

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re