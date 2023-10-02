# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/10/02 21:33:47 by akekesi          ###   ########.fr        #
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
	00_game.c \
	01_map.c \
	02_player.c \
	03_price.c \
	04_start_stop.c \
	05_win_lose.c \
	06_road.c \
	07_enemy.c \
	08_collectible.c \
	09_check_00.c \
	09_check_01.c \
	ft_itoa.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_math.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	llist_00.c \
	llist_01.c \
	time.c

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
