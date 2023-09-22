/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_road.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:32 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/22 19:54:02 by akekesi          ###   ########.fr       */
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
	game->speed = 1;
	game->time_last = get_time_current();
	game->time_delta = 1000 / game->speed;
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
		mlx_set_instance_depth(((mlx_image_t *)game->road->prev->value)->instances, 0);
	}
	mlx_delete_texture(texture_01);
	mlx_delete_texture(texture_02);
}

void	move_road(t_game *game)
{
	int	i;

	if (game->time_delta <= get_time_elapsed(game->time_last))
	{
		i = 10;
		while (i--)
		{
			if (((mlx_image_t *)game->road->value)->instances->y == 450)
				((mlx_image_t *)game->road->value)->instances->y = 0;
			else
				((mlx_image_t *)game->road->value)->instances->y += 50;
			llist_rot(&game->road);
			game->time_last = get_time_current();
		}
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
