/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_car.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/22 19:54:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_car(t_game *game)
{
	mlx_texture_t	*texture;
	texture = mlx_load_png("assets/images/car_50x50.png");
	game->car = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->car, 300, 400);
	mlx_set_instance_depth(game->car->instances, 1);
	mlx_delete_texture(texture);
}

void	move_car(t_game *game)
{
	(void)game;
}

void	free_car(t_game *game)
{
	mlx_delete_image(game->mlx, game->car);
}
