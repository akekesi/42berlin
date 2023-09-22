/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:38:48 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/22 19:54:04 by akekesi          ###   ########.fr       */
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
	move_road(game);
}
