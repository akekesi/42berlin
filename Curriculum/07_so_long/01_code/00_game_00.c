/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/05 22:57:42 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, TITLE, false);
	game->img_player = NULL;
	game->img_crash = NULL;
	game->img_price = NULL;
	game->img_start = NULL;
	game->img_stop = NULL;
	game->img_win = NULL;
	game->img_lose = NULL;
	game->img_dashboard_bgr = NULL;
	game->img_dashboard_str = NULL;
	game->road = NULL;
	game->enemy = NULL;
	game->collectible = NULL;
	game->start_stop = 0;
	game->speed = 1;
	game->time_last = get_time_current();
	game->time_rest = 0;
	game->time_move = 0;
	game->time_delta = 1000 / game->speed;
	game->time_elapsed = 0;
	game->length_collectible_curr = 0;
	game->length_collectible_orig = 0;
	game->length_moves = 0;
}

void	loop_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &loop_hook, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
}

void	loop_hook(void *param)
{
	t_game		*game;

	game = param;
	if (game->start_stop)
	{
		loop_hook_sub(game);
		find_collectible(game);
		find_img_price(game);
	}
}

void	loop_hook_sub(t_game *game)
{

	game->time_elapsed += get_time_elapsed(game->time_last);
	game->time_move += get_time_elapsed(game->time_last);
	game->time_last = get_time_current();
	move_img_dashboard(game);
	if (game->time_delta <= game->time_move)
	{
		game->time_move = 0;
		find_enemy_front(game);
		if (game->img_lose->instances->y == MSG_Y)
			return ;
		move_road(game);
		move_enemy(game);
		move_collectible(game);
		game->time_last = get_time_current();
		if (!game->length_collectible_curr)
			move_img_price(game);
		if (game->img_win->instances->y == MSG_Y)
			move_img_player(game);
		if (game->img_player->instances->y < 0)
		{
			game->start_stop = 0;
			write_win(game);
		}
	}
}

void	write_win(t_game *game)
{
	char	*str;

	write(1, "time: ", 6);
	str = ft_itoa(game->time_elapsed / 1000);
	write(1, str, ft_strlen(str));
	free(str);
	write(1, ".", 1);
	str = ft_itoa(game->time_elapsed / 100);
	write(1, &str[ft_strlen(str) - 1], 1);
	free(str);
	write(1, "s\n", 2);
	write(1, ">>> YOU WIN <<<\n", 16);
}
