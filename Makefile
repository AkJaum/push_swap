NAME	= push_swap
TESTER	= push_swap_tester
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I includes/
SRCS	= src/push_swap.c src/ft_swap.c src/ft_rotate.c src/ft_revrotate.c src/ft_dosort.c src/ft_push.c src/ft_aux.c
OBJS	= $(SRCS:.c=.o)
TESTER_SRC	= src/m_tester.c
TESTER_OBJ	= $(TESTER_SRC:.c=.o)
LIBFT = libft/libft.a
MAKE	= make

all: $(NAME) $(TESTER)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(TESTER): $(TESTER_OBJ)
	$(CC) $(CFLAGS) -o $(TESTER) $(TESTER_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TESTER_OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(TESTER)
	rm -f $(LIBFT)

m: all
	./$(TESTER)

re: fclean all

.PHONY: all clean fclean re m
