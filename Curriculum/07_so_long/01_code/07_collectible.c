/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_collectible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:45:51 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/24 20:56:42 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_collectible(t_game *game)
{
	int				row;
	int				col;
	t_llist			*tmp;
	t_llist			*node;
	mlx_texture_t	*texture;

	texture = mlx_load_png("assets/images/gasoline_50x50_small2.png");
	tmp = game->map;
	row = -1;
	while (1)
	{
		col = 1;
		while (((char *)game->map->value)[col] != '1')
		{
			if (((char *)game->map->value)[col] == 'C')
			{
				node = llist_create(mlx_texture_to_image(game->mlx, texture));
				llist_add(&game->collectible, node);
				mlx_image_to_window(
					game->mlx,
					game->collectible->prev->value,
					col * 50 + 50,
					row * -50);
				mlx_set_instance_depth(
					((mlx_image_t *)game->collectible->prev->value)->instances,
					1);
			}
			col++;
		}
		row++;
		llist_rot(&game->map);
		if (tmp == game->map)
			break ;
	}
	mlx_delete_texture(texture);
}

void	move_collectible(t_game *game)
{
	t_llist	*tmp;

	tmp = game->collectible;
	while (1)
	{
		if (((mlx_image_t *)game->collectible->value)->instances->y == (game->length_map - 5) * TILE_SIZE)
			((mlx_image_t *)game->collectible->value)->instances->y = 0;
		else
			((mlx_image_t *)game->collectible->value)->instances->y += 50;
		llist_rot(&game->collectible);
		if (tmp == game->collectible)
			break ;
	}
}

void	free_collectible(t_game *game)
{
	t_llist	*tmp;

	game->collectible->prev->next = NULL;
	while (game->collectible)
	{
		tmp = game->collectible;
		game->collectible = (game->collectible)->next;
		mlx_delete_image(game->mlx, tmp->value);
		free(tmp);
	}
}
