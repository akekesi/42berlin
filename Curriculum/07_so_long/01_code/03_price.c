/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_price.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 00:06:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_price(t_game *game)
{
	int				i;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/price.png");
	game->img_price = mlx_texture_to_image(game->mlx, texture);
	i = 1;
	while (i)
	{
		if (((char *)game->map->prev->prev->value)[i] == 'W')
		{
			mlx_image_to_window(game->mlx, game->img_price, (i + 1) * TILE_SIZE, -TILE_SIZE);
			break ;
		}
		i++;
	}
	mlx_set_instance_depth(game->img_price->instances, 1);
	mlx_delete_texture(texture);
}

void	move_img_price(t_game *game)
{
	if (game->img_price->instances->y == ft_max((game->length_map - 5), MAP_HEIGHT / TILE_SIZE) * TILE_SIZE)
		game->img_price->instances->y = 0;
	else
		game->img_price->instances->y += TILE_SIZE;
}

void	find_img_price(t_game *game)
{
	if (game->img_price->instances->x == game->img_player->instances->x
		&& game->img_price->instances->y == game->img_player->instances->y)
	{
		game->img_price->instances->y = 999 * ft_max((game->length_map - 5), MAP_HEIGHT / TILE_SIZE) * TILE_SIZE;
		game->img_win->instances->y = MSG_Y;
	}
}

void	free_img_price(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_price);
}
