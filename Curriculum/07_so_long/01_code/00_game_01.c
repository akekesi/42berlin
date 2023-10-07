/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/07 21:39:22 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_hook(void *param)
{
	t_game		*game;

	game = param;
	if (game->start_stop)
	{
		loop_hook_sub1(game);
		loop_hook_sub2(game);
		find_collectible(game);
		find_img_finish(game);
		find_img_price(game);
	}
}

void	loop_hook_sub1(t_game *game)
{
	game->time_elapsed += get_time_elapsed(game->time_last);
	game->time_move += get_time_elapsed(game->time_last);
	game->time_last = get_time_current();
	if (game->img_win->instances->y != MSG_Y)
	{
		game->time_finish = game->time_elapsed;
		move_img_dashboard(game);
	}
}

void	loop_hook_sub2(t_game *game)
{
	if (game->time_delta <= game->time_move)
	{
		game->time_move = 0;
		find_enemy_static_front(game);
		if (game->img_lose->instances->y == MSG_Y)
			return ;
		move_road(game);
		move_enemy_static(game);
		move_collectible(game);
		game->time_last = get_time_current();
		loop_hook_sub3(game);
	}
}

void	loop_hook_sub3(t_game *game)
{
	if (!game->length_collectible_curr)
	{
		move_img_finish(game);
		move_img_price(game);
	}
	if (game->img_win->instances->y == MSG_Y)
	{
		move_img_player(game);
		move_police(game);
	}
	if (game->img_player->instances->y < 0 \
		&& ((mlx_image_t *)game->police->value)->instances->y < 0)
	{
		game->start_stop = 0;
		write_win(game);
	}
}

void	write_win(t_game *game)
{
	char	*str;

	write(1, "time: ", 6);
	str = ft_itoa(game->time_finish / 1000);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, ".", 1);
	str = ft_itoa(game->time_finish / 100);
	write(1, &str[ft_strlen(str) - 1], 1);
	free(str);
	write(1, "s\n", 2);
	if (game->img_price_win->instances->y > 0)
	{
		write(1, "***************\n", 16);
		write(1, "*** YOU WIN ***\n", 16);
		write(1, "***************\n", 16);
	}
	else
		write(1, ">>> YOU WIN <<<\n", 16);
}
