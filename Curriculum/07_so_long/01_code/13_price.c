/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_price.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/20 21:18:00 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_price(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(PATH_PRICE);
	if (!texture)
	{
		game->error = 1;
		return ;
	}
	game->img_price = mlx_texture_to_image(game->mlx, texture);
	game->img_price_win = mlx_texture_to_image(game->mlx, texture);
	init_img_price_sub(game);
	mlx_delete_texture(texture);
}

void	init_img_price_sub(t_game *game)
{
	int	i;

	i = 1;
	while (i)
	{
		if (((char *)game->map->prev->prev->value)[i] == 'W')
		{
			mlx_image_to_window(game->mlx, game->img_price,
				(i + 1) * TILE_SIZE, -2 * TILE_SIZE);
			break ;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->img_price_win,
		MSG_X_EXTRA, -TILE_SIZE);
	mlx_set_instance_depth(game->img_price->instances, LAYER_OTHERS);
	mlx_set_instance_depth(game->img_price_win->instances, LAYER_MSG);
}

void	move_img_price(t_game *game)
{
	game->img_price->instances->y += TILE_SIZE;
}

void	find_img_price(t_game *game)
{
	if (game->img_price->instances->x == game->img_player->instances->x
		&& game->img_price->instances->y == game->img_player->instances->y
		&& game->img_price->instances->enabled == true)
	{
		game->img_price->instances->enabled = false;
		game->img_price_win->instances->y = MSG_Y_EXTRA;
	}
}

void	free_img_price(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_price);
	mlx_delete_image(game->mlx, game->img_price_win);
}
