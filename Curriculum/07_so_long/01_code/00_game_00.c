/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_game_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:48:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/06 22:43:50 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, TITLE, false);
	init_game_sub(game);
}

void	init_game_sub(t_game *game)
{
	game->img_player = NULL;
	game->img_crash = NULL;
	game->img_finish = NULL;
	game->img_price = NULL;
	game->img_price_win = NULL;
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
	game->time_finish = 0;
	game->length_collectible_curr = 0;
	game->length_collectible_orig = 0;
	game->length_moves = 0;
}
