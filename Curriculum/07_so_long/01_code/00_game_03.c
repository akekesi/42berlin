/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:30:30 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/15 01:09:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_sub3(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		game->speed = ft_min(game->speed + 1, 10);
		game->time_delta = 1000 / game->speed;
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		ft_putstr(str);
		ft_putstr(": up\n");
		free(str);
	}
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		game->speed = ft_max(game->speed - 1, 1);
		game->time_delta = 1000 / game->speed;
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		ft_putstr(str);
		ft_putstr(": down\n");
		free(str);
	}
}

void	key_hook_sub4(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		find_enemy_static_left(game);
		find_enemy_moving_left(game);
		if (game->img_lose->instances->y == MSG_Y)
		{
			game->img_player->instances->x -= 20;
			write_lose();
			return ;
		}
		game->img_player->instances->x = ft_max(
				game->img_player->instances->x - TILE_SIZE,
				2 * TILE_SIZE);
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		ft_putstr(str);
		ft_putstr(": left\n");
		free(str);
	}
}

void	key_hook_sub5(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		find_enemy_static_right(game);
		find_enemy_moving_right(game);
		if (game->img_lose->instances->y == MSG_Y)
		{
			game->img_player->instances->x += 20;
			write_lose();
			return ;
		}
		game->img_player->instances->x = ft_min(
				game->img_player->instances->x + TILE_SIZE,
				MAP_WIDTH - 3 * TILE_SIZE);
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		ft_putstr(str);
		ft_putstr(": right\n");
		free(str);
	}
}

void	key_hook_sub6(mlx_key_data_t keydata, t_game *game)
{
	char	*str;

	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_H)
	{
		play_music_honk(game);
		game->length_moves += 1;
		str = ft_itoa(game->length_moves);
		ft_putstr(str);
		ft_putstr(": honk\n");
		free(str);
	}
	if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_H)
		free_music_honk(game);
}
