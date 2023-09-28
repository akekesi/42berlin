# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/09/28 18:40:03 by akekesi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

DEPS = so_long.h

MLX42_DIR = ./MLX42/
MLX42_GIT = git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLG = -L$(MLX_PATH)/build -lglfw -ldl -lm -pthread

SRCS = so_long.c \
	00_time.c \
	01_game.c \
	02_map.c \
	03_player.c \
	04_win.c \
	05_road.c \
	06_enemy.c \
	07_collectible.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_math.c \
	llist_00.c \
	llist_01.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	check_00.c \
	check_01.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAGS) -c $< -o $@

all: mlx42_clone mlx42_build $(NAME)

$(NAME): $(OBJS) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(MLX42_FLG) -o $@ $^

clean:
	$(RM) $(OBJS)
	$(RM) $(MLX42_DIR)/build

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX42_DIR)

re: fclean all

mlx42_clone:
	@if [ ! -d $(MLX42_DIR) ]; then \
		$(MLX42_GIT); \
    fi

mlx42_build:
	@if [ ! -d $(MLX42_DIR)/build ]; then \
		cmake $(MLX42_DIR) -B $(MLX42_DIR)/build; \
		make -C $(MLX42_DIR)/build -j4; \
    fi

bonus:

.PHONY: all clean fclean re bonus
