CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -rc

DEPS = libft.h
OBJS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_toupper.o ft_tolower.o ft_memset.o
NAME = libft.a

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CLFAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $(LFLAGS) -o $@ $^

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
