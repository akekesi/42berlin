/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/07 21:39:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
			write(1, "esc\n", 4);
		}
		if (game->img_win->instances->y < 0 && game->img_lose->instances->y < 0)
		{
			if (keydata.key == MLX_KEY_SPACE)
			{
				key_hook_sub1(game);
				write(1, "space\n", 6);
			}
			if (game->start_stop)
			{
				key_hook_sub2(keydata, game);
				key_hook_sub3(keydata, game);
				key_hook_sub4(keydata, game);
			}
		}
	}
}

void	key_hook_sub1(t_game *game)
{
	game->start_stop = (game->start_stop + 1) % 2;
	if (game->start_stop)
	{
		game->time_last = game->time_rest + get_time_current();
		game->time_rest = 0;
		game->img_start->instances->y = -MSG_Y;
		game->img_stop->instances->y = -MSG_Y;
	}
	else
	{
		game->time_rest = get_time_elapsed(game->time_last);
		game->img_stop->instances->y = MSG_Y;
	}
}

void	key_hook_sub2(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		game->speed = ft_min(game->speed + 1, 10);
		game->time_delta = 1000 / game->speed;
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		write(1, str, ft_strlen(str));
		write(1, ": up\n", 5);
		free(str);
	}
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		game->speed = ft_max(game->speed - 1, 1);
		game->time_delta = 1000 / game->speed;
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		write(1, str, ft_strlen(str));
		write(1, ": down\n", 7);
		free(str);
	}
}

void	key_hook_sub3(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		find_enemy_static_left(game);
		if (game->img_lose->instances->y == MSG_Y)
		{
			game->img_player->instances->x -= 20;
			return ;
		}
		game->img_player->instances->x = ft_max(
				game->img_player->instances->x - TILE_SIZE,
				2 * TILE_SIZE);
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		write(1, str, ft_strlen(str));
		write(1, ": left\n", 7);
		free(str);
	}
}

void	key_hook_sub4(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		find_enemy_static_right(game);
		if (game->img_lose->instances->y == MSG_Y)
		{
			game->img_player->instances->x += 20;
			return ;
		}
		game->img_player->instances->x = ft_min(
				game->img_player->instances->x + TILE_SIZE,
				MAP_WIDTH - 3 * TILE_SIZE);
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		write(1, str, ft_strlen(str));
		write(1, ": right\n", 8);
		free(str);
	}
}
