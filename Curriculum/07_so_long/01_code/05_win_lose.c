/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_win_lose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/30 23:27:40 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
https://fontmeme.com/pixel-fonts/
font: KleinHeadline
*/

void	init_img_win(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/win.png");
	game->img_win = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_win, 2 * TILE_SIZE, -TILE_SIZE);
	mlx_set_instance_depth(game->img_win->instances, 3);
	mlx_resize_image(game->img_win, 5 * TILE_SIZE, TILE_SIZE);
	mlx_delete_texture(texture);
}

void	free_img_win(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_win);
}

void	init_img_lose(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/lose.png");
	game->img_lose = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_lose, 2 * TILE_SIZE, -TILE_SIZE);
	mlx_set_instance_depth(game->img_lose->instances, 3);
	mlx_resize_image(game->img_lose, 5 * TILE_SIZE, TILE_SIZE);
	mlx_delete_texture(texture);
}

void	free_img_lose(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_lose);
}
