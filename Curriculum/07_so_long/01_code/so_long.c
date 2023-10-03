/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 23:08:12 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
- error handling
- read map (ures, ...)
- return value int --> meg lehet szakitani a jatekot
- show function for start, stop, win and lose
- a price utan ne tudjon savot valtani, mert kicsit furan mozog
*/

void	init_sub(t_game *game)
{
	init_game(game);
	init_road(game);
	init_enemy(game);
	init_collectible(game);
	init_img_player(game);
	init_img_crash(game);
	init_img_price(game);
	init_img_start(game);
	init_img_stop(game);
	init_img_win(game);
	init_img_lose(game);
	init_img_dashboard(game);
}

void	free_sub(t_game *game)
{
	free_map(game);
	free_road(game);
	free_enemy(game);
	free_collectible(game);
	free_img_player(game);
	free_img_crash(game);
	free_img_price(game);
	free_img_start(game);
	free_img_stop(game);
	free_img_win(game);
	free_img_lose(game);
	free_img_dashboard(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		game.length_map = llist_len(game.map);
		if (!check_map(&game))
		{
			free_map(&game);
			return (0);
		}
		init_sub(&game);
		loop_game(&game);

		free_sub(&game);
		mlx_terminate(game.mlx);
	}
	else
		ft_putstr("Error");
}
