/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/30 23:36:21 by akekesi          ###   ########.fr       */
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
...
*/

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game, argv[1]);
		init_road(&game);
		init_img_player(&game);
		init_img_price(&game);
		init_img_start(&game);
		init_img_stop(&game);
		init_img_win(&game);
		init_img_lose(&game);
		init_enemy(&game);
		init_collectible(&game);
		loop_game(&game);
		free_map(&game);
		free_road(&game);
		free_img_player(&game);
		free_img_price(&game);
		free_img_start(&game);
		free_img_stop(&game);
		free_img_win(&game);
		free_img_lose(&game);
		free_enemy(&game);
		free_collectible(&game);
		mlx_terminate(game.mlx);
	}
	else
	{
		ft_putstr("Error");
		return (0);
	}
}
