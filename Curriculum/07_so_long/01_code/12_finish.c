/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/06 21:54:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_finish(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_FINISH);
	game->img_finish = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_finish, 100, -2 * TILE_SIZE);
	mlx_set_instance_depth(game->img_finish->instances, LAYER_FINISH);
	mlx_delete_texture(texture);
}

void	move_img_finish(t_game *game)
{
	game->img_finish->instances->y += TILE_SIZE;
}

void	find_img_finish(t_game *game)
{
	if (game->img_finish->instances->y == game->img_player->instances->y)
		game->img_win->instances->y = MSG_Y;
}

void	free_img_finish(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_finish);
}
