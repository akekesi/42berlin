/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:25:08 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/23 21:53:35 by akekesi          ###   ########.fr       */
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
		init_game(&game);
		init_road(&game);
		init_car(&game);
		init_traffic(&game);
		loop_game(&game);
		free_car(&game);
		free_road(&game);
		free_traffic(&game);
		mlx_terminate(game.mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_putstr("Error");
}
