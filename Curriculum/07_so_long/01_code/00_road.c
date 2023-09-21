/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/21 22:04:13 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_road(t_game *game)
{
	t_llist	*node;
	mlx_texture_t	*texture;
	mlx_texture_t	*texture_01;
	mlx_texture_t	*texture_02;
	int	i;
	game->road = NULL;
	texture_01 = mlx_load_png("assets/images/road_line_01.png");
	texture_02 = mlx_load_png("assets/images/road_line_02.png");
	i = 10;
	while (i--)
	{
		if (i % 2)
			texture = texture_01;
		else
			texture = texture_02;
		node = llist_create(mlx_texture_to_image(game->mlx, texture));
		llist_add(&game->road, node);
		mlx_image_to_window(game->mlx, game->road->prev->value, 0, i * 50);
	}
	mlx_delete_texture(texture_01);
	mlx_delete_texture(texture_02);
}

void	free_road(t_game *game)
{
	(void)game;
	// loop or llist_free with mlx_delete_image()
	// mlx_delete_image(game->mlx, game-);
}