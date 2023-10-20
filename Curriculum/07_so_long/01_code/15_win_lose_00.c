/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_win_lose_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/20 20:39:27 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_win(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_WIN);
	if (!texture)
	{
		game->error = 1;
		return ;
	}
	game->img_win = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_win, MSG_X, -MSG_Y);
	mlx_set_instance_depth(game->img_win->instances, LAYER_MSG);
	mlx_resize_image(game->img_win, MSG_WIDTH, MSG_HEIGHT);
	mlx_delete_texture(texture);
}

void	init_img_win_question(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_WIN_QUESTION);
	if (!texture)
	{
		game->error = 1;
		return ;
	}
	game->img_win_question = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_win_question,
		MSG_X_EXTRA, -MSG_Y_EXTRA);
	mlx_set_instance_depth(game->img_win_question->instances, LAYER_MSG);
	mlx_delete_texture(texture);
}

void	init_img_lose(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_LOSE);
	if (!texture)
	{
		game->error = 1;
		return ;
	}
	game->img_lose = mlx_texture_to_image(game->mlx, texture);
	mlx_image_to_window(game->mlx, game->img_lose, MSG_X, -MSG_Y);
	mlx_set_instance_depth(game->img_lose->instances, LAYER_MSG);
	mlx_resize_image(game->img_lose, MSG_WIDTH, MSG_HEIGHT);
	mlx_delete_texture(texture);
}
