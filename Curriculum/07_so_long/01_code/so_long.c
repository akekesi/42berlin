/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 21:45:22 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
- error handling
- delete images
- read map (ures, ...)
- starting position
- exit position
- check_map(&game->map)
- return value int --> meg lehet szakitani a jatekot
- collectable and win is moving back after lot of loop (because -9999 +50+50+50...)
- valgrind should give some leaks --> but how many is OK?
- a key_hook-ba lehetne egy find enemit es egy tobblepcsos savvaltassal elkerulni, hogy egymasra menjenek
- show function for start, stop, win and lose
- a price utan ne tudjon savot valtani, mert kicsit furan mozog
...
*/

void	init_sub(t_game *game, char *path_map)
{
	init_game(game, path_map);
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
		init_sub(&game, argv[1]);
		loop_game(&game);
		free_sub(&game);
		mlx_terminate(game.mlx);
	}
	else
	{
		ft_putstr("Error");
		return (0);
	}
}
