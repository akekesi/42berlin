/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/15 01:50:43 by akekesi          ###   ########.fr       */
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
			ft_putstr("esc\n");
		}
		if (game->img_win->instances->y < 0 && game->img_lose->instances->y < 0)
		{
			if (keydata.key == MLX_KEY_SPACE)
			{
				key_hook_sub1(game);
				ft_putstr("space\n");
			}
			if (game->start_stop)
				key_hook_sub2(keydata, game);
		}
	}
	if (game->start_stop)
		key_hook_sub6(keydata, game);
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
	key_hook_sub3(keydata, game);
	key_hook_sub4(keydata, game);
	key_hook_sub5(keydata, game);
}
