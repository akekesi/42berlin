/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/24 19:46:35 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
- error handling
- delete images
- read map (ures, ...)
- starting position
- exit position
*/

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game, argv[1]);
		init_player(&game);
		init_win(&game);
		init_road(&game);
		init_enemy(&game);
		init_collectible(&game);
		loop_game(&game);
		free_player(&game);
		free_win(&game);
		free_road(&game);
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
