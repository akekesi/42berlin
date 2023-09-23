/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/23 21:53:58 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, "RoadFighter", false);
	game->speed = 1;
	game->time_last = get_time_current();
	game->time_delta = 1000 / game->speed;
	game->car = NULL;
	game->road = NULL;
	game->traffic = NULL;
}

void	loop_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &loop_hook, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
}

void	move_game(t_game *game)
{
	if (game->time_delta <= get_time_elapsed(game->time_last))
	{
		move_road(game);
		move_traffic(game);
		game->time_last = get_time_current();
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
		{
			game->speed = ft_min(game->speed + 1, 10);
			game->time_delta = 1000 / game->speed;
		}
		if (keydata.key == MLX_KEY_DOWN)
		{
			game->speed = ft_max(game->speed - 1, 1);
			game->time_delta = 1000 / game->speed;
		}
		if (keydata.key == MLX_KEY_LEFT)
			game->car->instances->x = ft_max(game->car->instances->x - 50, 100);
		if (keydata.key == MLX_KEY_RIGHT)
			game->car->instances->x = ft_min(game->car->instances->x + 50, 300);
	}
}

void	loop_hook(void *param)
{
	t_game		*game;

	game = param;
	move_game(game);
}
