CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -rc

DEPS = libft.h
SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CLFAGS) -c  $< -o $@

$(NAME): $(OBJS)
	$(AR) $(LFLAGS) -o $@ $^

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
