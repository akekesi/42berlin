/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/02 21:57:04 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_player(t_game *game)
{
	int				i;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/player.png");
	game->img_player = mlx_texture_to_image(game->mlx, texture);
	i = 1;
	while (i)
	{
		if (((char *)game->map->next->value)[i] == 'P')
		{
			mlx_image_to_window(game->mlx, game->img_player, (i + 1) * TILE_SIZE, MAP_HEIGHT - 2 * TILE_SIZE);
			break ;
		}
		i++;
	}
	mlx_set_instance_depth(game->img_player->instances, 2);
	mlx_delete_texture(texture);
}

void	move_img_player(t_game *game)
{
	game->img_player->instances->y -= TILE_SIZE;
}

void	free_img_player(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_player);
}
