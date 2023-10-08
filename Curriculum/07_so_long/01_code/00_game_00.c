/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/08 17:19:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, TITLE, false);
	init_game_sub1(game);
	init_game_sub2(game);
}

void	init_game_sub1(t_game *game)
{
	game->img_player = NULL;
	game->img_crash = NULL;
	game->img_finish = NULL;
	game->img_price = NULL;
	game->img_price_win = NULL;
	game->img_start = NULL;
	game->img_stop = NULL;
	game->img_win = NULL;
	game->img_win_question = NULL;
	game->img_lose = NULL;
	game->img_dashboard_bgr = NULL;
	game->img_dashboard_str = NULL;
	game->road = NULL;
	game->police = NULL;
	game->collectible = NULL;
	game->enemy_static = NULL;
	game->enemy_moving = NULL;
}

void	init_game_sub2(t_game *game)
{
	game->start_stop = 0;
	game->speed = 1;
	game->time_last = get_time_current();
	game->time_rest = 0;
	game->time_move = 0;
	game->time_delta = 1000 / game->speed;
	game->time_elapsed = 0;
	game->time_finish = 0;
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
