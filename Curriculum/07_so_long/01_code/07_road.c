/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 00:06:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_road(t_game *game)
{
	int				i;
	t_llist			*node;
	const char		*path[10] = {
		"assets/images/road_line_00.png",
		"assets/images/road_line_01.png",
		"assets/images/road_line_02.png",
		"assets/images/road_line_03.png",
		"assets/images/road_line_04.png",
		"assets/images/road_line_05.png",
		"assets/images/road_line_06.png",
		"assets/images/road_line_07.png",
		"assets/images/road_line_08.png",
		"assets/images/road_line_09.png"
	};
	mlx_texture_t	*texture;

	i = 0;
	while (i < MAP_HEIGHT / TILE_SIZE)
	{
		texture = mlx_load_png(path[i]);
		node = llist_create(mlx_texture_to_image(game->mlx, texture));
		llist_add(&game->road, node);
		mlx_image_to_window(game->mlx, game->road->prev->value, 0, i * TILE_SIZE);
		mlx_set_instance_depth(
			((mlx_image_t *)game->road->prev->value)->instances,
			0);
		mlx_delete_texture(texture);
		i++;
	}
}

void	move_road(t_game *game)
{
	t_llist	*tmp;

	tmp = game->road;
	while (game->road)
	{
		if (((mlx_image_t *)game->road->value)->instances->y == MAP_HEIGHT - TILE_SIZE)
			((mlx_image_t *)game->road->value)->instances->y = 0;
		else
			((mlx_image_t *)game->road->value)->instances->y += TILE_SIZE;
		llist_rot(&game->road);
		if (tmp == game->road)
			break ;
	}
}

void	free_road(t_game *game)
{
	t_llist	*tmp;

	game->road->prev->next = NULL;
	while (game->road)
	{
		tmp = game->road;
		game->road = (game->road)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
