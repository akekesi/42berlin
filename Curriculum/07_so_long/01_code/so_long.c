/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/07 21:39:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
- price felbevagja a truck-ot, ha ugy van
- legyen gyozelmi fekete-feher csik az uton?
--> de mikor legyen vege a jateknak akkor
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
	init_enemy_static(game);
	init_police(game);
	init_collectible(game);
	init_img_player(game);
	init_img_crash(game);
	init_img_finish(game);
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
	free_enemy_static(game);
	free_police(game);
	free_collectible(game);
	free_img_player(game);
	free_img_crash(game);
	free_img_finish(game);
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
		write(1, INFO, ft_strlen(INFO));
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
		write(1, INFO, ft_strlen(INFO));
	}
	else
		ft_putstr("Error");
}
