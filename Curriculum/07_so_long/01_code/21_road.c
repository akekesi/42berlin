/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/20 21:20:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_road(t_game *game)
{
	int				i;
	char			*path_road;
	t_llist			*node;
	mlx_texture_t	*texture;

	i = 0;
	while (i < MAP_HEIGHT / TILE_SIZE)
	{
		path_road = ft_strdup(PATH_ROAD);
		path_road[25] = i + '0';
		texture = mlx_load_png(path_road);
		free(path_road);
		if (!texture)
		{
			game->error = 1;
			return ;
		}
		node = llist_create(mlx_texture_to_image(game->mlx, texture));
		llist_add(&game->road, node);
		init_road_sub(game, i);
		mlx_delete_texture(texture);
		i++;
	}
}

void	init_road_sub(t_game *game, int i)
{
	mlx_image_to_window(
		game->mlx,
		game->road->prev->value,
		0,
		i * TILE_SIZE);
	mlx_set_instance_depth(
		((mlx_image_t *)game->road->prev->value)->instances,
		LAYER_ROAD);
}

void	move_road(t_game *game)
{
	t_llist	*tmp;

	tmp = game->road;
	while (game->road)
	{
		if (((mlx_image_t *)game->road->value)->instances->y \
			== MAP_HEIGHT - TILE_SIZE)
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

	if (!game->road)
		return ;
	game->road->prev->next = NULL;
	while (game->road)
	{
		tmp = game->road;
		game->road = (game->road)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
