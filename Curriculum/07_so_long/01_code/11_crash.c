/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_crash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/20 20:38:16 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_crash(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_CRASH);
	if (!texture)
	{
		game->error = 1;
		return ;
	}
	game->img_crash = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_crash, -TILE_SIZE, -TILE_SIZE);
	mlx_set_instance_depth(game->img_crash->instances, LAYER_CRASH);
	mlx_delete_texture(texture);
}

void	free_img_crash(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_crash);
}
