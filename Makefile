NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./libft
SRCS = push_swap.c
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
MAKE = make

all: 
	cd libft && $(MAKE) 
	cd ..
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re