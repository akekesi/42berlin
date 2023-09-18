# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/09/18 21:42:25 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB_MLX = ./MLX42/
GIT_MLX = git clone https://github.com/codam-coding-college/MLX42.git $(LIB_MLX)

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

DEPS = so_long.h \
	get_next_line_bonus.h

SRCS_SO_LONG = so_long.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strlen.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	llist_00.c \
	llist_01.c \
	map.c \

OBJS_SO_LONG = $(SRCS_SO_LONG:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_SO_LONG)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS_SO_LONG)
	$(RM) $(LIB_MLX)/build

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB_MLX)

re: fclean all

mlx42:
	$(GIT_MLX)
	cd $(LIB_MLX) && cmake -B build
	cd $(LIB_MLX) && cmake --build build -j4

bonus:

.PHONY: all clean fclean re bonus
