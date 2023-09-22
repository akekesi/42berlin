/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/22 19:53:58 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
- error handling
- delete images
*/


int32_t	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc == 2)
	{
		(void)argv;
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		game.mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, "RoadFighter", false);
		init_road(&game);
		init_car(&game);
		mlx_loop_hook(game.mlx, &loop_hook, &game);
		mlx_key_hook(game.mlx, &key_hook, &game);
		mlx_loop(game.mlx);
		free_road(&game);
		free_car(&game);
		mlx_terminate(game.mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_putstr("Error");
	// so_long_demo();
	// test_mlx42_00();
}
