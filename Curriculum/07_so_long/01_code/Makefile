# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 19:43:09 by akekesi           #+#    #+#              #
#    Updated: 2023/10/20 21:32:14 by akekesi          ###   ########.fr        #
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
MUSIC_DIR = ./MUSIC/
MUSIC_GIT = git clone https://github.com/mackron/miniaudio.git $(MUSIC_DIR)

SRCS = so_long.c \
	00_game_00.c \
	00_game_01.c \
	00_game_02.c \
	00_game_03.c \
	00_game_04.c \
	10_player.c \
	11_crash.c \
	12_finish.c \
	13_price.c \
	14_start_stop.c \
	15_win_lose_00.c \
	15_win_lose_01.c \
	16_dashboard_00.c \
	16_dashboard_01.c \
	20_map_00.c \
	20_map_01.c \
	21_road.c \
	22_police.c \
	23_collectible.c \
	24_enemy_static_00.c \
	24_enemy_static_01.c \
	24_enemy_static_02.c \
	25_enemy_moving_00.c \
	25_enemy_moving_01.c \
	25_enemy_moving_02.c \
	30_music.c \
	40_check_00.c \
	40_check_01.c \
	40_check_02.c \
	40_check_03.c \
	flood_fill.c \
	ft_itoa.c \
	ft_putstr.c \
	ft_strdup.c \
	ft_strjoin.c \
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

all: mlx42_clone mlx42_build music_clone $(NAME)

$(NAME): $(OBJS) $(MLX42_LIB)
	$(CC) $(CFLAGS) $(MLX42_FLG) -o $@ $^

clean:
	$(RM) $(OBJS)
	$(RM) $(MLX42_DIR)/build

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX42_DIR)
	$(RM) $(MUSIC_DIR)

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

music_clone:
	@if [ ! -d $(MUSIC_DIR) ]; then \
		$(MUSIC_GIT); \
    fi

bonus:

.PHONY: all clean fclean re bonus
