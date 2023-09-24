/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/24 18:09:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game)
{
	int				i;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/player.png");
	game->player = mlx_texture_to_image(game->mlx, texture);
	i = 1;
	while (i)
	{
		if (((char *)game->map->next->value)[i] == 'P')
		{
			mlx_image_to_window(game->mlx, game->player, (i + 1) * 50, 400); // +1 because of 2 tiles roadside
			break ;
		}
		i++;
	}
	mlx_set_instance_depth(game->player->instances, 2);
	mlx_delete_texture(texture);
}

void	move_player(t_game *game)
{
	(void)game;
}

void	free_player(t_game *game)
{
	mlx_delete_image(game->mlx, game->player);
}
