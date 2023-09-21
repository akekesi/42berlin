/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:38:48 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/21 22:23:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	int	i;
	t_game		*game;

	i = 10;
	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
		{
			while (i--)
			{
				if (((mlx_image_t *)game->road->value)->instances->y == 450)
					((mlx_image_t *)game->road->value)->instances->y = 0;
				else
					((mlx_image_t *)game->road->value)->instances->y += 50;
				llist_rot(&game->road);
			}
		}
		if (keydata.key == MLX_KEY_DOWN)
			game->car->instances->y += 50;
		if (keydata.key == MLX_KEY_LEFT)
			game->car->instances->x -= 50;
		if (keydata.key == MLX_KEY_RIGHT)
			game->car->instances->x += 50;
	}
}

void	loop_hook(void *param)
{
	t_game		*game;

	game = param;	
}
