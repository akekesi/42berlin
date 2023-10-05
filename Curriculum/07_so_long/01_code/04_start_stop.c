/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_start_stop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/05 17:27:55 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_start(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_START);
	game->img_start = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_start, MSG_X, MSG_Y);
	mlx_set_instance_depth(game->img_start->instances, 3);
	mlx_resize_image(game->img_start, MSG_WIDTH, MSG_HEIGHT);
	mlx_delete_texture(texture);
}

void	init_img_stop(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_STOP);
	game->img_stop = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_stop, MSG_X, -MSG_Y);
	mlx_set_instance_depth(game->img_stop->instances, 3);
	mlx_resize_image(game->img_stop, MSG_WIDTH, MSG_HEIGHT);
	mlx_delete_texture(texture);
}

void	free_img_start(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_start);
}

void	free_img_stop(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_stop);
}
